class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return {};
        }

        int rows = matrix.size(), columns = matrix[0].size();
        vector<int> order;
        int left = 0, right = columns - 1, top = 0, bottom = rows - 1;
        while (left <= right && top <= bottom) {
            for (int column = left; column <= right; column++) {
                order.push_back(matrix[top][column]);
            }
            for (int row = top + 1; row <= bottom; row++) {
                order.push_back(matrix[row][right]);
            }
            if (left < right && top < bottom) {
                for (int column = right - 1; column > left; column--) {
                    order.push_back(matrix[bottom][column]);
                }
                for (int row = bottom; row > top; row--) {
                    order.push_back(matrix[row][left]);
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return order;
    }
};


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        vector<int> res;
        if(a.size()==0 || a[0].size()==0) return res;
        int rows = a.size(), cols = a[0].size();
        int l=0, r=cols-1, u=0, d=rows-1;
        while(1)
        {
            for(int j=l; j<=r; j++) res.push_back(a[u][j]);     //从左到右
            u++; if(u > d) break;
            
            for(int i=u; i<=d; i++) res.push_back(a[i][r]);     //从上到下
            r--; if(l > r) break;

            for(int j=r; j>=l; j--) res.push_back(a[d][j]);     //从右到左
            d--; if(u > d) break;

            for(int i=d; i>=u; i--) res.push_back(a[i][l]);     //从下到上
            l++; if(l > r) break;
        }
        return res;
    }
};


class Solution {
public:
    int add(int a, int b) {
        while (b) {
            // 无进位求和
            int not_carry = a ^ b;
            // 求进位数（这里负数会报错，转成无符号）
            // 求出的进位数要左移一位，
            // 例如：进位数是1，左移一位才是10
            int carry = ((unsigned int)(a & b) << 1);
            // 一直循环，直到不需要进位为止
            a = not_carry;
            b = carry;
        }
        return a;
    }
};


class Solution {
public:
    int add(int a, int b) {
        if (a == 0 || b == 0) {
            return a == 0 ? b : a;
        }

        int sum = 0, carry = 0;

        while (b != 0) { // 当没有进位的时候退出循环
            sum = a ^ b; 
            carry = (unsigned int) (a & b) << 1; // C++ 不允许负数进行左移操作，故要加 unsigned int

            a = sum;
            b = carry;
        }

        return a;
    }
};

class Solution {
public:
    int add(int a, int b) {
        if (b == 0) {
            return a;
        }

        int sum = a ^ b;
        int carry = (unsigned int) (a & b) << 1;

        a = sum;
        b = carry;

        return add(a, b);
    }
};


class Solution {
public:
    int Add(int num1, int num2) {
        if(num1==0||num2==0){
            return num1==0?num2:num1;
        }
        //没有进位的时候退出循环
        while(num2){
            int sum=num1^num2;
            //cpp不允许负数进行左移操作，强转成无符号数
            int carry=(unsigned int)((num1&num2)<<1);
            num1=sum;
            num2=carry;
        }
        return num1;
    }
};