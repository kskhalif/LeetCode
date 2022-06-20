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
 * @param {number} k
 * @return {number}
 */
let kthSmallest = function(root, k) 
{
    let inorder = [];
    (function inOrderTraversal(node, inorder)
    {
        if (node.left) inOrderTraversal(node.left, inorder);
        inorder.push(node.val);
        if (node.right) inOrderTraversal(node.right, inorder);
    })(root, inorder);
    return inorder[k - 1];
};