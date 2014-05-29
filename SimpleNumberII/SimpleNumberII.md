##Single Number II
###Question:
Given an array of integers, every element appears three times except for one. Find that single one. 
###Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 

###Analysis:
The requirement is O(n) time and O(1) space.
Thus, both "first sort and then find" (time complexity) and "hash map" (space complexity) are not working.

To solve this problem using only constant space, you have to rethink how the numbers are being represented in computers -- using bits.

If you sum the ith bit of all numbers and mod 3, it must be either 0 or 1 due to the constraint of this problem 
where each number must appear either three times or once. This will be the ith bit of that "single number".
把数字全部用二进制表示，对第ith位上所有数字的和对3取余，只会有两个结果0或1. 取余的结果就是single number的第ith位.

A straightforward implementation is to use an array of size 32 to keep track of the total count of ith bit. 
一个直接的实现就是用大小为32的数组来记录所有位上的和。

Reference:	http://www.acmerblog.com/leetcode-single-number-ii-5394.html
			https://oj.leetcode.com/discuss/857/constant-space-solution

解法1：
int singleNumber(int A[], int n) {
	int count[32] = {0};
    int result = 0;
	for (int i = 0; i < 32; i++) {
		for (int j = 0; j < n; j++) {
			if ((A[j] >> i) & 1) {
				count[i]++;
			}
		}
		result |= ((count[i] % 3) << i);
	}
	return result;
}

We can improve this based on the previous solution using three bitmask variables:

    ones as a bitmask to represent the ith bit had appeared once.
    twos as a bitmask to represent the ith bit had appeared twice.
    threes as a bitmask to represent the ith bit had appeared three times.

When the ith bit had appeared for the third time, clear the ith bit of both ones and twos to 0. The final answer will be the value of ones.

这个算法是有改进的空间的，可以使用掩码变量：

    ones   	代表第ith 位只出现一次的掩码变量
    twos	代表第ith 位只出现两次次的掩码变量
    threes  代表第ith 位只出现三次的掩码变量

假设在数组的开头连续出现3次5，则变化如下：
	ones = 101
	twos = 0
	threes = 0
	--------------
	ones = 0
	twos = 101
	threes = 0
	--------------
	ones = 0
	twos = 0
	threes = 101
	--------------

当第ith位出现3次时，我们就将ones和twos的第ith位设置为0. 最终的答案就是ones。

解法2：
	int singleNumber(int A[], int n) {
	    int ones = 0, twos = 0, threes = 0;
	    for (int i = 0; i < n; i++) {
	        twos |= ones & A[i];
	        ones ^= A[i];		//异或3次和异或1次的结果是一样的

	       	//对于ones和twos把出现了3次的位置设置为0（取反之后1的位置为0）
	        threes = ones & twos;
	        ones &= ~threes;
	        twos &= ~threes;
	    }
	    return ones;
	}