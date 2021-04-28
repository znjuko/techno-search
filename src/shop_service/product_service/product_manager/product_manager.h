//
// Created by fillinmar on 14.04.2021.
//

#ifndef TECHNO_SEARCH_STORE_MANAGER_H
#define TECHNO_SEARCH_STORE_MANAGER_H

class ProductManager{
private:
    ProductStorage: store;
public:
    GetProductMetadataResponse GetStoreMetadata( GetProductMetadataRequest req){};
    GetListProductResponse GetListStore(GetListProductRequest req);
    UpdateProductResponse UpdateProductMetadata(UpdateMetadataRequest req);
    AddProductResponse AddStore(AddProductRequest req);
};

#endif //TECHNO_SEARCH_STORE_MANAGER_H
