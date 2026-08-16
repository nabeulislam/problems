## Problem Setting

Problem setting might feel like a daunting task, but it's fun and worth it when you know how. I'll try my best to explain everything as clearly and simply as possible.

## Prerequisites

- Familiarity with C++.
- Familiarity with `testlib.h` (this is important, you'll need it along the way).
- Basic usage of the Linux shell (bash).
- Git (helpful if multiple people are collaborating, but not required).

## Setting up the environment

It's recommended to use macOS or Linux. If you are a Windows user, please install WSL.

Run the following command to install TPS on Linux/macOS/Windows (with WSL):

```bash
bash -c "$(curl -fsSL https://raw.githubusercontent.com/ioi-2017/tps/master/online-installer/install.sh)"
```

The online installer assumes `git` is installed on your system. It clones the TPS repository and installs it.

Then use the following command to add the template directory to your path:

```bash
export TPS_TASK_TEMPLATES_PATH="$HOME/.local/share/tps/task-templates"
```

**Note:** Your template location might differ depending on your operating system.

Then use the following command to set up the problem directory:

```bash
tps init <problem name>
```

For full documentation, visit https://github.com/ioi-2017/tps/tree/master/docs.

While the repository contains detailed documentation about problem setting, it can be overwhelming. Below I discuss a simplified version.

Let's discuss the problem preparation for the `blackmath` task.

## Blackmath preparation

Folder structure:
```
blackmath/
├── checker/
│   ├── Makefile
│   ├── checker.cpp
│   └── testlib.h
├── gen/
│   ├── Makefile
│   ├── data            # generator config/params
│   ├── gen1.cpp         # test generator source
│   ├── testlib.h
│   └── manual/
│       ├── 0-01.in
│       ├── 0-02.in
│       ├── 1-01.in
│       ├── 2-01.in
│       └── 2-02.in
├── validator/
│   ├── Makefile
│   ├── testlib.h
│   ├── validator.cpp
│   ├── val1.cpp
│   ├── val2.cpp
│   ├── val3.cpp
│   ├── val4.cpp
│   └── val5.cpp
├── solution/
│   ├── correct1.cpp     # model solution
│   ├── partial1.cpp, partial2.cpp
│   └── wrong.cpp, wrong1.cpp
├── statement/
│   └── index.pdf
├── scripts/             # TPS tooling - compile, gen, invoke, stress, export (60+ files, framework boilerplate)
├── problem.json
├── solutions.json
└── subtasks.json
```

You don't need to worry about every file. Focus on the following:

1. `checker.cpp` (for this problem you can ignore it).
2. `gen1.cpp`
3. `data`
4. `.cpp` files in `validator/`
5. Files in the `solution/` folder.
6. `problem.json`
7. `solutions.json`
8. `subtasks.json`

You may inspect the folder contents for reference. It's recommended to know how to write generators and validators. You can use standard input/output, but using `testlib` functions and conventions is recommended.

## Generator

Here is the `generator.cpp`:
```cpp
#include "testlib.h"
#define ll long long
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    ll subtask = atoi(argv[1]);
    ll min_n = 1LL;
    ll max_n = 1000000000000000000LL;
    ll min_a = 0LL;
    ll min_b = 0LL;
    
    ll  max_a = 1000000000000000000LL;
    ll max_b =  1000000000000000000LL;

    if (subtask == 1) {
        max_n = 3;
    } else if (subtask == 2) {
        max_n = 10LL;
        min_a = 1LL;    
        max_a = 1LL;
        min_b = 1LL;
        max_b = 1LL;

    } else if (subtask == 3) {
        max_n = 20LL;
    } else if (subtask == 4) {
        max_n = 1000LL;
    } else if (subtask == 5) {
        max_n = 100000LL;
    } else if (subtask == 6) {
        min_n = 1000000000000000000LL;
        max_n = 1000000000000000000LL;
        min_a = 999999999999999990LL;
        min_b = 999999999999999900LL;
    }

    ll n = rnd.next(min_n, max_n);
    ll a = rnd.next(min_a, max_a);
    ll b = rnd.next(min_b, max_b);

    cout << n << " " << a << " " << b << "\n";
         
    return 0;
}
```

`argc` and `argv` are used to pass command line arguments (these are listed in the `data` file used for test case generation).
`rnd.next()` is a `testlib` function that generates a random number between `l` and `r`.

Let's review part of the `data` file:

```
@subtask samples
manual 0-01.in
manual 0-02.in

@subtask 1
manual 1-01.in
gen1 1 2
gen1 1 3
gen1 1 4
gen1 1 5

@subtask 2
gen1 2 1
manual 2-01.in
gen1 2 35
gen1 2 45
gen1 2 55
gen1 2 66
manual 2-02.in
```

`manual` entries are taken from the `manual/` folder, these are handwritten test cases. `@subtask <name>` denotes a subtask (these are used in `subtasks.json`). You can add dependencies by using `@include <subtask name>` inside a subtask block.

Now let's clarify the syntax of `gen1 1 2`. This runs the following command in the terminal:

```bash
./gen1 1 2
```

You don't need to worry about compiling and running, `tps` handles it. `gen1` is the compiled binary of `gen1.cpp`. The first argument (`1`) is the subtask number; the second argument is a seed used to produce different outputs. If you run `gen1 1` repeatedly without a varying seed, you'll get the same output each time. To produce unique test cases you append a seed, for example `gen1 1 pepegoat67`. Using the same seed will produce the same output, so vary the seed for unique cases.


## Validator

The validator is used to check that generated inputs are valid for the problem and its subtasks. It's a safety check to ensure test data is correct. Writing validators requires some familiarity with `testlib`.

## JSON files

`.json` files are used to configure time limits, subtasks, and solution invocation.

## Commands for TPS that might be helpful

To generate test cases, use the command:
```bash
tps gen
```

This creates the test cases in the `tests` folder. Note: the folder resets each time you run it, and you must have the model solution available to generate tests.

To run a solution:
```bash
tps invoke <path-to-solution-file>
```

To verify the folder and structure for exporting to CMS or DMOJ, use:
```bash
tps verify
```

To export the problem for CMS, use:
```bash
tps export CMS 1
```

## Important links (don't skip)

Important resources you might need for problem setting:
1. Video guide: https://youtu.be/i7tMwDK5gpg?si=aWuTywGzkKW9mUEk
2. Writing generators: https://codeforces.com/blog/entry/18291
3. Writing validators: https://codeforces.com/blog/entry/18426
4. Writing checkers: https://codeforces.com/blog/entry/18431

