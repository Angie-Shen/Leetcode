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
������ȫ���ö����Ʊ�ʾ���Ե�ithλ���������ֵĺͶ�3ȡ�ֻ࣬�����������0��1. ȡ��Ľ������single number�ĵ�ithλ.

A straightforward implementation is to use an array of size 32 to keep track of the total count of ith bit. 
һ��ֱ�ӵ�ʵ�־����ô�СΪ32����������¼����λ�ϵĺ͡�

Reference:	http://www.acmerblog.com/leetcode-single-number-ii-5394.html
			https://oj.leetcode.com/discuss/857/constant-space-solution

�ⷨ1��
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

����㷨���иĽ��Ŀռ�ģ�����ʹ�����������

    ones   	�����ith λֻ����һ�ε��������
    twos	�����ith λֻ�������δε��������
    threes  �����ith λֻ�������ε��������

����������Ŀ�ͷ��������3��5����仯���£�
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

����ithλ����3��ʱ�����Ǿͽ�ones��twos�ĵ�ithλ����Ϊ0. ���յĴ𰸾���ones��

�ⷨ2��
	int singleNumber(int A[], int n) {
	    int ones = 0, twos = 0, threes = 0;
	    for (int i = 0; i < n; i++) {
	        twos |= ones & A[i];
	        ones ^= A[i];		//���3�κ����1�εĽ����һ����

	       	//����ones��twos�ѳ�����3�ε�λ������Ϊ0��ȡ��֮��1��λ��Ϊ0��
	        threes = ones & twos;
	        ones &= ~threes;
	        twos &= ~threes;
	    }
	    return ones;
	}