class MaxInnerRec {
public:
    int countArea(vector<int> A, int n) {
        // write code here
		stack<int> stk;
		A.push_back(-1);
		int max_ret = INT_MIN;
		int lens = A.size();
		if(n==0)	return 0;
		for(int i=0;i<lens;i++){
			if(stk.empty()||A[stk.top()]<=A[i]){
				stk.push(i); continue;
			}
			while(!stk.empty()&&A[stk.top()]>A[i]){
				int index = stk.top(); stk.pop();
				max_ret = max(max_ret, A[index]*(stk.empty()?i:i-stk.top()-1));
			}
			stk.push(i);
		}
		return max_ret;
    }
};