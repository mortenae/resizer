@echo off
call "%vs110comntools%vsvars32.bat"
cl /nologo /GL /O2 /Feresizer.exe resizer.c kernel32.lib user32.lib /link /subsystem:windows
if errorlevel 1 pause
