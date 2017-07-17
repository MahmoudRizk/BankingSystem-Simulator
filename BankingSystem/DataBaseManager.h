#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H


#include <QtSql>
#include <QSqlQuery>
#include <QDebug>



class DataBaseManager : public QObject{ // Manages connection, query & modification of mysql_server DB .

    Q_OBJECT

    private:
        QSqlDatabase db;
        QSqlQuery *mysqlquery;
    public:
        explicit DataBaseManager(QString database, QString hostname,
                                 QString database_name, QString username,
                                 QString password);
        ~DataBaseManager();

    signals:
        void send_query_result(QSqlQuery); // Sends the query result to the table view.


    public slots:
        void make_query(QString type, QString value);  //make query which matches type and value.
        void insert_entry(QString name, QString address, QString phone, QString balance); //insert new entry to DB.

};

#endif // BATABASEMANAGER_H
