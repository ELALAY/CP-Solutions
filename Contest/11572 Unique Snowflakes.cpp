#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(){
	long long TC; cin >> TC;
	while (TC--) {
		long long n; cin >> n;
		set<long long> s;
		while (n--) {
			long long a; cin >> a;
			s.insert(a);
		}
		cout << s.size() << endl;
	}
	return 0;
}