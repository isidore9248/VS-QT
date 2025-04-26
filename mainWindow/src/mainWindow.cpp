#include "mainWindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QLabel>
#include <QDOckWidget>
#include <QTextEdit>
#include <QDialog>
#include <QMessageBox>
#include <QDebug>

mainWindow::mainWindow(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	ui.textEdit->setText("666");
	ui.actionopen->setIcon(QIcon(":/img/xiaomi13/IMG_20240907_205432.jpg"));

	//模态，强制阻塞在当前窗口
	connect(ui.actionmodel, &QAction::triggered, this, [=]()
		{
			QDialog dia(this);
			dia.exec();
		});

	//非模态，不阻塞
	connect(ui.actionnonmodel, &QAction::triggered, this, [=]()
		{
			//非模态下，show为非阻塞函数，如果dia定义在栈区，在函数结束后会被销毁
			//所以需要使用堆区
			QDialog* dia = new QDialog(this);
			//非模态对话框只有在父类窗口关闭时才会被销毁
			//但是如果只关闭对话框，父类窗口不关闭，则一直不会销毁，造成内存泄漏
			//以下设置dia的属性为关闭时自动删除
			dia->setAttribute(Qt::WA_DeleteOnClose);	//设置关闭时自动删除
			dia->show();
		});

	connect(ui.actioncritical, &QAction::triggered, this, &mainWindow::on_critical_triggered);
	connect(ui.actionwarning, &QAction::triggered, this, &mainWindow::on_warning_triggered);
	connect(ui.actioninfo, &QAction::triggered, this, &mainWindow::on_info_triggered);
	connect(ui.actionquestion, &QAction::triggered, this, &mainWindow::on_question_triggered);

	//ui.menudialog

	//代码手动创建组件
	//createMenubar();
	//createToolbar();
	//createStatuesBar();
	//createDockWidget();
}

mainWindow::~mainWindow()
{
}

void mainWindow::on_warning_triggered()
{
	QMessageBox::warning(this, "标题", "内容");
}

void mainWindow::on_info_triggered()
{
	QMessageBox::information(this, "标题", "内容");
}

void mainWindow::on_question_triggered()
{
	int ret = QMessageBox::question(this, "标题", "内容", QMessageBox::Ok | QMessageBox::Retry);
	if (ret == QMessageBox::Ok)
	{
		qDebug().noquote() << "ok";
	}
	else if (ret == QMessageBox::Retry)
	{
		qDebug().noquote() << "retry";
	}
	else
	{
		qDebug().noquote() << "other";
	}
}

void mainWindow::on_critical_triggered()
{
	QMessageBox::critical(this, "标题", "内容");
}

//使用代码创建菜单栏
void mainWindow::createMenubar(void)
{
	//获取菜单栏
	QMenuBar* MenuBar = menuBar();
	//菜单的返回类型是 QMenu*
	QMenu* firstBar = MenuBar->addMenu("新建");
	MenuBar->addMenu("打开");
	QMenu* SecondBar = firstBar->addMenu("1");
	firstBar->addSeparator();	//添加分隔符
	//直接可以点击的目标返回值为 QAction*
	QAction* action = firstBar->addAction("2");
	SecondBar->addAction("1-1");
	SecondBar->addAction("1-2");
}

void mainWindow::createToolbar(void)
{
	//工具栏设置
	QToolBar* toolBar = addToolBar("tool");
	toolBar->addAction("新建");
	//设置工具栏的可移动性
	toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
	toolBar->setFloatable(false);//设置工具栏不可浮动
}

void mainWindow::createStatuesBar(void)
{
	QStatusBar* statusBar = this->statusBar();
	statusBar->addWidget(new QLabel("状态栏"));
	statusBar->addPermanentWidget(new QLabel("永久状态栏"));
}

void mainWindow::createDockWidget(void)
{
	//使用代码创建DockWidget
	QDockWidget* DockWidget = new QDockWidget("DockWidget", this);
	this->addDockWidget(Qt::LeftDockWidgetArea, DockWidget);
	QTextEdit* textEdit = new QTextEdit(this);
	this->setCentralWidget(textEdit);
}