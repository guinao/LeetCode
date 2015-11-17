#include <vector>
using namespace std;

class NumMatrix {
private:
	vector<vector<long long> > bittree;

	int lowbit(int x)
	{
		return x & (-x);
	}

	void update(int x, int y, long long val)
	{
		for(int i=x; i<bittree.size(); i+=lowbit(i))
			for(int j=y; j<bittree[0].size(); j+=lowbit(j))
				bittree[i][j] += val;
	}

	long long sum(int x, int y)
	{
		long long s = 0;
		for(int i=x; i>0; i-=lowbit(i))
			for(int j=y; j>0; j-=lowbit(j))
				s += bittree[i][j];

		return s;
	}

public:
	NumMatrix(vector<vector<int>> &matrix) {
		int n = matrix.size();
		int m = matrix[0].size();
		bittree = vector<vector<long long> >(n+1, vector<long long>(m+1, 0));

		for(int i=0; i<n; ++i){
			for(int j=0; j<m; ++j){
				update(i+1, j+1, matrix[i][j]);
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		return sum(row2+1, col2+1) 
			- sum(row2+1, col1) 
			- sum(row1, col2+1)
			+ sum(row1, col1);
	}
};

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	vector<vector<int> > mat(n, vector<int>(m,0));
	int x;
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			scanf("%d", &x);
			mat[i][j] = x;
		}
	}
	NumMatrix nm(mat);
	int r1, c1, r2, c2;
	while(EOF != scanf("%d %d %d %d", &r1, &c1, &r2, &c2)){
		printf("%d\n", nm.sumRegion(r1, c1, r2, c2));
	}
}