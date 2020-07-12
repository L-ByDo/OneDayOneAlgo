'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(string => {
        return string.trim();
    });

    main();
});

function readLine() {
    return inputString[currentLine++];
}
function getSecondLargest(nums) {
    // Complete the function
    var ans;
    nums.sort(function(a, b){return b - a});
    for (let i = 0; i<nums.length ; i++) {
        if (nums[i] !== nums[i+1]) {  ans = nums[i+1]; break; }
    }
    return ans;
}
function main() {
    const n = +(readLine());
    const nums = readLine().split(' ').map(Number);

    console.log(getSecondLargest(nums));
}
