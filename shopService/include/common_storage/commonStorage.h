//
// Created by fillinmar on 14.04.2021.
//

#ifndef TECHNO_SEARCH_COMMONSTORAGE_H
#define TECHNO_SEARCH_COMMONSTORAGE_H

#include <string>

class Query {
public:
    virtual ~Query()=default;
    virtual std::string GetQuery()=0;
};

class IntQuery : public IQuery {
public:
    IntQuery(int value) : value(value) {};

    virtual std::string GetQuery() override {
        return std::to_string(value);
    }

private:
    int value;
};

class StringQuery : public IQuery {
public:
    StringQuery(std::string value) : value(value) {};

    virtual std::string GetQuery() override {
        return value;
    }

private:
    std::string value;
};

class FloatQuery : public IQuery {
public:
    FloatQuery(float value) : value(value) {};

    virtual std::string GetQuery() override {
        return std::to_string(value);;
    }

private:
    float value;
};

class CommonStorage {
private:
    PSQL client;
public:
    void Insert(Querty *q, string field, string nameStore){

    };
    void Update(Querty *q, string field, string nameStore){

    };
    Row GetMetaData(string nameStore);
    Rows GetListMetaData(string nameStore);

};

#endif //TECHNO_SEARCH_COMMONSTORAGE_H
