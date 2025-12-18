#include "chatlist.h"
#include "ui_chatlist.h"

ChatList::ChatList(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChatList)
{
    ui->setupUi(this);

    for (int i = 0; i < 50; ++i) {
        ui->listWidget->addItem("微信好友 " + QString::number(i));
    }

    connect(ui->listWidget, &QListWidget::itemClicked, this, [=](QListWidgetItem *item){
        // 发射信号
        emit signalUserClicked(item->text());
    });
}

ChatList::~ChatList()
{
    delete ui;
}

