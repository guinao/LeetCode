#include <cstdio>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
private:
	int gcd(int x, int y){
		if(y == 0)
			return x;
		return gcd(y, x%y);
	}

public:
	int maxPoints(vector<Point>& points) {
		if(points.size() <= 2)
			return points.size();

		map<pair<int,int>, int > m;
		int ans = 2;

		for(int i=0; i<points.size(); ++i){
			int dup = 1;
			int tmp = 0;
			m.clear();
			for(int j=i+1; j<points.size(); ++j){
				int x = points[i].x - points[j].x;
				int y = points[i].y - points[j].y;
				if(x==0 && y==0){
					++dup;
					continue;
				}

				int g = gcd(x, y);
				if(g != 0){
					x /= g;
					y /= g;
				}
				pair<int,int> p = make_pair(x, y);
				m[p] = m[p]+1;
				tmp = max(tmp, m[p]);
			}

			ans = max(ans, tmp+dup);
		}

		return ans;
	}
};

int main()
{
	Solution s;
	int n;
	vector<Point> vp;
	while(EOF != scanf("%d", &n)){
		int x, y;
		vp.clear();
		for(int i=0; i<n; ++i){
			scanf("%d %d", &x, &y);
			vp.push_back(Point(x,y));
		}
		printf("%d\n", s.maxPoints(vp));
	}
	return 0;
}