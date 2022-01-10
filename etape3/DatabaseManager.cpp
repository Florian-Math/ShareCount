#include "DatabaseManager.h"
#include <iostream>

DatabaseManager *DatabaseManager::instance = nullptr;

DatabaseManager::DatabaseManager(){
    database = QSqlDatabase::addDatabase(DRIVER);
    database.setDatabaseName("app.db");
    if(!this->database.open()) qWarning() << "Error: " << database.lastError();

    // Creating database
    QSqlQuery query("CREATE TABLE if not exists utilisateur (email TEXT NOT NULL PRIMARY KEY, nom TEXT, prenom TEXT, mdp TEXT NOT NULL)");
    if(!query.isActive()) qWarning() << "Error: " << database.lastError();

    QSqlQuery query2("CREATE TABLE if not exists Compte (id INTEGER PRIMARY KEY AUTOINCREMENT, titre TEXT NOT NULL, description TEXT)");
    if(!query2.isActive()) qWarning() << "Error: " << database.lastError();

    QSqlQuery query3("CREATE TABLE if not exists ParticipantsCompte (id INTEGER NOT NULL, email TEXT NOT NULL, PRIMARY KEY(id, email))");
    if(!query3.isActive()) qWarning() << "Error: " << database.lastError();

    QSqlQuery query4("CREATE TABLE if not exists Cagnotte (id INTEGER PRIMARY KEY AUTOINCREMENT, titre TEXT NOT NULL, description TEXT)");
    if(!query4.isActive()) qWarning() << "Error: " << database.lastError();

    QSqlQuery query5("CREATE TABLE if not exists ParticipantsCagnotte (id INTEGER NOT NULL, email TEXT NOT NULL, PRIMARY KEY(id, email))");
    if(!query5.isActive()) qWarning() << "Error: " << database.lastError();
}

QSqlDatabase DatabaseManager::getDatabase(){
    if(instance == nullptr) instance = new DatabaseManager();
    return instance->database;
}
