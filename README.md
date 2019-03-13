# Wordlist-Pair-

此项目来自作业[结对项目-最长单词链](https://edu.cnblogs.com/campus/buaa/BUAA_SE_2019_LJ/homework/2638)。

## 运行说明

### 运行命令行程序

在BIN目录下执行Wordlist.exe程序。运行时需要Core.dll与Wordlist.exe在一个目录下。

### 运行GUI

在GUIBIN目录下打开WordlistGUI.exe程序。运行时需要GUIBIN目录中的所有文件。

## 其他说明

除了BIN和GUIBIN目录外，其他每个目录都是一个Visual Studio项目。

- Core：计算模块，生成Core.dll
- CoreUnitTest1：Core的单元测试
- Wordlist：命令行程序，在源代码目录下要求存在Core.dll
- WordlistGUI：Wordlist的GUI版本，依赖Core.dll
- PreProcessUnitTest1：Wordlist除Core以外的单元测试。