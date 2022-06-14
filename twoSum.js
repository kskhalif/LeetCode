/*
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */

let twoSum = function(nums, target) 
{
    let diffs = {};
    for (let i in nums)
    {
        let curr = nums[i];
        let diff = target - curr;
        let match = diffs[diff];
        if (match) return [i, match];
        else diffs[curr] = i; 
    }
};