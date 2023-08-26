using namespace std;
#pragma once

#define ALPHABET_SIZE 26

class TrieNode {
private:
	TrieNode* children[ALPHABET_SIZE];
	bool isEnd;
public:
	TrieNode();
	bool IsEnd();
	bool InsertChild(int);
	TrieNode** GetChildren();
	TrieNode* GetChild(int);
	void SetEnd(bool);
};