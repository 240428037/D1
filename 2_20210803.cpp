class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char,int> mp;
        for(auto ch:s){
            mp[ch]++;
        }
        for(auto ch:s){
            if(mp[ch]==1){
                return ch;
            }
        }
        return ' ';
    }
};


class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        unordered_map<char,int>map;
        //统计每个字符出现的次数
        for(auto ch:str){
            map[ch]++;
        }
        //找出第一个只出现一次的字符
        for(int i=0;i<str.size();i++){
            if(map[str[i]]==1){
                return i;
            }
        }
        return -1;
    }
};


class Solution {
public:
    //利用reverse和迭代器翻转
    string reverseLeftWords(string s, int n) {
        //abcdefg n=2,->cdefgab
        //bacdefg
        reverse(s.begin(),s.begin()+n);
        //bagfedc
        reverse(s.begin()+n,s.begin()+s.size());
        //cdefgab
        reverse(s.begin(),s.end());
        return s;
    }
};


class Solution {
public:
    string LeftRotateString(string str, int n) {
        //abcXYZdef
        //cbaXYZdef
        //cbafedZYX
        //XYZdefabc
        reverse(str.begin(),str.begin()+n);
        reverse(str.begin()+n,str.end());
        reverse(str.begin(),str.end());
        return str;
    }
};