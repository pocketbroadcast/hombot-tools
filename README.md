# hombot-tools
Contains tools to explore and pimp Lg Home Bot (vacuum cleaner)

All the tools provided have been developed for the vacuum cleaner Lg64703. 
All observations and changes are based upon version 13865 of the Hom-Bot's firmware.


DatExtractor:
-------------
The software uses experimental namespaces provided by the implemenation of std c++17 distributed with Visual Studio 2015 Update 3.

Feel free to port this tool to other platforms!


Scripts:
--------
The folder Scripts contains simple scripts to be executed during firmware update.
To use these copy the update.sh on an empty usb stick and plug it to the hom bot during startup.


To preserve functioning use 
git config --global core.autocrlf false
on windows or any system using CR/LF line endings.
