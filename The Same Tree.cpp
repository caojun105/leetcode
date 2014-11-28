/*Same Tree Total Accepted: 38398 Total Submissions: 91676 My Submissions Question Solution 
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p==NULL)
        {
            return q==NULL;
        }
        if(q==NULL)
        {
            return p==NULL;
        }
	if(p->val==q->val)
        {
            return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
        }
        else
        {
            return false;
        }
    }
};


