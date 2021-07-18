class Solution {
public:
	int minArray(vector<int>& numbers) {
		int left = 0;
		int right = numbers.size() - 1;
		while (left < right){
			int mid = (left + right) >> 1;
			if (numbers[mid]<numbers[right]){
				right = mid;
			}
			else if (numbers[mid]>numbers[right]){
				left = mid + 1;
			}
			else{
				right--;
			}
		}
		return numbers[left];
	}
};


class Solution {
public:
	vector<int> exchange(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;
		while (left < right){
			while (left < right && (nums[left] % 2 == 1)){
				left++;
			}
			while (left < right && (nums[right] % 2 == 0)){
				right--;
			}
			swap(nums[left], nums[right]);
		}
		return nums;
	}
};



class Solution {
public:
	int majorityElement(vector<int>& nums) {
		if (nums.empty()){
			return 0;
		}
		int result = nums[0];
		int times = 1;
		for (int i = 1; i < nums.size(); i++){
			if (times == 0){
				result = nums[i];
				times = 1;
			}
			else{
				if (result == nums[i]){
					times++;
				}
				else{
					times--;
				}
			}
		}
		int count = 0;
		for (int i = 0; i<nums.size(); i++){
			if (result == nums[i]){
				count++;
			}
		}
		return count>nums.size() / 2 ? result : 0;
	}
};