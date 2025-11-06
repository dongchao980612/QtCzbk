del *.pro.user /s


@echo off
setlocal enabledelayedexpansion

:: 查找当前目录及所有子目录中名为 "build" 的文件夹
for /d /r . %%i in (build) do (
    if exist "%%i" (
        echo 正在删除：%%i
        :: 强制删除文件夹及其所有内容（/s 递归删除，/q 静默模式）
        rmdir /s /q "%%i"
        if !errorlevel! equ 0 (
            echo 删除成功：%%i
        ) else (
            echo 删除失败：%%i
        )
    )
)

echo 操作完成！按任意键退出...
pause >nul
