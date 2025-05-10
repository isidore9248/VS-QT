#include "Event.h"
#include <QMouseEvent>
#include <QDebug>

Event::Event(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	ui.label->setText("Click anywhere in the window to see the coordinates.");
	setMouseTracking(true); // Enable mouse tracking to receive mouse move events

	installEventFilter(this); // Install event filter to intercept events
}

Event::~Event()
{
}

void Event::mousePressEvent(QMouseEvent* Event)
{
	//Qt::MouseButton btn = Event->button();

	//int x = Event->x();
	//int y = Event->y();
	//ui.label->setText(QString("Mouse Pressed with button: %1").arg(btn) + "\n"
	//	+ QString("Mouse Pressed at (%1, %2)").arg(x).arg(y));
}

void Event::mouseMoveEvent(QMouseEvent* Event)
{
	Qt::MouseButton btn = Event->button();

	int x = Event->x();
	int y = Event->y();
	ui.label->setText(QString("Mouse Moved with button: %1").arg(btn) + "\n"
		+ QString("Mouse Moved at (%1, %2)").arg(x).arg(y));

	qDebug() << "Mouse Moved with button:" << btn
		<< "at (" << x << ", " << y << ")";
}

bool Event::event(QEvent* Event)
{
	if (Event->type() == QEvent::MouseButtonPress)
	{
		QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(Event);
		qDebug() << "Mouse Button Pressed at:" << mouseEvent->pos();
		return true; // 事件已处理
	}
	else if (Event->type() == QEvent::MouseMove)
	{
		QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(Event);
		qDebug() << "Mouse Moved at:" << mouseEvent->pos();
		return true; // 事件已处理
	}
	else if (Event->type() == QEvent::MouseButtonRelease)
	{
		QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(Event);
		qDebug() << "Mouse Button Released at:" << mouseEvent->pos();
		return true; // 事件已处理
	}

	// 将剩余事件传递给当前类的基类事件处理器
	return QWidget::event(Event);
}

bool Event::eventFilter(QObject* watched, QEvent* event)
{
	//true表示拦截，false不拦截
	if (event->type() == QEvent::MouseMove) { return true; }

	return false;
}