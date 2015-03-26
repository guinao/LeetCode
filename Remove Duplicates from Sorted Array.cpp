#include <cstdio>

class Solution {
public:
	int removeDuplicates(int A[], int n) {
		if(n == 0)
			return 0;
		int pre = 0;
		int cur = pre+1;
		while(cur < n){
			if(A[pre] != A[cur]){
				A[++pre] = A[cur];
			}
			cur++;
		}
		return pre+1;
	}
};

//#include <algorithm>
//using namespace std;
//
//class Solution {
//public:
//	int removeDuplicates(int A[], int n) {
//		return unique(A, A+n) - A;
//	}
//};

int main()
{
	Solution s;
	int a[] = {1, 1, 1, 2,3,5,6,6,6,6,6};
	int k = s.removeDuplicates(a, 10);
	for(int i=0; i<k; ++i)
		printf("%d ", a[i]);
	puts("");
	scanf("\n");
	return 0;
}