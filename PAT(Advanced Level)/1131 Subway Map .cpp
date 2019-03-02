#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<set>

using namespace std;

int pairStops(const int &s1, const int &s2) {
	return s1 * 10000 + s2;
}

class subwayMap {
public:
	subwayMap(int n) :N(n) {
	}
	void getSubwayLines() {
		int M;
		int stop;
		for (int lineNo = 1; lineNo <= N; lineNo++) {
			cin >> M;
			//first stop
			scanf_s("%d", &stop);
			int lastStop = stop;
			for (int j = 2; j <= M; j++) {
				scanf_s("%d", &stop);
				pairStops2Line[pairStops(lastStop, stop)] = lineNo;
				pairStops2Line[pairStops(stop, lastStop)] = lineNo;
				stop2otherCollectedStops[lastStop].insert(stop);
				stop2otherCollectedStops[stop].insert(lastStop);
				lastStop = stop;
			}
		}
	}

	int getTranferTimes(const vector<int> &path) {
		int count = -1, perLine = 0;
		int currLine;
		for (int i = 1; i < path.size(); i++) {
			currLine = pairStops(path[i - 1], path[i]);
			if (currLine != perLine)	count++;
			perLine = currLine;
		}
		return count;
	}

	void dfs(const int &currStop, const int &stopCount, const int &des, vector<int> &path) {
		int tranferTimes = getTranferTimes(path);
		if (currStop == des) {
			if (stopCount < minStopCount)
				getMin(stopCount, tranferTimes, path);
			else if (stopCount == minStopCount) {
				if (tranferTimes < minTranferTimes)
					getMin(stopCount, tranferTimes, path);
			}
			else
				return;
		}
		for (auto iter = stop2otherCollectedStops[currStop].cbegin(); iter != stop2otherCollectedStops[currStop].cend(); ++iter) {
			if (!isVisited[*iter]) {
				isVisited[*iter] = true;
				path.push_back(*iter);
				dfs(*iter, stopCount + 1, des, path);
				isVisited[*iter] = false;
				path.pop_back();
			}
		}
	}

	void getMin(const int &stopCount, const int &tranferTimes, const vector<int> &path) {
		minStopCount = stopCount;
		minTranferTimes = tranferTimes;
		finalPath = path;
	}

	void clearEverytime() {
		finalPath.clear();
		minStopCount = 9999;
		minTranferTimes = 9999;
	}

	int N;
	unordered_map<int, unordered_set<int>> stop2otherCollectedStops;
	unordered_map<int, int> pairStops2Line;
	unordered_map<int, bool> isVisited;
	vector<int> finalPath;
	int minStopCount, minTranferTimes;

};

//START 2019年3月2日00:35:04
//FINISH READ 2019年3月2日00:40:35
//TOO HARD	WRONG
int P1131() {
	int N; cin >> N;
	subwayMap totalMap(N);
	totalMap.getSubwayLines();

	int K; cin >> K;
	int start, destination;
	vector<int> tempPath;
	for (int i = 0; i < K; i++) {
		cin >> start >> destination;

		totalMap.clearEverytime();
		tempPath.clear();

		tempPath.push_back(start);
		totalMap.isVisited[start] = true;
		totalMap.dfs(start, 0, destination, tempPath);
		totalMap.isVisited[start] = false;
		printf("%d\n", totalMap.minStopCount);
		int preLine = 0, preTranfer = start;
		int currLine;
		for (int j = 1; j < totalMap.finalPath.size(); j++) {
			currLine = totalMap.pairStops2Line[pairStops(totalMap.finalPath[j - 1], totalMap.finalPath[j])];
			if (currLine != preLine){
				if (preLine != 0) printf("Take Line#%d from %04d to %04d.\n", preLine, preTranfer, totalMap.finalPath[j - 1]);
				preLine = currLine;
				preTranfer = totalMap.finalPath[j - 1];
			}
		}
		printf("Take Line#%d from %04d to %04d.\n", preLine, preTranfer, destination);
	}
	return 0;
}