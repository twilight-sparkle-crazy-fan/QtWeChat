#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QTcpSocket>
#include <QJsonObject>
#include <QJsonDocument>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QDialog *parent = nullptr);
    ~LoginDialog();

private slots:
    void on_btnLogin_clicked();

    void on_btnReg_clicked();

    void onReadyRead();

    void onConnected();


private:
    Ui::LoginDialog *ui;

    QTcpSocket *m_socket;
};

#endif // LOGINDIALOG_H
