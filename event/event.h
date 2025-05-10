#pragma once

#include <QtWidgets/QWidget>
#include "ui_event.h"

class Event : public QWidget
{
	Q_OBJECT

public:
	Event(QWidget* parent = nullptr);
	~Event();

protected:
	void mousePressEvent(QMouseEvent* Event) override;
	void mouseMoveEvent(QMouseEvent* Event) override;
	bool event(QEvent* Event) override;

	bool eventFilter(QObject* watched, QEvent* event) override;

private:
	Ui::eventClass ui;
};
