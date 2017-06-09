class ArrayMex {
public:
    int findArrayMex(vector<int> A, int n) {
        // write code here
        for(int i=0;i<n;i++){
            //数组中的每一个数都应该到他该到的位置
            while(A[i]>=1 && A[i]<=n && A[i] != A[A[i]-1]){
                //
                //swap(A[i], A[A[i]-1]);
                //下面种情况oj报错？
                //事实证明oj出错了
                int tmp = A[A[i]-1];
                A[A[i]-1] = A[i];
                A[i] = tmp;
            }
        }
        int ret;
        for(ret=0;ret<n;ret++){
            if(A[ret] != ret+1) break;
        }
        return ret+1;
    }
};