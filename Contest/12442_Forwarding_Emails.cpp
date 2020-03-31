#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
int DFS(int u, int *graph, int *sum_rec, int *visited) {
    visited[u] = 1;
    int count = 0;
    if(graph[u] != -1 && !visited[graph[u]])//
        count += 1 + DFS(graph[u], graph, sum_rec, visited);
    visited[u] = 0;
    return sum_rec[u] = count;
}


int main(void){
	int T; cin >> T;
	for (int k=1; k<=T; ++k) {
		int N; cin >> N;
		int graph[N], sum_rec[N], visited[N];
		int ans = 0, max_people = 0;

		for (int i=0; i<N; ++i){
			graph[i]  =-1;
            sum_rec[i]=-1;
            visited[i] =0;
		}
		for (int i=0; i<N; ++i){
			int a, b; cin >> a >> b;
			graph[a-1] = b-1; //to be able to start fro idx 0
		}
		for (int i=0; i<N; ++i){
			if(sum_rec[i] == -1) DFS(i, graph, sum_rec, visited);
			if(sum_rec[i] > max_people){
				max_people = sum_rec[i];
				ans = i;
			}
		}
		printf("Case %d: %d\n", k, ans+1);
	}
	return 0;
}
