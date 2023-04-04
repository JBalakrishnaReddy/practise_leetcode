#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector <int> vec;
        if (root == NULL){
            return vec;
        }
        vec_inorder(vec, root);
        return vec;
    }
private:
    void vec_inorder(vector<int> &vec, TreeNode *root){
        if(root != NULL){
            vec_inorder(vec, root->left);
            vec.push_back(root->val);
            vec_inorder(vec, root->right);
        }
    }
};

struct TreeNode *create_hardcode()
{
    /*              4
            5               10
        7       8               1   */
    struct TreeNode *new_node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    new_node->val = 4;
    new_node->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    new_node->left->val = 5;
    new_node->left->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    new_node->left->left->val = 7;
    new_node->left->left->left = NULL;
    new_node->left->left->right = NULL;
    new_node->left->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    new_node->left->right->val = 8;
    new_node->left->right->left = NULL;
    new_node->left->right->right = NULL;

    new_node->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    new_node->right->val = 10;
    new_node->right->left = NULL;
    new_node->right->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    new_node->right->right->val = 1;
    new_node->right->right->left =NULL;
    new_node->right->right->right = NULL;
    return new_node;
}

void print_vector(vector<int> &vec){
    for(int i=0; i < vec.size(); i++){
        cout << vec[i] << ',';
    }
    cout << endl;
}

int main()
{
    struct TreeNode *node = create_hardcode(); // This will create a sample tree 
    // display_preorder(node);
    // cout << endl;
    // vector<int> vec;
    // cout << "This is ";
    // display_inorder(node);
    // cout << endl;
    // vec_inorder(vec, node);  
    Solution sol;

    vector<int> vec = sol.inorderTraversal(node);
    print_vector(vec);
    
    return 0;
}