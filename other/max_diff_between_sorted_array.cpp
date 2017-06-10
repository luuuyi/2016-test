//桶排序经典题目
class MaxDivision {
public:
    int findMaxDivision(vector<int> A, int n) {
        // write code here
        if(n <= 1)  return 0;
        int max_val = 0x80000000, min_val = 0x7fffffff;
        //找到最大值和最小值
        for(int i=0;i<n;i++){
            max_val = max(max_val, A[i]);
            min_val = min(min_val, A[i]);
        }
        vector<int> buckets(max_val - min_val + 1, 0);
        //将每一个数填入到桶里面，计数加一
        for(int i=0;i<n;i++)    buckets[A[i]-min_val]++;
        //统计最大的连续的0有多少个即可判断最终的结果
        int ret = 0, lens = buckets.size(), count = 0;
        for(int i=0;i<lens;i++){
            if(buckets[i]==0){
                ++count;
            }
            else{
                ret = max(ret, count);
                count = 0;
            }
        }
        //最终要返回的是最大的差值，所以需要在结果+1
        return ret+1;
    }
};