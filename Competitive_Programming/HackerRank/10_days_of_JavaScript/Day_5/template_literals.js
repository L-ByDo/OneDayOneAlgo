"use strict";

process.stdin.resume();
process.stdin.setEncoding("utf-8");

let inputString = "";
let currentLine = 0;

process.stdin.on("data", (inputStdin) => {
  inputString += inputStdin;
});

process.stdin.on("end", (_) => {
  inputString = inputString
    .trim()
    .split("\n")
    .map((string) => {
      return string.trim();
    });

  main();
});

function readLine() {
  return inputString[currentLine++];
}

function sides(literals, a, p) {
  const root = (p ** 2 - 16 * a) ** 0.5;

  const s1 = (p + root) / 4;
  const s2 = (p - root) / 4;
  // if s1 and s1 are both positive s1 will always be greater than s2
  return [s2, s1];
}

function main() {
  let s1 = +readLine();
  let s2 = +readLine();

  [s1, s2] = [s1, s2].sort();

  const [x, y] = sides`The area is: ${s1 * s2}.\nThe perimeter is: ${
    2 * (s1 + s2)
  }.`;

  console.log(s1 === x ? s1 : -1);
  console.log(s2 === y ? s2 : -1);
}
