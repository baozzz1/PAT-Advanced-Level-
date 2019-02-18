#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

const int maxTime = (17 - 8) * 60;
class customer {
public:
	int customer_number;
	int line_number;
	int finish_time;
};
class customerCmp {
public:
	bool operator()(const customer &c1, const customer &c2) {
		if (c1.finish_time == c2.finish_time)
			return c1.line_number > c2.line_number;
		else
			return c1.finish_time > c2.finish_time;
	}
};
//START	2019年2月18日14:12:35
//END	
//TIME	1h20min
//方案：采用事件驱动模拟，使用一个大小为N的优先队列，记录接下去一段时间，N个队头发生“队头办完事情，队尾插入新顾客”的时间点。
int P1014() {
	// N is the number of lines;
	int N, M, K, Q;
	scanf_s("%d %d %d %d", &N, &M, &K, &Q);
	int i;
	vector<int> customers_time(K + 1, 0);
	vector<int> customers_finish_time(K + 1, 0);
	vector<int> linesEnd(N + 1, 0);
	priority_queue<customer, vector<customer>, customerCmp> queue;
	for (i = 1; i <= K; i++) {
		scanf_s("%d", &customers_time[i]);
	}
	//PROCESS
	for (i = 0; i < M; i++) {
		for (int j = 1; j <= N; j++) {
			customer temp;
			if (linesEnd[j] > maxTime || linesEnd[j] < 0)
				linesEnd[j] = -1;
			else
				linesEnd[j] += customers_time[i*N + j];
			temp.customer_number = i * N + j;
				temp.line_number = j;
			temp.finish_time = linesEnd[j];
			customers_finish_time[i*N + j] = linesEnd[j];
			queue.push(temp);
		}
	}
	int curr = N * M + 1;
	while (curr <= K) {
		customer leave = queue.top();
		customer temp;
		queue.pop();
		if (linesEnd[leave.line_number] > maxTime || linesEnd[leave.line_number] < 0)
			linesEnd[leave.line_number] = -1;
		else
			linesEnd[leave.line_number] += customers_time[curr];

		temp.customer_number = curr;
		temp.line_number = leave.line_number;
		temp.finish_time = linesEnd[leave.line_number];
		customers_finish_time[curr] = linesEnd[leave.line_number];
		queue.push(temp);
		curr++;
	}
	int check;
	int hour, minute;
	for (i = 0; i < Q; i++) {
		scanf_s("%d", &check);
		//OUTPUT
		if (customers_finish_time[check] > maxTime || customers_finish_time[check] < 0)
			printf("Sorry\n");
		else{
			hour = customers_finish_time[check] / 60 + 8;
			minute = customers_finish_time[check] % 60;
			printf("%02d:%02d\n", hour, minute);
		}
	}
	return 0;
}