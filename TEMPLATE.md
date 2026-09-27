# Solution Template

Copy this structure for every new problem. Explanations belong in the header comment so the code itself stays readable.

---

## 1. Pick the folder and the filename

Put the file in the topic folder it belongs to, named after the problem in `snake_case`.

```text
Array/next_greater_element.cpp
Stack/daily_temperatures.cpp
Dynamic Programming/climbing_stairs.cpp
```

## 2. Use this file structure

```cpp
/*
===========================================================
Problem: <Problem Name>

Platform: <LeetCode | GeeksforGeeks | Practice>
Problem No.: <number, if the platform has one>
Difficulty: <Easy | Medium | Hard — only if known>
Topic: <folder name>
Pattern: <Two Pointers | Sliding Window | Hashing | Binary Search |
         Monotonic Stack | Recursion | Backtracking | BFS | DFS |
         Dynamic Programming | ...>
===========================================================

-----------------------------------------------------------
PROBLEM
-----------------------------------------------------------
<Short statement, or the link to the original problem.>

Example:
    Input:  <input>
    Output: <output>

-----------------------------------------------------------
APPROACH
-----------------------------------------------------------
<The main idea, in plain language.>

<If there is a brute-force version worth keeping, describe it
 and say what the optimization removes.>

-----------------------------------------------------------
DRY RUN
-----------------------------------------------------------
<input> -> <output, step by step if it helps>

-----------------------------------------------------------
TIME COMPLEXITY:  O(...)
SPACE COMPLEXITY: O(...)
-----------------------------------------------------------
*/

#include <...>
using namespace std;

class Solution {
public:
    // <clean implementation, no debug statements>
};
```

## 3. Code rules

- Clear variable names.
- Use the STL when it makes the solution clearer.
- No debug output, no commented-out code, no unused variables.
- No unnecessary includes.
- No long explanations inside the code — those go in the header comment.
- If two approaches are worth keeping (for example brute force and optimized), give each its own clearly named class rather than redefining the same one.

## 4. Add one row to the Daily Problem Log

Add a single row at the **top** of the table in [README.md](README.md#daily-problem-log).

```markdown
| `66` | 2026-09-27 | [Problem Name](https://leetcode.com/problems/problem-slug/) | LeetCode | Medium | Two Pointers | [`C++`](Stack/problem_name.cpp) |
```

Fill in:

- `#` — the next sequential number
- `Date` — the day you solved it
- `Problem` — link to the original problem if it can be identified with confidence
- `Platform` — `LeetCode`, `GFG`, or `Practice`
- `Difficulty` — only if known; otherwise `-`
- `Pattern` — the approach, not the topic folder
- `Solution` — relative link to the file

## 5. Commit

```text
feat(<topic>): solve <problem name>
```

Examples:

```text
feat(dsa): solve next greater element
feat(array): solve product of array except self
feat(stack): solve daily temperatures
feat(dp): solve climbing stairs
```

Avoid `update`, `done`, `today`, `new code`, `final`, `changes`.

## 6. Checklist before pushing

- [ ] File is in the correct topic folder
- [ ] Filename is `snake_case` and describes the problem
- [ ] Header comment states approach, pattern, time and space complexity
- [ ] No debug statements, unused variables, or commented-out code
- [ ] `g++ -std=c++17 -fsyntax-only <file>` passes
- [ ] One new row added at the top of the Daily Problem Log
- [ ] Every link in the new row resolves

## 7. Refresh occasionally, not daily

These do not need updating for every problem:

- The solution count in each row of the **Topics** table
- The **Progress** numbers and distribution bars
- The **Last solved** dates and status dots
- The **Patterns I'm Learning** lists

Update them when a topic's count or status actually changes meaningfully, so the numbers on this page stay trustworthy.
