#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<ctime>
using namespace std;
int maintask(string path) {
	fstream file;
	char c[1];
	int i = 0;
	int counter = 0;
	int sum = 0;
	bool ping = false;
	vector<vector<int>> square(1);
	file.open(path, fstream::in);
	while (file.get(c[0])) {
		if (c[0] == '\n') {
			i++;
			square.resize(i + 1);
		}
		else {
			square[i].push_back(atoi(c));
		}
	}
	file.close();
	square.resize(i);
	sum = square[0].size() + square[i - 1].size() + i * 2 - 4;
	//Вот это чекни
	for (int k = 1; k < square.size() - 1; k++) {
		for (int j = 1; j < square[k].size() - 1; j++) {
			ping = false;
			if (ping == false) {
				for (int f = 0; f < j; f++) {
					if (square[k][j] > square[k][f]) {
						counter++;
					}
					if (counter == f + 1 && f == j - 1) {
						sum++;
						ping = true;
					}
				}
			}
			counter = 0;
			if (ping == false) {
				counter = j + 1;
				for (int f = j + 1; f < square[k].size(); f++) {
					if (square[k][j] > square[k][f]) {
						counter++;
					}
					if (counter == square[k].size() && f == square[k].size() - 1) {
						sum++;
						ping = true;
					}
				}
			}
			counter = 0;
			if (ping == false) {
				for (int f = 0; f < k; f++) {
					if (square[k][j] > square[f][j]) {
						counter++;
					}
					if (counter == f + 1 && f == k - 1) {
						sum++;
						ping = true;
					}
				}
			}
			counter = 0;
			if (ping == false) {
				counter = k + 1;
				for (int f = k + 1; f < square.size(); f++) {
					if (square[k][j] > square[f][j]) {
						counter++;
					}
					if (counter == square.size() && f == square.size() - 1) {
						sum++;
					}
				}
			}
			counter = 0;
		}
	}
	return sum;
}
int main() {
	string path;
	cout << "Enter the path" << endl;
	cin >> path;
	clock_t start = clock();
	cout << "The result is " << maintask(path) << endl;
	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("The time: %f seconds\n", seconds);
	return 0;
}