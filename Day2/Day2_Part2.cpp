#include<iostream>
#include<fstream>
using namespace std;
struct cases {
	int choice = 0;
};
int main() {
	fstream file;
	string path;
	char c;
	cout << "Enter the path\n";
	cin >> path;
	int sum = 0;
	cases enemy;
	cases me;
	int i = 0;
	file.open(path, fstream::in);
	while (file.get(c)) {
		if (c == 'A') {
			enemy.choice = 1;
		}
		else if (c == 'B') {
			enemy.choice = 2;
		}
		else if (c == 'C') {
			enemy.choice = 3;
		}
		else if (c == 'X') {
			me.choice = 1;
		}
		else if (c == 'Y') {
			me.choice = 2;
		}
		else if (c == 'Z') {
			me.choice = 3;
		}
		else if (c == ' ') {
			continue;
		}
		else if (c == '\n') {
			if (enemy.choice == 1 && me.choice == 1) {
				sum = sum + 3;
			}
			else if (enemy.choice == 1 && me.choice == 2) {
				sum = sum + 1 + 3;
			}
			else if (enemy.choice == 1 && me.choice == 3) {
				sum = sum + 2 + 6;
			}
			else if (enemy.choice == 2 && me.choice == 1) {
				sum = sum + 1;
			}
			else if (enemy.choice == 2 && me.choice == 2) {
				sum = sum + 2 + 3;
			}
			else if (enemy.choice == 2 && me.choice == 3) {
				sum = sum + 3 + 6;
			}
			else if (enemy.choice == 3 && me.choice == 1) {
				sum = sum + 2;
			}
			else if (enemy.choice == 3 && me.choice == 2) {
				sum = sum + 3 + 3;
			}
			else if (enemy.choice == 3 && me.choice == 3) {
				sum = sum + 1 + 6;
			}
		}
	}
	file.close();
	cout << "Your score\n";
	cout << sum << endl;
	return 0;
}