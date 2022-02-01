#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

struct Vertex {
   char label;
   bool visited;
};
int queue[MAX];
int rear = -1;
int front = 0;
int queueItemCount = 0;
struct Vertex* lstVertices[MAX];
int adjMatrix[MAX][MAX];
int vertexCount = 0;
void insert(int data) {
   queue[++rear] = data;
   queueItemCount++;
}

int removeData() {
   queueItemCount--;
   return queue[front++];
}

bool isQueueEmpty() {
   return queueItemCount == 0;
}
void addVertex(char label) {
   struct Vertex* vertex = (struct Vertex*) malloc(sizeof(struct Vertex));
   vertex->label = label;
   vertex->visited = false;
   lstVertices[vertexCount++] = vertex;
}

void addEdge(int start,int end) {
   adjMatrix[start][end] = 1;
   adjMatrix[end][start] = 1;
}

void displayVertex(int vertexIndex) {
   printf("%c ",lstVertices[vertexIndex]->label);
}

int getAdjUnvisitedVertex(int vertexIndex) {
   int i;

   for(i = 0; i<vertexCount; i++) {
      if(adjMatrix[vertexIndex][i] == 1 && lstVertices[i]->visited == false)
         return i;
   }

   return -1;
}

void breadthFirstSearch() {
   int i;

   lstVertices[0]->visited = true;

   displayVertex(0);

   insert(0);
   int unvisitedVertex;

   while(!isQueueEmpty()) {
      int tempVertex = removeData();

      while((unvisitedVertex = getAdjUnvisitedVertex(tempVertex)) != -1) {
         lstVertices[unvisitedVertex]->visited = true;
         displayVertex(unvisitedVertex);
         insert(unvisitedVertex);
      }

   }

   for(i = 0;i<vertexCount;i++) {
      lstVertices[i]->visited = false;
   }
}

int main() {
   int i, j,n1,n2,e1,e2;
   char var;

   for(i = 0; i<MAX; i++)  {
      for(j = 0; j<MAX; j++)
         adjMatrix[i][j] = 0;
   }
    printf("Enter number of vertices\t");
    scanf("%d",&n1);
    printf("Number of edges\t");
    scanf("%d",&n2);
   for(i=0;i<n1;i++)
    {
        printf("Insert %dth vertex charactor\t",i+1);
        scanf("\t%c",&var);
        addVertex(var);
    }
    for(i=0;i<n2;i++)
    {
        printf("Insert %dth edge\n",i+1);
        printf("Initial point\t");
        scanf("%d",&e1);
        printf("terminal point\t");
        scanf("%d",&e2);
        addEdge(e1,e2);
    }

   printf("\nBreadth First Search: ");

   breadthFirstSearch();
   printf("\n");
   return 0;
}