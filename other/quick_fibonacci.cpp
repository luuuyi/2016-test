//依图科技面试题
class Fibonacci {
private:
    vector<vector<long long>> matrixPow(int n){
        if(n==1)    return vector<vector<long long>>({
            {0, 1}, {1, 1}
        });
        //注意这个比较核心的地方，如果按下列写法，绝对递归层数太多超时
        //matrixMutply(matrixPow(n/2), matrixPow(n/2))
        //因为相当于matrixPow(n/2)要计算两边，而且是递归计算，耗时非常多
        vector<vector<long long>> tmp = matrixPow(n/2);
        if(n&0x01){
            vector<vector<long long>> single({{0, 1}, {1, 1}});
            return matrixMutply(tmp, matrixMutply(tmp, single));
        }
        else    return matrixMutply(tmp, tmp);
    }
    vector<vector<long long>> matrixMutply(const vector<vector<long long>>& a, const vector<vector<long long>>& b){
        vector<vector<long long>> ret(2, vector<long long>(2, 0));
        for(int i=0;i<2;i++){
            for(int j=0;j<=2;j++){
                //注意可能会超过限制
                //每一个环节都要对1000000007取余
                ret[i][j] = ((a[i][0]*b[0][j])%1000000007 + (a[i][1]*b[1][j])%1000000007)%1000000007;
            }
        }
        return ret;
    }
public:
    int getNthNumber(int n) {
        // write code here
        int real = n;
        if(real<2) return 1;
        else{
            vector<vector<long long>> help = matrixPow(real-1);
            long long res = help[0][1] + help[1][1];
            return int(res%1000000007);
        }
    }
};