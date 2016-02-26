class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int> > ans;
		if(nums.size() == 0)
			return ans;

		sort(nums.begin(), nums.end());

		bool flag = true;
		while(flag){
		    ans.push_back(nums);
			flag = false;
			for(int i=nums.size()-1; i>0; --i){
				if(nums[i] > nums[i-1]){
					sort(nums.begin()+i, nums.end());
					int k = upper_bound(nums.begin()+i, nums.end(), nums[i-1]) - nums.begin();
					swap(nums[k], nums[i-1]);
					flag = true;
					break;
				}
			}
		}

		return ans;
	}
};
