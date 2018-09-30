#include<iostream>
#include<vector>
#include <utility>
#include<list>
using namespace std;


 void print_list_edges(vector<pair<int,int> > gr){
      cout<<endl<<"list edges: "<<endl;
      for(int j=0; j<gr.size(); j++){
         cout<<j+1<<") "<<gr[j].first<<", "<<gr[j].second<<endl;
      }
  }

  void make_matrix_adj(vector<pair<int,int> > gr1, bool** matr){
        for(int k=0; k<gr1.size(); k++){
            matr[gr1[k].first-1][gr1[k].second-1]=1;
            matr[gr1[k].second-1][gr1[k].first-1]=1;
        }


  }

  void print_matrix_adj(bool** n,int v){
      cout<<"adjacency matrix: "<<endl;
      for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                cout<<n[i][j]<<" ";
            }
            cout<<endl;
        }
}

void make_matrix_in(vector<pair<int,int> > p,bool** q){//1-ребро, 2- вершина
    for(int i=0; i<p.size(); i++){
        q[i][p[i].first-1]=1;
        q[i][p[i].second-1]=1;
    }
}

void print_matrix_in(bool** w,int r, int v){
     cout<<"incidence matrix: "<<endl;
      for(int i=0; i<r; i++){
            for(int j=0; j<v; j++){
                cout<<w[i][j]<<" ";
            }
            cout<<endl;
        }
}

void make_list_con(vector<pair<int,int> > a, vector<vector<int> > &b, int k){//1-данная вершина, 2-те,что связаны с ней ребром
    vector<int> temp;
    for (int j = 0; j < k; j++){
        b.push_back(temp);
    }
    for(int i=0; i<a.size(); i++){
        b[a[i].first-1].push_back(a[i].second);
        b[a[i].second-1].push_back(a[i].first);
    }
}

void print_list_con(vector<vector<int> >z, int l){
    cout<<endl<<"the list of connectivity: "<<endl;
    for (int i=0; i<l; i++)
    {
        cout <<i+1<< ") ";
        for (int j = 0; j<z[i].size(); j++){
            cout << z[i][j]<<" ";
        }
        cout << endl;

    }
}


int main(){
    int V, E;
    cout<<"print number of vertices: ";
    cin>>V;

    cout<<"print number of edges: ";
    cin>>E;

    //список ребер
    vector<pair<int,int> > g;

    int f,s;
    for(int i=0; i<E; i++){
        cout<<"enter data for the "<<i+1<<" edge: ";
        cin>>f>>s;
        g.push_back(make_pair(f,s));
    }

    //матрица смежности
    bool** m_adj= new bool*[V];
        for(int i=0; i<V; i++){
            m_adj[i]=new bool[V];
        }
    for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                m_adj[i][j]=0;
            }
        }
    
    //матрица инцидентности
    bool** m_in= new bool*[E];
        for(int i=0; i<E; i++){
            m_in[i]=new bool[V];
        }
        for(int i=0; i<E; i++){
            for(int j=0; j<V; j++){
                m_in[i][j]=0;
            }
        }
    
    
    //список связности
    vector<vector<int> > list_c;
    

    make_matrix_adj(g,m_adj);
    make_matrix_in(g,m_in);
    make_list_con(g,list_c, V);
    print_list_edges(g);
    cout<<endl;
    print_matrix_adj(m_adj, V);
    cout<<endl;
    print_matrix_in(m_in, E, V);
    cout<<endl;
    print_list_con(list_c, V);

    return 0;
}
