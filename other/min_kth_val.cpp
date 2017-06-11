//最白痴的做法，使用STL来做
class KthNumbers {
public:
    vector<int> findKthNumbers(vector<int> A, int n, int k) {
        // write code here
        vector<int> tmp(A);
        sort(A.begin(), A.end());
        vector<int> ret;
        for(int i=0;i<n;i++){
            if(tmp[i] <= A[k-1])    ret.push_back(tmp[i]);
        }
        return ret;
    }
};

//使用快排确定第k个数的大小，然后按原数组的顺序遍历输出
class KthNumbers {
private:
    //使用快排的思路来确定第k大的值
    int findKth(vector<int>& tmp, int start, int end, int k){
        if(k > end-start+1)   return -1;
        else{
            int index = tmp[start], i = start, j = end;
            while(i < j){
                for(;j>i;j--){
                    if(tmp[j] > index)  continue;
                    else{
                        tmp[i++] = tmp[j];
                        break;
                    }
                }
                for(;i<j;i++){
                    if(tmp[i] < index)  continue;
                    else{
                        tmp[j--] = tmp[i];
                        break;
                    }
                }
            }
            //找到基准值是第几大的数
            tmp[i] = index;
            //根据基准值是第几大的数决定递归的在哪一半里面继续寻找
            if(i-start+1 == k)  return tmp[i];
            else if(i-start+1 > k)  return findKth(tmp, start, i-1, k);
            else    return findKth(tmp, i+1, end, k-i+start-1);
        }
    }
public:
    vector<int> findKthNumbers(vector<int> A, int n, int k) {
        // write code here
        vector<int> tmp(A);
        //利用快排的思路找到第k大的值
        int index = findKth(tmp, 0, n-1, k);
        vector<int> ret;
        //根据第k大的值，在原数组中找到k个最小的值，保持顺序不变
        for(int i=0;i<n;i++){
            if(A[i] <= index)   ret.push_back(A[i]);
        }
        return ret;
    }
};