#include <iostream>
#include <vector>
#include <string>
#include "tr_essentials.cpp"

using namespace std;


class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool res = false;
        if(root == NULL)    return false;
        res = pathSum(root, targetSum, 0);
        return res;
    }

    int pathSum(TreeNode* node, int targetSum, int currentSum){
        int sum = currentSum + node->val;
        bool res = false;
        if(node->left == NULL && node->right == NULL && sum == targetSum){
            return true;
        }else{
            if(node->left != NULL){
                res = pathSum(node->left, targetSum, sum);
            }
            if(!res && node->right != NULL){
                res = pathSum(node->right, targetSum, sum);
            }
        }
        return res;
    }
};

int main(){
    TreeNode *root = create_hardcode1();
    printTree(root, NULL, false);
    TreeNode *root2 = create_hardcode2();
    printTree(root2, NULL, false);
    Solution sol;
    bool res = sol.hasPathSum(root2, 18);   // Answer should be true
    cout << "res: " << res << endl;
    return 0;
}