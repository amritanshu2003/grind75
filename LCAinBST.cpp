/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
/*
The beauty of finding LCA in a BST is that 
we continue traversing until the current node's value is no longer greater than both p and q, 
and no longer strictly less than both p and q. 
When that happens, the current node must be the LCA.
*/
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr){
            return root; //no lca found
        }
        //cur node is greater than p and smaller than q means its lca
        if( p->val <= root->val && root->val <= q->val ){
            return root;
        }
        // both p & q are smaller than root
        //q is smaller than root means lca is on the left side
        //since root is greater than both means we can find another ancestor on the left side which is closer to both p & q
        else if( p->val < root->val &&  q->val < root->val  ){
            return lowestCommonAncestor(root->left,p,q);
        }

        // both p & q are greater than root means LCA is on right side of root
        else if( p->val > root->val &&  q->val > root->val  ){
            return lowestCommonAncestor(root->right,p,q);
        }
        return root;
    }
};
