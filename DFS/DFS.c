#include<stdlib.h>
#include<stdio.h>

#define MAX 100

#define initial 1
#define visited 2

void graph_traversal();
void DFS(int vertex);
void make_graph();
void push(int vertex);
int pop();
int isEmpty();

int stack[MAX];
int top = -1;
int vertices;
int adjacent_matrix[MAX][MAX];
int vertex_status[MAX];
char ar[MAX];
int main()
{
      make_graph();
      graph_traversal();
      return 0;
}

void graph_traversal()
{
      int vertex;
      for(vertex = 0; vertex < vertices; vertex++)
      {
            vertex_status[vertex] = initial;
      }
      printf("Enter Starting Vertex for DFS:\t");
      scanf("%d", &vertex);
      DFS(vertex);
      printf("\n");
}

void DFS(int vertex)
{
      int count;
      push(vertex);
      while(!isEmpty())
      {
            vertex = pop();
            if(vertex_status[vertex] == initial)
            {
                //  printf("%3d", vertex);
                  printf("%c\t",ar[vertex]);
                  vertex_status[vertex] = visited;
            }
            for(count = vertices - 1; count >= 0; count--)
            {
                  if(adjacent_matrix[vertex][count] == 1 && vertex_status[count] == initial)
                  {
                        push(count);
                  }
            }
      }
}

void push(int vertex)
{
      if(top == (MAX - 1))
      {
            printf("Stack Overflow\n");
            return;
      }
      top = top + 1;
      stack[top] = vertex;
}

int pop()
{
      int vertex;
      if(top == -1)
      {
            printf("Stack Underflow\n");
            exit(1);
      }
      else
      {
            vertex = stack[top];
            top = top - 1;
            return vertex;
      }
}

int isEmpty()
{
      if(top == -1)
      {
            return 1;
      }
      else
      {
            return 0;
      }
}

void make_graph()
{
      int i, edges, origin_vertex, destination_vertex;
      printf("Number of vertices:\t");
      scanf("%d", &vertices);
      for(i=0;i<vertices;i++)
      {
        printf("%dth Vertex name\t",i+1);
        scanf("\t%c",&ar[i]);
      }
      printf("Number of edges\t");
      scanf("%d",&edges);
      for(i = 0; i < edges; i++)
      {
            printf("Enter %dth Edge  Co-ordinates  [-1 -1] to Quit\n", i + 1);
            printf("Enter Origin Vertex Point:\t");
            scanf("%d", &origin_vertex);
            printf("Enter Destination Vertex Point:\t");
            scanf("%d", &destination_vertex);
            if((origin_vertex == -1) && (destination_vertex == -1))
            {
                  break;
            }
            if(origin_vertex >= vertices || destination_vertex >= vertices || origin_vertex < 0 || destination_vertex < 0)
            {
                  printf("Edge Co - ordinates are Invalid\n");
                  i--;
            }
            else
            {
                  adjacent_matrix[origin_vertex][destination_vertex] = 1;
            }
      }
}