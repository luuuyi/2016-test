//难得的一次通过，求纸张的折痕
//使用递归的方法来做
class FoldPaper {
public:
    vector<string> foldPaper(int n) {
        // write code here
        if(n == 1)  return vector<string>({"down"});
        vector<string> last = foldPaper(n-1);
        vector<string> ret;
        int lens = last.size();
        //可以从实际中得到规律，每一次折痕是上一次的折痕之间插值，交替插值
        //比如使用1代表down，2代表up
        /*第一次：      1
        **第二次：  1   1   2
        **第三次：1 1 2 1 1 2 2
        **以此类推即可
        */
        for(int i=0;i<lens;i++){
            ret.push_back((i&0x01)==1?"up":"down");
            ret.push_back(last[i]);
        }
        ret.push_back("up");
        return ret;
    }
};