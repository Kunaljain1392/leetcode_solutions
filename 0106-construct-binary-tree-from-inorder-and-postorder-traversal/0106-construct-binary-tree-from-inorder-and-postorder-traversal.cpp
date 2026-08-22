/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) nt>& p: val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, unordered_map<int,int>& mp,int& postIdx, int inStart, int inEnd) {

        if(inStart > inEnd) {
            return NULL;
        }

        int rootVal = postorder[postIdx];
        postIdx--;

        int inIdx = mp[rootVal];

        TreeNode* root = new TreeNode(rootVal);

        
        root->right = build(inorder,postorder,mp,postIdx,inIdx+1,inEnd);
        root->left = build(inorder,postorder,mp,postIdx,inStart,inIdx-1);

        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++) {
            mp[inorder[i]] = i;
        }
        int postIdx = postorder.size()-1;
        return build(inorder,postorder,mp,postIdx,0,inorder.size()-1);
    }
};