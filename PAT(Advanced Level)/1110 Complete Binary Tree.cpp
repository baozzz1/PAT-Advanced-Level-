#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
using namespace std;
int res = -1;
class Node {
public: 
	int val;
	Node *left, *right;
	Node(int x) :val(x), left(NULL), right(NULL) {}
};

bool dfs(const int &rootIndex, const vector<Node*> &trees) {
	queue<Node*> q;
	q.push(trees[rootIndex]);
	bool noChild = false;
	Node * curr = q.front();
	while (q.size() != 0) {
		curr = q.front();
		q.pop();
		if (curr->left != NULL) {
			if (noChild)
				return false;
			q.push(curr->left);
		}
		else
			noChild = true;

		if (curr->right != NULL) {
			if (noChild)
				return false;
			q.push(curr->right);
		}
		else
			noChild = true;
	}
	res = curr->val;
	return true;
}

// 部分正确
int P1110() {
	int N;
	cin >> N;
	char c1, c2;
	vector<int> reserve(N,-1);
	vector<Node*> trees(N);
	for (int i = 0; i < N; i++)
		trees[i] = new Node(i);
	int temp = -1;
	for (int i = 0; i < N; i++ ) {
		cin >> c1 >> c2;
		if (c1 != '-') {
			temp = c1 - '0';
			reserve[temp] = i;
			trees[i]->left = trees[temp];
		}
		if (c2 != '-') {
			temp = c2 - '0';
			reserve[temp] = i;
			trees[i]->right = trees[temp];
		}
	}
	int root = 0;
	while (reserve[root] != -1)
		root++;
	if (dfs(root, trees))
		cout << "YES " << res;
	else
		cout << "NO " << root;

	return 0;
}