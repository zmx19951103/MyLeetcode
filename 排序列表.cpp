/*
 * =====================================================================================
 *
 *       Filename:  排序列表.cpp
 *
 *    Description: 
 *
 *        Version:  1.0
 *        Created:  2019/11/27 22时29分22秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zmxdream (), zmxdream@pku.edu.cn
 *   Organization:  pku
 *
 * =====================================================================================
 */

// 要求 时间复杂度是O(nlogn),空间复杂度是O(1), 所以用了类似数组的归并排序对链表进行归并排序，时间复杂度是符合要求的，但是递归会引入递归栈的空间开销,所以严格来说并不是O(1)。需要改成迭代的。
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
    ListNode* mergelist(ListNode* left,ListNode* right){
        
        ListNode* dummy = new ListNode(-1);
        ListNode* t = dummy;

        ListNode* p = left; ListNode* q = right;
        while(p&&q){
            if(p->val<=q->val){
                t->next = p;
                p=p->next;
            }else{
                t->next=q;
                q=q->next;
            }
          t=t->next;
        }
        while(p) {t->next = p; p =p->next; t=t->next;} 
        while(q){t->next = q;q=q->next; t=t->next;}
        t->next= nullptr;

        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {

        if(head ==nullptr || head->next == nullptr)return head;

        ListNode* p = head;
        int count = 0;
        while(p){count++;p=p->next;}
        int k = count/2-1;
        p = head;
        while(k--)p=p->next;

        ListNode* right = p->next;
        p->next=nullptr;
        ListNode* left = head;

/*
        ListNode* fast = head; ListNode* slow = head;
        while( fast&& fast->next){
             slow = slow->next;
             fast = fast->next->next;
        }
        ListNode* right = slow->next;
        slow->next=nullptr;
        ListNode* left= head;
*/



        left =  sortList(left);
        right = sortList(right);
        
       // p=left;ListNode *q = right;
        
        //while(p){ std::cout<<p->val<<" ";p=p->next;}
        //std::cout<<std::endl;
        //while(q){ std::cout<<q->val<<" "; q=q->next;}
        ///std::cout<<std::endl;

        ListNode* res = mergelist(left,right);
        //q = res;

       // while(q){ std::cout<<q->val<<" "; q=q->next;}
        //std::cout<<std::endl;
        
        return res;

        
    }
};
