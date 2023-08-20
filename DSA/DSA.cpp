#include <iostream>
#include "FileHelper.h"

int main()
{
	vector<string> lines = FileHelper::ReadFile("import.txt");
	for (int i = 0; i < lines.size(); i++) {
		cout << lines[i] << endl;
	}
}