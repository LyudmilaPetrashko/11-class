//поиск мостов
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

void bridge(int a, int b){
    cout<<endl<<"("<<a+1<<","<<b+1<<")";
}


void dfs(int k, int p=-1){
    used[k]=1;
    t_in[k]=f_up[k]=timer++;
    for (int i=0; i<v; i++){
        if (g[k][i]!=0){
            int to=i;
            if (to==p) continue;
            if (used[to])
                f_up[k]=min(f_up[k], t_in[to]);
            else{
                dfs(to, k);
                f_up[k]=min(f_up[k], f_up[to]);
                if (f_up[to]>t_in[k])
                    bridge(k, to);
            }
        }
    }
}

void find_bridges() {
	timer=0;
	for (int i=0; i<v; i++){
		used[i] = 0;
	}
	for(int i=0; i<v; i++){
		if(!used[i])
			dfs(i);
	}
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

    bool* us=new bool[v];

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
        us[i]=0;
    }

    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            g[i][j]=0;
        }
    }

    make_matrix_adj( h, g);
    
    cout<<"bridges: ";
	find_bridges();

	return 0;
}
