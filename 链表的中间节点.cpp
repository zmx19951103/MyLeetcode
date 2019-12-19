/*
 * =====================================================================================
 *
 *       Filename:  链表的中间节点.cpp
 *
 *    Description:  fast pointer, slow pointer 
 *
 *        Version:  1.0
 *        Created:  2019/12/19 16时33分18秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zmxdream (), zmxdream@pku.edu.cn
 *   Organization:  pku
 *
 * =====================================================================================
 */



// 快慢指针， 时间复杂度O(N),空间复杂度O(1)
//
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //快慢指针找中间节点,这个技巧用一次遍历找到链表的中间节点
    // 在重排列表，排序链表中都有用到
    ListNode* middleNode(ListNode* head) {

        if(head->next==NULL) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        
        // while(p->next){
           
          
        //     if(q&&q->next)
        //         q = q->next->next;
        //     else break;
        //     p = p->next;
            
         // }
          // 0 1 2 3 NULL
       while(fast&&fast->next){
          fast=fast->next->next;
          slow = slow->next;

       }
        return slow; 
    }
};

