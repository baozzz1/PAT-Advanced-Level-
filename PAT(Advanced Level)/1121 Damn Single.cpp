#include<iostream>
#include<vector>
#include<cstdio>
#include<set>
#include<map>
#include<iomanip>
using namespace std;

struct guest {
	guest() :id(0), coupleId(0) {}
	int id;
	int coupleId;
	bool beThere = false;
};

//输出格式要求五位数字
int P1121() {
	int N;
	cin >> N;
	int c1, c2;
	vector<guest> guests(100000);
	for (int i = 0; i < N; i++) {
		scanf_s("%d %d", &c1, &c2);
		guests[c1].id = c1;
		guests[c1].coupleId = c2;
		guests[c2].id = c2;
		guests[c2].coupleId = c1;
	}
	int M; cin >> M;
	map<int,bool> lonely;
	int count = 0;
	for (int i = 0; i < M; i++) {
		scanf_s("%d", &c1);
		if (guests[c1].id == 0) {//绝对单身
			lonely[c1] = true;
			count++;
		}
		else if (lonely[guests[c1].coupleId] == false) {//同伴没来
			lonely[c1] = true;
			count++;
		}
		else {
			lonely[c1] = false;
			lonely[guests[c1].coupleId] = false;
			count--;
		}
	}
	cout << count << endl;
	int outputCount=0;
	for (auto iter = lonely.begin(); iter != lonely.end(); ++iter) {
		if (iter->second) {
			if (outputCount != 0)
				cout << " ";
			cout << setw(5)<<setfill('0')<<iter->first;
			outputCount++;
		}
	}
	return 0;
}