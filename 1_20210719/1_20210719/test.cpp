class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		while (left < right){
			if (nums[left] + nums[right] == target){
				return vector<int>{nums[left], nums[right]};
			}
			else if (nums[left] + nums[right]<target){
				left++;
			}
			else if (nums[left] + nums[right]>target){
				right--;
			}
		}
		return vector<int>{};
	}
};

class Solution {
public:
	vector<vector<int>> findContinuousSequence(int target) {
		int i = 1, j = 2, s = 3;
		vector<vector<int>> res;
		while (i < j) {
			if (s == target) {
				vector<int> ans;
				for (int k = i; k <= j; k++)
					ans.push_back(k);
				res.push_back(ans);
			}
			if (s >= target) {
				s -= i;
				i++;
			}
			else {
				j++;
				s += j;
			}
		}
		return res;
	}
};

class Solution {
public:
	vector<vector<int>> findContinuousSequence(int target) {
		vector<vector<int>>vv;
		int left = 1;
		int right = 2;
		int sum = 3;
		while (left < right){
			if (sum == target){
				vector<int>v;
				for (int i = left; i < right; i++){
					v.push_back(i);
				}
				vv.push_back(v);
			}
			if (sum >= target){
				sum -= left;
				left++;
			}
			else{
				right++;
				sum += right;
			}
		}
		return vv;
	}
};



class Solution {
public:
	//双指针维护一个滑动窗口
	vector<vector<int>> findContinuousSequence(int target) {
		vector<vector<int>>vv;
		int left = 1;
		int right = 2;
		int sum = 3;
		while (left < right){
			if (sum == target){
				//临时一维数组放在循环内定义，如果放在循环外每次都需要v.clear();
				vector<int>v;
				//i<=right,否则最后一个数组加不上
				for (int i = left; i <= right; i++){
					v.push_back(i);
				}
				vv.push_back(v);
			}
			//先减sum,再left++
			if (sum >= target){
				sum -= left;
				left++;
			}
			else{
				//right先++,再加sum
				right++;
				sum += right;
			}
		}
		return vv;
	}
};


class Solution {
public:
	//双指针维护一个滑动窗口
	vector<vector<int>> findContinuousSequence(int target) {
		vector<vector<int>>vv;
		int left = 1;
		int right = 2;
		int sum = 3;
		while (left < right){
			if (sum == target){
				//临时一维数组放在循环内定义，如果放在循环外每次都需要v.clear();
				vector<int>v;
				//i<=right,否则最后一个数组加不上
				for (int i = left; i <= right; i++){
					v.push_back(i);
				}
				vv.push_back(v);
			}
			//先减sum,再left++
			if (sum >= target){
				sum -= left;
				left++;
			}
			else{
				//right先++,再加sum
				right++;
				sum += right;
			}
		}
		return vv;
	}
};
