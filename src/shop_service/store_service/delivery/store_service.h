//
// Created by fillinmar on 14.04.2021.
//

#ifndef TECHNO_SEARCH_STORE_SERVICE_H
#define TECHNO_SEARCH_STORE_SERVICE_H

class StoreService
{
  private:
    RequestReader requestReader;
    ResponseWrite responseWriter;
    StoreManager store;

  public:
    void GetStoreMetadata(Http::Request req, Http : ResponseWriter res);
    void GetListStore(Http::Request req, Http : ResponseWriter res);
    void SetupService(Http : router);
};
#endif // TECHNO_SEARCH_STORE_SERVICE_H
