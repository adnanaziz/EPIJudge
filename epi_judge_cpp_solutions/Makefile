# Compile and run by "make <program_name>"
# For example, typing "make parity" in your terminal will compile and run parity.cc.
#
# You could try "make last" (or simply "make"), this command will compile and run the last modified file.
# This comes pretty handy while you are working a problem, and then you want to see the result soon without thinking program name.
BUILD_DIR := cpp_build
SRC_DIR := .
TEST_DATA_DIR := ../test_data

# Modify this line if you want to pass custom arguments
PROGRAM_ARGS := --test-data-dir $(TEST_DATA_DIR) 

CXX_COMPILER := g++
CXX_FLAGS := -std=c++17 -pthread -Werror -Wno-unused-variable -Wno-sign-compare
CXX_FLAGS_DEBUG := $(CXX_FLAGS) -g -O0

LAST_MODIFIED_CXX_FILE = $(shell ls -rt $(SRC_DIR)/*\.cc | tail -1)


# Compile and run the last modified file.
last: $(notdir $(basename $(LAST_MODIFIED_CXX_FILE)))

.PHONY: last

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)


# a_b_sqrt2.cc

$(BUILD_DIR)/a_b_sqrt2: $(SRC_DIR)/a_b_sqrt2.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
a_b_sqrt2: $(BUILD_DIR)/a_b_sqrt2
	$< $(PROGRAM_ARGS)

.PHONY: a_b_sqrt2


# absent_value_array.cc

$(BUILD_DIR)/absent_value_array: $(SRC_DIR)/absent_value_array.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
absent_value_array: $(BUILD_DIR)/absent_value_array
	$< $(PROGRAM_ARGS)

.PHONY: absent_value_array


# adding_credits.cc

$(BUILD_DIR)/adding_credits: $(SRC_DIR)/adding_credits.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
adding_credits: $(BUILD_DIR)/adding_credits
	$< $(PROGRAM_ARGS)

.PHONY: adding_credits


# advance_by_offsets.cc

$(BUILD_DIR)/advance_by_offsets: $(SRC_DIR)/advance_by_offsets.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
advance_by_offsets: $(BUILD_DIR)/advance_by_offsets
	$< $(PROGRAM_ARGS)

.PHONY: advance_by_offsets


# alternating_array.cc

$(BUILD_DIR)/alternating_array: $(SRC_DIR)/alternating_array.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
alternating_array: $(BUILD_DIR)/alternating_array
	$< $(PROGRAM_ARGS)

.PHONY: alternating_array


# anagrams.cc

$(BUILD_DIR)/anagrams: $(SRC_DIR)/anagrams.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
anagrams: $(BUILD_DIR)/anagrams
	$< $(PROGRAM_ARGS)

.PHONY: anagrams


# apply_permutation.cc

$(BUILD_DIR)/apply_permutation: $(SRC_DIR)/apply_permutation.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
apply_permutation: $(BUILD_DIR)/apply_permutation
	$< $(PROGRAM_ARGS)

.PHONY: apply_permutation


# arbitrage.cc

$(BUILD_DIR)/arbitrage: $(SRC_DIR)/arbitrage.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
arbitrage: $(BUILD_DIR)/arbitrage
	$< $(PROGRAM_ARGS)

.PHONY: arbitrage


# binomial_coefficients.cc

$(BUILD_DIR)/binomial_coefficients: $(SRC_DIR)/binomial_coefficients.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
binomial_coefficients: $(BUILD_DIR)/binomial_coefficients
	$< $(PROGRAM_ARGS)

.PHONY: binomial_coefficients


# bonus.cc

$(BUILD_DIR)/bonus: $(SRC_DIR)/bonus.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
bonus: $(BUILD_DIR)/bonus
	$< $(PROGRAM_ARGS)

.PHONY: bonus


# bst_from_preorder.cc

$(BUILD_DIR)/bst_from_preorder: $(SRC_DIR)/bst_from_preorder.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
bst_from_preorder: $(BUILD_DIR)/bst_from_preorder
	$< $(PROGRAM_ARGS)

.PHONY: bst_from_preorder


# bst_from_sorted_array.cc

$(BUILD_DIR)/bst_from_sorted_array: $(SRC_DIR)/bst_from_sorted_array.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
bst_from_sorted_array: $(BUILD_DIR)/bst_from_sorted_array
	$< $(PROGRAM_ARGS)

.PHONY: bst_from_sorted_array


# bst_merge.cc

$(BUILD_DIR)/bst_merge: $(SRC_DIR)/bst_merge.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
bst_merge: $(BUILD_DIR)/bst_merge
	$< $(PROGRAM_ARGS)

.PHONY: bst_merge


# bst_to_sorted_list.cc

$(BUILD_DIR)/bst_to_sorted_list: $(SRC_DIR)/bst_to_sorted_list.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
bst_to_sorted_list: $(BUILD_DIR)/bst_to_sorted_list
	$< $(PROGRAM_ARGS)

.PHONY: bst_to_sorted_list


# buy_and_sell_stock.cc

$(BUILD_DIR)/buy_and_sell_stock: $(SRC_DIR)/buy_and_sell_stock.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
buy_and_sell_stock: $(BUILD_DIR)/buy_and_sell_stock
	$< $(PROGRAM_ARGS)

.PHONY: buy_and_sell_stock


# buy_and_sell_stock_k_times.cc

$(BUILD_DIR)/buy_and_sell_stock_k_times: $(SRC_DIR)/buy_and_sell_stock_k_times.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
buy_and_sell_stock_k_times: $(BUILD_DIR)/buy_and_sell_stock_k_times
	$< $(PROGRAM_ARGS)

.PHONY: buy_and_sell_stock_k_times


# buy_and_sell_stock_twice.cc

$(BUILD_DIR)/buy_and_sell_stock_twice: $(SRC_DIR)/buy_and_sell_stock_twice.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
buy_and_sell_stock_twice: $(BUILD_DIR)/buy_and_sell_stock_twice
	$< $(PROGRAM_ARGS)

.PHONY: buy_and_sell_stock_twice


# calendar_rendering.cc

$(BUILD_DIR)/calendar_rendering: $(SRC_DIR)/calendar_rendering.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
calendar_rendering: $(BUILD_DIR)/calendar_rendering
	$< $(PROGRAM_ARGS)

.PHONY: calendar_rendering


# circular_queue.cc

$(BUILD_DIR)/circular_queue: $(SRC_DIR)/circular_queue.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
circular_queue: $(BUILD_DIR)/circular_queue
	$< $(PROGRAM_ARGS)

.PHONY: circular_queue


# closest_int_same_weight.cc

$(BUILD_DIR)/closest_int_same_weight: $(SRC_DIR)/closest_int_same_weight.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
closest_int_same_weight: $(BUILD_DIR)/closest_int_same_weight
	$< $(PROGRAM_ARGS)

.PHONY: closest_int_same_weight


# collatz_checker.cc

$(BUILD_DIR)/collatz_checker: $(SRC_DIR)/collatz_checker.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
collatz_checker: $(BUILD_DIR)/collatz_checker
	$< $(PROGRAM_ARGS)

.PHONY: collatz_checker


# combinations.cc

$(BUILD_DIR)/combinations: $(SRC_DIR)/combinations.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
combinations: $(BUILD_DIR)/combinations
	$< $(PROGRAM_ARGS)

.PHONY: combinations


# convert_base.cc

$(BUILD_DIR)/convert_base: $(SRC_DIR)/convert_base.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
convert_base: $(BUILD_DIR)/convert_base
	$< $(PROGRAM_ARGS)

.PHONY: convert_base


# copy_posting_list.cc

$(BUILD_DIR)/copy_posting_list: $(SRC_DIR)/copy_posting_list.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
copy_posting_list: $(BUILD_DIR)/copy_posting_list
	$< $(PROGRAM_ARGS)

.PHONY: copy_posting_list


# count_bits.cc

$(BUILD_DIR)/count_bits: $(SRC_DIR)/count_bits.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
count_bits: $(BUILD_DIR)/count_bits
	$< $(PROGRAM_ARGS)

.PHONY: count_bits


# count_inversions.cc

$(BUILD_DIR)/count_inversions: $(SRC_DIR)/count_inversions.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
count_inversions: $(BUILD_DIR)/count_inversions
	$< $(PROGRAM_ARGS)

.PHONY: count_inversions


# deadlock_detection.cc

$(BUILD_DIR)/deadlock_detection: $(SRC_DIR)/deadlock_detection.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
deadlock_detection: $(BUILD_DIR)/deadlock_detection
	$< $(PROGRAM_ARGS)

.PHONY: deadlock_detection


# defective_jugs.cc

$(BUILD_DIR)/defective_jugs: $(SRC_DIR)/defective_jugs.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
defective_jugs: $(BUILD_DIR)/defective_jugs
	$< $(PROGRAM_ARGS)

.PHONY: defective_jugs


# delete_from_list.cc

$(BUILD_DIR)/delete_from_list: $(SRC_DIR)/delete_from_list.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
delete_from_list: $(BUILD_DIR)/delete_from_list
	$< $(PROGRAM_ARGS)

.PHONY: delete_from_list


# delete_kth_last_from_list.cc

$(BUILD_DIR)/delete_kth_last_from_list: $(SRC_DIR)/delete_kth_last_from_list.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
delete_kth_last_from_list: $(BUILD_DIR)/delete_kth_last_from_list
	$< $(PROGRAM_ARGS)

.PHONY: delete_kth_last_from_list


# delete_node_from_list.cc

$(BUILD_DIR)/delete_node_from_list: $(SRC_DIR)/delete_node_from_list.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
delete_node_from_list: $(BUILD_DIR)/delete_node_from_list
	$< $(PROGRAM_ARGS)

.PHONY: delete_node_from_list


# descendant_and_ancestor_in_bst.cc

$(BUILD_DIR)/descendant_and_ancestor_in_bst: $(SRC_DIR)/descendant_and_ancestor_in_bst.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
descendant_and_ancestor_in_bst: $(BUILD_DIR)/descendant_and_ancestor_in_bst
	$< $(PROGRAM_ARGS)

.PHONY: descendant_and_ancestor_in_bst


# directory_path_normalization.cc

$(BUILD_DIR)/directory_path_normalization: $(SRC_DIR)/directory_path_normalization.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
directory_path_normalization: $(BUILD_DIR)/directory_path_normalization
	$< $(PROGRAM_ARGS)

.PHONY: directory_path_normalization


# do_lists_overlap.cc

$(BUILD_DIR)/do_lists_overlap: $(SRC_DIR)/do_lists_overlap.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
do_lists_overlap: $(BUILD_DIR)/do_lists_overlap
	$< $(PROGRAM_ARGS)

.PHONY: do_lists_overlap


# do_terminated_lists_overlap.cc

$(BUILD_DIR)/do_terminated_lists_overlap: $(SRC_DIR)/do_terminated_lists_overlap.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
do_terminated_lists_overlap: $(BUILD_DIR)/do_terminated_lists_overlap
	$< $(PROGRAM_ARGS)

.PHONY: do_terminated_lists_overlap


# drawing_skyline.cc

$(BUILD_DIR)/drawing_skyline: $(SRC_DIR)/drawing_skyline.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
drawing_skyline: $(BUILD_DIR)/drawing_skyline
	$< $(PROGRAM_ARGS)

.PHONY: drawing_skyline


# dutch_national_flag.cc

$(BUILD_DIR)/dutch_national_flag: $(SRC_DIR)/dutch_national_flag.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
dutch_national_flag: $(BUILD_DIR)/dutch_national_flag
	$< $(PROGRAM_ARGS)

.PHONY: dutch_national_flag


# element_appearing_once.cc

$(BUILD_DIR)/element_appearing_once: $(SRC_DIR)/element_appearing_once.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
element_appearing_once: $(BUILD_DIR)/element_appearing_once
	$< $(PROGRAM_ARGS)

.PHONY: element_appearing_once


# enumerate_balanced_parentheses.cc

$(BUILD_DIR)/enumerate_balanced_parentheses: $(SRC_DIR)/enumerate_balanced_parentheses.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
enumerate_balanced_parentheses: $(BUILD_DIR)/enumerate_balanced_parentheses
	$< $(PROGRAM_ARGS)

.PHONY: enumerate_balanced_parentheses


# enumerate_palindromic_decompositions.cc

$(BUILD_DIR)/enumerate_palindromic_decompositions: $(SRC_DIR)/enumerate_palindromic_decompositions.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
enumerate_palindromic_decompositions: $(BUILD_DIR)/enumerate_palindromic_decompositions
	$< $(PROGRAM_ARGS)

.PHONY: enumerate_palindromic_decompositions


# enumerate_trees.cc

$(BUILD_DIR)/enumerate_trees: $(SRC_DIR)/enumerate_trees.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
enumerate_trees: $(BUILD_DIR)/enumerate_trees
	$< $(PROGRAM_ARGS)

.PHONY: enumerate_trees


# euclidean_gcd.cc

$(BUILD_DIR)/euclidean_gcd: $(SRC_DIR)/euclidean_gcd.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
euclidean_gcd: $(BUILD_DIR)/euclidean_gcd
	$< $(PROGRAM_ARGS)

.PHONY: euclidean_gcd


# evaluate_rpn.cc

$(BUILD_DIR)/evaluate_rpn: $(SRC_DIR)/evaluate_rpn.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
evaluate_rpn: $(BUILD_DIR)/evaluate_rpn
	$< $(PROGRAM_ARGS)

.PHONY: evaluate_rpn


# even_odd_array.cc

$(BUILD_DIR)/even_odd_array: $(SRC_DIR)/even_odd_array.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
even_odd_array: $(BUILD_DIR)/even_odd_array
	$< $(PROGRAM_ARGS)

.PHONY: even_odd_array


# even_odd_list_merge.cc

$(BUILD_DIR)/even_odd_list_merge: $(SRC_DIR)/even_odd_list_merge.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
even_odd_list_merge: $(BUILD_DIR)/even_odd_list_merge
	$< $(PROGRAM_ARGS)

.PHONY: even_odd_list_merge


# fibonacci.cc

$(BUILD_DIR)/fibonacci: $(SRC_DIR)/fibonacci.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
fibonacci: $(BUILD_DIR)/fibonacci
	$< $(PROGRAM_ARGS)

.PHONY: fibonacci


# find_salary_threshold.cc

$(BUILD_DIR)/find_salary_threshold: $(SRC_DIR)/find_salary_threshold.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
find_salary_threshold: $(BUILD_DIR)/find_salary_threshold
	$< $(PROGRAM_ARGS)

.PHONY: find_salary_threshold


# first_missing_positive_entry.cc

$(BUILD_DIR)/first_missing_positive_entry: $(SRC_DIR)/first_missing_positive_entry.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
first_missing_positive_entry: $(BUILD_DIR)/first_missing_positive_entry
	$< $(PROGRAM_ARGS)

.PHONY: first_missing_positive_entry


# gcd.cc

$(BUILD_DIR)/gcd: $(SRC_DIR)/gcd.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
gcd: $(BUILD_DIR)/gcd
	$< $(PROGRAM_ARGS)

.PHONY: gcd


# graph_clone.cc

$(BUILD_DIR)/graph_clone: $(SRC_DIR)/graph_clone.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
graph_clone: $(BUILD_DIR)/graph_clone
	$< $(PROGRAM_ARGS)

.PHONY: graph_clone


# gray_code.cc

$(BUILD_DIR)/gray_code: $(SRC_DIR)/gray_code.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
gray_code: $(BUILD_DIR)/gray_code
	$< $(PROGRAM_ARGS)

.PHONY: gray_code


# group_equal_entries.cc

$(BUILD_DIR)/group_equal_entries: $(SRC_DIR)/group_equal_entries.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
group_equal_entries: $(BUILD_DIR)/group_equal_entries
	$< $(PROGRAM_ARGS)

.PHONY: group_equal_entries


# h_index.cc

$(BUILD_DIR)/h_index: $(SRC_DIR)/h_index.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
h_index: $(BUILD_DIR)/h_index
	$< $(PROGRAM_ARGS)

.PHONY: h_index


# hanoi.cc

$(BUILD_DIR)/hanoi: $(SRC_DIR)/hanoi.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
hanoi: $(BUILD_DIR)/hanoi
	$< $(PROGRAM_ARGS)

.PHONY: hanoi


# huffman_coding.cc

$(BUILD_DIR)/huffman_coding: $(SRC_DIR)/huffman_coding.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
huffman_coding: $(BUILD_DIR)/huffman_coding
	$< $(PROGRAM_ARGS)

.PHONY: huffman_coding


# insert_in_list.cc

$(BUILD_DIR)/insert_in_list: $(SRC_DIR)/insert_in_list.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
insert_in_list: $(BUILD_DIR)/insert_in_list
	$< $(PROGRAM_ARGS)

.PHONY: insert_in_list


# insert_operators_in_string.cc

$(BUILD_DIR)/insert_operators_in_string: $(SRC_DIR)/insert_operators_in_string.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
insert_operators_in_string: $(BUILD_DIR)/insert_operators_in_string
	$< $(PROGRAM_ARGS)

.PHONY: insert_operators_in_string


# int_as_array_increment.cc

$(BUILD_DIR)/int_as_array_increment: $(SRC_DIR)/int_as_array_increment.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
int_as_array_increment: $(BUILD_DIR)/int_as_array_increment
	$< $(PROGRAM_ARGS)

.PHONY: int_as_array_increment


# int_as_array_multiply.cc

$(BUILD_DIR)/int_as_array_multiply: $(SRC_DIR)/int_as_array_multiply.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
int_as_array_multiply: $(BUILD_DIR)/int_as_array_multiply
	$< $(PROGRAM_ARGS)

.PHONY: int_as_array_multiply


# int_as_list_add.cc

$(BUILD_DIR)/int_as_list_add: $(SRC_DIR)/int_as_list_add.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
int_as_list_add: $(BUILD_DIR)/int_as_list_add
	$< $(PROGRAM_ARGS)

.PHONY: int_as_list_add


# int_square_root.cc

$(BUILD_DIR)/int_square_root: $(SRC_DIR)/int_square_root.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
int_square_root: $(BUILD_DIR)/int_square_root
	$< $(PROGRAM_ARGS)

.PHONY: int_square_root


# intersect_sorted_arrays.cc

$(BUILD_DIR)/intersect_sorted_arrays: $(SRC_DIR)/intersect_sorted_arrays.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
intersect_sorted_arrays: $(BUILD_DIR)/intersect_sorted_arrays
	$< $(PROGRAM_ARGS)

.PHONY: intersect_sorted_arrays


# interval_add.cc

$(BUILD_DIR)/interval_add: $(SRC_DIR)/interval_add.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
interval_add: $(BUILD_DIR)/interval_add
	$< $(PROGRAM_ARGS)

.PHONY: interval_add


# intervals_union.cc

$(BUILD_DIR)/intervals_union: $(SRC_DIR)/intervals_union.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
intervals_union: $(BUILD_DIR)/intervals_union
	$< $(PROGRAM_ARGS)

.PHONY: intervals_union


# is_anonymous_letter_constructible.cc

$(BUILD_DIR)/is_anonymous_letter_constructible: $(SRC_DIR)/is_anonymous_letter_constructible.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
is_anonymous_letter_constructible: $(BUILD_DIR)/is_anonymous_letter_constructible
	$< $(PROGRAM_ARGS)

.PHONY: is_anonymous_letter_constructible


# is_array_dominated.cc

$(BUILD_DIR)/is_array_dominated: $(SRC_DIR)/is_array_dominated.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
is_array_dominated: $(BUILD_DIR)/is_array_dominated
	$< $(PROGRAM_ARGS)

.PHONY: is_array_dominated


# is_circuit_wirable.cc

$(BUILD_DIR)/is_circuit_wirable: $(SRC_DIR)/is_circuit_wirable.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
is_circuit_wirable: $(BUILD_DIR)/is_circuit_wirable
	$< $(PROGRAM_ARGS)

.PHONY: is_circuit_wirable


# is_list_cyclic.cc

$(BUILD_DIR)/is_list_cyclic: $(SRC_DIR)/is_list_cyclic.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
is_list_cyclic: $(BUILD_DIR)/is_list_cyclic
	$< $(PROGRAM_ARGS)

.PHONY: is_list_cyclic


# is_list_palindromic.cc

$(BUILD_DIR)/is_list_palindromic: $(SRC_DIR)/is_list_palindromic.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
is_list_palindromic: $(BUILD_DIR)/is_list_palindromic
	$< $(PROGRAM_ARGS)

.PHONY: is_list_palindromic


# is_number_palindromic.cc

$(BUILD_DIR)/is_number_palindromic: $(SRC_DIR)/is_number_palindromic.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
is_number_palindromic: $(BUILD_DIR)/is_number_palindromic
	$< $(PROGRAM_ARGS)

.PHONY: is_number_palindromic


# is_string_decomposable_into_words.cc

$(BUILD_DIR)/is_string_decomposable_into_words: $(SRC_DIR)/is_string_decomposable_into_words.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
is_string_decomposable_into_words: $(BUILD_DIR)/is_string_decomposable_into_words
	$< $(PROGRAM_ARGS)

.PHONY: is_string_decomposable_into_words


# is_string_in_matrix.cc

$(BUILD_DIR)/is_string_in_matrix: $(SRC_DIR)/is_string_in_matrix.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
is_string_in_matrix: $(BUILD_DIR)/is_string_in_matrix
	$< $(PROGRAM_ARGS)

.PHONY: is_string_in_matrix


# is_string_palindromic.cc

$(BUILD_DIR)/is_string_palindromic: $(SRC_DIR)/is_string_palindromic.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
is_string_palindromic: $(BUILD_DIR)/is_string_palindromic
	$< $(PROGRAM_ARGS)

.PHONY: is_string_palindromic


# is_string_palindromic_punctuation.cc

$(BUILD_DIR)/is_string_palindromic_punctuation: $(SRC_DIR)/is_string_palindromic_punctuation.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
is_string_palindromic_punctuation: $(BUILD_DIR)/is_string_palindromic_punctuation
	$< $(PROGRAM_ARGS)

.PHONY: is_string_palindromic_punctuation


# is_string_permutable_to_palindrome.cc

$(BUILD_DIR)/is_string_permutable_to_palindrome: $(SRC_DIR)/is_string_permutable_to_palindrome.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
is_string_permutable_to_palindrome: $(BUILD_DIR)/is_string_permutable_to_palindrome
	$< $(PROGRAM_ARGS)

.PHONY: is_string_permutable_to_palindrome


# is_tree_a_bst.cc

$(BUILD_DIR)/is_tree_a_bst: $(SRC_DIR)/is_tree_a_bst.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
is_tree_a_bst: $(BUILD_DIR)/is_tree_a_bst
	$< $(PROGRAM_ARGS)

.PHONY: is_tree_a_bst


# is_tree_balanced.cc

$(BUILD_DIR)/is_tree_balanced: $(SRC_DIR)/is_tree_balanced.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
is_tree_balanced: $(BUILD_DIR)/is_tree_balanced
	$< $(PROGRAM_ARGS)

.PHONY: is_tree_balanced


# is_tree_symmetric.cc

$(BUILD_DIR)/is_tree_symmetric: $(SRC_DIR)/is_tree_symmetric.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
is_tree_symmetric: $(BUILD_DIR)/is_tree_symmetric
	$< $(PROGRAM_ARGS)

.PHONY: is_tree_symmetric


# is_valid_parenthesization.cc

$(BUILD_DIR)/is_valid_parenthesization: $(SRC_DIR)/is_valid_parenthesization.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
is_valid_parenthesization: $(BUILD_DIR)/is_valid_parenthesization
	$< $(PROGRAM_ARGS)

.PHONY: is_valid_parenthesization


# is_valid_sudoku.cc

$(BUILD_DIR)/is_valid_sudoku: $(SRC_DIR)/is_valid_sudoku.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
is_valid_sudoku: $(BUILD_DIR)/is_valid_sudoku
	$< $(PROGRAM_ARGS)

.PHONY: is_valid_sudoku


# k_closest_stars.cc

$(BUILD_DIR)/k_closest_stars: $(SRC_DIR)/k_closest_stars.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
k_closest_stars: $(BUILD_DIR)/k_closest_stars
	$< $(PROGRAM_ARGS)

.PHONY: k_closest_stars


# k_largest_in_heap.cc

$(BUILD_DIR)/k_largest_in_heap: $(SRC_DIR)/k_largest_in_heap.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
k_largest_in_heap: $(BUILD_DIR)/k_largest_in_heap
	$< $(PROGRAM_ARGS)

.PHONY: k_largest_in_heap


# k_largest_values_in_bst.cc

$(BUILD_DIR)/k_largest_values_in_bst: $(SRC_DIR)/k_largest_values_in_bst.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
k_largest_values_in_bst: $(BUILD_DIR)/k_largest_values_in_bst
	$< $(PROGRAM_ARGS)

.PHONY: k_largest_values_in_bst


# knapsack.cc

$(BUILD_DIR)/knapsack: $(SRC_DIR)/knapsack.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
knapsack: $(BUILD_DIR)/knapsack
	$< $(PROGRAM_ARGS)

.PHONY: knapsack


# kth_largest_element_in_long_array.cc

$(BUILD_DIR)/kth_largest_element_in_long_array: $(SRC_DIR)/kth_largest_element_in_long_array.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
kth_largest_element_in_long_array: $(BUILD_DIR)/kth_largest_element_in_long_array
	$< $(PROGRAM_ARGS)

.PHONY: kth_largest_element_in_long_array


# kth_largest_element_in_two_sorted_arrays.cc

$(BUILD_DIR)/kth_largest_element_in_two_sorted_arrays: $(SRC_DIR)/kth_largest_element_in_two_sorted_arrays.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
kth_largest_element_in_two_sorted_arrays: $(BUILD_DIR)/kth_largest_element_in_two_sorted_arrays
	$< $(PROGRAM_ARGS)

.PHONY: kth_largest_element_in_two_sorted_arrays


# kth_largest_in_array.cc

$(BUILD_DIR)/kth_largest_in_array: $(SRC_DIR)/kth_largest_in_array.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
kth_largest_in_array: $(BUILD_DIR)/kth_largest_in_array
	$< $(PROGRAM_ARGS)

.PHONY: kth_largest_in_array


# kth_node_in_tree.cc

$(BUILD_DIR)/kth_node_in_tree: $(SRC_DIR)/kth_node_in_tree.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
kth_node_in_tree: $(BUILD_DIR)/kth_node_in_tree
	$< $(PROGRAM_ARGS)

.PHONY: kth_node_in_tree


# largest_rectangle_under_skyline.cc

$(BUILD_DIR)/largest_rectangle_under_skyline: $(SRC_DIR)/largest_rectangle_under_skyline.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
largest_rectangle_under_skyline: $(BUILD_DIR)/largest_rectangle_under_skyline
	$< $(PROGRAM_ARGS)

.PHONY: largest_rectangle_under_skyline


# left_right_justify_text.cc

$(BUILD_DIR)/left_right_justify_text: $(SRC_DIR)/left_right_justify_text.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
left_right_justify_text: $(BUILD_DIR)/left_right_justify_text
	$< $(PROGRAM_ARGS)

.PHONY: left_right_justify_text


# levenshtein_distance.cc

$(BUILD_DIR)/levenshtein_distance: $(SRC_DIR)/levenshtein_distance.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
levenshtein_distance: $(BUILD_DIR)/levenshtein_distance
	$< $(PROGRAM_ARGS)

.PHONY: levenshtein_distance


# line_through_most_points.cc

$(BUILD_DIR)/line_through_most_points: $(SRC_DIR)/line_through_most_points.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
line_through_most_points: $(BUILD_DIR)/line_through_most_points
	$< $(PROGRAM_ARGS)

.PHONY: line_through_most_points


# list_cyclic_right_shift.cc

$(BUILD_DIR)/list_cyclic_right_shift: $(SRC_DIR)/list_cyclic_right_shift.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
list_cyclic_right_shift: $(BUILD_DIR)/list_cyclic_right_shift
	$< $(PROGRAM_ARGS)

.PHONY: list_cyclic_right_shift


# longest_contained_interval.cc

$(BUILD_DIR)/longest_contained_interval: $(SRC_DIR)/longest_contained_interval.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
longest_contained_interval: $(BUILD_DIR)/longest_contained_interval
	$< $(PROGRAM_ARGS)

.PHONY: longest_contained_interval


# longest_increasing_subarray.cc

$(BUILD_DIR)/longest_increasing_subarray: $(SRC_DIR)/longest_increasing_subarray.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
longest_increasing_subarray: $(BUILD_DIR)/longest_increasing_subarray
	$< $(PROGRAM_ARGS)

.PHONY: longest_increasing_subarray


# longest_nondecreasing_subsequence.cc

$(BUILD_DIR)/longest_nondecreasing_subsequence: $(SRC_DIR)/longest_nondecreasing_subsequence.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
longest_nondecreasing_subsequence: $(BUILD_DIR)/longest_nondecreasing_subsequence
	$< $(PROGRAM_ARGS)

.PHONY: longest_nondecreasing_subsequence


# longest_subarray_with_distinct_values.cc

$(BUILD_DIR)/longest_subarray_with_distinct_values: $(SRC_DIR)/longest_subarray_with_distinct_values.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
longest_subarray_with_distinct_values: $(BUILD_DIR)/longest_subarray_with_distinct_values
	$< $(PROGRAM_ARGS)

.PHONY: longest_subarray_with_distinct_values


# longest_subarray_with_sum_constraint.cc

$(BUILD_DIR)/longest_subarray_with_sum_constraint: $(SRC_DIR)/longest_subarray_with_sum_constraint.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
longest_subarray_with_sum_constraint: $(BUILD_DIR)/longest_subarray_with_sum_constraint
	$< $(PROGRAM_ARGS)

.PHONY: longest_subarray_with_sum_constraint


# longest_substring_with_matching_parentheses.cc

$(BUILD_DIR)/longest_substring_with_matching_parentheses: $(SRC_DIR)/longest_substring_with_matching_parentheses.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
longest_substring_with_matching_parentheses: $(BUILD_DIR)/longest_substring_with_matching_parentheses
	$< $(PROGRAM_ARGS)

.PHONY: longest_substring_with_matching_parentheses


# look_and_say.cc

$(BUILD_DIR)/look_and_say: $(SRC_DIR)/look_and_say.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
look_and_say: $(BUILD_DIR)/look_and_say
	$< $(PROGRAM_ARGS)

.PHONY: look_and_say


# lowest_common_ancestor.cc

$(BUILD_DIR)/lowest_common_ancestor: $(SRC_DIR)/lowest_common_ancestor.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
lowest_common_ancestor: $(BUILD_DIR)/lowest_common_ancestor
	$< $(PROGRAM_ARGS)

.PHONY: lowest_common_ancestor


# lowest_common_ancestor_close_ancestor.cc

$(BUILD_DIR)/lowest_common_ancestor_close_ancestor: $(SRC_DIR)/lowest_common_ancestor_close_ancestor.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
lowest_common_ancestor_close_ancestor: $(BUILD_DIR)/lowest_common_ancestor_close_ancestor
	$< $(PROGRAM_ARGS)

.PHONY: lowest_common_ancestor_close_ancestor


# lowest_common_ancestor_in_bst.cc

$(BUILD_DIR)/lowest_common_ancestor_in_bst: $(SRC_DIR)/lowest_common_ancestor_in_bst.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
lowest_common_ancestor_in_bst: $(BUILD_DIR)/lowest_common_ancestor_in_bst
	$< $(PROGRAM_ARGS)

.PHONY: lowest_common_ancestor_in_bst


# lowest_common_ancestor_with_parent.cc

$(BUILD_DIR)/lowest_common_ancestor_with_parent: $(SRC_DIR)/lowest_common_ancestor_with_parent.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
lowest_common_ancestor_with_parent: $(BUILD_DIR)/lowest_common_ancestor_with_parent
	$< $(PROGRAM_ARGS)

.PHONY: lowest_common_ancestor_with_parent


# lru_cache.cc

$(BUILD_DIR)/lru_cache: $(SRC_DIR)/lru_cache.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
lru_cache: $(BUILD_DIR)/lru_cache
	$< $(PROGRAM_ARGS)

.PHONY: lru_cache


# majority_element.cc

$(BUILD_DIR)/majority_element: $(SRC_DIR)/majority_element.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
majority_element: $(BUILD_DIR)/majority_element
	$< $(PROGRAM_ARGS)

.PHONY: majority_element


# making_change.cc

$(BUILD_DIR)/making_change: $(SRC_DIR)/making_change.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
making_change: $(BUILD_DIR)/making_change
	$< $(PROGRAM_ARGS)

.PHONY: making_change


# matrix_connected_regions.cc

$(BUILD_DIR)/matrix_connected_regions: $(SRC_DIR)/matrix_connected_regions.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
matrix_connected_regions: $(BUILD_DIR)/matrix_connected_regions
	$< $(PROGRAM_ARGS)

.PHONY: matrix_connected_regions


# matrix_enclosed_regions.cc

$(BUILD_DIR)/matrix_enclosed_regions: $(SRC_DIR)/matrix_enclosed_regions.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
matrix_enclosed_regions: $(BUILD_DIR)/matrix_enclosed_regions
	$< $(PROGRAM_ARGS)

.PHONY: matrix_enclosed_regions


# matrix_rotation.cc

$(BUILD_DIR)/matrix_rotation: $(SRC_DIR)/matrix_rotation.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
matrix_rotation: $(BUILD_DIR)/matrix_rotation
	$< $(PROGRAM_ARGS)

.PHONY: matrix_rotation


# max_of_sliding_window.cc

$(BUILD_DIR)/max_of_sliding_window: $(SRC_DIR)/max_of_sliding_window.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
max_of_sliding_window: $(BUILD_DIR)/max_of_sliding_window
	$< $(PROGRAM_ARGS)

.PHONY: max_of_sliding_window


# max_product_all_but_one.cc

$(BUILD_DIR)/max_product_all_but_one: $(SRC_DIR)/max_product_all_but_one.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
max_product_all_but_one: $(BUILD_DIR)/max_product_all_but_one
	$< $(PROGRAM_ARGS)

.PHONY: max_product_all_but_one


# max_safe_height.cc

$(BUILD_DIR)/max_safe_height: $(SRC_DIR)/max_safe_height.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
max_safe_height: $(BUILD_DIR)/max_safe_height
	$< $(PROGRAM_ARGS)

.PHONY: max_safe_height


# max_square_submatrix.cc

$(BUILD_DIR)/max_square_submatrix: $(SRC_DIR)/max_square_submatrix.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
max_square_submatrix: $(BUILD_DIR)/max_square_submatrix
	$< $(PROGRAM_ARGS)

.PHONY: max_square_submatrix


# max_submatrix.cc

$(BUILD_DIR)/max_submatrix: $(SRC_DIR)/max_submatrix.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
max_submatrix: $(BUILD_DIR)/max_submatrix
	$< $(PROGRAM_ARGS)

.PHONY: max_submatrix


# max_sum_subarray.cc

$(BUILD_DIR)/max_sum_subarray: $(SRC_DIR)/max_sum_subarray.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
max_sum_subarray: $(BUILD_DIR)/max_sum_subarray
	$< $(PROGRAM_ARGS)

.PHONY: max_sum_subarray


# max_teams_in_photograph.cc

$(BUILD_DIR)/max_teams_in_photograph: $(SRC_DIR)/max_teams_in_photograph.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
max_teams_in_photograph: $(BUILD_DIR)/max_teams_in_photograph
	$< $(PROGRAM_ARGS)

.PHONY: max_teams_in_photograph


# max_trapped_water.cc

$(BUILD_DIR)/max_trapped_water: $(SRC_DIR)/max_trapped_water.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
max_trapped_water: $(BUILD_DIR)/max_trapped_water
	$< $(PROGRAM_ARGS)

.PHONY: max_trapped_water


# max_water_trappable.cc

$(BUILD_DIR)/max_water_trappable: $(SRC_DIR)/max_water_trappable.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
max_water_trappable: $(BUILD_DIR)/max_water_trappable
	$< $(PROGRAM_ARGS)

.PHONY: max_water_trappable


# maximum_subarray_in_circular_array.cc

$(BUILD_DIR)/maximum_subarray_in_circular_array: $(SRC_DIR)/maximum_subarray_in_circular_array.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
maximum_subarray_in_circular_array: $(BUILD_DIR)/maximum_subarray_in_circular_array
	$< $(PROGRAM_ARGS)

.PHONY: maximum_subarray_in_circular_array


# minimum_distance_3_sorted_arrays.cc

$(BUILD_DIR)/minimum_distance_3_sorted_arrays: $(SRC_DIR)/minimum_distance_3_sorted_arrays.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
minimum_distance_3_sorted_arrays: $(BUILD_DIR)/minimum_distance_3_sorted_arrays
	$< $(PROGRAM_ARGS)

.PHONY: minimum_distance_3_sorted_arrays


# minimum_points_covering_intervals.cc

$(BUILD_DIR)/minimum_points_covering_intervals: $(SRC_DIR)/minimum_points_covering_intervals.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
minimum_points_covering_intervals: $(BUILD_DIR)/minimum_points_covering_intervals
	$< $(PROGRAM_ARGS)

.PHONY: minimum_points_covering_intervals


# minimum_waiting_time.cc

$(BUILD_DIR)/minimum_waiting_time: $(SRC_DIR)/minimum_waiting_time.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
minimum_waiting_time: $(BUILD_DIR)/minimum_waiting_time
	$< $(PROGRAM_ARGS)

.PHONY: minimum_waiting_time


# minimum_weight_path_in_a_triangle.cc

$(BUILD_DIR)/minimum_weight_path_in_a_triangle: $(SRC_DIR)/minimum_weight_path_in_a_triangle.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
minimum_weight_path_in_a_triangle: $(BUILD_DIR)/minimum_weight_path_in_a_triangle
	$< $(PROGRAM_ARGS)

.PHONY: minimum_weight_path_in_a_triangle


# n_queens.cc

$(BUILD_DIR)/n_queens: $(SRC_DIR)/n_queens.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
n_queens: $(BUILD_DIR)/n_queens
	$< $(PROGRAM_ARGS)

.PHONY: n_queens


# nearest_repeated_entries.cc

$(BUILD_DIR)/nearest_repeated_entries: $(SRC_DIR)/nearest_repeated_entries.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
nearest_repeated_entries: $(BUILD_DIR)/nearest_repeated_entries
	$< $(PROGRAM_ARGS)

.PHONY: nearest_repeated_entries


# next_permutation.cc

$(BUILD_DIR)/next_permutation: $(SRC_DIR)/next_permutation.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
next_permutation: $(BUILD_DIR)/next_permutation
	$< $(PROGRAM_ARGS)

.PHONY: next_permutation


# nonuniform_random_number.cc

$(BUILD_DIR)/nonuniform_random_number: $(SRC_DIR)/nonuniform_random_number.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
nonuniform_random_number: $(BUILD_DIR)/nonuniform_random_number
	$< $(PROGRAM_ARGS)

.PHONY: nonuniform_random_number


# number_of_score_combinations.cc

$(BUILD_DIR)/number_of_score_combinations: $(SRC_DIR)/number_of_score_combinations.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
number_of_score_combinations: $(BUILD_DIR)/number_of_score_combinations
	$< $(PROGRAM_ARGS)

.PHONY: number_of_score_combinations


# number_of_traversals_matrix.cc

$(BUILD_DIR)/number_of_traversals_matrix: $(SRC_DIR)/number_of_traversals_matrix.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
number_of_traversals_matrix: $(BUILD_DIR)/number_of_traversals_matrix
	$< $(PROGRAM_ARGS)

.PHONY: number_of_traversals_matrix


# number_of_traversals_staircase.cc

$(BUILD_DIR)/number_of_traversals_staircase: $(SRC_DIR)/number_of_traversals_staircase.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
number_of_traversals_staircase: $(BUILD_DIR)/number_of_traversals_staircase
	$< $(PROGRAM_ARGS)

.PHONY: number_of_traversals_staircase


# offline_sampling.cc

$(BUILD_DIR)/offline_sampling: $(SRC_DIR)/offline_sampling.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
offline_sampling: $(BUILD_DIR)/offline_sampling
	$< $(PROGRAM_ARGS)

.PHONY: offline_sampling


# online_median.cc

$(BUILD_DIR)/online_median: $(SRC_DIR)/online_median.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
online_median: $(BUILD_DIR)/online_median
	$< $(PROGRAM_ARGS)

.PHONY: online_median


# online_sampling.cc

$(BUILD_DIR)/online_sampling: $(SRC_DIR)/online_sampling.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
online_sampling: $(BUILD_DIR)/online_sampling
	$< $(PROGRAM_ARGS)

.PHONY: online_sampling


# parity.cc

$(BUILD_DIR)/parity: $(SRC_DIR)/parity.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
parity: $(BUILD_DIR)/parity
	$< $(PROGRAM_ARGS)

.PHONY: parity


# pascal_triangle.cc

$(BUILD_DIR)/pascal_triangle: $(SRC_DIR)/pascal_triangle.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
pascal_triangle: $(BUILD_DIR)/pascal_triangle
	$< $(PROGRAM_ARGS)

.PHONY: pascal_triangle


# path_sum.cc

$(BUILD_DIR)/path_sum: $(SRC_DIR)/path_sum.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
path_sum: $(BUILD_DIR)/path_sum
	$< $(PROGRAM_ARGS)

.PHONY: path_sum


# permutations.cc

$(BUILD_DIR)/permutations: $(SRC_DIR)/permutations.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
permutations: $(BUILD_DIR)/permutations
	$< $(PROGRAM_ARGS)

.PHONY: permutations


# phone_number_mnemonic.cc

$(BUILD_DIR)/phone_number_mnemonic: $(SRC_DIR)/phone_number_mnemonic.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
phone_number_mnemonic: $(BUILD_DIR)/phone_number_mnemonic
	$< $(PROGRAM_ARGS)

.PHONY: phone_number_mnemonic


# picking_up_coins.cc

$(BUILD_DIR)/picking_up_coins: $(SRC_DIR)/picking_up_coins.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
picking_up_coins: $(BUILD_DIR)/picking_up_coins
	$< $(PROGRAM_ARGS)

.PHONY: picking_up_coins


# pivot_list.cc

$(BUILD_DIR)/pivot_list: $(SRC_DIR)/pivot_list.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
pivot_list: $(BUILD_DIR)/pivot_list
	$< $(PROGRAM_ARGS)

.PHONY: pivot_list


# power_set.cc

$(BUILD_DIR)/power_set: $(SRC_DIR)/power_set.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
power_set: $(BUILD_DIR)/power_set
	$< $(PROGRAM_ARGS)

.PHONY: power_set


# power_x_y.cc

$(BUILD_DIR)/power_x_y: $(SRC_DIR)/power_x_y.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
power_x_y: $(BUILD_DIR)/power_x_y
	$< $(PROGRAM_ARGS)

.PHONY: power_x_y


# pretty_printing.cc

$(BUILD_DIR)/pretty_printing: $(SRC_DIR)/pretty_printing.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
pretty_printing: $(BUILD_DIR)/pretty_printing
	$< $(PROGRAM_ARGS)

.PHONY: pretty_printing


# prime_sieve.cc

$(BUILD_DIR)/prime_sieve: $(SRC_DIR)/prime_sieve.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
prime_sieve: $(BUILD_DIR)/prime_sieve
	$< $(PROGRAM_ARGS)

.PHONY: prime_sieve


# primitive_divide.cc

$(BUILD_DIR)/primitive_divide: $(SRC_DIR)/primitive_divide.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
primitive_divide: $(BUILD_DIR)/primitive_divide
	$< $(PROGRAM_ARGS)

.PHONY: primitive_divide


# primitive_multiply.cc

$(BUILD_DIR)/primitive_multiply: $(SRC_DIR)/primitive_multiply.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
primitive_multiply: $(BUILD_DIR)/primitive_multiply
	$< $(PROGRAM_ARGS)

.PHONY: primitive_multiply


# queue_from_stacks.cc

$(BUILD_DIR)/queue_from_stacks: $(SRC_DIR)/queue_from_stacks.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
queue_from_stacks: $(BUILD_DIR)/queue_from_stacks
	$< $(PROGRAM_ARGS)

.PHONY: queue_from_stacks


# queue_with_max.cc

$(BUILD_DIR)/queue_with_max: $(SRC_DIR)/queue_with_max.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
queue_with_max: $(BUILD_DIR)/queue_with_max
	$< $(PROGRAM_ARGS)

.PHONY: queue_with_max


# random_permutation.cc

$(BUILD_DIR)/random_permutation: $(SRC_DIR)/random_permutation.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
random_permutation: $(BUILD_DIR)/random_permutation
	$< $(PROGRAM_ARGS)

.PHONY: random_permutation


# random_subset.cc

$(BUILD_DIR)/random_subset: $(SRC_DIR)/random_subset.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
random_subset: $(BUILD_DIR)/random_subset
	$< $(PROGRAM_ARGS)

.PHONY: random_subset


# range_lookup_in_bst.cc

$(BUILD_DIR)/range_lookup_in_bst: $(SRC_DIR)/range_lookup_in_bst.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
range_lookup_in_bst: $(BUILD_DIR)/range_lookup_in_bst
	$< $(PROGRAM_ARGS)

.PHONY: range_lookup_in_bst


# real_square_root.cc

$(BUILD_DIR)/real_square_root: $(SRC_DIR)/real_square_root.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
real_square_root: $(BUILD_DIR)/real_square_root
	$< $(PROGRAM_ARGS)

.PHONY: real_square_root


# rectangle_intersection.cc

$(BUILD_DIR)/rectangle_intersection: $(SRC_DIR)/rectangle_intersection.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
rectangle_intersection: $(BUILD_DIR)/rectangle_intersection
	$< $(PROGRAM_ARGS)

.PHONY: rectangle_intersection


# refueling_schedule.cc

$(BUILD_DIR)/refueling_schedule: $(SRC_DIR)/refueling_schedule.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
refueling_schedule: $(BUILD_DIR)/refueling_schedule
	$< $(PROGRAM_ARGS)

.PHONY: refueling_schedule


# regular_expression.cc

$(BUILD_DIR)/regular_expression: $(SRC_DIR)/regular_expression.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
regular_expression: $(BUILD_DIR)/regular_expression
	$< $(PROGRAM_ARGS)

.PHONY: regular_expression


# remove_duplicates.cc

$(BUILD_DIR)/remove_duplicates: $(SRC_DIR)/remove_duplicates.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
remove_duplicates: $(BUILD_DIR)/remove_duplicates
	$< $(PROGRAM_ARGS)

.PHONY: remove_duplicates


# remove_duplicates_from_sorted_list.cc

$(BUILD_DIR)/remove_duplicates_from_sorted_list: $(SRC_DIR)/remove_duplicates_from_sorted_list.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
remove_duplicates_from_sorted_list: $(BUILD_DIR)/remove_duplicates_from_sorted_list
	$< $(PROGRAM_ARGS)

.PHONY: remove_duplicates_from_sorted_list


# replace_and_remove.cc

$(BUILD_DIR)/replace_and_remove: $(SRC_DIR)/replace_and_remove.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
replace_and_remove: $(BUILD_DIR)/replace_and_remove
	$< $(PROGRAM_ARGS)

.PHONY: replace_and_remove


# reverse_bits.cc

$(BUILD_DIR)/reverse_bits: $(SRC_DIR)/reverse_bits.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
reverse_bits: $(BUILD_DIR)/reverse_bits
	$< $(PROGRAM_ARGS)

.PHONY: reverse_bits


# reverse_digits.cc

$(BUILD_DIR)/reverse_digits: $(SRC_DIR)/reverse_digits.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
reverse_digits: $(BUILD_DIR)/reverse_digits
	$< $(PROGRAM_ARGS)

.PHONY: reverse_digits


# reverse_sublist.cc

$(BUILD_DIR)/reverse_sublist: $(SRC_DIR)/reverse_sublist.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
reverse_sublist: $(BUILD_DIR)/reverse_sublist
	$< $(PROGRAM_ARGS)

.PHONY: reverse_sublist


# reverse_words.cc

$(BUILD_DIR)/reverse_words: $(SRC_DIR)/reverse_words.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
reverse_words: $(BUILD_DIR)/reverse_words
	$< $(PROGRAM_ARGS)

.PHONY: reverse_words


# road_network.cc

$(BUILD_DIR)/road_network: $(SRC_DIR)/road_network.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
road_network: $(BUILD_DIR)/road_network
	$< $(PROGRAM_ARGS)

.PHONY: road_network


# roman_to_integer.cc

$(BUILD_DIR)/roman_to_integer: $(SRC_DIR)/roman_to_integer.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
roman_to_integer: $(BUILD_DIR)/roman_to_integer
	$< $(PROGRAM_ARGS)

.PHONY: roman_to_integer


# rook_attack.cc

$(BUILD_DIR)/rook_attack: $(SRC_DIR)/rook_attack.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
rook_attack: $(BUILD_DIR)/rook_attack
	$< $(PROGRAM_ARGS)

.PHONY: rook_attack


# rotate_array.cc

$(BUILD_DIR)/rotate_array: $(SRC_DIR)/rotate_array.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
rotate_array: $(BUILD_DIR)/rotate_array
	$< $(PROGRAM_ARGS)

.PHONY: rotate_array


# run_length_compression.cc

$(BUILD_DIR)/run_length_compression: $(SRC_DIR)/run_length_compression.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
run_length_compression: $(BUILD_DIR)/run_length_compression
	$< $(PROGRAM_ARGS)

.PHONY: run_length_compression


# search_entry_equal_to_index.cc

$(BUILD_DIR)/search_entry_equal_to_index: $(SRC_DIR)/search_entry_equal_to_index.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
search_entry_equal_to_index: $(BUILD_DIR)/search_entry_equal_to_index
	$< $(PROGRAM_ARGS)

.PHONY: search_entry_equal_to_index


# search_first_greater_value_in_bst.cc

$(BUILD_DIR)/search_first_greater_value_in_bst: $(SRC_DIR)/search_first_greater_value_in_bst.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
search_first_greater_value_in_bst: $(BUILD_DIR)/search_first_greater_value_in_bst
	$< $(PROGRAM_ARGS)

.PHONY: search_first_greater_value_in_bst


# search_first_key.cc

$(BUILD_DIR)/search_first_key: $(SRC_DIR)/search_first_key.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
search_first_key: $(BUILD_DIR)/search_first_key
	$< $(PROGRAM_ARGS)

.PHONY: search_first_key


# search_for_min_max_in_array.cc

$(BUILD_DIR)/search_for_min_max_in_array: $(SRC_DIR)/search_for_min_max_in_array.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
search_for_min_max_in_array: $(BUILD_DIR)/search_for_min_max_in_array
	$< $(PROGRAM_ARGS)

.PHONY: search_for_min_max_in_array


# search_for_missing_element.cc

$(BUILD_DIR)/search_for_missing_element: $(SRC_DIR)/search_for_missing_element.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
search_for_missing_element: $(BUILD_DIR)/search_for_missing_element
	$< $(PROGRAM_ARGS)

.PHONY: search_for_missing_element


# search_frequent_items.cc

$(BUILD_DIR)/search_frequent_items: $(SRC_DIR)/search_frequent_items.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
search_frequent_items: $(BUILD_DIR)/search_frequent_items
	$< $(PROGRAM_ARGS)

.PHONY: search_frequent_items


# search_in_bst.cc

$(BUILD_DIR)/search_in_bst: $(SRC_DIR)/search_in_bst.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
search_in_bst: $(BUILD_DIR)/search_in_bst
	$< $(PROGRAM_ARGS)

.PHONY: search_in_bst


# search_in_list.cc

$(BUILD_DIR)/search_in_list: $(SRC_DIR)/search_in_list.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
search_in_list: $(BUILD_DIR)/search_in_list
	$< $(PROGRAM_ARGS)

.PHONY: search_in_list


# search_maze.cc

$(BUILD_DIR)/search_maze: $(SRC_DIR)/search_maze.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
search_maze: $(BUILD_DIR)/search_maze
	$< $(PROGRAM_ARGS)

.PHONY: search_maze


# search_row_col_sorted_matrix.cc

$(BUILD_DIR)/search_row_col_sorted_matrix: $(SRC_DIR)/search_row_col_sorted_matrix.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
search_row_col_sorted_matrix: $(BUILD_DIR)/search_row_col_sorted_matrix
	$< $(PROGRAM_ARGS)

.PHONY: search_row_col_sorted_matrix


# search_shifted_sorted_array.cc

$(BUILD_DIR)/search_shifted_sorted_array: $(SRC_DIR)/search_shifted_sorted_array.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
search_shifted_sorted_array: $(BUILD_DIR)/search_shifted_sorted_array
	$< $(PROGRAM_ARGS)

.PHONY: search_shifted_sorted_array


# search_unknown_length_array.cc

$(BUILD_DIR)/search_unknown_length_array: $(SRC_DIR)/search_unknown_length_array.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
search_unknown_length_array: $(BUILD_DIR)/search_unknown_length_array
	$< $(PROGRAM_ARGS)

.PHONY: search_unknown_length_array


# smallest_nonconstructible_value.cc

$(BUILD_DIR)/smallest_nonconstructible_value: $(SRC_DIR)/smallest_nonconstructible_value.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
smallest_nonconstructible_value: $(BUILD_DIR)/smallest_nonconstructible_value
	$< $(PROGRAM_ARGS)

.PHONY: smallest_nonconstructible_value


# smallest_subarray_covering_all_values.cc

$(BUILD_DIR)/smallest_subarray_covering_all_values: $(SRC_DIR)/smallest_subarray_covering_all_values.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
smallest_subarray_covering_all_values: $(BUILD_DIR)/smallest_subarray_covering_all_values
	$< $(PROGRAM_ARGS)

.PHONY: smallest_subarray_covering_all_values


# smallest_subarray_covering_set.cc

$(BUILD_DIR)/smallest_subarray_covering_set: $(SRC_DIR)/smallest_subarray_covering_set.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
smallest_subarray_covering_set: $(BUILD_DIR)/smallest_subarray_covering_set
	$< $(PROGRAM_ARGS)

.PHONY: smallest_subarray_covering_set


# snake_string.cc

$(BUILD_DIR)/snake_string: $(SRC_DIR)/snake_string.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
snake_string: $(BUILD_DIR)/snake_string
	$< $(PROGRAM_ARGS)

.PHONY: snake_string


# sort_almost_sorted_array.cc

$(BUILD_DIR)/sort_almost_sorted_array: $(SRC_DIR)/sort_almost_sorted_array.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
sort_almost_sorted_array: $(BUILD_DIR)/sort_almost_sorted_array
	$< $(PROGRAM_ARGS)

.PHONY: sort_almost_sorted_array


# sort_increasing_decreasing_array.cc

$(BUILD_DIR)/sort_increasing_decreasing_array: $(SRC_DIR)/sort_increasing_decreasing_array.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
sort_increasing_decreasing_array: $(BUILD_DIR)/sort_increasing_decreasing_array
	$< $(PROGRAM_ARGS)

.PHONY: sort_increasing_decreasing_array


# sort_list.cc

$(BUILD_DIR)/sort_list: $(SRC_DIR)/sort_list.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
sort_list: $(BUILD_DIR)/sort_list
	$< $(PROGRAM_ARGS)

.PHONY: sort_list


# sorted_array_remove_dups.cc

$(BUILD_DIR)/sorted_array_remove_dups: $(SRC_DIR)/sorted_array_remove_dups.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
sorted_array_remove_dups: $(BUILD_DIR)/sorted_array_remove_dups
	$< $(PROGRAM_ARGS)

.PHONY: sorted_array_remove_dups


# sorted_arrays_merge.cc

$(BUILD_DIR)/sorted_arrays_merge: $(SRC_DIR)/sorted_arrays_merge.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
sorted_arrays_merge: $(BUILD_DIR)/sorted_arrays_merge
	$< $(PROGRAM_ARGS)

.PHONY: sorted_arrays_merge


# sorted_list_to_bst.cc

$(BUILD_DIR)/sorted_list_to_bst: $(SRC_DIR)/sorted_list_to_bst.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
sorted_list_to_bst: $(BUILD_DIR)/sorted_list_to_bst
	$< $(PROGRAM_ARGS)

.PHONY: sorted_list_to_bst


# sorted_lists_merge.cc

$(BUILD_DIR)/sorted_lists_merge: $(SRC_DIR)/sorted_lists_merge.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
sorted_lists_merge: $(BUILD_DIR)/sorted_lists_merge
	$< $(PROGRAM_ARGS)

.PHONY: sorted_lists_merge


# spiral_ordering.cc

$(BUILD_DIR)/spiral_ordering: $(SRC_DIR)/spiral_ordering.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
spiral_ordering: $(BUILD_DIR)/spiral_ordering
	$< $(PROGRAM_ARGS)

.PHONY: spiral_ordering


# spreadsheet_encoding.cc

$(BUILD_DIR)/spreadsheet_encoding: $(SRC_DIR)/spreadsheet_encoding.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
spreadsheet_encoding: $(BUILD_DIR)/spreadsheet_encoding
	$< $(PROGRAM_ARGS)

.PHONY: spreadsheet_encoding


# stack_with_max.cc

$(BUILD_DIR)/stack_with_max: $(SRC_DIR)/stack_with_max.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
stack_with_max: $(BUILD_DIR)/stack_with_max
	$< $(PROGRAM_ARGS)

.PHONY: stack_with_max


# string_decompositions_into_dictionary_words.cc

$(BUILD_DIR)/string_decompositions_into_dictionary_words: $(SRC_DIR)/string_decompositions_into_dictionary_words.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
string_decompositions_into_dictionary_words: $(BUILD_DIR)/string_decompositions_into_dictionary_words
	$< $(PROGRAM_ARGS)

.PHONY: string_decompositions_into_dictionary_words


# string_integer_interconversion.cc

$(BUILD_DIR)/string_integer_interconversion: $(SRC_DIR)/string_integer_interconversion.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
string_integer_interconversion: $(BUILD_DIR)/string_integer_interconversion
	$< $(PROGRAM_ARGS)

.PHONY: string_integer_interconversion


# string_transformability.cc

$(BUILD_DIR)/string_transformability: $(SRC_DIR)/string_transformability.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
string_transformability: $(BUILD_DIR)/string_transformability
	$< $(PROGRAM_ARGS)

.PHONY: string_transformability


# substring_match.cc

$(BUILD_DIR)/substring_match: $(SRC_DIR)/substring_match.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
substring_match: $(BUILD_DIR)/substring_match
	$< $(PROGRAM_ARGS)

.PHONY: substring_match


# successor_in_tree.cc

$(BUILD_DIR)/successor_in_tree: $(SRC_DIR)/successor_in_tree.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
successor_in_tree: $(BUILD_DIR)/successor_in_tree
	$< $(PROGRAM_ARGS)

.PHONY: successor_in_tree


# sudoku_solve.cc

$(BUILD_DIR)/sudoku_solve: $(SRC_DIR)/sudoku_solve.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
sudoku_solve: $(BUILD_DIR)/sudoku_solve
	$< $(PROGRAM_ARGS)

.PHONY: sudoku_solve


# sum_root_to_leaf.cc

$(BUILD_DIR)/sum_root_to_leaf: $(SRC_DIR)/sum_root_to_leaf.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
sum_root_to_leaf: $(BUILD_DIR)/sum_root_to_leaf
	$< $(PROGRAM_ARGS)

.PHONY: sum_root_to_leaf


# sunset_view.cc

$(BUILD_DIR)/sunset_view: $(SRC_DIR)/sunset_view.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
sunset_view: $(BUILD_DIR)/sunset_view
	$< $(PROGRAM_ARGS)

.PHONY: sunset_view


# swap_bits.cc

$(BUILD_DIR)/swap_bits: $(SRC_DIR)/swap_bits.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
swap_bits: $(BUILD_DIR)/swap_bits
	$< $(PROGRAM_ARGS)

.PHONY: swap_bits


# task_pairing.cc

$(BUILD_DIR)/task_pairing: $(SRC_DIR)/task_pairing.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
task_pairing: $(BUILD_DIR)/task_pairing
	$< $(PROGRAM_ARGS)

.PHONY: task_pairing


# three_sum.cc

$(BUILD_DIR)/three_sum: $(SRC_DIR)/three_sum.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
three_sum: $(BUILD_DIR)/three_sum
	$< $(PROGRAM_ARGS)

.PHONY: three_sum


# tree_connect_leaves.cc

$(BUILD_DIR)/tree_connect_leaves: $(SRC_DIR)/tree_connect_leaves.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
tree_connect_leaves: $(BUILD_DIR)/tree_connect_leaves
	$< $(PROGRAM_ARGS)

.PHONY: tree_connect_leaves


# tree_exterior.cc

$(BUILD_DIR)/tree_exterior: $(SRC_DIR)/tree_exterior.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
tree_exterior: $(BUILD_DIR)/tree_exterior
	$< $(PROGRAM_ARGS)

.PHONY: tree_exterior


# tree_from_preorder_inorder.cc

$(BUILD_DIR)/tree_from_preorder_inorder: $(SRC_DIR)/tree_from_preorder_inorder.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
tree_from_preorder_inorder: $(BUILD_DIR)/tree_from_preorder_inorder
	$< $(PROGRAM_ARGS)

.PHONY: tree_from_preorder_inorder


# tree_from_preorder_with_null.cc

$(BUILD_DIR)/tree_from_preorder_with_null: $(SRC_DIR)/tree_from_preorder_with_null.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
tree_from_preorder_with_null: $(BUILD_DIR)/tree_from_preorder_with_null
	$< $(PROGRAM_ARGS)

.PHONY: tree_from_preorder_with_null


# tree_inorder.cc

$(BUILD_DIR)/tree_inorder: $(SRC_DIR)/tree_inorder.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
tree_inorder: $(BUILD_DIR)/tree_inorder
	$< $(PROGRAM_ARGS)

.PHONY: tree_inorder


# tree_level_order.cc

$(BUILD_DIR)/tree_level_order: $(SRC_DIR)/tree_level_order.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
tree_level_order: $(BUILD_DIR)/tree_level_order
	$< $(PROGRAM_ARGS)

.PHONY: tree_level_order


# tree_postorder.cc

$(BUILD_DIR)/tree_postorder: $(SRC_DIR)/tree_postorder.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
tree_postorder: $(BUILD_DIR)/tree_postorder
	$< $(PROGRAM_ARGS)

.PHONY: tree_postorder


# tree_preorder.cc

$(BUILD_DIR)/tree_preorder: $(SRC_DIR)/tree_preorder.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
tree_preorder: $(BUILD_DIR)/tree_preorder
	$< $(PROGRAM_ARGS)

.PHONY: tree_preorder


# tree_right_sibling.cc

$(BUILD_DIR)/tree_right_sibling: $(SRC_DIR)/tree_right_sibling.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
tree_right_sibling: $(BUILD_DIR)/tree_right_sibling
	$< $(PROGRAM_ARGS)

.PHONY: tree_right_sibling


# tree_with_parent_inorder.cc

$(BUILD_DIR)/tree_with_parent_inorder: $(SRC_DIR)/tree_with_parent_inorder.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
tree_with_parent_inorder: $(BUILD_DIR)/tree_with_parent_inorder
	$< $(PROGRAM_ARGS)

.PHONY: tree_with_parent_inorder


# two_sorted_arrays_merge.cc

$(BUILD_DIR)/two_sorted_arrays_merge: $(SRC_DIR)/two_sorted_arrays_merge.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
two_sorted_arrays_merge: $(BUILD_DIR)/two_sorted_arrays_merge
	$< $(PROGRAM_ARGS)

.PHONY: two_sorted_arrays_merge


# two_sum.cc

$(BUILD_DIR)/two_sum: $(SRC_DIR)/two_sum.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
two_sum: $(BUILD_DIR)/two_sum
	$< $(PROGRAM_ARGS)

.PHONY: two_sum


# uniform_random_number.cc

$(BUILD_DIR)/uniform_random_number: $(SRC_DIR)/uniform_random_number.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
uniform_random_number: $(BUILD_DIR)/uniform_random_number
	$< $(PROGRAM_ARGS)

.PHONY: uniform_random_number


# valid_ip_addresses.cc

$(BUILD_DIR)/valid_ip_addresses: $(SRC_DIR)/valid_ip_addresses.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
valid_ip_addresses: $(BUILD_DIR)/valid_ip_addresses
	$< $(PROGRAM_ARGS)

.PHONY: valid_ip_addresses


# zip_list.cc

$(BUILD_DIR)/zip_list: $(SRC_DIR)/zip_list.cc | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
zip_list: $(BUILD_DIR)/zip_list
	$< $(PROGRAM_ARGS)

.PHONY: zip_list

all: \
    $(BUILD_DIR)/a_b_sqrt2 \
    $(BUILD_DIR)/absent_value_array \
    $(BUILD_DIR)/adding_credits \
    $(BUILD_DIR)/advance_by_offsets \
    $(BUILD_DIR)/alternating_array \
    $(BUILD_DIR)/anagrams \
    $(BUILD_DIR)/apply_permutation \
    $(BUILD_DIR)/arbitrage \
    $(BUILD_DIR)/binomial_coefficients \
    $(BUILD_DIR)/bonus \
    $(BUILD_DIR)/bst_from_preorder \
    $(BUILD_DIR)/bst_from_sorted_array \
    $(BUILD_DIR)/bst_merge \
    $(BUILD_DIR)/bst_to_sorted_list \
    $(BUILD_DIR)/buy_and_sell_stock \
    $(BUILD_DIR)/buy_and_sell_stock_k_times \
    $(BUILD_DIR)/buy_and_sell_stock_twice \
    $(BUILD_DIR)/calendar_rendering \
    $(BUILD_DIR)/circular_queue \
    $(BUILD_DIR)/closest_int_same_weight \
    $(BUILD_DIR)/collatz_checker \
    $(BUILD_DIR)/combinations \
    $(BUILD_DIR)/convert_base \
    $(BUILD_DIR)/copy_posting_list \
    $(BUILD_DIR)/count_bits \
    $(BUILD_DIR)/count_inversions \
    $(BUILD_DIR)/deadlock_detection \
    $(BUILD_DIR)/defective_jugs \
    $(BUILD_DIR)/delete_from_list \
    $(BUILD_DIR)/delete_kth_last_from_list \
    $(BUILD_DIR)/delete_node_from_list \
    $(BUILD_DIR)/descendant_and_ancestor_in_bst \
    $(BUILD_DIR)/directory_path_normalization \
    $(BUILD_DIR)/do_lists_overlap \
    $(BUILD_DIR)/do_terminated_lists_overlap \
    $(BUILD_DIR)/drawing_skyline \
    $(BUILD_DIR)/dutch_national_flag \
    $(BUILD_DIR)/element_appearing_once \
    $(BUILD_DIR)/enumerate_balanced_parentheses \
    $(BUILD_DIR)/enumerate_palindromic_decompositions \
    $(BUILD_DIR)/enumerate_trees \
    $(BUILD_DIR)/euclidean_gcd \
    $(BUILD_DIR)/evaluate_rpn \
    $(BUILD_DIR)/even_odd_array \
    $(BUILD_DIR)/even_odd_list_merge \
    $(BUILD_DIR)/fibonacci \
    $(BUILD_DIR)/find_salary_threshold \
    $(BUILD_DIR)/first_missing_positive_entry \
    $(BUILD_DIR)/gcd \
    $(BUILD_DIR)/graph_clone \
    $(BUILD_DIR)/gray_code \
    $(BUILD_DIR)/group_equal_entries \
    $(BUILD_DIR)/h_index \
    $(BUILD_DIR)/hanoi \
    $(BUILD_DIR)/huffman_coding \
    $(BUILD_DIR)/insert_in_list \
    $(BUILD_DIR)/insert_operators_in_string \
    $(BUILD_DIR)/int_as_array_increment \
    $(BUILD_DIR)/int_as_array_multiply \
    $(BUILD_DIR)/int_as_list_add \
    $(BUILD_DIR)/int_square_root \
    $(BUILD_DIR)/intersect_sorted_arrays \
    $(BUILD_DIR)/interval_add \
    $(BUILD_DIR)/intervals_union \
    $(BUILD_DIR)/is_anonymous_letter_constructible \
    $(BUILD_DIR)/is_array_dominated \
    $(BUILD_DIR)/is_circuit_wirable \
    $(BUILD_DIR)/is_list_cyclic \
    $(BUILD_DIR)/is_list_palindromic \
    $(BUILD_DIR)/is_number_palindromic \
    $(BUILD_DIR)/is_string_decomposable_into_words \
    $(BUILD_DIR)/is_string_in_matrix \
    $(BUILD_DIR)/is_string_palindromic \
    $(BUILD_DIR)/is_string_palindromic_punctuation \
    $(BUILD_DIR)/is_string_permutable_to_palindrome \
    $(BUILD_DIR)/is_tree_a_bst \
    $(BUILD_DIR)/is_tree_balanced \
    $(BUILD_DIR)/is_tree_symmetric \
    $(BUILD_DIR)/is_valid_parenthesization \
    $(BUILD_DIR)/is_valid_sudoku \
    $(BUILD_DIR)/k_closest_stars \
    $(BUILD_DIR)/k_largest_in_heap \
    $(BUILD_DIR)/k_largest_values_in_bst \
    $(BUILD_DIR)/knapsack \
    $(BUILD_DIR)/kth_largest_element_in_long_array \
    $(BUILD_DIR)/kth_largest_element_in_two_sorted_arrays \
    $(BUILD_DIR)/kth_largest_in_array \
    $(BUILD_DIR)/kth_node_in_tree \
    $(BUILD_DIR)/largest_rectangle_under_skyline \
    $(BUILD_DIR)/left_right_justify_text \
    $(BUILD_DIR)/levenshtein_distance \
    $(BUILD_DIR)/line_through_most_points \
    $(BUILD_DIR)/list_cyclic_right_shift \
    $(BUILD_DIR)/longest_contained_interval \
    $(BUILD_DIR)/longest_increasing_subarray \
    $(BUILD_DIR)/longest_nondecreasing_subsequence \
    $(BUILD_DIR)/longest_subarray_with_distinct_values \
    $(BUILD_DIR)/longest_subarray_with_sum_constraint \
    $(BUILD_DIR)/longest_substring_with_matching_parentheses \
    $(BUILD_DIR)/look_and_say \
    $(BUILD_DIR)/lowest_common_ancestor \
    $(BUILD_DIR)/lowest_common_ancestor_close_ancestor \
    $(BUILD_DIR)/lowest_common_ancestor_in_bst \
    $(BUILD_DIR)/lowest_common_ancestor_with_parent \
    $(BUILD_DIR)/lru_cache \
    $(BUILD_DIR)/majority_element \
    $(BUILD_DIR)/making_change \
    $(BUILD_DIR)/matrix_connected_regions \
    $(BUILD_DIR)/matrix_enclosed_regions \
    $(BUILD_DIR)/matrix_rotation \
    $(BUILD_DIR)/max_of_sliding_window \
    $(BUILD_DIR)/max_product_all_but_one \
    $(BUILD_DIR)/max_safe_height \
    $(BUILD_DIR)/max_square_submatrix \
    $(BUILD_DIR)/max_submatrix \
    $(BUILD_DIR)/max_sum_subarray \
    $(BUILD_DIR)/max_teams_in_photograph \
    $(BUILD_DIR)/max_trapped_water \
    $(BUILD_DIR)/max_water_trappable \
    $(BUILD_DIR)/maximum_subarray_in_circular_array \
    $(BUILD_DIR)/minimum_distance_3_sorted_arrays \
    $(BUILD_DIR)/minimum_points_covering_intervals \
    $(BUILD_DIR)/minimum_waiting_time \
    $(BUILD_DIR)/minimum_weight_path_in_a_triangle \
    $(BUILD_DIR)/n_queens \
    $(BUILD_DIR)/nearest_repeated_entries \
    $(BUILD_DIR)/next_permutation \
    $(BUILD_DIR)/nonuniform_random_number \
    $(BUILD_DIR)/number_of_score_combinations \
    $(BUILD_DIR)/number_of_traversals_matrix \
    $(BUILD_DIR)/number_of_traversals_staircase \
    $(BUILD_DIR)/offline_sampling \
    $(BUILD_DIR)/online_median \
    $(BUILD_DIR)/online_sampling \
    $(BUILD_DIR)/parity \
    $(BUILD_DIR)/pascal_triangle \
    $(BUILD_DIR)/path_sum \
    $(BUILD_DIR)/permutations \
    $(BUILD_DIR)/phone_number_mnemonic \
    $(BUILD_DIR)/picking_up_coins \
    $(BUILD_DIR)/pivot_list \
    $(BUILD_DIR)/power_set \
    $(BUILD_DIR)/power_x_y \
    $(BUILD_DIR)/pretty_printing \
    $(BUILD_DIR)/prime_sieve \
    $(BUILD_DIR)/primitive_divide \
    $(BUILD_DIR)/primitive_multiply \
    $(BUILD_DIR)/queue_from_stacks \
    $(BUILD_DIR)/queue_with_max \
    $(BUILD_DIR)/random_permutation \
    $(BUILD_DIR)/random_subset \
    $(BUILD_DIR)/range_lookup_in_bst \
    $(BUILD_DIR)/real_square_root \
    $(BUILD_DIR)/rectangle_intersection \
    $(BUILD_DIR)/refueling_schedule \
    $(BUILD_DIR)/regular_expression \
    $(BUILD_DIR)/remove_duplicates \
    $(BUILD_DIR)/remove_duplicates_from_sorted_list \
    $(BUILD_DIR)/replace_and_remove \
    $(BUILD_DIR)/reverse_bits \
    $(BUILD_DIR)/reverse_digits \
    $(BUILD_DIR)/reverse_sublist \
    $(BUILD_DIR)/reverse_words \
    $(BUILD_DIR)/road_network \
    $(BUILD_DIR)/roman_to_integer \
    $(BUILD_DIR)/rook_attack \
    $(BUILD_DIR)/rotate_array \
    $(BUILD_DIR)/run_length_compression \
    $(BUILD_DIR)/search_entry_equal_to_index \
    $(BUILD_DIR)/search_first_greater_value_in_bst \
    $(BUILD_DIR)/search_first_key \
    $(BUILD_DIR)/search_for_min_max_in_array \
    $(BUILD_DIR)/search_for_missing_element \
    $(BUILD_DIR)/search_frequent_items \
    $(BUILD_DIR)/search_in_bst \
    $(BUILD_DIR)/search_in_list \
    $(BUILD_DIR)/search_maze \
    $(BUILD_DIR)/search_row_col_sorted_matrix \
    $(BUILD_DIR)/search_shifted_sorted_array \
    $(BUILD_DIR)/search_unknown_length_array \
    $(BUILD_DIR)/smallest_nonconstructible_value \
    $(BUILD_DIR)/smallest_subarray_covering_all_values \
    $(BUILD_DIR)/smallest_subarray_covering_set \
    $(BUILD_DIR)/snake_string \
    $(BUILD_DIR)/sort_almost_sorted_array \
    $(BUILD_DIR)/sort_increasing_decreasing_array \
    $(BUILD_DIR)/sort_list \
    $(BUILD_DIR)/sorted_array_remove_dups \
    $(BUILD_DIR)/sorted_arrays_merge \
    $(BUILD_DIR)/sorted_list_to_bst \
    $(BUILD_DIR)/sorted_lists_merge \
    $(BUILD_DIR)/spiral_ordering \
    $(BUILD_DIR)/spreadsheet_encoding \
    $(BUILD_DIR)/stack_with_max \
    $(BUILD_DIR)/string_decompositions_into_dictionary_words \
    $(BUILD_DIR)/string_integer_interconversion \
    $(BUILD_DIR)/string_transformability \
    $(BUILD_DIR)/substring_match \
    $(BUILD_DIR)/successor_in_tree \
    $(BUILD_DIR)/sudoku_solve \
    $(BUILD_DIR)/sum_root_to_leaf \
    $(BUILD_DIR)/sunset_view \
    $(BUILD_DIR)/swap_bits \
    $(BUILD_DIR)/task_pairing \
    $(BUILD_DIR)/three_sum \
    $(BUILD_DIR)/tree_connect_leaves \
    $(BUILD_DIR)/tree_exterior \
    $(BUILD_DIR)/tree_from_preorder_inorder \
    $(BUILD_DIR)/tree_from_preorder_with_null \
    $(BUILD_DIR)/tree_inorder \
    $(BUILD_DIR)/tree_level_order \
    $(BUILD_DIR)/tree_postorder \
    $(BUILD_DIR)/tree_preorder \
    $(BUILD_DIR)/tree_right_sibling \
    $(BUILD_DIR)/tree_with_parent_inorder \
    $(BUILD_DIR)/two_sorted_arrays_merge \
    $(BUILD_DIR)/two_sum \
    $(BUILD_DIR)/uniform_random_number \
    $(BUILD_DIR)/valid_ip_addresses \
    $(BUILD_DIR)/zip_list

clean:
	rm -r $(BUILD_DIR)

.PHONY: all clean
