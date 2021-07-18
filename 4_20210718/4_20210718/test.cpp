class Solution {
public:
	string reverseWords(string s) {
		// ��ת�����ַ���
		reverse(s.begin(), s.end());
		int n = s.size();
		int idx = 0;
		for (int start = 0; start < n; ++start) {
			if (s[start] != ' ') {
				// ��һ���հ��ַ�Ȼ��idx�ƶ�����һ�����ʵĿ�ͷλ��
				if (idx != 0) s[idx++] = ' ';
				// ѭ�����������ʵ�ĩβ
				int end = start;
				while (end < n && s[end] != ' ') s[idx++] = s[end++];
				// ��ת��������
				reverse(s.begin() + idx - (end - start), s.begin() + idx);
				// ����start��ȥ����һ������
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
			while (j < s.size() && s[j] == ' ') j++; //jָ���������ʵ�ǰ���ո�
			if (j == s.size()) break; //����break��Ϊ�˱�֤��󲻻�s[k++] = ' '�����һ���ո�
			i = j;
			while (j < s.size() && s[j] != ' ') j++;
			reverse(s.begin() + i, s.begin() + j);
			if (k)  s[k++] = ' '; //�����ո�
			while (i < j) s[k++] = s[i++];
		}
		s.erase(s.begin() + k, s.end());//��������Ŀո�
		reverse(s.begin(), s.end());
		return s;
	}
};


class Solution {
public:
	//˫ָ���������ת���ʣ�����ٷ�ת�����ַ���
	string reverseWords(string s) {
		int k = 0;//k�ǲ��ո�͸�ֵ�õ�
		for (int left = 0; left < s.size(); left++){
			int right = left;
			//ȥ�����ʵ�ǰ���ո�
			while (right < s.size() && s[right] == ' '){
				right++;
			}
			//��֤��󲻻�s[k++]=' '���¶��һ���ո�
			if (right == s.size()){
				break;
			}
			left = right;
			//�ҳ���������
			while (right < s.size() && s[right] != ' '){
				right++;
			}
			//��ת����
			reverse(s.begin() + left, s.begin() + right);
			//���ո񣬵�һ�����ʲ��ò�
			if (k != 0){
				s[k] = ' ';
				k++;
			}
			//����ת��ĵ������¸�ֵ��s��ǰk���ַ���kΪ���ʳ���
			while (left < right){
				s[k++] = s[left++];
			}
		}
		//��������ո�
		s.erase(s.begin() + k, s.end());
		//��ת�����ַ���
		reverse(s.begin(), s.end());
		return s;
	}
};
