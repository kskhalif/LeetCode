/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {TreeNode}
 */

let findAncestors = function(curr, dest, ancestors)
{
    if ((curr === dest) || 
        (curr.left && findAncestors(curr.left, dest, ancestors)) ||
        (curr.right && findAncestors(curr.right, dest, ancestors))) 
    {
        ancestors.push(curr);
        return true;
    }
    else return false;
};

let lowestCommonAncestor = function(root, p, q) 
{
    let p_ancestors = [], q_ancestors = [];
    findAncestors(root, p, p_ancestors);
    findAncestors(root, q, q_ancestors);
    let p_index = -1 * p_ancestors.length, q_index = -1 * q_ancestors.length;
    while (p_index < 0 && q_index < 0)
    {
        if (p_ancestors.at(p_index) === q_ancestors.at(q_index))
            return p_ancestors.at(p_index);
        
        else if (p_index < q_index)
            ++p_index;

        else if (q_index < p_index)
            ++q_index
        else 
        {
            ++p_index;
            ++q_index;
        }
    }
};