#include<iostream>
#include <cstdio>
#include <map>
#include <set>

using namespace std;

int main(void){
	int nbr_days;
	while (cin >> nbr_days){
		if(nbr_days == 0) break;
		long long count=0;
		set<int> bills;
		set<int>::iterator it;
		map<int, int> freq;
		map<int, int>::iterator it1;
		for(int i=0; i<nbr_days; ++i){
			int n; cin >>n;
			for(int j=0; j<n; ++j){
				int a; cin >> a;
				bills.insert(a);
				it1 = freq.find(a);
				if(it1 != freq.end()) freq[a]++;
				else freq[a]=1;
			}

			//printf("day %d:\n", i);
			int max = *bills.rbegin();
			int min = *bills.begin();
			count+=(max-min);

			//printf("max: %d \n min: %d \n count: %d \n", max, min, count);

			freq[max]--;
			freq[min]--;

			//cout << "pre-erase ";
			//for(it=bills.begin();it!=bills.end(); it++) printf("%d ", *it);
			//cout << endl;

			if(freq[max] == 0) bills.erase(max);
			if(freq[min] == 0) bills.erase(min);

			//cout << "post-erase ";
			//for(it=bills.begin();it!=bills.end(); it++) printf("%d ", *it);
			//cout << endl;
		}

		cout << count << endl;

	}
	return 0;
}