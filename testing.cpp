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

	int res=0;
	int max1;
	int max2;

	string line;
	while (getline(myfile,line)) {
		max1=*(line.end()-2)-'0';
		max2=*(line.end()-1)-'0';
		for (auto i= line.rbegin()+2; i!=line.rend();++i) {
			if ((*i - '0') >= max1) {
				max2=(max1 > max2)? max1: max2;
				max1=(*i - '0');
			} 
		}
		res += max1*10+max2;
	}
	cout << res << "\n";




	myfile.close();
	/////////////////////////////////////////////////////////
	auto end = chrono::steady_clock::now();
	auto diff = end - start;
	cout << "Execution time: " << chrono::duration<double, milli>(diff).count() << " ms" << endl;

	return 0;
}