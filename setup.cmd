@REM run as Administrator
@echo off

set DOWNLOADS_DIR=%USERPROFILE%\Downloads

set SEVENZIP=C:\"Program Files"\7-Zip\7z.exe
set PYTHON_DIR=%DOWNLOADS_DIR%\python-3.10.8-amd64-portable
set PYTHON_EXE=%PYTHON_DIR%\python.exe

if not exist %PYTHON_EXE% (
cd /d "%TEMP%" &&^
%SystemRoot%\System32\curl.exe "https://github.com/dirkarnez/python-portable/releases/download/v3.10.8/python-3.10.8-amd64-portable.zip" -L -O  &&^
%SEVENZIP% x python-3.10.8-amd64-portable.zip -o"%PYTHON_DIR%" -y &&^
del python-3.10.8-amd64-portable.zip
)

if exist %PYTHON_EXE% (
    echo python %PYTHON_EXE% found
)


set GIT_EXE=%DOWNLOADS_DIR%\PortableGit\bin\git.exe
if not exist %GIT_EXE% (
cd /d "%TEMP%" &&^
%SystemRoot%\System32\curl.exe "https://github.com/git-for-windows/git/releases/download/v2.42.0.windows.2/PortableGit-2.42.0.2-64-bit.7z.exe" -L -O  &&^
PortableGit-2.42.0.2-64-bit.7z.exe -o%DOWNLOADS_DIR%\PortableGit -y &&^
del PortableGit-2.42.0.2-64-bit.7z.exe
)

if exist %GIT_EXE% (
    echo git %GIT_EXE% found
)

set ARMGCC_DIR=%DOWNLOADS_DIR%\arm-gnu-toolchain-12.2.rel1-mingw-w64-i686-aarch64-none-elf\arm-gnu-toolchain-12.2.rel1-mingw-w64-i686-aarch64-none-elf
set ARMGCC_EXE=%ARMGCC_DIR%\bin\aarch64-none-elf-gcc.exe

if not exist %ARMGCC_EXE% (
cd /d "%TEMP%" &&^
%SystemRoot%\System32\curl.exe "https://developer.arm.com/-/media/Files/downloads/gnu/12.2.rel1/binrel/arm-gnu-toolchain-12.2.rel1-mingw-w64-i686-aarch64-none-elf.zip" -L -O &&^
%SEVENZIP% x arm-gnu-toolchain-12.2.rel1-mingw-w64-i686-aarch64-none-elf.zip -o"%DOWNLOADS_DIR%\arm-gnu-toolchain-12.2.rel1-mingw-w64-i686-aarch64-none-elf" -y &&^
del arm-gnu-toolchain-12.2.rel1-mingw-w64-i686-aarch64-none-elf.zip
)

if exist %ARMGCC_EXE% (
    echo gcc %ARMGCC_EXE% found
)
