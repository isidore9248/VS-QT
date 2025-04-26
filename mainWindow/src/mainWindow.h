#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_mainWindow.h"

class mainWindow : public QMainWindow
{
	Q_OBJECT

public:
	mainWindow(QWidget* parent = nullptr);
	~mainWindow();

private slots:

	void on_critical_triggered();
	void on_warning_triggered();
	void on_info_triggered();
	void on_question_triggered();

private:
	Ui::mainWindowClass ui;

	//用代码手动创建组件
	void createMenubar(void);
	void createToolbar(void);
	void createStatuesBar(void);
	void createDockWidget(void);
};
