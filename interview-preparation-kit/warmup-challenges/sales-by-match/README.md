<b>Compiling:</b> gcc -pedantic -std=c99 -Wall sales_by_match.c -o sales_by_match.o<br>
<b>Testing:</b> sh testing.sh

<h2>Problem</h2>
<p>
There is a large pile of socks that must be paired by color.<br>
Given an array of integers representing the color of each sock,<br>
determine how many pairs of socks with matching colors there are.<br>
</p>

<h3>Example</h3>
n = 7<br>
ar = [1, 2, 1, 2, 1, 3, 2]<br>
<p>
There is one pair of color <b>1</b> and one of color <b>2</b>.<br>
There are three odd socks left, one of each color.<br>
The number of pairs is <b>2</b>.
</p>

<h3>Function Description</h3>
Complete the <b>sock_merchant</b> function.<br>
This function has the following parameters:
<ul>
    <li>int ar[n]: the colors of each sock.</li>
    <li>int n: the number of socks in the pile.</li>
</ul>

<h3>Returns</h3>
<li>int: the number of pairs.</li>

<h3>Input Format</h3>
The first line contains an integer <b>n</b>, the number of socks represented in <b>ar</b>.<br>
The second line contains <b>n</b> space-separated integers, <b>ar[i]</b>, the colors of the socks in the pile.

<h3>Constraints</h3>
<ul>
    <li>1&#8804;n&#8804;100</li>
    <li>1&#8804;ar[i]&#8804;100, where 0&#8804;i<n</li>
</ul>

<h2>Samples</h2>
<h3>Sample Input 1</h3>
9<br>
10 20 20 10 10 30 50 10 20<br>

<h3>Sample Output 1</h3>
3<br>

<h3>Explanation 1</h3>
There are <b>3</b> pairs of socks, <b>2</b> of color 10 and <b>1</b> of color 20.<br>
There are three odd socks left.