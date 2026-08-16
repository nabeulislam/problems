# Aritro and the Group Chat

The group chat was once buzzing with messages, reactions, memes and jokes every nanosecond just like the peak of every group chat. Alas, the glory days are now over, only Aritro sends messages in the chat now. The others have a life now!

There are $N$ inactive friends in the chat. Aritro sends messages one by one, and each message is assigned an id equal to the number of messages sent so far. So his first message has id 1, his second has id 2, and so on.

A friend can come online at any point. When friend $f$ comes online, he reads all messages that have been sent so far, and then immediately goes offline. If Aritro sends more messages after that, friend $f$ will not see them unless he comes online again.

You will be given $Q$ events in order. Each event is one of the following:
1. Aritro sends a message. It is assigned the next available id.
2. Friend $f$ comes online and reads all messages sent so far. He then goes offline.
3. How many friends have read message with id $s$?

**Note:** A friend reads message $s$ if and only if he came online at a time when at least $s$ messages had already been sent.

## Input Format
Input is given in the following format:
* line 1: $N$ $Q$
* line $1+i$ ($1 \le i \le Q$): The $i$-th query, starting with its type $t$ represented as either of the following:
  * `1`
  * `2 f` ($1 \le f \le N$)
  * `3 s`

## Output Format
* For every query of type 3, print the number of people that have seen the message with id $s$.

## Constraints
* $1 \le N \le 5 \times 10^5$
* $1 \le Q \le 5 \times 10^5$

## Subtasks

| Subtask | Score | Additional constraints |
| :--- | :--- | :--- |
| 1 | 10 | $N = 1$ |
| 2 | 20 | $N, Q \le 5000$ |
| 3 | 30 | All type 3 queries appear after all other queries |
| 4 | 40 | No additional constraints |

## Examples

### Example 1

**Input:**
```
4 11
1
1
2 1
3 1
1
1
2 2
3 1
2 3
2 4
3 4
```

**Output:**
```
1
2
3
```

## Note

**Query types:**
* If $t=1$, Aritro sends a message in the group chat.
* If $t=2$, another integer $f$ is given. ($1 \le f \le N$) Friend $f$ comes online and reads every message sent beforehand.
* If $t=3$, another integer $s$ is given. Aritro asks how many friends have seen the message with id $s$.

**Explanation of Example:**
* **Query 1:** Aritro sends a message. It is assigned id 1.
* **Query 2:** Aritro sends a message. It is assigned id 2.
* **Query 3:** Friend 1 gets online. He reads the messages with id 1, 2.
* **Query 4:** Aritro asks how many friends have seen message with id 1. Only friend 1 has seen it. So, the answer is 1.
* **Query 5:** Aritro sends a message. It is assigned id 3.
* **Query 6:** Aritro sends a message. It is assigned id 4.
* **Query 7:** Friend 2 gets online and reads the messages 1, 2, 3, 4.
* **Query 8:** Aritro asks how many friends have seen message with id 1. Friends 1, 2 have seen it. So, the answer is 2.
* **Query 9:** Friend 3 gets online. He reads the messages with id 1, 2, 3, 4.
* **Query 10:** Friend 4 gets online. He reads the messages with id 1, 2, 3, 4.
* **Query 11:** Aritro asks how many friends have seen message with id 4. Friends 2, 3, 4 have seen it. So, the answer is 3.
