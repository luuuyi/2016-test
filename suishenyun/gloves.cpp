class Gloves {
public:
    //对于非0递增序列a1,a2...an，要想最终取值覆盖每一个种类
    //n = sum(a1...an) - a1 + 1（也就是总数减去最小值之后加一）
    //所以对于左右手手套颜色都有数量的序列，取左边和右边的最小值即可
    int findMinimum(int n, vector<int> left, vector<int> right) {
        // write code here
        int left_sum = 0, left_min = INT_MAX;
        int right_sum = 0, right_min = INT_MAX;
        int sum = 0;
        //遍历每一种颜色的左右手套序列
        for(int i=0;i<n;i++){
            //对于有0存在的颜色手套，累加
            if(left[i]*right[i]==0) sum += left[i] + right[i];
            //对于左右手都有的颜色手套，执行上面的策略
            //找到最小值和总数
            else{
                left_sum += left[i];
                right_sum += right[i];
                left_min = min(left_min, left[i]);
                right_min = min(right_min, right[i]);
            }
        }
        //结果为有左右都有数量的手套序列的结果+有0存在的手套数+最后再加一肯定就能保证了
        return sum + min(left_sum-left_min+1, right_sum-right_min+1) + 1;
    }
};