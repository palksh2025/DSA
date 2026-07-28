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
        if(head == nullptr){
            return false;
        }
        if(head->next == nullptr){
            return false;
        }

        vector<ListNode*> address;
        ListNode* temp = head;

        while(temp){
            if (find(address.begin(), address.end(), temp) == address.end()){
                address.push_back(temp);
            }
            else{
                return true;
            }
            temp = temp->next;
        }

        return false;
    }
};