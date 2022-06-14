/* Definition for a binary tree node.
 * function TreeNode(val, left, right)
 * {
 *     this.val = (val===undefined ? 0 : val);
 *     this.left = (left===undefined ? null : left);
 *     this.right = (right===undefined ? null : right);
 * }
 * @param {TreeNode} root
 * @return {boolean}
 */

/* Iterative Solution */
let isUnivalTree2 = function(root)
{
    let stack = new Array(root);
    while (stack.length)
    {
        let curr = stack.at(-1);
        stack.pop();
        if (!curr.left)
        {
            if (!curr.right) continue;
            else if (curr.right.val === curr.val)
                stack.push(curr.right);
            else
                return false;
        }
        else if (!curr.right)
        {
            if (curr.left.val === curr.val) 
                stack.push(curr.left);
            else
                return false;
        }
        else if (curr.val === curr.left.val && curr.val === curr.right.val)
            stack.push(curr.left, curr.right);
        else
            return false;
    }
    return true;
};

/* Recursive Solution */
let isUnivalTree = function(root) 
{
    if (!root.left)
    {
        if (!root.right) return true;
        if (root.right.val === root.val)
            return isUnivalTree(root.right);
        else
            return false;
    }
    if (!root.right)
    {
        if (root.left.val === root.val) 
            return isUnivalTree(root.left);
        else
            return false;
    }
    if (root.val === root.left.val && root.val === root.right.val)
        return (isUnivalTree(root.left) && isUnivalTree(root.right));
    else
        return false;
};