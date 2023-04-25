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

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print_vector(vector<int> & vec, string msg=""){
    cout << msg;
    for(int &s:vec){
        cout << s << ",";
    }
    cout << endl;
}


class Solution1 {
    //This basically works fine but this is limited to small integers but if 
    // the numbers are large then the next class Solution is the best bet
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int val1 = listNodeToInt(l1);
        int val2 = listNodeToInt(l2);
        return intToListNode(val1+val2);
    }

    int listNodeToInt(ListNode* l){
        int data=0;
        vector<int> vec;
        while(l!=NULL){
            vec.push_back(l->val);
            l = l->next;
        }
        while(!vec.empty()){
            data = data*10 + vec.back();
            vec.pop_back();
        }
        return data;
    }

    ListNode* intToListNode(int val){
        ListNode* head=NULL;
        ListNode* tail=NULL;
        vector<int> vec;
        if(val == 0){
            return new ListNode(0);
        }
        while(val != 0)
        {
            if (head == NULL){
                tail = new ListNode(val%10);
                head = tail;
            }
            else{
                tail->next = new ListNode(val%10);
                tail = tail->next;
            }
            val = val/10;
        }
        return head;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL; // This has answer
        ListNode *tail = NULL;
        ListNode *temp = NULL;
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        int _sum = 0;
        while(l1!= NULL && l2 != NULL){
            _sum = _sum + l1->val + l2->val;
            l1 = l1->next;
            l2 = l2->next;
            cout << "_sum: " << _sum << endl;
            if(head == NULL){
                tail = new ListNode(_sum%10);
                head = tail;
            }
            else{
                tail->next = new ListNode(_sum%10);
                tail = tail->next;
            }
            _sum /= 10; // here this acts as carry
        }
        if(l1 == NULL && l2 == NULL && _sum != 0){
            tail->next = new ListNode(_sum%10);
        }
        if(l1 != NULL && l2 == NULL)        temp = l1;
        else if(l1 == NULL && l2 != NULL)   temp = l2;

        while(temp != NULL){
            _sum = _sum + temp->val;
            tail->next = new ListNode(_sum%10);
            temp = temp->next;
            tail = tail->next;
            _sum = _sum/10;
        }
        if(_sum != 0){
            tail->next = new ListNode(_sum%10);
        }
        return head;
    }
    
    ListNode* _addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL;
        ListNode *tail = NULL;
        ListNode *temp = NULL;
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        int val1=0, val2=0;
        int _sum=0;
        while(l1!= NULL && l2!= NULL){
            val1 = l1->val;
            val2 = l2->val;
            _sum = _sum+val1+val2;
            l1 = l1->next;
            l2 = l2->next;
            cout << "_sum: " << _sum << endl;
            if(head == NULL){
                head = new ListNode(_sum%10);
                cout << "pushed into head: " << head->val << endl;
                tail = head->next;
                // tail = tail->next;
            }
            else{
                tail = new ListNode(_sum%10);
                cout << "pushed into tail: " << tail->val << endl;
                tail = tail->next;
            }
            _sum = _sum/10;
        }
        if(l1 == NULL && l2 == NULL)
        {
            if(_sum != 0)   tail = new ListNode(_sum%10); // Here percentile is not required just putting it maintain consistency
            // Solution1 temp;
            // cout << "out:" << temp.listNodeToInt(head) << endl;
            // return head;
        }else if((l1 != NULL) && (l2 == NULL)){
            temp = l1;  // Will use temp for further calculations.
        }else if((l1 == NULL) && (l2 != NULL)){
            temp = l2;  // Instead of putting this else I put this in else if because I am not returning before this.
        }
        while(temp!=NULL){
            _sum = _sum+temp->val;
            tail = new ListNode(_sum%10);
            tail = tail->next;
            temp = temp->next;
        }
        {
            Solution1 temp;
            cout << "out:" << temp.listNodeToInt(head) << endl;
            // tail = 
            // while()
        }
        return head;
    }
};

ListNode *func(){
    ListNode *head;
    ListNode *tail;
    head = new ListNode(9);
    head->next = new ListNode(5);
    head->next->next = new ListNode(3);
    tail = head;
    return tail;
}


int main(){

    Solution sol;
    Solution1 sol1;
    int temp;
    ListNode *head = sol.addTwoNumbers(sol1.intToListNode(223),sol1.intToListNode(999991));
    temp = sol1.listNodeToInt(head);
    cout << "689: " << temp << endl;
    return 0;
}