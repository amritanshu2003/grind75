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
    int height(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int maxHeight = std::max(leftHeight, rightHeight);
        return 1 + maxHeight;
    }

/*
For the current root node
  if root node is empty then tree is balanced
  find the height of left child
  find the height of right child
  take a difference of left & right height & 
  check if the height difference is greater than 1 then binary tree is not balanced
  repeat this for all the nodes.

To find the height
  Find the height of each left & right child
  Choose the max of left & right height as the height of the root
  Add 1 to the max to represent current node's height.
*/
    bool isBalanced(TreeNode* root) {
        if(root==nullptr){
            return true;
        }
        //bool leftBalanced = isBalanced(root->left) ;
        //bool rightBalanced = isBalanced(root->right) ;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int heightDiff = leftHeight-rightHeight;
        int absHeight = std::abs(heightDiff);
        if (absHeight > 1){
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right) ;
    }
};
