#pragma once
#include <QtWidgets/QApplication>
class SignalSend :public QObject
{
	/*
		自定义信号
		函数声明在类头文件的 signals 域下面
		void 类型的函数，没有返回值
		可以有参数，也可以重载
		只有声明，没有实现定义
		触发信号 emit obj->sign (参数...)
	*/

	Q_OBJECT
signals:
	void signalSend(); // 自定义信号
	void signalSend(QString sendString); // 自定义信号

public:
	explicit SignalSend(QObject* parent = nullptr) : QObject(parent)
	{
		// 构造函数
	}
	~SignalSend() = default;
};
