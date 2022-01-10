#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

const QString DRIVER("QSQLITE");

/**
 * @brief Classe stockant la base de donnée
 *
 * @author Florian
 */
class DatabaseManager{

    /**
     * @brief instance du manager
     */
    static DatabaseManager* instance;
    /**
     * @brief base de données globale
     */
    QSqlDatabase database;

private:
    DatabaseManager();

public:
    /**
     * @brief Retourne la base de données statique
     * @return base de donnée
     */
    static QSqlDatabase getDatabase();

};

#endif // DATABASEMANAGER_H
