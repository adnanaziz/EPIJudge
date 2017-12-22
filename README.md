# EPIJudge
title: EPI Judge
date: 2017-12-21
---

The EPI Judge is ready! This screenshot should give you a good idea of what it's about. 

<img src="{{ site.url }}/img/judge-ide-example.png" width="650px"></img>

You can also view these one minute screencapture videos on YouTube to see how easy it is to get started with the judge:  <a href="https://youtu.be/ImD_iI-uGYo">PyCharm</a>, <a href="https://youtu.be/1BzHUpluQHM">IntelliJ</a>, <a href="https://youtu.be/aHPDApyyYEg">CLion</a>

EPI Judge consists of the following:

  - **Stub programs** for each problem in our book in Python, Java, and C++
  - **Test-cases** that cover common corner-case and performance bugs 
  - A **framework** for running these tests on your implementation on your machine

The installation is super-simple - there's no install! You just **download the project, point your IDE/editor to it**, and start the code-debug cycle, with instant feedback!

The best interview preparation is a combination of hands-on practice over a representative set of problems with quality explanations. 

The best way to get this hands-on practice is by developing, running, and debugging programs in the **environment you're most comfortable with**, i.e., your own computer and IDE/editor:
  1. It's a very fast compile-debug cycle, 
  2. you have complete control and visibility, both into the internal state and the test data, 
  3. you can use the features such as autocomplete, autoformat, linting, definiton lookups, etc., and
  4. you can choose to use version control, to track your own progress, as well as to pull updates.

A big shout-out to <a href="https://github.com/metopa">Viacheslav Kroilov</a>, for applying his exceptional software engineering skills to make EPI Judge a reality.

# Problem to Program Mapping

| Problem | C++ | Java | Python  |
| ------ | ------ | ------ | ------ |
| Bootcamp: Primitive Types | [count_bits.cc] | [CountBits.java] | [count_bits.py] | 
| Computing the parity of a word | [parity.cc] | [Parity.java] | [parity.py] | 
| Swap bits | [swap_bits.cc] | [SwapBits.java] | [swap_bits.py] | 
| Reverse bits | [reverse_bits.cc] | [ReverseBits.java] | [reverse_bits.py] | 
| Find a closest integer with the same weight | [closest_int_same_weight.cc] | [ClosestIntSameWeight.java] | [closest_int_same_weight.py] | 
| Compute x * y without arithmetical operators | [primitive_multiply.cc] | [PrimitiveMultiply.java] | [primitive_multiply.py] | 
| Compute x/y | [primitive_divide.cc] | [PrimitiveDivide.java] | [primitive_divide.py] | 
| Compute x^y | [power_x_y.cc] | [PowerXY.java] | [power_x_y.py] | 
| Reverse digits | [reverse_digits.cc] | [ReverseDigits.java] | [reverse_digits.py] | 
| Check if a decimal integer is a palindrome | [is_number_palindromic.cc] | [IsNumberPalindromic.java] | [is_number_palindromic.py] | 
| Generate uniform random numbers | [uniform_random_number.cc] | [UniformRandomNumber.java] | [uniform_random_number.py] | 
| Rectangle intersection | [rectangle_intersection.cc] | [RectangleIntersection.java] | [rectangle_intersection.py] | 
| Bootcamp: Arrays | [even_odd_array.cc] | [EvenOddArray.java] | [even_odd_array.py] | 
| The Dutch national flag problem | [dutch_national_flag.cc] | [DutchNationalFlag.java] | [dutch_national_flag.py] | 
| Increment an arbitrary-precision integer | [int_as_array_increment.cc] | [IntAsArrayIncrement.java] | [int_as_array_increment.py] | 
| Multiply two arbitrary-precision integers | [int_as_array_multiply.cc] | [IntAsArrayMultiply.java] | [int_as_array_multiply.py] | 
| Advancing through an array | [advance_by_offsets.cc] | [AdvanceByOffsets.java] | [advance_by_offsets.py] | 
| Delete duplicates from a sorted array | [sorted_array_remove_dups.cc] | [SortedArrayRemoveDups.java] | [sorted_array_remove_dups.py] | 
| Buy and sell a stock once | [buy_and_sell_stock.cc] | [BuyAndSellStock.java] | [buy_and_sell_stock.py] | 
| Buy and sell a stock twice | [buy_and_sell_stock_twice.cc] | [BuyAndSellStockTwice.java] | [buy_and_sell_stock_twice.py] | 
| Computing an alternation | [alternating_array.cc] | [AlternatingArray.java] | [alternating_array.py] | 
| Enumerate all primes to n | [prime_sieve.cc] | [PrimeSieve.java] | [prime_sieve.py] | 
| Permute the elements of an array | [apply_permutation.cc] | [ApplyPermutation.java] | [apply_permutation.py] | 
| Compute the next permutation | [next_permutation.cc] | [NextPermutation.java] | [next_permutation.py] | 
| Sample offline data | [offline_sampling.cc] | [OfflineSampling.java] | [offline_sampling.py] | 
| Sample online data | [online_sampling.cc] | [OnlineSampling.java] | [online_sampling.py] | 
| Compute a random permutation | [random_permutation.cc] | [RandomPermutation.java] | [random_permutation.py] | 
| Compute a random subset | [random_subset.cc] | [RandomSubset.java] | [random_subset.py] | 
| Generate nonuniform random numbers | [nonuniform_random_number.cc] | [NonuniformRandomNumber.java] | [nonuniform_random_number.py] | 
| The Sudoku checker problem | [is_valid_sudoku.cc] | [IsValidSudoku.java] | [is_valid_sudoku.py] | 
| Compute the spiral ordering of a 2D array | [spiral_ordering_segments.cc] | [SpiralOrderingSegments.java] | [spiral_ordering_segments.py] | 
| Rotate a 2D array | [matrix_rotation.cc] | [MatrixRotation.java] | [matrix_rotation.py] | 
| Compute rows in Pascal's Triangle | [pascal_triangle.cc] | [PascalTriangle.java] | [pascal_triangle.py] | 
| Interconvert strings and integers | [string_integer_interconversion.cc] | [StringIntegerInterconversion.java] | [string_integer_interconversion.py] | 
| Base conversion | [convert_base.cc] | [ConvertBase.java] | [convert_base.py] | 
| Compute the spreadsheet column encoding | [spreadsheet_encoding.cc] | [SpreadsheetEncoding.java] | [spreadsheet_encoding.py] | 
| Replace and remove | [replace_and_remove.cc] | [ReplaceAndRemove.java] | [replace_and_remove.py] | 
| Test palindromicity | [is_string_palindromic_punctuation.cc] | [IsStringPalindromicPunctuation.java] | [is_string_palindromic_punctuation.py] | 
| Reverse all the words in a sentence | [reverse_words.cc] | [ReverseWords.java] | [reverse_words.py] | 
| Compute all mnemonics for a phone number | [phone_number_mnemonic.cc] | [PhoneNumberMnemonic.java] | [phone_number_mnemonic.py] | 
| The look-and-say problem | [look_and_say.cc] | [LookAndSay.java] | [look_and_say.py] | 
| Convert from Roman to decimal | [roman_to_integer.cc] | [RomanToInteger.java] | [roman_to_integer.py] | 
| Compute all valid IP addresses | [valid_ip_addresses.cc] | [ValidIpAddresses.java] | [valid_ip_addresses.py] | 
| Write a string sinusoidally | [snake_string.cc] | [SnakeString.java] | [snake_string.py] | 
| Implement run-length encoding | [run_length_compression.cc] | [RunLengthCompression.java] | [run_length_compression.py] | 
| Find the first occurrence of a substring | [substring_match.cc] | [SubstringMatch.java] | [substring_match.py] | 
| Bootcamp: Linked Lists | [search_in_list.cc] | [SearchInList.java] | [search_in_list.py] | 
| Bootcamp: Linked Lists | [insert_in_list.cc] | [InsertInList.java] | [insert_in_list.py] | 
| Bootcamp: Linked Lists | [delete_from_list.cc] | [DeleteFromList.java] | [delete_from_list.py] | 
| Merge two sorted lists | [sorted_lists_merge.cc] | [SortedListsMerge.java] | [sorted_lists_merge.py] | 
| Reverse a single sublist | [reverse_sublist.cc] | [ReverseSublist.java] | [reverse_sublist.py] | 
| Test for cyclicity | [is_list_cyclic.cc] | [IsListCyclic.java] | [is_list_cyclic.py] | 
| Test for overlapping lists - lists are cycle-free | [do_terminated_lists_overlap.cc] | [DoTerminatedListsOverlap.java] | [do_terminated_lists_overlap.py] | 
| Test for overlapping lists - lists may have cycles | [do_lists_overlap.cc] | [DoListsOverlap.java] | [do_lists_overlap.py] | 
| Delete a node from a singly linked list | [delete_node_from_list.cc] | [DeleteNodeFromList.java] | [delete_node_from_list.py] | 
| Remove the kth last element from a list | [delete_kth_last_from_list.cc] | [DeleteKthLastFromList.java] | [delete_kth_last_from_list.py] | 
| Remove duplicates from a sorted list | [remove_duplicates_from_sorted_list.cc] | [RemoveDuplicatesFromSortedList.java] | [remove_duplicates_from_sorted_list.py] | 
| Implement cyclic right shift for singly linked lists | [list_cyclic_right_shift.cc] | [ListCyclicRightShift.java] | [list_cyclic_right_shift.py] | 
| Implement even-odd merge | [even_odd_list_merge.cc] | [EvenOddListMerge.java] | [even_odd_list_merge.py] | 
| Test whether a singly linked list is palindromic | [is_list_palindromic.cc] | [IsListPalindromic.java] | [is_list_palindromic.py] | 
| Implement list pivoting | [pivot_list.cc] | [PivotList.java] | [pivot_list.py] | 
| Add list-based integers | [int_as_list_add.cc] | [IntAsListAdd.java] | [int_as_list_add.py] | 
| Implement a stack with max API | [stack_with_max.cc] | [StackWithMax.java] | [stack_with_max.py] | 
| Evaluate RPN expressions | [evaluate_rpn.cc] | [EvaluateRpn.java] | [evaluate_rpn.py] | 
| Test a string over ''{,},(,),[,]'' for well-formedness | [is_valid_parenthesization.cc] | [IsValidParenthesization.java] | [is_valid_parenthesization.py] | 
| Normalize pathnames | [directory_path_normalization.cc] | [DirectoryPathNormalization.java] | [directory_path_normalization.py] | 
| Compute buildings with a sunset view | [sunset_view.cc] | [SunsetView.java] | [sunset_view.py] | 
| Compute binary tree nodes in order of increasing depth | [tree_level_order.cc] | [TreeLevelOrder.java] | [tree_level_order.py] | 
| Implement a circular queue | [circular_queue.cc] | [CircularQueue.java] | [circular_queue.py] | 
| Implement a queue using stacks | [queue_from_stacks.cc] | [QueueFromStacks.java] | [queue_from_stacks.py] | 
| Implement a queue with max API | [queue_with_max.cc] | [QueueWithMax.java] | [queue_with_max.py] | 
| Test if a binary tree is height-balanced | [is_tree_balanced.cc] | [IsTreeBalanced.java] | [is_tree_balanced.py] | 
| Test if a binary tree is symmetric | [is_tree_symmetric.cc] | [IsTreeSymmetric.java] | [is_tree_symmetric.py] | 
| Compute the lowest common ancestor in a binary tree | [lowest_common_ancestor.cc] | [LowestCommonAncestor.java] | [lowest_common_ancestor.py] | 
| Compute the LCA when nodes have parent pointers | [lowest_common_ancestor_with_parent.cc] | [LowestCommonAncestorWithParent.java] | [lowest_common_ancestor_with_parent.py] | 
| Sum the root-to-leaf paths in a binary tree | [sum_root_to_leaf.cc] | [SumRootToLeaf.java] | [sum_root_to_leaf.py] | 
| Find a root to leaf path with specified sum | [path_sum.cc] | [PathSum.java] | [path_sum.py] | 
| Implement an inorder traversal without recursion | [tree_inorder.cc] | [TreeInorder.java] | [tree_inorder.py] | 
| Implement a preorder traversal without recursion | [tree_preorder.cc] | [TreePreorder.java] | [tree_preorder.py] | 
| Compute the kth node in an inorder traversal | [kth_node_in_tree.cc] | [KthNodeInTree.java] | [kth_node_in_tree.py] | 
| Compute the successor | [successor_in_tree.cc] | [SuccessorInTree.java] | [successor_in_tree.py] | 
| Implement an inorder traversal with O(1) space | [tree_with_parent_inorder.cc] | [TreeWithParentInorder.java] | [tree_with_parent_inorder.py] | 
| Reconstruct a binary tree from traversal data | [tree_from_preorder_inorder.cc] | [TreeFromPreorderInorder.java] | [tree_from_preorder_inorder.py] | 
| Reconstruct a binary tree from a preorder traversal with markers | [tree_from_preorder_with_null.cc] | [TreeFromPreorderWithNull.java] | [tree_from_preorder_with_null.py] | 
| Form a linked list from the leaves of a binary tree | [tree_connect_leaves.cc] | [TreeConnectLeaves.java] | [tree_connect_leaves.py] | 
| Compute the exterior of a binary tree | [tree_exterior.cc] | [TreeExterior.java] | [tree_exterior.py] | 
| Compute the right sibling tree | [tree_right_sibling.cc] | [TreeRightSibling.java] | [tree_right_sibling.py] | 
| Merge sorted files | [sorted_arrays_merge.cc] | [SortedArraysMerge.java] | [sorted_arrays_merge.py] | 
| Sort an increasing-decreasing array | [sort_increasing_decreasing_array.cc] | [SortIncreasingDecreasingArray.java] | [sort_increasing_decreasing_array.py] | 
| Sort an almost-sorted array | [sort_almost_sorted_array.cc] | [SortAlmostSortedArray.java] | [sort_almost_sorted_array.py] | 
| Compute the k closest stars | [k_closest_stars.cc] | [KClosestStars.java] | [k_closest_stars.py] | 
| Compute the median of online data | [online_median.cc] | [OnlineMedian.java] | [online_median.py] | 
| Compute the k largest elements in a max-heap | [k_largest_in_heap.cc] | [KLargestInHeap.java] | [k_largest_in_heap.py] | 
| Search a sorted array for first occurrence of k | [search_first_key.cc] | [SearchFirstKey.java] | [search_first_key.py] | 
| Search a sorted array for entry equal to its index | [search_entry_equal_to_index.cc] | [SearchEntryEqualToIndex.java] | [search_entry_equal_to_index.py] | 
| Search a cyclically sorted array | [search_shifted_sorted_array.cc] | [SearchShiftedSortedArray.java] | [search_shifted_sorted_array.py] | 
| Compute the integer square root | [int_square_root.cc] | [IntSquareRoot.java] | [int_square_root.py] | 
| Compute the real square root | [real_square_root.cc] | [RealSquareRoot.java] | [real_square_root.py] | 
| Search in a 2D sorted array | [search_row_col_sorted_matrix.cc] | [SearchRowColSortedMatrix.java] | [search_row_col_sorted_matrix.py] | 
| Find the min and max simultaneously | [search_for_min_max_in_array.cc] | [SearchForMinMaxInArray.java] | [search_for_min_max_in_array.py] | 
| Find the kth largest element | [kth_largest_in_array.cc] | [KthLargestInArray.java] | [kth_largest_in_array.py] | 
| Find the missing IP address | [absent_value_array.cc] | [AbsentValueArray.java] | [absent_value_array.py] | 
| Find the duplicate and missing elements | [search_for_missing_element.cc] | [SearchForMissingElement.java] | [search_for_missing_element.py] | 
| Bootcamp: Hash Tables | [anagrams.cc] | [Anagrams.java] | [anagrams.py] | 
| Test for palindromic permutations | [is_string_permutable_to_palindrome.cc] | [IsStringPermutableToPalindrome.java] | [is_string_permutable_to_palindrome.py] | 
| Is an anonymous letter constructible? | [is_anonymous_letter_constructible.cc] | [IsAnonymousLetterConstructible.java] | [is_anonymous_letter_constructible.py] | 
| Implement an ISBN cache | [lru_cache.cc] | [LRUCache.java] | [lru_cache.py] | 
| Compute the LCA, optimizing for close ancestors | [lowest_common_ancestor_close_ancestor.cc] | [LowestCommonAncestorCloseAncestor.java] | [lowest_common_ancestor_close_ancestor.py] | 
| Find the nearest repeated entries in an array | [nearest_repeated_entries.cc] | [NearestRepeatedEntries.java] | [nearest_repeated_entries.py] | 
| Find the smallest subarray covering all values | [smallest_subarray_covering_set.cc] | [SmallestSubarrayCoveringSet.java] | [smallest_subarray_covering_set.py] | 
| Find smallest subarray sequentially covering all values | [smallest_subarray_covering_all_values.cc] | [SmallestSubarrayCoveringAllValues.java] | [smallest_subarray_covering_all_values.py] | 
| Find the longest subarray with distinct entries | [longest_subarray_with_distinct_values.cc] | [LongestSubarrayWithDistinctValues.java] | [longest_subarray_with_distinct_values.py] | 
| Find the length of a longest contained interval | [longest_contained_interval.cc] | [LongestContainedInterval.java] | [longest_contained_interval.py] | 
| Compute all string decompositions | [string_decompositions_into_dictionary_words.cc] | [StringDecompositionsIntoDictionaryWords.java] | [string_decompositions_into_dictionary_words.py] | 
| Test the Collatz conjecture | [collatz_checker.cc] | [CollatzChecker.java] | [collatz_checker.py] | 
| Compute the intersection of two sorted arrays | [intersect_sorted_arrays.cc] | [IntersectSortedArrays.java] | [intersect_sorted_arrays.py] | 
| Remove first-name duplicates | [remove_duplicates.cc] | [RemoveDuplicates.java] | [remove_duplicates.py] | 
| Smallest nonconstructible value | [smallest_nonconstructible_value.cc] | [SmallestNonconstructibleValue.java] | [smallest_nonconstructible_value.py] | 
| Render a calendar | [calendar_rendering.cc] | [CalendarRendering.java] | [calendar_rendering.py] | 
| Merging intervals | [interval_add.cc] | [IntervalAdd.java] | [interval_add.py] | 
| Compute the union of intervals | [intervals_union.cc] | [IntervalsUnion.java] | [intervals_union.py] | 
| Partitioning and sorting an array with many repeated entries | [group_equal_entries.cc] | [GroupEqualEntries.java] | [group_equal_entries.py] | 
| Team photo day - 1 | [is_array_dominated.cc] | [IsArrayDominated.java] | [is_array_dominated.py] | 
| Implement a fast sorting algorithm for lists | [sort_list.cc] | [SortList.java] | [sort_list.py] | 
| Compute a salary threshold | [find_salary_threshold.cc] | [FindSalaryThreshold.java] | [find_salary_threshold.py] | 
| Test if a binary tree satisfies the BST property | [is_tree_a_bst.cc] | [IsTreeABst.java] | [is_tree_a_bst.py] | 
| Find the first key greater than a given value in a BST | [search_first_greater_value_in_bst.cc] | [SearchFirstGreaterValueInBst.java] | [search_first_greater_value_in_bst.py] | 
| Find the k largest elements in a BST | [k_largest_values_in_bst.cc] | [KLargestValuesInBst.java] | [k_largest_values_in_bst.py] | 
| Compute the LCA in a BST | [lowest_common_ancestor_in_bst.cc] | [LowestCommonAncestorInBst.java] | [lowest_common_ancestor_in_bst.py] | 
| Reconstruct a BST from traversal data | [bst_from_preorder.cc] | [BstFromPreorder.java] | [bst_from_preorder.py] | 
| Find the closest entries in three sorted arrays | [minimum_distance_3_sorted_arrays.cc] | [MinimumDistance3SortedArrays.java] | [minimum_distance_3_sorted_arrays.py] | 
| Build a minimum height BST from a sorted array | [bst_from_sorted_array.cc] | [BstFromSortedArray.java] | [bst_from_sorted_array.py] | 
| Test if three BST nodes are totally ordered | [descendant_and_ancestor_in_bst.cc] | [DescendantAndAncestorInBst.java] | [descendant_and_ancestor_in_bst.py] | 
| Add credits | [adding_credits.cc] | [AddingCredits.java] | [adding_credits.py] | 
| The Towers of Hanoi problem | [hanoi.cc] | [Hanoi.java] | [hanoi.py] | 
| Generate all nonattacking placements of n-Queens | [n_queens.cc] | [NQueens.java] | [n_queens.py] | 
| Generate permutations | [permutations.cc] | [Permutations.java] | [permutations.py] | 
| Generate the power set | [power_set.cc] | [PowerSet.java] | [power_set.py] | 
| Generate all subsets of size k | [combinations.cc] | [Combinations.java] | [combinations.py] | 
| Generate strings of matched parens | [enumerate_balanced_parentheses.cc] | [EnumerateBalancedParentheses.java] | [enumerate_balanced_parentheses.py] | 
| Generate palindromic decompositions | [enumerate_palindromic_decompositions.cc] | [EnumeratePalindromicDecompositions.java] | [enumerate_palindromic_decompositions.py] | 
| Generate binary trees | [enumerate_trees.cc] | [EnumerateTrees.java] | [enumerate_trees.py] | 
| Implement a Sudoku solver | [sudoku_solve.cc] | [SudokuSolve.java] | [sudoku_solve.py] | 
| Compute a Gray code | [gray_code.cc] | [GrayCode.java] | [gray_code.py] | 
| Count the number of score combinations | [number_of_score_combinations.cc] | [NumberOfScoreCombinations.java] | [number_of_score_combinations.py] | 
| Compute the Levenshtein distance | [levenshtein_distance.cc] | [LevenshteinDistance.java] | [levenshtein_distance.py] | 
| Count the number of ways to traverse a 2D array | [number_of_traversals_matrix.cc] | [NumberOfTraversalsMatrix.java] | [number_of_traversals_matrix.py] | 
| Compute the binomial coefficients | [binomial_coefficients.cc] | [BinomialCoefficients.java] | [binomial_coefficients.py] | 
| Search for a sequence in a 2D array | [is_string_in_matrix.cc] | [IsStringInMatrix.java] | [is_string_in_matrix.py] | 
| The knapsack problem | [knapsack.cc] | [Knapsack.java] | [knapsack.py] | 
| The bedbathandbeyond.com problem | [is_string_decomposable_into_words.cc] | [IsStringDecomposableIntoWords.java] | [is_string_decomposable_into_words.py] | 
| Find the minimum weight path in a triangle | [minimum_weight_path_in_a_triangle.cc] | [MinimumWeightPathInATriangle.java] | [minimum_weight_path_in_a_triangle.py] | 
| Pick up coins for maximum gain | [picking_up_coins.cc] | [PickingUpCoins.java] | [picking_up_coins.py] | 
| Count the number of moves to climb stairs | [number_of_traversals_staircase.cc] | [NumberOfTraversalsStaircase.java] | [number_of_traversals_staircase.py] | 
| The pretty printing problem | [pretty_printing.cc] | [PrettyPrinting.java] | [pretty_printing.py] | 
| Find the longest nondecreasing subsequence | [longest_nondecreasing_subsequence.cc] | [LongestNondecreasingSubsequence.java] | [longest_nondecreasing_subsequence.py] | 
| Compute an optimum assignment of tasks | [task_pairing.cc] | [TaskPairing.java] | [task_pairing.py] | 
| Schedule to minimize waiting time | [minimum_waiting_time.cc] | [MinimumWaitingTime.java] | [minimum_waiting_time.py] | 
| The interval covering problem | [minimum_points_covering_intervals.cc] | [MinimumPointsCoveringIntervals.java] | [minimum_points_covering_intervals.py] | 
| The interval covering problem | [two_sum.cc] | [TwoSum.java] | [two_sum.py] | 
| The 3-sum problem | [three_sum.cc] | [ThreeSum.java] | [three_sum.py] | 
| Find the majority element | [majority_element.cc] | [MajorityElement.java] | [majority_element.py] | 
| The gasup problem | [refueling_schedule.cc] | [RefuelingSchedule.java] | [refueling_schedule.py] | 
| Compute the largest rectangle under the skyline | [largest_rectangle_under_skyline.cc] | [LargestRectangleUnderSkyline.java] | [largest_rectangle_under_skyline.py] | 
| Search a maze | [search_maze.cc] | [SearchMaze.java] | [search_maze.py] | 
| Compute enclosed regions | [matrix_enclosed_regions.cc] | [MatrixEnclosedRegions.java] | [matrix_enclosed_regions.py] | 
| Deadlock detection | [deadlock_detection.cc] | [DeadlockDetection.java] | [deadlock_detection.py] | 
| Clone a graph | [graph_clone.cc] | [GraphClone.java] | [graph_clone.py] | 
| Making wired connections | [is_circuit_wirable.cc] | [IsCircuitWirable.java] | [is_circuit_wirable.py] | 
| Transform one string to another | [string_transformability.cc] | [StringTransformability.java] | [string_transformability.py] | 
| Team photo day - 2 | [max_teams_in_photograph.cc] | [MaxTeamsInPhotograph.java] | [max_teams_in_photograph.py] | 
| Compute the greatest common divisor | [gcd.cc] | [Gcd.java] | [gcd.py] | 
| Find the first missing positive entry | [first_missing_positive_entry.cc] | [FirstMissingPositiveEntry.java] | [first_missing_positive_entry.py] | 
| Buy and sell a stock k times | [buy_and_sell_stock_k_times.cc] | [BuyAndSellStockKTimes.java] | [buy_and_sell_stock_k_times.py] | 
| Compute the maximum product of all entries but one | [max_product_all_but_one.cc] | [MaxProductAllButOne.java] | [max_product_all_but_one.py] | 
| Compute the longest contiguous increasing subarray | [longest_increasing_subarray.cc] | [LongestIncreasingSubarray.java] | [longest_increasing_subarray.py] | 
| Rotate an array | [rotate_array.cc] | [RotateArray.java] | [rotate_array.py] | 
| Identify positions attacked by rooks | [rook_attack.cc] | [RookAttack.java] | [rook_attack.py] | 
| Justify text | [left_right_justify_text.cc] | [LeftRightJustifyText.java] | [left_right_justify_text.py] | 
| Implement list zipping | [zip_list.cc] | [ZipList.java] | [zip_list.py] | 
| Copy a postings list | [copy_posting_list.cc] | [CopyPostingList.java] | [copy_posting_list.py] | 
| Compute the longest substring with matching parens | [longest_substring_with_matching_parentheses.cc] | [LongestSubstringWithMatchingParentheses.java] | [longest_substring_with_matching_parentheses.py] | 
| Compute the maximum of a sliding window | [max_of_sliding_window.cc] | [MaxOfSlidingWindow.java] | [max_of_sliding_window.py] | 
| Implement a postorder traversal without recursion | [tree_postorder.cc] | [TreePostorder.java] | [tree_postorder.py] | 
| Compute fair bonuses | [bonus.cc] | [Bonus.java] | [bonus.py] | 
| Search a sorted array of unknown length | [search_unknown_length_array.cc] | [SearchUnknownLengthArray.java] | [search_unknown_length_array.py] | 
| Search in two sorted arrays | [kth_largest_element_in_two_sorted_arrays.cc] | [KthLargestElementInTwoSortedArrays.java] | [kth_largest_element_in_two_sorted_arrays.py] | 
| Find an element that appears only once | [element_appearing_once.cc] | [ElementAppearingOnce.java] | [element_appearing_once.py] | 
| Find the line through the most points | [line_though_most_points.cc] | [LineThoughMostPoints.java] | [line_though_most_points.py] | 
| Convert a sorted doubly linked list into a BST | [sorted_list_to_bst.cc] | [SortedListToBst.java] | [sorted_list_to_bst.py] | 
| Convert a BST to a sorted doubly linked list | [bst_to_sorted_list.cc] | [BstToSortedList.java] | [bst_to_sorted_list.py] | 
| Merge two BSTs | [bst_merge.cc] | [BstMerge.java] | [bst_merge.py] | 
| Implement regular expression matching | [regular_expression.cc] | [RegularExpression.java] | [regular_expression.py] | 
| Synthesize an expression | [insert_operators_in_string.cc] | [InsertOperatorsInString.java] | [insert_operators_in_string.py] | 
| Count inversions | [count_inversions.cc] | [CountInversions.java] | [count_inversions.py] | 
| Draw the skyline | [drawing_skyline.cc] | [DrawingSkyline.java] | [drawing_skyline.py] | 
| Measure with defective jugs | [defective_jugs.cc] | [DefectiveJugs.java] | [defective_jugs.py] | 
| Compute the maximum subarray sum in a circular array | [maximum_subarray_in_circular_array.cc] | [MaximumSubarrayInCircularArray.java] | [maximum_subarray_in_circular_array.py] | 
| Determine the critical height | [max_safe_height.cc] | [MaxSafeHeight.java] | [max_safe_height.py] | 
| Find the maximum 2D subarray | [max_submatrix.cc] | [MaxSubmatrix.java] | [max_submatrix.py] | 
| Find the maximum 2D subarray | [max_square_submatrix.cc] | [MaxSquareSubmatrix.java] | [max_square_submatrix.py] | 
| Implement Huffman coding | [huffman_coding.cc] | [HuffmanCoding.java] | [huffman_coding.py] | 
| Trapping water | [max_water_trappable.cc] | [MaxWaterTrappable.java] | [max_water_trappable.py] | 
| The heavy hitter problem | [search_frequent_items.cc] | [SearchFrequentItems.java] | [search_frequent_items.py] | 
| Find the longest subarray whose sum <=  k | [longest_subarray_with_sum_constraint.cc] | [LongestSubarrayWithSumConstraint.java] | [longest_subarray_with_sum_constraint.py] | 
| Road network | [road_network.cc] | [RoadNetwork.java] | [road_network.py] | 
| Test if arbitrage is possible | [arbitrage.cc] | [Arbitrage.java] | [arbitrage.py] | 
