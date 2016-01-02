#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> ans;
		vector<string> line;
		int cnt = maxWidth;

		for(int i=0; i<words.size(); ++i){
			if(cnt == maxWidth)
				cnt -= words[i].size();
			else
				cnt -= words[i].size() + 1;
			if(cnt == 0){
				string tmp = "";
				for(int j=0; j<line.size(); ++j){
					tmp += line[j] + " ";
				}
				tmp += words[i];
				ans.push_back(tmp);
				cnt = maxWidth;
			}else if(cnt < 0){
				cnt +=  1 + words[i].size();
				string tmp = line[0];

				for(int j=1; j<line.size(); ++j){
					int rest = line.size()-j;
					int blank;
					if(cnt % rest == 0){
						blank = cnt;
					}else{
						blank = cnt / rest + 1;
					}
					for(int k=0; k<blank; ++k)
						tmp.push_back(' ');
					cnt -= blank;
					tmp += line[j];
				}
				ans.push_back(tmp);
				cnt = maxWidth;
			}else{
				line.push_back(words[i]);
			}
		}

		if(line.size() > 0){
			string tmp = line[0];

			for(int j=1; j<line.size(); ++j){
				int rest = line.size()-j;
				int blank;
				if(cnt % rest == 0){
					blank = cnt;
				}else{
					blank = cnt / rest + 1;
				}
				for(int k=0; k<blank; ++k)
					tmp.push_back(' ');
				cnt -= blank;
				tmp += line[j];
			}
			ans.push_back(tmp);
		}
		return ans;
	}
};