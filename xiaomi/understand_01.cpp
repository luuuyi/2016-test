class Solution {
private:
    int findOnes(int n){
        int tmp = n;
        int count = 0;
        while(tmp){
            ++count;
            tmp &= tmp - 1;
        }
        return count;
    }
public:
    /**
     * 获得两个整形二进制表达位数不同的数量
     * 
     * @param m 整数m
     * @param n 整数n
     * @return 整型
     */
    int countBitDiff(int m, int n) {
        int res = m^n;
        return findOnes(res);
    }
};