@REM run as Administrator
@echo off

set DOWNLOADS_DIR=%USERPROFILE%\Downloads

set SEVENZIP=C:\"Program Files"\7-Zip\7z.exe
set QEMU_DIR=%DOWNLOADS_DIR%\qemu-w64-portable-20240822
set QEMU_EXE=%QEMU_DIR%\qemu-system-aarch64.exe

if not exist %QEMU_EXE% (
cd /d "%TEMP%" &&^
%SystemRoot%\System32\curl.exe "https://github.com/dirkarnez/qemu-portable/releases/download/20240822/qemu-w64-portable-20240822.zip" -L -O  &&^
%SEVENZIP% x qemu-w64-portable-20240822.zip -o"%QEMU_DIR%" -y
)

cd /d "%~dp0"

@REM [QEMU User Documentation — QEMU documentation](https://www.qemu.org/docs/master/system/qemu-manpage.html)
@REM -serial tcp:[host]:port[,server=on|off][,wait=on|off][,nodelay=on|off][,reconnect=seconds]
@REM -serial telnet:host:port[,server=on|off][,wait=on|off][,nodelay=on|off]
if exist %QEMU_EXE% (
  echo qemu %QEMU_EXE% found
  @REM %QEMU_EXE% -M virt -cpu cortex-a72 -serial telnet:localhost:4321,server,nowait -nographic -kernel main.elf
  %QEMU_EXE% -M virt -cpu cortex-a72 -nographic -kernel main.elf
)
