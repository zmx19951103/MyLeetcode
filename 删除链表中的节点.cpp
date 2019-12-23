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
    void deleteNode(ListNode* node) {
        ListNode* p = node, *nex = node->next;
        while(nex){
            p->val = nex->val;
            
            if(nex->next==NULL) {p->next= NULL;break;}

            p=nex;
            nex=nex->next;
        }
        return;
    }
};

//只给了要删除的节点，用后面的节点的值来覆盖前面的值，然后删掉最后一个节点