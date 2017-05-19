// find DP solver too long
class Visit {
private:
	void findLoc(int& x1, int& y1,int& x2,int& y2, vector<vector<int> >& map, int n, int m){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(map[i][j]==1){
					x1 = j; y1 = i;
				}
				else if(map[i][j]==2){
					x2 = j; y2 = i;
				}
			}
		}
	}

	int findPaths(int x1, int y1,int x2,int y2, vector<vector<int> >& map, int n, int m){
		int is_right = x1>x2?-1:1;
		int is_down = y1>y2?-1:1;
		bool is_invalid = false;
		for(int i=y1;i!=y2+is_down;i+=is_down){
			if(map[i][x1]==-1)	is_invalid = true;
			map[i][x1] = is_invalid?0:1;
		}
		is_invalid = false;
		for(int j=x1;j!=x2+is_right;j+=is_right){
			if(map[y1][j]==-1)	is_invalid = true;
			map[y1][j] = is_invalid?0:1;
		}
		for(int i=y1+is_down;i!=y2+is_down;i+=is_down){
			for(int j=x1+is_right;j!=x2+is_right;j+=is_right){
				if(map[i][j]!=-1){
					map[i][j] = map[i-is_down][j] + map[i][j-is_right];
				}
				else	map[i][j] = 0;
			}
		}
		return map[y2][x2];
	}

	//TODO
public:
    int countPath(vector<vector<int> > map, int n, int m) {
        // write code here
		int x1 = 0, y1 = 0;
		int x2 = 0, y2 = 0;
		findLoc(x1, y1, x2, y2, map, n, m);
		return findPaths(x1, y1, x2, y2, map, n, m);
    }
};