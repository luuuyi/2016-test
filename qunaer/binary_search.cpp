class BinarySearch {
private:
	int binarySearch(vector<int>& A, int start, int end, int target){
		while(start<=end){
			int mid = start + (end - start) / 2;
			if(A[mid]==target){
				while(mid>=0&&A[mid]==target)	--mid;
				return mid+1;
			}
			else if(A[mid]>target)	end = mid - 1;
			else	start = mid + 1;
		}
		return -1;
	}
public:
    int getPos(vector<int> A, int n, int val) {
        // write code here
		return binarySearch(A,0,n-1,val);
    }
};