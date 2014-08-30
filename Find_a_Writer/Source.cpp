#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::getline;
using std::istringstream;
using std::vector;
using std::stoi;

int main(int argc, char *argv[])
{
	string input_file;

	// Check first argument if it exists for input file, otherwise ask user
	if (argc > 1)
	{
		input_file = argv[1];
	}
	else
	{
		cout << "Please enter the path to your input file: " << endl;
		cin >> input_file;
	}

	// Open input file and check if successfully opened
	ifstream ifs(input_file);
	if (!ifs)
	{
		cout << "Failed to open input file." << endl;
		return 1;
	}

	string line;
	// Get line from input file
	while (getline(ifs, line))
	{
		// Seperate line according to the pipe charter (|)
		istringstream iss(line);
		string writers_name, numbers;
		getline(iss, writers_name, '|');
		getline(iss, numbers, '|');

		// Remove the blank space at beginning of string
		numbers.erase(0, 1);

		// Convert string to int and load into vector
		istringstream iss_num(numbers);
		string num;
		vector<int> key;
		while (getline(iss_num, num, ' '))
		{
			int n = stoi(num) - 1;
			key.push_back(n);
		}

		// Print characters from writers_name string based on index values taken from vector
		for (auto &n : key)
		{
			cout << writers_name.at(n);
		}
		cout << endl;
	}

	return 0;
}