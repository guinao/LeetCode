#include <cstdio>
#include <vector>
#include <list>
#include <utility>
#include <unordered_map>
#include <iostream>
using namespace std;

class LRUCache{
private:
	list<pair<int,int> > cache;
	unordered_map<int, list<pair<int,int> >::iterator> rec;
	int n;

public:
	LRUCache(int capacity) {
		cache.clear();
		rec.clear();
		n = capacity;
	}

	int get(int key) {
		if(rec.find(key) == rec.end())
			return -1;

		list<pair<int,int> >::iterator it = rec[key];
		int ret = it->second;
		cache.erase(it);
		cache.push_front(make_pair(key, ret));
		rec[key] = cache.begin();
		return ret;
	}

	void set(int key, int value) {
		if(rec.find(key) != rec.end()){
			list<pair<int,int> >::iterator it = rec[key];
			cache.erase(it);
			cache.push_front(make_pair(key, value));
			rec[key] = cache.begin();
		}else{
			if(cache.size() == n){
				int del = cache.back().first;
				cache.pop_back();
				rec.erase(rec.find(del));
			}
			cache.push_front(make_pair(key, value));
			rec[key] = cache.begin();
		}
	}
};

int main(void)
{
	int n, re, op, k, v;
	while(EOF!=scanf("%d %d", &n, &re)){
		LRUCache cache(n);
		for(int i=0; i<re; ++i){
			scanf("%d", &op);
			if(op == 1){
				scanf("%d", &k);
				printf("%d\n", cache.get(k));
			}else{
				scanf("%d %d", &k, &v);
				cache.set(k, v);
			}
		}
	}
	
	return 0;
}