@echo off                            :: Disable command echoing
echo Username:%USERNAME%             :: Display the current username
echo Windows Version:                 :: Display the text "Windows Version:"
ver                                  :: Display the Windows version
set Age\p = How old are you          :: Prompt for the user's age (note: there's a typo in the variable name)
pause                                :: Wait for user to press a key before closing
