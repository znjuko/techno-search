//
// Created by Никита Черных on 20.05.2021.
//

#ifndef TECHNO_ALGO_PATH_MODELS_H
#define TECHNO_ALGO_PATH_MODELS_H

#include "marshaller.h"
#include "unmarshaller.h"
#include "common_exceptions.h"

#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <nlohmann/json.hpp>
#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>
#include <vector>

using namespace Pistache;

class GetStorePathRequest : public IRequestMarshaller {
public:
    GetStorePathRequest();

    void Marshall(const Rest::Request &req) override;

    ~GetStorePathRequest() override = default;

    int ShopID, FromNode, ToNode;
};

class GetStorePathResponse : public IUnMarshaller {
public:
    explicit GetStorePathResponse(std::vector<size_t> Path);

    nlohmann::json UnMarshall() override;

    ~GetStorePathResponse() override = default;

    std::vector<size_t> Array;
};

#endif // TECHNO_ALGO_PATH_MODELS_H
