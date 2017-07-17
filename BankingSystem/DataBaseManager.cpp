#include "DataBaseManager.h"

DataBaseManager::DataBaseManager(QString database, QString hostname,
                                 QString database_name, QString username,
                                 QString password){ // Establishing connection with the mysql_server DB.
    this->db = QSqlDatabase::addDatabase(database);
    this->db.setHostName(hostname);
    this->db.setDatabaseName(database_name);
    this->db.setUserName(username);
    this->db.setPassword(password);
}

DataBaseManager::~DataBaseManager(){
    delete this;
}

void DataBaseManager::make_query(QString value, QString type){

    if(! this->db.open())
        qDebug() << "Error connection with DataBase.";
    else
        qDebug() << "Successfully connection with DataBase.";

    this->mysqlquery = new QSqlQuery;
    QString temp_query = "select * from ACCOUNT where " + type + "="  + "\"" + value + "\"";
    this->mysqlquery->exec(temp_query);

    if (this->mysqlquery->size()>0){
        qDebug() << "Query result not Empty.";
        emit send_query_result(*this->mysqlquery);
    }
    else
        qDebug() << "Query result is Empty.";
}

void DataBaseManager::insert_entry(QString name, QString address, QString phone, QString balance){

    if(! this->db.open())
        qDebug() << "Error connection with DataBase.";
    else
        qDebug() << "Successfully connection with DataBase.";

    this->mysqlquery = new QSqlQuery;
    this->mysqlquery->prepare("insert into ACCOUNT (NAME, ADDRESS, PHONE, BALANCE)"
                              "values (:name, :address, :phone, :balance)");
    this->mysqlquery->bindValue(":name",name);
    this->mysqlquery->bindValue(":address",address);
    this->mysqlquery->bindValue(":phone",phone);
    this->mysqlquery->bindValue(":balance",balance);

    this->mysqlquery->exec();
}
