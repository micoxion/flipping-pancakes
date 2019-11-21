// Flipping Pancakes
// Micaiah Soto
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void flip(int, vector<char>&);

void main() {
	ifstream fin("pancakes.in");
	if (fin.is_open()) {
		ofstream fout("pancakes.out");

		string pancakes;
		vector<char> stack;
		fin >> pancakes;

		while (pancakes != "0") {
			for (int i = 0; i < pancakes.size(); i++) {
				stack.push_back(pancakes[i]);
			}
			flip(0, stack);
		}

		fout.close();
		fin.close();
	}
	else {
		cout << "Input file not found." << endl;
	}
}

void flip(int flipPos, vector<char>& stack) {
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