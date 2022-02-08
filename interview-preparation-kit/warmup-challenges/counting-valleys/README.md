<b>Compiling and Testing</b><br>
<b>gcc</b> -pedantic -std=c99 -Wall counting_valleys.c -o counting_valleys.o<br>
<b>sh</b> testing.sh

<h2>Problem</h2>
An avid hiker keeps meticulous records of their hikes. During the last hike that took exactly <b>steps</b>, for every step it was noted if it was an uphill, <b>U</b>, or a downhill, <b>D</b> step. Hikes always start and end at sea level, and each step up or down represents a <b>1</b> unit change in altitude. We define the following terms:<br>
<ul>
    <li>A mountain is a sequence of consecutive steps above sea level, starting with a step up from sea level and ending with a step down to sea level.
    <li>A valley is a sequence of consecutive steps below sea level, starting with a step down from sea level and ending with a step up to sea level.
</ul>
Given the sequence of up and down steps during a hike, find and print the number of valleys walked through.

<h3>Example</h3>
<ul>
    <li>steps = 8</li>
    <li>path = [DDUUUUDD]</li>
</ul>
The hiker first enters a valley <b>2</b> units deep. Then climb out and up onto a mountain <b>2</b> units high.<br>
Finally, the hiker returns to sea level and ends the hike.<br>

<h3>Function Description</h3>
Complete the counting_valleys function.
This function has the following parameter(s):
<ul>
    <li>int steps: the number of steps on the hike.</li>
    <li>string path: a string describing the path.</li>
</ul>

<h3>Returns</h3>
<ul>
    <li>int: the number of valleys traversed.</li>
</ul>

<h3>Input Format</h3>
The first line contains an integer <b>steps</b>, the number of steps in the hike.<br>
The second line contains a single string <b>path</b>, of <b>steps</b> characters that describe the path.

<h3>Constraints</h3>
<ul>
    <li>2 &#8804; steps &#8804;10 <sup>6</li>
    <li>path[i] &#8712; {UD}</li>
</ul>

<h2>Samples</h2>
<h3>Sample Input</h3>
8<br>
UDDDUDUU

<h3>Sample Output</h3>
1

<h3>Explanation</h3>
The hiker enters and leaves <b>one</b> valley.