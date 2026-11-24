@echo off
g++ main.cpp -o program -std=c++17 -lncurses -DNCURSES_STATIC
if %errorlevel% == 0 (
    echo Berhasil!
    program.exe
) else (
    echo Build gagal.
)