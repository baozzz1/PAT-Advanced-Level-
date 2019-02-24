#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

bool isPrime(int x) {
	if (x == 2 || x == 3)
		return true;
	if (x == 1 || x % 2 == 0)
		return false;
	if (x % 6 != 1 && x % 6 != 5)
		return false;
	for (int i = 5; i <= sqrt(x); i += 6)
		if (x%i == 0 || x % (i + 2) == 0)
			return false;
	return true;
}

class positiveHashTable {
public:
	positiveHashTable(int Msize) :Max(Msize) {
		adj = vector<int>(Max,-1);
	}
	int hash(const int &input) {
		return input % Max;
	}
	bool insert(const int &input) {
		int index;
		for (int i = 0; i < Max; i++) {
			index = hash(hash(input) + i * i);
			if (adj[index] == -1) {
				adj[index] = input;
				return true;
			}
		}
		return false;
	}
	int findCount(const int &input) {
		int index, count = 1;
		for (int i = 0; i < Max; i++) {
			index = hash(hash(input) + i * i);
			if (adj[index] == input || adj[index] == -1)
				return count;
			count++;
		}
		return count;
	}
private:
	int Max;
	vector<int> adj;
};

int P1145() {
	int Msize, N, M;
	cin >> Msize >> N >> M;
	while (!isPrime(Msize))	Msize++;
	positiveHashTable pht(Msize);
	int num;
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &num);
		if (!pht.insert(num))
			cout << num << " cannot be inserted." << endl;
	}
	double count = 0;
	for (int i = 0; i < M; i++) {
		scanf_s("%d", &num);
		count += pht.findCount(num);
	}
	printf("%.1lf", (double)count / M);

	return 0;
}