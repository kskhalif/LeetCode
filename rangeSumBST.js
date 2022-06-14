/* Definition for a binary tree node.
 * function TreeNode(val, left, right)
 * {
 *     this.val = (val===undefined ? 0 : val);
 *     this.left = (left===undefined ? null : left);
 *     this.right = (right===undefined ? null : right);
 * }
 * @param {TreeNode} root
 * @param {number} low
 * @param {number} high
 * @return {number}
 */

/* Iterative Solution */
let rangeSumBST2 = function(root, low, high) 
{
    let stack = [root];
    let sum = 0;
    while (stack.length)
    {
        let curr = stack.at(-1);
        stack.pop();
        if (curr)
        {
            if (curr.val >= low && curr.val <= high) sum += curr.val;
            if (curr.val > low) stack.push(curr.left);
            if (curr.val < high) stack.push(curr.right);
        }
    }
    return sum;
};

/* Recursive Solution */
let rangeSumBST = function(root, low, high) 
{
    let sum = 0;
    if (root)
    {
        if (root.val >= low && root.val <= high) sum += root.val;
        if (root.val > low) sum += rangeSumBST(root.left, low, high);
        if (root.val < high) sum += rangeSumBST(root.right, low, high);
    }
    return sum;
};