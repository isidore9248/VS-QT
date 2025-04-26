#include "SignalRecv.h"
#include <QDebug>
#include <QPushButton>

void SignalRecv::signalRecv()
{
	QPushButton btn;
	btn.setWindowTitle("signal-slot");
	btn.resize(400, 100);
	btn.show();
	//system("pause");
}

void SignalRecv::signalRecv(QString recvString)
{
	qDebug().noquote() << "recvString:" << recvString;
	qDebug().noquote() << "signalRecv";
	qDebug().noquote() << "signalRecv(QString recvString)";
	qDebug().noquote() << "signalRecv(QString recvString)";
	QPushButton btn;

	btn.setWindowTitle(recvString);
	btn.resize(400, 100);
	btn.show();
	//system("pause");
}