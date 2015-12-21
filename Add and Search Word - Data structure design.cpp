#include <cstring>
#include <string>
#include <vector>
using namespace std;

class WordNode{
public:
	WordNode* next[26];
	bool isLeaf;

	WordNode(){
		isLeaf = false;
		for(int i=0; i<26; ++i)
			next[i] = NULL;
	}

	bool search(string word){
		if(word == "")
			return isLeaf;

		for(int i=0; i<26; ++i){
			if(next[i]!=NULL &&
				(word[0]=='.' || word[0]-'a'==i))
				if(next[i]->search(word.substr(1)))
					return true;
		}
		return false;
	}
};

class WordDictionary {
private:
	WordNode *root;

public:
	WordDictionary(){
		root = new WordNode();
	}

	// Adds a word into the data structure.
	void addWord(string word) {
		int i;
		WordNode* cur = root;
		for(i=0; i<word.size(); ++i){
			int x = word[i] - 'a';
			if(cur->next[x] == NULL)
				cur->next[x] = new WordNode();
			cur = cur->next[x];
		}
		cur->isLeaf = true;
	}

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool search(string word) {
		return root->search(word);
	}
};

//int main()
//{
//	WordDictionary wd;
//	int x;
//	char word[26];
//	while(EOF != scanf("%d", &x)){
//		scanf("%s", word);
//		if(x == 0)
//			wd.addWord(word);
//		else
//			printf("%s\n", wd.search(word)? "true": "false");
//	}
//	return 0;
//}