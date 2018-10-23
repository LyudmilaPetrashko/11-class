#include<iostream>
#include<vector>
using namespace std;

int v;

vector<vector<int> >  g;


bool* used= new bool[v];
int timer;
int* tin=new int[v];
int* fup=new int[v];


 void IS_BRIDGE(int a, int b){
    cout<<endl<<"("<<a<<","<<b<<")";
}


void dfs (int k, int p = -1) {
	used[k] = true;
	tin[k] = fup[k] = timer++;
	for (size_t i=0; i<g[k].size(); ++i) {
		int to = g[k][i];
		if (to == p)  continue;
		if (used[to])
			fup[k] = min (fup[k], tin[to]);
		else {
			dfs (to, k);
			fup[k] = min (fup[k], fup[to]);
			if (fup[to] > tin[k])
				IS_BRIDGE(k+1,to+1);
		}
	}
}




void find_bridges() {
	timer = 0;
	for (int i=0; i<v; ++i)
		used[i] = false;
	for (int i=0; i<v; ++i)
		if (!used[i])
			dfs (i);
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





    make_list_con(h,g,v);
/////////////////////////////////////////////////////////////////////////////

    find_bridges();

    delete[] used;

    return 0;
}
