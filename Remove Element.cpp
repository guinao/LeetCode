#include <cstdio>

class Solution {
public:
	int removeElement(int A[], int n, int elem) {
		int index=0, cur=0;
		while(cur < n){
			if(A[cur] == elem){
				cur ++;
			}else{
				A[index++] = A[cur++];
			}
		}
		return index;
	}
};