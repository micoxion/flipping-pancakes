// Flipping Pancakes
// Micaiah Soto
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void flip(int, string&);

void main() {
	ifstream fin("pancakes.in");
	if (fin.is_open()) {
		ofstream fout("pancakes.out");

		string stack;
		fin >> stack;

		while (stack != "0") {
			flip(0, stack);
		}

		fout.close();
		fin.close();
	}
	else {
		cout << "Input file not found." << endl;
	}
}

void flip(int flipPos, string& stack) {
	string flipped = "";
	for (int i = stack.size() - 1; i > flipPos - 1; i--) {
		if (stack[i] > 90) {
			flipped += stack[i] - 32;
		}
		else {
			flipped += stack[i] + 32;
		}
	}
	for (int i = flipPos; i < stack.size(); i++) {
		stack[i] = flipped[i - flipPos];
	}
}