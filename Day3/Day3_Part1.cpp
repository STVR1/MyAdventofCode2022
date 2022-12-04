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
	int count = 0;
	file.open(path, fstream::in);
	while (file.get(c)) {
		if (c != '\n') {
			for (int i = 0; i < strlen(letters); i++) {
				limit++;
				if (c == letters[i]) {
					meanings.push_back(limit);
					limit = 0;
					break;
				}
			}
		}
		else {
			for (int i = 0; i < (meanings.size() / 2); i++) {
				for (int j = (meanings.size() / 2); j < meanings.size(); j++) {
					if (meanings[i] == meanings[j]) {
						sum = sum + meanings[i];
						i = 348;
						break;
					}
				}
			}
			meanings.clear();
		}
	}
	file.close();
	cout << "The total score is " << sum << endl;
	return 0;
}