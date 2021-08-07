#include<iostream>
using namespace std;
int check1(){
    int a = 1;
    return *(char*)&a;
}
int check2(){
    union un
    {
        char c;
        int i;
    }un;
    un.i = 1;
    return un.c;
}
int main(){
    int ret = check2();
    if (1 == ret){
        cout << "小端" << endl;
    }
    else{
        cout << "大端" << endl;
    }
    return 0;
}