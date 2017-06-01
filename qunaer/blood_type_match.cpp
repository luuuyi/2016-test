//很简单的一个题，根据题目提示用一个表存储血型配对的后代可能血型就好了；
//注意父母血型交换结果不变，所以按字典序来组合会比较方便
class ChkBloodType {
private:
	//初始化函数，初始化一个table
	map<vector<string>, vector<string>> init(){
		return map<vector<string>, vector<string>>({
			{{"O","O"},{"O"}},
			{{"A","O"},{"A","O"}},
			{{"A","A"},{"A","O"}},
			{{"A","B"},{"A","AB","B","O"}},
			{{"A","AB"},{"A","AB","B"}},
			{{"B","O"},{"B","O"}},
			{{"B","B"},{"B","O"}},
			{{"AB","B"},{"A","AB","B"}},
			{{"AB","O"},{"A","B"}},
			{{"AB","AB"},{"A","AB","B"}}
		});
	}
public:
    vector<string> chkBlood(string father, string mother) {
        // write code here
		map<vector<string>, vector<string>> table = init();
		//按字典序来组合
		if(father.compare(mother) <= 0)	return table[vector<string>({father, mother})];
		else	return table[vector<string>({mother, father})];
    }
};