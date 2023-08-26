#include "Trie.h"

Trie::Trie() {
	this->root = new TrieNode();
}

int Trie::GetIndex(char s) {
	return s - 'a';
}

void Trie::Insert(string s) {
	if (s.empty()) {
		return;
	}

	TrieNode* node = this->root;
	for (int i = 0; i < s.size(); i++) {
		s[i] = tolower(s[i]);
		int index = GetIndex(s[i]);
		if (node->GetChild(index) == nullptr) {
			node->InsertChild(index);
		}

		node = node->GetChild(index);
		if (i == s.size() - 1) {
			node->SetEnd(true);
		}
	}
}

bool Trie::Search(string s) {
	TrieNode* node = this->root;
	for (int i = 0; i < s.size(); i++) {
		char c = tolower(s[i]);
		int index = GetIndex(c);
		if (node->GetChild(index) == nullptr) {
			return false;
		}
		node = node->GetChild(index);
	}

	if (node != nullptr && node->IsEnd()) {
		return true;
	}

	return false;
}

bool Trie::Delete(string s) {
	TrieNode* node = this->root;
	for (int i = 0; i < s.size(); i++) {
		char c = tolower(s[i]);
		int index = GetIndex(c);
		if (node->GetChild(index) == nullptr) {
			return false;
		}
		node = node->GetChild(index);
		if (i == s.size() - 1 && node->IsEnd()) {
			node->SetEnd(false);
			return true;
		}
	}
	return false;
}