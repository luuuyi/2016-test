//取巧办法
//每次删掉字符串第一位，然后判断余下的部分是否是一个回文串
class Palindrome {
public:
    string addToPalindrome(string A, int n) {
        // write code here
        //首先维护一个反向的字符串
        string tmp(A.rbegin(), A.rend());
        string ret = "";
        for(int i=1;i<n;i++){
            //对比分别去掉两端之后的字符串是否相等；
            //别忘了取最小值的话，及时break
            if(A.substr(i) == tmp.substr(0,n-i)){    ret = A.substr(0,i); break;}
        }
        //最终还需要一次翻转
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

//dp做法
//借鉴最长公共子串的思路来做，时间复杂度O(n*n)