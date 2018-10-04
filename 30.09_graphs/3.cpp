//проверка существования пути

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

int number_of_con_com(int* used){
    int temp=1;
    for(int j=0; j<v; j++){
        if(used[j]==0){
            dfs(j, used);
            temp++;
        }
    }
    return temp;
}

//проверка существования пути
bool way(int x, int y, int* us){
    us[x-1]=1;
    for(int i=0; i<v; i++){
        if(us[i]==0 && g[x-1][i]==1) {
            if(i+1==y){return 1;}
            else{ return way(i+1, y, us);}
        }
     }
    return 0;
}


void make_matrix_adj(vector<pair<int,int> > gr1, int** matr){
        for(int k=0; k<gr1.size(); k++){
            matr[gr1[k].first-1][gr1[k].second-1]=1;
            matr[gr1[k].second-1][gr1[k].first-1]=1;
        }


  }

  void print_matrix_adj(int** n,int v){
      cout<<"adjacency matrix: "<<endl;
      for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                cout<<n[i][j]<<" ";
            }
            cout<<endl;
        }
}


int main(){



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
/////////////////////////////////////////////////////////////////////////////

    cout<<endl<<"way exists?: "<<way(1,2,used);

    delete[] used;
    for(int i=v-1; i>=0; i--){
        delete[] g[i];
    }

    return 0;
}
