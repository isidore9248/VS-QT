#pragma once

#include <QtWidgets/QWidget>
#include "ui_hello.h"
#include "SignalSend.h"
#include "SignalRecv.h"

class hello : public QWidget
{
	//引入信号和槽机制的宏对象
	Q_OBJECT
private:
	QPushButton btn2;

	SignalSend* pSend;
	SignalRecv* pRecv;

public:
	//默认为顶层窗口(父窗口)
	hello(QWidget* parent = nullptr);
	~hello();

	void Send();

private:
	Ui::helloClass ui;
};
