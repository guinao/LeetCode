#include <cstring>
#include <cstdio>
#include <cstdlib>

//class Solution {
//public:
//	int strStr(char *haystack, char *needle) {
//		int lena = strlen(haystack);
//		int lenb = strlen(needle);
//		for(int i=0; i<=lena-lenb; ++i){
//			if(strncmp(haystack+i, needle, lenb) == 0)
//				return i;
//		}
//		return -1;
//	}
//};

class Solution {
public:
	int strStr(char *haystack, char *needle) {
		if(strcmp(needle, "") == 0)
			return 0;
		int n = strlen(haystack);
		int m = strlen(needle);
		//compute_prefix
		int *pi = (int*)malloc(m*sizeof(int));

		pi[0] = -1;
		int k = -1;
		for(int i=1; i<m; ++i){
			while(k>=0 && needle[k+1]!=needle[i])
				k = pi[k];
			if(needle[k+1] == needle[i])
				++k;
			pi[i] = k;
		}
		for(int i=0; i<m; ++i)
			printf("%d ", pi[i]);
		printf("\n");

		//kmp
		int q = -1;
		for(int i=0; i<n; ++i){
			while(q>=0 && needle[q+1]!=haystack[i])
				q = pi[q];
			if(needle[q+1] == haystack[i])
				++q;
			if(q == m-1){
				free(pi);
				return i-q;
			}
		}
		free(pi);
		return -1;
	}
};

int main()
{
	char a[] = "bbababaaaababbaabbbabbbaaabbbaaababbabaabbaaaaabbaaabbbbaaabaabbaababbbaabaaababbaaabbbbbbaabbbbbaaabbababaaaaabaabbbababbaababaabbaa";
	char b[] = "bbabba";
	Solution s;
	printf("%d\n", s.strStr(a,b));
	scanf("%*d");
	return 0;
}
