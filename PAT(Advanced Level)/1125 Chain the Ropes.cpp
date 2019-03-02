#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<set>

using namespace std;


//START 2019年3月2日02:25:29
//SUCCESS 2019年3月2日02:33:32
int P1125() {
	int N; cin >> N;
	int length;
	vector<int> ropes(N);
	for (int i = 0; i < N; i++) {
		cin >> ropes[i];
	}
	sort(ropes.begin(), ropes.end());
	double sum = ropes[0];
	for (int i = 1; i < ropes.size();i++) {
		sum = ((double)ropes[i] + sum) / 2.0;
	}
	cout << (int)sum;
	return 0;
}