class Solution {
public:
	string reverseWords(string s) {
		// 反转整个字符串
		reverse(s.begin(), s.end());
		int n = s.size();
		int idx = 0;
		for (int start = 0; start < n; ++start) {
			if (s[start] != ' ') {
				// 填一个空白字符然后将idx移动到下一个单词的开头位置
				if (idx != 0) s[idx++] = ' ';
				// 循环遍历至单词的末尾
				int end = start;
				while (end < n && s[end] != ' ') s[idx++] = s[end++];
				// 反转整个单词
				reverse(s.begin() + idx - (end - start), s.begin() + idx);
				// 更新start，去找下一个单词
				start = end;
			}
		}
		s.erase(s.begin() + idx, s.end());
		return s;
	}
};

reverse(s.begin(), s.end());
int k = 0;
for (int left = 0; left < s.size(); left++){
	if (k != 0){
		s[k++] = ' ';
	}
	int right = left;
	while (right < n&&s[right] != ' '){
		s[k++] = s[right++];
	}
	reverse(s.begin() + k - (right - left), s.begin() + k);
	left = right;
}
s.erase(s.begin() + k, s.end());
return s;


class Solution {
public:
	string reverseWords(string s) {
		int k = 0;
		for (int i = 0; i < s.size(); i++)
		{
			int j = i;
			while (j < s.size() && s[j] == ' ') j++; //j指针跳过单词的前导空格
			if (j == s.size()) break; //这里break是为了保证最后不会s[k++] = ' '，多加一个空格
			i = j;
			while (j < s.size() && s[j] != ' ') j++;
			reverse(s.begin() + i, s.begin() + j);
			if (k)  s[k++] = ' '; //补个空格
			while (i < j) s[k++] = s[i++];
		}
		s.erase(s.begin() + k, s.end());//擦除多余的空格
		reverse(s.begin(), s.end());
		return s;
	}
};


class Solution {
public:
	//双指针先逐个翻转单词，最后再翻转整个字符串
	string reverseWords(string s) {
		int k = 0;//k是补空格和赋值用的
		for (int left = 0; left < s.size(); left++){
			int right = left;
			//去掉单词的前导空格
			while (right < s.size() && s[right] == ' '){
				right++;
			}
			//保证最后不会s[k++]=' '导致多加一个空格
			if (right == s.size()){
				break;
			}
			left = right;
			//找出单词区间
			while (right < s.size() && s[right] != ' '){
				right++;
			}
			//翻转单词
			reverse(s.begin() + left, s.begin() + right);
			//补空格，第一个单词不用补
			if (k != 0){
				s[k] = ' ';
				k++;
			}
			//将翻转后的单词重新赋值给s的前k个字符，k为单词长度
			while (left < right){
				s[k++] = s[left++];
			}
		}
		//擦除多余空格
		s.erase(s.begin() + k, s.end());
		//翻转整个字符串
		reverse(s.begin(), s.end());
		return s;
	}
};
