#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chatlist.h"
#include "chatbox.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->ChatListWidget, &ChatList::signalUserClicked, this, [=](const QString &name){
        ui->ChatboxWidget->setUserTitle(name);
        ui->stackedWidget->setCurrentIndex(1);
    });

    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}
