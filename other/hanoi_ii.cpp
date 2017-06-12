//判断汉诺塔中间状态
//最白痴的方法可以模拟汉诺塔转移，然后判断是第几步
class Hanoi { 
public:
    int chkStep(vector<int> arr, int n) {
        // write code here
        //初始化状态
        int sum = 0, cur = n-1, left = 1, mid = 2, right = 3;
        //从最后一块圆盘开始逐步向前计算，最后一块圆盘永远不可能在辅助位置
        for(;cur>=0&&arr[cur]!=mid;cur--){
            if(arr[cur] == left){
                //最后一块圆盘还在原地没动，可以判断最后一块圆盘之前的都还在转移中，交换目标位置和辅助位置的值
                swap(mid, right);
            }
            else{
                sum += pow(2, cur);
                //最后一块圆盘已经就绪，所以可以得知已经花费了多少步
                //然后交换辅助位和初始位的值
                swap(mid, left);
            }
        }
        //如果cur还指向某一个圆盘，代表这个状态是不可能的，反之返回统计值
        return cur >= 0?-1:sum;
    }
};