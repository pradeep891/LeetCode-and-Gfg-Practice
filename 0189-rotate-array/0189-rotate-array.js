/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var rotate = function(nums, k) {
    k = k % nums.length;
    
    nums.reverse();
    let numsleft = nums.slice(0 , k);
    numsleft.reverse();
    let numsright = nums.slice(k);
    numsright.reverse();
    
    nums.splice(0 , nums.length , ...numsleft, ...numsright);
};