class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        // Jab tak fast khud NULL nahi hai aur fast ke baad bhi ek node available hai,
        // tab tak loop chalega, kyunki hume fast ko ek baar mein 2 nodes aage le jaana hai.
        // Isliye fast->next NULL hua toh fast ko 2 steps aage nahi le ja sakte.

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;          // slow 1 node aage
            fast = fast->next->next;    // fast 2 nodes aage
        }

        return slow;                    // middle node
    }
};