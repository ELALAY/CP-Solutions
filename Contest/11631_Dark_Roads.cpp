#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find(vector<int>& parent, int u){
    if(parent[u] == u)
        return u;
    return parent[u] = find(parent, parent[u]);
}

bool uni(vector<int>& parent, vector<int>& rank, int u, int v){
    int par_u = find(parent, u);
    int par_v = find(parent, v);
    if(par_u == par_v)
        return false;
    if(rank[par_u] >= rank[par_v]){
        parent[par_v] = par_u;
        rank[par_u] += rank[par_v] + 1;
    }
    else{
        parent[par_u] = par_v;
        rank[par_v] += rank[par_u] + 1;
    }
    return true;
}

int main(void){
    int n, m;

    while(cin >> n >> m){
        if(m == 0 && n == 0)
            break;

        vector <pair <long long, pair<int, int> > > edges;

        long long Initial_Cost = 0;
        long long MST_Cost = 0;
        for(int i = 0; i < m; i++){
        	int x, y; long long z;
            cin >> x >> y >> z;
            edges.push_back(make_pair(z, make_pair(x, y)));
            Initial_Cost += z;
        }

        sort(edges.begin(), edges.end());

        vector<int> parent(n),rank(n, 0);
        for(int i = 0; i < n; i++)
            parent[i] = i;
        for(int i=0; i<(int)edges.size(); ++i){
            if(!uni(parent,rank, edges[i].second.first, edges[i].second.second))
                continue;
            MST_Cost+=edges[i].first;
        }
        cout << Initial_Cost - MST_Cost << endl;

    }


    return 0;
}
