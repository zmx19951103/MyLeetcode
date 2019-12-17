/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL)return NULL;

      //对二叉搜索树的中序遍历就是有序列表
      //结果又很多种，我们可以用递归，一直从中间分，有点像排序列表， 一直有用快慢指针找中点的，上次看排序列表好像不对
	  //https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/solution/kuai-man-zhi-zhen-zhao-zhong-dian-by-powcai/
      ListNode* p = head;
      int num = 0;
      while(p){
          num++;
          p=p->next;
      }
      p= head;
      ListNode* t = p;
      int k = num/2;
      while(k--){
          t=p;
          p = p->next;
      }
      // new p refer to middle
     t->next = NULL;

     TreeNode* root = new TreeNode(p->val);
     if(t==p) root->left=NULL;
     else root->left = sortedListToBST(head);
     root->right= sortedListToBST(p->next);
     return root;
    }
};