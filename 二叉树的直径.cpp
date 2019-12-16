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

    int helper(TreeNode* root, int & diameter){
      
      int leftmax=0, rightmax=0; 
     
      if(root->left) leftmax = helper(root->left,diameter);
      if(root->right) rightmax = helper(root->right, diameter);

        
      if(root->left&&root->right){
         
         diameter=std::max(diameter,leftmax+rightmax+2);
          return std::max(leftmax,rightmax)+1;

      }else if(root->left){
            diameter=std::max(diameter,leftmax+1);
             return std::max(leftmax,rightmax)+1;
                        
      }else if(root->right){
            diameter=std::max(diameter,rightmax+1);
             return std::max(leftmax,rightmax)+1;
      }
       

       return std::max(leftmax,rightmax);


    }


// 递归的做法， 二叉树的直径不一定经过根节点，所以以root节点为根的二叉树的直径 = std::max(左子树的直径，右子树的直径，左子树的最大深度+右子树的最大深度+2)；
    int diameterOfBinaryTree(TreeNode* root) {

    if(!root) return 0;
      
      int MaxDiameter = 0 ; 
      int leftmax=0, rightmax=0; 
     
      if(root->left) leftmax = helper(root->left,MaxDiameter);
      if(root->right) rightmax = helper(root->right, MaxDiameter);
        
     // std::cout<<leftmax<<" "<<rightmax<<std::endl;

      if(root->left&&root->right){
         MaxDiameter=std::max(MaxDiameter,leftmax+rightmax+2);
      }else if(root->left){
            MaxDiameter=std::max(MaxDiameter,leftmax+1);
      }else if(root->right){
            MaxDiameter=std::max(MaxDiameter,rightmax+1);
      }

       return MaxDiameter;
    }

};