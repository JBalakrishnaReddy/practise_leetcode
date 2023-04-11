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

#include <iostream>
#include <vector>

using namespace std;


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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vec;
        vec_preorder(vec, root);
        return vec;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vec;
        vec_postorder(vec, root);
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

    void vec_preorder(vector<int> &vec, TreeNode *root){
        if(root != NULL){
            vec.push_back(root->val);
            vec_preorder(vec, root->left);
            vec_preorder(vec, root->right);
        }
    }

    void vec_postorder(vector<int> &vec, TreeNode *root){
        if(root != NULL){
            vec_postorder(vec, root->left);
            vec_postorder(vec, root->right);
            vec.push_back(root->val);
        }
    }
};

void print_vector(vector<int> &vec, string msg = ""){
    cout << msg;
    for(int i=0; i < vec.size(); i++){
        cout << vec[i] << ',';
    }
    cout << endl;
}

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

int main()
{
    TreeNode *root = create_hardcode();
    Solution sol;
    vector<int> vec = sol.preorderTraversal(root);
    print_vector(vec, "preorder traversal: ");
    vec = sol.postorderTraversal(root);
    print_vector(vec, "postorder traversal: ");
    return 0;
}
