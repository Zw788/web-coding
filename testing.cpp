/*
"stage changes" , no, push directly
"commit and sync" , always3
"pull?" doesn't matter


run in terminal "cd /workspaces/web-coding && g++ -Wall -Wextra -g3 testing.cpp -o output/testing && cd output && ./testing"
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <set>
#include <cmath>


using namespace std;


int main()
{
	auto start = chrono::steady_clock::now();
	/////////////////////////////////////////////////////////
	ifstream myfile;
	myfile.open("../aoc2025_input.txt");
	if (!myfile.is_open()) {
		cerr << "Error opening file" << endl;
		return 1;
	}

	string line;
	while (getline(myfile,line)) {
		cout << line << "\n";
	}

	myfile.close();
	/////////////////////////////////////////////////////////
	auto end = chrono::steady_clock::now();
	auto diff = end - start;
	cout << "Execution time: " << chrono::duration<double, milli>(diff).count() << " ms" << endl;

	return 0;
}