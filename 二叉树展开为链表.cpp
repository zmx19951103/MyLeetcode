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
    void flatten(TreeNode* root) {

        // if(root==NULL)return;
           
        // if(root->right)flatten(root->right);
        // if(root->left)flatten(root->left);

        // if(root->left) {
        // TreeNode* p = root->left;
        // while(p->right)  p = p->right;
        //  p->right = root->right;
        //  root->right = root->left;
        //  root->left = NULL;

        // }

// 可以把递归改成迭代

    
        while(root!=NULL){
           
        //if(root->right)flatten(root->right);
        //if(root->left)flatten(root->left);

        if(root->left) {
        TreeNode* p = root->left;
        while(p->right)  p = p->right;
         p->right = root->right;
         root->right = root->left;
         root->left = NULL;

        }
        root=root->right;


        }
        
    }
};
//递归的思路比较好理解， 就是从展开的形式来看，右子树是接在左子树的最右下的节点的right部分的.