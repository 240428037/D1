class Solution {
public:
    vector<int> LRU(vector<vector<int> >& operators, int k) {
        if(operators.empty()){
            return{};
        }
        vector<int>v;
        for(auto&opt:operators){
            //若opt=1，接下来两个整数x, y，表示set(x, y)
            if(opt[0]==1){
                set(opt[1],opt[2],k);
            //若opt=2，接下来一个整数x，表示get(x)，若x未出现过或已被移除，则返回-1
            //对于每个操作2，输出一个答案
            }else if(opt[0]==2){
                get(opt[1],v);
            }
        }
        return v;
    }
private:
    unordered_map<int,int>map;
    list<int>list;
    //某个key的set或get操作一旦发生，认为这个key的记录成了最常使用的。
    //当缓存的大小超过K时，移除最不经常使用的记录，即set或get最久远的。
    //
    //若opt=1，接下来两个整数x, y，表示set(x, y)
    //set(key, value)：将记录(key, value)插入该结构
    void set(int key,int value,int k){
        if(list.size()==k){
            int delkey=list.back();
            list.pop_back();
            map.erase(delkey);
        }
        map[key]=value;
        list.push_front(key);
    }
    //若opt=2，接下来一个整数x，表示get(x)，若x未出现过或已被移除，则返回-1
    //对于每个操作2，输出一个答案
    //get(key)：返回key对应的value值
    void get(int key,vector<int>&v){
        auto it=map.find(key);
        if(it==map.end()){
            v.push_back(-1);
        }else{
            v.push_back(it->second);
            list.remove(it->first);
            list.push_front(it->first);
        }
    }
};


class Solution {
public:
    //输入一个二维数组和k
    //二维数组每一维有2个或者3个数字，第一个数字为opt，第2,3个数字为key,value
    vector<int> LRU(vector<vector<int> >& operators, int k) {
        vector<int>v;
        if(operators.empty()){
            return v;
        }
        for(auto&opt:operators){
            //若opt=1,接下来两个key,value，表示set(key,value)
            if(opt[0]==1){
                set(opt[1],opt[2],k);
            //若opt=2，接下来一个整数key，表示get(key)
            //若key未出现过或者已被移除，则返回-1
            //对于每个pot=2，输出一个答案
            }else if(opt[0]==2){
                get(opt[1],v);
            }
        }
        return v;
    }
private:
    //键值对的查询，首选map，又因为本题中map只是用来查询，不涉及排序，所以采用unordered_map
    //维护最近使用元素，涉及入队和出队的概念，但因为queue只能操作头部和尾部元素，所以不适用
    //而list既满足了队头队头元素的操作，也可以对中间元素进行删除操作，所以选用list
    //list中只需要维护map中的键值key
    unordered_map<int,int>map;
    list<int>list;
    //某个key的set或者get操作一旦发生，认为这个key的记录成了最常使用的，然后都会刷新缓存
    //void set(){}
    //将记录(key,value)插入该结构
    //当缓存的大小超过k时，移除最不常使用的记录
    void set(int key,int value,int k){
        if(list.size()==k){
            int delkey=list.back();
            list.pop_back();
            map.erase(delkey);
        }
        map[key]=value;
        list.push_front(key);
    }
    //int get(){}
    //返回key对应的value值
    //若key未出现过或者已被移除，则返回-1
    //对于每个pot=2，输出一个答案
    void get(int key,vector<int>&v){
        auto it=map.find(key);
        if(it==map.end()){
            v.push_back(-1);
        }else{
            v.push_back(it->second);
            list.remove(it->first);
            list.push_front(it->first);
        }
    }
};