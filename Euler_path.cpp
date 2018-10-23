#include<iostream>
#include<vector>
#include<utility>
#include<queue>

using namespace std;

int v; // число вершин

int** g=new int*[v]; // граф


void dfs(int n, bool* used){
    used[n]=1;
    for(int i=0; i<v; i++){
        if(used[i]==0 && g[n][i]==1) {
            dfs(i,used);

    }
 }
}

int number_of_con_com(bool* used){//подсчет компонент связности
    int t=1;
    for(int j=0; j<v; j++){
        if(used[j]==0){
            dfs(j,used);
            t++;
        }
    }
    return t;
}


int chetnosti(int** f, int y){//подсчет количества вершин с нечетной степенью
        int temp=0, z;

        for(int i=0; i<y; i++){
                z=0;

            for(int j=0; j<y; j++){
                if(f[i][j]==1){z++;}
            }
            if(z%2==1) {temp++;}
        }
    return temp;
}

void el(int** r, int e, bool* u){
            if(chetnosti(r,e)<3 && number_of_con_com(u)==1 ){
                cout<<"yes";
            }
            else{
                cout<<"no";
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
    
    dfs(0,us);
     
    el(g,v,us);


    return 0;
}

