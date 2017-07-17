#include "widget.h"
#include <QApplication>

#include <QtSql>
#include <QSqlQuery>
#include <QDebug>
#include "DataBaseManager.h"
#include "querywidget.h"

#include <string>
#include <QTabWidget>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    DataBaseManager db("QMYSQL", "localhost", "DB_NAME", "YOUR_DB_USERNAME" ,"DB_PASSWORD" ); // Establishing connection with mysql DB.
    Widget new_bank_application_widget; //New_Client form widget.
    QueryWidget query_widget;   // Query widget.
    QTabWidget tab_widget;  // Tab widget that holds all widgets inside it.

    QObject::connect(&new_bank_application_widget, SIGNAL(send_values(QString,QString,QString,QString)),
                     &db, SLOT(insert_entry(QString,QString,QString,QString)));

    QObject::connect(&query_widget, SIGNAL(send_values(QString,QString)),
                     &db, SLOT(make_query(QString,QString)));

    QObject::connect(&db, SIGNAL(send_query_result(QSqlQuery)),
                     &query_widget, SLOT(update_query_table(QSqlQuery)));

    //---> Adding widgets to the Tab_widget.
    tab_widget.addTab(&new_bank_application_widget, QIcon(), "New");
    tab_widget.addTab(&query_widget, QIcon(), "query");
    tab_widget.setGeometry(0,0,550,500);
    tab_widget.show();

    return a.exec();
}
