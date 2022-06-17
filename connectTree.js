/**
 * // Definition for a Node.
 * function Node(val, left, right, next) 
 * {
 *    this.val = val === undefined ? null : val;
 *    this.left = left === undefined ? null : left;
 *    this.right = right === undefined ? null : right;
 *    this.next = next === undefined ? null : next;
 * };
 */
/**
 * @param {Node} root
 * @return {Node}
 */

let connect = function(root)
{
    if (!root) return root;
    let curr_level = [root];
    let level_count = 1;
    while (curr_level.length)
    {
        for (let i = 0; i < level_count; ++i)
        {
            let curr = curr_level.shift();
            if (curr.left && curr.right)
                curr_level.push(curr.left, curr.right);
            else return root;
        }
        for (let i = 1; i < curr_level.length; ++i)
        {
            curr_level[i - 1].next = curr_level[i];
        }
        level_count *= 2;
    }
    return root;
};