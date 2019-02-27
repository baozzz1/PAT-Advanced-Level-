#include<iostream>
#include<vector>
#include<cstdio>
#include<map>
#include<set>
#include<string>
#include<algorithm>
using namespace std;
//
//class Node{
//public:
//	int val;
//	Node *left, *right;
//	Node(int x) :val(x), left(NULL), right(NULL) {}
//};
//
//class BST {
//public:
//	BST() { root = NULL; }
//	void insert(int x) {
//		insert(root, x);
//	}
//	void insert(Node * &node, int x) {
//		if (node == NULL)
//			node = new Node(x);
//		else {
//			if (x < node->val)
//				insert(node->left, x);
//			else
//				insert(node->right, x);
//		}
//	}
//	void getTwoPath(const int &n1, const int &n2) {
//		path1.clear();
//		path2.clear();
//		bool has1 = track1(root, n1);
//		bool has2 = track2(root, n2);
//
//		if (!has1) {
//			if (!has2) {
//				cout << "ERROR: " << n1 << " and " << n2 << " are not found." << endl;
//				return;
//			}
//			else {
//				cout << "ERROR: " << n1 << " is not found." << endl;
//				return;
//			}
//		}
//		else if (!has2) {
//			cout << "ERROR: " << n2 << " is not found." << endl;
//			return;
//		}
//		int res = root->val;
//		for (int i = 0; i < path1.size() && i < path2.size(); i++) {
//			if (path1[i] != path2[i])
//				break;
//			res = path1[i];
//		}
//		if (res == n1)
//			cout << n1 << " is an ancestor of " << n2 << "." << endl;
//		else if (res == n2)
//			cout << n2 << " is an ancestor of " << n1 << "." << endl;
//		else
//			cout << "LCA of " << n1 << " and " << n2 << " is " << res << "." << endl;
//		return;
//	}
//
//	bool track1(Node *node, const int &x) {
//		if (node == NULL) return false;
//		path1.push_back(node->val);
//		if (x == node->val) return true;
//		else if (x < node->val) return track1(node->left, x);
//		else return track1(node->right, x);
//	}
//	bool track2(Node *node, const int &x) {
//		if (node == NULL) return false;
//		path2.push_back(node->val);
//		if (x == node->val) return true;
//		else if (x < node->val) return track2(node->left, x);
//		else return track2(node->right, x);
//	}
//	Node *root;
//	vector<int> path1, path2;
//};
//
//int main() {
//	int M, N;
//	cin >> M >> N;
//	int num;
//	BST bst;
//	for (int i = 0; i < N; i++) {
//		scanf_s("%d", &num);
//		bst.insert(num);
//	}
//	int n1, n2;
//	for (int i = 0; i < M; i++) {
//		cin >> n1 >> n2;
//		//START FIND
//		bst.getTwoPath(n1, n2);
//	}
//	return 0;
//}

//BETTER WAY
int P1143() {
	int m, n;
	scanf_s("%d %d", &m, &n);
	vector<int> preorder(n);
	map<int, bool> mp;
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &preorder[i]);
		mp[preorder[i]] = true;
	}

	for (int i = 0; i < m; i++) {
		int u, v;
		scanf_s("%d %d", &u, &v);
		if (mp[u] == false && mp[v] == true) {
			printf("ERROR: %d is not found.\n", u);
			continue;
		}
		else if (mp[v] == false && mp[u] == true) {
			printf("ERROR: %d is not found.\n", v);
			continue;
		}
		else if (mp[v] == false && mp[u] == false) {
			printf("ERROR: %d and %d are not found.\n", u, v);
			continue;
		}
		int anc;
		for (int j = 0; j < n; j++) {
			anc = preorder[j];
			if ((anc >= u && anc <= v) || (anc >= v && anc <= u)) {
				break;
			}
		}
		if (anc == u) {
			printf("%d is an ancestor of %d.\n", u, v);
		}
		else if (anc == v) {
			printf("%d is an ancestor of %d.\n", v, u);
		}
		else {
			printf("LCA of %d and %d is %d.\n", u, v, anc);
		}
	}
	return 0;
}