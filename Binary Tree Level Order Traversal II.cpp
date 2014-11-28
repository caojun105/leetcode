/*
Binary Tree Level Order Traversal II Total Accepted: 24830 Total Submissions: 80430 My Submissions Question Solution 
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > res;
        list<TreeNode*> sameLayerElem;
        if(root==NULL)
            return res;
        else
            sameLayerElem.push_back(root);
        int sameLayerSize= sameLayerElem.size();
        
        while(sameLayerSize!=0)
        {
            int times=sameLayerSize;
            vector<int> sameLayerVec;
            TreeNode *tmp;
            while(times--!=0)
            {
                tmp = sameLayerElem.front();
                if(tmp->left!=NULL)
                    sameLayerElem.push_back(tmp->left);
                if(tmp->right!=NULL)
                    sameLayerElem.push_back(tmp->right);
                    
                sameLayerElem.pop_front();
                sameLayerVec.push_back(tmp->val);
            }
            sameLayerSize=sameLayerElem.size();
            res.push_back(sameLayerVec);
        }
        reverse(res.begin(),res.end());
        
    }
};

