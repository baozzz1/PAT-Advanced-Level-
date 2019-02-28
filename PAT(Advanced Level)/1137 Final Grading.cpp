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
#include<unordered_map>
#include<set>

using namespace std;

struct student {
	student() :scoreProgramming(0), scoreMid(-1), scoreFinal(0), scoreG(0), isPassed(false) {}
	string StudentID;
	int scoreProgramming;
	int scoreMid;
	int scoreFinal;
	int scoreG;
	bool isPassed;
	void check() {
		if (scoreProgramming < 200)
			return;
		if (scoreMid <= scoreFinal)
			scoreG = scoreFinal;
		else {
			double temp = (double)scoreMid*0.4 + (double)scoreFinal * 0.6;
			if (temp - (int)temp < 0.5)
				scoreG = (int)temp;
			else
				scoreG = (int)temp + 1;
		}
		if (scoreG < 60)
			return;
		isPassed = true;
	}
	bool operator<(const student &s2)const {
		if (scoreG == s2.scoreG)
			return StudentID < s2.StudentID;
		else
			return scoreG > s2.scoreG;
	}
};

//关键：最终综合成绩得不小于60分，而不是“final exam grade”
int P1137() {
	int P, M, N;
	cin >> P >> M >> N;
	int i;
	string StudentID;
	int Score;
	unordered_map<string, student> students;
	for (i = 0; i < P; i++) {
		cin >> StudentID >> Score;
		students[StudentID].StudentID = StudentID;
		students[StudentID].scoreProgramming = Score;
	}
	for (i = 0; i < M; i++) {
		cin >> StudentID >> Score;
		students[StudentID].StudentID = StudentID;
		students[StudentID].scoreMid = Score;
	}
	for (i = 0; i < N; i++) {
		cin >> StudentID >> Score;
		students[StudentID].StudentID = StudentID;
		students[StudentID].scoreFinal = Score;
	}
	set<student> passed;
	for (auto iter = students.begin(); iter != students.end(); ++iter) {
		iter->second.check();
		if (iter->second.isPassed)
			passed.insert(iter->second);
	}
	for (auto iter = passed.begin(); iter != passed.end(); ++iter) {
		cout << iter->StudentID << " " << iter->scoreProgramming << " " << iter->scoreMid << " "
			<< iter->scoreFinal << " " << iter->scoreG << endl;
	}

	return 0;
}