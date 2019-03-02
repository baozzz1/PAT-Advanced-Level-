#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<set>

using namespace std;

//START 2019年3月2日02:14:58
//SUCCESS 2019年3月2日02:24:36
//TIME	10min
int P1124() {
	//forwards
	//the skip number of winners
	//and the index of the first winner (FROM 1)
	int M, N, S;
	cin >> M >> N >> S;
	string nickname;
	vector<string> res;
	int count = 0;
	for (int i = 1; i <= M; i++) {
		cin >> nickname;
		if (i < S)
			continue;
		else if (i == S) {
			res.push_back(nickname);
			count = 0;
		}
		if (count == N) {
			if (find(res.begin(), res.end(), nickname) != res.end())
				continue;
			else {
				res.push_back(nickname);
				count = 0;
			}
		}
		count++;
	}

	if (res.size() == 0)
		cout << "Keep going...";
	else
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] << endl;
		}
	return 0;
}