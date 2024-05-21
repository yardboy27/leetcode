# Sliding Window Technique

## What is the Sliding Window Technique?

### Definition
**sliding window technique: efficiently solves problems that involve defining a window or range in the input data (arrays or strings) an dthen moves that window across the data to perform some operation within the window**

### Where is it used?
This technique is commonly used in algorithms that find subarrays with a specific sum, finding the longest substring with unique characters, solving problems that require a fixed-size window to process elements efficiently. 

### Example
Given an array of size `N` and an integer `K`. We have to calculate the maximum sum of a subarray having size exactly `K`. How should we approach the problem?
#### Approach 1: `O(n^2)`
We can take each subarray of size `K` from the array and find out the max sum of the subarrays. We can use nested loops, which will result in `O(n^2)` complexity.
#### Approach 2: `O(n)`
We can take one `K` sized subarray and calculate its sum from the `0` index to the `K-1` index. We will save this sum to a `max_sum` variable. We will then increase the "left pointer" (the `0` index) and the "right pointer" (`K-1` index) by `1`, and update the `max_sum` variable if it is larger than the current `max_sum`. We will continue this until we get to `N-1`.

The **Sliding Window Technique** uses Approach 2. Let us take a look at the two types of sliding window.
<hr/>
