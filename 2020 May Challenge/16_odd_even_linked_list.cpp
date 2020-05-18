/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        /*
        Two pointer approach can be used. One for odd indexed nodes and another for even indexed nodes.
        Keeping the heads of both odd indexed node and even indexed node to join.
        */

        //boundary check
        if(head == NULL)
            return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = head->next;

        while(even && even->next){
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }

        odd->next = evenHead;
        return head;
    }
};
