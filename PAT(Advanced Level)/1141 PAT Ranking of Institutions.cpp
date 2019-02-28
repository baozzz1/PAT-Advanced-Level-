#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<unordered_map>
#include<set>
#include<algorithm>
#include<functional>
using namespace std;

struct institution {
	institution() :SchoolCode(""), TWS(0), Bgrade(0),Agrade(0),Tgrade(0), totalNs(0) {}
	string SchoolCode;
	int TWS;
	double Bgrade;
	double Agrade;
	double Tgrade;
	int totalNs;
	void getTWS() {
		double x = (double)Bgrade / 1.5;
		x += Agrade;
		x += (double)Tgrade * 1.5;
		TWS = (int)x;
	}
	
	bool operator<(const institution &rhs)const {
		if (TWS == rhs.TWS) {
			if (totalNs == rhs.totalNs)
				return SchoolCode < rhs.SchoolCode;
			else
				return totalNs < rhs.totalNs;
		}
		else
			return TWS > rhs.TWS;
	}
};


int P1141() {
	int N;
	cin >> N;
	string ID,School;
	int  Score;
	unordered_map<string, institution> institutions;
	for (int i = 0; i < N; i++) {
		cin >> ID >> Score >> School;
		transform(School.begin(), School.end(), School.begin(),::tolower);
		institutions[School].SchoolCode = School;
		institutions[School].totalNs++;
		switch (ID[0]) {
		case 'B':
			institutions[School].Bgrade += Score;
			break;
		case 'A':
			institutions[School].Agrade += Score;
			break;
		case 'T':
			institutions[School].Tgrade += Score;
			break;
		}
	}
	set< institution> ordered;
	for (auto iter = institutions.begin(); iter != institutions.end(); iter++) {
		iter->second.getTWS();
		ordered.insert(iter->second);
	}
	int ranking = 0 /*排名*/, count = 0   /*计数器*/;
	int pre = -1;				//前驱分数
	cout << ordered.size() << endl;
	for (auto it = ordered.begin(); it != ordered.end(); it++) {
		count++;
		if (it->TWS != pre)	//与前驱分数不同时，更新ranking
			ranking = count;
		pre = it->TWS;
		cout << ranking << " " << it->SchoolCode << " " << it->TWS << " " << it->totalNs << endl;
	}
	return 0;
}
