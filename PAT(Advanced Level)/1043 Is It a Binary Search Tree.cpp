#include<iostream>
#include<vector>
using namespace std;

void check(const int &beg, const int &end,const vector<int> &vec) {
	if (beg >= end) return;
	auto right = beg;
	for (auto iter = beg+1; iter < end; iter++) {
		if (vec[iter] < vec[beg]) {
			right = iter;
			break;
		}
	}
	check(beg + 1, right,vec);
	check(right, end, vec);
	cout << vec[right] << " ";
}

//START 2019Äê2ÔÂ24ÈÕ23:04:34
int P1043() {
	int N; cin >> N;
	vector<int> origin(N);
	for (int i = 0; i < N; i++)
		cin >> origin[i];
	check(0,N,origin);
	return 0;
}