#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#pragma once

class FileHelper {
public:
	static vector<string> ReadFile(string path);
};