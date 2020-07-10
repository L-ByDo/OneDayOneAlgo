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

function getLetter(s) {
     switch (true) {
        case 'aeiou'.includes(s[0]):
            return 'A';
        case 'bcdfg'.includes(s[0]):
            return 'B';
        case 'hjklm'.includes(s[0]):
            return 'C';
        default: return 'D';
    }
}


function main() {
    const s = readLine();

    console.log(getLetter(s));
}
