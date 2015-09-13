#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define ROWS 7
#define COLS 7


int graph [ROWS][COLS] = { 0, 7, 0, 5, 0, 0, 0,
                           7, 0, 8, 9, 7, 0, 0,
                           0, 8, 0, 0, 5, 0, 0,
                           5, 9, 0, 0, 15, 6, 0,
                           0, 7, 5, 15, 0, 8, 9,
                           0, 0, 0, 6, 8, 0, 11,
                           0, 0, 0, 0, 9, 11, 0 
                         };

bool visit[COLS];
int dist[COLS];


int choose(int size){

  int min = 1e9;
  int k;
  int re_value;
    re_value = -1;
   for(k = 0; k < size; k++){
      if(dist[k] < min && visit[k]!=true){
        min = dist[k];
        re_value = k;
       }
    }

   return re_value;
}



void prim()
{  
   int i;
   for(i = 0; i < ROWS; i++)visit[i]=false;
   for(i = 0; i < ROWS; i++)dist[i] = 1e9;

   dist[0] = 0; //dist[x],x can be any start node in graph.

   for(i = 0; i < ROWS; i++)
   {
         int u = -1;
          u = choose(7);
         if(u == -1)break;
         visit[u] = true;
      
       int w;
       for(w = 0; w < ROWS; w++){
           if(!visit[w] && graph[u][w]!=0){
                   if(graph[u][w] < dist[w]){
                      dist[w] = graph[u][w];
                    }      
           }

       }
   }


}










int main(){


   prim();

  int k;
  for(k = 0; k < ROWS; k++)printf(" %d ",dist[k]);




  return 0;
}
