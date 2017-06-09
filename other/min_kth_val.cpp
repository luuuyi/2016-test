//最白痴的做法，使用STL来做
class KthNumbers {
public:
    vector<int> findKthNumbers(vector<int> A, int n, int k) {
        // write code here
        sort(A.begin(), A.end());
        return vector<int>(A.begin(), A.begin()+k);
    }
};