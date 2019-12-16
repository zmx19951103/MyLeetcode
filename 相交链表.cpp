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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode* p = headA, *q = headB;
         int lenA =0 , lenB = 0 ;
    //    std::set<ListNode*> ss; //oh not O(1) 

        while(p){
      //    ss.insert(p);
         lenA+=1;
          p=p->next;
        }

        while(q){
          //if(ss.count(q)==1)return q;
          //else ss.insert(q);
          lenB +=1;
          q=q->next;
         
        }

        int dist = std::max(lenA,lenB)-std::min(lenA,lenB);
        p = headA; q = headB;
        if(std::max(lenA,lenB)==lenA) {
        while(dist--) p =p->next;
        } else {
            while(dist--)q=q->next;
        }

        while(p&&q){
          if(p==q)return p;
          else {p=p->next;q=q->next;}


        }
       
        return nullptr;



        
    }
};