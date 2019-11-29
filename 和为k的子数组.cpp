/*
 * =====================================================================================
 *
 *       Filename:  和为k的子数组.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2019/11/29 21时03分57秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zmxdream (), zmxdream@pku.edu.cn
 *   Organization:  pku
 *
 * =====================================================================================
 */



// 累积和数组的解法是第一个想到的，时间复杂度是O(n^2),空间复杂度是O(n)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> sums;
        for(size_t i = 0 ; i< nums.size(); i++ ){

            if(i==0) sums.push_back(nums[i]);
            else sums.push_back(nums[i]+sums[i-1]);

        }
        int res =0;

        for(int i = 0 ; i<nums.size();i++){
          for(int j =i; j<nums.size();j++){
              if(i==0) {
                  int temp = sums[j]-0;
                  if(temp==k)res+=1;

              }else{

                   int temp = sums[j]-sums[i-1];
                   if(temp==k)res+=1;

              }
          }
        }
        return res;      
    }
};


// 进一步优化
//
//
