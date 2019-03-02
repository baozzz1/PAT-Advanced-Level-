// 2019年3月1日14:13:43
// 2019年3月1日14:22:32
//2019年3月1日14:28:16
//2019年3月1日14:39:38

//total time: 20min
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


int P1132() {
	int N; cin >> N;
	unsigned long Znum, A, B;
	string Z;
	for (int i = 0; i < N; i++) {
		cin >> Z;
		string temp1 = Z.substr(0, Z.size() / 2);
		string temp2 = Z.substr(Z.size() / 2, Z.size() / 2);
		A = atoi(temp1.c_str());
		B = atoi(temp2.c_str());
		Znum = atoi(Z.c_str());
		unsigned long C = A * B;
		if (C == 0) {
			cout << "No" << endl;
		}
		else if(Znum%C==0) {
			cout << "Yes" << endl;
		}
		else
			cout << "No" << endl;
	}
	return 0;
}