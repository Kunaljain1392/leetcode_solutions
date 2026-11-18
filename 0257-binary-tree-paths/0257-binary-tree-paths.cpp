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
    void help(TreeNode* root, vector<string> &ans, string &st) {
        

        if(root == NULL) {
            return;
        }
        int len = st.size();

        st += to_string(root->val);

        if(root->left == NULL && root->right == NULL) {
            ans.push_back(st);
        } else {

        

        st += "->";
        

        // left jao
        if(root->left) {
            help(root->left,ans,st);
        }
        

        // right jao
        if(root->right) {
            help(root->right,ans,st);
        }
        }
        st.resize(len);
        return;
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> ans;
        string st;
        help(root,ans,st);
        return ans;
    }
};