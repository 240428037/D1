class Solution {
public:
    //挖坑法
    int partsort(vector<int>&arr,int left,int right){
        int key=arr[right];//右边作key,挖一个坑
        while(left<right){
            //左边找大先走
            while(left<right&&arr[left]<=key){
                left++;
            }
            //找到了，填右边的坑
            arr[right]=arr[left];
            //右边找小后走
            while(left<right&&arr[right]>=key){
                right--;
            }
            //找到了，填左边的坑
            arr[left]=arr[right];
        }
        //填最后一个坑
        arr[left]=key;
        return left;
    }
    void quicksort(vector<int>&arr,int left,int right){
        //递归终止条件 
        if(left>right){
            return;
        }
        int pos=partsort(arr,left,right);
        //[left,pos-1],pos,[pos+1,right]
        //递归
        quicksort(arr,left,pos-1);
        quicksort(arr,pos+1,right);
    }
    vector<int> MySort(vector<int>& arr) {
        int left=0;
        int right=arr.size()-1;
        quicksort(arr,left,right);
        return arr;
    }
};



class Solution {
public:
    int partsort(vector<int>&arr,int left,int right){
        int key=arr[right];
        while(left<right){
            while(left<right&&arr[left]<=key){
                left++;
            }
            arr[right]=arr[left];
            while(left<right&&arr[right]>=key){
                right--;
            }
            arr[left]=arr[right];
        }
        arr[left]=key;
        return left;
    }
    void quicksort(vector<int>&arr,int left,int right){
        stack<int>st;
        st.push(left);
        st.push(right);
        while(!st.empty()){
            int right=st.top();
            st.pop();
            int left=st.top();
            st.pop();
            int pos=partsort(arr,left,right);
            if(left<pos-1){
                st.push(left);
                st.push(pos-1);
            }
            if(pos+1<right){
                st.push(pos+1);
                st.push(right);
            }
        }
    }
    vector<int> MySort(vector<int>& arr) {
        int left=0;
        int right=arr.size()-1;
        quicksort(arr,left,right);
        return arr;
    }
};


class Solution {
public:
    //挖坑法
    //将区间按照key划分为左右两半
    int partsort(vector<int>&nums,int left,int right){
        int key=nums[right];//右边作key
        while(left<right){
            //左边先走找小
            while(left<right&&nums[left]<=key){
                left++;
            }
            nums[right]=nums[left];
            //右边后走找大
            while(left<right&&nums[right]>=key){
                right--;
            }
            nums[left]=nums[right];
        }
        //把key给左边
        nums[left]=key;
        return left;
    }
    //快排递归
    void quicksort1(vector<int>&nums,int left,int right){
        //递归终止条件
        if(left>right){
            return;
        }
        int pos=partsort(nums,left,right);
        //[left,pos-1],pos,[pos+1,right]
        quicksort1(nums,left,pos-1);
        quicksort1(nums,pos+1,right);
    }
    //快排非递归
    void quicksort2(vector<int>&nums,int left,int right){
        stack<int>st;
        st.push(left);
        st.push(right);
        while(!st.empty()){
            int right=st.top();
            st.pop();
            int left=st.top();
            st.pop();
            //挖坑法
            int pos=partsort(nums,left,right);
            //[left,pos-1],pos,[pos+1,right]
            if(left<pos-1){
                st.push(left);
                st.push(pos-1);
            }
            if(pos+1<right){
                st.push(pos+1);
                st.push(right);
            }
        }
    }
    vector<int> MySort(vector<int>& arr) {
        int left=0;
        int right=arr.size()-1;//数组需要下标,-1
        quicksort1(arr,left,right);
        return arr;
    }
};



class Solution {
public:
    //向下调整算法，把堆调为大堆
    void adjustdown(vector<int>&arr,int n,int root){
        int parent=root;
        int child=parent*2+1;
        while(child<n){
            //选出左右孩子中较大的那一个
            if(child+1<n&&arr[child+1]>arr[child]){
                child++;
            }
            //如果孩子比父亲大，交换，继续向下调整
            if(arr[child]>arr[parent]){
                swap(arr[child],arr[parent]);
                parent=child;
                child=parent*2+1;
            }else{
                //如果孩子小于父亲，则调整结束
                break;
            }
        }
    }
    void heapsort(vector<int>&arr,int n){
        //堆排升序建大堆
        //建堆
        //使用adjustdown从倒数第一个非叶子节点的子树开始调整，一直调整到根节点的树，就可以建为堆
        for(int i=((n-1)-1)/2;i>=0;i--){
            adjustdown(arr,n,i);
        }
        //交换然后继续调堆
        for(int end=n-1;end>=0;end--){
            swap(arr[0],arr[end]);
            adjustdown(arr,end,0);
        }
    }
    vector<int> MySort(vector<int>& arr) {
        int n=arr.size();
        heapsort(arr,n);
        return arr;
    }
};


class Solution {
public:
    //向下调整算法
    void adjustdown(vector<int>&nums,int n,int root){
        int parent=root;
        int child=parent*2+1;
        while(child<n){
            //1.选出左右两个孩子中较大的那一个
            if(child+1<n&&nums[child+1]>nums[child]){
                child++;
            }
            //2.如果孩子比父亲大，则交换，继续向下调整
            if(nums[child]>nums[parent]){
                swap(nums[child],nums[parent]);
                //迭代parent和child,继续向下调整
                parent=child;
                child=parent*2+1;
            }else{
                break;//如果孩子小于父亲则调整结束
            }
        }
    }
    //两个for循环
    //一个建堆,n=nums.size(),root=i;迭代root
    //一个交换然后调堆,n=i,root=0;迭代n
    void heapsort(vector<int>&nums,int n){
        //使用向下调整算法建一个大堆
        //从倒数第一个非叶子节点的子树开始调整，
        //一直调整到根节点的树,就可以建为大堆
        for(int i=((n-1)-1)/2;i>=0;i--){
            adjustdown(nums,n,i);//n=nums.size(),root=i;迭代root
        }
        //取出堆顶元素和最后一个元素交换，然后再调为大堆
        for(int i=n-1;i>=0;i--){
            swap(nums[0],nums[i]);
            adjustdown(nums,i,0);//n=i,root=0;迭代n
        }
    }
    vector<int> MySort(vector<int>& arr) {
        int n=arr.size();//和快排相反，不减1
        heapsort(arr,n);
        return arr;
    }
};


class Solution {
public:
    void mergesort(vector<int>&nums,vector<int>&tmp,int left,int right){
        //递归的终止条件
        if(left>=right){
            return;
        }
        int mid=(left+right)>>1;
        mergesort(nums,tmp,left,mid);
        mergesort(nums,tmp,mid+1,right);
        int left1=left;
        int left2=mid+1;
        int k=left;
        //合并两个有序的子序列
        while(left1<=mid&&left2<=right){
            if(nums[left1]<nums[left2]){
                tmp[k++]=nums[left1++];
            }else{
                tmp[k++]=nums[left2++];
            }
        }
        while(left1<=mid){
            tmp[k++]=nums[left1++];
        }
        while(left2<=right){
            tmp[k++]=nums[left2++];
        }
        //tmp为临时数组-将tmp拷回nums
        for(int k=left;k<=right;k++){
            nums[k]=tmp[k];
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>tmp(n);
        int left=0;
        int right=n-1;
        mergesort(nums,tmp,left,right);
        return nums;
    }
};


class string{
public:
    /构造
    string(const char*str=""){
        if(str==nullptr){
            str="";
        }
        _str=new char[strlen(str)+1];
        strcpy(_str,str);
    }
    //析构
    ~string(){
        if(_str){
            delete[] _str;
            _str=nullptr;
        }
    }
    //拷贝构造
    string(const string&s):_str(nullptr){
        string strtmp(s._str);
        swap(_str,strtmp);
    }
    //赋值运算符重载
    string& operator=(string s){
        swap(_str,s._str);
        return *this;
    }
private:
    char* _str;
};