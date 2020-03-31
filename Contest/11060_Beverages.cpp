#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <string>
#include <queue>
#include <map>

using namespace std;

int main(void){
	int T, count=1;

	while (cin >> T){
		map <string, int> indexOf;
		vector<string> av_drinks;

		for (int i=0; i<T; ++i){
			string s; cin >> s;
			av_drinks.push_back(s);
			indexOf[s] = i;
		}

		int n;
		cin >> n;

		vector <int> counter(T, 0);
		vector <int> adj[n+10];

		for (int i=0; i<n; ++i){
			string b1, b2;
			cin >> b1 >> b2;
			counter[ indexOf[b2] ]++;
			adj[ indexOf[b1] ].push_back(indexOf[b2]);
		}

		for (int i=0; i<T; ++i){
			sort(adj[i].begin(), adj[i].end());
		}

		priority_queue <int, vector<int>, greater<int> > pq;
		vector <int> order;

		for (int i=0; i<T; ++i)
			if (counter[i]==0)
				pq.push(i);

		while (!pq.empty()){
			int u = pq.top(); pq.pop();
			order.push_back(u);

			for (int i=0; i<(int)adj[u].size(); ++i){
				int v = adj[u][i];
				counter[v]--;
				if (counter[v] == 0) pq.push(v);
			}
		}
		//print
		printf("Case #%d: Dilbert should drink beverages in this order:", count);
		for (int i=0; i<(int)order.size(); ++i){
			cout << " " << av_drinks[order[i]];
		} cout << "." << endl << endl;

		count++;
	}

	return 0;
}
