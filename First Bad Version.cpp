#include <cstdio>

// Forward declaration of isBadVersion API.
bool isBadVersion(int version)
{
	return version>=1702766719;
}

class Solution {
public:
	int firstBadVersion(int n) {
		long long lb = 0;
		long long ub = n;
		while(lb+1<ub){
			long long mid = (lb+ub)/2;
			if(isBadVersion(mid))
				ub = mid;
			else
				lb = mid;
		}
		return ub;
	}
};

int main()
{
	Solution s;
	printf("%d\n", s.firstBadVersion(2126753390));
	getchar();
	return 0;
}