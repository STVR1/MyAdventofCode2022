#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
int themaintask(string path) {
	ifstream file;
	string str;
	char c[1];
	int number = 0;
	bool sign = false;
	bool ping = false;
	int integer = 1;
	int counter = 0;
	int bonus = 1;
	int sum = 0;
	file.open(path);
	while (getline(file, str)) {
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == 'a') {
				counter = counter + 2;
				if (counter == 20 || counter == 60 || counter == 100
					|| counter == 140 || counter == 180 || counter == 220) {
					bonus = counter;
				}
				if (counter == 21 || counter == 61 || counter == 101
					|| counter == 141 || counter == 181 || counter == 221) {
					bonus = counter;
					ping = true;
				}
			}
			else if (str[i] == 'n') {
				counter++;
				if (counter == 20 || counter == 60 || counter == 100
					|| counter == 140 || counter == 180 || counter == 220) {
					bonus = counter;
				}
				i = str.size() - 1;
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
				if (ping == true) {
					if (bonus != 1) {
						sum = sum + integer * (bonus - 1);
						bonus = 1;

						integer = integer + number;
					}
				}
				else {
					integer = integer + number;
					if (bonus != 1) {
						sum = sum + (integer - number) * bonus;
						bonus = 1;
					}
				}
				number = 0;
				sign = false;
				ping = false;
			}

		}
	}
	file.close();
	return sum;
}
int main() {
	string path;
	cout << "Enter the path" << endl;
	cin >> path;
	cout << "The power is " << themaintask(path) << endl;
	return 0;
}