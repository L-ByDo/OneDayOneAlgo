<h2>Triplet Sum </h2><br>
Given an array of integers and a target value `k`. We are required to find a triplet from the array so that its sum is equal to `k`. <br>
Here we will look at two different solutions.<br>
1) The first one is a naive solution which involves the use of three nested `for loops` to check every possible triplet in the array. Its time complexity is `O(n<sup>3</sup>)`. <br>
2) The next one involves an algorithm which uses the two pointer technique, where we first sort the array, then loop over each element by fixing
   two pointer variables and check if the sum is `>` or `<` or `==` to `k`. Its time complexity is reduces to `O(n<sup>2</sup>)`

To see the difference our optimized solution has made, e will use the Python's timeit library to compare both the solutions.<br>
To know more about timeit, check out the [docs](https://docs.python.org/3/library/timeit.html)
