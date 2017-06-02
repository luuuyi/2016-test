//递归的思想
//明白该思想需要找到f(n)与f(n-1)与f(n-2)的关系
class GrayCode {
public:
    vector<string> getGray(int n) {
        // write code here
        if(n==1){
            vector<string> ret;
            ret.push_back("0");
            ret.push_back("1");
            return ret;
        }
        vector<string> gray_code = getGray(n-1);
        int lens = gray_code.size();
        vector<string> ret;
        for(int i=0;i<lens;i++){
            ret.push_back("0" + gray_code[i]);
        }
        for(int i=lens-1;i>=0;i--){
            ret.push_back("1" + gray_code[i]);
        }
        return ret;
    }
};

//思路二
//利用公式G(n) =  n XOR (n/2)，求得gray码的十进制之后再转换成二进制字符串
class GrayCode {
public:
    string getbinarystr(int num, int n){
        string binarystr = "";
        while(num){
            int remain = num % 2;
            stringstream ss;
            ss << remain;
            string remainstr;
            ss >> remainstr;
            binarystr = remainstr + binarystr;
            num = num / 2;
            n--;
        }
        while(n--)
            binarystr = "0" + binarystr;
        return binarystr;
    }
    vector<string> getGray(int n) {
        // write code here
        int pown = pow(2, n);
        vector<string> gray;
        for(int i = 0; i < pown; i++){
            int graynum = i ^ (i/2);
            string graystr = getbinarystr(graynum,n);
            gray.push_back(graystr);
        }
        return gray;
    }
};