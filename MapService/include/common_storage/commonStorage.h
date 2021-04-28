#ifndef TECHNO_SEARCH_COMMONSTORAGE_H
#define TECHNO_SEARCH_COMMONSTORAGE_H

#include <string>


class CommonStorage {
private:
    PSQL client;
public:
    void InsertData(.json value, .json field, size_t ShopID){

    };
    void Update(.json value, .json field, size_t ShopID){

    };
    Row GetDataJSON(size_t ShopID);
    Rows GetDataGraph(size_t ShopID);
};

#endif //TECHNO_SEARCH_COMMONSTORAGE_H
