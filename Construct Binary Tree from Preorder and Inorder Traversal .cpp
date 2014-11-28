/* Problem Demonstration::***************

Construct Binary Tree from Preorder and Inorder Traversal Total Accepted: 20800 Total Submissions: 78822 My Submissions Question Solution 
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

Show Tags
Have you met this question in a real interview? Yes  No
Discuss

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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        
        TreeNode *TreeNodeRoot = buildTreeHelp(preorder.begin(),inorder.begin(),inorder.size());
        return TreeNodeRoot;
    }
    
    
    TreeNode *buildTreeHelp(vector<int>::iterator preorder, vector<int>::iterator inorder, int size) 
    {
        if(size==0)
        {
            return NULL;
        }
        
        /*if only has one elements, just construct an TreeNode and return*/
        int rootVal=*preorder;
        TreeNode *TreeNodeRoot = new  TreeNode(0);
        TreeNodeRoot->val=rootVal;
        if(size ==1)
        {
            return TreeNodeRoot;
        }
        
        int leftlength=0;
        int rightlength=0;
        vector<int>::iterator leftTreeInorderNodeVal;
        vector<int>::iterator rightTreeInorderNodeVal;
        vector<int>::iterator leftTreePreorderNodeVal;
        vector<int>::iterator rightTreePreorderNodeVal;
        
        vector<int>::iterator iterInoder=inorder;
        vector<int>::iterator iterPreoder=preorder;
        iterPreoder++;
        
        leftTreeInorderNodeVal = iterInoder;    //set the left half tree
        leftTreePreorderNodeVal = iterPreoder;
        
        while(*iterInoder!=rootVal)             //cal the length of left tree and beginning of right half tree.
        {
            leftlength++;
            iterInoder++;
            iterPreoder++;
        }
        iterInoder++;
        
        rightTreeInorderNodeVal = iterInoder;  //set the right half tree
        rightTreePreorderNodeVal = iterPreoder;
        rightlength= size-leftlength-1;
    
        
        TreeNodeRoot->left=buildTreeHelp(leftTreePreorderNodeVal,leftTreeInorderNodeVal,leftlength);
        TreeNodeRoot->right=buildTreeHelp(rightTreePreorderNodeVal,rightTreeInorderNodeVal,rightlength);
        
        return TreeNodeRoot;
        
    }
};
