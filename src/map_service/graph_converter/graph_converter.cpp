#include "shop_map.h"
#include <vector>
#include "map_models.h"
#include "graph_converter.h"

std::vector<std::vector<double>> GraphConverter::Generate(Map map) {

    std::vector<std::vector<double>> AdjacencyTable;

    std::vector<Polygon> counters = map.GetCounters();
    Polygon shop = map.GetShop();



    return AdjacencyTable;
}