class Solution {
private:
    vector<vector<int>> res;
    void dfs(vector<string>& matrix, int cur, int indexA, int indexB, vector<int> tmp, vector<bool>& is_visit){
        int lens = matrix[0].size();
        for(int i=0;i<lens;i++){
            if(i == cur)    continue;
            if(is_visit[i]) continue;
            tmp.push_back(i);
            is_visit[i] = true;
            if(i == indexA || i == indexB)  res.push_back(tmp);
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
            if(i < res[0].size() && i < res[1].size()){
                if(res[0][i] == res[1][i])  continue;
                else    break;
            }
            else    break;
        }
        return res[0][i-1];
    }
};