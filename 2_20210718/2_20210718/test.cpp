class Solution {
public:
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
		//matrix[i][j],�����½ǿ�ʼ��
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
		//����whileѭ����Ҳ����˵�л������ߵ���ͷ����û�ҵ�return false;
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
		//ͳ�ƿո����
		int count = 0;
		for (auto&ch : s){
			if (ch == ' '){
				count++;
			}
		}
		//s.resize
		int length = s.size();
		s.resize(length + 2 * count);
		//��ʼ�滻
		//iָ��Դ�ַ���β��Ԫ�أ�jָ�����ַ���β��Ԫ��
		//��i=jʱ����ѭ������ʾ�Ѿ�û�пո�
		for (int i = length - 1, j = s.size() - 1; i < j; i--, j--){
			if (s[i] != ' '){
				s[j] = s[i];
			}
			else{
				//%20
				s[j - 2] = '%';
				s[j - 1] = '2';
				s[j] = '0';
				//��������滻��j�ܹ�Ҫ��3��ѭ���ڲ���2����Ϊfor����������j--;
				j -= 2;
			}
		}
		return s;
	}
};