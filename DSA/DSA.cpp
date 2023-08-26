#include <iostream>
#include "FileHelper.h"
#include "Trie.h"

int main()
{
	vector<string> lines = FileHelper::ReadFile("import.txt");
	
	Trie* trie = new Trie();
	for (int i = 0; i < lines.size(); i++) {
		trie->InsertNode(lines[i]);
	}

	string s = "th";
	if (trie->Search(s)) {
		cout << "There is node: " << s << endl;
	}
	else {
		cout << "There is no node: " << s << endl;
	}
}