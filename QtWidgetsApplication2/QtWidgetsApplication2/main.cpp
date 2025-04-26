#include "hello.h"
#include <QtWidgets/QApplication>
#include <QPushButton> // 添加此行以包含 QPushButton 的定义
#include <qdebug.h>
int main(int argc, char* argv[])
{
	//维护一个Qt应用程序的生命周期，有且仅有一个对象
	QApplication a(argc, argv);
	//创建一个窗口对象
	hello w;

	//设置窗口的标题
	w.setWindowTitle("Hello winget");
	//设置窗口固定大小
	w.setFixedSize(400, 300);

	qDebug() << "Hello world";

	w.show();

	//system("pause");
	return a.exec();
}