class Solution {
public:
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
		//matrix[i][j],从左下角开始找
		int i = matrix.size() - 1;
		int j = 0;
		while (i >= 0 && j < matrix[0].size()){
			if (matrix[i][j]<target){
				j++;
			}
			else if (matrix[i][j]>target){
				i--;
			}
			else{
				return true;
			}
		}
		//出了while循环，也就是说行或者列走到尽头，还没找到return false;
		return false;
	}
};


class Solution {
public:
	string replaceSpace(string s) {
		string str;
		for (auto&ch : s){
			if (ch == ' '){
				str += "%20";
			}
			else{
				str += ch;
			}
		}
		return str;
	}
};



class Solution {
public:
	string replaceSpace(string s) {
		//统计空格个数
		int count = 0;
		for (auto&ch : s){
			if (ch == ' '){
				count++;
			}
		}
		//s.resize
		int length = s.size();
		s.resize(length + 2 * count);
		//开始替换
		//i指向源字符串尾部元素，j指向新字符串尾部元素
		//当i=j时跳出循环，表示已经没有空格
		for (int i = length - 1, j = s.size() - 1; i < j; i--, j--){
			if (s[i] != ' '){
				s[j] = s[i];
			}
			else{
				//%20
				s[j - 2] = '%';
				s[j - 1] = '2';
				s[j] = '0';
				//如果发生替换，j总共要减3，循环内部减2，因为for迭代条件有j--;
				j -= 2;
			}
		}
		return s;
	}
};