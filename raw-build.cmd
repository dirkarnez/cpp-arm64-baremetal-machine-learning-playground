@echo off

@REM set PREFIX=D:\Softwares\
set PREFIX=%USERPROFILE%\Downloads
%PREFIX%\arm-gnu-toolchain-12.2.rel1-mingw-w64-i686-aarch64-none-elf\arm-gnu-toolchain-12.2.rel1-mingw-w64-i686-aarch64-none-elf\bin\aarch64-none-elf-gcc -c main.c -o main.o
%PREFIX%\arm-gnu-toolchain-12.2.rel1-mingw-w64-i686-aarch64-none-elf\arm-gnu-toolchain-12.2.rel1-mingw-w64-i686-aarch64-none-elf\bin\aarch64-none-elf-as startup.s -o startup.o
%PREFIX%\arm-gnu-toolchain-12.2.rel1-mingw-w64-i686-aarch64-none-elf\arm-gnu-toolchain-12.2.rel1-mingw-w64-i686-aarch64-none-elf\bin\aarch64-none-elf-ld -T link_script.ld startup.o main.o -o main.elf
pause