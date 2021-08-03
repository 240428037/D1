class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        int pos1 = -1;
        while(left <= right) {
            int mid = (left + right) / 2;

            if(nums[mid] == target)
                pos1 = mid;

            if(nums[mid] >= target)
                right = mid - 1;
            else if(nums[mid] < target)
                left = mid + 1;
        }
        if(pos1 == -1)
            return 0;
        
        left = 0, right = n - 1;
        int pos2 = n;
        while(left <= right) {
            int mid = (left + right) / 2;

            if(nums[mid] > target)
                pos2 = mid;
            
            if(nums[mid] > target)
                right = mid - 1;
            else if(nums[mid] <= target)
                left = mid + 1;
        }
        return pos2 - pos1;
    }
};


class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int left=0;
        int right=data.size()-1;
        int pos1=-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(data[mid]==k){
                pos1=mid;
            }
            if(data[mid]>=k){
                right=mid-1;
            }else if(data[mid]<k){
                left=mid+1;
            }
        }
        if(pos1==-1){
            return 0;
        }
        left=0;
        right=data.size()-1;
        int pos2=data.size();
        while(left<=right){
            int mid=(left+right)/2;
            if(data[mid]>k){
                pos2=mid;
            }
            if(data[mid]>k){
                right=mid-1;
            }else if(data[mid]<=k){
                left=mid+1;
            }
        }
        return pos2-pos1;
    }
};