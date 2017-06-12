//经典汉诺塔求解问题，打印出移动信息
class Hanoi {
private:
    vector<string> ret;
    void hanoi(int n, const string &l, const string &m, const string &r){
        //只有第一个圆盘时，直接从l移动到r
        if(n == 1){
            ret.push_back("move from "+l+" to "+r);
        }
        //大于一个圆盘时，通过辅助位置移动
        else{
            //先把前n-1个圆盘通过移动到m，借助r的辅助
            hanoi(n-1, l, r, m);
            ret.push_back("move from "+l+" to "+r);
            //再把n-1个圆盘通过l的辅助从m移动到r即可
            hanoi(n-1, m, l, r);
        }
    }
public:
    vector<string> getSolution(int n) {
        // write code here
        if(n == 0)  return ret;
        string left = "left", right = "right", middle = "mid";
        hanoi(n, left, middle, right);
        return ret;
    }
};