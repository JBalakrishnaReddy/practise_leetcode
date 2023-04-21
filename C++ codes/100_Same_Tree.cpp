#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    inline TreeNode() : val(0), left(nullptr), right(nullptr) {}
    inline TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    inline TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    //Three solutions vary slightly but are functionally very similar and overhead is also same.
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if( (p == NULL && q == NULL) || (
            (p != NULL && q != NULL) &&
            (p->val == q->val) && 
            isSameTree(p->left, q->left) &&
            isSameTree(p->right, q->right)) ){ 
            return true;
        }
        return false;
    }

    bool _isSameTree2(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) 
            return true;
        // Because of the placement of this if statement after previous if this works flawlessly 
        // Since the above condition is checked there is no way both are NULL and it returns false despite the single condition says so.
        if(p == NULL || q == NULL) 
            return false;
        if(p->val != q->val) 
            return false;
        return _isSameTree2(p->left,q->left) && _isSameTree2(p->right,q->right);
    }

    bool _isSameTree3(TreeNode* p, TreeNode* q) {
        bool isSame = false;
        //isSame will be true if both node values is same and its sub tree is same is same
        if(p == NULL && q == NULL){
            isSame = true;
            return isSame;
        }
        if((p != NULL && q != NULL) && (p->val == q->val) && 
            _isSameTree3(p->left, q->left) &&
            _isSameTree3(p->right, q->right)){
                isSame = true;
                return isSame;
            }
        return isSame;
    }
};


TreeNode* create_hardcode1(){
    /*              4
            5               10
        7       8               1   
                                    6   */
    
    TreeNode *root; 
    // root = (TreeNode *)malloc(sizeof(TreeNode));
    root = new TreeNode(4);
    root->left = new TreeNode(5); 
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(8);

    root->right = new TreeNode(10); 
    root->right->right = new TreeNode(1);
    root->right->right->right = new TreeNode(6);
    return root;
}


TreeNode* create_hardcode2(){
    /*              4
            6               10
        7       8               1   
                                    6   */
    
    TreeNode *root; 
    // root = (TreeNode *)malloc(sizeof(TreeNode));
    root = new TreeNode(4);
    root->left = new TreeNode(6); 
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(8);

    root->right = new TreeNode(10); 
    root->right->right = new TreeNode(1);
    root->right->right->right = new TreeNode(6);
    // root->right->right->right = NULL;
    return root;
}


TreeNode* create_hardcode3(){
    /*              4
            6               10
        7       8               1   
                                       */
    
    TreeNode *root; 
    // root = (TreeNode *)malloc(sizeof(TreeNode));
    root = new TreeNode(4);
    root->left = new TreeNode(6); 
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(8);

    root->right = new TreeNode(10); 
    root->right->right = new TreeNode(1);
    // root->right->right->right = new TreeNode(6);
    // root->right->right->right = NULL;
    return root;
}

int main()
{
    TreeNode *root1 = create_hardcode1();
    TreeNode *root2 = create_hardcode2();
    TreeNode *root3 = create_hardcode3();
    Solution sol;
    // root1, root2, root3 are three different trees. root1 and root2 are similar but values are different. 
    // root1 , root3 are different by depth also
    bool temp1 = sol.isSameTree(root1, root1);
    bool temp2 = sol.isSameTree(root1, root2);
    bool temp3 = sol.isSameTree(root1, root3);
    bool temp4 = sol.isSameTree(root2, root3);

    cout << "return: " << temp1 << " " << temp2 << " " << temp3 << " " << temp4 << endl;
}