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
    ListNode* swapPairs(ListNode* head) {

        if(head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* first = head;
        ListNode* snd = head->next;
        ListNode* newHead = snd;
        ListNode* prev = NULL;
        // do {
        //     ListNode* nextNode = snd->next;
        //     swap(first,snd);
        //     first = nextNode;
        //     snd = first->next;
        // }
        while(first != NULL && snd != NULL) {
            ListNode* nextNode = snd->next;
            snd->next = first;
            first->next = nextNode;

            if(prev != NULL) {
                prev->next = snd;
            }

            prev = first;
            first = nextNode;
            if(first != NULL) {
                snd = first->next;
            }
        }
        return newHead;
    }
};