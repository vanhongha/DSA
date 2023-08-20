#include "FileHelper.h"

vector<string> FileHelper::ReadFile(string path) {
	ifstream file;
	file.open(path);
	string line;
	vector<string> lines;
	if (file.is_open()) {
		while (file) {
			getline(file, line);
			lines.push_back(line);
			file.tellg();
		}
	}
	else {
		cout << "Can't open file";
	}

	return lines;

}