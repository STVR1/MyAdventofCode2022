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
	int position = 0;
	for (int i = 0; i < task.size(); i++) {
		if (task[i] > max) {
			max = task[i];
		}
	}
	cout << max << endl;
	return 0;
}