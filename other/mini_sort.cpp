//用先sort一遍的方法来做
//时间复杂度为排序的时间复杂度，大概是O(nlgn)
//理解错题目了，以为是求出所有需要排序的子区间里面最小的那个
class ShortSubsequence {
public:
    int findShortest(vector<int> A, int n) {
        // write code here
		vector<int> tmp(A);
		sort(tmp.begin(), tmp.end());
		int lens = A.size();
		int sum = 0, min_val = 0x7fffffff;
		for(int i=0;i<lens;i++){
			//如果排序后与排序前相等，判断sum是否是最小值，然后将sum置为0
			if(A[i] == tmp[i]){
				if(sum != 0)	min_val = min(min_val, sum);
				sum = 0;
			}
			//排序后和排序前不相等证明该位置需要排序，sum += 1
			else	sum++;
		}
		//别忘了最后一串待排序的统计值
		if(sum != 0)	min_val = min(min_val, sum);
		return min_val==0x7fffffff?0:min_val;
    }
};

//正确做法，非动态规划解法
//借助一个已经排序的数组，从左右两边不断往中间寻找第一个不同点
class ShortSubsequence {
public:
    int findShortest(vector<int> A, int n) {
        // write code here
		vector<int> tmp(A);
		sort(tmp.begin(), tmp.end());
		int lens = A.size();
		int left = 0, right = lens-1;
		while(left <= right){
			//找寻左右两边的第一个不同点
			if(A[left]==tmp[left] && A[right]==tmp[right]){	left++; right--;}
			else if(A[left]!=tmp[left] && A[right]!=tmp[right])	break;
			else if(A[left]==tmp[left] && A[right]!=tmp[right])	left++;
			else	right--;
		}
		//返回中间的区间大小
		return	right>=left?right-left+1:0;
    }
};

