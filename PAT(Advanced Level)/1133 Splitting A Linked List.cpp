#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

struct Node1133 {
	Node1133() {}
	Node1133(int addr, int data, int next) :address(addr), data(data), next(next) {}
	int address;
	int data;
	int next;
};

//2019年3月1日14:39:38
//2019年3月1日15:01:45
///total time: 22min
int P1133() {
	int N, K, rootAddr;
	cin >> rootAddr >> N >> K;
	unordered_map<int, Node1133> nodes;
	int addr, data, next;
	for (int i = 0; i < N; i++) {
		cin >> addr >> data >> next;
		nodes[addr] = Node1133(addr, data, next);
	}
	vector<Node1133> belowZero;
	vector<Node1133> Zero2K;
	vector<Node1133> UpperK;
	int ptr = rootAddr;
	while (ptr != -1) {
		if (nodes[ptr].data < 0)
			belowZero.push_back(nodes[ptr]);
		else if (nodes[ptr].data > K)
			UpperK.push_back(nodes[ptr]);
		else
			Zero2K.push_back(nodes[ptr]);
		ptr = nodes[ptr].next;
	}
	vector<Node1133> res(belowZero);
	int i = 0;
	for (; i < Zero2K.size(); i++)
		res.push_back(Zero2K[i]);
	for (i = 0; i < UpperK.size(); i++)
		res.push_back(UpperK[i]);
	for (i = 0; i < res.size() - 1; i++) {
		printf("%05d %d %05d\n", res[i].address, res[i].data, res[i + 1].address);
	}
	printf("%05d %d -1\n", res[i].address, res[i].data);


	return 0;
}