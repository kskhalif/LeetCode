/* Definition for a binary tree node.
 * function TreeNode(val, left, right)
 * {
 *     this.val = (val===undefined ? 0 : val);
 *     this.left = (left===undefined ? null : left);
 *     this.right = (right===undefined ? null : right);
 * }
 * @param {TreeNode} root1
 * @param {TreeNode} root2
 * @return {TreeNode}
 */

/* Iterative Solution */
let mergeTrees2 = function(root1, root2)
{
    if (!root1) { return root2; }
    if (!root2) { return root1; }
    let stack = [[root1, root2]];
    let curr1, curr2;
    while (stack.length)
    {
        curr1 = stack.at(-1)[0];
        curr2 = stack.at(-1)[1];
        stack.pop();
        if (!curr1) { curr1 = curr2; }
        else if (curr2)
        {
            curr1.val += curr2.val;
            if (!curr1.left) { curr1.left = curr2.left; }
            else { stack.push([curr1.left, curr2.left]); }
            if (!curr1.right) { curr1.right = curr2.right; }
            else { stack.push([curr1.right, curr2.right]); }
        }
    }
    return root1;
};

/* Recursive Solution */
let mergeTrees = function(root1, root2) 
{
    if (!root1) return root2;
    if (!root2) return root1;
    root1.val += root2.val;
    root1.left = mergeTrees(root1.left, root2.left);
    root1.right = mergeTrees(root1.right, root2.right);
    return root1;
};