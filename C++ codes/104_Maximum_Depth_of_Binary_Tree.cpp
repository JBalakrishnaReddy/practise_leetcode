#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#include <stdbool.h>

using namespace std;

//Definition for a binary tree node.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    inline TreeNode() : val(0), left(nullptr), right(nullptr) {}
    inline TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    inline TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

class Solution {
public:
    int maxDepth(TreeNode* root) {
        int left_max_depth = 0;
        int right_max_depth = 0;
        int max_depth = 0;
        if(root != NULL)
        {
            // cout << "root val: " << root->val << endl;
            ++max_depth; // because we need to add the current layer also.
            left_max_depth = maxDepth(root->left);
            right_max_depth = maxDepth(root->right);
            max_depth += left_max_depth>right_max_depth ? left_max_depth:right_max_depth ;
            // cout << "node val: " << root->val << "left_max_depth: " << left_max_depth << \
            //         " right_max_depth: " << right_max_depth << "max_depth: " << max_depth << endl;
            return max_depth;
        }
        // cout << "no modifications to max_depth as null found" << endl;
        return max_depth;
        // int depth = 0;
        // int maxdepth = 0;
        // getDepth(root, depth, maxdepth);
        // return depth;
    }
private:
    void getDepth(const TreeNode *root, int& depth, int &maxdepth){
        //This is a recursive funcion and will iterate till it covers all the nodes
        cout << "val: " << root->val << endl;
        if(root == NULL)
            return;
        ++depth;
        int temp_depth = depth;
        getDepth(root->left, depth, maxdepth);
        if (depth > maxdepth){
            maxdepth = depth;
            cout << "maxdepth modified at line: " << __LINE__ << "max_depth: " << maxdepth << endl;
        }
        depth = temp_depth;
        getDepth(root->right, depth, maxdepth);
        if (depth > maxdepth){
            maxdepth = depth;
            cout << "maxdepth modified at line: " << __LINE__ << "max_depth: " << maxdepth << endl;
        }
        depth = temp_depth;
    }
public:
    int get_max_depth(TreeNode *root){
        int left_max_depth = 0;
        int right_max_depth = 0;
        int max_depth = 0;
        if(root != NULL)
        {
            cout << "root val: " << root->val << endl;
            ++max_depth; // because we need to add the current layer also.
            left_max_depth = get_max_depth(root->left);
            right_max_depth = get_max_depth(root->right);
            max_depth += left_max_depth>right_max_depth ? left_max_depth:right_max_depth ;
            cout << "node val: " << root->val << "left_max_depth: " << left_max_depth << \
                    " right_max_depth: " << right_max_depth << "max_depth: " << max_depth << endl;
            return max_depth;
        }
        cout << "no modifications to max_depth as null found" << endl;
        return max_depth;
    }
};



class Solution_traversal {
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

TreeNode* create_hardcode(){
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

int main()
{
    TreeNode *root = create_hardcode();
    Solution_traversal sol;
    vector<int> vec = sol.preorderTraversal(root);
    print_vector(vec, "preorder traversal: ");
    Solution sol1;
    int temp = sol1.get_max_depth(root);
    cout << "max_depth: " << temp << endl;
    return 0;
}