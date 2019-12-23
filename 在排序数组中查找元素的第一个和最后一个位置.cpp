class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0)return {-1,-1};

        // O(logn) 二分
       int l = 0 , r = nums.size()-1;
       int left = -1, right =-1;

       while(l<r){
            int mid  =(l+r)/2;
            if(nums[mid]>=target) r = mid; else l = mid +1;

       }

       if(nums[l]==target)left = l;
        
        l = 0, r = nums.size()-1;

    //     while(l<r){
    //         int mid  =(l+r)/2;
    //         if(nums[mid]>target) r = mid-1; else l = mid +1;

    //    }
    //    right = l-1;
    //    left =l;
       
          while(l<r){
            int mid  =(l+r+1)/2;
            if(nums[mid]<=target) l = mid; else r = mid -1;

       }
       if(nums[l]==target)right = l;

       return {left,right}; 
    
    }
};

//在一个排序数组中查找>=x的最小的数和<=x的最大的数,就是left和right
