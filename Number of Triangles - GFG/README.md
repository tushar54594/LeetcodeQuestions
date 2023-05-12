# Number of Triangles
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given a 2D matrix <strong>g </strong>contains only <strong>1</strong> and<strong> 0</strong>, count the number of triangles in it.<br>
Take 3 index i,j,k (0&lt;=i,j,k&lt;n). {i,j}, {j,k}, {k,i} will form a triangle if&nbsp;i!=j and&nbsp;i!=k and j!=k and g[i][j]=1 and g[j][k]=1 and g[k][i]=1.</span></p>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
N=4
graph[][]={{0, 0, 1, 0}, 
           {1, 0, 0, 1},
&nbsp;          {0, 1, 0, 0}, 
&nbsp;          {0, 0, 1, 0}}
<strong>Output:</strong>
2
<strong>Explanation;
</strong>Triangle 1: {{0,2}, {2,1}, {1,0}}
graph[][]={{0, 0, <span style="color:#FF0000">1</span>, 0},
           {<span style="color:#FF0000">1</span>, 0, 0, 1},
&nbsp;          {0, <span style="color:#FF0000">1</span>, 0, 0},
&nbsp;          {0, 0, 1, 0}}.  

Triangle 2: {{1,3}, {3,2}, {2,1}}
graph[][]={{0, 0, 1, 0},
           {1, 0, 0, <span style="color:#FF0000">1</span>},
&nbsp;          {0, <span style="color:#FF0000">1</span>, 0, 0},
&nbsp;          {0, 0, <span style="color:#FF0000">1</span>, 0}}. 
</span>
</pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Your task is to complete the function <strong>numberOfTriangles()</strong>&nbsp;which takes the 2D matrix&nbsp;g[][], it's number of nodes&nbsp;N<strong>&nbsp;</strong>as input parameters&nbsp;and returns the number of triangles in it.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N*N*N)<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(1)</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1&lt;=N&lt;=100<br>
0&lt;=g[i][j]&lt;=1</span></p>
</div>