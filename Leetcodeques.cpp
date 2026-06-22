//Ques 148

/*class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector <int> s;
        ListNode * temp = head;
        while(temp!=nullptr){
            s.push_back(temp->val);
            temp = temp -> next;
        }
sort(s.begin(),s.end());

        temp = head;
        int i = 0;
        while(temp!=NULL){
            temp-> val = s[i++];
            temp = temp -> next ;
        }
        return head;
    }
};*/

//160
/*class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;
        unordered_set<ListNode*> nodes_in_A;
        unordered_set<ListNode*> nodes_in_B;
        while(ptr1!=nullptr){
            nodes_in_A.insert(ptr1);
            ptr1 = ptr1->next;
        }
        while(ptr2!=nullptr){
            if(nodes_in_A.count(ptr2)) return ptr2;
            ptr2=ptr2->next;
        }return nullptr;
    }
};*/