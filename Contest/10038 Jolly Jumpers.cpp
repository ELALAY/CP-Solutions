#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int n; 
	while (cin >> n) {
		vector <int> v, diff;

		//input
		for (int i=0; i<n; i++) {
			int a; cin >> a;
			v.push_back(a);
		}
		//defference array
		for (int i=0; i<n-1; i++) {
			diff.push_back(abs(v[i] - v[i+1]));
		}


		bool works = true;
		sort(diff.begin(), diff.end());

		for(int i=1; i<diff.size(); ++i) {
			if((diff[i] - diff[i-1]) != 1){
				works = false;
				break;
			}
		}

		if(works) cout << "Jolly" << endl;
		else cout << "Not jolly" << endl;
	}
	return 0;
}