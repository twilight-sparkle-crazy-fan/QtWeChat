#ifndef CHATBOX_H
#define CHATBOX_H

#include <QWidget>
#include <QMap>
#include <QstringList>

namespace Ui {
class Chatbox;
}

class Chatbox : public QWidget
{
    Q_OBJECT

public:
    explicit Chatbox(QWidget *parent = nullptr);
    ~Chatbox();

    void setUserTitle (const QString &name);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Chatbox *ui;
    QMap<QString, QStringList> m_messages; //人名 + 消息
    QString m_currentUser;
};

#endif // CHATBOX_H
