#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
private:
	const static int mod = 1<<20;
	const static char dna[];
	void encode(int& num, char c){
		num <<= 2;
		num %= mod;
		switch(c){
		case 'A':
			num += 0;
			break;
		case 'C':
			num += 1;
			break;
		case 'G':
			num += 2;
			break;
		case 'T':
			num += 3;
			break;
		};
	}

	string decode(int num){
		string ans;
		ans.resize(10);
		for(int i=0; i<10; ++i){
			ans[10-i-1] = dna[num%4];
			num >>= 2;
		}
		return ans;
	}
public:
	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> ans;
		if(s.size() < 10)
			return ans;

		unordered_map<int, int> cnt;
		int sign = 0;
		for(int i=0; i<10; ++i){
			encode(sign, s[i]);
		}
		cnt[sign] = 1;
		for(int i=10; i<s.size(); ++i){
			encode(sign, s[i]);
			if(cnt.find(sign) == cnt.end())
				cnt[sign] = 0;
			cnt[sign] += 1;
		}

		for(auto it=cnt.begin(); it!=cnt.end(); ++it){
			if(it->second > 1)
				ans.push_back(decode(it->first));
		}
		return ans;
	}
};

const char Solution::dna[] = "ACGT";