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
     
    void solve(int sum,TreeNode* root, int targetSum,vector<int>&ds,vector<vector<int>>&ans){
        if(root==NULL){return;}

        ds.push_back(root->val);
        sum+=root->val;

        if(root->left==NULL and root->right==NULL and sum==targetSum){
            ans.push_back(ds);
            
        }

        solve(sum,root->left,targetSum,ds,ans);
        solve(sum,root->right,targetSum,ds,ans);

        ds.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==NULL){return {};}
        vector<vector<int>>ans;
        vector<int>ds;
        solve(0,root,targetSum,ds,ans);
        return ans;
    }
};