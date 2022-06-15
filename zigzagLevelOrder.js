/* Definition for a binary tree node.
 * function TreeNode(val, left, right)
 * {
 *     this.val = (val===undefined ? 0 : val);
 *     this.left = (left===undefined ? null : left);
 *     this.right = (right===undefined ? null : right);
 * }
 * /
/* @param {TreeNode} root
 * @return {number[][]}
 */
let zigzagLevelOrder = function(root)
{
    if (!root) return [];
    let answer = [[root.val]];
    let queue = [[root]];
    let dir = 0;
    while (queue.length)
    {
        let curr_level = queue.shift();
        let next_level = [];
        let vals = [];
        for (node of curr_level)
        {
            if (node.left)
            { 
                next_level.push(node.left);
                vals.push(node.left.val);
            }
            if (node.right)
            { 
                next_level.push(node.right);
                vals.push(node.right.val);
            }
        }
        if (++dir % 2 === 1) vals.reverse();
        if (next_level.length)
        { 
            queue.push(next_level);
            answer.push(vals);
        }
    }
    return answer;
};