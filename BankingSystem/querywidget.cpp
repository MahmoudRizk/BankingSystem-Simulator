#include "querywidget.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>

#include <QStringList>
#include <QHeaderView>
#include <QSqlQuery>

QueryWidget::QueryWidget(QWidget *parent) :
    QWidget(parent)
{
    // Code related to view:

    //---> View components.
    this->search_filed = new QLineEdit();
    this->search_filed->setPlaceholderText("Enter your query here...");
    this->name = new QRadioButton("name");
    this->address = new QRadioButton("address");
    this->phone = new QRadioButton("phone");
    this->balance = new QRadioButton("balance");
    this->id = new QRadioButton("id");
    this->search = new QPushButton("Search");
    this->cancel = new QPushButton("cancel");
    this->search_type = "";
    this -> table = new QTableWidget();
    this -> table -> setRowCount(1);
    this -> table -> setColumnCount(5);
    QStringList labels;
    labels << tr("ID") << tr("NAME")<< tr("ADDRESS")<< tr("PHONE")<< tr("BALANCE");
    this -> table -> setHorizontalHeaderLabels(labels);
    this->table->horizontalHeader()->setStretchLastSection(true);
    for(int i=0;i<5;i++)
        this->table->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);

    //---> Horizontal layout for the radio_buttons.
    QHBoxLayout *lay_H1= new QHBoxLayout();
    lay_H1 -> addWidget(this->id);
    lay_H1 -> addWidget(this->name);
    lay_H1 -> addWidget(this->address);
    lay_H1 -> addWidget(this->phone);
    lay_H1 -> addWidget(this->balance);

    //---> Horizontal layout for the Search & Cancel push_buttons.
    QHBoxLayout *lay_H2 = new QHBoxLayout();
    lay_H2 -> addWidget(this->search);
    lay_H2 -> addWidget(this->cancel);

    //---> Main widget Vertical layout.
    QVBoxLayout *lay_V = new QVBoxLayout();
    lay_V -> addWidget(this->search_filed);
    lay_V -> addLayout(lay_H1);
    lay_V -> addLayout(lay_H2);
    lay_V -> addWidget(table);

    this->setLayout(lay_V);

    QObject::connect(this->search, SIGNAL(clicked()), this, SLOT(search_watcher()) );

    //---> Connecting all the radio_buttons SIGNALS to the update_search_type() SLOT.
    QObject::connect(this->id, SIGNAL(clicked()), this, SLOT(update_search_type()) );
    QObject::connect(this->name, SIGNAL(clicked()), this, SLOT(update_search_type()) );
    QObject::connect(this->address, SIGNAL(clicked()), this, SLOT(update_search_type()) );
    QObject::connect(this->phone, SIGNAL(clicked()), this, SLOT(update_search_type()) );
    QObject::connect(this->balance, SIGNAL(clicked()), this, SLOT(update_search_type()) );
}

void QueryWidget::search_watcher(){
    emit send_values(this->search_filed->text(), this->search_type);
}

void QueryWidget::update_search_type(){
    if (this->id->isChecked())
        this->search_type = "id";
    else if(this->name->isChecked())
        this->search_type = "name";
    else if(this->address->isChecked())
        this->search_type = "address";
    else if(this->phone->isChecked())
        this->search_type = "phone";
    else if(this->balance->isChecked())
        this->search_type = "balance";
}

void QueryWidget::update_query_table(QSqlQuery sqlquery){ // Populating the view table with the result queries.
    int row = 0;
    this->table->setRowCount(1);
    while(sqlquery.next()){
        this-> table -> setItem(row, 0, new QTableWidgetItem(sqlquery.value("id").toString()));
        this-> table -> setItem(row, 1, new QTableWidgetItem(sqlquery.value("name").toString()));
        this-> table -> setItem(row, 2, new QTableWidgetItem(sqlquery.value("address").toString()));
        this-> table -> setItem(row, 3, new QTableWidgetItem(sqlquery.value("phone").toString()));
        this-> table -> setItem(row, 4, new QTableWidgetItem(sqlquery.value("balance").toString()));
        row ++;
        this -> table -> insertRow(1);
    }
}
