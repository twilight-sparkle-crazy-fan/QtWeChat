#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>

LoginDialog::LoginDialog(QDialog *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
{
    ui->setupUi(this);

    m_socket = new QTcpSocket (this);

    connect(m_socket,&QTcpSocket::connected, this, &LoginDialog::onConnected);
    connect(m_socket, &QTcpSocket::readyRead, this, &LoginDialog::onReadyRead);

    m_socket->connectToHost("127.0.0.1", 8888);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_btnLogin_clicked()
{
    qDebug() << "登录按钮被点击了！准备发送数据...";
    QString user = ui->editUser->text().trimmed();
    QString pass = ui->editPass->text().trimmed();

    // 1. 简单判空
    if (user.isEmpty() || pass.isEmpty()) {
        QMessageBox::warning(this, "提示", "账号或密码不能为空");
        return;
    }

    QJsonObject json;
    json["type"] = "LOGIN";
    json["username"] = user;
    json["password"] = pass;
    m_socket->write(QJsonDocument(json).toJson(QJsonDocument::Compact));
}


void LoginDialog::on_btnReg_clicked()
{
    QString user = ui->editUser->text().trimmed();
    QString pass = ui->editPass->text().trimmed();

    if (user.isEmpty() || pass.isEmpty()) {
        QMessageBox::warning(this, "提示", "账号密码不能为空");
        return;
    }

    QJsonObject json;
    json["type"] = "REGISTER";
    json["username"] = user;
    json["password"] = pass;

    m_socket->write(QJsonDocument(json).toJson(QJsonDocument::Compact));

}

void LoginDialog::onReadyRead() {
    QByteArray data = m_socket->readAll();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject obj = doc.object();
    QString type = obj["type"].toString();

    if (type == "REGISTER_ACK") {
        if (obj["result"].toString() == "true") {
            QMessageBox::information(this, "提示", "注册成功！请直接登录。");
        } else {
            QMessageBox::critical(this, "失败", "注册失败，用户名可能已存在。");
        }
    }
    else if (type == "LOGIN_ACK") {
        if (obj["result"].toString() == "true") {
            // 登录成功！关闭窗口，放行！
            this->accept();
        } else {
            QMessageBox::critical(this, "失败", "登录失败，账号或密码错误。");
        }
    }

}

void LoginDialog::onConnected(){
    return;
}


