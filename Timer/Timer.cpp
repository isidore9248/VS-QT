#include "Timer.h"
#include <qDebug>
#include <QTimer>

Timer::Timer(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	TimerID = startTimer(1000); // ms
}

Timer::~Timer()
{
}

void Timer::on_pushButton_2_clicked(void)
{
	QTimer* timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, [=]() {
		static int count = 0;
		count++;
		qDebug() << "Lambda Qtimer event triggered" << count;
		});
	timer->start(1000); // ms
}

void Timer::timerEvent(QTimerEvent* event)
{
	static int count = 0;
	count++;
	qDebug() << "Timer event triggered" << count;
}

void Timer::on_pushButton_clicked(void)
{
	qDebug() << "Button clicked";
	killTimer(TimerID);
	ui.pushButton->setEnabled(false);
	ui.pushButton->setText("Timer stopped");
}