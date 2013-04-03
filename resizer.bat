@echo off
call "%vs110comntools%vsvars32.bat"
rc resizer.rc
cl /nologo /GL /O2 /Feresizer.exe resizer.c /link /subsystem:windows kernel32.lib user32.lib resizer.res
if errorlevel 1 pause
