#include <iostream>
#include <vector>
#include <string>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    inline TreeNode() : val(0), left(nullptr), right(nullptr) {}
    inline TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    inline TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct Trunk
{
    Trunk *prev;
    std::string str;
 
    Trunk(Trunk *prev, std::string str)
    {
        this->prev = prev;
        this->str = str;
    }
};
 
// Helper function to print branches of the binary tree
void showTrunks(Trunk *p)
{
    if (p == nullptr) {
        return;
    }
 
    showTrunks(p->prev);
    std::cout << p->str;
}
 
void printTree(TreeNode* root, Trunk *prev, bool isLeft)
{
    if (root == nullptr) {
        return;
    }
 
    std::string prev_str = "    ";
    Trunk *trunk = new Trunk(prev, prev_str);
 
    printTree(root->right, trunk, true);
 
    if (!prev) {
        trunk->str = "———";
    }
    else if (isLeft)
    {
        trunk->str = ".———";
        prev_str = "   |";
    }
    else {
        trunk->str = "`———";
        prev->str = prev_str;
    }
 
    showTrunks(trunk);
    std::cout << " " << root->val << std::endl;
 
    if (prev) {
        prev->str = prev_str;
    }
    trunk->str = "   |";
 
    printTree(root->left, trunk, false);
}
 

// The below functions simply create trees.
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
