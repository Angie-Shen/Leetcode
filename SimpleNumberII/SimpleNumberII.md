##Single Number II
###Question:
Given an array of integers, every element appears three times except for one. Find that single one. 
###Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 

###Analysis:
The requirement is O(n) time and O(1) space.
Thus, both "first sort and then find" (time complexity) and "hash map" (space complexity) are not working.

We still use bit operation. The computer stores numbers in binary format. According to the question, only one of the numbers appears once. 
Thus, if we calculate the sum of ith bit of all the numbers and then modulo 3, the result could be only 0 or 1. 
������ȫ���ö����Ʊ�ʾ���Ե�ithλ���������ֵĺͶ�3ȡ�ֻ࣬�����������0��1. ��ȡ��Ľ�����Ͼ����Ǹ�single number.

һ��ֱ�ӵ�ʵ�־����ô�СΪ32����������¼����λ�ϵĺ͡�