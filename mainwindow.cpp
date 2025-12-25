#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chatlist.h"
#include "chatbox.h"
#include <QJsonObject>
#include <QJsonDocument>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_socket = new QTcpSocket(this);

    m_socket->connectToHost("127.0.0.1", 8888);

    ui->stackedWidget->setCurrentIndex(0);

    connect(m_socket, &QTcpSocket::readyRead, [=]()
            {QByteArray data = m_socket->readAll();
            qDebug() << "客户端收到回信：" << data; });

    connect(m_socket, &QTcpSocket::connected, [=]()
            {qDebug() << "连接服务器成功！";
            QJsonObject json;
            json["type"] = "LOGIN";
            json["username"] = "Twilight";
            json["password"] = "123456";

            QJsonDocument doc(json);
            QByteArray data = doc.toJson();

            m_socket->write(data);
            qDebug() << "发送登录信息：" << data;
             });

    connect(ui->ChatListWidget, &ChatList::signalUserClicked, this, [=](const QString &name)
            {
        ui->ChatboxWidget->setUserTitle(name);
        ui->stackedWidget->setCurrentIndex(1); });
    // 空页和实页
}

MainWindow::~MainWindow()
{
    delete ui;
}
