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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        ListNode* newHead = getNewHead(head, k);
        ListNode* result = new ListNode(newHead->val);
        ListNode* newHeadCopy = newHead;
        ListNode* resultCopy = result;
        
        while (newHeadCopy->next != nullptr) {
            resultCopy->next = new ListNode(newHeadCopy->next->val);
            resultCopy = resultCopy->next;
            newHeadCopy = newHeadCopy->next;
        }
        while (head != newHead) {
            resultCopy->next = new ListNode(head->val);
            resultCopy = resultCopy->next;
            head = head->next;
        }
        return result;
    }
    
    ListNode* getNewHead(ListNode* head, int k) {
        ListNode* slow = head;
        ListNode* fast = head;
        int listSize = 0;
        /* Calculate list size first */
        while (fast != nullptr) {
            fast = fast->next;
            listSize++;
        }
       
        int trueK = (k >= listSize) ? k % listSize : k;
            
        if (trueK == 0) return head;
        
        fast = head;
        while (trueK > 0) {
            fast = fast->next;
            trueK--;
        }
        
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};