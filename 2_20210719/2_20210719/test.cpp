class Solution {
public:
	int myAtoi(string s) {
		int i = 0, sign = 1, tmp = 0；        //没有符号字符时sign是正数

		while (s[i] == ' ')  ++i;              //1.忽略前导空格

		if (s[i] == '+' || s[i] == '-')        //2.确定正负号
			sign = (s[i++] == '-') ? -1 : 1;  //s[i]为+的话sign依旧为1，为-的话sign为-1

		while (s[i] >= '0' && s[i] <= '9')     //3.检查输入是否合法
		{
			if (tmp > INT_MAX / 10 || (tmp == INT_MAX / 10 && s[i] - '0' > 7)) //4.是否溢出
				return sign == 1 ? INT_MAX : INT_MIN;
			tmp = tmp * 10 + (s[i++] - '0');  //5.不加括号有溢出风险
		}
		return tmp * sign;
	}
};



class Solution {
public:
	int strToInt(string str) {
		//i用来遍历str
		int i = 0;
		//标志位
		int flag = 1;
		//处理前导空格
		while (str[i] == ' '){
			i++;
		}
		//处理'+''-'
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
			//处理溢出
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