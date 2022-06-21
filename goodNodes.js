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
 * @return {number}
 */

let findGoodNodes = function(node, max = -Infinity)
{
    let answer = 0;
    if (max <= node.val) 
    {
        ++answer;
        max = node.val;
    }
    if (node.left) answer += findGoodNodes(node.left, max);
    if (node.right) answer += findGoodNodes(node.right, max);
    return answer;
};

let goodNodes = function(root) 
{
    return findGoodNodes(root);
};