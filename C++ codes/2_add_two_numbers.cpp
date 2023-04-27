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

// Approach
// Grab values from l1, l2 add them to _sum, increment l1, l2 to next position iff are not null. push the first digit in _sum into tail, now increment tail also. Iterate this process till there are no digits in either of the lists.

// Disclaimer:
// Even though this is efficient but the increased efficiency comes at a cost. We have created an empty node and returned from its next address, so once the function returns this can become a memory leak.

// Complexity
// Time complexity: O(max(len(l1), len(l2)))
// Space complexity: O(max(len(l1), len(l2))+1)


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
    for(int i=0; i<vec.size(); i++) cout << vec[i] << ", ";   cout << endl;
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

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        ListNode *head = new ListNode();
        ListNode *tail = head;
        int _sum = 0;  // We will use this both for carry and storing the sum 
        while(l1 != NULL || l2 != NULL){
            if(l1 != NULL){
                _sum = _sum + l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                _sum = _sum + l2->val;
                l2 = l2->next;
            }
            // if(head == NULL){
            //     head = new ListNode(_sum%10);
            //     tail = head;
            // }else{
            //     tail->next = new ListNode(_sum%10);
            //     tail = tail->next;
            // }
            tail->next = new ListNode(_sum%10);
            tail = tail->next;
            _sum = _sum/10;
        }
        if(_sum)   tail->next = new ListNode(_sum%10);
        // Disclaimer:
        /* The efficiency in code execution is coming by omitting the 
        ( head == NULL ) check, we have assinged a node in the beginning 
        of the function and returning the address from next.
        Even though this is efficient but the increased efficiency comes at a cost.
        We have created an empty node and returned from its next address,
        so once the function returns this can become a memory leak.
        */ 
        return head->next;
    }

    ListNode* _addTwoNumbers(ListNode* l1, ListNode* l2) {
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
        }else if(l1 != NULL && l2 == NULL)        temp = l1;
        else if(l1 == NULL && l2 != NULL)   temp = l2;

        while(temp != NULL){
            _sum = _sum + temp->val;
            tail->next = new ListNode(_sum%10);
            tail = tail->next;
            temp = temp->next;
            _sum = _sum/10;
        }
        if(_sum != 0){
            tail->next = new ListNode(_sum%10);
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
    int temp;
    int tt = 1e7;
    ListNode *head;
    // while(tt--)
    head = sol.addTwoNumbers(intToListNode(223),intToListNode(9999991));
    temp = listNodeToInt(head);
    cout << "689: " << temp << endl;
    tt = 1e7;
    // while(tt--)
    head = sol.addTwoNumbers(intToListNode(406),intToListNode(203));
    cout << "689: " << listNodeToInt(head) << endl;
    return 0;
}