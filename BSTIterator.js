/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */

/**
 * @param {TreeNode} root
 */
let BSTIterator = function(root) 
{
    this.index = -1;
    this.inorder = [];
    (function inOrderTraversal(node, inorder)
    {
        if (node.left) inOrderTraversal(node.left, inorder);
        inorder.push(node.val);
        if (node.right) inOrderTraversal(node.right, inorder);
    })(root, this.inorder);
};

/**
 * @return {number}
 */
BSTIterator.prototype.next = function() 
{
    return this.inorder[++this.index];
};

/**
 * @return {boolean}
 */
BSTIterator.prototype.hasNext = function() 
{
    return (this.index + 1 < this.inorder.length);
};

/** 
 * Your BSTIterator object will be instantiated and called as such:
 * var obj = new BSTIterator(root)
 * var param_1 = obj.next()
 * var param_2 = obj.hasNext()
 */