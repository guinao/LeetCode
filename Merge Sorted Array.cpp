#include <cstdio>
#include <cstdlib>
#include <cstring>

class Solution {
public:
	void merge(int A[], int m, int B[], int n) {
		int i=0, j=0, index = 0;
		int *C = (int*)malloc((m+n)*sizeof(int));
		while(i<m && j<n){
			if(A[i] < B[j]){
				C[index++] = A[i++];
			}else{
				C[index++] = B[j++];
			}
		}
		for(; i<m; ++i)
			C[index++] = A[i];
		for(; j<n; ++j)
			C[index++] = B[j];

		for(int i=0; i<m+n; ++i)
			A[i] = C[i];

		free(C);
	}
};

int main()
{
	int A[] = {1,2,3};
	int B[] = {4,5,6};
	Solution s;
	s.merge(A, 3, B, 3);
	for(int i=0; i<6; ++i){
		printf("%d ", A[i]);
	}
	printf("\n");
	scanf("\n");
	return 0;
}