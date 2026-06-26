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
}*/

