#include <cstdio>
#include <cstddef>
#include <cstdint>
#include <iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
		for(int i=0; i<32; ++i){
			ans <<= 1;
			if(n & 1){
				ans |= 1;
			}
			n >>= 1;
		}
		return ans;
    }
};

int main()
{
	Solution s;
	uint32_t a;
	while(EOF != scanf("%u", &a)){
		printf("%u\n", s.reverseBits(a));
	}
}