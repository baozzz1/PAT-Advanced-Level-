#include<iostream>
#include<vector>
#include<cstdio>
#include<map>
using namespace std;

class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};
class BST {
public:
	void insert(const int &val) {
		root = insert(val, root);
	}
	TreeNode *insert(const int &val, TreeNode *node) {
		if (node == NULL) {
			return new TreeNode(val);
		}
		if (val <= node->val)
			node->left = insert(val, node->left);
		else
			node->right = insert(val, node->right);
		return node;
	}

	void dfs() {
		int depth = 1;
		dfs(root, depth);
	}

	void dfs(TreeNode *node,const int &depth) {
		if (node == NULL)
			return;
		dfs(node->left, depth + 1);
		dfs(node->right, depth + 1);
		depthNumCount[depth]++;
		return;
	}
	TreeNode *root = NULL;
	vector<int> depthNumCount = vector<int>(1001,0);
};


int P1115() {
	int N; cin >> N;
	vector<int> vec(N);
	BST bst;
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &vec[i]);
		bst.insert(vec[i]);
	}
	bst.dfs();
	int a, b, count = 0;
	for (int i = 1000; i > 0; i--) {
		if (bst.depthNumCount[i] != 0) {
			count++;
			if (count == 1)
				a = bst.depthNumCount[i];
			else if (count == 2)
				b = bst.depthNumCount[i];
			else
				break;
		}
	}
	cout << a << " + " << b << " = " << a + b;
	return 0;
}