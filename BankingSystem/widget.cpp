#include "widget.h"
#include "ui_widget.h"

#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

    //---> View components.
    this->name = new QLineEdit();
    this->address = new QLineEdit();
    this->phone = new QLineEdit();
    this->balance = new QLineEdit();
    this->name->setPlaceholderText("Client's name...");
    this->address->setPlaceholderText("Client's address...");
    this->phone->setPlaceholderText("Client's phone...");
    this->balance->setPlaceholderText("Client's balance...");
    this -> submit = new QPushButton("Submit");
    this -> cancel = new QPushButton("Cancel");

    //---> Horizontal layout.
    QHBoxLayout *layh = new QHBoxLayout();
    layh -> addWidget(submit);
    layh -> addWidget(cancel);

    //---> Main widget vertical layout.
    QVBoxLayout *lay = new QVBoxLayout();
    lay->addWidget(name);
    lay->addWidget(address);
    lay->addWidget(phone);
    lay->addWidget(balance);
    lay->addLayout(layh);

    this -> setLayout(lay);
    this->setFixedSize(300,400);

    QObject::connect(this->submit,SIGNAL(clicked()),this,SLOT(submit_watcher()));
    QObject::connect(this->cancel,SIGNAL(clicked()),this, SLOT(cancel_watcher()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::submit_watcher(){
    emit send_values(this->name->text(), this->address->text(), this->phone->text(), this->balance->text());
}

void Widget::cancel_watcher(){
    this->name->clear();
    this->address->clear();
    this->phone->clear();
    this->balance->clear();
}
