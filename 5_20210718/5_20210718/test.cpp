class Solution {
public:
	//����reverse�͵�������ת
	string reverseLeftWords(string s, int n) {
		//abcdefg n=2,->cdefgab
		//bacdefg
		reverse(s.begin(), s.begin() + n);
		//bagfedc
		reverse(s.begin() + n, s.begin() + s.size());
		//cdefgab
		reverse(s.begin(), s.end());
		return s;
	}
};