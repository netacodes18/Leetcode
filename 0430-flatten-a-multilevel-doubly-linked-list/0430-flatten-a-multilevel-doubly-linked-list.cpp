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
        Node* last = head;

        while (curr) {

            Node* nxt = curr->next;

            if (curr->child) {

                Node* childHead = curr->child;

                Node* childTail = dfs(childHead);

                curr->next = childHead;
                childHead->prev = curr;

                curr->child = NULL;

                if (nxt) {
                    childTail->next = nxt;
                    nxt->prev = childTail;
                }

                last = childTail;
                curr = childTail;
            }
            else {
                last = curr;
            }

            curr = curr->next;
        }

        return last;
    }

    Node* flatten(Node* head) {

        if (!head)
            return NULL;

        dfs(head);

        return head;
    }
};