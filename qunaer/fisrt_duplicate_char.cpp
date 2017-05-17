class FirstRepeat {
public:
    char findFirstRepeat(string A, int n) {
        // write code here
		set<char> tab;
		int i = 0;
		for(i=0;i<n;i++){
			if(tab.find(A[i])!=tab.end())	break;
			else	tab.insert(A[i]);
		}
		return A[i];
    }
};