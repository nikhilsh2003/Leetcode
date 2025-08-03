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
    ListNode* reverse(ListNode* temp) {
        if(!temp or !temp->next) return temp;
        ListNode* rev=reverse(temp->next);
        temp->next->next=temp;
        temp->next=NULL;
        return rev;
    }
    void reorderList(ListNode* head) {
        int n=0;
        ListNode* temp=head;
        while(temp) {
            n++;
            temp=temp->next;
        }
        int ct=0;
        temp=head;
        while(temp) {
            ct++;
            if(ct==((n+3)/2)) break;
            temp=temp->next;
        }
        temp=reverse(temp);
        ListNode* front=head;
        while(front) {
            ListNode *nextTemp,*nextFront;
            nextFront=front->next;
            front->next=temp;
            if(!temp) return;
            front=nextFront;
            nextTemp=temp->next;
            temp->next=nextFront;
            temp=nextTemp;
        }
    }
};