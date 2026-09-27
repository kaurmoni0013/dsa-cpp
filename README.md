# DSA in C++

![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=flat-square&logo=cplusplus&logoColor=white)
![Last Commit](https://img.shields.io/github/last-commit/kaurmoni0013/dsa-cpp?style=flat-square)

A clean and continuously growing collection of Data Structures & Algorithms problems solved in C++.

This repository documents my daily problem-solving practice, with solutions organized by topic and platform. Every solution records the approach, the pattern it belongs to, and the time/space complexity involved.

I use this repository to strengthen:

- algorithmic thinking
- pattern recognition
- time and space complexity analysis
- implementation skills
- interview problem solving

---

## Problem Solving Approach

For each problem, I try to answer these questions before writing code:

1. **What is being asked?** Restate the problem in one line and identify the input/output contract.
2. **What is the brute-force approach?** Write the version that obviously works, even if it is slow.
3. **Can it be optimized?** Identify the repeated work and what data structure removes it.
4. **Which pattern or data structure applies?** Two pointers, sliding window, hashing, binary search, monotonic stack, recursion, backtracking, BFS, DFS, DP, and so on.
5. **What is the time complexity?** Big-O of the final solution, and of the brute force for comparison.
6. **What is the space complexity?** Including recursion stack and auxiliary containers.

Where a problem has multiple natural solutions, I keep the brute force and the optimized version in the same file so the improvement stays visible.

---

## Topics

Solutions are grouped by data structure or algorithm family. Every folder is linked.

| Topic | Solutions | Last solved | Status |
| --- | ---: | --- | --- |
| [Linked List](Linked%20List/) | 32 | 2026-09-18 | 🟢 Active |
| [Recursion](Recursion/) | 11 | 2026-08-08 | 🟡 Growing |
| [Stack](Stack/) | 8 | 2026-09-26 | 🟢 Active |
| [Dynamic Programming](Dynamic%20Programming/) | 6 | 2026-08-28 | 🟡 Growing |
| [Graph](Graph/) | 2 | 2026-09-20 | 🟢 Active |
| [Math](Math/) | 2 | 2026-09-04 | 🟡 Growing |
| [Sorting](Sorting/) | 2 | 2026-08-07 | 🟡 Growing |
| [Array](Array/) | 1 | 2026-08-25 | 🟡 Growing |
| [Daily Questions](Daily%20Questions/) | 1 | 2026-09-20 | 🟢 Active |
| Binary Search | 0 | — | 🔵 Planned |
| Strings | 0 | — | 🔵 Planned |
| Queue | 0 | — | 🔵 Planned |
| Trees | 0 | — | 🔵 Planned |
| Greedy | 0 | — | 🔵 Planned |

**Status legend**

- 🟢 **Active** — at least one solution added in the last 14 days
- 🟡 **Growing** — solutions exist, but none added in the last 14 days
- 🔵 **Planned** — no solutions yet

**Notes**

- Total across all folders: **65 solutions**.
- "Strings" and "Binary Search" are not separate folders yet. String-based and binary-search problems currently live inside their primary structure folder (for example `Stack/`, `Math/`). The folders will be split out once they hold enough solutions to be useful on their own.
- GFG is abbreviated in the tables; it means GeeksforGeeks.

---

## Daily Problem Log

One row per problem, newest first. Every row links to the actual solution file in this repository.

| # | Date | Problem | Platform | Difficulty | Pattern | Solution |
| --- | --- | --- | --- | --- | --- | --- |
| `65` | 2026-09-26 | [Next Greater Element I](https://leetcode.com/problems/next-greater-element-i/) | LeetCode | Easy | Monotonic Stack + Hashing | [`C++`](Stack/Leetcode_Next_greater_Element_1.cpp) |
| `64` | 2026-09-20 | Remove Consecutive Same | GFG | - | Stack | [`C++`](Stack/GFG_String_Manipulation.cpp) |
| `63` | 2026-09-20 | Make Array Beautiful | GFG | - | Stack | [`C++`](Stack/GFG_Make_array_beautiful.cpp) |
| `62` | 2026-09-20 | BFS traversal | Practice | - | BFS | [`C++`](Graph/BFStraversal.cpp) |
| `61` | 2026-09-20 | [Reverse Degree of a String](https://leetcode.com/problems/reverse-degree-of-a-string/) | LeetCode | Easy | Strings | [`C++`](Daily%20Questions/Leetcode_3498_Reverse_Degree_of_String.cpp) |
| `60` | 2026-09-20 | [Backspace String Compare](https://leetcode.com/problems/backspace-string-compare/) | LeetCode | Easy | Stack + Two Pointers | [`C++`](Stack/Leetcode_844_Backspace_string_compare.cpp) |
| `59` | 2026-09-20 | Stack implementation (array) | Practice | - | Stack | [`C++`](Stack/Stack_Implementation_byArray.cpp) |
| `58` | 2026-09-20 | Stack implementation (linked list) | Practice | - | Stack | [`C++`](Stack/Stack_Implementation_byLL.cpp) |
| `57` | 2026-09-20 | [Minimum Add to Make Parentheses Valid](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/) | LeetCode | Medium | Stack | [`C++`](Stack/Leetcode_921_minimum_add_to_make_Paranthesis_valid.cpp) |
| `56` | 2026-09-20 | STL stack basics | Practice | - | STL | [`C++`](Stack/Stack_by_STL_library.cpp) |
| `55` | 2026-09-18 | Clone a Linked List with Random Pointer | GFG | - | Hashing | [`C++`](Linked%20List/GFG_Clone_a_LL.cpp) |
| `54` | 2026-09-04 | [Sqrt(x)](https://leetcode.com/problems/sqrtx/) | LeetCode | Easy | Binary Search | [`C++`](Math/Leetcode_69_Sqrt%28x%29.cpp) |
| `53` | 2026-09-02 | Reverse a Linked List in Groups | GFG | - | Dummy node + Pointer reversal | [`C++`](Linked%20List/GFG_reverse_LinkedList_in_groups.cpp) |
| `52` | 2026-09-02 | [Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/) | LeetCode | Hard | Dummy node + Pointer reversal | [`C++`](Linked%20List/Leetcode_ReverseLinked_List_inGroups.cpp) |
| `51` | 2026-09-01 | [Add Binary](https://leetcode.com/problems/add-binary/) | LeetCode | Easy | Bit Manipulation | [`C++`](Math/Leetcode_add_binary.cpp) |
| `50` | 2026-09-01 | Add Two Numbers Represented by Linked Lists | GFG | - | Two Pointers | [`C++`](Linked%20List/GFG_Add_Two_Numbers_Linked_List.cpp) |
| `49` | 2026-08-31 | [Remove Duplicates from Sorted List II](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/) | LeetCode | Medium | Two Pointers | [`C++`](Linked%20List/Leetcode_Remove_Duplicates_from_Sorted_List_II.cpp) |
| `48` | 2026-08-30 | Intersection Point of Two Linked Lists | GFG | - | Two Pointers | [`C++`](Linked%20List/GFG_Intersection_Point_of_Two_Linked_Lists.cpp) |
| `47` | 2026-08-30 | Length of Loop | GFG | - | Fast and Slow Pointers | [`C++`](Linked%20List/GFG_Length_of_Loop.cpp) |
| `46` | 2026-08-30 | Remove Loop in Linked List | GFG | - | Fast and Slow Pointers | [`C++`](Linked%20List/GFG_Remove_Loop_In_Linked_List.cpp) |
| `45` | 2026-08-29 | [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/) | LeetCode | Easy | Fast and Slow Pointers | [`C++`](Linked%20List/Leetcode_141_linked_list_cycle.cpp) |
| `44` | 2026-08-28 | Frog Jump with K Jumps | GFG | - | Dynamic Programming | [`C++`](Dynamic%20Programming/GFG_Frog_jump_with_K.cpp) |
| `43` | 2026-08-26 | [Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs/) | LeetCode | Medium | Recursion + Two Pointers | [`C++`](Linked%20List/Leetcode_24_Swap_Nodes_In_Pairs.cpp) |
| `42` | 2026-08-25 | [Find Pivot Index](https://leetcode.com/problems/find-pivot-index/) | LeetCode | Easy | Prefix Sum | [`C++`](Array/Leetcode_724_find_pivot_index.cpp) |
| `41` | 2026-08-24 | [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/) | LeetCode | Medium | Two Pointers | [`C++`](Linked%20List/Leetcode_2_add_two_numbers.cpp) |
| `40` | 2026-08-24 | [House Robber II](https://leetcode.com/problems/house-robber-ii/) | LeetCode | Medium | Dynamic Programming | [`C++`](Dynamic%20Programming/Leetcode_213_house_robber2.cpp) |
| `39` | 2026-08-20 | Remove Duplicates from a Sorted Linked List | GFG | - | Two Pointers | [`C++`](Linked%20List/GFG_Remove_Duplicates_From_Sorted_Linked_List.cpp) |
| `38` | 2026-08-20 | Merge Two Sorted Linked Lists | GFG | - | Two Pointers | [`C++`](Linked%20List/GFG_Merge_Two_Sorted_List.cpp) |
| `37` | 2026-08-20 | Reverse a Doubly Linked List | GFG | - | Pointer manipulation | [`C++`](Linked%20List/GFG_reverse_Doubly_LL.cpp) |
| `36` | 2026-08-20 | Insert at a Given Position in Doubly Linked List | GFG | - | Pointer manipulation | [`C++`](Linked%20List/GFG_Insert_at_given_pos.cpp) |
| `35` | 2026-08-19 | [House Robber](https://leetcode.com/problems/house-robber/) | LeetCode | Medium | Dynamic Programming | [`C++`](Dynamic%20Programming/Leetcode_house_robber_198.cpp) |
| `34` | 2026-08-18 | Doubly Linked List (recursive) | Practice | - | Recursion | [`C++`](Linked%20List/DoublyLL_by_Recurssion.cpp) |
| `33` | 2026-08-17 | [Min Cost Climbing Stairs](https://leetcode.com/problems/min-cost-climbing-stairs/) | LeetCode | Easy | Dynamic Programming | [`C++`](Dynamic%20Programming/MinCostClimbingStairs.cpp) |
| `32` | 2026-08-17 | Doubly Linked List (recursive build) | Practice | - | Recursion | [`C++`](Linked%20List/Dll_by_recurrsion.cpp) |
| `31` | 2026-08-17 | Climbing Stairs (4 DP approaches) | Practice | - | Dynamic Programming | [`C++`](Dynamic%20Programming/Climbing_stairs.cpp) |
| `30` | 2026-08-16 | Doubly Linked List implementation | Practice | - | Doubly Linked List | [`C++`](Linked%20List/DoublyLL.cpp) |
| `29` | 2026-08-15 | Fibonacci Number (4 DP approaches) | Practice | - | Dynamic Programming | [`C++`](Dynamic%20Programming/Fibonacci_series.cpp) |
| `28` | 2026-08-15 | [Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/) | LeetCode | Easy | Fast and Slow Pointers | [`C++`](Linked%20List/Leetcode_234_Palindrome_Linked_List.cpp) |
| `27` | 2026-08-14 | Delete Every Kth Node | GFG | - | Pointer manipulation | [`C++`](Linked%20List/GFG_remove_every_kth_node.cpp) |
| `26` | 2026-08-14 | [Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) | LeetCode | Medium | Fast and Slow Pointers | [`C++`](Linked%20List/Leetcode_19_remove_nth_node_from_end.cpp) |
| `25` | 2026-08-13 | Delete Node at a Given Position | GFG | - | Two Pointers | [`C++`](Linked%20List/GFG_Delete_Node_At_Position.cpp) |
| `24` | 2026-08-13 | Delete a Node Without Head Pointer | GFG | - | Pointer manipulation | [`C++`](Linked%20List/GFG_deleteNode_Without_LinkedList_Head.cpp) |
| `23` | 2026-08-13 | Deletion drills (iterative + recursive) | Practice | - | Pointer manipulation | [`C++`](Linked%20List/deletionInLL.cpp) |
| `22` | 2026-08-13 | [Rotate List](https://leetcode.com/problems/rotate-list/) | LeetCode | Medium | Two Pointers | [`C++`](Linked%20List/Leetcode_61_rotate_list.cpp) |
| `21` | 2026-08-13 | [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/) | LeetCode | Easy | Pointer reversal | [`C++`](Linked%20List/LeetCode_206_Reverse_Linked_List.cpp) |
| `20` | 2026-08-13 | [Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/) | LeetCode | Easy | Fast and Slow Pointers | [`C++`](Linked%20List/Leetcode_876_middle_of_linked_list.cpp) |
| `19` | 2026-08-11 | Insert at end (iterative) | Practice | - | Pointer manipulation | [`C++`](Linked%20List/insert-in-end.cpp) |
| `18` | 2026-08-11 | Insert at end (recursive) | Practice | - | Recursion | [`C++`](Linked%20List/insertAtEndByRecurssion.cpp) |
| `17` | 2026-08-11 | Insert at any position (recursive) | Practice | - | Recursion | [`C++`](Linked%20List/insert-at-anyPoint.cpp) |
| `16` | 2026-08-11 | Insert at start (recursive) | Practice | - | Recursion | [`C++`](Linked%20List/insertAtStartByRecurssion.cpp) |
| `15` | 2026-08-10 | Insert at start (iterative) | Practice | - | Pointer manipulation | [`C++`](Linked%20List/insert-in-start.cpp) |
| `14` | 2026-08-08 | Print N-bit Binary Numbers Having More 1s Than 0s | GFG | Medium | Backtracking | [`C++`](Recursion/Print-N-binary-number-having-more-1s-than0s.cpp) |
| `13` | 2026-08-07 | Perfect Sum Problem (in progress) | Practice | - | Recursion | [`C++`](Recursion/PerfectSumProblem.cpp) |
| `12` | 2026-08-07 | Merge Sort | Practice | - | Divide and Conquer | [`C++`](Sorting/mergeSort.cpp) |
| `11` | 2026-08-07 | Array recursion drills (sum, minimum) | Practice | - | Recursion | [`C++`](Recursion/arrayProblems.cpp) |
| `10` | 2026-08-07 | Quick Sort | Practice | - | Divide and Conquer | [`C++`](Sorting/quickSort.cpp) |
| `09` | 2026-08-07 | String recursion drills (palindrome, vowels, reverse, case) | Practice | - | Recursion | [`C++`](Recursion/string_problem.cpp) |
| `08` | 2026-08-07 | [Find the Winner of the Circular Game](https://leetcode.com/problems/find-the-winner-of-the-circular-game/) | LeetCode | Medium | Recursion | [`C++`](Recursion/josephus.cpp) |
| `07` | 2026-08-07 | Target Sum | Practice | - | Recursion | [`C++`](Recursion/targetSum.cpp) |
| `06` | 2026-08-07 | Rat in a Maze | GFG | Medium | Backtracking | [`C++`](Recursion/Rat_in_a_maze.cpp) |
| `05` | 2026-08-07 | Subset Sums | Practice | - | Recursion | [`C++`](Recursion/subsetsSums.cpp) |
| `04` | 2026-08-07 | Target Sum (with repetition) | Practice | - | Recursion | [`C++`](Recursion/targetSumwithRepetetion.cpp) |
| `03` | 2026-08-07 | Tower of Hanoi | GFG | Easy | Recursion | [`C++`](Recursion/towerOfHanoi.cpp) |
| `02` | 2026-08-07 | Graph representation (adjacency matrix) | Practice | - | Graph representation | [`C++`](Graph/graph.cpp) |
| `01` | 2026-08-07 | Generate Permutations | Practice | - | Backtracking | [`C++`](Recursion/permutation.cpp) |

**Column notes**

- `Platform` — `LeetCode`, `GFG` (GeeksforGeeks), or `Practice` for drills I wrote without a platform problem statement.
- `Difficulty` — shown only for LeetCode problems, where it is taken from the platform. GFG difficulty labels are not recorded, so they are left as `-` rather than guessed.
- `Pattern` — the approach the solution is built on, not the topic folder.
- Problem names link to the original statement for LeetCode. GFG problem URLs are not recorded, so those rows are plain text instead of guessed links.
- `#13` is a recursion drill that is still in progress. It is listed so the log matches the files on disk.

---

## Patterns I'm Learning

Patterns are how I organise practice. This list grows only when the repository actually contains problems for that pattern.

**In use**

- Two Pointers
- Fast and Slow Pointers
- Hashing
- Prefix Sum
- Binary Search
- Monotonic Stack
- Stack
- Recursion
- Backtracking
- Divide and Conquer
- BFS
- Dynamic Programming
- Doubly Linked List
- Pointer manipulation
- Bit Manipulation

**Next up**

- Sliding Window
- Greedy
- Heap / Priority Queue
- Tries
- Trees and Binary Search Trees
- Topological Sort
- Union-Find

---

## Progress

All numbers below are counts of files in this repository.

| Metric | Value |
| --- | --- |
| Solutions | 65 (64 complete, 1 in progress) |
| Topics with solutions | 9 |
| Primary language | C++ |
| Platform problems | LeetCode 21, GeeksforGeeks 19 |
| Self-directed drills | 25 |
| Practice period | 2026-08-07 to 2026-09-26 |
| Active practice days | 25 |

**Distribution by topic**

Bar length is relative to the largest topic, Linked List at 32 solutions.

```text
Linked List         32  ██████████
Recursion           11  ███░░░░░░░
Stack                8  ███░░░░░░░
Dynamic Programming   6  ██░░░░░░░░
Math                 2  █░░░░░░░░░
Graph                2  █░░░░░░░░░
Sorting              2  █░░░░░░░░░
Array                1  ░░░░░░░░░░
Daily Questions      1  ░░░░░░░░░░
```

The distribution is intentionally uneven. Linked List and Recursion were the early focus, and Stack is the current one. The thinner topics are what [Current Focus](#current-focus) is for.

---

## Current Focus

Right now I am working through:

- **Stack** — patterns over raw and STL stack usage
- **Graph** — BFS, then DFS and topological ordering
- **Dynamic Programming** — building the recursion → memoization → tabulation → space-optimised progression consistently
- **Problem-solving patterns** — recognising which pattern applies before writing code
- **Queue** — starting, so the Stack focus has a natural follow-on

Linked List is well covered and is on maintenance mode: new problems only when they add a pattern that is not already represented.

---

## How to Use This Repository

If you are learning DSA:

1. Pick a topic from the [Topics](#topics) table.
2. Choose a problem from the [Daily Problem Log](#daily-problem-log).
3. Try solving it yourself first, without opening the file.
4. Read the approach comment at the top of the `.cpp` file.
5. Study the implementation.
6. Check the stated time and space complexity against your own.
7. Move to the next problem.

If you are reviewing this repository: every solution states its own approach and complexity, so you can audit the reasoning without running anything. Every `.cpp` file compiles standalone with `g++ -std=c++17 -fsyntax-only <file>`.

---

## Adding a New Problem

The daily workflow is deliberately short so it stays sustainable.

1. Add one `.cpp` file to the correct topic folder, using a readable name such as `next_greater_element.cpp`.
2. Add one row at the top of the [Daily Problem Log](#daily-problem-log) with date, platform, difficulty, and pattern.
3. Commit and push.

No other file needs to change. The folder tree, the topic counts and this page only need a refresh occasionally, not daily.

**Standard format for a solution file**

The file header follows this structure. Explanations live in the header comment, not scattered through the code.

```text
===========================================================
Problem: <problem name>

Platform: <LeetCode | GeeksforGeeks | Practice>
Problem No.: <number, if the platform has one>
Difficulty: <Easy | Medium | Hard, only if known>
Topic: <folder name>
Pattern: <the approach used>
===========================================================

<short problem statement or link>

-----------------------------------------------------------
APPROACH
-----------------------------------------------------------
<the idea in a few lines>

-----------------------------------------------------------
DRY RUN
-----------------------------------------------------------
<input> -> <output>

-----------------------------------------------------------
TIME COMPLEXITY:  O(...)
SPACE COMPLEXITY: O(...)
-----------------------------------------------------------
```

Followed by the solution itself:

```cpp
// clean C++ solution, no debug statements
```

**File naming**

Use `snake_case` and describe the problem: `two_sum.cpp`, `valid_parentheses.cpp`, `daily_temperatures.cpp`, `divide_two_integers.cpp`.

Avoid `question1.cpp`, `new.cpp`, `test.cpp`, `final.cpp`, `code1.cpp`, `abc.cpp`.

**Commit format**

```text
feat(dsa): solve next greater element
feat(array): solve product of array except self
feat(stack): solve daily temperatures
feat(dp): solve climbing stairs
```

Avoid `update`, `done`, `today`, `new code`, `final`, `changes`.

The activity in this repository comes from actually solving problems. No commit is made for its own sake.

---

## Repository Structure

```text
dsa-cpp/
├── Array/                        # Prefix sum, two pointers
├── Daily Questions/              # Ongoing daily practice problems
├── Dynamic Programming/          # Recursion -> memoization -> tabulation -> O(1)
├── Graph/                        # Representations and traversal
├── Linked List/                  # Singly and doubly linked lists
├── Math/                         # Bit manipulation, binary search
├── Recursion/                    # Recursion, backtracking, drills
├── Sorting/                      # Merge sort, quick sort
├── Stack/                        # Stack usage, monotonic stack, STL
├── TEMPLATE.md                   # Standard format for a new solution
└── README.md
```

Topic folders use spaces in their names, matching the topic names used throughout this page. New problems go into an existing folder; a new folder is only created when a genuinely new topic starts.

---

## Language

**C++** — the only language in this repository.

Solutions follow the LeetCode `class Solution` shape where the problem comes from LeetCode, and a standalone program or class where it does not. STL is used where it makes the solution clearer, and avoided where a manual implementation is the point of the exercise.

---

## Platforms

| Platform | Problems | Notes |
| --- | ---: | --- |
| [LeetCode](https://leetcode.com/) | 21 | Difficulty verified from the platform. |
| [GeeksforGeeks](https://www.geeksforgeeks.org/) | 19 | Difficulty not recorded. |
| Practice drills | 25 | Written from textbook or lecture topics, no platform statement. |

Problem links are only added when the original problem can be identified with confidence. Nothing is guessed.
