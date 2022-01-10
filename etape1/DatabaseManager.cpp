#include "DatabaseManager.h"
#include <iostream>

DatabaseManager *DatabaseManager::instance = new DatabaseManager();

DatabaseManager::DatabaseManager(){
    database = QSqlDatabase::addDatabase(DRIVER);
    database.setDatabaseName("app.db");
    if(!this->database.open()) qWarning() << "Error: " << database.lastError();

    // Creating database
    QSqlQuery query("CREATE TABLE if not exists utilisateur (email TEXT PRIMARY KEY, nom TEXT, prenom TEXT, mdp TEXT)");
    if(!query.isActive()) qWarning() << "Error: " << database.lastError();
}

QSqlDatabase DatabaseManager::getDatabase(){
    if(instance == nullptr) instance = new DatabaseManager();
    return instance->database;
}
