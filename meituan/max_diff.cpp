class LongestDistance {
public:
    int getDis(vector<int> A, int n) {
        // write code here
		int min_val = INT_MAX, max_diff = 0;
		for(int i=0;i<n;i++){
			min_val = min(min_val, A[i]);
			max_diff = max(max_diff, A[i] - min_val);
		}
		return max_diff;
    }
};