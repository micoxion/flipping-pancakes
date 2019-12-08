// Flipping Pancakes
// Micaiah Soto
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <set>

using namespace std;

string flip(int, string);
bool solved(string);

void main() {
	ifstream fin("pancakes.in");
	if (fin.is_open()) {
		ofstream fout("pancakes.out");

		set<string> markedNodes;
		queue<string> nodes;
		string stack, currentNode, flippedNode, parent;
		int flips = 0;
		bool correct = false;
		fin >> stack;

		while (stack != "0") {
			markedNodes.insert(stack);
			nodes.push(stack);

			if (!solved(stack)) {
				parent = stack;
				currentNode = flip(0, parent);
				nodes.push(currentNode);
				markedNodes.insert(currentNode);

				while (!nodes.empty()) {
					flips++;
					currentNode = nodes.front();
					if (solved(currentNode)) {
						break;
					}
					nodes.front();
					nodes.pop();

					for (int i = 0; i < stack.length(); i++) {
						flippedNode = flip(0, parent);
						if (markedNodes.find(flippedNode) == markedNodes.end()) {
							markedNodes.insert(flippedNode);
							nodes.push()
						}
					}
				}
			}
			else {
				flips = 1;
			}

			/*while (!nodes.empty() && !correct) {
				currentNode = nodes.front();
				
				if (solved(currentNode)) {
					break;
				}
				flips++;
				nodes.pop();
				for (int i = 0; i < stack.length(); i++) {
					flippedNode = flip(i, currentNode);
					if (markedNodes.find(flippedNode) == markedNodes.end()) {
						markedNodes.insert(flippedNode);
						nodes.push(flippedNode);
					}
					if (solved(flippedNode)) {
						correct = true;
						break;
					}
				}
			}*/

			fout << flips;
			correct = false;
			flips = 0;
			nodes = queue<string>();
			markedNodes.clear();
			fin >> stack;
			if (stack != "0") {
				fout << endl;
			}
		}

		fout.close();
		fin.close();
	}
	else {
		cout << "Input file not found." << endl;
	}
}

string flip(int flipPos, string stack) {
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
	return stack;
}

bool solved(string stack) {
	bool result = true;
	if (stack.length() == 1 && stack[0] > 90) {
		result = false;
	}
	for (int i = 0; i < stack.length() - 1; i++) {
		if (stack[i] > 90 || stack[i + 1] > 90) {
			result = false;
			break;
		}
		else if (stack[i] > stack[i + 1]) {
			result = false;
				break;
		}
	}
	return result;
}