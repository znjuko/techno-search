#ifndef TECHNO_SEARCH_MAP_MANAGER_H
#define TECHNO_SEARCH_MAP_MANAGER_H

class MapManager
{
  private:
    MapStorage mapStorage;

  public:
    GetGraphResponse GetGraph(GetGraph req);
    AddGraphResponse AddGraph(AddGraph req);
    UpdateGraphResponse UpdateGraph(UpdateGraph req);
    GetMapResponse GetMap(GetMap req);
    AddMapResponse AddMap(AddMap req);
    UpdateMapResponse UpdateMap(UpdateMap req);
};

#endif // TECHNO_SEARCH_MAP_MANAGER_H
