#include<iostream>
#include<cstdio>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
//会超时！
//class solution1151 {
//public:
//	typedef vector<int>::iterator index;
//	solution1151(int N) :N(N) {
//		inOrder = vector<int>(N);
//		preOrder = vector<int>(N);
//	}
//	void read() {
//		for (int i = 0; i < N; i++) {
//			scanf_s("%d", &inOrder[i]);
//			exist[inOrder[i]] = 1;
//		}
//		for (int i = 0; i < N; i++) {
//			scanf_s("%d", &preOrder[i]);
//		}
//	}
//	int Find(const int &u, const int &v) {
//		return Find(preOrder.begin(), inOrder.begin(), N, u, v);
//	}
//
//	int Find(const index &preBeg, const index &inBeg, const int &length, const int &u, const int &v) {
//		if (length == 0)	return -1;
//		if (u == *preBeg) return u;
//		else if (v == *preBeg) return v;
//		int rootIndex = 0;
//		while (rootIndex < length && *(preBeg) != *(inBeg + rootIndex)) rootIndex++;
//		bool uLeft = find(inBeg, inBeg + rootIndex, u) != inBeg + rootIndex;
//		bool vRight = find(inBeg + rootIndex + 1, inBeg + length , v) != inBeg + length;
//		if ((uLeft && vRight) || (!uLeft && !vRight))
//			return *preBeg;
//		else if (uLeft && !vRight) {
//			return Find(preBeg + 1, inBeg, rootIndex, u, v);
//		}
//		else if (!uLeft && vRight)
//			return Find(preBeg + rootIndex + 1, inBeg + rootIndex + 1, length - rootIndex - 1, u, v);
//		return -1;
//	}
//	int N;
//	vector<int> inOrder;
//	vector<int> preOrder;
//	unordered_map<int, int> exist;
//};
//
//int main() {
//	int M, N;
//	cin >> M >> N;
//	solution1151 res(N);
//	res.read();
//	int u, v;
//	int ans;
//	bool has1, has2;
//	for (int i = 0; i < M; i++) {
//		scanf("%d %d", &u, &v);
//		//cin >> u >> v;
//		has1 = res.exist[u];
//		has2 = res.exist[v];
//		if (!has1) {
//			if (!has2) {
//				cout << "ERROR: " << u << " and " << v << " are not found." << endl;
//				continue;
//			}
//			else {
//				cout << "ERROR: " << u << " is not found." << endl;
//				continue;
//			}
//		}
//		else if (!has2) {
//			cout << "ERROR: " << v << " is not found." << endl;
//			continue;
//		}
//		ans = res.Find(u, v);
//
//		if (ans == u)
//			cout << u << " is an ancestor of " << v << "." << endl;
//		else if (ans == v)
//			cout << v << " is an ancestor of " << u << "." << endl;
//		else
//			cout << "LCA of " << u << " and " << v << " is " << ans << "." << endl;
//	}
//	return 0;
//}

class Node {
public:
	int val;
	Node *left, *right;
	Node(int x) :val(x), left(NULL), right(NULL) {}
};
class BST1151{
public:
	typedef vector<int>::iterator index;
	BST1151(int N) :N(N) {
		inOrder = vector<int>(N);
		preOrder = vector<int>(N);
		root = NULL;
	}

	void process() {
		for (int i = 0; i < N; i++) {
			scanf_s("%d", &inOrder[i]);
			hasItem[inOrder[i]] = true;
		}
		for (int i = 0; i < N; i++) {
			scanf_s("%d", &preOrder[i]);
		}
		getTotalTree();
		dfs();
	}

	void dfs() {
		reserve[root->val] = -1;
		dfs(root);
	}

	void dfs(Node *node) {
		if (node->left != NULL) {
			reserve[node->left->val] = node->val;
			dfs(node->left);
		}
		if (node->right != NULL) {
			reserve[node->right->val] = node->val;
			dfs(node->right);
		}
	}
	void getTotalTree() {
		getTree(preOrder.begin(), inOrder.begin(), N, root);
	}

	void getTree(const index &preBeg, const index &inBeg, const int &length, Node *&node) {
		if (length == 0) return;
		int rootIndex = 0;
		while (rootIndex < length && *preBeg != *(inBeg + rootIndex)) rootIndex++;
		node = new Node(*preBeg);
		getTree(preBeg + 1, inBeg, rootIndex, node->left);
		getTree(preBeg + rootIndex + 1, inBeg + rootIndex + 1, length - rootIndex - 1, node->right);
	}
	int N;
	vector<int> inOrder;
	vector<int> preOrder;
	unordered_map<int, int> reserve;
	unordered_map<int, bool> hasItem;
	Node *root;
};
//方法2：建立反向链表，在map中建
int P1151() {
	int M, N;
	cin >> M >> N;
	BST1151 bst(N);
	bst.process();
	int u, v;
	bool has1, has2;
	int u_parent, v_parent;
	vector<int> path_u, path_v;
	for (int i = 0; i < M; i++) {
		scanf_s("%d %d", &u, &v);
		path_u.clear();
		path_v.clear();
		has1 = bst.hasItem[u];
		has2 = bst.hasItem[v];

		if (!has1) {
			if (!has2) {
				cout << "ERROR: " << u << " and " << v << " are not found." << endl;
				continue;
			}
			else {
				cout << "ERROR: " << u << " is not found." << endl;
				continue;
			}
		}
		else if (!has2) {
			cout << "ERROR: " << v << " is not found." << endl;
			continue;
		}
		int temp = u;
		while (temp != -1) {
			path_u.push_back(temp);
			temp = bst.reserve[temp];
		}
		path_u.push_back(temp);
		temp = v;
		while (temp != -1) {
			path_v.push_back(temp);
			temp = bst.reserve[temp];
		}
		path_v.push_back(temp);
		auto riter1 = path_u.rbegin();
		auto riter2 = path_v.rbegin();
		while (riter1!=path_u.rend() && riter2!=path_v.rend()) {
			if (*riter1 != *riter2) {
				break;
			}
			temp = *riter1;
			riter1++;
			riter2++;
		}
		if (temp == u)
			cout << u << " is an ancestor of " << v << "." << endl;
		else if (temp == v)
			cout << v << " is an ancestor of " << u << "." << endl;
		else
			cout << "LCA of " << u << " and " << v << " is " << temp << "." << endl;

	}

	return 0;
}