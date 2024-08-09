#include <stdio.h>
#include <stdlib.h>
#include <cstring>
typedef struct{

  int vertices;
  int* edgeListSize;
  int** edgeList;
  int* countersPerVertex;

  void initialize(const char* graphDataset){
FILE* fp = fopen(graphDataset, "r");

    int src, dst;
    int maxVertexID = -1;

    while(fscanf(fp, "%d %d", &src, &dst) != EOF){
      if (src > maxVertexID){
        maxVertexID = src;
      }
      if (dst > maxVertexID){
        maxVertexID = dst;
      }
    }

    this->vertices = maxVertexID + 1;

    rewind(fp);

    edgeListSize = (int*)malloc(vertices*sizeof(int));

    while(fscanf(fp, "%d %d", &src, &dst) != EOF){
      edgeListSize[src]++;
    }

    edgeList = (int**)malloc(vertices*sizeof(int*));

    for(int i = 0; i < vertices; i++){
      edgeList[i] = (int*)malloc( edgeListSize[i] *sizeof(int));
    }

    countersPerVertex = (int*)malloc(vertices*sizeof(int));
    memset(countersPerVertex, 0, vertices*sizeof(int));

    rewind(fp);

  }
  void addEdge(int src, int dst){
    edgeList[src][countersPerVertex[src]++] = dst;
  }
  bool isNeighbour(int src, int dst){

    for(int i = 0; i < edgeListSize[src]; i++){
      if(edgeList[src][i] == dst){
        return true;
      }
    }
    
    for(int i = 0; i < edgeListSize[dst]; i++){
      if(edgeList[dst][i] == src){
        return true;
      }
    }

    return false;
  }
  int getVertices(){
    return vertices;
  }
  int getEdgeListSize(int src){
    return edgeListSize[src];
  }
  int getEdge(int src, int pos){
    return edgeList[src][pos];
  }
  void release(){
    // Memory release
    for(int i = 0; i <vertices; i++){
      free(edgeList[i]);
    }

    free(edgeList);
    free(edgeListSize);
    free(countersPerVertex);
  }
} Graph;

int main(){

  Graph* graph = (Graph*)malloc(sizeof(Graph));
  graph->initialize("graph.edgelist");

  FILE* fp = fopen("graph.edgelist", "r");
  int src, dst;

  while(fscanf(fp, "%d %d", &src, &dst) != EOF){
    graph->addEdge(src, dst);
  }

  for(int i = 0; i < graph->getVertices(); i++){
    for(int j = 0; j < graph->getEdgeListSize(i); j++){
      printf("%d %d\n", i, graph->getEdge(i, j));
    }
  }

  graph->release();

}
