@REM run as Administrator
@echo off

set DOWNLOADS_DIR=%USERPROFILE%\Downloads

set PYTHON_DIR=%DOWNLOADS_DIR%\python-3.10.8-amd64-portable

set PATH=^
%PYTHON_DIR%;^
%PYTHON_DIR%\Scripts;^
%DOWNLOADS_DIR%\PortableGit\bin;

C:\Windows\System32\taskkill /f /im python.exe
if exist "%PYTHON_DIR%\Lib\site-packages\tbuild-1.0.0-py3.10.egg" del /f /q "%PYTHON_DIR%\Lib\site-packages\tbuild-1.0.0-py3.10.egg"
if exist "%DOWNLOADS_DIR%\tbuild" rmdir /s /q "%DOWNLOADS_DIR%\tbuild"

cd /d "%DOWNLOADS_DIR%" &&^
git clone https://github.com/dirkarnez/tbuild.git &&^
cd tbuild &&^
.\setup.cmd &&^
.\install-packages.cmd &&^
.\install-as-package.cmd &&^
echo tbuild installed &&^
cd /d "%~dp0" &&^
python -m pip install --upgrade pip &&^
python -m pip install -r requirements.txt
