#ifndef TECHNO_SEARCH_JSONGRAPHCONVERTER_H
#define TECHNO_SEARCH_JSONGRAPHCONVERTER_H

class JSONGraphConverter{
private:
    .json geoJSON;
    *double pointsArray;
    **double adjacencyTable;
    *size_t counterArray;
public:
    void JSONGraphConverter(.json geoJSON);
    *double GeneratePointsArray(.json geoJSON);
    **double GenerateAdjacencyTable(*double pointsArray);
};

#endif //TECHNO_SEARCH_JSONGRAPHCONVERTER_H
