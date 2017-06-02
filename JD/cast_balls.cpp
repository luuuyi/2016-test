//方案一
//模拟小球的运动轨迹来求值，注意必须用double来做
//用int来做的话会使得最终结果不精准
class Balls {
private:
	//运动轨迹为x+x*（1 + 1/2 + ... + 1/2^m）
	double calcu(double x){
		double ret = x;
		while(x>0.0000000001){
			ret += x;
			x /= 2;
		}
		return ret;
	}
public:
    int calcDistance(int A, int B, int C, int D) {
        // write code here
		double ret = 0;
		ret += calcu(A);
		ret += calcu(B);
		ret += calcu(C);
		ret += calcu(D);
		return (int)ret;
    }
};

//根据运动轨迹的方程
//x+x*（1 + 1/2 + ... + 1/2^m）
//可以推算出结果为
//fun(x) = 3*x
class Balls {
public:
    int calcDistance(int A, int B, int C, int D) {
        // write code here
		return (A+B+C+D)*3;
    }
};