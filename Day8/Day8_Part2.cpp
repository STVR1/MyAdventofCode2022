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
	int winner = 0;
	int sum = 0;
	int counter1 = 0;
	int counter2 = 0;
	int counter3 = 0;
	int counter4 = 0;
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
	for (int k = 1; k < square.size() - 1; k++) {
		for (int j = 1; j < square[k].size() - 1; j++) {
			for (int f = j - 1; 0 <= f; f--) {
				if (square[k][j] > square[k][f]) {
					counter1++;
				}
				else {
					counter1++;
					break;
				}
			}
			for (int f = j + 1; f < square[k].size(); f++) {
				if (square[k][j] > square[k][f]) {
					counter2++;
				}
				else {
					counter2++;
					break;
				}
			}
			for (int f = k - 1; 0 <= f; f--) {
				if (square[k][j] > square[f][j]) {
					counter3++;
				}
				else {
					counter3++;
					break;
				}
			}
			for (int f = k + 1; f < square.size(); f++) {
				if (square[k][j] > square[f][j]) {
					counter4++;
				}
				else {
					counter4++;
					break;
				}
			}
			sum = counter4 * counter3 * counter2 * counter1;
			if (sum > winner) {
				winner = sum;
			}
			sum = 0;
			counter1 = 0;
			counter2 = 0;
			counter3 = 0;
			counter4 = 0;
		}
	}
	return winner;
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