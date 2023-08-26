#include <iostream>
#include "FileHelper.h"
#include "Trie.h"

void SearchWord(Trie*, string);

int main()
{
	vector<string> lines = FileHelper::ReadFile("import.txt");
	
	Trie* trie = new Trie();
	for (int i = 0; i < lines.size(); i++) {
		trie->Insert(lines[i]);
	}
	string s = "there";
	SearchWord(trie, s);
	trie->Delete(s);
	SearchWord(trie, s);
}

void SearchWord(Trie* trie,string s) {
	if (trie->Search(s)) {
		cout << "There is node: " << s << endl;
	}
	else {
		cout << "There is no node: " << s << endl;
	}
}