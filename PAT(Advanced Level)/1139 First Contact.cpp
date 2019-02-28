//#include<iostream>
//#include<cstdio>
//#include<vector>
//#include<string>
//#include<unordered_map>
//#include<unordered_set>
//#include<set>
//#include<iomanip>
//#include<algorithm>
//using namespace std;
//
//struct pairPeople {
//	pairPeople(int i1, int i2) {
//		if (i1 > 0) {
//			id1 = i1;
//			isMale1 = true;
//		}
//		else {
//			id1 = -i1;
//			isMale1 = false;
//		}
//		if (i2 > 0) {
//			id2 = i2;
//			isMale2 = true;
//		}
//		else {
//			id2 = -i2;
//			isMale2 = false;
//		}
//	}
//	int id1;
//	bool isMale1;
//	int id2;
//	bool isMale2;
//	bool operator<(const pairPeople &p2)const {
//		if (id1 == p2.id1)
//			return id2 < p2.id2;
//		else
//			return id1 < p2.id1;
//	}
//};
//
//struct network {
//	network(int n, int m) :n(n), m(m) {
//		contact = vector<vector<int>>(301, vector<int>(301,0));
//	}
//
//	void read() {
//		int p1, p2;
//		int count = 1;
//		for (int i = 0; i < m; i++) {
//			cin >> p1 >> p2;
//			adj[p1].push_back(p2);
//			adj[p2].push_back(p1);
//			if (log.find(p1) == log.end()) {
//				log.insert(p1);
//				transforms[p1] = count;
//				count++;
//			}
//			if (log.find(p2) == log.end()) {
//				log.insert(p2);
//				transforms[p2] = count;
//				count++;
//			}
//			contact[transforms[p1]][transforms[p2]] = 1;
//			contact[transforms[p2]][transforms[p1]] = 1;
//		}
//	}
//
//	set<pairPeople> dfs(const int &p1, const int &p2) {
//		set<pairPeople> res;
//		unordered_set<int> maybeF1, maybeF2;
//		if (p1 > 0) {
//			for (auto f1 : adj[p1])
//				if (f1 > 0)	maybeF1.insert(f1);
//		}
//		else {
//			for (auto f1 : adj[p1])
//				if (f1 < 0)	maybeF1.insert(f1);
//		}
//		if (p2 > 0) {
//			for (auto f2 : adj[p2])
//				if (f2 > 0)	maybeF2.insert(f2);
//		}
//		else {
//			for (auto f2 : adj[p2])
//				if (f2 < 0)	maybeF2.insert(f2);
//		}
//		maybeF1.erase(p1);
//		maybeF2.erase(p2);
//		for (auto iter1 = maybeF1.begin(); iter1 != maybeF1.end(); ++iter1) {
//			for (auto iter2= maybeF2.begin(); iter2 != maybeF2.end(); ++iter2) {
//				if(contact[transforms[*iter1]][transforms[*iter2]] == 1)
//					res.insert(pairPeople(*iter1, *iter2));
//			}
//		}
//
//		/*for (auto f1 : adj[p1]) {
//			if ((p1 < 0 && f1 < 0) || (p1 > 0 && f1 > 0)) {
//				for (auto f2 : adj[f1]) {
//					if ((p2 < 0 && f2 < 0) || (p2 > 0 && f2 > 0)) {
//						if (find(adj[f2].begin(), adj[f2].end(), p2) != adj[f2].end())
//							res.insert(pairPeople(f1, f2));
//					}
//				}
//			}
//		}*/
//		return res;
//	}
//
//	int n, m;
//	unordered_map<int, vector<int>> adj;
//	vector<vector<int>> contact;
//	unordered_set<int> log;
//	unordered_map<int, int> transforms;
//};
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	network networks(n, m);
//	int p1, p2;
//	networks.read();
//
//	int k; cin >> k;
//	set<pairPeople> res;
//	for (int i = 0; i < k; i++) {
//		cin >> p1 >> p2;
//		res.clear();
//		res = networks.dfs(p1, p2);
//		cout << res.size() << endl;
//		for (auto pp : res) {
//			cout << setw(4) << setfill('0') << pp.id1 << " ";
//			cout << setw(4) << setfill('0') << pp.id2 << endl;
//		}
//	}
//	return 0;
//}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
unordered_map<int, bool> arr;
struct node {
	int a, b;
};
bool cmp(node x, node y) {
	return x.a != y.a ? x.a < y.a : x.b < y.b;
}

//�ؼ������ڽӾ����ʾ���Ƿ�Ϊ���ѡ������ڽӱ��ʾ���Ƿ�Ϊͬ�����ѡ���
//0000 ��-0000���ѣ�����int����ʱ�޷���ʾ������Ϣ����˸���string���ܣ����жϳ��ȴ�С�����ж��Ա�
//���ʱ��ʾ4λ��
//��PATϵͳ��ԭ���뵼����һ�����Ե��ڴ泬�ޣ�ʹ��unordered_map<int, bool> arr �����ά����ɱ����ڴ泬��
int P1139() {
	int n, m, k;
	scanf("%d%d", &n, &m);
	vector<int> v[10000];
	for (int i = 0; i < m; i++) {
		string a, b;
		cin >> a >> b;
		if (a.length() == b.length()) {
			v[abs(stoi(a))].push_back(abs(stoi(b)));
			v[abs(stoi(b))].push_back(abs(stoi(a)));
		}
		arr[abs(stoi(a)) * 10000 + abs(stoi(b))] = arr[abs(stoi(b)) * 10000 + abs(stoi(a))] = true;
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int c, d;
		cin >> c >> d;
		vector<node> ans;
		for (int j = 0; j < v[abs(c)].size(); j++) {
			for (int k = 0; k < v[abs(d)].size(); k++) {
				if (v[abs(c)][j] == abs(d) || abs(c) == v[abs(d)][k]) continue;
				if (arr[v[abs(c)][j] * 10000 + v[abs(d)][k]] == true)
					ans.push_back(node{ v[abs(c)][j], v[abs(d)][k] });
			}
		}
		sort(ans.begin(), ans.end(), cmp);
		printf("%d\n", int(ans.size()));
		for (int j = 0; j < ans.size(); j++)
			printf("%04d %04d\n", ans[j].a, ans[j].b);
	}
	return 0;
}