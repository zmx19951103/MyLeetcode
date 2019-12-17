
//思路就是二分+递归
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(vector<int>& nums, int l, int r){
        if(l>r)return NULL;
        int middle = (l+r)/2;
        TreeNode* root = new TreeNode(nums[middle]);
        root->left= helper(nums,l,middle-1);
        root->right = helper(nums,middle+1,r);
        return root;

    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {

        int size = nums.size();
        return helper(nums,0,size-1);
    }
};