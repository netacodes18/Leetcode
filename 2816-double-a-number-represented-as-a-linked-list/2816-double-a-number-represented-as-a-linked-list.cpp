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
    ListNode* reverse(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        return prev;
    }

    ListNode* doubleIt(ListNode* head) {

        head = reverse(head);

        ListNode* curr = head;
        ListNode* last = NULL;
        int carry = 0;

        while (curr) {

            int sum = curr->val * 2 + carry;

            curr->val = sum % 10;
            carry = sum / 10;

            last = curr;
            curr = curr->next;
        }

        // Agar carry bacha hai
        if (carry) {
            last->next = new ListNode(carry);
        }

        return reverse(head);
    }
};