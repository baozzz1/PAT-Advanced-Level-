#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>

using namespace std;

struct graph {
	graph(int n, int m) :N(n), M(n) {
		//adj = vector<vector<int>>(N);
	}
	void insert(const int &v1, const int &v2) {
		//adj[v1].push_back(v2);
		//adj[v2].push_back(v1);
		allE.push_back(make_pair(v1, v2));
	}

	bool toCheck(const unordered_set<int> &sets)const {
		int temp;
		for (int i = 0; i < allE.size(); i++) {
			temp = allE[i].first;
			if (sets.find(temp) == sets.cend()) {
				temp = allE[i].second;
				if (sets.find(temp) == sets.cend())
					return false;
			}
		}
		return true;
	}
	int N, M;
	//vector< vector<int>> adj;
	vector<pair<int, int>> allE;
};

//2019年3月1日15:02:45
//2019年3月1日15:16:55
//total time: 14min
int P1134() {
	int N, M;
	cin >> N >> M;
	graph G(N, M);
	int v1, v2;
	for (int i = 0; i < M; i++) {
		scanf_s("%d %d", &v1, &v2);
		G.insert(v1, v2);
	}

	int K; cin >> K;
	int Nv; int Vinput;
	unordered_set<int> toCheck;
	for (int i = 0; i < K; i++) {
		cin >> Nv;
		toCheck.clear();
		for (int j = 0; j < Nv; j++) {
			scanf_s("%d", &Vinput);
			toCheck.insert(Vinput);
		}
		if (G.toCheck(toCheck))
			cout << "Yes";
		else
			cout << "No";
		cout << endl;
	}
	return 0;
}