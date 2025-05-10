#pragma once

#include <QtWidgets/QWidget>
#include "ui_Timer.h"

class Timer : public QWidget
{
	Q_OBJECT

public:
	Timer(QWidget* parent = nullptr);
	~Timer();

private slots:
	void on_pushButton_clicked(void);
	void on_pushButton_2_clicked(void);

protected:
	void timerEvent(QTimerEvent* event) override;

private:
	Ui::TimerClass ui;
	int TimerID;
};
