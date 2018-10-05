//топологическая сортировка

#include<iostream>
#include<vector>
#include<utility>

using namespace std;

int n; // число вершин

int** g=new int*[n]; // граф

bool* used=new bool[n];

vector<int> ans;// дополнительный массив

void dfs (int v) {
     used[v] = 1;
     for (int i=0; i<n; ++i) {
        if (used[i]==0 && g[v][i]==1)
            dfs (i);
    }
    ans.push_back (v+1);
}


void top_sort() {

    for (int i = 0; i < n; i++){
		if (used[i]==0){dfs (i);}
    }

    vector <int> m;
	for (int i = 0; i < n; i++){
        m.push_back(ans[i]);
	}
	for (int i = 0; i < n; i++){
        ans[n - 1 - i] = m[i];
	}


}

void make_matrix_adj(vector<pair<int,int> > gr1){
        for(int k=0; k<gr1.size(); k++){
            g[gr1[k].first-1][gr1[k].second-1]=1;
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

    //матрица смежности
    for(int i=0; i<n; i++){
        g[i]=new int[n];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            g[i][j]=0;
        }
    }

    make_matrix_adj(h);


    top_sort();
    cout<<endl<<"top_sort: ";

    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }

    delete[] used;
    for(int i=n-1; i<-1; i++){
        delete[] g[i];
    }
    return 0;
}

