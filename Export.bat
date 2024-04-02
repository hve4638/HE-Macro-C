@echo off
mkdir .Export

copy /Y .\x64\Release\HEMacro.dll .\.Export\
copy /Y .\x64\Release\KeyHook.dll .\.Export\
copy /Y .\HEMacroGUI\bin\Release\net6.0-windows\HEMacroGUI.exe .\.Export\HEMacro.exe

explorer .Export
timeout 3