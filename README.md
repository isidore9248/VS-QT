<!--
 * @Description: 
 * @Version: v1.0.0
 * @Author: isidore-chen
 * @Date: 2025-04-26 12:55:00
 * @Copyright: Copyright (c) 2025 CAUC
-->

# QTvsProject

## 开发环境
- QT5.14.2 + VS2022 + C++20

## 环境搭建
- 参考：</br>
    ```
    https://blog.csdn.net/MelyLenient/article/details/123854069
    ```
  QT安装选择msvc2017_64(vs2022兼容此版本)
- vs2022细节微调：
    1. VS打开Qt的ui界面几秒后闪退（ui无法打开文件）的解决办法
    ```
    https://blog.csdn.net/weixin_32155265/article/details/114905744
    ```
    2. vs + Qt开发时qDebug()打印到“输出”窗口
    ```
    https://blog.csdn.net/noon1252/article/details/138762248
    ```
    3. include目录位置
    ```
  ...\QtWidgetsApplication2\      ← .sln所在目录
    ├── QtWidgetsApplication2\                 ← .vcxproj所在目录
    │   ├── src\                               ← 源代码目录
    │   │   ├── main.cpp
    │   │   └── xxx.h
    │   └── QtWidgetsApplication2.vcxproj
    └── QtWidgetsApplication2.sln
    ```
    本项目路径基于 .vcxproj 文件存放，添加```Debug | x64``` 下的包含目录 
    ```
    $(ProjectDir)src
    ```
## 学习笔记
- 参考  note.txt    

## 添加Qt模块
- ```属性管理器->属性->QT Project Settings->Qt Modules```