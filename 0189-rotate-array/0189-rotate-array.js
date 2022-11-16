/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var rotate = function(nums, k) {
    k = k % nums.length;
    // console.log(k);
    
    if(k === 0) return;
    let end = nums.slice(-k);
    nums.splice(nums.length - k);
    // console.log(nums);
    // console.log(end);
    nums.splice(0 , 0, ...end);
};