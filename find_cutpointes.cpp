//поиск шарниров

#include <iostream>
#include <vector>
#include<utility>


using namespace std;

int v; 
bool* used = new bool[v];
int timer;
int* t_in = new int[v];
int* f_up = new int[v];
int** g = new int* [v];


void cutpoint(int a){
    
    cout<<endl<<"("<<a+1<<")";

}


void dfs(int k, int p=-1){
    
    used[k]=1;
    t_in[k]=f_up[k]=timer++;
    int kids=0;
    
    for (int i=0; i<v; i++){
        
        if (g[k][i]!=0){
            
            int to=i;
            
            if (to==p) continue;
            
            if (used[to])
                f_up[k]=min(f_up[k], t_in[to]);
            
            else{
                dfs(to, k);
                f_up[k]=min(f_up[k], f_up[to]);
                
                if (f_up[to]>=t_in[k]&&p!=-1){
                    cutpoint(k);
                }
                
                kids++;
            }
        }
    }
    
    if (p==-1 && kids>1)
        cutpoint(k);
}



void make_matrix_adj(vector<pair<int,int> > gr1, int** matr){
        for(int k=0; k<gr1.size(); k++){
            matr[gr1[k].first-1][gr1[k].second-1]=1;
            matr[gr1[k].second-1][gr1[k].first-1]=1;
        }


  }

int main(){
    int E;
    cout<<"print number of vertices: ";
    cin>>v;
    cout<<"print number of edges: ";
    cin>>E;


    //список ребер
    vector<pair<int,int> > h;


    //заполнение списка
    int f,s;
    for(int i=0; i<E; i++){
        cout<<"enter data for the "<<i+1<<" edge "<<endl<<"beginning: ";
        cin>>f;
        cout<<"end: ";
        cin>>s;
        h.push_back(make_pair(f,s));
        cout<<endl;
    }

    //матрица смежностей
    for(int i=0; i<v; i++){
        g[i]=new int[v];
        used[i]=0;
    }

    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            g[i][j]=0;
        }
    }

    make_matrix_adj( h, g);

    timer=0;
    
    
    cout<<"cutpointes: ";
    dfs(0);
	

	return 0;
}
