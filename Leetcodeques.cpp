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
                                           //22
class Solution {
    vector <string> ans ;
public:
    void solve(int open , int close , int n , string curr){
        if(curr.length()==2*n){
        ans.push_back(curr);
        curr = "";
        }

        if(open<n){
            solve(open+1, close , n , curr + '(');
        }

        if(close<open){
            solve(open,close+1,n,curr+')');
        }
    }


    vector<string> generateParenthesis(int n) {
        string curr ="";
        solve(0,0,n,curr);
        return ans;
    }
};
                                       //39ques
class Solution {
    public :
     vector <vector<int>> ans ;
        vector <int> path;
    void dfs (int start , vector <int> candidates , int target){
            if(target==0){
                ans.push_back(path);
                return ;
            }

            for(int i = start ; i<candidates.size() ; i++){
                if(candidates[i]>target) continue;

                path.push_back(candidates[i]);

                dfs(i,candidates,target - candidates[i]);
                path.pop_back();
            }
        }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(0,candidates,target);
        return ans;
    }
};                                    
                                   //40 ques
class Solution {
public:
        vector <vector<int>> ans;
        vector <int> path ;

        void dfs (int start , vector <int> candidates , int target){
            if(target==0) {
               ans.push_back(path);
               return ;
            }
            for( int i = start ; i<candidates.size() ; i++){
                if(i>start && candidates[i]==candidates[i-1]) continue;   //this ques may contains duplicates in input 
                if(candidates[i]>target) continue;

                path.push_back(candidates[i]);
                dfs(i+1,candidates,target-candidates[i]); //i+1 becoz sam element cant be used
                path.pop_back();  //to remove last choosen element
                
            }
        }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        dfs(0,candidates,target);
        return ans;
    }
    
};
                                        //78
class Solution {
public:
vector <int> path;
vector <vector<int>> ans;
    void dfs(int indx , vector <int> &nums){
       ans.push_back(path);  //every state represents one  subset

       for(int i = indx ; i<nums.size() ; i++ ){
        path.push_back(nums[i]);

        dfs(i+1,nums); 

        path.pop_back(); //backtrack
       }
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0,nums);
        return  ans;
    }
};
                                      //90 ques
                                      class Solution {
public:
vector <vector<int>> ans;
vector <int> path ;
    void dfs(int indx , vector<int>&nums){
        ans.push_back(path);

        for( int i = indx ; i<nums.size() ; i++){
            if(i>indx && nums[i]==nums[i-1]) continue;

            path.push_back(nums[i]);

            dfs(i+1,nums);
            path.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        dfs(0,nums);
        return ans;
    }
}; 
                                   //216
                                   class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(int indx, int k, int target) {
        if (target == 0 && k == 0) {
            ans.push_back(temp);
            return;
        }

        if(k==0 || target < 0) return ; //invalid state

        for (int i = indx; i <= 9; i++) {
            if (i > target) break;

            temp.push_back(i);   
            solve(i + 1, k-1, target - i);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {

        solve(1, k, n);
        return ans;
    }
}; 
                                 //17ques
                                 class Solution {
public:
    vector<string> result;
     
    void backtrack (string digits , vector<string> mapping , int index , string current){
        if(index==digits.length()){
            result.push_back(current);
            return ;
        }

        string letter = mapping[digits[index] - '0'];

        for (char ch : letter){
            backtrack(digits , mapping , index + 1 , current + ch);
        }

    }

    vector<string> letterCombinations(string digits){
        if (digits.empty()) return {};
        vector<string> mapping = {"" , "" , "abc", "def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wxyz"};
        backtrack(digits, mapping , 0 , "");
        return result;
    }
};
                             //79 ques
                    class Solution {
public:
    bool solve (vector<vector<char>>& board, string word,int row , int col, int indx){
        if(board[row][col]!=word[indx]) return false;
        if(word.size()-1 == indx) return true ;

        char ch = board[row][col];
        board[row][col] = '#';

        if(row>0 && solve(board,word,row-1,col,indx+1)){
           board[row][col] = ch;
           return true;
        }
        else if(row<board.size()-1 && solve(board,word,row+1 , col , indx+1)){
            board[row][col] = ch;
            return true;
        }
        else if(col>0 && solve(board,word, row, col-1 ,  indx+1)){
            board[row][col]=ch;
            return true;
        }
        else if(col<board[0].size()-1 && solve(board,word,row, col+1 , indx+1)){
            board[row][col]=ch;
            return true;
        }

        board[row][col] = ch;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0 ; i<board.size();i++){
            for( int j = 0  ; j<board[0].size() ; j++){
                if(solve(board,word,i,j,0)) return  true;
            }
        }return false;
    }
};
                                 //51 ques
class Solution {
public:

    void solve(int col , vector <vector<string>> &ans, vector<string> &board , int n ,vector <int> &leftrow , vector<int> &UpperDiagonal , vector <int> &LowerDiagonal){


        if(col==n){
            ans.push_back(board);
            return ;
        }

        for( int row= 0 ; row <n ; row ++){
            if(leftrow[row]==0 && UpperDiagonal[(n-1)+(col-row)]==0 && LowerDiagonal[row+col]==0) {
                board[row][col] = 'Q';
                leftrow[row] = 1;
                UpperDiagonal[(n-1)+(col-row)] = 1;
                LowerDiagonal[row + col] = 1;
                solve(col +1 , ans,board ,n ,leftrow , UpperDiagonal , LowerDiagonal);

                board[row][col] = '.';
                leftrow[row] = 0;
                UpperDiagonal[(n-1)+(col-row)] = 0;
                LowerDiagonal[row + col] = 0;
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector <vector<string>> ans;
        vector <string> board(n) ;
        string s(n,'.');
        for ( int i =0 ; i< n ;i++){
            
               board[i] = s;
            
        }
        vector<int> leftrow(n,0) , UpperDiagonal(n*2-1,0) , LowerDiagonal(2*n-1,0);
        solve(0,ans,board,n,leftrow,UpperDiagonal,LowerDiagonal);

        return ans;
    }
};
                                         //282
                                         class Solution {
public:
    vector <string> ans;
    void solve (string num , int target ,int index, long long currval , long long prenum , string path ){
        if(index==num.size()){
            if(currval==target){
                ans.push_back(path);
            }return ;
        }

        for (int i= index ; i<num.size() ; i++){
            if(i>index && num[index] == '0') break;

            string str = num.substr(index,i-index+1);
            long long currnum = stoll(str);

            if(index==0) solve(num,target,i+1,currnum,currnum,str);
            else {
                solve(num, target ,i+1 ,currval + currnum,currnum,path +"+"+ str);
                solve(num, target, i+1 ,currval - currnum,-currnum, path +"-"+str);
                solve(num , target ,i+1
                ,currval-prenum + (currnum*prenum)
                ,currnum*prenum,
                path+"*"+str);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        ans.clear();
        solve(num,target,0,0,0,"");
        return ans;
    }
}; 
                                  //29ques
                                  class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor){
            return 1;
        }
        bool sign  = true ;
        if(dividend < 0 && divisor > 0 ) sign = false;
        if(dividend > 0 && divisor < 0 ) sign = false;
        
        long long ans  =0;
long long n = llabs((long long)dividend);
        long long d = llabs((long long)divisor);


        while(n >= d){
            int count = 0;
            while(n >= (d<<(count+1))){
                count++;
            }
            ans += 1LL<<count;
            n = n-d*(1LL<<count);
        }

        if(ans > INT_MAX && sign==true) return INT_MAX;
        if(ans > INT_MAX && sign==false ) return INT_MIN;

        return sign? ans: -ans;
    }
};                                   
                                 //2220
                                 class Solution {
public:
    int minBitFlips(int start, int goal) {
      int x = start^goal;
      int count = 0;
      while(x>0){
        count += (x & 1);
        x >>= 1;
      }
        return count;
    }
};  
                              //136 ques
                              class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int num:nums){
            result ^=num;
        }return  result;
    }
};/*
                             //204
                             class Solution {
public:
    int countPrimes(int n) {
      /*  if (n < 2)
            return 0;
        int count = 0;
        for (int i = 2; i < n; i++) {
            bool flag = true;
            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag == true)
                count++;
        }
        return count;

        if(n<=2) return 0;
        vector<bool> isprime(n,true);
        isprime[0] = false; //0,1 are not applicable in this  ques
        isprime[1] = false;
        
        for(int i = 2 ; i*i< n ; i++){ // marking false to square of primes
            if(isprime[i]){
                for(int j = i*i ; j < n ; j += i){
                    isprime[j] = false;
                }
            }
        }
        
        int count = 0 ;
        for(int i = 2 ; i<n ; i++){
            if(isprime[i]) count++;
        } 
        return  count ;  }
};
                                           //155
                                        class MinStack {
public:
stack <int> s;
stack <int> minstack;
int min = INT_MAX;
int prevmin = INT_MAX;
    MinStack() {
        
    }
    
    void push(int value) {
        if(minstack.empty() || value<minstack.top()){
            minstack.push(value);
        }else {
            minstack.push(minstack.top());
        }
        s.push(value);
    }
    
    void pop() {
        minstack.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
  

                                                     //496ques
                                                     class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // int s1 = nums1.size();    //brute force
        // int s2 = nums2.size();
        // vector<int> result;

        // for (int i = 0; i < s1; i++) {
        //     bool flag = false;
        //     for (int j = 0; j < s2; j++) {
        //         if (nums1[i] == nums2[j]) {
        //             for (int k = j + 1; k < s2; k++) {
        //                 if (nums2[k] > nums1[i]) {
        //                     result.push_back(nums2[k]);
        //                     flag = true;
        //                     break;
        //                 }
        //             }
        //         }
        //     }if (flag == false)
        //         result.push_back(-1);

        // }return result;

        stack<int> st;
        unordered_map<int, int> nge; //next greater element

        for (int i : nums2) {
            while (!st.empty() && i>st.top()){
                nge[st.top()] = i ; //marking next greater element of st.top()
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()){
            nge[st.top()] = -1;
            st.pop();
        }

        vector <int> result;
        for (int num : nums1){
            result.push_back(nge[num]);
        }
        return result;
        }
    }; 
                                               //503
                                               class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack <int> st;
        int n = nums.size();
        vector <int> ans(n,-1);
        for(int i= 2*n-1 ; i>=0 ; i--){
            int idx = i%n;
            while(!st.empty() && nums[st.top()] <= nums[idx]){
                st.pop();
            }

            if(!st.empty()) {
                ans[idx] = nums[st.top()];
            }

            st.push(idx);
        }
       return ans;
    }
}; 
                                            //42
                                            class Solution {
public:
    int trap(vector<int>& height) {
       int water = 0;
       int n = height.size();
        vector <int> leftmax(n);
       vector <int> rightmax(n);
       leftmax[0] = height[0];
       for(int i = 1 ; i<n ; i++){
        leftmax[i] =  max(leftmax[i-1],height[i]);
        }

        rightmax[n-1] = height[n-1];
        for (int i = n-2 ; i>=0 ; i--){
            rightmax[i] = max(rightmax[i+1],height[i]);
        }

        for(int i=0; i<n ; i++){
                water += min(leftmax[i],rightmax[i]) - height[i];
        }
return water;
    }
};
                                        //907
                                        class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
       int n = arr.size();   //does overflow 
       
        long long sum =0;
        int MOD = 1e9 + 7;
        /*
        for(int start = 0 ; start <n ; start ++){
            int minn =INT_MAX;
            for(int end = start ; end <n ; end++){
                minn = min(minn,arr[end]);
                sum = (sum+minn)%MOD;
            }
        }return sum;

        stack <int> stk ;
        vector <int> leftmin(n,-1);
        vector <int> rightmin(n,-1);
        for(int i= 0 ;i<n ;i++){
            while(!stk.empty() && arr[stk.top()]>arr[i]){
                stk.pop();
            }
            if(!stk.empty()){
            leftmin[i] = stk.top();

            }
            stk.push(i);
        }
        while(!stk.empty()) stk.pop();
       
        for(int i=n-1 ; i>=0 ; i--){
            while(!stk.empty() && arr[stk.top()]>=arr[i]){
               
                stk.pop();
            }
            if(stk.empty()) rightmin[i] = n;
            else {
                rightmin[i] = stk.top();
            }
            stk.push(i);
        }

        for(int i=0 ; i<n ; i++){
            int leftchoice = i- leftmin[i];
            int rightchoice = rightmin[i] - i;
            sum = (sum +(1LL*arr[i]*leftchoice)%MOD*rightchoice)%MOD ;
        }return sum ;
    }
};
*/
