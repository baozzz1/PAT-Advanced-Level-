#include<iostream>
#include<cstdio>
#include<set>
using namespace std;

//START 2019年2月24日23:28:06
//END 2019年2月24日23:39:07
// 11min
int P1144() {
	int N;
	cin >> N;
	int num;
	set<int> nums;
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &num);
		if (num > 0)
			nums.insert(num);
	}
	if (nums.size() == 0) {
		cout << "1";
		return 0;
	}
	int i = 1;
	for (auto iter = nums.begin(); iter != nums.end(); iter++) {
		if (*iter > i) {
			cout << i;
			return 0;
		}
		i++;
	}
	cout << i;
	
	return 0;
}