#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		string ans = "";

		vector<string> folder;

		string f = "";		
		for(int i=1; i<path.length(); ++i){
			if(path[i] == '/'){
				if(f == ".."){
					if(folder.size() > 0)
						folder.pop_back();
				}else if(f != "." && f!=""){
					folder.push_back(f);
				}
				f = "";
			}else{
				f.push_back(path[i]);
			}
		}
		if(f == ".."){
			if(folder.size() > 0)
				folder.pop_back();
		}else if(f != "." && f!=""){
			folder.push_back(f);
		}

		if(folder.empty())
			return "/";

		for(int i=0; i<folder.size(); ++i){
			ans = ans + "/" + folder[i];
		}

		return ans;
	}
};

int main()
{
	Solution s;
	char buf[32];
	while(EOF != scanf("%s", buf)){
		printf("%s\n", s.simplifyPath(buf).c_str());
	}
	return 0;
}