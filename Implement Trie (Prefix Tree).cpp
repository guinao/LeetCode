#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Trie;

class TrieNode {
private:
	unordered_map<char, TrieNode*> children;
	bool isLeaf;
public:
	// Initialize your data structure here.
	TrieNode() {
		children = unordered_map<char, TrieNode*>();
		isLeaf = false;
	}

	TrieNode* getChild(char c){
		if(children.find(c) == children.end())
			return NULL;
		else
			return children[c];
	}

	bool insert(char c){
		if(children.find(c) != children.end())
			return false;

		children[c] = new TrieNode();
		return true;
	}

	bool empty(){
		return children.empty();
	}

	friend class Trie;
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string word) {
		int i;
		TrieNode *cur = root;
		for(i=0; i<word.length(); ++i){
			TrieNode *next = cur->getChild(word[i]);
			if(next)
				cur = next;
			else
				break;
		}
		for(; i<word.length(); ++i){
			cur->insert(word[i]);
			cur = cur->getChild(word[i]);
		}
		cur->isLeaf = true;
	}

	// Returns if the word is in the trie.
	bool search(string word) {
		TrieNode *cur = root;
		for(int i=0; i<word.length(); ++i){
			TrieNode *next = cur->getChild(word[i]);
			if(next)
				cur = next;
			else
				return false;
		}
		return cur->isLeaf;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		TrieNode *cur = root;
		for(int i=0; i<prefix.length(); ++i){
			TrieNode *next = cur->getChild(prefix[i]);
			if(next)
				cur = next;
			else
				return false;
		}
		return true;
	}

private:
	TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");