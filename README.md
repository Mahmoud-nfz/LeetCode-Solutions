# LeetCode Solutions

<div align="center">
  <img src="https://user-images.githubusercontent.com/65515933/228696522-e369c0b8-edf2-4c5e-99fc-e329ceac819a.png" alt="Software Project Ideas">
</div>

---

This repository contains a collection of solutions to problems from the LeetCode platform, written in C++ programming language. The solutions are explained with comments to help with understanding.

For contributing : see [Contributing](#Contributing) section.

## Structure of the Repository

The repository is organized according to the problem's difficulty level and its respective question number. Each problem contains a `.cpp` file that contains the solution to the problem along with comments.

---
# Problems
<!-- PROBLEMS START -->
## EASY
| Problem | Solution | Difficulty | Tags |
| ------- | -------- | ---------- | ---- |
| [Contains Duplicate](./easy/contains_duplicates/contains_duplicates.md) | [C++](./easy/contains_duplicates/contains_duplicates.md) | Easy | Hash Map, Data Structures |
| [Reverse Linked List](./easy/reverse_linked_list/reverse_linked_list.md) | [C++](./easy/reverse_linked_list/reverse_linked_list.md) | Easy | linked list |

## MEDIUM
| Problem | Solution | Difficulty | Tags |
| ------- | -------- | ---------- | ---- |
| [Jump Game](./medium/jump_game/jump_game.md) | [C++](./medium/jump_game/jump_game.md) | Medium | dp |
| [Binary Tree Level Order Traversal](./medium/binary_tree_level_order_traversal/binary_tree_level_order_traversal.md) | [C++](./medium/binary_tree_level_order_traversal/binary_tree_level_order_traversal.md) | Medium | binary tree |
| [Reorganize String](./medium/reorganize_string/reorganize_string.md) | [C++](./medium/reorganize_string/reorganize_string.md) | Medium | strings, greedy, data structures |
| [Combination Sum IV](./medium/combination-sum-iv.cpp/combination-sum-iv.cpp.md) | [C++](./medium/combination-sum-iv.cpp/combination-sum-iv.cpp.md) | Medium | DP |
| [Binary Tree Level Order Traversal II](./medium/binary_tree_level_order_traversal_ii/binary_tree_level_order_traversal_ii.md) | [C++](./medium/binary_tree_level_order_traversal_ii/binary_tree_level_order_traversal_ii.md) | Medium | binary tree |
| [Path Sum II](./medium/path_sum_ii/path_sum_ii.md) | [C++](./medium/path_sum_ii/path_sum_ii.md) | Medium | dfs, binary tree |
| [Reorder List](./medium/reorder_list/reorder_list.md) | [C++](./medium/reorder_list/reorder_list.md) | Medium | linked list |
| [Find All Duplicates in an Array](./medium/find_all_duplicates_in_an_array/find_all_duplicates_in_an_array.md) | [C++](./medium/find_all_duplicates_in_an_array/find_all_duplicates_in_an_array.md) | Medium | data structures, frequency array |
| [K Closest Points to Origin](./medium/k_closest_points_to_origin/k_closest_points_to_origin.md) | [C++](./medium/k_closest_points_to_origin/k_closest_points_to_origin.md) | Medium | sorting |
| [Letter Case Permutation](./medium/letter_case_permutation/letter_case_permutation.md) | [C++](./medium/letter_case_permutation/letter_case_permutation.md) | Medium | strings backtracking bruteforce |

## CONTESTS
| Problem | Solution | Difficulty | Tags |
| ------- | -------- | ---------- | ---- |
| biweekly-contest-101 | | | |
| [Find the Substring With Maximum Cost](./contest/biweekly-contest-101/find_the_substring_with_maximum_cost/find_the_substring_with_maximum_cost.md) | [C++](./contest/biweekly-contest-101/find_the_substring_with_maximum_cost/find_the_substring_with_maximum_cost.md) | Medium | arrays |
| [Form Smallest Number From Two Digit Arrays](./contest/biweekly-contest-101/form_smallest_number_from_two_digit_arrays/form_smallest_number_from_two_digit_arrays.md) | [C++](./contest/biweekly-contest-101/form_smallest_number_from_two_digit_arrays/form_smallest_number_from_two_digit_arrays.md) | Easy | arrays |
| [Make K-Subarray Sums Equal](./contest/biweekly-contest-101/make_k-subarray_sums_equal/make_k-subarray_sums_equal.md) | [C++](./contest/biweekly-contest-101/make_k-subarray_sums_equal/make_k-subarray_sums_equal.md) | Medium | arrays, dsu |
| weekly-contest-339 | | | |
| [Find the Longest Balanced Substring of a Binary String](./contest/weekly-contest-339/find_the_longest_balanced_substring_of_a_binary_string/find_the_longest_balanced_substring_of_a_binary_string.md) | [C++](./contest/weekly-contest-339/find_the_longest_balanced_substring_of_a_binary_string/find_the_longest_balanced_substring_of_a_binary_string.md) | Easy | arrays |
| [Convert an Array Into a 2D Array With Conditions](./contest/weekly-contest-339/convert_an_array_into_a_2d_array_with_conditions/convert_an_array_into_a_2d_array_with_conditions.md) | [C++](./contest/weekly-contest-339/convert_an_array_into_a_2d_array_with_conditions/convert_an_array_into_a_2d_array_with_conditions.md) | Medium | data structures |
| [Mice and Cheese](./contest/weekly-contest-339/mice_and_cheese/mice_and_cheese.md) | [C++](./contest/weekly-contest-339/mice_and_cheese/mice_and_cheese.md) | Medium | sorting |

<!-- PROBLEMS END -->

---

## Contributing <a name="Contributing"></a>

If you find a problem whose solution is not included in the repository, feel free to contribute by submitting a pull request.

### Steps to contribute:

- Fork the repository
- Clone the forked repository
- Create a new branch
- Run **`add_solution.py`** script to launch the prompt of adding a new problem and generating the files for it
- Add your explained solution in the **`Solution.cpp`** file
- Add the problem statement in the **`statement.html`** file
- Once you've added some problems , run **`build_problems_pages.py`** script to generate the markdown files for the problems you added
- Commit and push the changes
- Create a pull request




