#include "string.h"
using namespace std;


/*
* 请实现一个函数，把字符串 s 中的每个空格替换成"%20"
*/
string StringSolution::replaceSpace(string s)
{
        //定义一个要统计替换空格数量的count，获取字符串长度的len
        int count = 0, len = s.size();
        // 统计空格数量
        for (int i = 0; i < len; i++)
        {   
            if (s[i] == ' ')
                count++;

        }
        // 修改 s 长度
        s.resize(len + 2 * count);
        // 倒序遍历修改
        for (int i = len - 1, j = s.size() - 1; i < j; i--, j--) {
            if (s[i] != ' ')
                s[j] = s[i];
            else {
                s[j - 2] = '%';
                s[j - 1] = '2';
                s[j] = '0';
                j -= 2;
            }
        }
        return s;
}



/*
* 字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部
* 请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"
* 
*   reverse()函数 实现翻转 数组，字符串，向量
*   s.begin() 字符串的头位置   string[0]
*   s.end()  字符串的尾位置   string[s.size()-1]
*/

string StringSolution::reverseLeftWords(string s, int n)
{
    reverse(s.begin(), s.begin() + n);
    reverse(s.begin() + n, s.end());
    reverse(s.begin(), s.end());
    return s;

}