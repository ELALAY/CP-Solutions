#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
	int T; cin >> T;
	vector<int> v;

	for(int i=0; i<T; ++i){
		vector<int> v;
		for(int j=0; j<3; ++j){
			int a; cin >> a;
			v.push_back(a);
		}
		sort(v.begin(), v.end());
		cout << "Case " << i+1 << ": " << v[1] << endl;
	}
	
	return 0;
}