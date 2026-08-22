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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,
    unordered_map<int,int>& mp, int& preIdx, int inStart, int inEnd) {
        if(inStart > inEnd) {
            return NULL;
        }
        int rootVal = preorder[preIdx];
        preIdx++;
        int inIdx = mp[rootVal];

        TreeNode* root = new TreeNode(rootVal);
        
            root->left = build(preorder,inorder,mp,preIdx,inStart,inIdx-1);
        
            root->right =  
                 build(preorder,inorder,mp,preIdx,inIdx+1,inEnd);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++) {
            mp[inorder[i]] = i;
        }
        int preIdx = 0;
        return build(preorder,inorder,mp,preIdx,0,inorder.size()-1);
    }
};