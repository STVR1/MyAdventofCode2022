#include<iostream>
#include<string>
#include<regex>
#include<fstream>
#include<vector>
using namespace std;
int main() {
	fstream file;
	string path;
	char c[1];
	int limit = 1;
	int number = 0;
	int sum = 0;
	bool ping = false;
	vector<int> task;
	cout << "Enter the path\n";
	cin >> path;
	file.open(path, fstream::in);
	while (!file.eof()) {
		file.get(c[0]);
		if (isdigit(c[0])) {
			number = number * limit + atoi(c);
			limit = 10;
			ping = false;
		}
		else if (c[0] == '\n' && ping == false) {

			sum = number + sum;
			limit = 1;
			number = 0;
			ping = true;
		}
		else if (c[0] == '\n' && ping == true) {
			task.push_back(sum);
			sum = 0;
			ping = false;
		}
	}
	file.close();
	int max = task[0];
	int point1 = 0;
	int point2 = 0;
	int point3 = 0;
	int position = 0;
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < task.size(); i++) {
			if (task[i] > max && task[i] != point1 && task[i] != point2 && task[i] != point3) {
				max = task[i];
				position = i + 1;
			}
			if (i == task.size() - 1 && j == 0) {
				cout << position << " " << max << endl;
				point1 = max;
			}
			else if (i == task.size() - 1 && j == 1) {
				cout << position << " " << max << endl;
				point2 = max;
			}
			else if (i == task.size() - 1 && j == 2) {
				cout << position << " " << max << endl;
				point3 = max;
			}
		}
		max = task[0];
	}
	cout << point1 + point2 + point3 << endl;
	return 0;
}