#pragma once
#include <QtWidgets/QApplication>
class SignalRecv :
	public QObject
{
	/*
		自定义槽
		函数声明在类头文件的 public/private/protected slots 域下面（qt4 以前的版本）
		qt5 就可以声明在类的任何位置，还可以是静态成员函数、全局函数、lambda 表达式
		void 类型的函数，没有返回值
		可以有参数，也可以重载
		不仅有声明，还得有实现	*/
	Q_OBJECT

public slots:
	void signalRecv();
	void signalRecv(QString recvString);

public:
	explicit SignalRecv(QObject* parent = nullptr) : QObject(parent)
	{
		// 构造函数
	}
	~SignalRecv() = default;
};
