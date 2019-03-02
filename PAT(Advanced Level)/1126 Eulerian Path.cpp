#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<set>

using namespace std;

//START 2019年3月2日02:34:14

void dfs(const int &start, vector<bool> &marked, const vector<vector<int>> &adj) {
	marked[start] = true;
	for (auto v : adj[start])
		if(!marked[v])
			dfs(v, marked, adj);
}

//注意连通图要求！！！
int P1126() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> adj(N + 1);
	int v1, v2;
	for (int i = 0; i < M; i++) {
		scanf_s("%d%d", &v1, &v2);
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}
	//is Connected Graph?
	bool flag = true;
	vector<bool> marked(N + 1, false);
	dfs(1, marked, adj);
	for (int i = 1; i <= N; i++)
		if (!marked[i])
			flag = false;

	//degrees
	int oddCount = 0;
	cout << adj[1].size();
	if (adj[1].size() % 2 != 0)
		oddCount++;
	for (int i = 2; i <= N; i++) {
		cout << " " << adj[i].size();
		if (adj[i].size() % 2 != 0)
			oddCount++;
	}
	cout << endl;
	if(!flag)
		cout << "Non-Eulerian";
	else if (oddCount == 0)
		cout << "Eulerian";
	else if (oddCount == 2)
		cout << "Semi-Eulerian";
	else
		cout << "Non-Eulerian";

	return 0;
}