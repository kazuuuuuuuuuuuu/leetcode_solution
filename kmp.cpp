#include <iostream>
#include <string>
#include <cstdio>

using namespace std;


static void build_next(int arr[], int n, const string &pattern)
{
	// next 数组的形成过程也像在主串中找相等的模式串一样
	// 每次j都从第一个位置出发 判断两个前后缀字串是否相等 如果相等 j++ i++
	// 如果失配了 那么前面遍历过的都相等
	// 可以用next值回退前缀串相等的位置
	int j = 0; // 含义1当前最长相等前后缀 含义2指向待测试前缀末尾
	arr[0] = 0;
	for(int i=1;i<n;i++) // i 指向待确定的后缀末尾
	{
		// 递归求解next数组 -> 由上一个j计算出下一个j
		// 不相等 -> 回退
		while(j>0&&pattern[i]!=pattern[j])
		{
			j = arr[j-1]; // 前一个位置的next数组值 回退
		}

		// 1 相等
		if(pattern[i]==pattern[j])
		{
			j ++;
			arr[i] = j;
		}
		else // j = 0 且 pattern[i]!=pattern[j];
		{
			arr[i] = 0;
		}
	}
}

int kmp(const string &target, const string &pattern)
{
	int n = pattern.size();
	int *next = new int[n];

	build_next(next, n, pattern);
	for(int i=0;i<n;i++)
	{
		printf("%d\t", next[i]);
	}
	printf("\n");	
	int i = 0;
	int j = 0;
	while(i<target.size())
	{
		if(target[i]==pattern[j]) // 字符匹配成功，测试下一个位置
		{
			i ++;
			j ++;
			if(j==pattern.size()) // 已经越界，匹配成功，返回目标串中的起始位置下标
			{
				return i - j;
			}			
		}
		else if(j>0) // 字符匹配失败，j使用next数组回退，再进行测试
		{
			j = next[j-1];
		}
		else // 字符匹配失败，而j已经到起点无法回退，测试下一个位置，i++
		{
			i ++;
		}
	}
	delete[] next;
	return -1; // 未找到匹配字串
}

int main(int argc, char const *argv[])
{
	string target = "ababzabacababbcaa";
	string pattern = "abacabab";
	int i = kmp(target, pattern);
	cout << "target: " << target << endl;
	cout << "pattern: " << pattern << endl;
	cout << "匹配位置下标: " << i << endl;
	return 0;
}