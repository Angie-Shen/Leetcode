##Single Number
###Question:
Given an array of integers, every element appears twice except for one. Find that single one.
###Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 

###Analysis:
The requirement is O(n) time and O(1) space.
Thus, both "first sort and then find " and "hash map" are not working.

Since we can not sort the array, we shall find a cumulative way, which is not about the ordering.
XOR is a good way, we can use the property that A XOR A = 0, and A XOR B XOR A = B.

Reference: http://yucoding.blogspot.ca/2013/10/leetcode-question-single-number-i.html