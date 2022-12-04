#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
int main() {
	fstream file;
	string path;
	vector<int> temp;
	vector<int> pair;
	int count = 0;
	int score = 0;
	char c[1];
	int number = 0;
	int limit = 1;
	cout << "Enter the path\n";
	cin >> path;
	file.open(path, fstream::in);
	while (file.get(c[0])) {
		if (isdigit(c[0])) {
			temp.push_back(atoi(c));
		}
		else if (c[0] == '-') {
			temp.push_back(-1);
		}
		else if (c[0] == ',' || c[0] == '\n') {
			temp.push_back(-1);
			for (int i = 0; i < temp.size(); i++) {
				if (temp[i] != -1 && temp[i + 1] == -1) {
					number = limit * number + temp[i];
					pair.push_back(number);
					count++;
					number = 0;
					limit = 1;
				}
				else if (temp[i] != -1 && temp[i + 1] != -1) {
					number = limit * number + temp[i];
					limit = limit * 10;
				}
				if (count == 2) {
					count = 0;
					temp.clear();
					break;
				}
			}
			if (pair.size() == 4) {
				if ((pair[0] <= pair[2] && pair[3] <= pair[1]) ||
					(pair[2] <= pair[0] && pair[1] <= pair[3]) ||
					(pair[0] <= pair[2] && pair[2] <= pair[1]) ||
					(pair[0] <= pair[3] && pair[3] <= pair[1]) ||
					(pair[2] <= pair[0] && pair[0] <= pair[3]) ||
					(pair[2] <= pair[1] && pair[1] <= pair[3])) {
					score++;
				}
				pair.clear();
			}
		}
	}
	file.close();
	cout << "The total score is " << score << endl;
	return 0;
}