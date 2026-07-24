/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:

    Node* dfs(Node* head) {

        Node* curr = head;

        while (curr) {

            Node* nxt = curr->next;

            if (curr->child) {

                // Flatten child list
                Node* childHead = dfs(curr->child);

                // Attach child after current
                curr->next = childHead;
                childHead->prev = curr;
                curr->child = NULL;

                // Find tail of child list
                Node* tail = childHead;
                while (tail->next) {
                    tail = tail->next;
                }

                // Connect tail with original next
                tail->next = nxt;
                if (nxt)
                    nxt->prev = tail;
            }

            curr = curr->next;
        }

        return head;      // return head instead of tail
    }

    Node* flatten(Node* head) {

        if (!head)
            return NULL;

        return dfs(head);
    }
};