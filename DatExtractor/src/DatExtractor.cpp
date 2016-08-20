// DatExtractor.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <filesystem>
#include <memory>
#include <string>

typedef struct _Header {
    unsigned long revNr;
    unsigned long firmwareSize;
    unsigned long checkSum;
    char partNr[16];
} Header;

typedef struct _SubHeader {
    long dataSize;
    unsigned short pathLength;
    unsigned short flags;
} SubHeader;

int main(int argc, char** argv)
{
    try {

        const auto inputFileName = R"(C:\HomBot\Firmware Update\update.dat)";
        const auto outputDir = std::experimental::filesystem::path(R"(C:\HomBot\filesys\)");

        auto infile = std::ifstream(inputFileName, std::ifstream::in | std::ifstream::binary);

        infile.seekg(0, std::ifstream::end);
        const auto fileSize = infile.tellg();
        infile.seekg(0, std::ifstream::beg);

        // TODO: check the checksum

        auto header = Header{};
        infile.read(reinterpret_cast<char*>(&header), sizeof(header));
        if (header.firmwareSize + sizeof(header) != fileSize)
        {
            std::cout << "Filesize missmatch!" << std::endl;
            return 1;
        }

        while (infile) {
            auto subHeader = SubHeader{};
            infile.read(reinterpret_cast<char*>(&subHeader), sizeof(subHeader));
            if (!infile)
                return 1;

            auto name = std::make_unique<unsigned char[]>(subHeader.pathLength + 1);
            infile.read(reinterpret_cast<char*>(name.get()), subHeader.pathLength);
            if (!infile)
                return 1;

            for (int i = 0; i < subHeader.pathLength; i++)
                if (name[i] >= 0x80)
                    name[i] = -1 - name[i];
                else
                    name[i] = name[i] + -128;

            const auto nameStr = std::string(reinterpret_cast<char*>(name.get()));

            const auto sub = std::experimental::filesystem::path(nameStr);
            const auto fullPath = outputDir / sub;

            if (subHeader.dataSize == -1)
            {
                // make dir
                std::experimental::filesystem::create_directories(fullPath);
            }
            else {
                // make file
                auto data = std::make_unique<unsigned char[]>(subHeader.dataSize);
                infile.read(reinterpret_cast<char*>(data.get()), subHeader.dataSize);
                if (!infile)
                    return 1;

                for (int i = 0; i < subHeader.dataSize; i++)
                if (data[i] >= 0x80)
                    data[i] = -1 - data[i];
                else
                    data[i] = data[i] + -128;
                    
                std::experimental::filesystem::create_directories(fullPath.parent_path());
                auto outfile = std::ofstream(fullPath, std::ofstream::out | std::ofstream::binary);
                outfile.write(reinterpret_cast<char*>(data.get()), subHeader.dataSize);
            }
            
            // TODO: chmod / fs::permissions
        }

    }
    catch (const std::exception& exc) {
        std::cout << exc.what();
    }

    return 0;
}
