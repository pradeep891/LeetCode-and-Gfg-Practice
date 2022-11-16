/** 
 * Forward declaration of guess API.
 * @param {number} num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * var guess = function(num) {}
 */

/**
 * @param {number} n
 * @return {number}
 */
var guessNumber = function(n) {
    let l = 1 , h = n;
    while(l <= h){
        let m = l + (h -l)//2;
        let k = guess(m);
        if(k === 0) return m ;
        k === 1 ? l = m + 1 : h = m - 1;
    }
    return -1;
};

//     int guessNumber(int n) {
//         int low = 1; 
//         int high = n;
        
//         while(low <= high){
//             int mid = low + (high - low) / 2;
//             int k = guess(mid);
//             if(k == -1){
//                 high = mid - 1;
//             }
//             else if(k == 1){
//                 low = mid + 1;
//             }
//             else{
//                 return mid;
//             }
//         }
//         return -1;
//     }