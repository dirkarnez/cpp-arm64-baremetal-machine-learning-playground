@echo off

@REM pretending project root
cd /d "%~dp0"

set PYTHON_DIR=%USERPROFILE%\Downloads\python-3.10.8-amd64-portable
set PATH=%PYTHON_DIR%;%PYTHON_DIR%\Scripts

python tbuildscript.py

pause