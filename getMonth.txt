@echo off                        :: Disable command echoing

echo %date%                       :: Display the current date

set /a month=%date:~4,2%          :: Extract the month from the current date (substring starting from position 4 with length 2)
echo Month: %month%                :: Display the extracted month
pause                            :: Wait for user to press a key before closing
