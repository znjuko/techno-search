//
// Created by Никита Черных on 19.05.2021.
//

#include "storage.h"

Storage::Storage(std::shared_ptr<mongocxx::database> database) : database(database) {
};

std::shared_ptr<StoreModel> Storage::GetStoreData(const int& ID) {
    auto storeCollection = database->collection("store");

    auto selectStoreResult = storeCollection.find_one(make_document(kvp("ID", ID)));
    if(!selectStoreResult) {
        const StoreGraphNotFound e = StoreGraphNotFound(ID);
        throw e;
    }

    auto selectStoreOutput = bsoncxx::to_json(*selectStoreResult);
    return std::make_shared<StoreModel>(selectStoreOutput);
}

