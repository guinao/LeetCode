#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size(), n = nums2.size();
		if(m > n)
			return findMedianSortedArrays(nums2, nums1);

		int lb=0, ub = m, i, j, half=(m+n+1)>>1;
		while(lb <= ub){
			i = (lb+ub) >> 1;
			j = half - i;
			if(i<m && j>0 && nums1[i]<nums2[j-1])
				lb = i+1;
			else if(i>0 && j<n && nums1[i-1]>nums2[j])
				ub = i-1;
			else
				break;
		}
		int x, y;
		if(i==0)
			x = nums2[j-1];
		else if(j==0)
			x = nums1[i-1];
		else
			x = max(nums1[i-1], nums2[j-1]);
		if((m+n)&1)
			return x;
		y = i==m? nums2[j] : j==n? nums1[i] : min(nums1[i], nums2[j]);
		return (x+y)*1./2;
	}
};