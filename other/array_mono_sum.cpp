//最白痴的做法，时间复杂度O(n*n)
class MonoSum {
public:
    int calcMonoSum(vector<int> A, int n) {
        // write code here
        //排除边界情况
        if(n == 1)  return 0;
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++)    count += A[j]<=A[i]?A[j]:0;
        }
        return count;
    }
};