class Solution {
private:
    vector<int> res1;
    vector<int> res2;
    void dfs(vector<string>& matrix, int cur, int indexA, int indexB, vector<int> tmp, vector<bool>& is_visit){
        int lens = matrix[cur].size();
        for(int i=0;i<lens;i++){
            if(i == cur)    continue;
            if(is_visit[i]) continue;
            if(matrix[cur][i] == '0')   continue;
            tmp.push_back(i);
            is_visit[i] = true;
            //这样写其实不对，只有根节点，然后A和B都是0的时候其实应该要有返回的
            if(i == indexA)  res1 = tmp;
            if(i == indexB)  res2 = tmp;
            dfs(matrix, i, indexA, indexB, tmp, is_visit);
            is_visit[i] = false;
            tmp.pop_back();
        }
    }
public:
    /**
     * 返回git树上两点的最近分割点
     * 
     * @param matrix 接邻矩阵，表示git树，matrix[i][j] == '1' 当且仅当git树中第i个和第j个节点有连接，节点0为git树的跟节点
     * @param indexA 节点A的index
     * @param indexB 节点B的index
     * @return 整型
     */
    int getSplitNode(vector<string> matrix, int indexA, int indexB) {
        int lens = matrix.size();
        if(lens == 0)   return 0;
        vector<bool> is_visit(lens, false); is_visit[0] = true;
        vector<int> tmp; tmp.push_back(0);
        dfs(matrix, 0, indexA, indexB, tmp, is_visit);
        int i = 0;
        for(;i<lens;i++){
            if(i < res1.size() && i < res2.size()){
                if(res1[i] == res2[i])  continue;
                else    break;
            }
            else    break;
        }
        if (i>0)    return res1[i-1];
        else    return 0;
    }
};