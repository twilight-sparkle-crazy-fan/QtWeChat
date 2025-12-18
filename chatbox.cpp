#include "chatbox.h"
#include "ui_chatbox.h"

Chatbox::Chatbox(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Chatbox)
{
    ui->setupUi(this);
}

Chatbox::~Chatbox()
{
    delete ui;
}

void Chatbox::setUserTitle(const QString &name)
{
    ui->label->setText(name);
}
