#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>
#include <string>

class Database {
public:
    Database(const std::string &dbName);
    ~Database();

    bool open();
    void close();

    bool createTable();
    bool insertAnimal(const std::string &name, const std::string &species, float weight);
    bool deleteAnimal(int id);
    bool updateAnimal(int id, const std::string &name, const std::string &species, float weight);
    void listAnimals();

private:
    std::string dbName;
    sqlite3 *db;
};

#endif // DATABASE_H
