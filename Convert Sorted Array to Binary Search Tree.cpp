#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return recursive(nums, 0, nums.size());
	}

	TreeNode* recursive(vector<int>& nums, int s, int e){
		if(s >= e)
			return NULL;

		int mid = (s+e) / 2;
		TreeNode* head = new TreeNode(nums[mid]);
		head->left = recursive(nums, s, mid);
		head->right = recursive(nums, mid+1, e);

		return head;
	}
};