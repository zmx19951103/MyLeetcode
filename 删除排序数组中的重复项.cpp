/*
 * =====================================================================================
 *
 *       Filename:  删除排序数组中的重复项.cpp
 *
 *    Description:  双指针
 *
 *        Version:  1.0
 *        Created:  2019/12/21 12时20分23秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zmxdream (), zmxdream@pku.edu.cn
 *   Organization:  pku
 *
 * =====================================================================================
 */


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //原地
        //O(1)
        // 队列
        //排序过的
      //O(n)双指针,O(n)
      int size= nums.size();
      int p , q ;
      for( p=0,q=0 ;p<size;p++){   
        if(p==0){q++;continue;}
        //if(nums[p]==nums[p-1]){     
            while(q<size&&nums[q]==nums[p-1])q++;
            if(q<size){nums[p]=nums[q];q++;}
            else break;
        //}
      }
      return p;
    }
};
