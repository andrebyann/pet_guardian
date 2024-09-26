#include "database.h"
#include <iostream>

Database::Database(const std::string &dbName) : dbName(dbName), db(nullptr) {}

Database::~Database() {
    close();
}

bool Database::open() {
    if (sqlite3_open(dbName.c_str(), &db) != SQLITE_OK) {
        std::cerr << "Erro ao abrir banco de dados: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    return true;
}

void Database::close() {
    if (db) {
        sqlite3_close(db);
    }
}

bool Database::createTable() {
    const char *sql = 
        "CREATE TABLE IF NOT EXISTS Animals ("
        "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
        "Name TEXT NOT NULL, "
        "Species TEXT NOT NULL, "
        "Weight REAL NOT NULL);";
    
    char *errMsg = nullptr;
    if (sqlite3_exec(db, sql, nullptr, nullptr, &errMsg) != SQLITE_OK) {
        std::cerr << "Erro ao criar tabela: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return false;
    }
    return true;
}

// Implementação das outras funções (insertAnimal, deleteAnimal, etc.) é semelhante
