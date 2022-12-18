#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
void themaintask(string path) {
	ifstream file;
	string str;
	int number = 0;
	int integer = 0;
	bool sign = false;
	bool ping = false;
	int size = 0;
	int choice = 0;
	int counter = 0;
	char c[1];
	vector<vector<char>> image(6);
	for (int i = 0; i < image.size(); i++) {
		image[i].resize(40);
		for (int j = 0; j < 40; j++) {
			image[i][j] = '.';
		}
	}
	file.open(path);
	int k = 0;
	while (getline(file, str)) {
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == 'a') {
				choice = 2;
			}
			else if (str[i] == 'n') {
				choice = 1;
			}
			else if (str[i] == '-') {
				sign = true;
			}
			else if (isdigit(str[i])) {
				c[0] = str[i];
				number = number * 10 + atoi(c);
			}
			if (i == str.size() - 1) {
				if (sign == true) {
					number = number * (-1);
				}
				size = choice + counter;
				for (counter; counter < size; counter++) {
					if (counter == integer || counter == integer + 1 || counter == integer + 2) {
						image[k][counter] = '#';
					}
					if (counter == 39) {
						if (counter != size - 1) {
							counter = 0;
							k++;
							if (counter == integer || counter == integer + 1 || counter == integer + 2) {
								image[k][counter] = '#';
							}
							counter++;
						}
						else {
							counter = 0;
							k++;
						}
						break;
					}
				}
				integer = integer + number;
				number = 0;
				sign = false;
			}
		}
	}
	for (int i = 0; i < image.size(); i++) {
		for (int j = 0; j < 40; j++) {
			cout << image[i][j];
		}
		cout << endl;
	}
	file.close();
}
int main() {
	string path;
	cout << "Enter the path" << endl;
	cin >> path;
	themaintask(path);
	return 0;
}