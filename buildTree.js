/* Definition for a binary tree node.
 * function TreeNode(val, left, right)
 * {
 *     this.val = (val===undefined ? 0 : val);
 *     this.left = (left===undefined ? null : left);
 *     this.right = (right===undefined ? null : right);
 * }
 */
/* @param {number[]} preorder
 * @param {number[]} inorder
 * @return {TreeNode}
 */
let buildTree = function(preorder, inorder) 
{
    let root = new TreeNode(preorder[0], null, null);
    let curr = root;
    let stack = [root];
    let pre_index = 1, in_index = 0;
    let popped = false;
    while (pre_index < preorder.length)
    {
        if (stack.length && stack.at(-1).val === inorder[in_index])
        {
            curr = stack.at(-1);
            stack.pop();
            popped = true;
            ++in_index;
        }
        else
        {
            if (!popped)
            {
                curr.left = new TreeNode(preorder[pre_index], null, null);
                curr = curr.left;
            }
            else
            {
                popped = false;
                curr.right = new TreeNode(preorder[pre_index], null, null);
                curr = curr.right;
            }
            stack.push(curr);
            ++pre_index;
        }
    }
    return root;
};