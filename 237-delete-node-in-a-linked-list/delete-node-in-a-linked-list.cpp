class Solution {
public:
    void deleteNode(ListNode* node) {

        // Hume current node ko directly delete nahi karna,
        // kyunki previous node ka pointer humare paas nahi hai.
        // Isliye next node ki value current node mein copy karenge.
        node->val = node->next->val;


        // Ab next node ko ek temporary pointer mein save kar rahe hain.
        // Baad mein isi node ko memory se delete karna hai.
        ListNode* temp = node->next;


        // Current node ke next ko uske next ke next se connect kar do.
        // Matlab beech wale node ko skip kar do.
        node->next = node->next->next;


        // Jo node humne skip kiya tha, uski memory free kar do.
        delete temp;
    }
};