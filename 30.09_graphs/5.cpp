/*поиск кратчайшего пути между 2 вершинами*/

#include<iostream>
#include<vector>
#include<utility>
#include<queue>

using namespace std;

int n; // число вершин

int** g=new int*[n]; // граф

bool* used=new bool[n];//доп. массив

queue<int> q;

vector<int>p, d;// в р[] хранится предыдущая вершина для вершины-индекса(т.е. родиель), в d[] - длина пути из заданной вершины в вершину-индекс. 

void bfs (int v1, int v2) { // поиск кратчайшего пути
    int temp;
    
    for(int x=0; x<n; x++){
        p.push_back(temp);
        d.push_back(temp);
    }
    
    int t=v1-1;

     used[t] = 1;
     p[t]=0;
     d[t]=0;
     q.push(t);
     while(!q.empty()){
         int k=q.front();
         q.pop();
         for(int i=0; i<n; i++){
             if(!used[i] && g[k][i]==1){
                used[i]=1;
                q.push(i);
                d[i]=d[k]+1;
                p[i]=k;
             }
         }
     }
    if(!used[v2-1]){
        cout<<"no path";
    }
    else{

        vector<int> path;
    
        for(int i=v2-1; i!=0; i=p[i]){

            path.push_back(i+1);
        }
    
        cout<<"path: "<<v1<<" ";
        for(int j=path.size()-1; j>-1; j--){
            cout<<path[j]<<" ";
        }
        cout<<endl<<"path length = "<<d[v2-1];
    }
}


void make_matrix_adj(vector<pair<int,int> > gr1){
        for(int k=0; k<gr1.size(); k++){
            g[gr1[k].first-1][gr1[k].second-1]=1;
        }
    }


int main(){

    int E;
    cout<<"print number of vertices: ";
    cin>>n;
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
    for(int i=0; i<n; i++){
        g[i]=new int[n];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            g[i][j]=0;
        }
    }

    make_matrix_adj(h);

    bfs( 1, 2);

    return 0;
}

