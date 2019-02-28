//#include<iostream>
//#include<cstdio>
//#include<vector>
//
//using namespace std;
//
//int main() {
//
//	return 0;
//}

#include<iostream>
#include<cstdio>
#include<vector>
#include<string>

using namespace std;

string prcu(const string &D) {
	char last = D[0], curr;
	int count = 1;
	string res = "";
	for (int i = 1; i < D.size(); i++) {
		curr = D[i];
		if (curr == last) {
			count++;
			continue;
		}
		else {
			res.push_back(last);
			res.push_back(count + '0');
			last = curr;
			count = 1;
		}
	}
	res.push_back(last);
	res.push_back(count + '0');
	return res;
}

//Easy
int P1140() {
	string D;
	int N;
	cin >> D >> N;
	for (int i = 1; i < N; i++) {
		D = prcu(D);
	}
	cout << D;
	return 0;
}