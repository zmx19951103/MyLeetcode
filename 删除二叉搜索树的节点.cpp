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
    TreeNode* deleteNode(TreeNode* root, int key) {


        if(!root)return root;
        
        if(root->val == key){

            if (root->left)  {
              TreeNode* prev = root->left, *cur = root->left;
              while(cur->right){ prev= cur ; cur=cur->right;}
              root->val = cur->val;
              if(prev == cur) root->left = cur->left;
              else  prev->right = cur->left;
              return root;

            } // 找root->left 最右下的节点
            else {return root->right;} // 如果 left 不存在直接root->right就是新的root
        }

        if(root->left&&key<root->val){
            root->left = deleteNode(root->left,key);
        }
        if(root->right&&key>root->val){
            root->right = deleteNode(root->right,key);
        }
        return root;

       //O(h)
       //替换的规则很简单，感觉是遍历的算法要高效
       // 如何做到 O(h)找到某个节点,递归就是了，因为二叉搜索树，所以和二分查找一样，每次比较和根节点的大小，然后找左子树或者右子树继续遍历，
       //时间复杂度是O(logn)=O(h)
        
    }
};