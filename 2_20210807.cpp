    //分割字符串
    //Cookie：SESSION_ID-12312535; NAME=zhangsan; path=/
    static int Split(const string &str,const string &sep,vector<string>*list){
      //string::substr()，从pos位置开始截取指定长度字符串
      //string::find()，从pos位置开始找_s分隔符，返回所在位置
      int count=0;
      size_t pos=0,idx=0;//idx起始找寻位置
      while(1){
        pos=str.find(sep,idx);//从str字符串的idx位置开始找sep分隔符
        if(pos==string::npos){
          break;
        }
        list->push_back(str.substr(idx,pos-idx));
        idx=pos+sep.size();
        count++;
      }
      if(idx<str.size()){
        list->push_back(str.substr(idx));
        count++;
      }
      return count;
    }


    int split(const string&str,const string &sep,vector<string>*list){
        int count=0;
        int pos=0;
        int idx=0;
        while(1){
            pos=str.find(sep.idx);
            if(pos==){

            }
            list
        }
    }


    class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        //一上来先考虑特殊情况
        if(k==0){
            return{};
        }
        //对v进行初始化
        vector<int>v(k,0);
        priority_queue<int>q;//优先级队列
        //向q中插入input中下标从0到k-1的k个数
        for(int i=0;i<k;i++){
            q.push(input[i]);
        }
        //i从k开始，逐一与堆顶元素比较，如果比堆顶元素小，则交换
        for(int i=k;i<(int)input.size();i++){
            if(q.top()>input[i]){
                q.pop();
                q.push(input[i]);
            }
        }
        //把q中元素赋值给v
        for(int i=0;i<k;i++){
            v[i]=q.top();
            q.pop();
        }
        return v;
    }
};



class Solution {
public:
    //解题思路
    //使用优先级队列，q默认为大堆
    //将input的前k个元素插入q,k个数的大堆
    //然后i从k开始，input剩下的元素逐一与堆顶元素进行比较
    //如果堆顶元素大于该元素，则替换，然后继续向后迭代
    //遍历完input数组后
    //将q中的元素插入v中，最后return v;
    //vector<int>xxx(vector<int>input,int k){}
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int>v;
        if(k==0){
            return v;
        }
        priority_queue<int>q;
        //1.取input数组中前k个数建一个包含k个数的大堆
        for(int i=0;i<k;i++){
            q.push(input[i]);
        }
        //2.从下标为k的位置开始遍历input数组，如果小于堆顶元素，则替换
        for(int i=k;i<input.size();i++){
            if(q.top()>input[i]){
                q.pop();
                q.push(input[i]);
            }
        }
        //3.将q中的元素插入到v中返回
        for(int i=0;i<k;i++){
            v.push_back(q.top());
            q.pop();
        }
        return v;
    }
};



int getmid(vector<int>&nums, int left, int right){
               int mid = (left + right) >> 1;
               //1-left<mid
               if (nums[left] < nums[mid]){
                       //1.1-right left mid
                       if (nums[right] < nums[left]){
                              return left;
                              //1.2-left mid right
                       }
                       else if (nums[mid] < nums[right]){
                              return mid;
                       }
                       else{//1.3-left right mid
                              return right;
                       }
               }
               else{//2-mid<left
                       //2.1-right mid left
                       if (nums[right] < nums[mid]){
                              return mid;
                              //2.2-mid left right
                       }
                       else if (nums[left] < nums[right]){
                              return left;
                       }
                       else{//2.3-mid right left
                              return right;
                       }
               }
        }



        class Solution {
public:
    int getmid(vector<int>&nums,int left,int right){
        int mid=(left+right)/2;
        //left mid
        if(nums[left]<nums[mid]){
            if(nums[right]<nums[left]){
                return left;
            }else if(nums[mid]<nums[right]){
                return mid;
            }else{
                return right;
            }
        //mid left
        }else{
            if(nums[right]<nums[mid]){
                return mid;
            }else if(nums[left]<nums[right]){
                return left;
            }else{
                return right;
            }
        }
    }
    int partsort(vector<int>&nums,int left,int right){
        int mid=getmid(nums,left,right);
        swap(nums[mid],nums[right]);
        int key=nums[right];
        while(left<right){
            while(left<right&&nums[left]<=key){
                left++;
            }
            nums[right]=nums[left];
            while(left<right&&nums[right]>=key){
                right--;
            }
            nums[left]=nums[right];
        }
        nums[left]=key;
        return left;
    }
    void quicksort(vector<int>&nums,int left,int right){
        if(left>=right){
            return;
        }
        int pos=partsort(nums,left,right);
        quicksort(nums,left,pos-1);
        quicksort(nums,pos+1,right);
    }
    int findKth(vector<int> a, int n, int K) {
        quicksort(a,0,n-1);
        return a[K-1];
    }
};