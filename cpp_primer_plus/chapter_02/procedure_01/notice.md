在一开始运行myfirst.cpp文件时，
终端报错"C:\windows\System32\WindowsPowerShell\v1.0\powershell.exe" does not exist

解决办法：
Ctrl+Shift+P >> 输入settings, 打开settings.json文件 >> 添加"terminal.integrated.shell.windows":"C:/WINDOWS/System32/cmd.exe"


在键入F5进行调试时，报错The preLaunchTask 'C/C++:cpp.exe build active file'...
从网上也没找到很好的解决方法，有一个勉强可以使用的是，注释掉"preLaunchTask": "C/C++: cpp.exe build active file"，然后就不报错了，但好像也不调试了，解决不了问题就解决提出问题的人？