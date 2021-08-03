class Solution {
public:
    string replaceSpace(string s) {
        //统计空格个数
        int count=0;
        for(auto&ch:s){
            if(ch==' '){
                count++;
            }
        }
        //s.resize
        int length=s.size();
        s.resize(length+2*count);
        //开始替换
        //i指向源字符串尾部元素，j指向新字符串尾部元素
        //当i=j时跳出循环，表示已经没有空格
        for(int i=length-1,j=s.size()-1;i<j;i--,j--){
            if(s[i]!=' '){
                s[j]=s[i];
            }else{
                //%20
                s[j-2]='%';
                s[j-1]='2';
                s[j]='0';
                //如果发生替换，j总共要减3，循环内部减2，因为for迭代条件有j--;
                j-=2;
            }
        }
        return s;
    }
};


class Solution {
public:
    string replaceSpace(string s) {
        int count=0;
        for(auto ch:s){
            if(ch==' '){
                count++;
            }
        }
        int length=s.size();
        s.resize(length+count*2);
        for(int i=length-1,j=s.size()-1;i<j;i--,j--){
            if(s[i]!=' '){
                s[j]=s[i];
            }else{
                s[j-2]='%';
                s[j-1]='2';
                s[j]='0';
                j-=2;
            }
        }
        return s;
    }
};

class Solution {
public:
    string replaceSpace(string s) {
        if(s.empty()){
            return "";
        }
        //1.用count统计空格个数
        int count=0;
        for(auto ch:s){
            if(ch==' '){
                count++;
            }
        }
        //2.为s重新开空间
        int length=s.size();
        s.resize(length+count*2);
        //3.开始替换
        //i指向源字符串末尾，j指向resize后字符串末尾
        //循环控制条件为i<j.当i==j，说明空格已经全部替换完了，跳出循环
        for(int i=length-1,j=s.size()-1;i<j;i--,j--){
            if(s[i]!=' '){
                s[j]=s[i];
            }else{
                s[j-2]='%';
                s[j-1]='2';
                s[j]='0';
                //循环控制条件本身包含j--,所以只需要j-=2;
                j-=2;
            }
        }
        return s;
    }
};