#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
using namespace std;
string readfile(string path) {
	fstream file;
	string line;
	file.open(path, fstream::in);
	file >> line;
	file.close();
	return line;
}
int maintask(string path) {
	string line = readfile(path);
	bool ping = true;
	int j = 0;
	for (int i = 0; i < line.size(); i++) {
		string check = "abcdefghijklmnopqrstuvwxyz";
		if (13 <= i) {
			j = i - 13;
			for (j; j <= i; j++) {
				for (int k = 0; k < check.size(); k++) {
					if (check[k] == line[j]) {
						check[k] = '1';
						break;
					}
					if (k == check.size() - 1 && check[k] != line[j]) {
						ping = false;
					}
				}
				if (ping == true && j == i) {
					return i + 1;
				}
			}

		}
		if (i == line.size() - 1) {
			return 0;
		}
		ping = true;
	}
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