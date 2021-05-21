//
// Created by Никита Черных on 21.05.2021.
//

#ifndef TECHNO_ALGO_PATH_DELIVERY_H
#define TECHNO_ALGO_PATH_DELIVERY_H


#include "path_usecase.h"
#include "reader.h"
#include "router_setupper.h"
#include "writer.h"
#include "path_models.h"


#include <pistache/endpoint.h>
#include <pistache/router.h>

using namespace Pistache;

class Delivery : public IRouterSetupper {
public:

private:
    std::shared_ptr<JsonResponseWriter> responseWriter;
    std::shared_ptr<JsonRequestBodyReader> bodyReader;
    std::shared_ptr<ErrorResponseWriter> errorWriter;
    std::shared_ptr<RequestQueryReader> queryReader;
    std::shared_ptr<PathManager> manager;
};


#endif //TECHNO_ALGO_PATH_DELIVERY_H
