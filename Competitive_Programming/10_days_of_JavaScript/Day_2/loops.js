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

function vowelsAndConsonants(s) {
  const vowels =  s.match(/[aeiou]/gi).join('\n')

  const others = s.match(/[^aeiou]/gi).join('\n')

  console.log(vowels.concat('\n', others));   
}


function main() {
    const s = readLine();
    
    vowelsAndConsonants(s);
}
