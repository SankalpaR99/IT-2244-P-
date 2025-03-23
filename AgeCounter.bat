@echo off
set /p year=Enter your birth year: 
set /a age=%date:~10,4% - %year% 
echo You are %age% years old.
pause

