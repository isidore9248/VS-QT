#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mythread.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 1. 创建子线程对象
    Generate* gen = new Generate;

    connect(this, &MainWindow::starting, gen, &Generate::recvNum);
    // 2. 启动子线程
    connect(ui->start, &QPushButton::clicked, this, [=]()
    {
        emit starting(10000);
        gen->start();
    });
    // 接收子线程发送的数据
    connect(gen, &Generate::sendArray, this, [=](QVector<int> list){
        for(int i=0; i<list.size(); ++i)
        {
            ui->randList->addItem(QString::number(list.at(i)));
        }
    });

    connect(this, &MainWindow::destroy, this, [=]()
    {
        gen->quit();
        gen->wait();
        gen->deleteLater();  // delete t1;


    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
