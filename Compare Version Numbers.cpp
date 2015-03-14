#include <cstring>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int compareVersion(string version1, string version2) {
		char v1[1024];
		char v2[1024];
		strcpy(v1, version1.c_str());
		strcpy(v2, version2.c_str());
		char *p1 = strtok(v1, ".");
		int a;
		vector<int> va;
		while(p1 != NULL){
			sscanf(p1, "%d", &a);
			va.push_back(a);
			p1 = strtok(NULL, ".");
		}
		char *p2 = strtok(v2, ".");
		int b;
		vector<int> vb;
		while(p2 != NULL){
			sscanf(p2, "%d", &b);
			vb.push_back(b);
			p2 = strtok(NULL, ".");
		}
		auto it1 = va.begin();
		auto it2 = vb.begin();
		while(it1 != va.end() && it2 != vb.end()){
			if(*it1 > *it2)
				return 1;
			else if(*it1 < *it2)
				return -1;
			++it1, ++it2;
		}
		while(it1 != va.end()){
			if(*it1 != 0)
				return 1;
			++it1;
		}
		for(; it2 != vb.end(); ++it2){
			if(*it2 != 0)
				return -1;
		}
		return 0;
	}
};

int main()
{
	Solution s;
	string v1, v2;
	while(1){
		cin>>v1>>v2;
		printf("%d\n", s.compareVersion(v1, v2));
	}
	return 0;
}