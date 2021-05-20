#ifndef TECHNO_SEARCH_GRAPH_CONVERTER_H
#define TECHNO_SEARCH_GRAPH_CONVERTER_H

#include "shop_map.h"
#include "map_models.h"
#include <vector>

class GraphConverter{

public:
    std::vector<std::vector<double>> Generate(Map map);
private:

};

#endif //TECHNO_SEARCH_GRAPH_CONVERTER_H
