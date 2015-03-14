class Solution {
public:
	int majorityElement(vector<int> &num) {
		int ret = 0;
		int cnt = 0;
		for(int i=0; i<num.size(); ++i){
			if(cnt == 0){
				++cnt;
				ret = num[i];
			}
			else if(ret == num[i]){
				++cnt;
			}else{
				--cnt;
			}
		}
		cnt = 0;
		for(int i=0; i<num.size(); ++i){
			if(num[i] == ret){
				++cnt;
			}
		}
		if(cnt > num.size() / 2)
			return ret;
		else
			return 0;
	}
};