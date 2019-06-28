### poj

following solutions are lost:

1182(three union-find) 

1185(dp)

1986(tarjan)

#### some algorithms and problems

- line segment tree: [total area and perimeter of overlaped rectangles](https://blog.csdn.net/tomorrowtodie/article/details/52048323)

- 妈个鸡poj1187搞了3天才把思路终于搞明白，网上解题报告实在太烂了（明明是我自己太蠢了555555），直接看代码很难理解dp的原理。这里记录下：
    
    dp[i][j][k][d]代表{}有i个，[]有j个，()有k个可以组成深度小于等于d的方案个数。那么dp[i][j][k][d]转移函数可以写作a × b，a和b分别代表两个子串，a代表第一个子串，子串就是{[]}这样没有拼接的串，剩下的好多个子串>的合并为b，那么我们只需要穷举子串a最外边的括号的可能性，比如当a最外边为()时，那么这种情况下就有$ \sum_{k_1} dp[0][0][k_1-1][d-1] \times dp[i][j][k-k_1][d] $ 个可能的情况，可以理解为当a最外边括号为（）时，那么a里面的所有括号也必定是（），那么乘法左边就代表a的（）里面所有的可能性，由于这个不算最外层的（），所以深度小于等于d-1，而右边代表b的所有可能性，同理也可以穷举[]和{}和里面的情况。

    难以理解的点在于，为什么这种转移函数可以保证没有重复也没有遗漏。这也是困扰我这么久的主要问题。最主要的原因在于这个小于等于d已经包含了这一状态的所有情况，而左边的穷举状态每次都是唯一的，换言之，乘法左边的项是穷举了在d-1情况下的所有的只有一个嵌入式括号的可能性，这当然可以保证无重复。

    感觉自己写的也不是很容易让不懂的人看懂，有啥疑问可以提issue哈。

#### some tips

add ```#define _CRT_SECURE_NO_WARNINGS``` to prevent warning of scanf in visual studio

a great oi website [oi-wiki](https://oi-wiki.org)


