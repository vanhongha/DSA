#include <string>
#include <iostream>
#include "TrieNode.h"
using namespace std;
#pragma once

class Trie {
private:
	TrieNode* root;
public:
	Trie();
	int GetIndex(char);
	void Insert(string);
	bool Search(string);
};