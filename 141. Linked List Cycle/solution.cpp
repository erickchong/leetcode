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
    bool hasCycle(ListNode *head) {
        ListNode* turtle = head;
        ListNode* hare = head;
        
        while (turtle != nullptr && hare != nullptr) {
            for (int i = 0; i < 2; ++i) {
                hare = hare->next;
                if (hare == nullptr) return false;
            }
            turtle = turtle->next;
            if (turtle == hare) return true;
        }
        return false;
    }
};