class Solution {
public:
	int myAtoi(string s) {
		int i = 0, sign = 1, tmp = 0��        //û�з����ַ�ʱsign������

		while (s[i] == ' ')  ++i;              //1.����ǰ���ո�

		if (s[i] == '+' || s[i] == '-')        //2.ȷ��������
			sign = (s[i++] == '-') ? -1 : 1;  //s[i]Ϊ+�Ļ�sign����Ϊ1��Ϊ-�Ļ�signΪ-1

		while (s[i] >= '0' && s[i] <= '9')     //3.��������Ƿ�Ϸ�
		{
			if (tmp > INT_MAX / 10 || (tmp == INT_MAX / 10 && s[i] - '0' > 7)) //4.�Ƿ����
				return sign == 1 ? INT_MAX : INT_MIN;
			tmp = tmp * 10 + (s[i++] - '0');  //5.�����������������
		}
		return tmp * sign;
	}
};



class Solution {
public:
	int strToInt(string str) {
		//i��������str
		int i = 0;
		//��־λ
		int flag = 1;
		//����ǰ���ո�
		while (str[i] == ' '){
			i++;
		}
		//����'+''-'
		if (str[i] == '+'){
			flag = 1;
			str[i] = '0';
		}
		if (str[i] == '-'){
			flag = -1;
			str[i] = '0';
		}
		//string->int
		long long sum = 0;
		while (str[i] >= '0'&&str[i] <= '9'){
			sum = sum * 10 + str[i] - '0';
			i++;
			//�������
			if (sum > INT_MAX&&flag == 1){
				return INT_MAX;
			}
			else if (-sum < INT_MIN&&flag == -1){
				return INT_MIN;
			}
		}
		return sum*flag;
	}
};