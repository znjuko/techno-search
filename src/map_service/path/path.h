#ifndef TECHNO_SEARCH_PATH_H
#define TECHNO_SEARCH_PATH_H

class FindPath{
private:
  size_t *path;
public:
  FindPath(size_t A, size_t B, double** AdjacencyTable, size_t size);
  size_t* GivePath(size_t *Array);
  ~FindPath();
};

#endif // TECHNO_SEARCH_PATH_H
