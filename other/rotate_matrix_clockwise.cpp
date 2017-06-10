//使用辅助空间来做
class Rotate {
public:
    vector<vector<int> > rotateMatrix(vector<vector<int> > mat, int n) {
        // write code here
        //新建数组比较耗时
        vector<vector<int>> ret(n, vector<int>(n, 0));
        //关键是找到规律，mat[i][j]会被移动到mat[j][n-i-1]
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                ret[j][n-i-1] = mat[i][j];
        return ret;
    }
};

//不使用辅助空间来做，可以节约时间
class Rotate {
public:
    vector<vector<int> > rotateMatrix(vector<vector<int> > mat, int n) {
        // write code here
        //对数组顺时针旋转90度可以看成是先对数组上下翻转，然后再右上，左下翻转即可
        //上下翻转
        for(int i=0;i<n/2;i++)
            for(int j=0;j<n;j++)
                swap(mat[i][j], mat[n-i-1][j]);
        //右上，左下翻转
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                swap(mat[i][j], mat[j][i]);
        return mat;
    }
};