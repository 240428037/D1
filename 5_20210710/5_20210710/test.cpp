class Solution {
public:
	void shellsort(vector<int>&nums){
		int n = nums.size();
		//gap>1为预排序-接近有序
		//gap=1为插排-有序
		int gap = n;
		while (gap > 1){
			gap = gap / 3 + 1;//+1是为了确保最后一次gap一定为1
			for (int i = 0; i<n - gap; i++){
				int end = i;
				int tmp = nums[end + gap];
				while (end >= 0){
					if (nums[end]>tmp){
						nums[end + gap] = nums[end];
						end -= gap;
					}
					else{
						break;
					}
				}
				nums[end + gap] = tmp;
			}
		}
	}
	vector<int> sortArray(vector<int>& nums) {
		shellsort(nums);
		return nums;
	}
};


class Solution {
public:
	void insertsort(vector<int>&nums){
		int n = nums.size();
		for (int i = 0; i<n - 2; i++){
			int end = i;
			int tmp = nums[end + 1];
			while (end >= 0){
				if (nums[end]>tmp){
					nums[end + 1] = nums[end];
					end--;
				}
				else{
					break;
				}
			}
			nums[end + 1] = tmp;
		}
	}
	vector<int> sortArray(vector<int>& nums) {
		insertsort(nums);
		return nums;
	}
};