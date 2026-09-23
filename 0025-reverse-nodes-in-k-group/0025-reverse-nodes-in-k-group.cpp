class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Recursive solution
        // Base Case
        if (head == nullptr) {
            return nullptr;
        }

        // step 1: Check if there are at least k nodes to reverse
        ListNode* temp = head;
        int count = 0;
        while (temp != nullptr && count < k) {
            temp = temp->next;
            count++;
        }

        // If there are fewer than k nodes left, return head without reversing
        if (count < k) {
            return head;
        }

        // Step 2 : reverse k nodes
        ListNode* prev = nullptr;
        temp = head;
        ListNode* next = nullptr;
        count = 0;
        while (temp != nullptr && count < k) {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
            count++;
        }

        // recursive call;
        if (next != nullptr) {
            head->next = reverseKGroup(next, k);
        }

        // return
        return prev;
    }
};