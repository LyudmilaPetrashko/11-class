//проверить, находятся ли 2 вершины в одной компоненте связности

#include<iostream>
#include<vector>
using namespace std;

int v;
int** g=new int*[v];


void dfs(int n, int* used){

    used[n]=1;
    for(int i=0; i<v; i++){
        if(used[i]==0&&g[n][i]==1) {
            dfs(i, used);
    }
 }
}


void make_matrix_adj(vector<pair<int,int> > gr1, int** matr){
        for(int k=0; k<gr1.size(); k++){
            matr[gr1[k].first-1][gr1[k].second-1]=1;
            matr[gr1[k].second-1][gr1[k].first-1]=1;
        }


  }


int main(){

    int a,b;




    int E;
    cout<<"print number of vertices: ";
    cin>>v;
    cout<<"print number of edges: ";
    cin>>E;

    int* used = new int[v];// дополнительный массив
    for(int j=0; j<v; j++){
        used[j]=0;
    }


    //список ребер
    vector<pair<int,int> > h;

    //заполнение списка
    int f,s;
    for(int i=0; i<E; i++){
        cout<<"enter data for the "<<i+1<<" edge: ";
        cin>>f>>s;
        h.push_back(make_pair(f,s));
    }

    //матрица смежностей
    for(int i=0; i<v; i++){
        g[i]=new int[v];
    }

    for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                g[i][j]=0;
            }
        }

    make_matrix_adj(h,g);

    cout<<"enter the number of the first vertex: ";
    cin>>a;
    cout<<"enter the number of the second vertex: ";
    cin>>b;

/////////////////////////////////////////////////////////////////////////////

    dfs(g[a-1][0], used);
    if(used[b-1]==1){
        cout<<endl<<"yes";
    }
    else{
        cout<<endl<<"no";
    }

    delete[] used;
    for(int i=v-1; i>=0; i--){
        delete[] g[i];
    }

    return 0;
}
