@echo off                                   :: Disable command echoing
set /p year=Enter your birth year:          :: Prompt user for birth year input
set /a age=%date:~10,4% - %year%            :: Calculate age based on current year and input birth year
echo You are %age% years old.               :: Display the calculated age
pause                                       :: Wait for user to press a key before closing


