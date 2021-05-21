//
// Created by Никита Черных on 20.05.2021.
//

#include "path_models.h"

void GetStorePathRequest::Marshall(const Rest::Request &req) {
    ShopID = boost::lexical_cast<int>(req.param(":shopID"));
    FromNode = boost::lexical_cast<int>(req.query().get("startNode"));
    ToNode = boost::lexical_cast<int>(req.query().get("endNode"));
}

GetStorePathRequest::GetStorePathRequest() : ShopID(0), FromNode(0), ToNode(0) {}

GetStorePathResponse::GetStorePathResponse(std::vector<size_t> Path) : Array(std::move(Path)) {}

nlohmann::json GetStorePathResponse::UnMarshall() {
    nlohmann::json output;
    nlohmann::json outputArray = nlohmann::json::array();
    for (size_t &item : Array) {
        outputArray.push_back(item);
    }
    output["path"] = outputArray;

    return output;
}


