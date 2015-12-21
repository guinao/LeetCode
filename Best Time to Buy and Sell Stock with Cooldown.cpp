#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int buy=INT_MIN, buy_pre, sell=0, sell_pre=0;
		for(int i=0; i<prices.size(); ++i){
			buy_pre = buy;
			buy = max(sell_pre-prices[i], buy_pre);
			sell_pre = sell;
			sell = max(buy_pre+prices[i], sell_pre);
		}

		return sell;
	}
};