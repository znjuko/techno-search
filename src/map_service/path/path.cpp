#include "path.h"

FindPath::FindPath(size_t A, size_t B, double** AdjacencyTable, size_t size){
    double *distance = new double[size]; // минимальное расстояние
    size_t *vizited = new size_t[size]; // посещенные вершины
    const size_t limit = 10000;
    size_t temp, minindex;
    double min;
    size_t begin_index = A;
    for (int i = 0; i<size; i++){
      distance[i] = limit;
      vizited[i] = 1;
    }
    distance[begin_index] = 0;
    do {
      minindex = limit;
      min = limit;
      for (size_t i = 0; i<size; i++){
        if ((vizited[i] == 1) && (distance[i]<min))
        {
          min = distance[i];
          minindex = i;
        }
      }
      if (minindex != limit){
        for (size_t i = 0; i<size; i++){
          if (AdjacencyTable[minindex][i] > 0){
            temp = min + AdjacencyTable[minindex][i];
            if (temp < distance[i]){
              distance[i] = temp;
            }
          }
        }
        vizited[minindex] = 0;
      }
    } while (minindex < limit);

    path = new size_t[size];
    size_t end = B; // индекс конечной вершины
    path[0] = end + 1; // начальный элемент - конечная вершина
    int k = 1; // индекс предыдущей вершины
    int weight = distance[end]; // вес конечной вершины

    while (end != begin_index)
    {
      for (int i = 0; i<size; i++)
        if (AdjacencyTable[i][end] != 0)
        {
          temp = weight - AdjacencyTable[i][end];
          if (temp == distance[i])
          {
            weight = temp;
            end = i;
            path[k] = i + 1;
            k++;
          }
        }
    }
    delete []distance;
    delete []vizited;
  }


FindPath::size_t* GivePath(size_t *Array){
    return path;
}

FindPath::~FindPath(){
    delete[] path;
}
