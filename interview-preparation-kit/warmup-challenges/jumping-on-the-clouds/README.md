<b>Compiling and Testing</b><br>
<b>gcc</b> -pedantic -std=c99 -Wall jumping_on_the_clouds.c -o jumping_on_the_clouds.o<br>
<b>sh</b> testing.sh

<h2>Problem</h2>
<p>
There is a new mobile game that starts with consecutively numbered clouds. Some of the clouds are thunderheads and others are cumulus.<br>
The player can jump on any cumulus cloud having a number that is equal to the number of the current cloud plus <b>1</b> or <b>2</b>.<br>
The player must avoid the thunderheads. Determine the minimum number of jumps it will take to jump from<br>
the starting position to the last cloud. It is always possible to win the game.<br>
For each game, you will get an array of clouds numbered <b>0</b><br>
if they are safe or <b>1</b> if they must be avoided.
</p>

<h3>Example</h3>
<b>c = [0, 1, 0, 0, 0, 1, 0]</b><br>
Index the array from <b>0 ... 6</b>. The number on each cloud is its index in the list so the player must avoid the clouds at indices <b>1</b> and <b>5</b>.<br>
They could follow these two paths: <b>0 &rarr; 2 &rarr; 4 &rarr; 6</b>  or <b>0 &rarr; 2 &rarr; 3 &rarr; 4 &rarr; 6</b>.<br>
The first path takes <b>3</b> jumps while the second takes <b>4</b>. So return <b>3</b>.

<h3>Function Description</h3>
Complete the jumping_on_the_clouds function.<br>
This function has the following parameters:
<ul>
    <li>int c_count: the number of clouds.</li>
    <li>int c[n]: an array of binary integers representing clouds.</li>
</ul>

<h3>Returns</h3>
<ul>
    <li>int: the minimum number of jumps required.</li>
</ul>

<h3>Input Format</h3>
The first line contains an integer <b>n</b>, the total number of clouds.<br>
The second line contains <b>n</b> space-separated binary integers describing clouds <b>c[i]</b> where <b>0 &#8804; i < n</b>.</br>

<h3>Constraints</h3>
<ul>
    <li>2&#8804;n&#8804;100</li>
    <li>c[i] &#8712; {0, 1}</li>
    <li>c[0] = c[n-1] = 0</li>
</ul>

<h3>Output Format</h3>
Print the minimum number of jumps needed to win the game.<br>

<h2>Samples</h2>
<h3>Sample Input 1</h3>
7<br>
0 0 1 0 0 1 0<br>

<h2>Sample Output 1</h2>
4

<h2>Explanation 1</h2>
The player must avoid <b>c[2]</b> and <b>c[5]</b>.<br>
The game can be won with a minimum of <b>4</b> jumps.

<h3>Sample Input 2</h3>
6<br>
0 0 0 0 1 0<br>

<h2>Sample Output 2</h2>
3

<h2>Explanation 2</h2>
The only thundercloud to avoid is <b>c[4]</b>.<br>
The game can be won in <b>3</b> jumps.