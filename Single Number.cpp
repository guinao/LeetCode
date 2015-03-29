class Solution {
public:
	int singleNumber(int A[], int n){
		int ans = A[0];
		for(int i=1; i<n; ++i)
			ans ^= A[i];
		return ans;
	}
};