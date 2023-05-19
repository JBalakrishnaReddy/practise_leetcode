#include <iostream>
#include <vector>

#include "tr_essentials.cpp"

using namespace std;

class Solution {
public:
    int minDepth(TreeNode* root) {
        // return calc_depth(root, 0);
        if(root == NULL) return 0;
        return calcMinDepth(root);

    }
    int calcMinDepth(TreeNode *root){
        if(root == NULL) return INT32_MAX;
        if(root->left == NULL && root->right == NULL)   return 1;
        else    return 1 + min(calcMinDepth(root->left), calcMinDepth(root->right));
    }
};

class Solution1 {
    // This solution is direct but since it has many checks it is little slow. 
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL)   return 1;
        else{
            if(root->left != NULL && root->right != NULL)
                return 1 + min(minDepth(root->left), minDepth(root->right));
            else if (root->left != NULL)
                return 1 + minDepth(root->left);
            else
                return 1 + minDepth(root->right);
        }
    }
};

int main(){
    TreeNode *root = create_hardcode2();
    printTree(root, NULL, false);
    Solution1 sol;
    int temp = sol.minDepth(root);
    cout << "min depth: " << temp << endl;

    return 0;
}