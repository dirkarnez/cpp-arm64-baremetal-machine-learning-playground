@echo off

@REM set PREFIX=D:\Softwares\
set PREFIX=%USERPROFILE%\Downloads
%PREFIX%\arm-gnu-toolchain-12.2.rel1-mingw-w64-i686-aarch64-none-elf\arm-gnu-toolchain-12.2.rel1-mingw-w64-i686-aarch64-none-elf\bin\aarch64-none-elf-gcc -mcpu=cortex-a72 -mlittle-endian -ffreestanding -I%~dp0 -c main.c -o main.o
%PREFIX%\arm-gnu-toolchain-12.2.rel1-mingw-w64-i686-aarch64-none-elf\arm-gnu-toolchain-12.2.rel1-mingw-w64-i686-aarch64-none-elf\bin\aarch64-none-elf-as -mcpu=cortex-a72 -mlittle-endian startup.s -o startup.o
%PREFIX%\arm-gnu-toolchain-12.2.rel1-mingw-w64-i686-aarch64-none-elf\arm-gnu-toolchain-12.2.rel1-mingw-w64-i686-aarch64-none-elf\bin\aarch64-none-elf-ld -T link_script.ld startup.o main.o -o main.elf
pause

@REM  -mfpu=neon-fp-armv8 -mfloat-abi=hard
