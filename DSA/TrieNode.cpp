#include "TrieNode.h"

TrieNode::TrieNode() {
	for (int i = 0; i < ALPHABET_SIZE; i++) {
		this->children[i] = nullptr;
	}

	this->isEnd = false;
}

bool TrieNode::IsEnd() {
	return this->isEnd;
}

bool TrieNode::InsertChild(int index) {
	if (this->children[index] != nullptr) {
		return false;
	}

	this->children[index] = new TrieNode();
	return true;
}

TrieNode** TrieNode::GetChildren() {
	return this->children;
}

TrieNode* TrieNode::GetChild(int index) {
	if (this == nullptr) {
		return nullptr;
	}
	return this->children[index];
}

void TrieNode::SetEnd(bool isEnd) {
	this->isEnd = isEnd;
}