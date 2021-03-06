#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <climits>

using namespace std;

struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
};



int singleNumber(vector<int>& nums) {
        
    sort(nums.begin(), nums.end());

    return 0;

}

bool checkValid(string s ){

    int count1 = 0;
    int count2 = 0;
    bool result = true;
    for(unsigned long i = 0 ; i < s.length(); i++){
        if(s[i] == '('){
            count1 ++;
        }else{
            count2 ++;
        }

        if(count2 > count1){
            result = false;
            return false;
        }
    }

    return true;
}
vector<string> generateParenthesis(int n) {
    vector<string> v;

    string s = "";
    for(int i = 0; i < n; i++ ){
        s = s + "(";
    }
    for(int i = 0; i < n; i++ ){
        s = s + ")";
    }

    do{
        if(s[0] == ')' || s[s.length() -1 ] == '('){
            continue;
        }else{
            bool t = true;
            t = checkValid(s);
            if(t==true){
                v.push_back(s);
            }
            //cout << s << endl;
        }
    }while(next_permutation(s.begin(),s.end()));


    for(unsigned long i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }
    return v;

}

struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
};

void travel(TreeLinkNode *root,TreeLinkNode *next, bool isleft, bool beenToLeft){


    if(isleft){
        root->left->next = root -> right;
        root-> right -> next = next -> left;
        beenToLeft = true;
        if(root -> left -> left!= NULL){
            travel(root->left,root->left->next,isleft, beenToLeft);
            travel(root->right,root-> right -> next,0, beenToLeft);
        }
    }
    else{

        root->left ->next = root-> right;
        if(beenToLeft){
            root -> right -> next = next -> left;
        }
        if(root->left -> left != NULL){
            travel(root->left, root->left->next, 1, beenToLeft);
            travel(root->right, root->right->next,0,beenToLeft);
        }
        
       
    }

}
void connect(TreeLinkNode *root) {
    if(root == NULL) return;
    if(root -> left != NULL){
        root -> left -> next = root -> right;
        if(root -> left -> left != NULL){
            travel(root -> left, root->left -> next, 1, 1);
            travel(root -> right, root->right->next,0,0);
        }

    }
}



int maxSubArray(vector<int>& nums) {
    int length = nums.size();
    vector<vector<int> > v(length, vector<int>(length)); 
    int max = 0;
    for(int i = 0; i < length; i++){
        if(nums[i] > max){
            max = nums[i];
        }
    }

    for(int i = 0; i < length; i++){
        v[0][i] = max;
    }

 //   cout << "max: " << max << endl;

    int t_max = max;
    for(int i = 1; i < length;i++){
       // t_max = v[i-1][length-1];
        for(int j = i; j < length; j++){
            int tmp = 0;
            int count = i + 1;
            int j2 = j;
           

                while(count > 0){
                    tmp = tmp + nums[j2];
                    count --;
                    j2 --;
                }

                if(tmp > t_max){
                    v[i][j] = tmp;
                    t_max = tmp;
                }else{
                    
                    v[i][j] = t_max;
                }
            
        }
    }
/*
    for(int i = 0; i < length; i++){
        for(int j = 0; j < length; j++){
            cout << v[i][j] << " " ;
        }
        cout << endl;
    }

*/


    cout <<  v[length-1][length-1] << endl;

    return v[length-1][length-1];

}


int uniquePaths(int m, int n) {
        
    vector <vector<int> > v(m, vector<int>(n));
    for(int i = 0; i < m; i++){
        v[i][0] = 1;
    }
    for(int i = 0; i < n; i++){
        v[0][i] = 1;
    }

    for(int i = 1; i < m ; i++ ){
        for (int j = 1; j < n ; j++ ){
            v[i][j] = v[i-1][j] + v[i][j-1];
        }
    }


    return v[m-1][n-1];
}


int maxProfit(vector<int>& prices) {
/*
    vector<int> v(prices.size(), 0);

    int max = 0;
    for(unsigned long i = 0; i < prices.size(); i++){
        for(int j = i; j >= 0 ; j --){

            int tmp = prices[i] - prices[j];
            if(tmp > max){
                max = tmp;
            } 

        }
    }
    cout << max << endl;

    return max;
*/

/*
    if(prices.size() == 0){
        return 0;
    }
    int max = 0;
    for(unsigned long i = 0 ; i < prices.size() - 1; i++){
        for(unsigned long j = i + 1; j  <prices.size();j++ ){
            int tmp_max = prices[j] - prices[i];
            if(tmp_max > max ){
                max = tmp_max;
            }
        }
    } 

    return max;
*/


    if(prices.size() == 0){
        return 0;
    }
    int max = 0;
    int min = prices[0];

    for(unsigned long i =1; i < prices.size(); i++ ){
        if(min > prices[i] ){
            min = prices[i];
        }
        if(max < prices[i] - min){
            max = prices[i] - min;
        }

    }
    return max;
}

void helper(vector<vector<int> > &result, vector<int> &v, int start, int k, int n){

    if(k == 0 && n == 0){
        result.push_back(v);
        return;
    }
    for (int i = start; i < 10; i ++ ){
        v.push_back(i);
        helper(result, v, start + 1,k -1  ,n - i);
        v.pop_back();
    }
}

vector<vector<int> > combinationSum3(int k, int n) {
        
    vector<vector<int> > result;

    vector<int> v; 
    helper(result, v, 1, k,n);
    return result;

}

vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > result; 
        sort(nums.begin(), nums.end());
        vector<int> v = nums;
        do{ 
            v =nums;
            result.push_back(v);

        }while(next_permutation(nums.begin(),nums.end()));
       
         return result;

}

void helper2(vector<vector<int> > &result, queue<int> &q, int n, int start, int end){
    if(q.empty()){
        return;
    }
           
    for(int i = start; i <= end ; i++ ){


        result[start][i] = q.front();

        q.pop();
    }



    for(int i = start+1; i <= end; i++){
        result[i][end] = q.front();

        q.pop();
    }


    for(int i = end - 1; i >=start; i-- ){
        result[end][i] = q.front();

        q.pop(); 
    }

    for(int i = end -1 ;  i > start;i-- ){
        result[i][start] = q.front();
        q.pop();
    }

    helper2(result,q, n - 2,start+1, end -1);


}
vector<vector<int>> generateMatrix(int n) {
    vector<vector<int> > result(n, vector<int>(n));  
    queue<int> q;
     for(int i = 1; i <=n*n; i++){
        q.push(i);
    } 

    helper2(result,q, n , 0, n-1);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return result;
}


int minPathSum(vector<vector<int>>& grid) {
    
    for(unsigned long i = 1; i < grid[0].size(); i++){
        grid[0][i] = grid[0][i-1] + grid[0][i];
    }

    for(unsigned long i = 1; i < grid.size(); i++){
        grid[i][0] = grid[i-1][0] + grid[i][0];
    }
    for(unsigned long i = 1; i < grid.size();i++){
        for(unsigned long j = 1; j < grid[0].size();j++){

            if(grid[i][j-1] > grid[i-1][j]){
                grid[i][j] = grid[i][j] + grid[i-1][j];
            }else{
                grid[i][j] = grid[i][j] + grid[i][j-1];
            }
        }
    }

    return grid[grid.size() - 1][grid[0].size() -1];
}

void sortColors(vector<int>& nums) {
        
    int count_0 = 0;
    int count_1 = 0;
    int count_2 = 0;
    vector<int> v;
    for(unsigned long i = 0; i < nums.size(); i++){

        if(nums[i] == 0){
            count_0 ++;
        }else if(nums[i] == 1){
            count_1 ++;
        }else{
            count_2 ++;
        }
    }
    
    while(count_0 != 0){
        v.push_back(0);
        count_0--;

    }
    while(count_1 != 0){
        v.push_back(1);
        count_1--;

    }
    while(count_2 != 0){
        v.push_back(2);
        count_2--;

    }

    for(unsigned long i =0 ; i < v.size(); i++){
        nums[i] = v[i];
    }
    return;

}



void rotate(vector<vector<int>>& matrix) {
    vector<vector<int> > v(matrix.size(), vector<int>(matrix.size()));
    int tmp = 0;
    for(int i = matrix[0].size()-1; i >= 0; i--){
        for(unsigned long j = 0; j < matrix.size(); j++){
            v[j][i] = matrix[tmp][j];
        }
        tmp++;
    }
   
    for(unsigned long i = 0; i < v.size(); i++){
        for(unsigned long j = 0; j < v[0].size();j++ ){
            matrix[i][j] = v[i][j];
        }
    }
}



int integerBreak(int n) {
    if(n == 2 )  return 1;
    if(n == 3 )  return 2;
    if(n == 4)  return 4;
    if(n == 5 )  return 6;
    if(n == 6 )  return 9;
    return 3*integerBreak(n-3);
}


bool searchMatrix(vector<vector<int> >& matrix, int target) {
    
    unsigned long i = 0;
    int j = matrix[0].size() - 1;    

    while(i < matrix.size() && j>= 0){
        if(matrix[i][j]  == target){
            return true;
        }

        if(matrix[i][j] < target){
            i++;
        }else{
            j--;
        }
    }
    return false;
}

struct TreeNode {
   int val;
    TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void helperRightSideView(TreeNode * root, unsigned long level, vector<int> &result){

    if(root == NULL) return;
    if( result.size() < level ) result.push_back(root->val);
    helperRightSideView(root -> right, level+1, result);
    helperRightSideView(root -> left, level+1, result);
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> result;

    helperRightSideView(root,1,result);

    return result;
}




string reverseString(string s) {
    int length = s.length();
    bool even = true;
    if(length%2 ){
        even = false;
    }
    
    if(even){   
        int end = length; 
        for(int i = 0; i < length/2; i++){
            char tmp = s[i];
            s[i] = s[end-1];
            s[end-1] = tmp;
            end --;
        }
        return s;
    }else{
        int end = length;
        for(int i = 0; i < (length - 1)/2; i++){
            char tmp = s[i];
            s[i] = s[end-1];
            s[end-1] = tmp;
            end --;
        }
        return s;
    }
}



void invertTree_helper(TreeNode * root){
    if(root -> left != NULL && root ->right != NULL){

        TreeNode *tmp = new TreeNode(root->left->val);
        tmp -> left = root -> left -> left;
        tmp -> right = root -> left -> right;
    
        root -> left = root -> right;
        root -> right = tmp;
    }
    if(root -> left !=NULL && root -> right == NULL){
        TreeNode *tmp = new TreeNode(root->left->val);
        tmp -> left = root -> left -> left;
        tmp -> right = root -> left -> right;

        root -> left = NULL;
        root -> right = tmp;
    }else if(root -> right !=NULL && root -> left == NULL){
        TreeNode *tmp = new TreeNode(root->right->val);
        tmp -> left = root -> right -> left;
        tmp -> right = root -> right -> right;

        root -> left = tmp;
        root -> right = NULL;
    }

    if(root -> left != NULL){
       invertTree_helper(root -> left); 
    }
    if(root -> right != NULL){
        invertTree_helper(root -> right);
    }
    return;
}

TreeNode* invertTree(TreeNode* root) {
    if(root == NULL){
        return root;
    }

    if(root -> left != NULL && root ->right != NULL){
        TreeNode *tmp = new TreeNode(root->left->val);
        tmp -> left = root -> left -> left;
        tmp -> right = root -> left -> right;

        root -> left = root -> right;
        root -> right = tmp;
    }

    if(root -> left !=NULL && root -> right == NULL){
        TreeNode *tmp = new TreeNode(root->left->val);
        tmp -> left = root -> left -> left;
        tmp -> right = root -> left -> right;

        root -> left = NULL;
        root -> right = tmp;
    }else if(root -> right !=NULL && root -> left == NULL){
        TreeNode *tmp = new TreeNode(root->right->val);
         tmp -> left = root -> right -> left;
        tmp -> right = root -> right -> right;

        root -> left = tmp;
        root -> right = NULL;
    }
    
    if(root -> left != NULL){
       invertTree_helper(root -> left); 
    }
    if(root -> right != NULL){
        invertTree_helper(root -> right);
    }
    return root;
}


vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> s1;
    unordered_set<int> s2;
    
    for(unsigned long i = 0; i < nums1.size(); i++){
        s1.insert(nums1[i]);
    }
    for(unsigned long i = 0; i < nums2.size(); i++){
        s2.insert(nums2[i]);
    } 
        vector<int> result;
    for(auto i = s2.begin(); i != s2.end(); i++){
        if(s1.find(*i) != s1.end()){
            result.push_back(*i);

        }
    }


    return result;
}


vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result;
    unordered_map<int ,int> m;
    for(unsigned long i = 0; i < nums1.size(); i++){
        if(m.find(nums1[i] )== m.end()){
            m[nums1[i]] = 1;
        }else{
            m[nums1[i]]++;
        }
    }

    for(unsigned long i = 0; i< nums2.size();i++){
        if(m.find(nums2[i]) != m.end() && m[nums2[i]] != 0){
            result.push_back(nums2[i]);
            m[nums2[i]]--;
        }
    }
    return result;

}

int lengthOfLIS(vector<int>& nums) {
    vector<int> result(nums.size(), 1);
    if(nums.size() == 1 ) return 1;
    if(nums.size() == 0) return 0;
    int min = 0;
    unsigned long i;
    for(i = 1; i < nums.size(); i++){
        if(nums[i] > nums[i-1]){
            min = nums[i-1];
            break;
        }
    }
    cout << "min: " << min << endl; 

    for(unsigned long j = i ; j<nums.size(); j++){

        if(nums[j] > min ){
            result[j] = result[j-1] + 1;
            min = nums[j];
        }else{
            result[j] = result[j-1];
        }

    }
     for(unsigned long k = 0; k < result.size(); k++){
        cout << result[k] <<  " ";

    }
    cout << endl;
    sort(result.begin(), result.end());

    for(unsigned long k = 0; k < result.size(); k++){
        cout << result[k] <<  " ";

    }
    cout << endl;

    return result[result.size()-1];
}

bool binary_search(unsigned long m, unsigned long beginning, unsigned long end, vector<vector<int>> &matrix,  int target, bool &result){
    
    if(end < beginning) return false;
    else if(end == beginning){
        if(matrix[m][beginning] == target){
            result = true;
            return true;
        } 
        else return false;
    }
    int mid = (end+beginning+1)/2;
    cout << "mid: " << mid << endl;
    cout << "8: " << matrix[m][mid] << "99: " << target << endl;
    if(matrix[m][mid] == target){
      //  cout << "10 ---- " << endl;
        result = true;
        return true;
     //   cout << "11 ------  " << endl;
    }
    else if(matrix[m][mid] < target){
      //  cout << "13 ------  " << endl;

        beginning = mid;
        binary_search(m,beginning,end,matrix,target,result);
    }
    else if(matrix[m][mid] > target){

        end = mid -1;
        binary_search(m,beginning,end,matrix,target,result);
    }
    return false;
}

bool searchMatrix_2nd(vector<vector<int>>& matrix, int target) {
    // 先确定哪一行 再做binary search 
    int m = -1; // 哪一个row 的 index
    bool exist = false;
    cout << "1111 " << endl; 
    for(unsigned long i = 0; i < matrix.size();i++){
        if(matrix[i][0] == target){
                cout << "2222 " << endl; 

            return true;
        }
        else if(matrix[i][0] < target){
                cout << "3333 " << endl; 
            exist = true;
            m = i;
        }

    }
        cout << "44444 " << endl; 
    if(exist == false) return false;
    cout << "5555 " << endl;
    cout << "m: " << m << endl;
    cout << matrix[m][matrix[0].size()-1] << endl;
    cout << "target: " << target << endl;
    if(matrix[m][matrix[0].size()-1] == target){
            cout << "6666 " << endl;

        return true;
    }
    else if(matrix[m][matrix[0].size()-1] < target){
            cout << "7777 " << endl;

        return false;
    }


    // 确定可能在 index 为 m 的这一行里 之后做 binary search
    unsigned long n = matrix[0].size()-1;

    cout << "m: " << m << endl;
    cout << "n: " << n << endl;
    bool result = false;
    binary_search(m,0,n,matrix,target,result);
    return result;
}

bool increasingTriplet(vector<int>& nums) {
    int a = INT_MAX;
    int b = INT_MAX;
    for(int x : nums){
        if(x <= a){
            a = x;
        }
        else if( x <= b){
            b = x;
        }
        else return true;
    }
    return false;
}

int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(),nums.end());
    int size = nums.size();
    return nums[size-k];
            
}

void setZeroes(vector<vector<int>>& matrix) {

    unordered_set<int> column;
    unordered_set<int> row;

    int m = matrix.size();
    int n = matrix[0].size();

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == 0){
                row.insert(i);
                column.insert(j);
            }
        }
    }

    for(auto itr = row.begin(); itr != row.end(); itr ++){
        for(int j = 0; j < n ; j++){
            matrix[*itr][j] = 0;
        }
    }

    for(auto itr = column.begin(); itr != column.end(); itr ++){
        for(int i = 0; i < m ; i++){
            matrix[i][*itr] = 0;
        }
    }

    return;

}

int findPeakElement(vector<int>& nums) {

    if(nums.size() == 1 ) return 0;
    int index = 0;
    for(unsigned long i = 1; i < nums.size(); i++){
        if(nums[i] > nums[i-1]){
            index = i;
        }else{
            break;
        }
    }
    return index;
}

int sumNumbers_helper(TreeNode *root, int result){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return result*10 + root -> val;
    }

    return sumNumbers_helper(root->left, result*10 + root->val) + sumNumbers_helper(root->right,result* 10 + root->val);

}
int sumNumbers(TreeNode* root) {
    int result = sumNumbers_helper(root, 0);
    return result;

}



int removeDuplicates(vector<int>& nums) {
    vector<int> tmp; 
    unordered_map<int,int> m;
        cout << "4444  " << endl;

    for(unsigned long i = 0; i < nums.size(); i++){
        if(m.find(nums[i]) != m.end()){
            m[nums[i]] = 2;
        }else{
            m[nums[i]] = 1;
        }
    }

    set<int> s;
    for(unsigned long i =0; i< nums.size(); i++){
        s.insert(nums[i]);
    }


    cout << "11111  " << endl;
    for(auto i = s.begin(); i != s.end(); i++){
        if(m[*i] == 1){
            tmp.push_back(*i);
        }else{
            tmp.push_back(*i);
            tmp.push_back(*i);
        }
    }
    cout << "22222 " << endl;

    int size = tmp.size();
    cout << "size: " << size << endl;
    cout << "tmp.size() " << tmp.size() << endl;
        cout << "33333 " << endl;

    for(unsigned long i = 0; i < tmp.size(); i++){
        nums[i] = tmp[i];
    }

    cout << "5555  " << endl;

    return size;
    
}

//priority_queue 的 练习 + make_pair, pair
vector<int> topKFrequent(vector<int>& nums, int k) {
    
    map<int, int> m;
    for(unsigned long i = 0; i < nums.size(); i++){
        if(m.find(nums[i]) == m.end()){
            m[nums[i]] = 1;
        }else{
            m[nums[i]]++;
        }
    }

    priority_queue< pair<int, int> > pq;
    vector<int> tmp;

    for(auto itr = m.begin(); itr != m.end(); itr ++ ){
      //  cout << "itr->first: " << itr->first << " " << itr -> second << endl; 
        pq.push(make_pair(itr->second, itr->first));
    }

    for(int i = 0; i < k; i++){
        tmp.push_back(pq.top().second);
       // cout << pq.top().second << endl;
        pq.pop();
    }
    return tmp;
}



//这个方法trick了leetcode， 其实应该用一个set 来储存所有出现过的sum,如果已经出现在了set里面，说明这个重复，然后就不会出现1，就return false;
bool isHappy(int n) {

    int tmp = n;
    int result = 0;
    while(tmp){

        result = (tmp%10)*(tmp%10) + result;
        tmp = tmp/10;
    }   
    result = result + tmp*tmp;
    tmp = result;

    int count = 50;
    while(result != 1){
        result = 0;
        while(tmp){

         result = (tmp%10)*(tmp%10) + result;
         tmp = tmp/10;
        }   
        result = result + tmp*tmp;
        tmp =result;

        count --;
        if(count == 0){
            return false;
        }
    }


    if(result == 1 )return true;
    else return false;
}

ListNode* swapPairs(ListNode* head) {
    if(head == NULL) return head;

    ListNode * first = head;
    if(first -> next == NULL) return head;
    ListNode * second = first -> next;
    
    bool exist = false;     
    do{
        exist = false;     
        int tmp = first -> val;
        

        first->val = second -> val;
        second -> val = tmp;
        cout << "first -> val: " << first -> val << endl;
        cout << "second -> val: " << second -> val << endl;
        if(second -> next != NULL && second-> next -> next != NULL){
            first = second -> next;
            second = second -> next -> next;
            exist = true;
        }
    }while(exist);

    return head;
}


string reverseVowels(string s) {
    unsigned long j = s.length() - 1;
    for(unsigned long i = 0 ; i< s.length(); i++){
        while((s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u' &&
            s[i] != 'A' && s[i] != 'E' && s[i] != 'I' && s[i] != 'O' && s[i] != 'U') && i < s.length()){
            i++;
        }
        while((s[j] != 'a' && s[j] != 'e' && s[j] != 'i' && s[j] != 'o' && s[j] != 'u' &&
            s[j] != 'A' && s[j] != 'E' && s[j] != 'I' && s[j] != 'O' && s[j] != 'U') && j > 0){
            j--;
        }

        cout << "i: " << i << endl;
        cout << "j: " << j << endl;  
        if(j > i){
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
        }else{
            break;
        }
        j--;
    }
    cout << s << endl;
    return s;
}

int hIndex(vector<int>& citations) {

    sort(citations.begin(), citations.end());
    unsigned long n = citations.size();
    int h;
    for(h = n; h > 0; h--){
        if(citations[n-h] >= h){
            break;
        }else{
            continue;
        }
    }
    return h; 
}


int hIndex2(vector<int>& citations) {

    int n = citations.size();
    if(n==0) return 0;
    int beginning = 0;
    int ending = n -1 ;
    int h;

    while(ending >= beginning){
        h = (ending + beginning )/2;
        cout << "h: " << h << endl;
        if(citations[h] >= n-h){
            ending = h -1 ;            
        }else{
            beginning = h + 1;
        }
    }

    return n-beginning; 
}


int search2(vector<int>& nums, int target) {
    
    int low = 0;
    int high = nums.size()-1;
    int mid = 0;

    while(low < high ){
        mid = (low + high)/2;
        if(nums[mid]== target) return mid;
        if(nums[mid] > nums[high]){
            if(nums[mid] > target && nums[low] <= target){
                high = mid;
            }else low = mid + 1;
        }
        else if(nums[mid] < nums[high]){
            if(nums[mid] < target && nums[high] >= target){
                low = mid + 1;
            }else{
                high = mid;
            }
        }
        else high --;
    }
    return nums[low] == target ? low : -1;

}

vector<vector<int>> subsets(vector<int>& nums){
    sort(nums.begin(), nums.end());
    vector<vector<int>> subs(1, vector<int>());

    for(unsigned long i = 0; i < nums.size(); i++){
        int n = subs.size();
        for(int j = 0; j < n; j++){
            subs.push_back(subs[j]);
            subs.back().push_back(nums[i]);
        }

    }
    return subs;
}

bool hasCycle(ListNode *head) {
    if(head == NULL) return false;
    unordered_set<ListNode*> s;
    s.insert(head);
    while(head){
        head = head -> next;
        if(s.find(head) == s.end()){
            s.insert(head);
        }else{
            return true;
        }
    }    

    return false;
}

ListNode *detectCycle(ListNode *head) {
    
    bool detect = false;
    detect = hasCycle(head);

    if(detect == true){
        unordered_set<ListNode*> s;
        s.insert(head);
        while(head){
            head = head -> next;
            if(s.find(head) == s.end()){
                s.insert(head);
            }else{
                return head;
            }
        }
        return NULL;    

    }else{
        return NULL;
    }
}


TreeNode *pre = NULL;
void flatten(TreeNode* root) {
    if(root == NULL) return; 
    flatten(root->left);
    flatten(root->right);
    root->right = pre;
    root->left =NULL;
    pre =root;
}

ListNode* rotateRight(ListNode* head, int k) {
    if(head == NULL) return NULL;
    int size =0;
    ListNode * tmp = head;
    while(tmp){
        size++;
        tmp = tmp -> next;
    }
    int k2 = k%size; 
    if(k2 == 0) return head;
    else{
        int j = size - k2;
        vector<int> v1;
        vector<int> v2;
        ListNode * tmp2 = head;
        while(j != 0){
            v1.push_back(tmp2->val);
            tmp2 = tmp2->next;
            j--;
        }

        while(k2 != 0){
            v2.push_back(tmp2->val);
            tmp2 = tmp2->next;
            k2 --;
        }

        for(int x : v1){
            v2.push_back(x);
        }

        ListNode *tmp3 = head;
        int i = 0;
        while(tmp3){
            tmp3->val = v2[i];
            i++;
            tmp3=tmp3->next;
        }
    }
    return head;

}

void combinationSum_helper(vector<vector<int>> & result, vector<int> &combine, vector<int> &candidates, int target, int begin ) {
    if(target == 0){
        result.push_back(combine);
        return;
    }

    for(unsigned long i = begin; i < candidates.size() && target >= candidates[i]; i++){
        combine.push_back(candidates[i]);
        combinationSum_helper(result, combine, candidates, target - candidates[i],i);
        combine.pop_back();
    }
}

//backtracking 的题目， 使用backtracking 模板
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> result;
    vector<int> combine; 
    combinationSum_helper(result, combine, candidates, target, 0);
    return result;

}


// 这个有更简单的方法 就是 创建2个ListNode, 一个 小于3， 一个 不小于， 一遍pass 原来的 ListNode, 最后 小于3的那个 next 指向 不小于3的head.
ListNode* partition(ListNode* head, int x) {
           if(head == NULL) return head;
    ListNode *cur = head;
    ListNode * new_head = NULL;
    while(cur){
       if(cur->val < x){
         new_head = new ListNode(cur->val);
         break;
       }else{
         cur = cur -> next;
       }
    }

    if(!cur){
        cout << "111" << endl;
    }
    ListNode * second = new_head;

    if(cur != NULL){
        while(cur->next){
            cur = cur->next;
            if(cur ->val < x){
                second -> next = new ListNode(cur -> val);
                second = second -> next;
            }else{
                continue;
        }
    }

    }

    

    cout << "222" << endl;

    if(second != NULL){
while(head){
        if(head -> val >= x){
            second -> next = new ListNode(head-> val);
            second = second -> next; 
            head = head-> next;
        }else{
            head = head -> next;
        }
    }
    }

    cout << "333" << endl;

    if(new_head != NULL){
        return new_head;
    }else return head;
    }


void postorder(vector<int> &res, TreeNode *root){
    if(root == NULL){
        return;
    }

    postorder(res,root -> left);
    postorder(res,root->right);
    res.push_back(root -> val);

}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    postorder(res,root);
    return res;        
}


//判断是否是 palindrome; 
// aba  aaabbb aaacbbb  abcc  aabb 
//初步判读 数每个char 的个数， 长度是偶数的 就每字母的都是 偶数   长度是odd， 就1个字母不是偶数
bool canPermutePalindrome(string s) {

    int length = s.length();
    if(length % 2 == 0){
        unordered_map<char, int> m;
        for(int i = 0; i < length; i++){
            if(m.find(s[i]) != m.end()){
                m[s[i]] ++;
            }else 
            {
                m[s[i]] = 1;
            }
        }

        for(int i = 0; i < length; i++){
            if(m[s[i]]%2 != 0){
                return false;
            }
        }
        return true;
    }
    else
    {
        unordered_map<char,int> m;
        for(int i = 0; i < length; i++){
            if(m.find(s[i]) != m.end()){
                m[s[i]] ++;
            }else 
            {
                m[s[i]] = 1;
            }
        }

        int count = 0;
        for(auto itr = m.begin(); itr != m.end(); itr++)
        {
            if(itr ->second %2 != 0){
                count ++;
            }
        }
        

        if(count == 1){
            return true;
        }else return false;
    } 


}


int shortestDistance(vector<string>& words, string word1, string word2) {

    int dis1 = -1;
    int dis2 = -1;
    int diff = 0;
    int min = -1;
    for(unsigned long i = 0; i < words.size();i++){

        if(words[i] == word1){
            dis1 = i;
        }
        if(words[i] == word2){
            dis2 = i;
        }
        if(dis1 != -1 && dis2 != -1){
            diff = abs(dis1 - dis2);
            if(min == -1){
                min = diff;
            }
        }
        if(diff < min){
            min = diff;
        }
    }
    return min;
}

struct Interval{
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
};

struct myclass{
    bool operator()(Interval a, Interval b){
        return a.start < b.start;
    }
}myobject;


bool canAttendMeetings(vector<Interval>& intervals) {
        
    sort(intervals.begin(), intervals.end(), myobject);
    for(unsigned long i = 1; i < intervals.size(); i++){
        if(intervals[i].start < intervals[i-1].end){
            return false;
        }   
    }
    return true;
}

vector<string> generatePossibleNextMoves(string s) {
        vector<string> result = {};
        if(s.length() == 0 ){
            return result;
        }    for(unsigned long i = 0; i < s.length() -1 ; i++){
        if(s[i] == '+' && s[i+1] == '+') {
            string tmp = s;
            tmp[i] = '-';
            tmp[i+1] = '-';
            result.push_back(tmp);
        }
    } 
    return result;
}

//"66811 11899"  
// 66811 8 or 1 11899
bool isStrobogrammatic(string num) {

    if(num.length()%2 == 0){
        string a = num.substr(0,num.length()/2);
        string b = num.substr(num.length()/2, num.length()/2);
        cout << a << endl;
        cout << b << endl; 

        for(unsigned long i = 0,j = b.length() -1; i < a.length(); i++, j--){
            if(a[i] == '6' && b[j] != '9'){
                return false;
            }else if(a[i] == '9' && b[j] != '6'){
                return false;
            }else if(a[i] == '8' && b[j] != '8'){
                return false;
            }else if(a[i] == '1' && b[j] != '1'){
                return false;
            }else if(a[i] == '0' && b[j] != '0'){
                return false;
            }else if(a[i] == '2' || a[i] == '3' ||a[i] == '4' ||a[i] == '5' ||a[i] == '7' ){
                return false;
            }else if(b[j] == '2' || b[j] == '3' ||b[j] == '4' ||b[j] == '5' ||b[j] == '7' ){
                return false;
            }
        }   
        cout << "dui" << endl;
        return true;
    }else{
        string a = num.substr(0,num.length()/2);
        string b = num.substr(num.length()/2+1, num.length()/2);
        cout << a << endl;
        cout << b << endl; 
        cout << num[num.length()/2] << endl;
        if(num[num.length()/2]!='1' && num[num.length()/2]!='0'&& num[num.length()/2]!='8' ){
            return false;
        }

        cout << "111" << endl;

        for(unsigned long i = 0,j = b.length() -1; i < a.length(); i++, j--){
            if(a[i] == '6' && b[j] != '9'){
                return false;
            }else if(a[i] == '9' && b[j] != '6'){
                return false;
            }else if(a[i] == '8' && b[j] != '8'){
                return false;
            }else if(a[i] == '1' && b[j] != '1'){
                return false;
            }else if(a[i] == '0' && b[j] != '0'){
                return false;
            }else if(a[i] == '2' || a[i] == '3' ||a[i] == '4' ||a[i] == '5' ||a[i] == '7' ){
                return false;
            }else if(b[j] == '2' || b[j] == '3' ||b[j] == '4' ||b[j] == '5' ||b[j] == '7' ){
                return false;
            }
        }   
        cout << "dui" << endl;
        return true;
    }
}


int maxSubArrayLen(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    m[0] = -1;
    int sum = 0;
    int maxLen = 0;
    for(unsigned long i = 0; i < nums.size(); i++){
        sum = sum + nums[i];
        if(m.count(sum) == 0){
            m[sum] = i;
        }
        if(m.count(sum - k)){
            maxLen = max(maxLen, int(i - m[sum-k]));
        }
    }

    return maxLen;

}



void preorderBST(TreeNode *root, vector<int> &nums){
    if(root == NULL) return;
    nums.push_back(root -> val);
    preorderBST(root -> left, nums);
    preorderBST(root -> right, nums);

}

int binary_search_min(vector<int> &nums, double target, double &diff, int &low, int &high, int &min, double min_diff){
    int mid = (high + low) / 2;
    diff = nums[mid] - target;
    cout << "low: " << low << endl;
    cout << "high: " << high << endl;
    cout << "mid: " << mid << endl;
    cout << "diff: " << diff << endl;
    cout << "min_diff: " << min_diff << endl;
    if(diff == 0.0){
        cout << "nums[mid] " << nums[mid] << endl;
        min = nums[mid];
        return min;
    }else if(diff > 0){
        cout << "1111" << endl;
        high = mid - 1;
        if(abs(diff) <= min_diff){
            cout << "4444" << endl;
            min_diff = abs(diff);
            min = nums[mid];
            
        }
        if(high >= low){
                  binary_search_min(nums,target,diff,low, high, min,min_diff);
  
        }
    }else if(diff < 0){
        cout << "333333" << endl;
        low = mid + 1;
        if(abs(diff) <= min_diff){
            cout << "2222" << endl;
            min_diff = abs(diff);
            min = nums[mid];
            cout << "min: " << min << endl;
        }
 if(high >= low){
                  binary_search_min(nums,target,diff,low, high, min,min_diff);
  
        }    }
    return min;

}
int closestValue(TreeNode* root, double target){
    vector<int> nums;
    preorderBST(root, nums);
    sort(nums.begin(), nums.end());
    
    for(int i : nums){
        cout << i << endl;
    }
    
    int low = 0;
    int high = nums.size() -1;
    int min = 0;
    double diff = 0.0;
    return binary_search_min(nums, target, diff, low, high, min, 1.79769e+308);
}



vector<vector<int>> levelOrderBottom(TreeNode* root) {

    queue<TreeNode*> q;
    vector<vector<int>> result;
    
    stack<vector<int>> s;

    if(root == NULL) return result;
    
    q.push(root);
    while(!q.empty()){
        vector<int> tmp;
        int size = q.size();
        cout << "size: " << size << endl;

        while(size != 0){
            if(q.front()-> left != NULL){
                q.push(q.front()->left);

            }
            
            if(q.front() -> right != NULL){
                 q.push(q.front()->right);

            }

        
            tmp.push_back(q.front() -> val);
            q.pop();
            size --;
        }

        s.push(tmp);
    }

    while(!s.empty()){
        result.push_back(s.top());
        s.pop();
    }
    return result;
}




vector<int> getRow(int rowIndex) {
    if(rowIndex == 0){
        vector<int> result = {1};
        return result;
    }
    if(rowIndex == 1){
        vector<int> result = {1,1};
        return result;
    }
    if(rowIndex == 2){
        vector<int> result = {1,2,1};
        return result;
    }
    int k = rowIndex;
    vector<int> tmp = {1,2,1};
    vector<int> result;
    while(k != 2){
        vector<int> next;
        next.push_back(1);
        for(unsigned long i = 0; i < tmp.size()-1;i++){
            next.push_back(tmp[i] + tmp[i+1]);
        }
        next.push_back(1);
        k--;
        tmp = next;
        result = next;
    }
    return result;
}


vector<vector<string>> groupStrings(vector<string>& strings) {

    vector<vector<string>> result;
   unordered_map<string, vector<string>> m;
   for(unsigned long i = 0; i < strings.size(); i++){
        string s = "";
        for(auto j : strings[i]){
            s += to_string(((j - strings[i][0]) + 26) % 26) + " ";  
        }

        if(m.find(s) == m.end()){
            vector<string> v; 
            v.push_back(strings[i]);
            m[s] = v;


        }else{
            m[s].push_back(strings[i]);
        }

   }

   for(auto i = m.begin(); i != m.end(); i++){
        sort(i->second.begin(), i->second.end());
        result.push_back(i->second);
   }
   return result;
}

int numWays(int n, int k) {
    if(n == 0){
        return 0;
    }else if(n == 1 ){
        return k;
    }
    else if(n == 2){
        return k * k;
    }
    vector<int> v;
    v.resize(n+1);

    v[0] = 0;
    v[1] = k;
    v[2] = k*k;
    for(int i = 3; i <= n; i++ ){
        v[i] = (k-1)*v[i-1] + (k-1)*v[i-2];
    }
    return v[n];


}


bool isValidSudoku(vector<vector<char>>& board) {
    int row = board.size();
    int column = board[0].size();
    bool result = true;

    //check each row 
    for(int i = 0; i < row; i++){
        unordered_set<char> s;
        for(int j = 0; j < column; j++){
            if(board[i][j] != '.'){
                if(s.find(board[i][j]) == s.end()){
                    s.insert(board[i][j]);
                }else{
                    result = false;
                    return false;
                }
            }
        }
    }

    //check each col
    for(int i = 0; i < column; i++){
        unordered_set<char> s;
        for(int j = 0; j < row; j++){
            if(board[j][i] != '.'){
                if(s.find(board[j][i]) == s.end()){
                    s.insert(board[j][i]);
                }else{
                    result = false;
                    return false;
                }
            }
        }
    }
    //check each box
    unordered_set<char> s1;
    for(int i = 0; i < 3; i ++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] != '.'){
                if(s1.find(board[i][j]) == s1.end()){
                    s1.insert(board[i][j]);
                }else{
                    result = false;
                    return false;
                }
            }
        }
    }


    unordered_set<char> s2;
    for(int i = 0; i < 3; i ++){
        for(int j = 3; j < 6; j++){
            if(board[i][j] != '.'){
                if(s2.find(board[i][j]) == s2.end()){
                    s2.insert(board[i][j]);
                }else{
                    result = false;
                    return false;
                }
            }
        }
    }


    unordered_set<char> s3;
    for(int i = 0; i < 3; i ++){
        for(int j = 6; j < 9; j++){
            if(board[i][j] != '.'){
                if(s3.find(board[i][j]) == s3.end()){
                    s3.insert(board[i][j]);
                }else{
                    result = false;
                    return false;
                }
            }
        }
    }

    // SSSSSSSSSSSSSSSS
    unordered_set<char> s4;
    for(int i = 3; i < 6; i ++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] != '.'){
                if(s4.find(board[i][j]) == s4.end()){
                    s4.insert(board[i][j]);
                }else{
                    result = false;
                    return false;
                }
            }
        }
    }


    unordered_set<char> s5;
    for(int i = 3; i < 6; i ++){
        for(int j = 3; j < 6; j++){
            if(board[i][j] != '.'){
                if(s5.find(board[i][j]) == s5.end()){
                    s5.insert(board[i][j]);
                }else{
                    result = false;
                    return false;
                }
            }
        }
    }


    unordered_set<char> s6;
    for(int i = 3; i < 6; i ++){
        for(int j = 6; j < 9; j++){
            if(board[i][j] != '.'){
                if(s6.find(board[i][j]) == s6.end()){
                    s6.insert(board[i][j]);
                }else{
                    result = false;
                    return false;
                }
            }
        }
    }

    ///////SSSS
    unordered_set<char> s7;
    for(int i = 6; i < 9; i ++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] != '.'){
                if(s7.find(board[i][j]) == s7.end()){
                    s7.insert(board[i][j]);
                }else{
                    result = false;
                    return false;
                }
            }
        }
    }


    unordered_set<char> s8;
    for(int i = 6; i < 9; i ++){
        for(int j = 3; j < 6; j++){
            if(board[i][j] != '.'){
                if(s8.find(board[i][j]) == s8.end()){
                    s8.insert(board[i][j]);
                }else{
                    result = false;
                    return false;
                }
            }
        }
    }


    unordered_set<char> s9;
    for(int i = 6; i < 9; i ++){
        for(int j = 6; j < 9; j++){
            if(board[i][j] != '.'){
                if(s9.find(board[i][j]) == s9.end()){
                    s9.insert(board[i][j]);
                }else{
                    result = false;
                    return false;
                }
            }
        }
    }
    return result;

}

int minDepth(TreeNode* root) {
    if(root == NULL){
        return 0;
    }
   
    queue<TreeNode*> q;
    q.push(root);
    int min = 1;
    while(!q.empty()){
        int size = q.size();
        
            while(size != 0){
                
                if(q.front()->left == NULL && q.front()->right == NULL){
                    return min;
                }
                if(q.front()->left !=NULL){
                    q.push(q.front()->left);
                }
                if(q.front() -> right != NULL){
                    q.push(q.front()->right);
                }
                q.pop();
                size --;
            }
            min = min + 1;

        }
    
    return min;
}

void binaryTreePaths_helper(TreeNode *root, vector<string> &result, string tmp){
    if(root -> left == NULL && root -> right == NULL){
        result.push_back(tmp);
        return;
    }
    if(root -> left){
        binaryTreePaths_helper(root -> left, result, tmp + "->" + to_string(root->left->val));
    }
    if(root -> right){
        binaryTreePaths_helper(root -> right, result, tmp + "->" + to_string(root->right->val));
    }
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> result;
    if(root == NULL){
        result.push_back("");
        return result;
    }
    string tmp = to_string(root->val);
    binaryTreePaths_helper(root, result, tmp);
    return result;

}

string addBinary(string a, string b) {
           string c = reverseString(a);
    string d = reverseString(b);
    while(c.length() > d.length()){
        d += '0';
    }

    while(c.length() < d.length()){
        c += '0';
    }
    cout << c << endl;
    cout << d << endl;

    string t = "";
    bool borrow = false;
    for(unsigned long i = 0; i < c.length()-1; i++){
        if(c[i] == '0' && d[i] == '1' && borrow == false){
            t += '1';
        }
        else if(c[i] == '1' && d[i] == '0' && borrow == false){
            t += '1';
        }
        else if(c[i] == '0' && d[i] == '1' && borrow == true){
            t += '0';
            borrow = true;
        }else if(c[i] == '1' && d[i] == '0' && borrow == true){
            t += '0';
            borrow = true;
        }else if(c[i] == '0' && d[i] == '0' && borrow == false){
            t += '0';
        }else if(c[i] == '0' && d[i] == '0' && borrow == true){
            t += '1';
            borrow = false;
        }else if(c[i] == '1' && d[i] == '1' && borrow == true){
            t += '1';
        }else if(c[i] == '1' && d[i] == '1' && borrow == false){
            t += '0';
            borrow = true;
        }
    }
   
   cout << "t: " << t << endl;
   cout << "borrow: " << borrow << endl;
   cout << "c.back(): " << c.back() << endl;
   cout << "d.back(): " << d.back() << endl;
        if(c.back() == '0' && d.back() == '1' && borrow == false){
            t += '1';
        }
        else if(c.back() == '1' && d.back() == '0' && borrow == false){
            t += '1';
        }
        else if(c.back() == '0' && d.back() == '1' && borrow == true){
            t += "01";
            cout << "222" << endl;
            
        }else if(c.back() == '1' && d.back() == '0' && borrow == true){
            t += "01";
                        cout << "222" << endl;

        }else if(c.back() == '0' && d.back() == '0' && borrow == false){
            t += '0';
        }else if(c.back() == '0' && d.back() == '0' && borrow == true){
            t += '1';
        }else if(c.back() == '1' && d.back() == '1' && borrow == true){
            t += "11";
        }else if(c.back() == '1' && d.back() == '1' && borrow == false){
            t += "01";
            borrow = true;
        }
   

    return reverseString(t);
}

int countPrimes(int n) {
    vector<bool> v(n, true);
    v[0] = false;
    v[1] = false;
    for(unsigned long i = 2; i < sqrt(n); i++){
        if(v[i]){
 for(int j = i * i; j < n; j += i ){
            v[j] = false;
        }
        }
       
    }

    return count(v.begin(), v.end(),true);
}



int reverse(int x) {
    cout << INT_MAX << endl;
         string s = to_string(x);
    cout << s << endl;
    bool hasNegative = false;
    if(s[0] == '-'){
        hasNegative = true;
    }

    if(hasNegative){
        int a = abs(x);
        s = to_string(a);
        string t = ""; 
        for(unsigned long i = s.length() -1; i != 0 ; i --){
            t += s[i];
        }
        t += s[0];
        string b = '-' + t;
        cout << b << endl;
        long long c = stoll(b);
        if(c < INT_MIN){
            return 0;
        }
        return stoi(b);
    }else{
        
        string t = ""; 
        for(unsigned long i = s.length() -1; i != 0 ; i --){
            t += s[i];
        }
        t += s[0];
        cout << t << endl;
        cout << "1111  " << endl;
        long long c = stoll(t);
        if(c > INT_MAX){
            return 0;
        }
        cout << "2222" << endl;
        return stoi(t);
    }
}





class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> &dictionary) {
        vector<string> abbr;
        for(unsigned long i = 0; i < dictionary.size(); i++ ){
            if(dictionary[i].length() <= 2){
                abbr.push_back(dictionary[i]);
            }
            else{
                int middle = dictionary[i].length() - 2;
                string tmp = dictionary[i][0] + to_string(middle) + dictionary[i].back();
                abbr.push_back(tmp);
            }
        }

        for(unsigned long i = 0; i < abbr.size(); i++){
            if(m.find(abbr[i]) == m.end()){
                m[abbr[i]] = dictionary[i];
            }else{
                if(m[abbr[i]] != dictionary[i]){
                    s.insert(abbr[i]);
                }
            }
        }     
    }

    bool isUnique(string word) {
        string new_word = "";
        if(word.length() <= 2){
            new_word = word;
        }else{
            new_word = word[0] + to_string(word.length() -2) + word.back();
        }
        cout << "new_word: " << new_word << endl;


        if(s.find(new_word) != s.end()){
            return false;
        }
        
        if(m.find(new_word) == m.end()){
            return true;
        }else{
            if(m[new_word] == word){
                return true;
            }else{
                return false;
            }
        }        
    }
private: 
    unordered_map<string,string> m;
    set<string> s;
};

void wiggleSort(vector<int>& nums) {
    
    for(unsigned long i = 1; i< nums.size(); i++){

        if(i%2 == 1 && nums[i] < nums[i-1]){
            int a = nums[i];
            nums[i] = nums[i-1];
            nums[i-1] = a;
        }else if(i%2 == 0 && nums[i] > nums[i-1]){
            int a = nums[i];
            nums[i] = nums[i-1];
            nums[i-1] = a;
        }
    }

}


vector<int> twoSum(vector<int>& numbers, int target) {
    
    int begin = 0;
    int end = numbers.size() - 1;

    while(begin < end){
        if(numbers[begin] + numbers[end] == target){
            vector<int> result = {begin+1, end+1};
            return result;
        }else if(numbers[begin]+numbers[end] < target ){
            begin ++;
        }else{
            end--;
        }
    } 
    vector<int> t;
    return t;
}


vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
    int A_row = A.size();
    int A_col = A[0].size();
   // int B_row = B.size();
    int B_col = B[0].size();

    vector<vector<int>> result(A_row, vector<int>(B_col));

    for(int i = 0; i < A_row;i++){
        
        for(int j = 0; j < A_col; j++){

            if(A[i][j] == 0){
                continue;
            }
            for(int k = 0; k < B_col; k++){
                if(B[j][k] == 0){
                    continue;
                }
                result[i][k] += A[i][j] * B[j][k];
            }


        }

    }

    return result;
}

int shortestWordDistance(vector<string>& words, string word1, string word2) {
    
    int pos1 = -1;
    int pos2 = -1;
    int min = INT_MAX;
    int diff = 0;
    int odd = 1;
    for(unsigned long i = 0; i < words.size(); i++){
            if(words[i] == word1 && (odd%2 == 1 || word1 != word2)){
                pos1 = i;
                odd ++;
            }
            else if(words[i] == word2){
                pos2 = i;
                odd ++;
            }
        
        
        if(pos1 != -1 && pos2 != -1){
            diff = abs(pos2 - pos1);
            if (diff < min){
                min = diff;
            }
        }

    }
    return min;       
} 


int minCost(vector<vector<int>>& costs) {
    if(costs.size() == 0) return 0;

    int red = costs[0][0];
    int green = costs[0][1];
    int blue = costs[0][2];

    for(unsigned long i = 1; i < costs.size(); i++){
        int red_i = costs[i][0] + min(green,blue);
        int green_i = costs[i][1] + min(red, blue);
        int blue_i = costs[i][2] + min(red, green);

        red = red_i;
        green = green_i;
        blue = blue_i;
    }
    return min(blue, min(red,green));
        
}

int find_helper(vector<int> &v, int i){
    if(v[i] == -1){
        return i;
    }
    return find_helper(v,v[i]);
}
int countComponents(int n, vector<pair<int, int>>& edges) {
    vector<int> v(n, -1);
    for(unsigned long i = 0; i< edges.size();i++){
        int x = find_helper(v,edges[i].first);
        int y = find_helper(v,edges[i].second);
        if(x != y){
            v[x] = y;
            n--;
        }
    }
    return n;
}


int minTotalDistance(vector<vector<int>>& grid) {
    vector<int> rows;
    vector<int> cols;
    if(grid.empty()){
        return 0;
    }
    for(unsigned long i = 0; i < grid.size();i++){
        for(unsigned long j = 0; j < grid[0].size();j++){
            if(grid[i][j]){
                rows.push_back(i);
                cols.push_back(j);
            }
        }
    }   

    sort(cols.begin(),cols.end());
    int row_median = rows[rows.size()/2];
    int col_median = cols[cols.size()/2];
    int result = 0;
    for(auto x : rows){
        result += abs(x - row_median);
    }
    for(auto x : cols){
        result += abs(x - col_median);
    }
    return result;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode * head = NULL;
    ListNode * prev = NULL;
    int carry = 0;
    while(l1 || l2){
        int a = l1 ? l1 -> val : 0;
        int b = l2 ? l2 -> val : 0;

        int sum =  a + b + carry;
        ListNode * cur;
        if(sum < 10){
            cur = new ListNode(sum);
            carry = 0;
        }else{
            cur = new ListNode(sum%10);
            carry = sum/10;
        }

        if(!head) head = cur;
        if(prev) prev -> next  = cur;
        prev = cur;

        l1 = l1 ? l1 -> next : NULL;
        l2 = l2 ? l2 -> next : NULL;
    }  
    if(carry > 0){
        prev -> next = new ListNode(carry);
    }

    return head;
}
/*
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int i = 0; 
    int j = nums1.size() -1;
    int x = 0;
    int y = nums2.size() -1;

    while(){

    }        
}

*/


int binarySearch_first(vector<int> &array, int target) {
        // write your code here
        if (array[0] == target) return 0;
        int low = 0;
        int high = array.size() -1;
        int mid;
        while (low <= high) {
            mid = (low + high) / 2;
            cout << "low: " << low  << endl;
            cout << "high : " << high << endl;
                        cout << "mid: " << mid << endl;

            if (array[mid] > target) {
                high = mid - 1;
            } else if (array[mid] < target) {
                low = mid + 1;
            } else if (array[mid] == target) {
                if (array[mid - 1] != target) {
                    return mid;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
}

int binarySearch_last(vector<int> &A, int target) {
        // write your code here
        if (A[A.size()-1] == target) return A.size()-1;
        int low = 0;
        int high = A.size() -1;
        int mid;
        while (low <= high) {
            mid = (low + high) / 2;
            cout << "low: " << low  << endl;
            cout << "high : " << high << endl;
            cout << "mid: " << mid << endl;
            if (A[mid] > target) {
                high = mid - 1;
            } else if (A[mid] < target) {
                low = mid + 1;
            } else if (A[mid] == target) {
                if (A[mid + 1] != target) {
                    return mid;
                } else {
                    low = mid + 1;
                }
            }
        }
        return -1;
}

int lastPosition(vector<int>& A, int target) {
        // write your code here
        if (A[A.size()-1] == target) return A.size()-1;
        int low = 0;
        int high = A.size() -1;
        int mid;
        while (low <= high) {
            mid = (low + high) / 2;
            cout << "low: " << low  << endl;
            cout << "high : " << high << endl;
            cout << "mid: " << mid << endl;
            if (A[mid] > target) {
                high = mid - 1;
            } else if (A[mid] < target) {
                low = mid + 1;
            } else if (A[mid] == target) {
                if (A[mid + 1] != target) {
                    return mid;
                } else {
                    low = mid + 1;
                }
            }
        }
        return -1;
}


int searchInsert(vector<int> &A, int target) {
    // write your code here
    int low = 0;
    int high = A.size() - 1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (A[mid] == target) {
            return mid;
        } else if (A[mid] > target) {
            high = mid - 1;
        } else if (A[mid] < target) {
            low = mid + 1;
        }
    }
    return low;
}

int findMin(vector<int> &num) {
        // write your code here
    int low = 0;
    int high = num.size() - 1;
    int mid;
    while (low < high) {
        mid = (low + high) / 2;
        cout << "mid: " << mid << endl;
        if(num[low] < num[high]) { 
            return num[low];
        } else if (num[low] > num[high] && num[mid] > num[low]) {
            low = mid + 1;
        } else if (num[low] >  num[high] && num[mid] <= num[low] ) {
            low++;
            high = mid;
        }
    }
    return num[low];
}

 int findPeak(vector<int> A) {
    int low = 0;
    int high = A.size() - 1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
     //   cout << "low: " << low << endl;
    //    cout << "high: " << high << endl;
     //   cout << "mid: " << mid << endl;
        if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1]) {
            return mid; 
        } else if (A[mid] < A[mid - 1]) {
            high = mid - 1;
        } else if (A[mid] < A[mid + 1]) {
            low  = mid + 1;
        }
    }
    return -1;    
}


int search(vector<int> &A, int target) {
    // write your code here
    int low = 0;
    int high = A.size() - 1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (A[mid] == target) {
            return mid;
        }
        if (A[mid] > A[high]) {
            if (A[mid] > target && A[low] <= target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else if (A[mid] < A[low]) {
            if (A[mid] < target && A[high] >= target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        } else {
            if (A[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
    }
    return -1;
}

vector<int> searchRange(vector<int> &A, int target) {
   vector<int> result; 
   vector<int>::iterator it;
   it = find(A.begin(),A.end(),target);
   int left;
   int right;
   if (it != A.end()) {
        left = it - A.begin();
   } else {
        left = -1;
   }
   right = -1;
   for(int i = A.size() - 1; i >= 0; i--){
        if(A[i] == target) {
            right = i;
            break;
        }
   }
   result = {left, right};
   return result;
}

vector<vector<int>> levelOrder(TreeNode *root) {
    // write your code here
    vector<vector<int>> result;
    queue<TreeNode*> q; 
    if (root == NULL) {
        return result;
    }
    cout << " 1111" << endl;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        vector<int> tmp;
        cout << "size: " << size << endl;

        while (size != 0) {
            if (q.front()->left != NULL) {
                q.push(q.front()->left);
            }
            if (q.front()->right!= NULL) {
                q.push(q.front()->right);
            }
            tmp.push_back(q.front()->val);
            q.pop();
            size--;
        }
        result.push_back(tmp);    
    }
    return result;
}

bool isValidBST_helper(TreeNode *root, long int max, long int min) {
    if (root == NULL) {
        return true;
    }
    if (root -> val >= max || root -> val <= min) {
        return false;
    }
    return isValidBST_helper(root->left, root->val, min) && isValidBST_helper(root->right, max, root->val);
}

bool isValidBST(TreeNode *root) {
    // write your code here
    return isValidBST_helper(root, LONG_MAX, LONG_MIN);
}

//leetcode
int max_helper(TreeNode *root, int &maxSum) {
    if (root == NULL) {
        return 0;
    }
    int left = max(0,max_helper(root->left,maxSum));
    int right = max(0,max_helper(root->right, maxSum));
    maxSum = max(maxSum, left + right + root->val);
    return max(left, right) + root->val;
}
int maxPathSum(TreeNode* root) {
     int maxSum = INT_MIN;
     max_helper(root, maxSum);
     return maxSum;       
}

//lintcode
int max_helper2(TreeNode *root, int maxSum) {
    if (root == NULL) {
        return 0;
    }
    int left = max_helper2(root->left,maxSum);
    int right = max_helper2(root->right, maxSum);
    maxSum = max(0, max(left, right)) + root->val + maxSum;
    return maxSum;
}
int maxPathSum2(TreeNode *root) {
        // Write your code here
    int maxSum = 0;
    maxSum = max_helper2(root, maxSum);
    return maxSum;   
}

void inorderSuccessor_helper(TreeNode *root, vector<TreeNode*> &container) {
    if (root == NULL) {
        return;
    }
    inorderSuccessor_helper(root->left, container);
    container.push_back(root);
    inorderSuccessor_helper(root->right, container);
}

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    vector<TreeNode*> container;
    inorderSuccessor_helper(root, container);
    for (unsigned long i = 0; i < container.size(); i++) {
        if (container[i] == p && i != container.size() - 1) {
            return container[i+1];
        } 
    }
    return NULL;
}


 TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
    // write your code here
    if (root == NULL) {
        return NULL;
    }

    if (root == A || root == B) {
        return root;
    } 
    TreeNode *left = lowestCommonAncestor(root->left, A, B);
    TreeNode *right = lowestCommonAncestor(root->right, A, B);
    if (left == NULL) {
        return right;
    } else if (right == NULL) {
        return left;
    } else {
        return root;
    }
}

void subsetsWithDup_helper(vector<int> &nums, vector<vector<int>> &result, vector<int> &tmp, unsigned long start) {
    result.push_back(tmp);
    for (unsigned long i = start; i < nums.size(); i++) {
        if (i == start || nums[i] != nums[i-1]) {
            tmp.push_back(nums[i]);
            subsetsWithDup_helper(nums, result, tmp, i + 1);
            tmp.pop_back();
        }
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> tmp;
    sort(nums.begin(), nums.end());
    subsetsWithDup_helper(nums, result, tmp, 0);
    return result;           
}

void permute2_helper(vector<vector<int>> &results, vector<int> nums, unsigned long start) {
    if (start == nums.size()) {
        results.push_back(nums);
        return;
    }
    for (unsigned long i = start; i < nums.size(); i++) {
        swap(nums[i], nums[start]);
        permute2_helper(results, nums, start + 1);
        swap(nums[i], nums[start]);
    }
}

// 不用next_permutation 做， 用backtracking 做
vector<vector<int> > permute2(vector<int> nums) {
    // write your code here
    vector<vector<int>> results;
    permute2_helper(results, nums, 0);
    return results;
       
}

//permutation 2  with duplicate values, 我就是在1的基础上 加一个set
void permute3_helper(vector<vector<int>> &results, vector<int> nums, unsigned long start, set <vector<int>> &s ) {
    if (start == nums.size()) {
        if (s.find(nums) == s.end()) {
            results.push_back(nums);
            s.insert(nums);
        }
        return;
    }
    for (unsigned long i = start; i < nums.size(); i++) {
        swap(nums[i], nums[start]);
        permute3_helper(results, nums, start + 1,s);
        swap(nums[i], nums[start]); 
    }
}

vector<vector<int> > permute3(vector<int> nums) {
    // write your code here
    vector<vector<int>> results;
    set< vector<int> > s;
    permute3_helper(results, nums, 0, s);
    return results;
       
}

int high_index_helper(vector<int> &A, int target){
    int low = 0;
    int high = A.size() - 1;

    if (A[high] == target) {
        return high;
    }
    high--;
    int mid;
    while (low <= high) {
        mid = (low + high ) / 2;
        if (A[mid] == target && A[mid + 1] != target) {
            return mid;
        } else if (A[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int low_index_helper(vector<int> &A, int target) {
    int low = 0;
    if (A[low] == target) {
        return low;
    }
    low++;
    int high = A.size() - 1;
    int mid; 
    while (low < high) {
        mid = (low + high) / 2;
        cout << "low: " << low << "   high: " << high << endl;
        cout << "mid: " << mid << endl;
        if (A[mid] == target && A[mid - 1] != target) {
            return mid;
        } else if (A[mid] >= target) {
            high = mid ;
        } else {
            low = mid - 1;
        }
    }
    return -1;   
}
int totalOccurrence(vector<int>& A, int target) {
    if (A.size() == 0) {
        return 0;
    }
    // Write your code here
    int high_index = -1;
    int low_index = -1;
    high_index = high_index_helper(A, target);
    low_index = low_index_helper(A, target);
    cout << "high_index: " << high_index << endl;
    cout << "low_index: " << low_index << endl;
    if (high_index == low_index && high_index == -1) {
        return 0;
    } else if (high_index == low_index) {
        return 1;
    } else {
        return high_index - low_index + 1;
    }
}


int closestNumber_helper(vector<int> &A, int target, int min) {
    int low = 0;
    int high = A.size() - 1;
    int mid;
    int diff;
    int index;
    while (low <= high) {
        mid = (low + high) / 2;
        if (A[mid] == target) {
            return mid;
        } else if (A[mid] < target) {
            diff = target - A[mid];
            if (diff < min) {
                min = diff;
                index = mid;
            }
            low = mid + 1;
        } else {
            diff = A[mid] - target;
            if (diff < min) {
                min = diff;
                index = mid;
            }
            high = mid - 1;
        }
    }
    return index;
}

int closestNumber(vector<int>& A, int target) {
    // Write your code here
    int index = -1;
    int min = INT_MAX;
    index = closestNumber_helper(A, target, min);
    return index;
}



vector<int> kClosestNumbers(vector<int>& A, int target, int k) {
    // Write your code here
    vector<int> results;
    if (k == 0) {
        return results;
    }
    int index_cloest = closestNumber(A, target);
    int size = A.size();
    cout << "index_cloest: " << index_cloest << endl;
    if (index_cloest == 0) {
        k--;
        results.push_back(A[0]);
        while (k != 0) {
            results.push_back(A[++index_cloest]);
            k--;
        }
        return results;
    } else if (index_cloest == (size - 1)) {
        k--;
        results.push_back(A[index_cloest]);
        while (k != 0) {
            results.push_back(A[--index_cloest]);
            k--;
        }
        return results;
    } else {
        results.push_back(A[index_cloest]);
        k--;
        int i_left = 1;
        int i_right = 1;
        //cout << "k: " << k << endl;
       //cout << "index_cloest: " << index_cloest << endl;
        while (k != 0) {
            if ((index_cloest - i_left) >= 0 && (index_cloest + i_right) <= ( size - 1)) {
                cout << "k: " << k << endl;
                int diff_left = abs(target - A[index_cloest - i_left]);
                int diff_right = abs(target- A[index_cloest + i_right]);
                if (diff_left == diff_right) {
                    results.push_back(A[index_cloest - i_left]);
                    i_left++;
                    k--;
                    if (k != 0 ) {
                        results.push_back(A[index_cloest + i_right]);
                        i_right++;
                        k--;
                    }
                } else if (diff_left > diff_right) {
                    results.push_back(A[index_cloest + i_right]);
                    i_right++;
                    k--;
                    /*
                    if (k != 0 ) {
                        results.push_back(A[index_cloest - i_left]);
                        i_left++;
                        k--;
                    }
                    */
                } else if (diff_left < diff_right) {
                    results.push_back(A[index_cloest - i_left]);
                    i_left++;
                    k--;
                    /*
                    if (k != 0 ) {
                        results.push_back(A[index_cloest + i_right]);
                        i_right++;
                        k--;
                    }
                    */
                }
            } else if ((index_cloest - i_left) < 0 && (index_cloest + i_right) > (size - 1)) {
                return results;
            } else if ((index_cloest - i_left) < 0) {
                while (k != 0) {
                    results.push_back(A[index_cloest + i_right]);
                    i_right++;
                    k--;
                    if ((index_cloest + i_right) > (size - 1)) {
                        return results;
                    }
                }
            } else if ((index_cloest + i_right) > (size - 1)) {
                   while (k != 0) {
                    results.push_back(A[index_cloest - i_left]);
                    i_left++;
                    k--;
                    if ((index_cloest - i_left) < 0) {
                        return results;
                    }
                } 
            }           
        }
        return results;
    }
}

bool woodCut_helper(vector<int> L, int k, int mid) {
    int sum = 0;
    for (auto x : L) {
        sum += x/mid;
    }
    if (sum >= k) {
        return true;
    } else {
        return false;
    }
}

int woodCut(vector<int> L, int k) {
    // write your code here
    if (L.size() == 0 || k == 0) {
        return 0;
    }
    int low = 0;
    int high = INT_MAX;
    int mid;
    while (low + 1 < high) {
        mid = (low + high) / 2;
        cout << "mid: " << endl;
        if (woodCut_helper(L, k, mid)) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return mid;
}

int findMin2(vector<int> &num) {
    int low = 0;
    int high = num.size() - 1;
    int mid;
    while (low < high) {
        mid = low + (high - low) / 2;
        if (num[mid] < num[high]) {
            high = mid;
        } else if (num[mid] > num[high]) {
            low = mid + 1;
        } else {
            high--;
        }
    }
    return num[low];
}

bool searchWithDuplicate(vector<int> &A, int target) {
    if (A.size() == 0) {
        return false; 
    }
    // write your code here
    int low = 0;
    int high = A.size() - 1;
    int mid;
    while (low < high) {
        mid = low + (high - low) / 2;
        cout << "low: " << low << endl;
        cout << "high: " << high << endl;
        cout << "mid: " << mid << endl;
        if (A[mid] == target) {
            return true;
        } else if (A[mid] < A[high]) {
            if (A[mid] < target && target <= A[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        } else if (A[mid] > A[high]) {
            if (target >= A[low] && A[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {
            high--;
        }
    }
    if (A[low] == target) {
        return true;
    }
    return false;
}

int searchMatrix2(vector<vector<int> > &matrix, int target) {
    // write your code here
    if (matrix.size() == 0) {
        return 0;
    }
    int m;
    int size_row = matrix.size();
    int size_col = matrix[0].size();
    int n;
    for (int i = 0; i < size_row; i++) {
        if (matrix[i][0] > target) {
            break;
        } else {
            m = i;
        }
    }
    for (int i = 0; i < size_col; i++) {
        if (matrix[0][i] > target) {
            break;
        } else {
            n = i;
        }
    }
    cout << "m: " << m << endl;
    cout << "n: " << n << endl;
    int count = 0; 
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (matrix[i][j] == target) {
                count++;
            } else if (matrix[i][j] > target) {
                break;
            }
        }
    }
    return count;
}

void traverse_binary_tree(vector<vector<int>> &tree, vector<int> &tmp, TreeNode *root, int target, int sum) {
    if (root == NULL) {
        return;
    }
    tmp.push_back(root->val);
    sum += root->val;
    if (root->left == NULL && root->right == NULL && sum == target) {
        tree.push_back(tmp);
    }
    traverse_binary_tree(tree, tmp, root->left, target, sum);
    traverse_binary_tree(tree, tmp, root->right, target, sum);
    sum -= root->val;
    tmp.pop_back();
    
}

vector<vector<int>> binaryTreePathSum(TreeNode *root, int target) {
    // Write your code here
    vector<vector<int>> tree;
    vector<int> tmp;
    traverse_binary_tree(tree, tmp, root, target,0);
    return tree;
}

bool identical(TreeNode *a, TreeNode *b) {
    if (a == NULL && b == NULL) {
        return true;
    }
    if (a == NULL && b != NULL) {
        return false;
    } else if (a != NULL && b == NULL) {
        return false;
    } else {
        if (a->val != b->val) {
            return false;
        } else {
            return identical(a->left, b->left) &&  identical(a->right, b->right);
        }
    }
}

void tweak_back(TreeNode *tmp) {
    if (tmp == NULL) {
        return;
    }
    if (tmp->left != NULL && tmp->right != NULL ) {
        if (tmp->left->val > tmp->right->val) {
            swap(tmp->left, tmp->right);
        }
    } else if (tmp->left == NULL && tmp->right != NULL) {
        swap(tmp->left, tmp->right);
    }
    tweak_back(tmp->left);
    tweak_back(tmp->right);
}

bool isTweakedIdentical(TreeNode* a, TreeNode* b) {
    // Write your code here
    tweak_back(a);
    tweak_back(b);
    return identical(a, b);
}

void isSymmetric_inorder(TreeNode *root, vector<int> &result){
    if (root == NULL) {
        result.push_back(-1);
        return;
    }
    if (root->left == NULL && root->right == NULL ){
        result.push_back(root->val);
        return;
    }
    isSymmetric_inorder(root->left, result);
    result.push_back(root->val);
    isSymmetric_inorder(root->right, result);
}

bool isSymmetric(TreeNode* root) {
    // Write your code here
    if (root == NULL) {
        return true;
    }
    vector<int> result;
    isSymmetric_inorder(root, result);
    if (result.size() % 2 == 0) {
        return false;
    }
    int size = result.size();
    cout << "size: " << size << endl;
    int j = size - 1;
    for (int i = 0; i < size/2; i++) {
        if (result[i] != result[j]) {
            return false;
        }
        j--;
    }
    if (result[j] != root->val) {
        return false;
    }
    return true;
}

bool isComplete_helper(TreeNode *root, int i, int count) {
    if (root == NULL) {
        return true;
    }
    if (i >= count) {
        return false;
    }
    return isComplete_helper(root->left, 2*i + 1, count) && isComplete_helper(root->right, 2*i + 2, count);
   
}

int count_nodes(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + count_nodes(root->left) + count_nodes(root->right); 
}

bool isComplete(TreeNode* root) {
    // Write your code here
    int num_nodes = count_nodes(root);
    return isComplete_helper(root, 0, num_nodes);
}


int minDepth2(TreeNode *root) {
    // write your code here
    queue<TreeNode*> q;
    if (root == NULL) {
        return 0;
    }
    int min = 1;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        while (size != 0) {
            size--;
            if (q.front()->left == NULL && q.front()->right == NULL ) {
                return min;
            }
            if (q.front()->left != NULL ) {
                q.push(q.front()->left);
            }
            if (q.front()->right != NULL) {
                q.push(q.front()->right);
            }
            q.pop();
        }
        min++;
    }

    return min;      
}

void insert_helper(TreeNode *root, TreeNode *node) {

    if (root->val > node->val) {
        if (root->left == NULL) {
            root->left = node;
        } else {
            insert_helper(root->left, node);
        }
    } else if (root->val < node->val) {
        if (root->right == NULL) {
            root->right = node;
        } else {
            insert_helper(root->right, node);
        }
    }
}

TreeNode* insertNode(TreeNode* root, TreeNode* node) {
    // write your code here
    if (root == NULL) {
        return node;
    }
    insert_helper(root, node);
    return root;
}

TreeNode *build(vector<int> &preorder, vector<int> &inorder, int preorder_start, int preorder_end, int inorder_start, int inorder_end) {
    if (preorder_start > preorder_end) {
        return NULL;
    }
    TreeNode *node = new TreeNode(preorder[preorder_start]);
    int pos = -1;
   cout << "11111" << endl;
    for (int i = inorder_start; i <= inorder_end; i++) {
        if (inorder[i] == node->val) {
            pos = i;
            break;
        }
    }
   cout << "2222" << endl;
    node->left = build(preorder, inorder, preorder_start + 1, 
        preorder_start + pos - inorder_start, inorder_start, pos - 1);
    node->right = build(preorder, inorder, preorder_end - inorder_end + pos + 1, 
        preorder_end, pos + 1, inorder_end);
    return node;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.size() == 0) {
        return NULL;
    }
    return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
}

TreeNode *buildTree_inorder_postorder_helper(vector<int> &inorder, vector<int> &postorder, int inorder_start, int inorder_end, int postorder_start, int postorder_end) {
    if (inorder_start > inorder_end) {
        return NULL;
    }
    TreeNode *node = new TreeNode(postorder[postorder_end]);
    int pos = -1;
    for (int i = inorder_start; i <= inorder_end; i++) {
        if (inorder[i] == node->val ){
            pos = i; 
            break;
        }
    }
    node->left = buildTree_inorder_postorder_helper(inorder, postorder,
        inorder_start, pos - 1, postorder_start, postorder_start + pos -inorder_start - 1);
    node->right = buildTree_inorder_postorder_helper(inorder, postorder,
        pos + 1, inorder_end, postorder_start + pos - inorder_start, postorder_end - 1);
    return node;
}

TreeNode *buildTree_inorder_postorder(vector<int> &inorder, vector<int> &postorder) {
    // write your code here
    return buildTree_inorder_postorder_helper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
}

vector<vector<int>> levelOrderBottom_lintcode(TreeNode *root) {
    // write your code here
    vector<vector<int>> results;
    if (root == NULL) {
        return results;
    } 
    queue<TreeNode*> q;
    stack<vector<int>> s;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        vector<int> level;
        while (size != 0) {
            level.push_back(q.front()->val);
            if (q.front()->left != NULL){
                q.push(q.front()->left);
            }
            if (q.front()->right != NULL) {
                q.push(q.front()->right);
            }
            q.pop();
            size--;
        }
        s.push(level);
    }
    while (!s.empty()) {
        results.push_back(s.top());
        s.pop();
    }
    return results;
}

vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    // write your code here
    vector<vector<int>> results;
    if (root == NULL) {
        return results;
    }
    queue<TreeNode*> q;
    q.push(root);
    int odd = 1;
    while (!q.empty()) {

        int size = q.size();
        vector<int> level;
        while (size != 0) {
            level.push_back(q.front()->val);
            if (q.front()->left != NULL) {
                q.push(q.front()->left);
            }
            if (q.front()->right != NULL) {
                q.push(q.front()->right);
            }
            q.pop();
            size--;
        }
        if (odd%2 == 1) {
            results.push_back(level);
            odd++;
        } else {
            reverse(level.begin(), level.end());
            results.push_back(level);
            odd++;
        }
    }
    return results;
}

void searchRange_helper(TreeNode *root, vector<int> &nums, int k1, int k2){
    if (root == NULL) {
        return;
    }
    if (root->val <= k2 && root->val >= k1) {
        nums.push_back(root->val);
    }
    if (root->val > k2) {
        searchRange_helper(root->left, nums, k1, k2);
    } else if (root->val < k1) {
        searchRange_helper(root->right, nums, k1, k2);
    } else {
        searchRange_helper(root->left, nums, k1, k2);
        searchRange_helper(root->right, nums, k1, k2);
    }
    return;
}

vector<int> searchRange(TreeNode* root, int k1, int k2) {
    // write your code here
    vector<int> nums; 
    searchRange_helper(root, nums, k1, k2);
    sort(nums.begin(), nums.end());
    return nums; 
}

string preorder_serialize(TreeNode *root, string &preorder_string) {
    if (root == NULL) {
        return preorder_string;
    }
    preorder_string += to_string(root->val);
    preorder_string += ",";
    preorder_serialize(root->left, preorder_string);
    preorder_serialize(root->right, preorder_string);
    return preorder_string;
}

string inorder_serialize(TreeNode *root, string &inorder_string) {
    if (root == NULL) {
        return inorder_string;
    }
    inorder_serialize(root->left, inorder_string);
    inorder_string += to_string(root->val);
    inorder_string += ",";
    inorder_serialize(root->right, inorder_string);
    return inorder_string;
}

string serialize(TreeNode *root) {
    // write your code here
    if (root == NULL) {
        return "";
    }
    string preorder_string = "";
    string inorder_string = "";
    preorder_string = preorder_serialize(root, preorder_string);
    preorder_string += '#';
    inorder_string = inorder_serialize(root, inorder_string);
    string data = preorder_string + inorder_string; 
    return data;
}

TreeNode *deserialize(string data) {
    // write your code here
    if (data == "") {
        return NULL;
    }
    vector<int> preorder; 
    vector<int> inorder;
    int size = data.size();
    int j = -1;
    string tmp = "";
    for (int i = 0; i < size; i++) {    
        if (data[i] == '#') {
            j = i;
            break;
        } else if (data[i] == ',') {
            preorder.push_back(atoi(tmp.c_str()));
            tmp = "";
            continue;
        } else {
            tmp += data[i];
        }
    }
    string tmp2 = "";
    for (j = j + 1; j < size; j++) {
        if (data[j] == ',') {
            inorder.push_back(atoi(tmp.c_str()));
            tmp = "";
            continue;
        } else {
            tmp += data[j];
        }
    }
    for(auto x : preorder){
        cout << x << " ";
    }
    cout << endl;
    for(auto x : inorder){
        cout << x << " ";
    }
    cout << endl;
    return buildTree(preorder, inorder);
}

int uniquePaths_lintcode(int m, int n) {
    // wirte your code higere
    vector<vector<int>> results(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0) {
                results[0][j] = 1;
            } else {
                if (j == 0) {
                    results[i][0] = 1;
                    continue;
                }
                results[i][j] = results[i-1][j] + results[i][j-1];
            }
        }
    }
    return results[m-1][n-1];
}

//先建立一个大小一样的 matrix, 如果是obstacle 位置是0  别的都一样
int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    // write your code here
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    cout << "m: " << m << endl;
    cout << "n: " << n << endl;
    vector<vector<int>> results(m, vector<int>(n));
    int pos = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (obstacleGrid[0][i] == 1){
            results[0][i] = 0;
            pos = i;
        } else {
            if (i > pos) {
                results[0][i] = 0;
            } else {
                results[0][i] = 1;
            }
        }
    }
    int pos2 = INT_MAX;
    for (int i = 0; i < m; i++) {
        if (obstacleGrid[i][0] == 1){
            results[i][0] = 0;
            pos2 = i;
        } else {
            if (i > pos2) {
                results[i][0] = 0;
            } else {
                results[i][0] = 1;
            }
        }
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[i][j] == 1) {
                results[i][j] = 0;
            } else {
                results[i][j] = results[i-1][j] + results[i][j-1];
            }
        }
    }
    return results[m-1][n-1];
}

int minPathSum_lintcode(vector<vector<int> > &grid) {
    // write your code here
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> results(m, vector<int>(n));
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            results[0][i] = grid[0][i];
        } else {
            results[0][i] = grid[0][i] + results[0][i - 1];
        }
    }
    for (int i = 0; i < m; i++) {
        if (i == 0) {
            continue;
        } else {
            results[i][0] = results[i - 1][0] + grid[i][0];
        }
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            results[i][j] = min(results[i][j - 1], results[i - 1][j]) + grid[i][j];
        }
    }
    return results[m - 1][n - 1];
}

// 1. vector vector 三角形
int minimumTotal(vector<vector<int> > &triangle) {
    // write your code here
    int m = triangle.size();
    int n = triangle[m - 1].size();
    vector<vector<int>> results(m, vector<int>(n));
    vector<vector<int>> container(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (unsigned long j = 0; j < triangle[i].size(); j++) {
            container[i][j] = triangle[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        if (i == 0) {
            results[i][0] = container[i][0];
        } else {
            results[i][0] = results[i-1][0] + container[i][0];
        } 
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == i) {
                results[i][j] = container[i][j] + results[i - 1][j - 1];
            } else {
                results[i][j] = min(results[i-1][j], results[i-1][j-1]) + container[i][j];
            }
        }
    }
    int min = INT_MAX;
    for (auto x : results[m - 1]) {
        if (x < min) {
            min = x;
        }
    }
    return min;
}

bool canJump(vector<int>& nums) {
    int n = nums.size();
    int maxCover = 0;
    for (int i = 0; i < n && i <= maxCover; i++){
        if (nums[i] + i > maxCover) {
            maxCover = nums[i] + i;
        }
        if (maxCover >= n - 1) {
            return true;
        }
    }
    return false;
}
/*
int jump(vector<int> &nums) {
    int size = nums.size();
    vector<int> tmp(size, -1);
    if (size == 0) {
        return 0;
    }
    if (size == 1) {
        return 0;
    }
    tmp[0] = 1;
    int count = 1;
    for (int i = 0; i < size; i++) {
        int reachable_steps = nums[i];
        cout << "reachable_steps: " << reachable_steps << endl;
        for (int j = 1; j <= reachable_steps && i + j < size; j++) {
            if (tmp[i + j] < count && tmp[i + j] != -1) {
                cout << "i + j  1: " << i + j << endl;
                cout << "count: " << count << endl;
                continue;
            } else if (tmp[i + j] == -1) {
                
                if (i == 0) {
                    cout << "i + j  2-1: " << i + j << endl;
                    cout << "count: " << tmp[i] << endl;
                    tmp[i + j] = tmp[i] ;

                } else {
                    
                    cout << "i + j  2-2: " << i + j << endl;
                    cout << "count: " << tmp[i] + 1 << endl;
                    tmp[i + j] = tmp[i] + 1;

                }
            } else {
                tmp[i + j] = count;
                cout << "i + j  3: " << i + j << endl;
                cout << "count: " << count << endl;
            }
        }
        if (tmp[size - 1] != -1) {
            return tmp[size - 1];
        }
        count++;
    }
    return -1;
}
*/

int longestIncreasingSubsequence(vector<int> nums) {
    // write your code here
    int size = nums.size();
    if (size == 0) {
        return 0;
    }
    if (size == 1) {
        return 1;
    }
    vector<int> tmp(size, 1);
    for (int i = 1; i < size; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] <= nums[i]) {
                if (tmp[j] + 1 > tmp[i]) {
                    tmp[i] = tmp[j] + 1;
                }
            }
        }
    }
    int max = INT_MIN;
    for (auto x : tmp) {
        if (x > max) {
            max = x;
        }
    } 
    return max;
}

bool wordBreak(string s, unordered_set<string> &dict) {
    // write your code here
    vector<bool> result (s.length() + 1, false);
    result[0] = true;
    for (unsigned long i = 0; i < s.length(); i++) {
        for (int j = i; j >= 0; j--) {
            if (result[j] && dict.count(s.substr(j,i-j+1))!=0) {
                result[i + 1] = true;
                break;
            }
        }
    }
    return result[s.size()];
}

bool isPalindromo(string s, int start, int end) {
    while (start <= end) {
        if (s[start++] != s[end--]) {
            return false;
        }
    }
    return true;
}

void dfs(int index, string s, vector<string> &path, vector<vector<string>> &results) {
    int tmp = s.size();
    if (index == tmp) {
        results.push_back(path);
        return;
    }
    for (int i = index; i < tmp; i++) {
        if (isPalindromo(s, index, i)) {
            path.push_back(s.substr(index, i - index + 1));
            dfs(i+1, s, path, results);
            path.pop_back();
        }
        
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> results; 
    vector<string> path;
    if (s.empty()) {
        return results;
    }        
    dfs(0, s, path, results);
    return results;
}

//2D vector vector
int longestCommonSubsequence(string A, string B) {
    // write your code here
    int size_A = A.length();
    int size_B = B.length();
    if (size_A == 0 || size_B == 0) {
        return 0;
    }
    vector<vector<int>> results(size_A + 1, vector<int>(size_B + 1));
   // cout << results.size() << endl;
    //cout << results[0].size() << endl;
    for (int i = 0; i < size_A + 1; i++) {
        results[i][0] = 0;
    }
    for (int i = 0; i < size_B + 1; i++) {
        results[0][i] = 0; 
    }
    for (int i = 1; i < size_A + 1; i++) {
        for (int j = 1; j < size_B + 1; j++) {
            if (A[i-1] != B[j-1]) {
                results[i][j] = max(results[i-1][j], results[i][j-1]);
            } else if (A[i-1] == B[j-1]) {
                results[i][j] = max(max(results[i-1][j], results[i][j-1]), results[i-1][j-1] + 1);
            }
        }
    }
 //   cout << "size_A: " << size_A << endl;
  //  cout << "size_B: " << size_B << endl;
    return results[size_A][size_B];
}

int minDistance(string word1, string word2) {
    // write your code here
    int size_word1 = word1.length();
    int size_word2 = word2.length();
    if (size_word1 == 0) {
        return size_word2;
    } else if (size_word2 == 0) {
        return size_word1;
    }
    vector<vector<int>> results(size_word1 + 1, vector<int>(size_word2 + 1));
    for (int i = 0; i < size_word1 + 1; i++) {
        results[i][0] = i;
    }
    for (int i = 0; i < size_word2 + 1; i++) {
        results[0][i] = i;
    }
    for (int i = 1; i < size_word1 + 1; i++) {
        for (int j = 1; j < size_word2 + 1; j++) {
            if (word1[i-1] == word2[j-1]) {
                results[i][j] = min(min(results[i-1][j] + 1, results[i][j-1] + 1), results[i-1][j-1]);
            } else if (word1[i-1] != word2[j-1]) {
                results[i][j] = min(min(results[i-1][j] + 1, results[i][j-1] + 1), results[i-1][j-1] + 1);
            }
        }
    }
    return results[size_word1][size_word2];
}

int numDistinct(string &S, string &T) {
    // write your code here
    int size_S = S.length();
    int size_T = T.length();
    if (size_T == 0) {
        return 1;
    } else if (size_S == 0) {
        return 0;
    }
    vector<vector<int>> results(size_S + 1, vector<int>(size_T + 1));
    for (int i = 0; i < size_S + 1; i++) {
        results[i][0] = 1;
    }
    for (int i = 1; i < size_T + 1; i++) {
        results[0][i] = 0;
    }
    for (int i = 1; i < size_S + 1; i++) {
        for (int j = 1; j < size_T + 1; j++) {
            if (S[i-1] == T[j-1]) {
                results[i][j] = results[i-1][j] + results[i-1][j-1];
            } else if (S[i-1] != T[j-1]) {
                results[i][j] = results[i-1][j];
            }
        }
    }
    return results[size_S][size_T];
}

bool isInterleave(string s1, string s2, string s3) {
    int size_s1 = s1.length();
    int size_s2 = s2.length();
    int size_s3 = s3.length();
    if (size_s3 != size_s1 + size_s2) {
        return false;
    } 
    vector<vector<bool>> results(size_s1 + 1, vector<bool>(size_s2 + 1));
    results[0][0] = true;
    for (int i = 1; i < size_s1 + 1; i++) {
        if (results[i-1][0] && s1[i-1] == s3[i-1]) {
            results[i][0] = true;
        } else {
            results[i][0] = false;
        }
    }
    for (int i = 1; i < size_s2 + 1; i++) {
        if ( results[0][i-1] &&  s2[i-1] == s3[i-1]) {
            results[0][i] = true;
        } else {
            results[0][i] = false;
        }
    }
    for (int i = 1; i < size_s1 + 1; i++) {
        for (int j = 1; j < size_s2 + 1; j++) {
            results[i][j] = ( results[i-1][j] && s1[i-1] == s3[i+j-1] ) 
                    ||  (results[i][j-1] && s2[j-1] == s3[i+j-1] );
        }
    }
    return results[size_s1][size_s2];
}

int longestCommonSubstring(string &A, string &B) {
    // write your code here
    int size_A = A.length();
    int size_B = B.length();
    if (size_A == 0 || size_B == 0) {
        return 0;
    }
    vector<vector<int>> results(size_A + 1, vector<int>(size_B + 1));
    for (int i = 0; i < size_A + 1; i++) {
        results[i][0] = 0;
    }
    for (int i = 0; i < size_B + 1; i++) {
        results[0][i] = 0;
    }
    for (int i = 1; i < size_A + 1; i++) {
        for (int j = 1; j < size_B + 1; j++) {
            if (A[i-1] == B[j-1]) {
                results[i][j] = results[i-1][j-1] + 1;
            } else {
                results[i][j] = 0;
            }
        }
    }
    int max = INT_MIN;
    for (int i = 0; i < size_A + 1; i++) {
        for (int j = 0; j < size_B + 1; j++) {
            if (max < results[i][j]) {
                max = results[i][j];
            }
        }
    }
    return max;
}


// 2 ,3 ,5, 7
// m 
int backPack(int m, vector<int> A) {
   int size = A.size();
   if (size == 0 || m == 0) {   
        return 0;
   }
   vector<vector<int>> results(size + 1, vector<int>(m+1));
   for (int i = 0; i < size + 1; i++) {
        results[i][0] = 0;
   }
   for (int i = 0; i < m + 1; i++) {
        results[0][i] = 0;
   }
   for (int i = 1; i < size + 1; i++) {
        for (int j = 1; j < m + 1; j++ ){
            if (j < A[i-1]) {
                results[i][j] = results[i-1][j];
            } else {
                results[i][j] = max(results[i-1][j], A[i-1] + results[i-1][j-A[i-1]]);
            }
        }
   }
   return results[size][m];
}

int backPackII(int m, vector<int> A, vector<int> V) {
    // write your code here
    int size_A = A.size();
    if (size_A == 0 || m == 0) {
        return 0;
    }
    vector<vector<int>> results(size_A + 1, vector<int>(m+1));
    for (int i = 0; i < size_A + 1; i++) {
        results[i][0] = 0;
    }
    for (int i = 0; i < m + 1; i++) {
        results[0][i] = 0;
    }
    for (int i = 1; i < size_A + 1; i++) {
        for (int j = 1; j < m + 1; j++ ){
            if (j < A[i-1]) {
                results[i][j] = results[i-1][j];
            } else {
                results[i][j] = max(results[i-1][j], V[i-1] + results[i-1][j-A[i-1]]);
            }
        }
    }   
    return results[size_A][m];
}

int longestIncreasingContinuousSubsequence(vector<int>& A) {
    // Write your code here
    if (A.size() == 0) {
        return 0;
    }
    if (A.size() == 1) {
        return 1;
    }
    int size = A.size();
    vector<int> B(size, 1);
    for (int i = 1; i < size; i++) {
        if (A[i] < A[i - 1]) {
            B[i] = B[i - 1] + 1;
        } else { 
            B[i] = 1;
        }
    }
    vector<int> C(size, 1);
    for (int i = size - 2; i >= 0; i--) {
        if (A[i] < A[i + 1] ) {
            C[i] = C[i + 1] + 1;
        } else {
            C[i] = 1;
        }
    }
    int max_B = INT_MIN;
    int max_C = INT_MIN;
    for (auto x : B) {
        if (x > max_B) {
            max_B = x;
        }
    }
    for (auto x : C) {
        if (x > max_C) {
            max_C = x;
        }
    }
    if (max_B >= max_C ) {
        return max_B;
    } else 
        return max_C;
}

ListNode *partition_lintcode(ListNode *head, int x) {
    // write your code here
    if (head == NULL) {
        return head;
    }
    ListNode *first_half = new ListNode(0);
    ListNode *first_half_head = first_half;
    ListNode *second_half = new ListNode(0);
    ListNode *second_half_head = second_half;
    ListNode *cur = head;
 
    while (cur != NULL) {
        if (cur->val < x) {
            ListNode *tmp = new ListNode(cur->val);
            first_half->next = tmp;
            first_half = tmp;
        } else {
            ListNode *tmp = new ListNode(cur->val);
            second_half->next = tmp;
            second_half = tmp;
        }
        cur = cur->next;
    }
    first_half->next = second_half_head->next;
    return first_half_head->next;
}

ListNode * deleteDuplicates(ListNode *head) {
    // write your code here
    if (head == NULL) {
        return head;
    }
    if (head->next == NULL) {
        return head;
    }
    if (head->next->next == NULL ) {
        if (head->val != head->next->val) {
            return head;
        } else {
            return NULL;
        }
    }
    ListNode *low = head;
    ListNode *mid = head->next;
    ListNode *high = head->next->next;
    ListNode *cur = new ListNode(0);
    ListNode *cur_head = cur;
    if (low->val != mid->val) {
        ListNode *tmp = new ListNode(low->val);
        cur->next = tmp;
        cur = tmp;
    }
    ListNode *second_last = new ListNode(0);
    while (head->next->next != NULL) {
        if (mid->val != low->val && mid->val != high->val) {
            ListNode *tmp = new ListNode(mid->val);
            cur->next = tmp;
            cur = tmp;
            head = head->next;
        } else {
            head = head->next;
        }
        second_last->next = mid;
        low = head;
        mid = head->next;
        high = head->next->next;
    }
   // cout << head->val << " 111 " << endl;
   // cout << second_last->next->val << endl;
    if (head->next->val != second_last->next->val) {
        ListNode *tmp = new ListNode(head->next->val);
        cur->next = tmp;
    }
    return cur_head->next;
}

ListNode *reverseBetween(ListNode *head, int m, int n) {
    // write your code here
    if (head == NULL) {
        return head;
    }
    if (m == n) {
        return head;
    }
    cout << "111111" << endl;
    ListNode *cur = head;
    ListNode *second_loop = head;
    int index = 1;
    vector<int> container;
    while (cur != NULL) {
        if (index > n) {
            break;
        }
        if (index >= m && index <= n ) {
            container.push_back(cur->val);
        }
        index++;
        cur = cur->next;
    }
        cout << "22222222  " << container.size()<< endl;
        for (auto x : container) {
            cout << x << endl;
        }

    reverse(container.begin(), container.end());
    int position = 1;
    int vector_index = 0;
    while (second_loop != NULL) {
        cout << "position: " << position << endl;
        if (position > n) {
            break;
        }
        if (position >= m && position <= n ) {
            second_loop->val = container[vector_index];
            vector_index++;
        }
        position++;
        second_loop = second_loop->next;
    }
        cout << "3333333" << endl;

    return head;
}


void quicksort_median(vector<int> &nums, int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = nums[left];
    int low = left;
    int high = right;
    // cout << "pivot: " << pivot << endl;
    // cout << "low: " << low << endl;
    // cout << "high: " << high << endl;
    // cout << "------------" << endl;
    while (low < high) {
        while (low < high && nums[high] >= pivot) {
            high--;
        }
        nums[low] = nums[high];
        while (low < high && nums[low] <= pivot) {
            low++;
        }
        nums[high] = nums[low];
    }
    nums[low] = pivot;
    quicksort_median(nums, left, low - 1);
    quicksort_median(nums, low + 1, right);
}

//quick sort
int median(vector<int> &nums) {
    // write your code here
    if (nums.size() == 1) {
        return nums[0];
    }
    int length = nums.size();
    quicksort_median(nums, 0, length - 1);
    // for (auto x : nums) {
    //     cout << x << " ";
    // }
    // cout << endl;
    if (length%2 == 1) {
        return nums[(length - 1) / 2];
    } else {
        return nums[(length - 2) / 2];
    }
}

void sortIntegers2_quicksort(vector<int> &A, int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = A[left];
    int low = left;
    int high = right;
    cout << "pivot: " << pivot << endl;
    cout << "low: " << low << endl;
    cout << "high: " << high << endl;
    cout << "------------" << endl;
    while (low < high) {
        while (low < high && A[high] >= pivot) {
            high--;
        }
        A[low] = A[high];
        while (low < high && A[low] <= pivot) {
            low++;
        }
        A[high] = A[low];
    }
    A[low] = pivot;
    sortIntegers2_quicksort(A, left, low - 1);
    sortIntegers2_quicksort(A, low + 1, right);  
}

//quick sort lintcode Sort Integers II
void sortIntegers2(vector<int>& A) {
    // Write your code here
    int length = A.size();
    sortIntegers2_quicksort(A, 0, length - 1);
    return;
}

void kthLargestElement_quicksort(vector<int> &nums, int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = nums[left];
    int low = left;
    int high = right;
    while (low < high) {
        while (low < high && nums[high] >= pivot) {
            high--;
        }
        nums[low] = nums[high];
        while (low < high && nums[low] <= pivot) {
            low++;
        }
        nums[high] = nums[low];
    }
    nums[low] = pivot;
    kthLargestElement_quicksort(nums, left, low - 1);
    kthLargestElement_quicksort(nums, low + 1, right);
}

int kthLargestElement(int k, vector<int> nums) {
    // write your code here
    int length = nums.size();
    kthLargestElement_quicksort(nums, 0, length - 1);
    return nums[length - k];
}

void merge(vector<int> &A, int low, int high, int mid) {
    int i = low;
    int j = mid + 1;
    int k = 0;
    vector<int> A2(high - low + 1, 0);

    while (i <= mid && j <= high) {
        if (A[i] < A[j]) {
            A2[k++] = A[i++];
        }else {
            A2[k++] = A[j++];
        }
    }
    while (i <= mid) {
        A2[k++] = A[i++];
    }
    while (j <= high) {
        A2[k++] = A[j++];
    }
    int size = A2.size();
    k = 0;
    while (k < size) {
        A[k + low] = A2[k];
        k++;
    }
}

void sortIntegers2_merge(vector<int> &A, int low, int high) {
    int mid = (low + high) / 2;
    if (low < high) {
        sortIntegers2_merge(A, low, mid);
        sortIntegers2_merge(A, mid + 1, high);
        merge(A, low, high, mid);
    }
}

void sortIntegers2_mergesort(vector<int>& A) {
    // Write your code here
    int length = A.size();
    sortIntegers2_merge(A, 0, length - 1);
    return;
}

ListNode *findmid(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head -> next;
    while (fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

ListNode * sortList_merge(ListNode *left, ListNode *right) {
    ListNode *dummy = new ListNode(0);
    ListNode *tail = dummy;
    while (left != NULL && right != NULL) {
        if (left -> val < right -> val) {
            tail -> next = left;
            tail = tail -> next;
            left = left -> next;
        } else {
            tail -> next = right;
            tail = tail -> next;
            right = right -> next;
        }
    }
    if (left != NULL) {
        tail -> next = left;
    } else {
        tail -> next = right;
    }
    return dummy->next;
}

ListNode *sortList_mergesort(ListNode *head) {
    // write your code here
    if (head == NULL || head -> next == NULL) {
        return head;
    }
    ListNode *mid = findmid(head);
    ListNode *right = sortList_mergesort(mid -> next);
    mid -> next = NULL;
    ListNode *left = sortList_mergesort(head);
    return sortList_merge(left, right);
}


void reorderList(ListNode *head) {
    // write your code here
    if (head == NULL || head -> next == NULL) {
        return;
    }
    ListNode *cur = head;
    int length = 0;
    ListNode *tmp = head;
    ListNode *dummy = new ListNode(0);
    ListNode *result = dummy;
    while (cur != NULL) {
        cur = cur -> next;
        length++;
    }
    int i = 0; 
    queue<ListNode*> q;
    stack<ListNode*> s;
    while (tmp != NULL) {
        ListNode * t = new ListNode(tmp -> val);
        if (i < length / 2) {
            q.push(t);
        } else {
            s.push(t);
        }
        i++;
        tmp = tmp -> next;
    }
    // cout << q.size() << endl;
    // cout << s.size() << endl;
    // // cout << "q -> val: " << q.front() -> val << endl;
    // q.pop();
    // cout << q.front() -> val << endl;
    // cout << s.top() -> val << endl;
    // s.pop();
    // cout << s.top() -> val << endl;
    // s.pop();
    // cout << s.top() -> val << endl;
    while (!q.empty() && !s.empty()) {
        // cout << q.front() -> val << endl;
        // cout << s.top() -> val << endl;
        // cout << "--------------" << endl;

        dummy -> next = q.front();
        //dummy = dummy -> next;
        dummy -> next -> next = s.top();
        dummy = dummy -> next -> next;
        q.pop();
        s.pop();
    }
    // cout << q.size() << endl;
    // cout << s.size() << endl;
    // return;
   // dummy = dummy -> next;
    if (!s.empty()) {
        dummy -> next = s.top();
    }
    // cout << result -> val << endl;
    // cout << result -> next -> val << endl;
    // cout << result -> next -> next -> val << endl;
    result = result -> next; 
    while (head != NULL) {
        head -> val = result -> val;
        head = head -> next;
        result = result -> next;
    }
}

bool hasCycle_lintcode(ListNode *head) {
    // write your code here
    if (head == NULL) {
        return false;
    }
    ListNode *slow = head;
    ListNode *fast = head -> next;
    while (fast != NULL && fast -> next != NULL) {
        if (slow == fast) {
            return true;
        }
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return false;
}

struct compare {
    bool operator()(const ListNode* l, const ListNode* r) {
        return l->val > r->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, compare> pq;
    for (unsigned long i = 0; i < lists.size(); i++) {
        while (lists[i] != NULL) {
            pq.push(lists[i]);
            lists[i] = lists[i] -> next;
        }
    }
    if (pq.empty()) {
        return NULL;
    }
    ListNode * dummy = pq.top();
    ListNode *tail = dummy;
    pq.pop();
    while (!pq.empty()) {
        tail -> next = pq.top();
        pq.pop();
        tail = tail -> next;
    }
    tail -> next = NULL;
    return dummy;
}

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode *copyRandomList(RandomListNode *head) {
    // write your code here
    RandomListNode *newHead, *l1, *l2;
    if (head == NULL) return NULL;
    for (l1 = head; l1 != NULL; l1 = l1->next->next) {
        l2 = new RandomListNode(l1->label);
        l2->next = l1->next;
        l1->next = l2;
    }
    newHead = head->next;
    for (l1 = head; l1 != NULL; l1 = l1->next->next) {
        if (l1->random != NULL) l1->next->random = l1->random->next;
    }    
    for (l1 = head; l1 != NULL; l1 = l1->next) {
        l2 = l1->next;
        l1->next = l2->next;
        if (l2->next != NULL) l2->next = l2->next->next;
    }
    return newHead;
}

ListNode *node; 

TreeNode *inorder_tree(int start, int end) {
    if (start > end) {
        return NULL;
    }
    int mid = start + (end - start) / 2;
    TreeNode * left = inorder_tree(start, mid - 1);
    TreeNode *tree_node = new TreeNode(node -> val);
    tree_node -> left = left;
    node = node -> next;
    TreeNode * right = inorder_tree(mid + 1, end);
    tree_node -> right = right;
    return tree_node;
}

TreeNode* sortedListToBST(ListNode* head) {
    if (head == NULL) {
        return NULL;
    }
    int size = 0;
    node = head;
    ListNode *runner = head;
    while (runner != NULL) {
        size++;
        runner = runner -> next;
    }
    return inorder_tree(0, size - 1);
}

//second version: without extra space
ListNode *detectCycle_lintcode(ListNode *head) {
    // write your code here
    if (head == NULL || head -> next == NULL) {
        return NULL;
    }
    bool hasCycle = false;
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
        if (slow == fast) {
            hasCycle = true;
            break;
        }
    }
    if (hasCycle == false) {
        return NULL;
    }
    while (slow != head) {
        slow = slow -> next;
        head = head -> next;
    }
    return slow;
}

vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
    // write your code here
    vector<int> results;
    int size_A = A.size();
    int size_B = B.size();
    int i = 0;
    int j = 0;
    while (i < size_A && j < size_B) {
        if (A[i] < B[j]) {
            results.push_back(A[i]);
            i++;
        } else if (A[i] > B[j]) {
            results.push_back(B[j]);
            j++;
        } else {
            results.push_back(A[i]);
            results.push_back(B[j]);
            i++;
            j++;
        }
    }
    cout << i << endl;
    cout << j << endl;
    cout << size_A << endl;
    cout << size_B << endl;
    while (i != size_A) {
        results.push_back(A[i]);
        i++;
    }
    while (j != size_B) {
        results.push_back(B[j]);
        j++;
    }
        cout << "assss" << endl;

    return results;
}

void mergeSortedArray(int A[], int m, int B[], int n) {
    // write your code here
    int i = 0;
    int j = 0;
    vector<int> results;
    while (i < m && j < n) {
        if (A[i] < B[j]) {
            results.push_back(A[i]);
            i++;
        } else if (A[i] > B[j]) {
            results.push_back(B[j]);
            j++;
        } else {
            results.push_back(A[i]);
            results.push_back(B[j]);
            i++;
            j++;
        }
    }
    while (i != m) {
        results.push_back(A[i]);
        i++;
    }
    while (j != n) {
        results.push_back(B[j]);
        j++;
    }
    int k = 0;
    for (auto x : results) {
        A[k] = x;
        k++;
    }
}

vector<int> intersection_lintcode(vector<int>& nums1, vector<int>& nums2) {
    // Write your code here
    vector<int> results;
    unordered_set<int> s1;
    unordered_set<int> s2;
    for (auto x : nums1) {
        s1.insert(x);
    }
    for (auto x : nums2) {
        s2.insert(x);
    }
    for (auto x : s1) {
        if (s2.find(x) != s2.end()) {
            results.push_back(x);
        }
    }
    return results;
}

// double findMedianSortedArrays(vector<int> A, vector<int> B) {
//     // write your code here
// }

int maxProfit_lintcode(vector<int> &prices) {
    // write your code here
    if (prices.size() == 0 || prices.size() == 1) {
        return 0;
    }
    vector<int> results(prices.size(), 0);
    int min = prices[0];
    int size = results.size();
    for (int i = 1; i < size; i++) {
        int tmp = prices[i] - min;
        if (tmp > results[i - 1]) {
            results[i] = tmp;
        } else {
            results[i] = results[i - 1];
        }
        if (min > prices[i]) {
            min = prices[i];
        }
    }
    return results.back();
}

int maxSubArray(vector<int> nums) {
    // write your code here
    int size = nums.size();
    vector<int> results(size, 0);
    results[0] = nums[0];
    int max = nums[0];

    for (int i = 1; i < size; i++) {
        if (results[i - 1] < 0) {
            results[i] = 0 + nums[i];
        } else {
            results[i] = results[i - 1] + nums[i];
        }
        if (results[i] > max) {
            max = results[i];
        }
    }
    return max;
}

int maxProfit2_lintcode(vector<int> &prices) {
    // write your code here
    if (prices.size() == 0 || prices.size() == 1) {
        return 0;
    }
    int size = prices.size();
    vector<int> results(prices.size(), 0);
    int min = prices[0];
    for (int i = 1; i < size; i++) {
        if (prices[i] > min) {
            results[i] = results[i - 1] + (prices[i] - min);
            min = prices[i];
        } else {
            results[i] = results[i - 1];
            min = prices[i];
        }
    }
    return results.back();
}

int maxProfit3(vector<int> &prices) {
    // write your code here
    if (prices.size() == 0 || prices.size() == 1) {
        return 0;
    }
    int hold1 = INT_MIN, hold2 = INT_MIN;
    int release1 = 0, release2 = 0;
    for (auto x : prices) {
        hold1 = max(-x, hold1);
        release1 = max(release1, hold1 + x);
        hold2 = max(hold2, release1 - x);
        release2 = max(release2, hold2 + x);
    }
    return release2;
}

vector<int> subarraySum(vector<int> nums){
    // write your code here
    unordered_map<int, int> m;
    if (nums[0] == 0) {
        vector<int> results = {0, 0};
        return results;
    }
    m[nums[0]] = 0;
    int size = nums.size();
    int sum = nums[0];
    for (int i = 1; i < size; i++) {
        sum += nums[i];
        cout << "sum: " << sum << endl;
        if (nums[i] == 0) {
            cout << "1111" << endl;
            vector<int> results = {i, i};
            return results;
        }
        if (sum == 0) {
                        cout << "2222" << endl;

            vector<int> results = {0, i};
            return results;
        }
        if (m.find(sum) != m.end()) {
                        cout << "3333" << endl;
            int c = m[sum];
            cout << "c: " << c << endl;
            vector<int> results = {m[sum] + 1, i};
            return results;
        }
        m[sum] = i;
    }   
    vector<int> results = {-1, -1};
    return results;
}

vector<int> twoSum_lintcode(vector<int> &nums, int target) {
    // write your code here
    unordered_map<int, int> m;
    int size = nums.size();
    for (int i = 0; i < size; i++) {
        if (m.find(target - nums[i]) != m.end()) {
            vector<int> results = {m[target - nums[i]] + 1, i + 1};
            return results;
        } else {
            m[nums[i]] = i;
        }
    }
    vector<int> results = {-1, -1};
    return results;
}

int twoSumCloset(vector<int>& nums, int target) {
    // Write your code here
    sort(nums.begin(), nums.end());
    int left = 0;
    int right = nums.size() - 1;
    int diff = INT_MAX;
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
            return 0;
        } else if (sum > target) {
            right = right - 1;
        } else {
            left = left + 1;
        }
        if (diff > abs(sum - target)) {
            diff = abs(sum - target);
        }
    }
    return diff;
}

void swap(vector<int> &nums, int j, int i) {
    int tmp = nums[j];
    nums[j] = nums[i];
    nums[i] = tmp;
}

void sortColors_lintcode(vector<int> &nums) {
    int size = nums.size();
    if (size == 0 || size == 1) {
        return;
    }
    int left = 0;
    int right = size - 1;
    int i = 0;
    while (i <= right) {
        if (nums[i] == 0) {
            swap(nums, left, i);
            i++;
            left++;
        } else if (nums[i] == 1) {
            i++;
        } else {
            swap(nums, right, i);
            right--;
        }
    }
    return;
}

int partitionArray(vector<int> &nums, int k) {
        // write your code here
    if (nums.size() == 0) {
        return 0;
    }
    int left = 0;
    int right = nums.size() - 1;
    int size = nums.size();
    while (left < right) {
        if (nums[left] >= k && nums[right] < k) {    
            int tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;
            left++;
            right--;
        } else {
            while (left < right && nums[left] < k) {
                left++;
            }
            while (left < right && nums[right] >= k) {
                right--;
            }
        }
    }
    for (int i = 0; i < size; i++) {
        if (nums[i] >= k) {
            return i;
        }
    }
    return size;
}

double helper(vector<int>& nums1, int m, vector<int>& nums2, int n, int k, int start1, int start2){
        if(m > n)
            return helper(nums2, n, nums1, m, k, start2, start1);
        if(m == 0)
            return nums2[k-1];
        if(k == 1)
            return min(nums1[start1], nums2[start2]);
        int a = min(k/2, m);
        int b = k-a;
        if(nums1[a+start1-1] <= nums2[b+start2-1]){
            return helper(nums1, m-a, nums2, n, k-a, start1+a, start2);
        }
        else{
            return helper(nums1, m, nums2, n-b, k-b, start1, start2+b);
        }
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int total = m+n;
        if(total%2 == 1)
            return helper(nums1, m, nums2, n, total/2+1, 0, 0);
        else
            return (helper(nums1, m, nums2, n, total/2, 0, 0) + helper(nums1, m, nums2, n, total/2+1, 0, 0))/2;
}

int largestRectangleArea(vector<int> &height) {
    // write your code here
    int n = height.size();
    stack<int> s;

    int max_area = 0;
    int top_stack;
    int area_with_top;

    int i = 0;
    while (i < n) {
        if (s.empty() || height[s.top()] <= height[i]) {
            s.push(i);
            i++;
        } else {
            top_stack = s.top();
            s.pop();

            area_with_top = height[top_stack] * (s.empty() ? i : i - s.top() - 1);

            if (max_area < area_with_top) {
                max_area = area_with_top;
            }
        }
    }

    while (!s.empty()) {
        top_stack = s.top();
        s.pop();

        area_with_top = height[top_stack] * (s.empty() ? i : i - s.top() - 1);

        if (max_area < area_with_top) {
            max_area = area_with_top;
        }
    }
    return max_area;
}

/*
先取到 所有的number 再rehash
*/
vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
    // write your code here
    int old_size = hashTable.size();
    vector<int> values;
    for (int i = 0; i < old_size; i++) {
        if (hashTable[i] == NULL) {
            continue;
        } else {
            values.push_back(hashTable[i] -> val);
            ListNode * head = hashTable[i];
            head = head -> next;
            while (head) {
                values.push_back(head -> val);
                head = head -> next;
            }
        }
    }
    cout << "values.size(): " << values.size() << endl;
    int new_size = 2 * old_size;
    vector<ListNode*> results(new_size);
    for (unsigned long i = 0; i < values.size(); i++) {
        int hash_value;
        if (values[i] >= 0) {
            hash_value = values[i] % new_size;
        } else {
            hash_value = (values[i] % new_size + new_size) % new_size;
        }
        ListNode * tmp = new ListNode(values[i]);
        if (results[hash_value] == NULL) {
            results[hash_value] = tmp;
        } else {
            ListNode *cur = results[hash_value];
            while (cur -> next != NULL) {
                cur = cur -> next;
            }
            cur -> next = tmp;
        }
    }
    return results;
}



// struct Node {
//         int key;
//         Node *pre;
//         Node *post;
//         Node(int x) : key(x), pre(NULL), post(NULL) {}
// };

// class LRUCache{
// public: 
//     Node * head = new Node(0);
//     Node * end = new Node(0);
//     head -> pre = NULL;
//     head -> post = end;
//     end -> pre = head;
//     end -> post = NULL;

//     unordered_map<int, int> m;
//     unsigned long size;
//     unsigned long count = 0;

//     LRUCache(int capacity) {
//         size = capacity;
//     }
    
//     int get(int key) {
//         if (m.find(key) != m.end()) {
//             Node * tmp = new Node(key);
//             tmp -> pre = head;
//             tmp -> post = head -> post;
//             if (end -> pre == head) {
//                 end -> pre = tmp;
//             }
//             head -> post -> pre = tmp;
//             head -> post = tmp;
//             count++;
//             if (count > size) {
//                 end -> pre = end -> pre -> pre;
//                 count--;
//             }
//             return m[key];
//         } else {
//             return -1;
//         }
//     }
    
//     void set(int key, int value) {
//         if (m.find(key) != m.end()) {
//             Node * tmp = new Node(key);
//             tmp -> pre = head;
//             tmp -> post = head -> post;
//             if (end -> pre == head) {
//                 end -> pre = tmp;
//             }
//             head -> post -> pre = tmp;
//             head -> post = tmp;
//             count++;
//             if (count > size) {
//                 end -> pre = end -> pre -> pre;
//                 count--;
//             }
//             m[key] = value;
//         } else {
//             Node * tmp = new Node(key);
//             tmp -> pre = head;
//             tmp -> post = head -> post;
//             if (end -> pre == head) {
//                 end -> pre = tmp;
//             }
//             head -> post -> pre = tmp;
//             head -> post = tmp;
//             count++;
//             if (count > size) {
//                 end -> pre = end -> pre -> pre;
//                 count--;
//             }
//             m[key] = value;
//         }
//     }
// };


int nthUglyNumber(int n) {
    int *uglys = new int[n];
    uglys[0] = 1;
    int next = 1;
    int *p2 = uglys;
    int *p3 = uglys;
    int *p5 = uglys;
    while (next < n) {
        int m = min(min(*p2 * 2, *p3 * 3), *p5 * 5);
        uglys[next] = m;
        while (*p2 * 2 <= uglys[next]) {
            p2++;
        }
        while (*p3 * 3 <= uglys[next]) {
            p3++;
        }
        while (*p5 * 5 <= uglys[next]) {
            p5++;
        }
        next++;
    }
    int nth = uglys[n - 1];
    delete[] uglys;
    return nth;
}

vector<int> topk(vector<int>& nums, int k) {
    // Write your code here
    priority_queue<int> pq;
    for (int x : nums) {
        pq.push(x);
    }
    vector<int> results;
    while (k != 0) {
        k--;
        results.push_back(pq.top());
        pq.pop();
    }
    return results;
}

/*
O(nlogk）

*/

    
struct Element {
    unsigned long row;
    unsigned long col;
    int val;
    Element(int row, int col, int val) {
        this -> row = row;
        this -> col = col;
        this -> val = val;
    }
};

struct Greater
{
  bool operator()(const Element& lhs, const Element& rhs) const
  {
    return lhs.val > rhs.val;
  }
};

vector<int> mergekSortedArrays(vector<vector<int>>& arrays) {
    // Write your code here
    int size = 0;
    priority_queue<Element, vector<Element>, Greater> pq;
    for (unsigned long i = 0; i < arrays.size(); i++) {
        if (arrays[i].size() > 0) {
            Element tmp(i, 0, arrays[i][0]);
            pq.push(tmp);
            size += arrays[i].size();
        }
    }
    vector<int> results(size);
    int next = 0;
    while (!pq.empty()) {
        Element min = pq.top();
        pq.pop();
        results[next++] = min.val;
        if (min.col + 1 < arrays[min.row].size()) {
            min.col++;
            min.val = arrays[min.row][min.col];
            pq.push(min);
        }
    }
    return results;
}

struct DirectedGraphNode {
    int label;
    vector<DirectedGraphNode *> neighbors;
    DirectedGraphNode(int x) : label(x) {};
};

void dfs(DirectedGraphNode * i, vector<DirectedGraphNode*> &results, 
    vector<DirectedGraphNode*> graph, map<DirectedGraphNode*, int> &m) 
{
    results.push_back(i);
    m[i]--;
    int size = i -> neighbors.size();
    for (int j = 0; j < size; j++) {
        m[i -> neighbors[j]]--;
        if (m[i -> neighbors[j]] == 0) {
            dfs(i -> neighbors[j], results, graph, m);
        }
    }
}

vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
    // write your code here
    //count number of neighbors
    map<DirectedGraphNode*, int> m;
    vector<DirectedGraphNode*> results;
    int size = graph.size();
    for (int i = 0; i < size; i++) {
        for (DirectedGraphNode * n : graph[i] -> neighbors) {
            if (m.find(n) == m.end()) {
                m[n] = 1;
            } else {
                m[n] = m[n] + 1;
            }
        }
    }
    //find the starting node;
    for (DirectedGraphNode * i : graph) {
        if (m[i] == 0) {
            dfs(i, results, graph, m);
        }
    }
    return results;
}

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
 };

int sixDegrees(vector<UndirectedGraphNode*> graph,
                   UndirectedGraphNode* s,
                   UndirectedGraphNode* t) {
    // Write your code here
    vector<UndirectedGraphNode*> unused = graph;
    map<UndirectedGraphNode*, int> m;
    queue<UndirectedGraphNode*> q;

    if (s == t) {
        return 0;
    }
    m[s] = 0;
    q.push(s);
    while (!q.empty()) {
        UndirectedGraphNode * node = q.front();
        q.pop();
        int step = m[node];
        for (unsigned long i = 0; i < node->neighbors.size(); i++) {
            if (m.find(node->neighbors[i]) != m.end()) {
                continue;
            }
            m[node->neighbors[i]] = step + 1;
            q.push(node->neighbors[i]);
            if (node->neighbors[i] == t) {
                return step + 1;
            }
        }
    }
    return -1;
}

TreeNode* cloneTree(TreeNode *root) {
    // Write your code here
    TreeNode * tmp = NULL;
    if (root) {
        tmp = new TreeNode(root -> val);
        tmp -> left = cloneTree(root -> left);
        tmp -> right = cloneTree(root -> right);
    }
    return tmp;
}

bool cmp(const string s1, const string s2) {
    return (s1 + s2) < (s2 + s1);
}

string minNumber(vector<int>& nums) {
    // Write your code here
    vector<string> s_nums(nums.size());
    stringstream stream;
    for (unsigned long i = 0; i < nums.size(); ++i) {
        stream << nums[i];
        stream >> s_nums[i];
        stream.clear();
    }
    sort(s_nums.begin(), s_nums.end(), cmp);
    string result;
    for (unsigned long i = 0; i < s_nums.size(); ++i) {
        result += s_nums[i];
    }
    cout << result << endl;
    string res;
    bool flag = false;
    for (unsigned long i = 0; i < result.size(); ++i) {
        if (result[i] != '0') {
            res.push_back(result[i]);
            flag = true;
        } else if (flag) {
            res.push_back(result[i]);
        }
    }
    if (!flag) res.push_back('0');
    return res;
}

/*
get length of ramsonNote and length of magazine
compare length; if not magazine length shorter, return false;
hash table each letter in ransomNote and count nums
hash table each letter in magazine and count nums
loop through ransomNote string
  check whether letter exists in magazine, if not, return false;
  check nums of that letter <= nums of letter in magazine or not; 
  if not return false;
otherwise, return true;
*/
bool canConstruct(string ransomNote, string magazine) {
    int length_ransomNote = ransomNote.length();
    int length_magazine = magazine.length();
    if (length_ransomNote > length_magazine) {
        return false;
    }
    map<char, int> hashTable_ransomNote;
    map<char, int> hashTable_magazine;
    for (int i = 0; i < length_ransomNote; i++) {
        if (hashTable_ransomNote.find(ransomNote[i]) == hashTable_ransomNote.end()) {
            hashTable_ransomNote[ransomNote[i]] = 1;
        } else {
            hashTable_ransomNote[ransomNote[i]] += 1;
        }
    }
    for (int i = 0; i < length_magazine; i++) {
        if (hashTable_magazine.find(magazine[i]) == hashTable_magazine.end()) {
            hashTable_magazine[magazine[i]] = 1;
        } else {
            hashTable_magazine[magazine[i]] += 1;
        }
    }
    for (int i = 0; i < length_ransomNote; i++) {
        if (hashTable_magazine.find(ransomNote[i]) == hashTable_magazine.end()) {
            return false;
        }
        if (hashTable_magazine[ransomNote[i]] < hashTable_ransomNote[ransomNote[i]]) {
            return false;
        }
    }
    return true;
}

/*
loop through string s, create a hash_table to count how many times a letter exists
loop through string s, again, map each char if char appears == 1 return index; 
otherwise return -1
*/
int firstUniqChar(string s) {
    map<char, int> m;
    int length = s.length();
    for (int i = 0; i < length; i++) {
        if (m.find(s[i]) == m.end()) {
            m[s[i]] = 1;
        } else {
            m[s[i]] += 1;
        }
    }
    for (int i = 0; i < length; i++) {
        if (m[s[i]] == 1) {
            return i;
        }
    }
    return -1;
} 

/*
A      E
 B   d   f
   c
*/
string convert(string s, int numRows) {
    if (numRows <= 1) {
        return s;
    }
    vector<vector<char>> container(numRows);
    int length = s.length();
    int row = 0;
    int step = 1;
    for (int i = 0; i < length; i++) {
        if (row == 0) {
            step = 1;
        } else if (row == numRows - 1) {
            step = -1;
        }
        container[row].push_back(s[i]);
        row += step;
    }
    string result = "";
    for (int i = 0; i < numRows; i++) {
        for (unsigned long j = 0; j < container[i].size(); j++) {
            result += container[i][j];
        }
    }
    return result;      
}

void search_leaf(TreeNode *&root, vector<int> &container) {
    if (root -> left == NULL && root -> right == NULL) {
        container.push_back(root -> val);
        root = NULL;
    } else {
        if (root -> left != NULL) {
            search_leaf(root -> left, container);
        }
        if (root -> right != NULL) {
            search_leaf(root -> right, container);
        }    
    } 
}

/*
create a vector vector
recurively preorder  go through the tree, 
if two children are NULL, push into to vector,  node == NULL
*/
vector<vector<int>> findLeaves(TreeNode* root) {
    vector<vector<int>> results; 

    while (root != NULL) {
        vector<int> container;
        search_leaf(root, container);
        results.push_back(container);
    }
    return results;
}

/*
create a vector of 0 with length;
loop through updates, updates line by line
*/
vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
    // vector<int> result(length, 0);
    // int rows = updates.size();
    // for (int i = 0; i < rows; i++) {
    //     for (int j = updates[i][0]; j <= updates[i][1]; j++) {
    //         result[j] = result[j] + updates[i][2];
    //     }
    // }
    // return result;

    int rows = updates.size();
    vector<int> res(length, 0);
    for (int i = 0; i < rows; i++) {
        int value = updates[i][2];
        int start = updates[i][0];
        int end = updates[i][1];
        res[start] += value; 
        if (end < length - 1) {
            res[end + 1] -= value;
        }
    }
    int sum = 0;
    for (unsigned long i = 0; i < res.size(); i++) {
        sum += res[i];
        res[i] = sum;
    }
    return res;
}

ListNode *reverse(ListNode *head) {
    ListNode *pre = head;
    if (head -> next == NULL) {
        return head;
    }
    ListNode *cur = head -> next;
    ListNode *next = cur -> next;
    pre -> next = NULL;
    while (cur != NULL) {
        cur -> next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

/*
reverse the head
1 2 3
3 2 1
+ 1
reverse back
*/
ListNode* plusOne(ListNode* head) {
   ListNode *dummy = reverse(head);
   ListNode *cur = dummy;
   int carry = 0;
   while (cur != NULL) {
        if (cur -> val + 1 + carry < 10) {
            cur -> val = cur -> val + 1;
        } else if (cur -> val + 1 + carry == 10) {
            carry = 1;
            cur -> val = 0;
        }
        if (cur -> next == NULL && cur -> val == 0) {
            cur -> next = new ListNode(1);
        }
        cur = cur -> next;
   }
   ListNode *res = reverse(dummy);
   return res;
}

bool pairExist(vector<int> &a, int sum) {

    unordered_set<int> s;
    for (unsigned long i = 0; i < a.size(); i++) {
        int tmp = sum - a[i];
        s.insert(a[i]);
        if (s.find(tmp) != s.end()) {
            return true;
        }
    }
    return false;
}



int main(){
    
    return 0;
}


