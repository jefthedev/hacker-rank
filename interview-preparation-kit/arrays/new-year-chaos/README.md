<b>Compiling and Testing</b><br>
<b>gcc</b> -pedantic -std=c99 -Wall new_year_chaos.c -o new_year_chaos.o<br>
<b>sh</b> testing.sh

<h2>Problem</h2>
It is New Year's Day and people are in line for the Wonderland Rollercoaster ride. Each person wears a sticker indicating their initial position in the queue from <b>1</b> to <b>n</b>. Any person can bribe the person directly in front of them to swap positions, but they still wear their original sticker. One person can bribe at most two others.<br>
Determine the minimum number of bribes that took place to get to a given <b>queue</b> order. Print the number of bribes, or, if anyone has bribed more than two people, print "Too chaotic".<br>

<h3>Example</h3>
<b>q = [1, 2, 3, 5, 4, 6, 7, 8]</b><br>
If person <b>5</b> bribes person <b>4</b>, the queue will look like this: <b>1, 2, 3, 4, 5, 6, 7, 8</b>. Only <b>1</b> bribe is required. Print <b>1</b>.<br>
<b>q = [4, 1, 2, 3]</b><br>
Person <b>4</b> had to bribe <b>3</b> people to get to the current position. Print "Too chaotic".<br>

<h3>Function Description</h3>
Complete the function minimum_bribes. This function has the following parameters:
<ul>
    <li>int q_count: numbers of people in line.</li>
    <li>int q[n]: the positions of the people after all bribes</li>
</ul>

<h3>Returns</h3>
No value is returned. Print the minimum number of bribes necessary or "Too chaotic" if someone has bribed more than <b>2</b> people.

<h3>Input Format</h3>
The first line contains an integer <b>t</b>, the number of test cases.<br>
Each of the next <b>t</b> pairs of lines are as follows:
<ul>
    <li>The first line contains an integer <b>p</b>, the number of people in the queue.</li>
    <li>The second line has <b>p</b> space-separated integers describing the final state of the queue.</li>
</ul>

<h3>Constraints</h3>
<ul>
    <li>1 &#8804; t &#8804; 10</li>
    <li>1 &#8804; n &#8804; 10<sup>5</li>
</ul>

<h3>Substasks</h3>
<ul>
    <li>For 60% score 1 &#8804; n &#8804; 10<sup>3<</li>
    <li>For 100% score 1 &#8804; n &#8804; 10<sup>5</li>
</ul>

<h2>Samples</h2>
<h3>Sample Input</h3>
2<br>
5<br>
2 1 5 3 4<br>
5<br>
2 5 1 3 4

<h3>Sample Output</h3>
3<br>
Too chaotic

<h3>Explanation</h3>
<ul>
    <li>Test Case 1: 5 &rarr; 4, 5 &rarr; 3, 2 &rarr; 1. So the final state is <b>2, 1, 5, 3, 4</b>.</li>
    <li>Test Case 2: No person can bribe more than <b>2</b> people, yet it appears person <b>5</b> has done so. It is not possible to achieve the input state.</li>
</ul>