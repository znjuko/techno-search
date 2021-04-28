//
// Created by fillinmar on 14.04.2021.
//

#ifndef TECHNO_SEARCH_STORE_MANAGER_H
#define TECHNO_SEARCH_STORE_MANAGER_H

class StoreManager{
private:
    StoreStorage: store;
public:
    GetStoreMetadataResponse GetStoreMetadata( GetStoreMetadataRequest req){};
    GetListStoreResponse GetListStore(GetListStoreRequest req);
    UpdateStoreMetadataResponse UpdateStoreMetadata(UpdateMetadataRequest req);
    AddListStoreResponse AddStore(AddStoreRequest req);
};

#endif //TECHNO_SEARCH_STORE_MANAGER_H
