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
 * @return {number[]}
 */
let rightSideView = function(root) 
{
    if (!root) return [];
    let curr_level = [root];
    let next_level = [];
    let answer = [root.val];
    while (true)
    {
        for (node of curr_level)
        {
            if (node.left) next_level.push(node.left);
            if (node.right) next_level.push(node.right);
        }
        if (next_level.length)
        {
            answer.push(next_level.at(-1).val);
            curr_level = next_level;
            next_level = [];
        }
        else break;
    }
    return answer;
};