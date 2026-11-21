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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessDmy = new ListNode(-1);
        ListNode* lessDmyTail = lessDmy;
        ListNode* greatDmy = new ListNode(-1);
        ListNode* greatDmyTail = greatDmy;

        ListNode* tmp = head;
        while(tmp != NULL) {
            if(tmp->val < x) {
                lessDmyTail->next = tmp;
                lessDmyTail = lessDmyTail->next;
               
            } else {
                greatDmyTail->next = tmp;
                greatDmyTail = greatDmyTail->next;
            }
            tmp = tmp->next;
        }

        lessDmyTail->next = greatDmy->next;
        greatDmyTail->next = NULL;
        delete(greatDmy);
        return lessDmy->next;

    }
};