#include<iostream>
#include<cstdio>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<queue>
#include<set>

using namespace std;
vector<int> itemsSearchTimes;
class cmp{
public:
	bool operator()(const int &index1, const int &index2) {
	if (itemsSearchTimes[index1] == itemsSearchTimes[index2])
		return index1 < index2;
	else
		return itemsSearchTimes[index1] < itemsSearchTimes[index2];
}
};
typedef priority_queue<int, set<int>, cmp> pq;

int main() {
	int N, K;
	cin >> N >> K;
	itemsSearchTimes = vector<int>(N + 1, 0);
	//pq recommed;
	set<int, cmp> recommed;
	int num;
	cin >> num;
	itemsSearchTimes[num]++;
	recommed.insert(num);
	while (cin >> num) {
		cout << num << ":";
		auto iter = recommed.begin();
		for (int i = 0; i < K && iter!=recommed.end(); i++) {
			cout << " " << *iter;
			iter++;
		}
		cout << endl;
		itemsSearchTimes[num]++;
		recommed.insert(num);
	}
	return 0;
}