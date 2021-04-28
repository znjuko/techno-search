#ifndef TECHNO_SEARCH_MAP_H
#define TECHNO_SEARCH_MAP_H

class Map {
private:
    .json geoJSON;
    **double counterArray;
    JSONGraphConverter jsonGraphConverter;
public:
    void Map(.json geoJson);
    .json GetShortestPath(.json coordinates);
};


#endif //TECHNO_SEARCH_MAP_H
