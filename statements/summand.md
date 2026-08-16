# Pepe & Minimum Summands

*Through the dark forests, crossing seven seas and thirteen rivers, Pepe has finally reached the mythical Island of Bika. There he found a cave. Some old saying says that whoever finds a cave on the Island of Bika and enters it never comes back alive, but Pepe is known as the most courageous in his village. So, he decides to enter it. There he finds a locked chest and a note beside it. The entrance immediately closes but fortunately Pepe had come with a torch. Pepe starts reading the note:*

You are given two positive integers $n$ and $x$. There is an array $a$ consisting of $m$ non-negative integers. Let $m$ be the size of the array $a$. For each $i$ ($1 \le i \le m$), $a_i$ is the base of the $i$-th summand, and $x$ is the common exponent of every summand.

Formally,

$$n = a_1^x + a_2^x + \dots + a_m^x$$

Your task is to find the minimum possible value of $m$, i.e. the minimum possible size of $a$.

Pepe has to enter the answer and the array $a$ into the chest, which contains a smart lock system. It is said that the Island of Bika was once the greatest in technology.

Help Pepe get the treasure and escape the cave.






## Input Format

Each test file contains multiple test cases. **The first line of the input contains the number of test cases $T$**. Then, for each test case, the input is given in the following format:

* line 1: $n \ x$


## Output Format

For each test case, if it is possible, output the minimum possible value of $m$ and a sequence of numbers that achieves the answer in the following format:

* line 1: $m$
* line 2: the sequence of numbers separated by spaces, or more formally $a$, in **non-decreasing order**.

If it is possible, but you do not output the sequence, output the following:
* line 1: $m \, -1$

If there is no possible answer, output the answer in the following format:
* line 1: $-1 \, -1$



## Constraints
 
- $1 \le T \le 1000$
- $1 \le n \le 10^5$
- $1 \le x \le 10$

## Subtasks

| Subtask | Score | Additional Constraints |
|:-------:|:-----:|-------------------------|
| 1 | 7  | $x = 1$ |
| 2 | 8  | $2^x > n$ |
| 3 | 8  | $m = 2$ |
| 4 | 10 | $x = 2$; $1 \le n \le 100$ |
| 5 | 14 | $1 \le n \le 1000$ |
| 6 | 25 | $1 \le n \le 10^5$; $2 \le x \le 3$ |
| 7 | 28 | No additional constraints. |

## Scoring
- If you choose not to print the sequence of numbers for any test case but provide the correct answer $m$, you will receive $50\%$ of the subtask’s score

- If you choose to print the sequence, but it is incorrect, you will receive $0$ points for that subtask.

- Otherwise, you will receive full score for the subtask.


## Examples

### Example 1

```
4
65 2
10 3
1024 10
12 8
```
The partially correct output is:
```
2 -1
```

The correct output for this case is:

```
2
1 8
3
1 1 2
1
2
12
1 1 1 1 1 1 1 1 1 1 1 1
```



## Note

**Explanation of Example:**
In the first test case, $n = 65$ and $x = 2$. A possible array is:
 
$a = [1, 8]$, because $65 = 1^2 + 8^2$.
 
In the second test case, $n = 10$ and $x = 3$. A possible array is:
 
$a = [1, 1, 2]$, because $10 = 1^3 + 1^3 + 2^3$.
 
In the fourth test case, $n = 12$ and $x = 8$. The only possible array is:
 
$a = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]$, because
 
$12 = 1^8 + 1^8 + 1^8 + 1^8 + 1^8 + 1^8 + 1^8 + 1^8 + 1^8 + 1^8 + 1^8 + 1^8$.
