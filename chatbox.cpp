#include "chatbox.h"
#include "ui_chatbox.h"

Chatbox::Chatbox(QWidget *parent)
    : QWidget(parent), ui(new Ui::Chatbox)
{
    ui->setupUi(this);
}

Chatbox::~Chatbox()
{
    delete ui;
}

void Chatbox::setUserTitle(const QString &name)
{
    if (m_currentUser == name)
    {
        return;
    }

    if (!m_currentUser.isEmpty())
    {
        QStringList history;
        for (int i = 0; i < ui->listWidget->count(); ++i)
        {
            history << ui->listWidget->item(i)->text();
        }
        m_messages[m_currentUser] = history;
    }

    m_currentUser = name;

    ui->label->setText(name);

    ui->listWidget->clear();

    if (m_messages.contains(name))
    {
        QStringList history = m_messages[name];

        for (const auto &text : history)
        {
            QListWidgetItem *item = new QListWidgetItem(text);
            item->setTextAlignment(Qt::AlignLeft);
            ui->listWidget->addItem(item);
        }
    }

    ui->label->setText(name);
}

void Chatbox::on_pushButton_clicked()
{
    QString text = ui->textEdit->toPlainText().trimmed();

    if (text.isEmpty())
    {
        return;
    }

    QListWidgetItem *item = new QListWidgetItem(text);

    item->setTextAlignment(Qt::AlignRight);

    ui->listWidget->addItem(item);

    ui->listWidget->scrollToBottom();

    ui->textEdit->clear();
}
