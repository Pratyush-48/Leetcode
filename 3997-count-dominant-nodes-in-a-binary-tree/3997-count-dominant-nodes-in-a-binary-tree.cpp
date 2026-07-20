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
class Solution {
public:
    int result = 0;
    int recc(TreeNode*root){
        if(!root){
            return -1;
        }
        int left = recc(root->left);
        int right = recc(root->right);
        int val = root->val;
        int maxi = max(left,right);
        maxi = max(maxi,val);
        if((left==-1 && right==-1) || val==maxi) result++;
        return max(maxi,val);
    }
    int countDominantNodes(TreeNode* root) {
        recc(root);
        return result;
    }
};