/* Definition for a binary tree node.
 * function TreeNode(val, left, right)
 * {
 *     this.val = (val===undefined ? 0 : val);
 *     this.left = (left===undefined ? null : left);
 *     this.right = (right===undefined ? null : right);
 * }
 */
/* @param {TreeNode} root
 * @return {void}
 */
let Node = function(ref, checked_left, checked_right)
{
    this.ref = ref;
    this.checked_left = checked_left;
    this.checked_right = checked_right;
};

let flatten = function(root)
{
    if (!root) return;
    let stack = [new Node(root, false, false)];
    let preorder = [root];
    while (stack.length)
    {
        let curr = stack.at(-1);
        if (curr.ref.left && !curr.checked_left)
        {
            curr.checked_left = true;
            stack.push(new Node(curr.ref.left, false, false));
            preorder.push(curr.ref.left);
        }
        else if (curr.ref.right && !curr.checked_right)
        {
            curr.checked_right = true;
            stack.push(new Node(curr.ref.right, false, false));
            preorder.push(curr.ref.right); 
        }
        else stack.pop();
    }
    for ([index, node] of preorder.entries())
    {
        node.left = null;
        if (index < (preorder.length - 1)) 
            node.right = preorder[index + 1];
    }
};