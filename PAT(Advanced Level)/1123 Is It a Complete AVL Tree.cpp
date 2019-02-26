#include<iostream>
#include<vector>
#include<cstdio>
#include<map>
using namespace std;

class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	int height;
	TreeNode(int x) :val(x), left(NULL), right(NULL), height(1) {}
};

class BST {
public:
	BST() {
		root = NULL;
	}
	void insert(const int &x) {
		insert(root, x);
	}
private:
	void LeftRotation(TreeNode * &node) {
		TreeNode *temp = node->right;
		node->right = temp->left;
		temp->left = node;

		//updateHeight(temp->left);
		//updateHeight(temp);
		temp->left->height = max(height(temp->left->left), height(temp->left->right)) + 1;
		temp->height = max(height(temp->left), height(temp->right)) + 1;
		node = temp;
	}

	void RightRotation(TreeNode * &node) {
		TreeNode *temp = node->left;
		node->left = temp->right;
		temp->right = node;

		//updateHeight(temp->right);
		//updateHeight(temp);
		temp->right->height = max(height(temp->right->left), height(temp->right->right)) + 1;
		temp->height = max(height(temp->left), height(temp->right)) + 1;
		node = temp;
	}

	void insert(TreeNode * &node,const int &x) {
		if (node == NULL)
			node = new TreeNode(x);
		else if (x < node->val) {
			insert(node->left, x);
			if (height(node->left) - height(node->right) > 1) {
				if (x > node->left->val) {
					LeftRotation(node->left);
					RightRotation(node);
				}
				else
					RightRotation(node);
			}
		}
		else {
			insert(node->right, x);
			if (height(node->right) - height(node->left) > 1) {
				if (x > node->right->val)
					LeftRotation(node);
				else {
					RightRotation(node->right);
					LeftRotation(node);
				}
			}
		}
		//updateHeight(node);
		node->height = max(height(node->left), height(node->right)) + 1;
	}

	int height(TreeNode *node) {
		if (node == NULL) return 0;
		else return node->height;
	}

	void updateHeight(TreeNode *node) {
		if (node == NULL)	return;
		node->height = max(height(node->left), height(node->right)) + 1;
	}
	int max(const int &n1, const int &n2) {
		return (n1 > n2) ? n1 : n2;
	}

	TreeNode *root;
};
//START 2019年2月26日15:48:32
// 未解决：问题是height不正常
int P1123() {
	int N; cin >> N;
	BST bst;
	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		bst.insert(num);
	}
		
	return 0;
}