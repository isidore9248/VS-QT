#include "hello.h"
#include <QPushButton>
#include <functional>

hello::hello(QWidget* parent)
	: QWidget(parent), btn2("close", this), pSend(new SignalSend(this)), pRecv(new SignalRecv(this))
{
	ui.setupUi(this);
	btn2.move(50, 50);

	//信号发送者 信号 信号接收者 槽函数
	connect(&btn2, &QPushButton::clicked, this, &hello::Send);
	//connect(pSend, &SignalSend::signalSend, pRecv, &SignalRecv::signalRecv);

	////这里的function是确定信号函数和槽函数的重载类型,lamba表达式内不需要实体
	//std::function<void(QString)> signalSend = [this](QString sendString)
	//	{ /*emit pSend->signalSend(sendString);*/ };
	//std::function<void(QString)> signalRecv = [this](QString sendString)
	//	{ /*emit pRecv->signalRecv(sendString);*/ };
	//connect(pSend, static_cast<void(SignalSend::*)(QString)>(&SignalSend::signalSend),
	//	pRecv, static_cast<void(SignalRecv::*)(QString)>(&SignalRecv::signalRecv));

	//函数指针替代function
	//有参类型
	void (SignalSend:: * signalSend2)(QString) = &SignalSend::signalSend;
	void (SignalRecv:: * signalRecv2)(QString) = &SignalRecv::signalRecv;
	connect(pSend, signalSend2, pRecv, signalRecv2);
	//可以同时连接多个信号和槽
	//无参类型
	connect(pSend, static_cast<void(SignalSend::*)()>(&SignalSend::signalSend),
		pRecv, static_cast<void(SignalRecv::*)()>(&SignalRecv::signalRecv));
}

hello::~hello()
{
}

void hello::Send()
{
	emit pSend->signalSend(); // 触发信号
	emit pSend->signalSend("2d1d12d"); // 触发信号
}