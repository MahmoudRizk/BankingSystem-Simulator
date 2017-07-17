#ifndef QUERYWIDGET_H
#define QUERYWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QRadioButton>
#include <QPushButton>
#include <QTableWidget>
#include <QSqlQuery>

class QueryWidget : public QWidget{ // Implementation of querying view and the results table.
    Q_OBJECT
public:
    explicit QueryWidget(QWidget *parent = 0);
    QLineEdit *search_filed;
    QRadioButton *id;
    QRadioButton *name;
    QRadioButton *address;
    QRadioButton *phone;
    QRadioButton *balance;
    QPushButton *search;
    QPushButton *cancel;
    QTableWidget *table;
    QString search_type; // Holds the value of the active radio button.

signals:
    void send_values(QString, QString); //Send values to DataBaseManager with the search constraints.

public slots:
    void search_watcher();  // Waits for the search_button clilcked() SIGNAL then emits send_values() SIGNAL.
    void update_search_type(); // Update the search_type value, when radiobutton fires it's SIGNAL.
    void update_query_table(QSqlQuery);// Receives the query result from DataBaseManager then view it in the table.

};

#endif // QUERYWIDGET_H
