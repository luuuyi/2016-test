//解题之前要明白重复数只能是真前缀
class Periods {
public:
    long long getLongest(int n, string s) {
        // write code here
        if(n == 1)  return 0;
        vector<int> nums(n, 0);
        //首先将与首字符相同字符所在位置的值设为i
        for(int i=1;i<n;i++){
            if(s[i] == s[0])    nums[i] = i;
        }
        //从后往前，如果每个i位置后面的值都与首字符后面相对位置一样的字符相等
        //将该位置也设置成i
        //注意考虑越界的问题
        for(int i=n-1;i>0;i--){
            if(nums[i]>0){
                //
                for(int j=1;j<=i-1&&i+j<n;j++){
                    if(s[j] == s[i+j])  nums[i+j] = max(nums[i+j], nums[i]);
                    else    break;
                }
            }
        }
        //将所有的值相加返回即可
        long long ret = 0;
        for(int i=0;i<n;i++)    ret += nums[i];
        return ret;
    }
};