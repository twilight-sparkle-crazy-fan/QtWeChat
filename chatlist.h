#ifndef CHATLIST_H
#define CHATLIST_H

#include <QWidget>
#include <QListWidgetItem>

namespace Ui {
class ChatList;
}

class ChatList : public QWidget
{
    Q_OBJECT

public:
    explicit ChatList(QWidget *parent = nullptr);
    ~ChatList();

signals:
    void signalUserClicked(const QString &name);

private:
    Ui::ChatList *ui;
};

#endif // CHATLIST_H
