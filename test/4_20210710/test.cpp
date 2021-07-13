class Solution {
public:
	int partsort2(vector<int>&nums, int left, int right){
		int key = nums[right];
		while (left < right){
			while (left < right&&nums[left] <= key){
				left++;
			}
			//左边坑出来了
			nums[right] = nums[left];
			while (left < right&&nums[right] >= key){
				right--;
			}
			//右边坑出来了
			nums[left] = nums[right];
		}
		nums[left] = key;
		return left;
	}
	void quicksort(vector<int>&nums, int left, int right){
		//递归终止条件
		if (left >= right){
			return;
		}
		int pos = partsort2(nums, left, right);
		quicksort(nums, left, pos - 1);
		quicksort(nums, pos + 1, right);
	}
	vector<int> sortArray(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;
		quicksort(nums, left, right);
		return nums;
	}
};




class Solution {
public:
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
	int partsort2(vector<int>&nums, int left, int right){
		int mid = getmid(nums, left, right);
		swap(nums[mid], nums[right]);
		int key = nums[right];
		while (left < right){
			while (left < right&&nums[left] <= key){
				left++;
			}
			//左边坑出来了
			nums[right] = nums[left];
			while (left < right&&nums[right] >= key){
				right--;
			}
			//右边坑出来了
			nums[left] = nums[right];
		}
		nums[left] = key;
		return left;
	}
	void quicksort(vector<int>&nums, int left, int right){
		//递归终止条件
		if (left >= right){
			return;
		}
		int pos = partsort2(nums, left, right);
		quicksort(nums, left, pos - 1);
		quicksort(nums, pos + 1, right);
	}
	vector<int> sortArray(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;
		quicksort(nums, left, right);
		return nums;
	}
};


//前后指针法
int partsort3(vector<int>&nums, int left, int right){
	int prev = left - 1;
	int cur = left;
	int mid = getmid(nums, left, right);
	swap(nums[right], nums[mid]);
	int key = nums[right];
	while (cur < right){
		if (nums[cur] < key&&prev++ != cur){
			swap(nums[prev], nums[cur]);
		}
		cur++;
	}
	prev++;
	swap(nums[prev], nums[right]);
	return prev;
}


//挖坑法
int partsort2(vector<int>&nums, int left, int right){
	int mid = getmid(nums, left, right);
	swap(nums[right], nums[mid]);
	int key = nums[right];
	while (left < right){
		while (left < right&&nums[left] <= key){
			left++;
		}
		nums[right] = nums[left];
		while (left < right&&nums[right] >= key){
			right--;
		}
		nums[left] = nums[right];
	}
	nums[left] = key;
	return left;
}


//左右指针法
int partsort1(vector<int>&nums, int left, int right){
	int mid = getmid(nums, left, right);
	swap(nums[right], nums[mid]);
	int key = nums[right];
	int keyindex = right;
	while (left < right){
		while (left < right&&nums[left] <= key){
			left++;
		}
		while (left < right&&nums[right] >= key){
			right--;
		}
		swap(nums[left], nums[right]);
	}
	swap(nums[left], nums[keyindex]);
	return left;
}



class Solution {
public:
	void quicksort(vector<int>&nums, int left, int right){
		if (left >= right){
			return;
		}
		int pos = partsort3(nums, left, right);
		quicksort(nums, left, pos - 1);
		quicksort(nums, pos + 1, right);
	}
	//挖坑法
	int partsort2(vector<int>&nums, int left, int right){
		int mid = getmid(nums, left, right);
		swap(nums[right], nums[mid]);
		int key = nums[right];
		while (left < right){
			while (left < right&&nums[left] <= key){
				left++;
			}
			nums[right] = nums[left];
			while (left < right&&nums[right] >= key){
				right--;
			}
			nums[left] = nums[right];
		}
		nums[left] = key;
		return left;
	}
	//左右指针法
	int partsort1(vector<int>&nums, int left, int right){
		int mid = getmid(nums, left, right);
		swap(nums[right], nums[mid]);
		int key = nums[right];
		int keyindex = right;
		while (left < right){
			while (left < right&&nums[left] <= key){
				left++;
			}
			while (left < right&&nums[right] >= key){
				right--;
			}
			swap(nums[left], nums[right]);
		}
		swap(nums[left], nums[keyindex]);
		return left;
	}
	//前后指针法
	int partsort3(vector<int>&nums, int left, int right){
		int prev = left - 1;
		int cur = left;
		int mid = getmid(nums, left, right);
		swap(nums[right], nums[mid]);
		int key = nums[right];
		while (cur < right){
			if (nums[cur] < key&&prev++ != cur){
				swap(nums[prev], nums[cur]);
			}
			cur++;
		}
		prev++;
		swap(nums[prev], nums[right]);
		return prev;
	}
	//三数取中法选key
	int getmid(vector<int>&nums, int left, int right){
		//left mid right
		int mid = (left + right) >> 1;
		//left<mid
		if (nums[left] < nums[mid]){
			//right left mid
			if (nums[right] < nums[left]){
				return left;
			}
			//left mid right
			else if (nums[mid] < nums[right]){
				return mid;
			}
			//left right mid
			else{
				return right;
			}
		}
		//mid<left
		else{
			//right mid left
			if (nums[right] < nums[mid]){
				return mid;
			}
			//mid left right
			else if (nums[left] < nums[right]){
				return left;
			}
			//mid right left
			else{
				return right;
			}
		}
	}
	//快排非递归
	void quicksortstack(vector<int>&nums, int left, int right){
		stack<int>st;
		st.push(left);
		st.push(right);
		while (!st.empty()){
			int right = st.top();
			st.pop();
			int left = st.top();
			st.pop();
			int pos = partsort2(nums, left, right);
			if (left < pos - 1){
				st.push(left);
				st.push(pos - 1);
			}
			if (pos + 1 < right){
				st.push(pos + 1);
				st.push(right);
			}
		}
	}
	vector<int> sortArray(vector<int>& nums) {
		int left = 0, right = nums.size() - 1;
		quicksort(nums, left, right);
		//quicksortstack(nums,left,right);
		return nums;
	}
};



class Solution {
public:
	int partsort2(vector<int>&nums, int left, int right){
		int key = nums[right];
		while (left < right){
			while (left < right&&nums[left] <= key){
				left++;
			}
			//左边坑出来了
			nums[right] = nums[left];
			while (left < right&&nums[right] >= key){
				right--;
			}
			//右边坑出来了
			nums[left] = nums[right];
		}
		nums[left] = key;
		return left;
	}
	void quicksortstack(vector<int>&nums, int left, int right){
		stack<int>st;
		st.push(left);
		st.push(right);
		while (!st.empty()){
			int right = st.top();
			st.pop();
			int left = st.top();
			st.pop();
			int pos = partsort2(nums, left, right);
			if (left < pos - 1){
				st.push(left);
				st.push(pos - 1);
			}
			if (pos + 1 < right){
				st.push(pos + 1);
				st.push(right);
			}
		}
	}
	vector<int> sortArray(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;
		quicksortstack(nums, left, right);
		return nums;
	}
};