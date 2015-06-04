#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

/************************************************************************/
/* DP                                                                   */
/************************************************************************/
//class Solution {
//public:
//	bool isMatch(string s, string p){
//		int count = 0;
//		for(int i=0; i<p.length(); ++i){
//			if(p[i] == '*') ++count;
//		}
//		if(s.length() < p.length()-count)
//			return false;
//		if(count==0 && s.length()!=p.length())
//			return false;
//
//		vector<vector<bool> > dp;
//		dp.resize(s.size()+1);
//		for(int i=0; i<=(int)s.size(); ++i){
//			dp[i].resize(p.size()+1);
//			fill(dp[i].begin(), dp[i].end(), false);
//		}
//		dp[0][0] = true;
//		for(int j=1; j<=p.size(); ++j){
//			if(p[j-1] == '*')
//				dp[0][j] = dp[0][j-1];
//		}
//		for(int j=1; j<=p.size(); ++j){
//			for(int i=1; i<=s.size(); ++i){
//				if(p[j-1] == '*'){
//					dp[i][j] = dp[i-1][j-1]	|| dp[i-1][j] || dp[i][j-1];
//				}else if(p[j-1] == '?'){
//					dp[i][j] = dp[i-1][j-1];
//				}else{
//					dp[i][j] = dp[i-1][j-1] && s[i-1]==p[j-1];
//				}
//			}
//		}
//
//		return dp[s.size()][p.size()];
//	}
//};

/************************************************************************/
/* Memorial DP                                                          */
/************************************************************************/
//class Solution {
//public:
//	vector<vector<int> > dp;
//	vector<string> wb;
//
//	bool isMatch(string s, string p){
//		wb.clear();
//		string np;
//		int count = 0;
//		for(int i=0; i<p.length(); ++i){
//			if(p[i] != '*'){
//				np.push_back(p[i]);
//			}else{
//				if(!np.empty()){
//					wb.push_back(np);
//					np.clear();
//				}
//				while(i<p.length() && p[i]=='*') ++i,++count;
//				wb.push_back("*");
//				--i;
//			}
//		}
//		if(!np.empty())
//			wb.push_back(np);
//
//
//		if(s.length() < p.length()-count)
//			return false;
//		if(count==0 && s.length()!=p.length())
//			return false;
//
//		dp.resize(s.length()+1);
//		for(int i=0; i<=s.length(); ++i){
//			dp[i].resize(wb.size()+1);
//			fill(dp[i].begin(), dp[i].end(), -1);
//		}
//		dp[0][0] = 1;
//		for(int i=1; i<=s.length(); ++i){
//			dp[i][0] = 0;
//		}
//		return match(s, s.length(), wb.size());
//	}
//
//	bool match(string s, int i, int j){
//		if(dp[i][j] != -1)
//			return dp[i][j] == 1;
//
//		string &p = wb[j-1];
//		if(p[0] == '*'){
//			for(int k=i; k>=0; --k){
//				dp[i][j] = match(s, k, j-1);
//				if(dp[i][j] == 1)
//					break;
//			}
//		}else{
//			bool flag = true;
//			int len = (int)p.length();
//			for(int k=1; k<=len; ++k){
//				if(i-k<0 || (s[i-k]!=p[len-k] && p[len-k]!='?') ){
//					flag = false;
//					break;
//				}
//			}
//			dp[i][j] = flag && match(s, i-len, j-1);
//		}
//		return dp[i][j] == 1;
//	}
//};

/************************************************************************/
/* Greedy                                                               */
/************************************************************************/
//class Solution {
//public:
//	vector<vector<int> > dp;
//	vector<string> wb;
//
//	bool isMatch(string s, string p){
//		if(s.length()==0 && p.length()==0)
//			return true;
//
//		int n = constructWordList(p);
//		if(s.length() < p.length()-n)
//			return false;
//		if(n==0)
//			return match(s, p);
//
//		int index = 0;
//		for(int i=0; i<(int)wb.size()-1&&index<=s.length(); ++i){
//			if(wb[i][0]=='*')
//				continue;
//
//			int len = wb[i].length();
//			if(i==0){
//				if(!match(s.substr(0,len), wb[i])){
//					return false;
//				}else{
//					index = index+len;
//				}
//			}else{
//				for(; index+len<=s.length(); ++index){
//					if(match(s.substr(index, len), wb[i]))
//						break;
//				}
//				index = index+len;
//			}
//		}
//		if(index > s.length())
//			return false;
//
//		string last = wb.back();
//		if(last[0] == '*')
//			return true;
//		else{
//			int len = last.length();
//			if(index + len > s.length())
//				return false;
//			return match(s.substr(s.length()-len, len), last);
//		}
//	}
//
//	bool match(string s, string p){
//		int i=0, j=0;
//		while(i<s.length() && j<p.length()){
//			if(s[i]!=p[j] && p[j]!='?')
//				return false;
//			++i,++j;
//		}
//		return s.length()==p.length();
//	}
//
//	int constructWordList(string p){
//		wb.clear();
//		string np;
//		int count = 0;
//		for(int i=0; i<p.length(); ++i){
//			if(p[i] != '*'){
//				np.push_back(p[i]);
//			}else{
//				if(!np.empty()){
//					wb.push_back(np);
//					np.clear();
//				}
//				while(i<p.length() && p[i]=='*') ++i,++count;
//				wb.push_back("*");
//				--i;
//			}
//		}
//		if(!np.empty())
//			wb.push_back(np);
//		return count;
//	}
//};

/************************************************************************/
/* Greedy with KMP_match                                                */
/************************************************************************/
class Solution {
public:
	vector<vector<int> > dp;
	vector<string> wb;

	bool isMatch(string s, string p){
		if(s.length()==0 && p.length()==0)
			return true;

		int n = constructWordList(p);
		if(s.length() < p.length()-n)
			return false;
		if(n==0)
			return match(s, p);

		int index = 0;
		for(int i=0; i<(int)wb.size()-1&&index<=s.length(); ++i){
			if(wb[i][0]=='*')
				continue;

			int len = wb[i].length();
			if(i==0){
				if(!match(s.substr(0,len), wb[i])){
					return false;
				}else{
					index = index+len;
				}
			}else{
				index = kmp_match(s, wb[i], index);
			}
		}
		if(index > s.length())
			return false;

		string last = wb.back();
		if(last[0] == '*')
			return true;
		else{
			int len = last.length();
			if(index + len > s.length())
				return false;
			return match(s.substr(s.length()-len, len), last);
		}
	}

	void compute_prefix(const string& p, vector<int>& pi){
		int m = p.length();
		pi.resize(m);
		pi[0] = -1;
		int k = -1;
		for(int i=1; i<m; ++i){
			while(k>=0 && p[k+1]!=p[i] && p[k+1]!='?')
				k = pi[k];
			if(p[k+1] == p[i] || p[k+1]=='?')
				++k;
			pi[i] = k;
		}
	}

	int kmp_match(const string& s, const string& p, int i){
		int n = s.length();
		int m = p.length();
		vector<int> pi;
		compute_prefix(p, pi);
		int q = -1;
		for(; i<n; ++i){
			while(q>=0 && p[q+1]!=s[i] && p[q+1]!='?')
				q = pi[q];
			if(p[q+1] == s[i] || p[q+1]=='?')
				++q;
			if(q == m-1)
				break;
		}
		return i+1;
	}

	bool match(string s, string p){
		int i=0, j=0;
		while(i<s.length() && j<p.length()){
			if(s[i]!=p[j] && p[j]!='?')
				return false;
			++i,++j;
		}
		return s.length()==p.length();
	}

	int constructWordList(string p){
		wb.clear();
		string np;
		int count = 0;
		for(int i=0; i<p.length(); ++i){
			if(p[i] != '*'){
				np.push_back(p[i]);
			}else{
				if(!np.empty()){
					wb.push_back(np);
					np.clear();
				}
				while(i<p.length() && p[i]=='*') ++i,++count;
				wb.push_back("*");
				--i;
			}
		}
		if(!np.empty())
			wb.push_back(np);
		return count;
	}
};

int main()
{
	Solution s;
	string a, b;
	//while(1){
	//	cin >> a >> b;
	//	printf("%s\n", s.isMatch(a, b)==1? "true": "false" );
	//}
	printf("%s\n", s.isMatch("aa", "a")==1? "true": "false" );
	printf("%s\n", s.isMatch("aa", "aa")==1? "true": "false" );
	printf("%s\n", s.isMatch("aaa", "a")==1?"true": "false" );
	printf("%s\n", s.isMatch("aa", "*")==1?"true": "false" );
	printf("%s\n", s.isMatch("aa", "a*")==1?"true": "false" );
	printf("%s\n", s.isMatch("ab", "?*")==1?"true": "false" );
	printf("%s\n", s.isMatch("aab", "c*a*b")==1? "true": "false" );
	printf("%s\n", s.isMatch("b", "?*?")==1? "true": "false" );
	printf("%s\n", s.isMatch("b", "?*")==1? "true": "false" );
	printf("%s\n", s.isMatch("babbbbaabababaabbababaababaabbaabababbaaababbababaaaaaabbabaaaabababbabbababbbaaaababbbabbbbbbbbbbaabbb", "b**bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***a")==1?"true": "false" );
	getchar();
	return 0;
}