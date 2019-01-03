#include<iostream>
#include<string>
using namespace std;

int out_h, out_m, out_s;
int in_h, in_m, in_s;
string out_id, in_id;
void in_write(const int &in_hour, const int &in_minute, const int &in_second, const string &ID) {
	in_h = in_hour;
	in_m = in_minute;
	in_s = in_second;
	in_id = ID;
}

void out_write(const int &out_hour, const int &out_minute, const int &out_second, const string &ID) {
	out_h = out_hour;
	out_m = out_minute;
	out_s = out_second;
	out_id = ID;
}

int P1006() {
	int M;
	cin >> M;
	string ID;
	int in_hour, in_minute, in_second, out_hour, out_minute, out_second;
	cin >> ID;
	scanf_s("%d:%d:%d %d:%d:%d", &in_hour, &in_minute, &in_second, &out_hour, &out_minute, &out_second);
	in_write(in_hour, in_minute, in_second, ID);
	out_write(out_hour, out_minute, out_second, ID);
	int i;
	for (i = 1; i < M; i++) {
		cin >> ID;
		scanf_s("%d:%d:%d %d:%d:%d", &in_hour, &in_minute, &in_second, &out_hour, &out_minute, &out_second);
		if (in_hour < in_h) {
			in_write(in_hour, in_minute, in_second, ID);
		}
		else if (in_hour == in_h) {
			if (in_minute < in_m) {
				in_write(in_hour, in_minute, in_second, ID);
			}
			else if (in_minute == in_m) {
				if (in_second < in_s) {
					in_write(in_hour, in_minute, in_second, ID);
				}
			}
		}

		if (out_hour > out_h) {
			out_write(out_hour, out_minute, out_second, ID);
		}
		else if (out_hour == out_h) {
			if (out_minute > out_m) {
				out_write(out_hour, out_minute, out_second, ID);
			}
			else if (out_minute == out_m) {
				if (out_second > out_s) {
					out_write(out_hour, out_minute, out_second, ID);
				}
			}
		}
	}

	cout << in_id << " " << out_id;

	return 0;
}