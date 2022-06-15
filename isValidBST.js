/* Definition for a binary tree node.
 * function TreeNode(val, left, right)
 * {
 *     this.val = (val===undefined ? 0 : val);
 *     this.left = (left===undefined ? null : left);
 *     this.right = (right===undefined ? null : right);
 * }
 * /
/* @param {TreeNode} root
 * @return {boolean}
 */

/* Iterative Solution */
let Obj = function(node, min, max)
{
    this.node = node;
    this.min = min;
    this.max = max;
};

let isValidBST2 = function(root)
{
    let stack = [new Obj(root, -Infinity, Infinity)];
    while (stack.length)
    {
        let curr = stack.at(-1);
        stack.pop();
        if (curr.node)
        {
            if (curr.node.val <= curr.min || curr.node.val >= curr.max)
                return false;
            stack.push(new Obj(curr.node.left, curr.min, curr.node.val), 
                       new Obj(curr.node.right, curr.node.val, curr.max));
        }
    }
    return true;
};

/* Recursive Solution */
let validate = function(node, min = -Infinity, max = Infinity)
{
    if (!node) return true;
    if (node.val <= min || node.val >= max) return false;
    return (validate(node.left, min, node.val) && 
            validate(node.right, node.val, max));
};

let isValidBST = function(root)
{
    return validate(root);
};