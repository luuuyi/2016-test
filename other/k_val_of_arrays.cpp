class Solution {
private:
	//每一次将k一分为二，比较两个数组中同样位置的值得大小
	//如果a(k/2) < b(k/2)可以证明a(k/2)不会是第k小的数
	//所以可以抛弃a(k/2)及其之前的数，然后求第k-k/2小的数
	int findKth(const vector<int>& arr1, int s1, int e1, const vector<int>& arr2, int s2, int e2, int kth){
		//保证长度比较小的数组在前
		if((e1-s1) > (e2-s2))	return findKth(arr2, s2, e2, arr1, s1, e1, kth);
		//当某一个数组全部被舍弃以后，即为求另一个数组的第k个数
		if(e1-s1 < 0)	return arr2[kth-1];
		//k为1的时候，判断两个数组第一位的大小返回最小值
		if(kth == 1)	return min(arr1[s1], arr2[s2]);
		//注意数组不能越界
		int idx1 = min(kth/2, e1-s1+1); int idx2 = kth - idx1;
		//分情况判断
		if(arr1[s1+idx1-1] < arr2[s2+idx2-1])	return findKth(arr1, s1+idx1, e1, arr2, s2, e2, kth-idx1);
		else if(arr1[s1+idx1-1] > arr2[s2+idx2-1])	return findKth(arr1, s1, e1, arr2, s2+idx2, e2, kth-idx2);
		else	return arr1[s1+idx1-1];
	}
public:
    int findKthNum(vector<int> arr1, vector<int> arr2, int kth) {
		int lens1 = arr1.size();
		int lens2 = arr2.size();
		return findKth(arr1, 0, lens1-1, arr2, 0, lens2-1, kth);
    }
};