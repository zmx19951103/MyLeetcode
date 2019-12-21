/*
 * =====================================================================================
 *
 *       Filename:  对链表进行插入排序.cpp
 *
 *    Description:  普通插入排序，创建dummy节点
 *
 *        Version:  1.0
 *        Created:  2019/12/21 15时03分57秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zmxdream (), zmxdream@pku.edu.cn
 *   Organization:  pku
 *
 * =====================================================================================
 */

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
    ListNode* insertionSortList(ListNode* head) {
           
            if(head==NULL||head->next==NULL)return head;
             
 
              ListNode* dummy = new ListNode(-1);
              dummy->next = head;
              ListNode *p = head->next ;
              head->next = NULL;
              
              while(p){

               ListNode* nex = p->next;
               ListNode* cur = dummy->next;
               ListNode* prev = dummy;

               while(cur&&cur->val<=p->val){prev = cur; cur=cur->next;}
               if(!cur){ // 插入到最后

                   p->next = prev->next;
                   prev->next = p;
               }else{

                   p->next = prev->next;
                   prev->next = p;

               }
                   p = nex;
              }
              return dummy->next;
        
    }
};
