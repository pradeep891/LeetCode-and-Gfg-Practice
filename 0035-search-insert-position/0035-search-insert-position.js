/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    var i = 0 , j = nums.length-1;
    while(i <= j){
        var m = i + (j-i)//2;
        // console.log(m);
        if(nums[m] === target) return m;
        if(nums[m] > target) j = m - 1;
        else i = m + 1;
    }
    return j + 1;
};