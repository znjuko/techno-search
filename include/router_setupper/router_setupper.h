//
// Created by paccbet on 14.04.2021.
//

#ifndef TECHNO_SEARCH_ROUTER_SETUPPER_H
#define TECHNO_SEARCH_ROUTER_SETUPPER_H

#include <pistache/endpoint.h>
#include <pistache/router.h>

using namespace Pistache;
using namespace Rest;

class IRouterSetupper
{
  public:
    virtual void SetupService(Rest::Router *router) = 0;

    virtual ~IRouterSetupper() noexcept = 0;
};

#endif // TECHNO_SEARCH_ROUTER_SETUPPER_H
