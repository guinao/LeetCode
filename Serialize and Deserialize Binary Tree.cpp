#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		if(root == NULL)
			return "[]";

		string ans = "[";
		char buf[32];
		queue<TreeNode*> q;
		q.push(root);
		while(!q.empty()){
			TreeNode* cur =q.front();
			q.pop();
			if(cur == NULL){
				ans.append("null,");
			}else{
				memset(buf, 0, sizeof buf);
				sprintf(buf, "%d,", cur->val);
				ans.append(buf);
				q.push(cur->left);
				q.push(cur->right);
			}
		}
		while(ans.length()>5 && ans.substr(ans.length()-5) == "null,"){
			for(int i=0; i<5; ++i) ans.pop_back();
		}
		ans[ans.length()-1] = ']';
		return ans;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		data = data.substr(1,data.length()-2);
		if(data.length() == 0 || data == "null")
			return NULL;

		// cout << data << endl;
		int pos = data.find(',');
		cout << pos << endl;
		if(pos == string::npos) pos = data.length();
		string ele = data.substr(0, pos);
		int v;
		sscanf(ele.c_str(), "%d", &v);
		TreeNode *head = new TreeNode(v);
		queue<TreeNode*> q;
		q.push(head);
		// 		cout << pos << endl;
		while(!q.empty() && pos<data.length()){
			TreeNode* cur = q.front();
			q.pop();

			int npos = data.find(',', pos+1);
			if(npos == string::npos)
				npos = data.length();
			ele = data.substr(pos+1, npos-pos-1);
			if(ele != "null"){
				sscanf(ele.c_str(), "%d", &v);
				cur->left = new TreeNode(v);
				q.push(cur->left);
			}
			pos = npos;

			if(pos >= data.length()) break;

			npos = data.find(',', pos+1);
			if(npos == string::npos)
				npos = data.length();
			ele = data.substr(pos+1, npos-pos-1);
			if(ele != "null"){
				sscanf(ele.c_str(), "%d", &v);
				cur->right = new TreeNode(v);
				q.push(cur->right);
			}
			pos = npos;

			if(pos >= data.length()) break;

		}

		return head;
	}
};