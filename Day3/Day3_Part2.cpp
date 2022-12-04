#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
int main() {
	fstream file;
	string path;
	char c;
	int limit = 0;
	int sum = 0;
	vector<int> meanings;
	char letters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	cout << "Enter the path\n";
	cin >> path;
	int point1 = 0;
	int point2 = 0;
	int point3 = 0;
	int count = 1;
	vector<int> point12;
	file.open(path, fstream::in);
	while (file.get(c)) {
		if (c != '\n') {
			for (int i = 0; i < strlen(letters); i++) {
				limit++;
				if (c == letters[i]) {
					meanings.push_back(limit);
					if (count == 1) {
						point1++;
					}
					else if (count == 2) {
						point2++;
					}
					else if (count == 3) {
						point3++;
					}
					limit = 0;
					break;
				}
			}
		}
		else if (c == '\n' && count != 3) {
			count++;
		}
		else if (c == '\n' && count == 3) {
			for (int i = 0; i < point1; i++) {
				for (int j = point1; j < (point1 + point2); j++) {
					if (meanings[i] == meanings[j]) {
						point12.push_back(meanings[i]);

					}
				}
			}
			for (int i = 0; i < point12.size(); i++) {
				for (int j = point1 + point2; j < meanings.size(); j++) {
					if (point12[i] == meanings[j]) {
						sum = sum + meanings[j];
						i = 348;
						break;
					}
				}
			}
			point12.clear();
			count = 1;
			point1 = 0;
			point2 = 0;
			point3 = 0;
			test = 1;
			meanings.clear();
		}
	}
	file.close();
	cout << "The total score is " << sum << endl;
	return 0;
}