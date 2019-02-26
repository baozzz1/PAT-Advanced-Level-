#include<iostream>
#include<vector>
#include<cstdio>
#include<map>
#include<set>
#include<string>
#include<algorithm>
using namespace std;

//vector<string> syms = { "+","-","*","%","/" };
struct node {
	string symbol;
	node *left, *right;
	node() :symbol(""), left(NULL), right(NULL) {}
};

void inOrder(node* node) {
	if (node == NULL) return;
	//bool flag = find(syms.cbegin(), syms.cend(), node->symbol) != syms.cend();
	bool flag = node->left != NULL || node->right != NULL;
	if (flag) cout << "(";
	inOrder(node->left);
	cout << node->symbol;
	inOrder(node->right);
	if (flag) cout << ")";
}

void inOrderH(node *root) {
	inOrder(root->left);
	cout << root->symbol;
	inOrder(root->right);
}

// 最后一个测试点一直过不去的原因：加括号的标准是左子树或右子树存在时，加括号；而不是原来的“此符号为运算符”时。
int P1130() {
	int N;
	cin >> N;
	vector<node*> symbols(N + 1);
	set<int> sets;
	string c;
	int n1, n2;
	for (int i = 1; i <= N; i++) {
		symbols[i] = new node();
		sets.insert(i);
	}
	for (int i = 1; i <= N; i++) {
		//scanf_s("%s %d %d", &c, &n1, &n2);
		cin >> c;
		cin >> n1 >> n2;
		symbols[i]->symbol = c;
		if (n1 != -1) {
			symbols[i]->left = symbols[n1];
			sets.erase(n1);
		}
		if (n2 != -1) {
			symbols[i]->right = symbols[n2];
			sets.erase(n2);
		}
	}
	int rootIndex = 0;
	if (sets.size() != 0)
		rootIndex = *sets.begin();
	inOrderH(symbols[rootIndex]);

	return 0;
}