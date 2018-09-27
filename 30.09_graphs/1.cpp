#include<iostream>
#include<vector>
using namespace std;

struct edge{ //ребро
    int x1, x2;
};


struct graph{
  
  int e;//количество ребер 
  
  edge* l_e= new edge[e];// список ребер
  
  graph(){e=0;}
      
  graph(int ee): e(ee){
      for(int i=0; i<e; i++){
          l_e[i].x1=0;
          l_e[i].x2=0;
          }
  }
  
  graph(const graph &gr){
      e=gr.e;
      for(int i=0; i<e; i++){
          l_e[i].x1=gr.l_e[i].x1;
          l_e[i].x2=gr.l_e[i].x2;
      }
  }
  
};

void read_list_edges(graph y){
       for(int i=0; i<y.e; i++){
          cout<<"print data for "<<i+1<<" edge: ";
          cin>>y.l_e[i].x1>>y.l_e[i].x2;
      }
  }
  
  void print_list_edges(graph x){
      cout<<endl;
      for(int j=0; j<x.e; j++){
         cout<<j+1<<") "<<x.l_e[j].x1<<", "<<x.l_e[j].x2<<endl;
      }
  }
  

int main(){
    graph g(5);
    read_list_edges(g);
    print_list_edges(g);
    
    return 0;
}
