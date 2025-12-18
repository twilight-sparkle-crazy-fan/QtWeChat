#ifndef CHATBOX_H
#define CHATBOX_H

#include <QWidget>

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

private:
    Ui::Chatbox *ui;
};

#endif // CHATBOX_H
