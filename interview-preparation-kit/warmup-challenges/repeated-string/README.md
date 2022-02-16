<b>Compiling:</b> gcc -pedantic -std=c99 -Wall repeated_string.c -o repeated_string.o<br>
<b>Testing:</b> sh testing.sh

<h2>Problem</h2>
<p>
There is a string <b>s</b> of lowercase English letters that is repeated infinitely many times.<br>
Given an integer <b>n</b> find and print the number of letter <b>a</b>'s in the first <b>n</b> letters of the infinite string.
</p>

<h3>Example</h3>
s = "abcac"<br>
n = 10<br>
<p>
The substring we consider is <b>abcacabcac</b>, the first <b>10</b> characters of the infinite string.<br> 
There are <b>4</b> occurrences of <b>a</b> in the substring.
</p>

<h3>Function Description</h3>
Complete the <b>repeated_string</b> function.<br>
This function has the following parameters:
<ul>
    <li>string s: a string to repeat.</li>
    <li>int n: the number of characters to consider.</li>
</ul>

<h3>Returns</h3>
long: the frequency of <b>a</b> in the substring.

<h3>Input Format</h3>
The first line contains a single string, <b>s</b>.<br>
The second line contains an integer, <b>n</b>.<br>

<h3>Constraints</h3>
<ul>
    <li>1&#8804;|s|&#8804;100</li>
    <li>1&#8804;n&#8804;10<sup>12</sup></li>
    <li>For 25% of the test cases, n&#8804;10<sup>6</sup></li>
</ul>

<h2>Samples</h2>
<h3>Sample Input 1</h3>
aba<br>
10<br>

<h3>Sample Output 1</h3>
7<br>

<h3>Explanation 1</h3>
The first <b>n=10</b> letters of the infinite string are <b>abaabaabaa</b>.<br>
Because there are <b>7</b> a's, we return <b>7</b>.<br>

<h3>Sample Input 2</h3>
a<br>
1000000000000<br>

<h3>Sample Output 2</h3>
1000000000000<br>

<h3>Explanation 2</h3>
Because all of the first <b>n=1000000000000</b> letters of the infinite string are a's,<br>
we return <b>1000000000000</b>.<br>