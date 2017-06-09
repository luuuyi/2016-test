//受牛客网之前模拟题，牛牛的数列启发
//维护两个同样长度的数组，一个从前往后统计最大值；
//另一个从后往前统计最大值
class MaxGap {
public:
    int findMaxGap(vector<int> A, int n) {
        // write code here
		int lens = A.size();
		vector<int> pre(lens, 0);
		vector<int> post(lens, 0);
		int left_max = 0x80000000, right_max = 0x80000000;
		//pre数组的每一位i代表0~i的最大值
		for(int i=0;i<lens;i++){
			if(A[i] > left_max){
				left_max = A[i];
			}
			pre[i] = left_max;
		}
		//post数组的每一位i代表从lens-1到i之间的最大值
		for(int i=lens-1;i>=0;i--){
			if(A[i] > right_max){
				right_max = A[i];
			}
			post[i] = right_max;
		}
		int max_val = 0;
		//返回最大值差值的最大值
		for(int i=0;i<lens-1;i++)	max_val = max(max_val, abs(pre[i]-post[i+1]));
		return max_val;
    }
};