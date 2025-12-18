#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chatlist.h"
#include "chatbox.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->ChatListWidget, &ChatList::signalUserClicked,
            ui->ChatboxWidget, &Chatbox::setUserTitle);
}

MainWindow::~MainWindow()
{
    delete ui;
}
