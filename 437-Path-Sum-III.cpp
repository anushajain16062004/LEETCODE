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

    int countNode(TreeNode* root, int targetSum,long long sum){
        if(root==NULL){return 0;}
        sum+=root->val;

        int count= (sum==targetSum)?1:0;

        count+=countNode(root->left,targetSum,sum);
        count+=countNode(root->right,targetSum,sum);

        return count;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL){return 0;} 

        int pathFromRoot= countNode(root,targetSum,0);
        int pathOnLeft=pathSum(root->left,targetSum);
        int pathOnRight=pathSum(root->right,targetSum);

        return pathFromRoot+pathOnLeft+pathOnRight;
    }
};