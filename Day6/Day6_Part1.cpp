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
	for (int i = 0; i < line.size(); i++) {
		if (3 <= i && line[i - 1] != line[i] && line[i - 2] != line[i] && line[i - 3] != line[i] && line[i - 1] != line[i - 2] &&
			line[i - 1] != line[i - 3] && line[i - 2] != line[i - 3]) {
			return i + 1;
		}
		if (i == line.size() - 1) {
			return 0;
		}
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