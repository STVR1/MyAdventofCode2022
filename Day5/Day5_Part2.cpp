#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<ctime>
using namespace std;
clock_t start = clock();
int main() {
	fstream file;
	string path;
	char c[1];
	int j = 0;
	bool start = false;
	bool ping = false;
	bool shot = false;
	int test = 0;
	int number = 0;
	int limit = 0;
	int a1 = 0;
	int a2 = 0;
	int a3 = 0;
	vector<vector<int>> supply(8);
	vector<vector<int>> realsupply(9);
	vector<int> temp;
	char str[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	cout << "Enter the path\n";
	cin >> path;
	file.open(path, fstream::in);
	while (file.get(c[0])) {
		if (c[0] != '\n' && start == false && ping == false) {
			for (int i = 0; i < strlen(str); i++) {
				if (c[0] == str[i]) {
					supply[j].push_back(i);
					break;
				}
				if (i == strlen(str) - 1 && c[0] != str[i]) {
					supply[j].push_back(-1);
				}
			}

		}
		else if (c[0] == '\n' && start == false && ping == false) {
			j++;
		}
		if (j == 8) {
			ping = true;
		}
		if (c[0] == 'm' && start == false && ping == true) {
			int f = 0;
			for (int k = 0; k < supply[0].size(); k++) {
				for (int i = 7; 0 <= i; i--) {
					if (supply[i][k] != -1) {
						realsupply[f].push_back(supply[i][k]);
						shot = true;
					}
					if (i == 0 && shot == true) {
						f++;
						shot = false;
					}
				}
			}
			start = true;
		}
		if (isdigit(c[0]) && start == true) {
			number = number * 10 + atoi(c);
		}
		else if (!isdigit(c[0]) && number != 0) {
			temp.push_back(number);
			number = 0;
		}
		if (c[0] == '\n' && start == true) {
			a1 = temp[2] - 1;                    
			a2 = temp[1] - 1;
			a3 = realsupply[a2].size() - temp[0];
			for (int i = 0; i < temp[0]; i++) {
				realsupply[a1].push_back(realsupply[a2][a3]);
				a3 = a3 + 1;
			}
			for (int i = 0; i < temp[0]; i++) {
				realsupply[a2].pop_back();
			}
			temp.clear();
		}
	}
	file.close();
	for (int i = 0; i < realsupply.size(); i++) {
		cout << "| ";
		for (int k = 0; k < realsupply[i].size(); k++) {
			cout << realsupply[i][k] << " ";
		}
		cout << "|\n";
	}
	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("The time: %f seconds\n", seconds);
	return 0;
}