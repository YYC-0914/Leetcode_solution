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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr;
        ListNode *tail = nullptr;
        ListNode *p1 = l1, *p2 = l2;
        int t = 0;
        while (p1 != nullptr || p2 != nullptr){
            if (p1 != nullptr){
                t += p1->val;
                p1 = p1->next;
            }
            if (p2 != nullptr){
                t += p2->val;
                p2 = p2->next;
            }
            if (! head){
                head = tail = new ListNode(t % 10);
            }
            else{
                tail->next = new ListNode (t % 10);
                tail = tail->next;
            }

            t /= 10;
        }
        if (t > 0){
            tail->next = new ListNode(t);
        }
        return head;
    }
};
