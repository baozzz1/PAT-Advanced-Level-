#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;

struct rtangle {
	int w;
	int h;
	int area;
	double rate;
	bool isWMax;
	rtangle(int w, int h) :w(w), h(h) {
		area = w * h;
		isWMax = w > h;
		rate = isWMax ? (double)h / (double)w : (double)w / (double)h;
	}
	bool operator<(const rtangle &r2)const {
		if (area == r2.area) {
			if((isWMax?w:h)*(r2.isWMax?r2.h:r2.w) == (isWMax ? h : w)*(r2.isWMax ? r2.w : r2.h))
			//if ((rate == r2.rate)) {
				return w < r2.w;
			else
				return rate > r2.rate;
		}
		else
			return area < r2.area;
	}
};
//
//int main() {
//	int N; cin >> N;
//	int w, h;
//	vector<rtangle> total;
//	for (int i = 0; i < N; i++) {
//		cin >> w >> h;
//		total.push_back(rtangle(w, h));
//	}
//	sort(total.begin(), total.end());
//	for (auto r : total) {
//		cout << r.w << " " << r.h << " ";
//	}
//	return 0;
//}