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
};

//1922
 const long long MOD = 1e9 + 7;
public:

    long  long power(long long base , long long exp){ //binary exponentiation
        long long ans = 1;  
        while(exp>0){
            if(exp & 1){ //checking if exp is odd
                ans = (ans * base)%MOD;
            }

            base = (base * base)%MOD; 

            exp >>= 1; //dividing exp by 2 
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long  even = (n+1)/2;
        long long  odd = n/2;
        return (power(5,even)*power(4,odd))%MOD;
    }
        

    //8
   int myAtoi(string s) {
        int i = 0;
        long long result = 0;
        int sign = 1;
        while (i < s.size() && s[i] == ' ') i++;
    
    if (s[i] == '-' || s[i] == '+') {
        if (s[i] == '-')
            sign = -1;
        i++;
    }
    while (i < s.size() ) {
        if(!isdigit(s[i])) break;

        int digit = s[i++] - '0';

        if(result > INT_MAX/10 || (result == INT_MAX/10 && digit > 7))
            return (sign == 1)? INT_MAX : INT_MIN;
        result = result * 10 + digit;
    }

    
    return result * sign;
}
} 

//138

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node * temp = head;
        unordered_map <Node*,Node*> mp;
        while(temp){
            mp[temp] = new Node(temp->val);
            temp = temp-> next;
        }

        temp = head;
        while(temp){
            mp[temp] -> next = mp[temp->next];
            mp[temp] -> random = mp[temp->random];

            temp = temp->next;
        }

        return mp[head];
    }
};

//61

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if( !head || !head->next || k==0 ){
            return head;
        }

        int n =1;

        ListNode * temp = head;
        while(temp->next){
            n++;
            temp = temp -> next ;
        }

        ListNode * tail = temp ;
        tail -> next = head;

        k %=n;
        n = n-k-1; //-1 because tail will be modified 
        temp = head;

        while(n--){
            temp = temp -> next;
        }

        ListNode * newHead = temp->next;
        temp -> next = nullptr;

        return newHead;
    }
};


//25 

lass Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode * prevgroup = &dummy;

        while(true){
            ListNode * kth = prevgroup;
            for(int i = 0 ; i<k && kth ; i++){
                kth = kth -> next ;
            }

            if(!kth) break ;

            ListNode  *nextgroup = kth -> next ;
            ListNode * prev = nextgroup;
            ListNode * curr = prevgroup->next;

            while(curr != nextgroup){
                ListNode * nxt = curr -> next ;
                curr -> next = prev ;
                prev = curr ;
                curr = nxt ;
            }

            ListNode * temp = prevgroup->next; //storing previous head
            prevgroup->next = kth ; //connecting previous head , which is now tail to next node (reinitializing dummy to head of LL )
            prevgroup = temp; // marking previous group to tail of prevgroup

        }
        return dummy.next;
    }
};
*/
