#Run "make <program_name>" for release build and "make <program_name>_dbg" for debug build
BUILD_DIR := cpp_build
SRC_DIR := .
TEST_DATA_DIR := ../test_data

CXX_COMPILER := g++
CXX_FLAGS := -std=c++14 -pthread -Werror
CXX_FLAGS_DEBUG := $(CXX_FLAGS) -g -O0
CXX_FLAGS_RELEASE := $(CXX_FLAGS) -O3

LAST_MODIFIED_CXX_FILE = $(shell ls -rt $(SRC_DIR)/*\.cc | tail -1)


last: $(notdir $(basename $(LAST_MODIFIED_CXX_FILE)))
last_dbg: $(notdir $(basename $(LAST_MODIFIED_CXX_FILE)))_dbg
clean:
	rm -r $(BUILD_DIR)
all:
	$(error ALL target is not implemented yet)
.PHONY: last last_dbg clean	all

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)


# absent_value_array.cc

$(BUILD_DIR)/absent_value_array: $(SRC_DIR)/absent_value_array.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
absent_value_array: $(BUILD_DIR)/absent_value_array
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/absent_value_array_dbg: $(SRC_DIR)/absent_value_array.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
absent_value_array_dbg: $(BUILD_DIR)/absent_value_array_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: absent_value_array absent_value_array_dbg


# adding_credits.cc

$(BUILD_DIR)/adding_credits: $(SRC_DIR)/adding_credits.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
adding_credits: $(BUILD_DIR)/adding_credits
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/adding_credits_dbg: $(SRC_DIR)/adding_credits.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
adding_credits_dbg: $(BUILD_DIR)/adding_credits_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: adding_credits adding_credits_dbg


# advance_by_offsets.cc

$(BUILD_DIR)/advance_by_offsets: $(SRC_DIR)/advance_by_offsets.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
advance_by_offsets: $(BUILD_DIR)/advance_by_offsets
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/advance_by_offsets_dbg: $(SRC_DIR)/advance_by_offsets.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
advance_by_offsets_dbg: $(BUILD_DIR)/advance_by_offsets_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: advance_by_offsets advance_by_offsets_dbg


# alternating_array.cc

$(BUILD_DIR)/alternating_array: $(SRC_DIR)/alternating_array.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
alternating_array: $(BUILD_DIR)/alternating_array
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/alternating_array_dbg: $(SRC_DIR)/alternating_array.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
alternating_array_dbg: $(BUILD_DIR)/alternating_array_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: alternating_array alternating_array_dbg


# anagrams.cc

$(BUILD_DIR)/anagrams: $(SRC_DIR)/anagrams.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
anagrams: $(BUILD_DIR)/anagrams
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/anagrams_dbg: $(SRC_DIR)/anagrams.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
anagrams_dbg: $(BUILD_DIR)/anagrams_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: anagrams anagrams_dbg


# apply_permutation.cc

$(BUILD_DIR)/apply_permutation: $(SRC_DIR)/apply_permutation.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
apply_permutation: $(BUILD_DIR)/apply_permutation
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/apply_permutation_dbg: $(SRC_DIR)/apply_permutation.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
apply_permutation_dbg: $(BUILD_DIR)/apply_permutation_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: apply_permutation apply_permutation_dbg


# arbitrage.cc

$(BUILD_DIR)/arbitrage: $(SRC_DIR)/arbitrage.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
arbitrage: $(BUILD_DIR)/arbitrage
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/arbitrage_dbg: $(SRC_DIR)/arbitrage.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
arbitrage_dbg: $(BUILD_DIR)/arbitrage_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: arbitrage arbitrage_dbg


# binomial_coefficients.cc

$(BUILD_DIR)/binomial_coefficients: $(SRC_DIR)/binomial_coefficients.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
binomial_coefficients: $(BUILD_DIR)/binomial_coefficients
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/binomial_coefficients_dbg: $(SRC_DIR)/binomial_coefficients.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
binomial_coefficients_dbg: $(BUILD_DIR)/binomial_coefficients_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: binomial_coefficients binomial_coefficients_dbg


# bonus.cc

$(BUILD_DIR)/bonus: $(SRC_DIR)/bonus.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
bonus: $(BUILD_DIR)/bonus
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/bonus_dbg: $(SRC_DIR)/bonus.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
bonus_dbg: $(BUILD_DIR)/bonus_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: bonus bonus_dbg


# bst_from_preorder.cc

$(BUILD_DIR)/bst_from_preorder: $(SRC_DIR)/bst_from_preorder.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
bst_from_preorder: $(BUILD_DIR)/bst_from_preorder
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/bst_from_preorder_dbg: $(SRC_DIR)/bst_from_preorder.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
bst_from_preorder_dbg: $(BUILD_DIR)/bst_from_preorder_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: bst_from_preorder bst_from_preorder_dbg


# bst_from_sorted_array.cc

$(BUILD_DIR)/bst_from_sorted_array: $(SRC_DIR)/bst_from_sorted_array.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
bst_from_sorted_array: $(BUILD_DIR)/bst_from_sorted_array
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/bst_from_sorted_array_dbg: $(SRC_DIR)/bst_from_sorted_array.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
bst_from_sorted_array_dbg: $(BUILD_DIR)/bst_from_sorted_array_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: bst_from_sorted_array bst_from_sorted_array_dbg


# bst_merge.cc

$(BUILD_DIR)/bst_merge: $(SRC_DIR)/bst_merge.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
bst_merge: $(BUILD_DIR)/bst_merge
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/bst_merge_dbg: $(SRC_DIR)/bst_merge.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
bst_merge_dbg: $(BUILD_DIR)/bst_merge_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: bst_merge bst_merge_dbg


# bst_to_sorted_list.cc

$(BUILD_DIR)/bst_to_sorted_list: $(SRC_DIR)/bst_to_sorted_list.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
bst_to_sorted_list: $(BUILD_DIR)/bst_to_sorted_list
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/bst_to_sorted_list_dbg: $(SRC_DIR)/bst_to_sorted_list.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
bst_to_sorted_list_dbg: $(BUILD_DIR)/bst_to_sorted_list_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: bst_to_sorted_list bst_to_sorted_list_dbg


# buy_and_sell_stock.cc

$(BUILD_DIR)/buy_and_sell_stock: $(SRC_DIR)/buy_and_sell_stock.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
buy_and_sell_stock: $(BUILD_DIR)/buy_and_sell_stock
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/buy_and_sell_stock_dbg: $(SRC_DIR)/buy_and_sell_stock.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
buy_and_sell_stock_dbg: $(BUILD_DIR)/buy_and_sell_stock_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: buy_and_sell_stock buy_and_sell_stock_dbg


# buy_and_sell_stock_k_times.cc

$(BUILD_DIR)/buy_and_sell_stock_k_times: $(SRC_DIR)/buy_and_sell_stock_k_times.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
buy_and_sell_stock_k_times: $(BUILD_DIR)/buy_and_sell_stock_k_times
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/buy_and_sell_stock_k_times_dbg: $(SRC_DIR)/buy_and_sell_stock_k_times.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
buy_and_sell_stock_k_times_dbg: $(BUILD_DIR)/buy_and_sell_stock_k_times_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: buy_and_sell_stock_k_times buy_and_sell_stock_k_times_dbg


# buy_and_sell_stock_twice.cc

$(BUILD_DIR)/buy_and_sell_stock_twice: $(SRC_DIR)/buy_and_sell_stock_twice.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
buy_and_sell_stock_twice: $(BUILD_DIR)/buy_and_sell_stock_twice
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/buy_and_sell_stock_twice_dbg: $(SRC_DIR)/buy_and_sell_stock_twice.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
buy_and_sell_stock_twice_dbg: $(BUILD_DIR)/buy_and_sell_stock_twice_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: buy_and_sell_stock_twice buy_and_sell_stock_twice_dbg


# calendar_rendering.cc

$(BUILD_DIR)/calendar_rendering: $(SRC_DIR)/calendar_rendering.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
calendar_rendering: $(BUILD_DIR)/calendar_rendering
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/calendar_rendering_dbg: $(SRC_DIR)/calendar_rendering.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
calendar_rendering_dbg: $(BUILD_DIR)/calendar_rendering_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: calendar_rendering calendar_rendering_dbg


# circular_queue.cc

$(BUILD_DIR)/circular_queue: $(SRC_DIR)/circular_queue.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
circular_queue: $(BUILD_DIR)/circular_queue
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/circular_queue_dbg: $(SRC_DIR)/circular_queue.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
circular_queue_dbg: $(BUILD_DIR)/circular_queue_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: circular_queue circular_queue_dbg


# closest_int_same_weight.cc

$(BUILD_DIR)/closest_int_same_weight: $(SRC_DIR)/closest_int_same_weight.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
closest_int_same_weight: $(BUILD_DIR)/closest_int_same_weight
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/closest_int_same_weight_dbg: $(SRC_DIR)/closest_int_same_weight.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
closest_int_same_weight_dbg: $(BUILD_DIR)/closest_int_same_weight_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: closest_int_same_weight closest_int_same_weight_dbg


# collatz_checker.cc

$(BUILD_DIR)/collatz_checker: $(SRC_DIR)/collatz_checker.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
collatz_checker: $(BUILD_DIR)/collatz_checker
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/collatz_checker_dbg: $(SRC_DIR)/collatz_checker.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
collatz_checker_dbg: $(BUILD_DIR)/collatz_checker_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: collatz_checker collatz_checker_dbg


# combinations.cc

$(BUILD_DIR)/combinations: $(SRC_DIR)/combinations.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
combinations: $(BUILD_DIR)/combinations
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/combinations_dbg: $(SRC_DIR)/combinations.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
combinations_dbg: $(BUILD_DIR)/combinations_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: combinations combinations_dbg


# convert_base.cc

$(BUILD_DIR)/convert_base: $(SRC_DIR)/convert_base.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
convert_base: $(BUILD_DIR)/convert_base
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/convert_base_dbg: $(SRC_DIR)/convert_base.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
convert_base_dbg: $(BUILD_DIR)/convert_base_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: convert_base convert_base_dbg


# copy_posting_list.cc

$(BUILD_DIR)/copy_posting_list: $(SRC_DIR)/copy_posting_list.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
copy_posting_list: $(BUILD_DIR)/copy_posting_list
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/copy_posting_list_dbg: $(SRC_DIR)/copy_posting_list.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
copy_posting_list_dbg: $(BUILD_DIR)/copy_posting_list_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: copy_posting_list copy_posting_list_dbg


# count_bits.cc

$(BUILD_DIR)/count_bits: $(SRC_DIR)/count_bits.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
count_bits: $(BUILD_DIR)/count_bits
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/count_bits_dbg: $(SRC_DIR)/count_bits.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
count_bits_dbg: $(BUILD_DIR)/count_bits_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: count_bits count_bits_dbg


# count_inversions.cc

$(BUILD_DIR)/count_inversions: $(SRC_DIR)/count_inversions.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
count_inversions: $(BUILD_DIR)/count_inversions
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/count_inversions_dbg: $(SRC_DIR)/count_inversions.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
count_inversions_dbg: $(BUILD_DIR)/count_inversions_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: count_inversions count_inversions_dbg


# deadlock_detection.cc

$(BUILD_DIR)/deadlock_detection: $(SRC_DIR)/deadlock_detection.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
deadlock_detection: $(BUILD_DIR)/deadlock_detection
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/deadlock_detection_dbg: $(SRC_DIR)/deadlock_detection.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
deadlock_detection_dbg: $(BUILD_DIR)/deadlock_detection_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: deadlock_detection deadlock_detection_dbg


# defective_jugs.cc

$(BUILD_DIR)/defective_jugs: $(SRC_DIR)/defective_jugs.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
defective_jugs: $(BUILD_DIR)/defective_jugs
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/defective_jugs_dbg: $(SRC_DIR)/defective_jugs.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
defective_jugs_dbg: $(BUILD_DIR)/defective_jugs_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: defective_jugs defective_jugs_dbg


# delete_from_list.cc

$(BUILD_DIR)/delete_from_list: $(SRC_DIR)/delete_from_list.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
delete_from_list: $(BUILD_DIR)/delete_from_list
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/delete_from_list_dbg: $(SRC_DIR)/delete_from_list.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
delete_from_list_dbg: $(BUILD_DIR)/delete_from_list_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: delete_from_list delete_from_list_dbg


# delete_kth_last_from_list.cc

$(BUILD_DIR)/delete_kth_last_from_list: $(SRC_DIR)/delete_kth_last_from_list.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
delete_kth_last_from_list: $(BUILD_DIR)/delete_kth_last_from_list
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/delete_kth_last_from_list_dbg: $(SRC_DIR)/delete_kth_last_from_list.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
delete_kth_last_from_list_dbg: $(BUILD_DIR)/delete_kth_last_from_list_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: delete_kth_last_from_list delete_kth_last_from_list_dbg


# delete_node_from_list.cc

$(BUILD_DIR)/delete_node_from_list: $(SRC_DIR)/delete_node_from_list.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
delete_node_from_list: $(BUILD_DIR)/delete_node_from_list
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/delete_node_from_list_dbg: $(SRC_DIR)/delete_node_from_list.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
delete_node_from_list_dbg: $(BUILD_DIR)/delete_node_from_list_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: delete_node_from_list delete_node_from_list_dbg


# descendant_and_ancestor_in_bst.cc

$(BUILD_DIR)/descendant_and_ancestor_in_bst: $(SRC_DIR)/descendant_and_ancestor_in_bst.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
descendant_and_ancestor_in_bst: $(BUILD_DIR)/descendant_and_ancestor_in_bst
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/descendant_and_ancestor_in_bst_dbg: $(SRC_DIR)/descendant_and_ancestor_in_bst.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
descendant_and_ancestor_in_bst_dbg: $(BUILD_DIR)/descendant_and_ancestor_in_bst_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: descendant_and_ancestor_in_bst descendant_and_ancestor_in_bst_dbg


# directory_path_normalization.cc

$(BUILD_DIR)/directory_path_normalization: $(SRC_DIR)/directory_path_normalization.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
directory_path_normalization: $(BUILD_DIR)/directory_path_normalization
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/directory_path_normalization_dbg: $(SRC_DIR)/directory_path_normalization.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
directory_path_normalization_dbg: $(BUILD_DIR)/directory_path_normalization_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: directory_path_normalization directory_path_normalization_dbg


# do_lists_overlap.cc

$(BUILD_DIR)/do_lists_overlap: $(SRC_DIR)/do_lists_overlap.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
do_lists_overlap: $(BUILD_DIR)/do_lists_overlap
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/do_lists_overlap_dbg: $(SRC_DIR)/do_lists_overlap.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
do_lists_overlap_dbg: $(BUILD_DIR)/do_lists_overlap_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: do_lists_overlap do_lists_overlap_dbg


# do_terminated_lists_overlap.cc

$(BUILD_DIR)/do_terminated_lists_overlap: $(SRC_DIR)/do_terminated_lists_overlap.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
do_terminated_lists_overlap: $(BUILD_DIR)/do_terminated_lists_overlap
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/do_terminated_lists_overlap_dbg: $(SRC_DIR)/do_terminated_lists_overlap.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
do_terminated_lists_overlap_dbg: $(BUILD_DIR)/do_terminated_lists_overlap_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: do_terminated_lists_overlap do_terminated_lists_overlap_dbg


# drawing_skyline.cc

$(BUILD_DIR)/drawing_skyline: $(SRC_DIR)/drawing_skyline.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
drawing_skyline: $(BUILD_DIR)/drawing_skyline
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/drawing_skyline_dbg: $(SRC_DIR)/drawing_skyline.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
drawing_skyline_dbg: $(BUILD_DIR)/drawing_skyline_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: drawing_skyline drawing_skyline_dbg


# dutch_national_flag.cc

$(BUILD_DIR)/dutch_national_flag: $(SRC_DIR)/dutch_national_flag.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
dutch_national_flag: $(BUILD_DIR)/dutch_national_flag
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/dutch_national_flag_dbg: $(SRC_DIR)/dutch_national_flag.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
dutch_national_flag_dbg: $(BUILD_DIR)/dutch_national_flag_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: dutch_national_flag dutch_national_flag_dbg


# element_appearing_once.cc

$(BUILD_DIR)/element_appearing_once: $(SRC_DIR)/element_appearing_once.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
element_appearing_once: $(BUILD_DIR)/element_appearing_once
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/element_appearing_once_dbg: $(SRC_DIR)/element_appearing_once.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
element_appearing_once_dbg: $(BUILD_DIR)/element_appearing_once_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: element_appearing_once element_appearing_once_dbg


# enumerate_balanced_parentheses.cc

$(BUILD_DIR)/enumerate_balanced_parentheses: $(SRC_DIR)/enumerate_balanced_parentheses.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
enumerate_balanced_parentheses: $(BUILD_DIR)/enumerate_balanced_parentheses
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/enumerate_balanced_parentheses_dbg: $(SRC_DIR)/enumerate_balanced_parentheses.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
enumerate_balanced_parentheses_dbg: $(BUILD_DIR)/enumerate_balanced_parentheses_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: enumerate_balanced_parentheses enumerate_balanced_parentheses_dbg


# enumerate_palindromic_decompositions.cc

$(BUILD_DIR)/enumerate_palindromic_decompositions: $(SRC_DIR)/enumerate_palindromic_decompositions.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
enumerate_palindromic_decompositions: $(BUILD_DIR)/enumerate_palindromic_decompositions
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/enumerate_palindromic_decompositions_dbg: $(SRC_DIR)/enumerate_palindromic_decompositions.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
enumerate_palindromic_decompositions_dbg: $(BUILD_DIR)/enumerate_palindromic_decompositions_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: enumerate_palindromic_decompositions enumerate_palindromic_decompositions_dbg


# enumerate_trees.cc

$(BUILD_DIR)/enumerate_trees: $(SRC_DIR)/enumerate_trees.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
enumerate_trees: $(BUILD_DIR)/enumerate_trees
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/enumerate_trees_dbg: $(SRC_DIR)/enumerate_trees.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
enumerate_trees_dbg: $(BUILD_DIR)/enumerate_trees_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: enumerate_trees enumerate_trees_dbg


# evaluate_rpn.cc

$(BUILD_DIR)/evaluate_rpn: $(SRC_DIR)/evaluate_rpn.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
evaluate_rpn: $(BUILD_DIR)/evaluate_rpn
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/evaluate_rpn_dbg: $(SRC_DIR)/evaluate_rpn.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
evaluate_rpn_dbg: $(BUILD_DIR)/evaluate_rpn_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: evaluate_rpn evaluate_rpn_dbg


# even_odd_array.cc

$(BUILD_DIR)/even_odd_array: $(SRC_DIR)/even_odd_array.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
even_odd_array: $(BUILD_DIR)/even_odd_array
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/even_odd_array_dbg: $(SRC_DIR)/even_odd_array.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
even_odd_array_dbg: $(BUILD_DIR)/even_odd_array_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: even_odd_array even_odd_array_dbg


# even_odd_list_merge.cc

$(BUILD_DIR)/even_odd_list_merge: $(SRC_DIR)/even_odd_list_merge.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
even_odd_list_merge: $(BUILD_DIR)/even_odd_list_merge
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/even_odd_list_merge_dbg: $(SRC_DIR)/even_odd_list_merge.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
even_odd_list_merge_dbg: $(BUILD_DIR)/even_odd_list_merge_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: even_odd_list_merge even_odd_list_merge_dbg


# find_salary_threshold.cc

$(BUILD_DIR)/find_salary_threshold: $(SRC_DIR)/find_salary_threshold.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
find_salary_threshold: $(BUILD_DIR)/find_salary_threshold
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/find_salary_threshold_dbg: $(SRC_DIR)/find_salary_threshold.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
find_salary_threshold_dbg: $(BUILD_DIR)/find_salary_threshold_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: find_salary_threshold find_salary_threshold_dbg


# first_missing_positive_entry.cc

$(BUILD_DIR)/first_missing_positive_entry: $(SRC_DIR)/first_missing_positive_entry.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
first_missing_positive_entry: $(BUILD_DIR)/first_missing_positive_entry
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/first_missing_positive_entry_dbg: $(SRC_DIR)/first_missing_positive_entry.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
first_missing_positive_entry_dbg: $(BUILD_DIR)/first_missing_positive_entry_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: first_missing_positive_entry first_missing_positive_entry_dbg


# gcd.cc

$(BUILD_DIR)/gcd: $(SRC_DIR)/gcd.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
gcd: $(BUILD_DIR)/gcd
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/gcd_dbg: $(SRC_DIR)/gcd.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
gcd_dbg: $(BUILD_DIR)/gcd_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: gcd gcd_dbg


# graph_clone.cc

$(BUILD_DIR)/graph_clone: $(SRC_DIR)/graph_clone.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
graph_clone: $(BUILD_DIR)/graph_clone
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/graph_clone_dbg: $(SRC_DIR)/graph_clone.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
graph_clone_dbg: $(BUILD_DIR)/graph_clone_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: graph_clone graph_clone_dbg


# gray_code.cc

$(BUILD_DIR)/gray_code: $(SRC_DIR)/gray_code.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
gray_code: $(BUILD_DIR)/gray_code
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/gray_code_dbg: $(SRC_DIR)/gray_code.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
gray_code_dbg: $(BUILD_DIR)/gray_code_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: gray_code gray_code_dbg


# group_equal_entries.cc

$(BUILD_DIR)/group_equal_entries: $(SRC_DIR)/group_equal_entries.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
group_equal_entries: $(BUILD_DIR)/group_equal_entries
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/group_equal_entries_dbg: $(SRC_DIR)/group_equal_entries.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
group_equal_entries_dbg: $(BUILD_DIR)/group_equal_entries_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: group_equal_entries group_equal_entries_dbg


# hanoi.cc

$(BUILD_DIR)/hanoi: $(SRC_DIR)/hanoi.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
hanoi: $(BUILD_DIR)/hanoi
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/hanoi_dbg: $(SRC_DIR)/hanoi.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
hanoi_dbg: $(BUILD_DIR)/hanoi_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: hanoi hanoi_dbg


# huffman_coding.cc

$(BUILD_DIR)/huffman_coding: $(SRC_DIR)/huffman_coding.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
huffman_coding: $(BUILD_DIR)/huffman_coding
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/huffman_coding_dbg: $(SRC_DIR)/huffman_coding.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
huffman_coding_dbg: $(BUILD_DIR)/huffman_coding_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: huffman_coding huffman_coding_dbg


# insert_in_list.cc

$(BUILD_DIR)/insert_in_list: $(SRC_DIR)/insert_in_list.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
insert_in_list: $(BUILD_DIR)/insert_in_list
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/insert_in_list_dbg: $(SRC_DIR)/insert_in_list.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
insert_in_list_dbg: $(BUILD_DIR)/insert_in_list_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: insert_in_list insert_in_list_dbg


# insert_operators_in_string.cc

$(BUILD_DIR)/insert_operators_in_string: $(SRC_DIR)/insert_operators_in_string.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
insert_operators_in_string: $(BUILD_DIR)/insert_operators_in_string
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/insert_operators_in_string_dbg: $(SRC_DIR)/insert_operators_in_string.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
insert_operators_in_string_dbg: $(BUILD_DIR)/insert_operators_in_string_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: insert_operators_in_string insert_operators_in_string_dbg


# int_as_array_increment.cc

$(BUILD_DIR)/int_as_array_increment: $(SRC_DIR)/int_as_array_increment.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
int_as_array_increment: $(BUILD_DIR)/int_as_array_increment
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/int_as_array_increment_dbg: $(SRC_DIR)/int_as_array_increment.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
int_as_array_increment_dbg: $(BUILD_DIR)/int_as_array_increment_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: int_as_array_increment int_as_array_increment_dbg


# int_as_array_multiply.cc

$(BUILD_DIR)/int_as_array_multiply: $(SRC_DIR)/int_as_array_multiply.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
int_as_array_multiply: $(BUILD_DIR)/int_as_array_multiply
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/int_as_array_multiply_dbg: $(SRC_DIR)/int_as_array_multiply.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
int_as_array_multiply_dbg: $(BUILD_DIR)/int_as_array_multiply_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: int_as_array_multiply int_as_array_multiply_dbg


# int_as_list_add.cc

$(BUILD_DIR)/int_as_list_add: $(SRC_DIR)/int_as_list_add.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
int_as_list_add: $(BUILD_DIR)/int_as_list_add
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/int_as_list_add_dbg: $(SRC_DIR)/int_as_list_add.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
int_as_list_add_dbg: $(BUILD_DIR)/int_as_list_add_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: int_as_list_add int_as_list_add_dbg


# int_square_root.cc

$(BUILD_DIR)/int_square_root: $(SRC_DIR)/int_square_root.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
int_square_root: $(BUILD_DIR)/int_square_root
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/int_square_root_dbg: $(SRC_DIR)/int_square_root.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
int_square_root_dbg: $(BUILD_DIR)/int_square_root_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: int_square_root int_square_root_dbg


# intersect_sorted_arrays.cc

$(BUILD_DIR)/intersect_sorted_arrays: $(SRC_DIR)/intersect_sorted_arrays.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
intersect_sorted_arrays: $(BUILD_DIR)/intersect_sorted_arrays
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/intersect_sorted_arrays_dbg: $(SRC_DIR)/intersect_sorted_arrays.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
intersect_sorted_arrays_dbg: $(BUILD_DIR)/intersect_sorted_arrays_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: intersect_sorted_arrays intersect_sorted_arrays_dbg


# interval_add.cc

$(BUILD_DIR)/interval_add: $(SRC_DIR)/interval_add.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
interval_add: $(BUILD_DIR)/interval_add
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/interval_add_dbg: $(SRC_DIR)/interval_add.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
interval_add_dbg: $(BUILD_DIR)/interval_add_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: interval_add interval_add_dbg


# intervals_union.cc

$(BUILD_DIR)/intervals_union: $(SRC_DIR)/intervals_union.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
intervals_union: $(BUILD_DIR)/intervals_union
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/intervals_union_dbg: $(SRC_DIR)/intervals_union.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
intervals_union_dbg: $(BUILD_DIR)/intervals_union_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: intervals_union intervals_union_dbg


# is_anonymous_letter_constructible.cc

$(BUILD_DIR)/is_anonymous_letter_constructible: $(SRC_DIR)/is_anonymous_letter_constructible.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
is_anonymous_letter_constructible: $(BUILD_DIR)/is_anonymous_letter_constructible
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/is_anonymous_letter_constructible_dbg: $(SRC_DIR)/is_anonymous_letter_constructible.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
is_anonymous_letter_constructible_dbg: $(BUILD_DIR)/is_anonymous_letter_constructible_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: is_anonymous_letter_constructible is_anonymous_letter_constructible_dbg


# is_array_dominated.cc

$(BUILD_DIR)/is_array_dominated: $(SRC_DIR)/is_array_dominated.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
is_array_dominated: $(BUILD_DIR)/is_array_dominated
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/is_array_dominated_dbg: $(SRC_DIR)/is_array_dominated.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
is_array_dominated_dbg: $(BUILD_DIR)/is_array_dominated_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: is_array_dominated is_array_dominated_dbg


# is_circuit_wirable.cc

$(BUILD_DIR)/is_circuit_wirable: $(SRC_DIR)/is_circuit_wirable.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
is_circuit_wirable: $(BUILD_DIR)/is_circuit_wirable
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/is_circuit_wirable_dbg: $(SRC_DIR)/is_circuit_wirable.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
is_circuit_wirable_dbg: $(BUILD_DIR)/is_circuit_wirable_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: is_circuit_wirable is_circuit_wirable_dbg


# is_list_cyclic.cc

$(BUILD_DIR)/is_list_cyclic: $(SRC_DIR)/is_list_cyclic.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
is_list_cyclic: $(BUILD_DIR)/is_list_cyclic
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/is_list_cyclic_dbg: $(SRC_DIR)/is_list_cyclic.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
is_list_cyclic_dbg: $(BUILD_DIR)/is_list_cyclic_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: is_list_cyclic is_list_cyclic_dbg


# is_list_palindromic.cc

$(BUILD_DIR)/is_list_palindromic: $(SRC_DIR)/is_list_palindromic.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
is_list_palindromic: $(BUILD_DIR)/is_list_palindromic
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/is_list_palindromic_dbg: $(SRC_DIR)/is_list_palindromic.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
is_list_palindromic_dbg: $(BUILD_DIR)/is_list_palindromic_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: is_list_palindromic is_list_palindromic_dbg


# is_number_palindromic.cc

$(BUILD_DIR)/is_number_palindromic: $(SRC_DIR)/is_number_palindromic.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
is_number_palindromic: $(BUILD_DIR)/is_number_palindromic
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/is_number_palindromic_dbg: $(SRC_DIR)/is_number_palindromic.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
is_number_palindromic_dbg: $(BUILD_DIR)/is_number_palindromic_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: is_number_palindromic is_number_palindromic_dbg


# is_string_decomposable_into_words.cc

$(BUILD_DIR)/is_string_decomposable_into_words: $(SRC_DIR)/is_string_decomposable_into_words.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
is_string_decomposable_into_words: $(BUILD_DIR)/is_string_decomposable_into_words
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/is_string_decomposable_into_words_dbg: $(SRC_DIR)/is_string_decomposable_into_words.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
is_string_decomposable_into_words_dbg: $(BUILD_DIR)/is_string_decomposable_into_words_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: is_string_decomposable_into_words is_string_decomposable_into_words_dbg


# is_string_in_matrix.cc

$(BUILD_DIR)/is_string_in_matrix: $(SRC_DIR)/is_string_in_matrix.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
is_string_in_matrix: $(BUILD_DIR)/is_string_in_matrix
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/is_string_in_matrix_dbg: $(SRC_DIR)/is_string_in_matrix.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
is_string_in_matrix_dbg: $(BUILD_DIR)/is_string_in_matrix_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: is_string_in_matrix is_string_in_matrix_dbg


# is_string_palindromic_punctuation.cc

$(BUILD_DIR)/is_string_palindromic_punctuation: $(SRC_DIR)/is_string_palindromic_punctuation.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
is_string_palindromic_punctuation: $(BUILD_DIR)/is_string_palindromic_punctuation
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/is_string_palindromic_punctuation_dbg: $(SRC_DIR)/is_string_palindromic_punctuation.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
is_string_palindromic_punctuation_dbg: $(BUILD_DIR)/is_string_palindromic_punctuation_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: is_string_palindromic_punctuation is_string_palindromic_punctuation_dbg


# is_string_permutable_to_palindrome.cc

$(BUILD_DIR)/is_string_permutable_to_palindrome: $(SRC_DIR)/is_string_permutable_to_palindrome.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
is_string_permutable_to_palindrome: $(BUILD_DIR)/is_string_permutable_to_palindrome
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/is_string_permutable_to_palindrome_dbg: $(SRC_DIR)/is_string_permutable_to_palindrome.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
is_string_permutable_to_palindrome_dbg: $(BUILD_DIR)/is_string_permutable_to_palindrome_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: is_string_permutable_to_palindrome is_string_permutable_to_palindrome_dbg


# is_tree_a_bst.cc

$(BUILD_DIR)/is_tree_a_bst: $(SRC_DIR)/is_tree_a_bst.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
is_tree_a_bst: $(BUILD_DIR)/is_tree_a_bst
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/is_tree_a_bst_dbg: $(SRC_DIR)/is_tree_a_bst.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
is_tree_a_bst_dbg: $(BUILD_DIR)/is_tree_a_bst_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: is_tree_a_bst is_tree_a_bst_dbg


# is_tree_balanced.cc

$(BUILD_DIR)/is_tree_balanced: $(SRC_DIR)/is_tree_balanced.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
is_tree_balanced: $(BUILD_DIR)/is_tree_balanced
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/is_tree_balanced_dbg: $(SRC_DIR)/is_tree_balanced.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
is_tree_balanced_dbg: $(BUILD_DIR)/is_tree_balanced_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: is_tree_balanced is_tree_balanced_dbg


# is_tree_symmetric.cc

$(BUILD_DIR)/is_tree_symmetric: $(SRC_DIR)/is_tree_symmetric.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
is_tree_symmetric: $(BUILD_DIR)/is_tree_symmetric
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/is_tree_symmetric_dbg: $(SRC_DIR)/is_tree_symmetric.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
is_tree_symmetric_dbg: $(BUILD_DIR)/is_tree_symmetric_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: is_tree_symmetric is_tree_symmetric_dbg


# is_valid_parenthesization.cc

$(BUILD_DIR)/is_valid_parenthesization: $(SRC_DIR)/is_valid_parenthesization.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
is_valid_parenthesization: $(BUILD_DIR)/is_valid_parenthesization
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/is_valid_parenthesization_dbg: $(SRC_DIR)/is_valid_parenthesization.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
is_valid_parenthesization_dbg: $(BUILD_DIR)/is_valid_parenthesization_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: is_valid_parenthesization is_valid_parenthesization_dbg


# is_valid_sudoku.cc

$(BUILD_DIR)/is_valid_sudoku: $(SRC_DIR)/is_valid_sudoku.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
is_valid_sudoku: $(BUILD_DIR)/is_valid_sudoku
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/is_valid_sudoku_dbg: $(SRC_DIR)/is_valid_sudoku.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
is_valid_sudoku_dbg: $(BUILD_DIR)/is_valid_sudoku_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: is_valid_sudoku is_valid_sudoku_dbg


# k_closest_stars.cc

$(BUILD_DIR)/k_closest_stars: $(SRC_DIR)/k_closest_stars.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
k_closest_stars: $(BUILD_DIR)/k_closest_stars
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/k_closest_stars_dbg: $(SRC_DIR)/k_closest_stars.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
k_closest_stars_dbg: $(BUILD_DIR)/k_closest_stars_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: k_closest_stars k_closest_stars_dbg


# k_largest_in_heap.cc

$(BUILD_DIR)/k_largest_in_heap: $(SRC_DIR)/k_largest_in_heap.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
k_largest_in_heap: $(BUILD_DIR)/k_largest_in_heap
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/k_largest_in_heap_dbg: $(SRC_DIR)/k_largest_in_heap.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
k_largest_in_heap_dbg: $(BUILD_DIR)/k_largest_in_heap_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: k_largest_in_heap k_largest_in_heap_dbg


# k_largest_values_in_bst.cc

$(BUILD_DIR)/k_largest_values_in_bst: $(SRC_DIR)/k_largest_values_in_bst.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
k_largest_values_in_bst: $(BUILD_DIR)/k_largest_values_in_bst
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/k_largest_values_in_bst_dbg: $(SRC_DIR)/k_largest_values_in_bst.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
k_largest_values_in_bst_dbg: $(BUILD_DIR)/k_largest_values_in_bst_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: k_largest_values_in_bst k_largest_values_in_bst_dbg


# knapsack.cc

$(BUILD_DIR)/knapsack: $(SRC_DIR)/knapsack.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
knapsack: $(BUILD_DIR)/knapsack
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/knapsack_dbg: $(SRC_DIR)/knapsack.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
knapsack_dbg: $(BUILD_DIR)/knapsack_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: knapsack knapsack_dbg


# kth_largest_element_in_two_sorted_arrays.cc

$(BUILD_DIR)/kth_largest_element_in_two_sorted_arrays: $(SRC_DIR)/kth_largest_element_in_two_sorted_arrays.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
kth_largest_element_in_two_sorted_arrays: $(BUILD_DIR)/kth_largest_element_in_two_sorted_arrays
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/kth_largest_element_in_two_sorted_arrays_dbg: $(SRC_DIR)/kth_largest_element_in_two_sorted_arrays.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
kth_largest_element_in_two_sorted_arrays_dbg: $(BUILD_DIR)/kth_largest_element_in_two_sorted_arrays_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: kth_largest_element_in_two_sorted_arrays kth_largest_element_in_two_sorted_arrays_dbg


# kth_largest_in_array.cc

$(BUILD_DIR)/kth_largest_in_array: $(SRC_DIR)/kth_largest_in_array.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
kth_largest_in_array: $(BUILD_DIR)/kth_largest_in_array
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/kth_largest_in_array_dbg: $(SRC_DIR)/kth_largest_in_array.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
kth_largest_in_array_dbg: $(BUILD_DIR)/kth_largest_in_array_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: kth_largest_in_array kth_largest_in_array_dbg


# kth_node_in_tree.cc

$(BUILD_DIR)/kth_node_in_tree: $(SRC_DIR)/kth_node_in_tree.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
kth_node_in_tree: $(BUILD_DIR)/kth_node_in_tree
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/kth_node_in_tree_dbg: $(SRC_DIR)/kth_node_in_tree.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
kth_node_in_tree_dbg: $(BUILD_DIR)/kth_node_in_tree_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: kth_node_in_tree kth_node_in_tree_dbg


# largest_rectangle_under_skyline.cc

$(BUILD_DIR)/largest_rectangle_under_skyline: $(SRC_DIR)/largest_rectangle_under_skyline.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
largest_rectangle_under_skyline: $(BUILD_DIR)/largest_rectangle_under_skyline
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/largest_rectangle_under_skyline_dbg: $(SRC_DIR)/largest_rectangle_under_skyline.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
largest_rectangle_under_skyline_dbg: $(BUILD_DIR)/largest_rectangle_under_skyline_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: largest_rectangle_under_skyline largest_rectangle_under_skyline_dbg


# left_right_justify_text.cc

$(BUILD_DIR)/left_right_justify_text: $(SRC_DIR)/left_right_justify_text.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
left_right_justify_text: $(BUILD_DIR)/left_right_justify_text
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/left_right_justify_text_dbg: $(SRC_DIR)/left_right_justify_text.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
left_right_justify_text_dbg: $(BUILD_DIR)/left_right_justify_text_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: left_right_justify_text left_right_justify_text_dbg


# levenshtein_distance.cc

$(BUILD_DIR)/levenshtein_distance: $(SRC_DIR)/levenshtein_distance.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
levenshtein_distance: $(BUILD_DIR)/levenshtein_distance
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/levenshtein_distance_dbg: $(SRC_DIR)/levenshtein_distance.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
levenshtein_distance_dbg: $(BUILD_DIR)/levenshtein_distance_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: levenshtein_distance levenshtein_distance_dbg


# line_though_most_points.cc

$(BUILD_DIR)/line_though_most_points: $(SRC_DIR)/line_though_most_points.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
line_though_most_points: $(BUILD_DIR)/line_though_most_points
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/line_though_most_points_dbg: $(SRC_DIR)/line_though_most_points.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
line_though_most_points_dbg: $(BUILD_DIR)/line_though_most_points_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: line_though_most_points line_though_most_points_dbg


# list_cyclic_right_shift.cc

$(BUILD_DIR)/list_cyclic_right_shift: $(SRC_DIR)/list_cyclic_right_shift.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
list_cyclic_right_shift: $(BUILD_DIR)/list_cyclic_right_shift
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/list_cyclic_right_shift_dbg: $(SRC_DIR)/list_cyclic_right_shift.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
list_cyclic_right_shift_dbg: $(BUILD_DIR)/list_cyclic_right_shift_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: list_cyclic_right_shift list_cyclic_right_shift_dbg


# longest_contained_interval.cc

$(BUILD_DIR)/longest_contained_interval: $(SRC_DIR)/longest_contained_interval.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
longest_contained_interval: $(BUILD_DIR)/longest_contained_interval
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/longest_contained_interval_dbg: $(SRC_DIR)/longest_contained_interval.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
longest_contained_interval_dbg: $(BUILD_DIR)/longest_contained_interval_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: longest_contained_interval longest_contained_interval_dbg


# longest_increasing_subarray.cc

$(BUILD_DIR)/longest_increasing_subarray: $(SRC_DIR)/longest_increasing_subarray.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
longest_increasing_subarray: $(BUILD_DIR)/longest_increasing_subarray
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/longest_increasing_subarray_dbg: $(SRC_DIR)/longest_increasing_subarray.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
longest_increasing_subarray_dbg: $(BUILD_DIR)/longest_increasing_subarray_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: longest_increasing_subarray longest_increasing_subarray_dbg


# longest_nondecreasing_subsequence.cc

$(BUILD_DIR)/longest_nondecreasing_subsequence: $(SRC_DIR)/longest_nondecreasing_subsequence.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
longest_nondecreasing_subsequence: $(BUILD_DIR)/longest_nondecreasing_subsequence
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/longest_nondecreasing_subsequence_dbg: $(SRC_DIR)/longest_nondecreasing_subsequence.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
longest_nondecreasing_subsequence_dbg: $(BUILD_DIR)/longest_nondecreasing_subsequence_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: longest_nondecreasing_subsequence longest_nondecreasing_subsequence_dbg


# longest_subarray_with_distinct_values.cc

$(BUILD_DIR)/longest_subarray_with_distinct_values: $(SRC_DIR)/longest_subarray_with_distinct_values.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
longest_subarray_with_distinct_values: $(BUILD_DIR)/longest_subarray_with_distinct_values
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/longest_subarray_with_distinct_values_dbg: $(SRC_DIR)/longest_subarray_with_distinct_values.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
longest_subarray_with_distinct_values_dbg: $(BUILD_DIR)/longest_subarray_with_distinct_values_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: longest_subarray_with_distinct_values longest_subarray_with_distinct_values_dbg


# longest_subarray_with_sum_constraint.cc

$(BUILD_DIR)/longest_subarray_with_sum_constraint: $(SRC_DIR)/longest_subarray_with_sum_constraint.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
longest_subarray_with_sum_constraint: $(BUILD_DIR)/longest_subarray_with_sum_constraint
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/longest_subarray_with_sum_constraint_dbg: $(SRC_DIR)/longest_subarray_with_sum_constraint.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
longest_subarray_with_sum_constraint_dbg: $(BUILD_DIR)/longest_subarray_with_sum_constraint_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: longest_subarray_with_sum_constraint longest_subarray_with_sum_constraint_dbg


# longest_substring_with_matching_parentheses.cc

$(BUILD_DIR)/longest_substring_with_matching_parentheses: $(SRC_DIR)/longest_substring_with_matching_parentheses.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
longest_substring_with_matching_parentheses: $(BUILD_DIR)/longest_substring_with_matching_parentheses
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/longest_substring_with_matching_parentheses_dbg: $(SRC_DIR)/longest_substring_with_matching_parentheses.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
longest_substring_with_matching_parentheses_dbg: $(BUILD_DIR)/longest_substring_with_matching_parentheses_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: longest_substring_with_matching_parentheses longest_substring_with_matching_parentheses_dbg


# look_and_say.cc

$(BUILD_DIR)/look_and_say: $(SRC_DIR)/look_and_say.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
look_and_say: $(BUILD_DIR)/look_and_say
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/look_and_say_dbg: $(SRC_DIR)/look_and_say.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
look_and_say_dbg: $(BUILD_DIR)/look_and_say_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: look_and_say look_and_say_dbg


# lowest_common_ancestor.cc

$(BUILD_DIR)/lowest_common_ancestor: $(SRC_DIR)/lowest_common_ancestor.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
lowest_common_ancestor: $(BUILD_DIR)/lowest_common_ancestor
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/lowest_common_ancestor_dbg: $(SRC_DIR)/lowest_common_ancestor.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
lowest_common_ancestor_dbg: $(BUILD_DIR)/lowest_common_ancestor_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: lowest_common_ancestor lowest_common_ancestor_dbg


# lowest_common_ancestor_close_ancestor.cc

$(BUILD_DIR)/lowest_common_ancestor_close_ancestor: $(SRC_DIR)/lowest_common_ancestor_close_ancestor.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
lowest_common_ancestor_close_ancestor: $(BUILD_DIR)/lowest_common_ancestor_close_ancestor
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/lowest_common_ancestor_close_ancestor_dbg: $(SRC_DIR)/lowest_common_ancestor_close_ancestor.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
lowest_common_ancestor_close_ancestor_dbg: $(BUILD_DIR)/lowest_common_ancestor_close_ancestor_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: lowest_common_ancestor_close_ancestor lowest_common_ancestor_close_ancestor_dbg


# lowest_common_ancestor_in_bst.cc

$(BUILD_DIR)/lowest_common_ancestor_in_bst: $(SRC_DIR)/lowest_common_ancestor_in_bst.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
lowest_common_ancestor_in_bst: $(BUILD_DIR)/lowest_common_ancestor_in_bst
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/lowest_common_ancestor_in_bst_dbg: $(SRC_DIR)/lowest_common_ancestor_in_bst.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
lowest_common_ancestor_in_bst_dbg: $(BUILD_DIR)/lowest_common_ancestor_in_bst_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: lowest_common_ancestor_in_bst lowest_common_ancestor_in_bst_dbg


# lowest_common_ancestor_with_parent.cc

$(BUILD_DIR)/lowest_common_ancestor_with_parent: $(SRC_DIR)/lowest_common_ancestor_with_parent.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
lowest_common_ancestor_with_parent: $(BUILD_DIR)/lowest_common_ancestor_with_parent
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/lowest_common_ancestor_with_parent_dbg: $(SRC_DIR)/lowest_common_ancestor_with_parent.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
lowest_common_ancestor_with_parent_dbg: $(BUILD_DIR)/lowest_common_ancestor_with_parent_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: lowest_common_ancestor_with_parent lowest_common_ancestor_with_parent_dbg


# lru_cache.cc

$(BUILD_DIR)/lru_cache: $(SRC_DIR)/lru_cache.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
lru_cache: $(BUILD_DIR)/lru_cache
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/lru_cache_dbg: $(SRC_DIR)/lru_cache.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
lru_cache_dbg: $(BUILD_DIR)/lru_cache_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: lru_cache lru_cache_dbg


# majority_element.cc

$(BUILD_DIR)/majority_element: $(SRC_DIR)/majority_element.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
majority_element: $(BUILD_DIR)/majority_element
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/majority_element_dbg: $(SRC_DIR)/majority_element.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
majority_element_dbg: $(BUILD_DIR)/majority_element_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: majority_element majority_element_dbg


# matrix_connected_regions.cc

$(BUILD_DIR)/matrix_connected_regions: $(SRC_DIR)/matrix_connected_regions.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
matrix_connected_regions: $(BUILD_DIR)/matrix_connected_regions
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/matrix_connected_regions_dbg: $(SRC_DIR)/matrix_connected_regions.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
matrix_connected_regions_dbg: $(BUILD_DIR)/matrix_connected_regions_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: matrix_connected_regions matrix_connected_regions_dbg


# matrix_enclosed_regions.cc

$(BUILD_DIR)/matrix_enclosed_regions: $(SRC_DIR)/matrix_enclosed_regions.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
matrix_enclosed_regions: $(BUILD_DIR)/matrix_enclosed_regions
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/matrix_enclosed_regions_dbg: $(SRC_DIR)/matrix_enclosed_regions.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
matrix_enclosed_regions_dbg: $(BUILD_DIR)/matrix_enclosed_regions_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: matrix_enclosed_regions matrix_enclosed_regions_dbg


# matrix_rotation.cc

$(BUILD_DIR)/matrix_rotation: $(SRC_DIR)/matrix_rotation.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
matrix_rotation: $(BUILD_DIR)/matrix_rotation
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/matrix_rotation_dbg: $(SRC_DIR)/matrix_rotation.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
matrix_rotation_dbg: $(BUILD_DIR)/matrix_rotation_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: matrix_rotation matrix_rotation_dbg


# max_of_sliding_window.cc

$(BUILD_DIR)/max_of_sliding_window: $(SRC_DIR)/max_of_sliding_window.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
max_of_sliding_window: $(BUILD_DIR)/max_of_sliding_window
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/max_of_sliding_window_dbg: $(SRC_DIR)/max_of_sliding_window.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
max_of_sliding_window_dbg: $(BUILD_DIR)/max_of_sliding_window_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: max_of_sliding_window max_of_sliding_window_dbg


# max_product_all_but_one.cc

$(BUILD_DIR)/max_product_all_but_one: $(SRC_DIR)/max_product_all_but_one.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
max_product_all_but_one: $(BUILD_DIR)/max_product_all_but_one
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/max_product_all_but_one_dbg: $(SRC_DIR)/max_product_all_but_one.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
max_product_all_but_one_dbg: $(BUILD_DIR)/max_product_all_but_one_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: max_product_all_but_one max_product_all_but_one_dbg


# max_safe_height.cc

$(BUILD_DIR)/max_safe_height: $(SRC_DIR)/max_safe_height.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
max_safe_height: $(BUILD_DIR)/max_safe_height
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/max_safe_height_dbg: $(SRC_DIR)/max_safe_height.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
max_safe_height_dbg: $(BUILD_DIR)/max_safe_height_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: max_safe_height max_safe_height_dbg


# max_square_submatrix.cc

$(BUILD_DIR)/max_square_submatrix: $(SRC_DIR)/max_square_submatrix.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
max_square_submatrix: $(BUILD_DIR)/max_square_submatrix
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/max_square_submatrix_dbg: $(SRC_DIR)/max_square_submatrix.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
max_square_submatrix_dbg: $(BUILD_DIR)/max_square_submatrix_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: max_square_submatrix max_square_submatrix_dbg


# max_submatrix.cc

$(BUILD_DIR)/max_submatrix: $(SRC_DIR)/max_submatrix.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
max_submatrix: $(BUILD_DIR)/max_submatrix
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/max_submatrix_dbg: $(SRC_DIR)/max_submatrix.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
max_submatrix_dbg: $(BUILD_DIR)/max_submatrix_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: max_submatrix max_submatrix_dbg


# max_teams_in_photograph.cc

$(BUILD_DIR)/max_teams_in_photograph: $(SRC_DIR)/max_teams_in_photograph.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
max_teams_in_photograph: $(BUILD_DIR)/max_teams_in_photograph
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/max_teams_in_photograph_dbg: $(SRC_DIR)/max_teams_in_photograph.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
max_teams_in_photograph_dbg: $(BUILD_DIR)/max_teams_in_photograph_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: max_teams_in_photograph max_teams_in_photograph_dbg


# max_water_trappable.cc

$(BUILD_DIR)/max_water_trappable: $(SRC_DIR)/max_water_trappable.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
max_water_trappable: $(BUILD_DIR)/max_water_trappable
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/max_water_trappable_dbg: $(SRC_DIR)/max_water_trappable.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
max_water_trappable_dbg: $(BUILD_DIR)/max_water_trappable_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: max_water_trappable max_water_trappable_dbg


# maximum_subarray_in_circular_array.cc

$(BUILD_DIR)/maximum_subarray_in_circular_array: $(SRC_DIR)/maximum_subarray_in_circular_array.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
maximum_subarray_in_circular_array: $(BUILD_DIR)/maximum_subarray_in_circular_array
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/maximum_subarray_in_circular_array_dbg: $(SRC_DIR)/maximum_subarray_in_circular_array.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
maximum_subarray_in_circular_array_dbg: $(BUILD_DIR)/maximum_subarray_in_circular_array_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: maximum_subarray_in_circular_array maximum_subarray_in_circular_array_dbg


# minimum_distance_3_sorted_arrays.cc

$(BUILD_DIR)/minimum_distance_3_sorted_arrays: $(SRC_DIR)/minimum_distance_3_sorted_arrays.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
minimum_distance_3_sorted_arrays: $(BUILD_DIR)/minimum_distance_3_sorted_arrays
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/minimum_distance_3_sorted_arrays_dbg: $(SRC_DIR)/minimum_distance_3_sorted_arrays.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
minimum_distance_3_sorted_arrays_dbg: $(BUILD_DIR)/minimum_distance_3_sorted_arrays_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: minimum_distance_3_sorted_arrays minimum_distance_3_sorted_arrays_dbg


# minimum_points_covering_intervals.cc

$(BUILD_DIR)/minimum_points_covering_intervals: $(SRC_DIR)/minimum_points_covering_intervals.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
minimum_points_covering_intervals: $(BUILD_DIR)/minimum_points_covering_intervals
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/minimum_points_covering_intervals_dbg: $(SRC_DIR)/minimum_points_covering_intervals.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
minimum_points_covering_intervals_dbg: $(BUILD_DIR)/minimum_points_covering_intervals_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: minimum_points_covering_intervals minimum_points_covering_intervals_dbg


# minimum_waiting_time.cc

$(BUILD_DIR)/minimum_waiting_time: $(SRC_DIR)/minimum_waiting_time.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
minimum_waiting_time: $(BUILD_DIR)/minimum_waiting_time
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/minimum_waiting_time_dbg: $(SRC_DIR)/minimum_waiting_time.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
minimum_waiting_time_dbg: $(BUILD_DIR)/minimum_waiting_time_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: minimum_waiting_time minimum_waiting_time_dbg


# minimum_weight_path_in_a_triangle.cc

$(BUILD_DIR)/minimum_weight_path_in_a_triangle: $(SRC_DIR)/minimum_weight_path_in_a_triangle.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
minimum_weight_path_in_a_triangle: $(BUILD_DIR)/minimum_weight_path_in_a_triangle
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/minimum_weight_path_in_a_triangle_dbg: $(SRC_DIR)/minimum_weight_path_in_a_triangle.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
minimum_weight_path_in_a_triangle_dbg: $(BUILD_DIR)/minimum_weight_path_in_a_triangle_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: minimum_weight_path_in_a_triangle minimum_weight_path_in_a_triangle_dbg


# n_queens.cc

$(BUILD_DIR)/n_queens: $(SRC_DIR)/n_queens.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
n_queens: $(BUILD_DIR)/n_queens
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/n_queens_dbg: $(SRC_DIR)/n_queens.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
n_queens_dbg: $(BUILD_DIR)/n_queens_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: n_queens n_queens_dbg


# nearest_repeated_entries.cc

$(BUILD_DIR)/nearest_repeated_entries: $(SRC_DIR)/nearest_repeated_entries.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
nearest_repeated_entries: $(BUILD_DIR)/nearest_repeated_entries
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/nearest_repeated_entries_dbg: $(SRC_DIR)/nearest_repeated_entries.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
nearest_repeated_entries_dbg: $(BUILD_DIR)/nearest_repeated_entries_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: nearest_repeated_entries nearest_repeated_entries_dbg


# next_permutation.cc

$(BUILD_DIR)/next_permutation: $(SRC_DIR)/next_permutation.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
next_permutation: $(BUILD_DIR)/next_permutation
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/next_permutation_dbg: $(SRC_DIR)/next_permutation.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
next_permutation_dbg: $(BUILD_DIR)/next_permutation_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: next_permutation next_permutation_dbg


# nonuniform_random_number.cc

$(BUILD_DIR)/nonuniform_random_number: $(SRC_DIR)/nonuniform_random_number.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
nonuniform_random_number: $(BUILD_DIR)/nonuniform_random_number
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/nonuniform_random_number_dbg: $(SRC_DIR)/nonuniform_random_number.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
nonuniform_random_number_dbg: $(BUILD_DIR)/nonuniform_random_number_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: nonuniform_random_number nonuniform_random_number_dbg


# number_of_score_combinations.cc

$(BUILD_DIR)/number_of_score_combinations: $(SRC_DIR)/number_of_score_combinations.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
number_of_score_combinations: $(BUILD_DIR)/number_of_score_combinations
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/number_of_score_combinations_dbg: $(SRC_DIR)/number_of_score_combinations.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
number_of_score_combinations_dbg: $(BUILD_DIR)/number_of_score_combinations_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: number_of_score_combinations number_of_score_combinations_dbg


# number_of_traversals_matrix.cc

$(BUILD_DIR)/number_of_traversals_matrix: $(SRC_DIR)/number_of_traversals_matrix.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
number_of_traversals_matrix: $(BUILD_DIR)/number_of_traversals_matrix
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/number_of_traversals_matrix_dbg: $(SRC_DIR)/number_of_traversals_matrix.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
number_of_traversals_matrix_dbg: $(BUILD_DIR)/number_of_traversals_matrix_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: number_of_traversals_matrix number_of_traversals_matrix_dbg


# number_of_traversals_staircase.cc

$(BUILD_DIR)/number_of_traversals_staircase: $(SRC_DIR)/number_of_traversals_staircase.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
number_of_traversals_staircase: $(BUILD_DIR)/number_of_traversals_staircase
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/number_of_traversals_staircase_dbg: $(SRC_DIR)/number_of_traversals_staircase.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
number_of_traversals_staircase_dbg: $(BUILD_DIR)/number_of_traversals_staircase_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: number_of_traversals_staircase number_of_traversals_staircase_dbg


# offline_sampling.cc

$(BUILD_DIR)/offline_sampling: $(SRC_DIR)/offline_sampling.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
offline_sampling: $(BUILD_DIR)/offline_sampling
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/offline_sampling_dbg: $(SRC_DIR)/offline_sampling.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
offline_sampling_dbg: $(BUILD_DIR)/offline_sampling_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: offline_sampling offline_sampling_dbg


# online_median.cc

$(BUILD_DIR)/online_median: $(SRC_DIR)/online_median.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
online_median: $(BUILD_DIR)/online_median
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/online_median_dbg: $(SRC_DIR)/online_median.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
online_median_dbg: $(BUILD_DIR)/online_median_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: online_median online_median_dbg


# online_sampling.cc

$(BUILD_DIR)/online_sampling: $(SRC_DIR)/online_sampling.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
online_sampling: $(BUILD_DIR)/online_sampling
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/online_sampling_dbg: $(SRC_DIR)/online_sampling.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
online_sampling_dbg: $(BUILD_DIR)/online_sampling_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: online_sampling online_sampling_dbg


# parity.cc

$(BUILD_DIR)/parity: $(SRC_DIR)/parity.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
parity: $(BUILD_DIR)/parity
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/parity_dbg: $(SRC_DIR)/parity.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
parity_dbg: $(BUILD_DIR)/parity_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: parity parity_dbg


# pascal_triangle.cc

$(BUILD_DIR)/pascal_triangle: $(SRC_DIR)/pascal_triangle.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
pascal_triangle: $(BUILD_DIR)/pascal_triangle
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/pascal_triangle_dbg: $(SRC_DIR)/pascal_triangle.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
pascal_triangle_dbg: $(BUILD_DIR)/pascal_triangle_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: pascal_triangle pascal_triangle_dbg


# path_sum.cc

$(BUILD_DIR)/path_sum: $(SRC_DIR)/path_sum.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
path_sum: $(BUILD_DIR)/path_sum
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/path_sum_dbg: $(SRC_DIR)/path_sum.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
path_sum_dbg: $(BUILD_DIR)/path_sum_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: path_sum path_sum_dbg


# permutations.cc

$(BUILD_DIR)/permutations: $(SRC_DIR)/permutations.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
permutations: $(BUILD_DIR)/permutations
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/permutations_dbg: $(SRC_DIR)/permutations.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
permutations_dbg: $(BUILD_DIR)/permutations_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: permutations permutations_dbg


# phone_number_mnemonic.cc

$(BUILD_DIR)/phone_number_mnemonic: $(SRC_DIR)/phone_number_mnemonic.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
phone_number_mnemonic: $(BUILD_DIR)/phone_number_mnemonic
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/phone_number_mnemonic_dbg: $(SRC_DIR)/phone_number_mnemonic.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
phone_number_mnemonic_dbg: $(BUILD_DIR)/phone_number_mnemonic_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: phone_number_mnemonic phone_number_mnemonic_dbg


# picking_up_coins.cc

$(BUILD_DIR)/picking_up_coins: $(SRC_DIR)/picking_up_coins.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
picking_up_coins: $(BUILD_DIR)/picking_up_coins
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/picking_up_coins_dbg: $(SRC_DIR)/picking_up_coins.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
picking_up_coins_dbg: $(BUILD_DIR)/picking_up_coins_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: picking_up_coins picking_up_coins_dbg


# pivot_list.cc

$(BUILD_DIR)/pivot_list: $(SRC_DIR)/pivot_list.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
pivot_list: $(BUILD_DIR)/pivot_list
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/pivot_list_dbg: $(SRC_DIR)/pivot_list.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
pivot_list_dbg: $(BUILD_DIR)/pivot_list_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: pivot_list pivot_list_dbg


# power_set.cc

$(BUILD_DIR)/power_set: $(SRC_DIR)/power_set.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
power_set: $(BUILD_DIR)/power_set
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/power_set_dbg: $(SRC_DIR)/power_set.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
power_set_dbg: $(BUILD_DIR)/power_set_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: power_set power_set_dbg


# power_x_y.cc

$(BUILD_DIR)/power_x_y: $(SRC_DIR)/power_x_y.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
power_x_y: $(BUILD_DIR)/power_x_y
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/power_x_y_dbg: $(SRC_DIR)/power_x_y.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
power_x_y_dbg: $(BUILD_DIR)/power_x_y_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: power_x_y power_x_y_dbg


# pretty_printing.cc

$(BUILD_DIR)/pretty_printing: $(SRC_DIR)/pretty_printing.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
pretty_printing: $(BUILD_DIR)/pretty_printing
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/pretty_printing_dbg: $(SRC_DIR)/pretty_printing.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
pretty_printing_dbg: $(BUILD_DIR)/pretty_printing_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: pretty_printing pretty_printing_dbg


# prime_sieve.cc

$(BUILD_DIR)/prime_sieve: $(SRC_DIR)/prime_sieve.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
prime_sieve: $(BUILD_DIR)/prime_sieve
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/prime_sieve_dbg: $(SRC_DIR)/prime_sieve.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
prime_sieve_dbg: $(BUILD_DIR)/prime_sieve_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: prime_sieve prime_sieve_dbg


# primitive_divide.cc

$(BUILD_DIR)/primitive_divide: $(SRC_DIR)/primitive_divide.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
primitive_divide: $(BUILD_DIR)/primitive_divide
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/primitive_divide_dbg: $(SRC_DIR)/primitive_divide.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
primitive_divide_dbg: $(BUILD_DIR)/primitive_divide_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: primitive_divide primitive_divide_dbg


# primitive_multiply.cc

$(BUILD_DIR)/primitive_multiply: $(SRC_DIR)/primitive_multiply.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
primitive_multiply: $(BUILD_DIR)/primitive_multiply
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/primitive_multiply_dbg: $(SRC_DIR)/primitive_multiply.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
primitive_multiply_dbg: $(BUILD_DIR)/primitive_multiply_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: primitive_multiply primitive_multiply_dbg


# queue_from_stacks.cc

$(BUILD_DIR)/queue_from_stacks: $(SRC_DIR)/queue_from_stacks.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
queue_from_stacks: $(BUILD_DIR)/queue_from_stacks
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/queue_from_stacks_dbg: $(SRC_DIR)/queue_from_stacks.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
queue_from_stacks_dbg: $(BUILD_DIR)/queue_from_stacks_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: queue_from_stacks queue_from_stacks_dbg


# queue_with_max.cc

$(BUILD_DIR)/queue_with_max: $(SRC_DIR)/queue_with_max.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
queue_with_max: $(BUILD_DIR)/queue_with_max
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/queue_with_max_dbg: $(SRC_DIR)/queue_with_max.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
queue_with_max_dbg: $(BUILD_DIR)/queue_with_max_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: queue_with_max queue_with_max_dbg


# random_permutation.cc

$(BUILD_DIR)/random_permutation: $(SRC_DIR)/random_permutation.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
random_permutation: $(BUILD_DIR)/random_permutation
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/random_permutation_dbg: $(SRC_DIR)/random_permutation.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
random_permutation_dbg: $(BUILD_DIR)/random_permutation_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: random_permutation random_permutation_dbg


# random_subset.cc

$(BUILD_DIR)/random_subset: $(SRC_DIR)/random_subset.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
random_subset: $(BUILD_DIR)/random_subset
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/random_subset_dbg: $(SRC_DIR)/random_subset.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
random_subset_dbg: $(BUILD_DIR)/random_subset_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: random_subset random_subset_dbg


# real_square_root.cc

$(BUILD_DIR)/real_square_root: $(SRC_DIR)/real_square_root.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
real_square_root: $(BUILD_DIR)/real_square_root
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/real_square_root_dbg: $(SRC_DIR)/real_square_root.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
real_square_root_dbg: $(BUILD_DIR)/real_square_root_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: real_square_root real_square_root_dbg


# rectangle_intersection.cc

$(BUILD_DIR)/rectangle_intersection: $(SRC_DIR)/rectangle_intersection.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
rectangle_intersection: $(BUILD_DIR)/rectangle_intersection
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/rectangle_intersection_dbg: $(SRC_DIR)/rectangle_intersection.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
rectangle_intersection_dbg: $(BUILD_DIR)/rectangle_intersection_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: rectangle_intersection rectangle_intersection_dbg


# refueling_schedule.cc

$(BUILD_DIR)/refueling_schedule: $(SRC_DIR)/refueling_schedule.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
refueling_schedule: $(BUILD_DIR)/refueling_schedule
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/refueling_schedule_dbg: $(SRC_DIR)/refueling_schedule.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
refueling_schedule_dbg: $(BUILD_DIR)/refueling_schedule_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: refueling_schedule refueling_schedule_dbg


# regular_expression.cc

$(BUILD_DIR)/regular_expression: $(SRC_DIR)/regular_expression.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
regular_expression: $(BUILD_DIR)/regular_expression
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/regular_expression_dbg: $(SRC_DIR)/regular_expression.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
regular_expression_dbg: $(BUILD_DIR)/regular_expression_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: regular_expression regular_expression_dbg


# remove_duplicates.cc

$(BUILD_DIR)/remove_duplicates: $(SRC_DIR)/remove_duplicates.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
remove_duplicates: $(BUILD_DIR)/remove_duplicates
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/remove_duplicates_dbg: $(SRC_DIR)/remove_duplicates.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
remove_duplicates_dbg: $(BUILD_DIR)/remove_duplicates_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: remove_duplicates remove_duplicates_dbg


# remove_duplicates_from_sorted_list.cc

$(BUILD_DIR)/remove_duplicates_from_sorted_list: $(SRC_DIR)/remove_duplicates_from_sorted_list.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
remove_duplicates_from_sorted_list: $(BUILD_DIR)/remove_duplicates_from_sorted_list
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/remove_duplicates_from_sorted_list_dbg: $(SRC_DIR)/remove_duplicates_from_sorted_list.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
remove_duplicates_from_sorted_list_dbg: $(BUILD_DIR)/remove_duplicates_from_sorted_list_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: remove_duplicates_from_sorted_list remove_duplicates_from_sorted_list_dbg


# replace_and_remove.cc

$(BUILD_DIR)/replace_and_remove: $(SRC_DIR)/replace_and_remove.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
replace_and_remove: $(BUILD_DIR)/replace_and_remove
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/replace_and_remove_dbg: $(SRC_DIR)/replace_and_remove.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
replace_and_remove_dbg: $(BUILD_DIR)/replace_and_remove_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: replace_and_remove replace_and_remove_dbg


# reverse_bits.cc

$(BUILD_DIR)/reverse_bits: $(SRC_DIR)/reverse_bits.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
reverse_bits: $(BUILD_DIR)/reverse_bits
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/reverse_bits_dbg: $(SRC_DIR)/reverse_bits.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
reverse_bits_dbg: $(BUILD_DIR)/reverse_bits_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: reverse_bits reverse_bits_dbg


# reverse_digits.cc

$(BUILD_DIR)/reverse_digits: $(SRC_DIR)/reverse_digits.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
reverse_digits: $(BUILD_DIR)/reverse_digits
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/reverse_digits_dbg: $(SRC_DIR)/reverse_digits.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
reverse_digits_dbg: $(BUILD_DIR)/reverse_digits_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: reverse_digits reverse_digits_dbg


# reverse_sublist.cc

$(BUILD_DIR)/reverse_sublist: $(SRC_DIR)/reverse_sublist.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
reverse_sublist: $(BUILD_DIR)/reverse_sublist
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/reverse_sublist_dbg: $(SRC_DIR)/reverse_sublist.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
reverse_sublist_dbg: $(BUILD_DIR)/reverse_sublist_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: reverse_sublist reverse_sublist_dbg


# reverse_words.cc

$(BUILD_DIR)/reverse_words: $(SRC_DIR)/reverse_words.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
reverse_words: $(BUILD_DIR)/reverse_words
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/reverse_words_dbg: $(SRC_DIR)/reverse_words.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
reverse_words_dbg: $(BUILD_DIR)/reverse_words_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: reverse_words reverse_words_dbg


# road_network.cc

$(BUILD_DIR)/road_network: $(SRC_DIR)/road_network.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
road_network: $(BUILD_DIR)/road_network
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/road_network_dbg: $(SRC_DIR)/road_network.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
road_network_dbg: $(BUILD_DIR)/road_network_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: road_network road_network_dbg


# roman_to_integer.cc

$(BUILD_DIR)/roman_to_integer: $(SRC_DIR)/roman_to_integer.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
roman_to_integer: $(BUILD_DIR)/roman_to_integer
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/roman_to_integer_dbg: $(SRC_DIR)/roman_to_integer.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
roman_to_integer_dbg: $(BUILD_DIR)/roman_to_integer_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: roman_to_integer roman_to_integer_dbg


# rook_attack.cc

$(BUILD_DIR)/rook_attack: $(SRC_DIR)/rook_attack.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
rook_attack: $(BUILD_DIR)/rook_attack
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/rook_attack_dbg: $(SRC_DIR)/rook_attack.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
rook_attack_dbg: $(BUILD_DIR)/rook_attack_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: rook_attack rook_attack_dbg


# rotate_array.cc

$(BUILD_DIR)/rotate_array: $(SRC_DIR)/rotate_array.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
rotate_array: $(BUILD_DIR)/rotate_array
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/rotate_array_dbg: $(SRC_DIR)/rotate_array.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
rotate_array_dbg: $(BUILD_DIR)/rotate_array_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: rotate_array rotate_array_dbg


# run_length_compression.cc

$(BUILD_DIR)/run_length_compression: $(SRC_DIR)/run_length_compression.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
run_length_compression: $(BUILD_DIR)/run_length_compression
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/run_length_compression_dbg: $(SRC_DIR)/run_length_compression.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
run_length_compression_dbg: $(BUILD_DIR)/run_length_compression_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: run_length_compression run_length_compression_dbg


# search_entry_equal_to_index.cc

$(BUILD_DIR)/search_entry_equal_to_index: $(SRC_DIR)/search_entry_equal_to_index.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
search_entry_equal_to_index: $(BUILD_DIR)/search_entry_equal_to_index
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/search_entry_equal_to_index_dbg: $(SRC_DIR)/search_entry_equal_to_index.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
search_entry_equal_to_index_dbg: $(BUILD_DIR)/search_entry_equal_to_index_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: search_entry_equal_to_index search_entry_equal_to_index_dbg


# search_first_greater_value_in_bst.cc

$(BUILD_DIR)/search_first_greater_value_in_bst: $(SRC_DIR)/search_first_greater_value_in_bst.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
search_first_greater_value_in_bst: $(BUILD_DIR)/search_first_greater_value_in_bst
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/search_first_greater_value_in_bst_dbg: $(SRC_DIR)/search_first_greater_value_in_bst.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
search_first_greater_value_in_bst_dbg: $(BUILD_DIR)/search_first_greater_value_in_bst_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: search_first_greater_value_in_bst search_first_greater_value_in_bst_dbg


# search_first_key.cc

$(BUILD_DIR)/search_first_key: $(SRC_DIR)/search_first_key.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
search_first_key: $(BUILD_DIR)/search_first_key
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/search_first_key_dbg: $(SRC_DIR)/search_first_key.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
search_first_key_dbg: $(BUILD_DIR)/search_first_key_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: search_first_key search_first_key_dbg


# search_for_min_max_in_array.cc

$(BUILD_DIR)/search_for_min_max_in_array: $(SRC_DIR)/search_for_min_max_in_array.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
search_for_min_max_in_array: $(BUILD_DIR)/search_for_min_max_in_array
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/search_for_min_max_in_array_dbg: $(SRC_DIR)/search_for_min_max_in_array.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
search_for_min_max_in_array_dbg: $(BUILD_DIR)/search_for_min_max_in_array_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: search_for_min_max_in_array search_for_min_max_in_array_dbg


# search_for_missing_element.cc

$(BUILD_DIR)/search_for_missing_element: $(SRC_DIR)/search_for_missing_element.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
search_for_missing_element: $(BUILD_DIR)/search_for_missing_element
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/search_for_missing_element_dbg: $(SRC_DIR)/search_for_missing_element.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
search_for_missing_element_dbg: $(BUILD_DIR)/search_for_missing_element_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: search_for_missing_element search_for_missing_element_dbg


# search_frequent_items.cc

$(BUILD_DIR)/search_frequent_items: $(SRC_DIR)/search_frequent_items.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
search_frequent_items: $(BUILD_DIR)/search_frequent_items
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/search_frequent_items_dbg: $(SRC_DIR)/search_frequent_items.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
search_frequent_items_dbg: $(BUILD_DIR)/search_frequent_items_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: search_frequent_items search_frequent_items_dbg


# search_in_list.cc

$(BUILD_DIR)/search_in_list: $(SRC_DIR)/search_in_list.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
search_in_list: $(BUILD_DIR)/search_in_list
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/search_in_list_dbg: $(SRC_DIR)/search_in_list.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
search_in_list_dbg: $(BUILD_DIR)/search_in_list_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: search_in_list search_in_list_dbg


# search_maze.cc

$(BUILD_DIR)/search_maze: $(SRC_DIR)/search_maze.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
search_maze: $(BUILD_DIR)/search_maze
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/search_maze_dbg: $(SRC_DIR)/search_maze.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
search_maze_dbg: $(BUILD_DIR)/search_maze_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: search_maze search_maze_dbg


# search_row_col_sorted_matrix.cc

$(BUILD_DIR)/search_row_col_sorted_matrix: $(SRC_DIR)/search_row_col_sorted_matrix.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
search_row_col_sorted_matrix: $(BUILD_DIR)/search_row_col_sorted_matrix
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/search_row_col_sorted_matrix_dbg: $(SRC_DIR)/search_row_col_sorted_matrix.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
search_row_col_sorted_matrix_dbg: $(BUILD_DIR)/search_row_col_sorted_matrix_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: search_row_col_sorted_matrix search_row_col_sorted_matrix_dbg


# search_shifted_sorted_array.cc

$(BUILD_DIR)/search_shifted_sorted_array: $(SRC_DIR)/search_shifted_sorted_array.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
search_shifted_sorted_array: $(BUILD_DIR)/search_shifted_sorted_array
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/search_shifted_sorted_array_dbg: $(SRC_DIR)/search_shifted_sorted_array.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
search_shifted_sorted_array_dbg: $(BUILD_DIR)/search_shifted_sorted_array_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: search_shifted_sorted_array search_shifted_sorted_array_dbg


# search_unknown_length_array.cc

$(BUILD_DIR)/search_unknown_length_array: $(SRC_DIR)/search_unknown_length_array.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
search_unknown_length_array: $(BUILD_DIR)/search_unknown_length_array
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/search_unknown_length_array_dbg: $(SRC_DIR)/search_unknown_length_array.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
search_unknown_length_array_dbg: $(BUILD_DIR)/search_unknown_length_array_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: search_unknown_length_array search_unknown_length_array_dbg


# smallest_nonconstructible_value.cc

$(BUILD_DIR)/smallest_nonconstructible_value: $(SRC_DIR)/smallest_nonconstructible_value.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
smallest_nonconstructible_value: $(BUILD_DIR)/smallest_nonconstructible_value
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/smallest_nonconstructible_value_dbg: $(SRC_DIR)/smallest_nonconstructible_value.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
smallest_nonconstructible_value_dbg: $(BUILD_DIR)/smallest_nonconstructible_value_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: smallest_nonconstructible_value smallest_nonconstructible_value_dbg


# smallest_subarray_covering_all_values.cc

$(BUILD_DIR)/smallest_subarray_covering_all_values: $(SRC_DIR)/smallest_subarray_covering_all_values.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
smallest_subarray_covering_all_values: $(BUILD_DIR)/smallest_subarray_covering_all_values
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/smallest_subarray_covering_all_values_dbg: $(SRC_DIR)/smallest_subarray_covering_all_values.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
smallest_subarray_covering_all_values_dbg: $(BUILD_DIR)/smallest_subarray_covering_all_values_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: smallest_subarray_covering_all_values smallest_subarray_covering_all_values_dbg


# smallest_subarray_covering_set.cc

$(BUILD_DIR)/smallest_subarray_covering_set: $(SRC_DIR)/smallest_subarray_covering_set.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
smallest_subarray_covering_set: $(BUILD_DIR)/smallest_subarray_covering_set
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/smallest_subarray_covering_set_dbg: $(SRC_DIR)/smallest_subarray_covering_set.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
smallest_subarray_covering_set_dbg: $(BUILD_DIR)/smallest_subarray_covering_set_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: smallest_subarray_covering_set smallest_subarray_covering_set_dbg


# snake_string.cc

$(BUILD_DIR)/snake_string: $(SRC_DIR)/snake_string.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
snake_string: $(BUILD_DIR)/snake_string
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/snake_string_dbg: $(SRC_DIR)/snake_string.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
snake_string_dbg: $(BUILD_DIR)/snake_string_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: snake_string snake_string_dbg


# sort_almost_sorted_array.cc

$(BUILD_DIR)/sort_almost_sorted_array: $(SRC_DIR)/sort_almost_sorted_array.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
sort_almost_sorted_array: $(BUILD_DIR)/sort_almost_sorted_array
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/sort_almost_sorted_array_dbg: $(SRC_DIR)/sort_almost_sorted_array.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
sort_almost_sorted_array_dbg: $(BUILD_DIR)/sort_almost_sorted_array_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: sort_almost_sorted_array sort_almost_sorted_array_dbg


# sort_increasing_decreasing_array.cc

$(BUILD_DIR)/sort_increasing_decreasing_array: $(SRC_DIR)/sort_increasing_decreasing_array.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
sort_increasing_decreasing_array: $(BUILD_DIR)/sort_increasing_decreasing_array
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/sort_increasing_decreasing_array_dbg: $(SRC_DIR)/sort_increasing_decreasing_array.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
sort_increasing_decreasing_array_dbg: $(BUILD_DIR)/sort_increasing_decreasing_array_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: sort_increasing_decreasing_array sort_increasing_decreasing_array_dbg


# sort_list.cc

$(BUILD_DIR)/sort_list: $(SRC_DIR)/sort_list.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
sort_list: $(BUILD_DIR)/sort_list
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/sort_list_dbg: $(SRC_DIR)/sort_list.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
sort_list_dbg: $(BUILD_DIR)/sort_list_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: sort_list sort_list_dbg


# sorted_array_remove_dups.cc

$(BUILD_DIR)/sorted_array_remove_dups: $(SRC_DIR)/sorted_array_remove_dups.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
sorted_array_remove_dups: $(BUILD_DIR)/sorted_array_remove_dups
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/sorted_array_remove_dups_dbg: $(SRC_DIR)/sorted_array_remove_dups.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
sorted_array_remove_dups_dbg: $(BUILD_DIR)/sorted_array_remove_dups_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: sorted_array_remove_dups sorted_array_remove_dups_dbg


# sorted_arrays_merge.cc

$(BUILD_DIR)/sorted_arrays_merge: $(SRC_DIR)/sorted_arrays_merge.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
sorted_arrays_merge: $(BUILD_DIR)/sorted_arrays_merge
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/sorted_arrays_merge_dbg: $(SRC_DIR)/sorted_arrays_merge.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
sorted_arrays_merge_dbg: $(BUILD_DIR)/sorted_arrays_merge_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: sorted_arrays_merge sorted_arrays_merge_dbg


# sorted_list_to_bst.cc

$(BUILD_DIR)/sorted_list_to_bst: $(SRC_DIR)/sorted_list_to_bst.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
sorted_list_to_bst: $(BUILD_DIR)/sorted_list_to_bst
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/sorted_list_to_bst_dbg: $(SRC_DIR)/sorted_list_to_bst.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
sorted_list_to_bst_dbg: $(BUILD_DIR)/sorted_list_to_bst_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: sorted_list_to_bst sorted_list_to_bst_dbg


# sorted_lists_merge.cc

$(BUILD_DIR)/sorted_lists_merge: $(SRC_DIR)/sorted_lists_merge.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
sorted_lists_merge: $(BUILD_DIR)/sorted_lists_merge
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/sorted_lists_merge_dbg: $(SRC_DIR)/sorted_lists_merge.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
sorted_lists_merge_dbg: $(BUILD_DIR)/sorted_lists_merge_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: sorted_lists_merge sorted_lists_merge_dbg


# spiral_ordering_segments.cc

$(BUILD_DIR)/spiral_ordering_segments: $(SRC_DIR)/spiral_ordering_segments.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
spiral_ordering_segments: $(BUILD_DIR)/spiral_ordering_segments
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/spiral_ordering_segments_dbg: $(SRC_DIR)/spiral_ordering_segments.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
spiral_ordering_segments_dbg: $(BUILD_DIR)/spiral_ordering_segments_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: spiral_ordering_segments spiral_ordering_segments_dbg


# spreadsheet_encoding.cc

$(BUILD_DIR)/spreadsheet_encoding: $(SRC_DIR)/spreadsheet_encoding.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
spreadsheet_encoding: $(BUILD_DIR)/spreadsheet_encoding
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/spreadsheet_encoding_dbg: $(SRC_DIR)/spreadsheet_encoding.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
spreadsheet_encoding_dbg: $(BUILD_DIR)/spreadsheet_encoding_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: spreadsheet_encoding spreadsheet_encoding_dbg


# stack_with_max.cc

$(BUILD_DIR)/stack_with_max: $(SRC_DIR)/stack_with_max.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
stack_with_max: $(BUILD_DIR)/stack_with_max
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/stack_with_max_dbg: $(SRC_DIR)/stack_with_max.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
stack_with_max_dbg: $(BUILD_DIR)/stack_with_max_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: stack_with_max stack_with_max_dbg


# string_decompositions_into_dictionary_words.cc

$(BUILD_DIR)/string_decompositions_into_dictionary_words: $(SRC_DIR)/string_decompositions_into_dictionary_words.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
string_decompositions_into_dictionary_words: $(BUILD_DIR)/string_decompositions_into_dictionary_words
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/string_decompositions_into_dictionary_words_dbg: $(SRC_DIR)/string_decompositions_into_dictionary_words.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
string_decompositions_into_dictionary_words_dbg: $(BUILD_DIR)/string_decompositions_into_dictionary_words_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: string_decompositions_into_dictionary_words string_decompositions_into_dictionary_words_dbg


# string_integer_interconversion.cc

$(BUILD_DIR)/string_integer_interconversion: $(SRC_DIR)/string_integer_interconversion.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
string_integer_interconversion: $(BUILD_DIR)/string_integer_interconversion
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/string_integer_interconversion_dbg: $(SRC_DIR)/string_integer_interconversion.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
string_integer_interconversion_dbg: $(BUILD_DIR)/string_integer_interconversion_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: string_integer_interconversion string_integer_interconversion_dbg


# string_transformability.cc

$(BUILD_DIR)/string_transformability: $(SRC_DIR)/string_transformability.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
string_transformability: $(BUILD_DIR)/string_transformability
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/string_transformability_dbg: $(SRC_DIR)/string_transformability.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
string_transformability_dbg: $(BUILD_DIR)/string_transformability_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: string_transformability string_transformability_dbg


# substring_match.cc

$(BUILD_DIR)/substring_match: $(SRC_DIR)/substring_match.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
substring_match: $(BUILD_DIR)/substring_match
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/substring_match_dbg: $(SRC_DIR)/substring_match.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
substring_match_dbg: $(BUILD_DIR)/substring_match_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: substring_match substring_match_dbg


# successor_in_tree.cc

$(BUILD_DIR)/successor_in_tree: $(SRC_DIR)/successor_in_tree.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
successor_in_tree: $(BUILD_DIR)/successor_in_tree
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/successor_in_tree_dbg: $(SRC_DIR)/successor_in_tree.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
successor_in_tree_dbg: $(BUILD_DIR)/successor_in_tree_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: successor_in_tree successor_in_tree_dbg


# sudoku_solve.cc

$(BUILD_DIR)/sudoku_solve: $(SRC_DIR)/sudoku_solve.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
sudoku_solve: $(BUILD_DIR)/sudoku_solve
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/sudoku_solve_dbg: $(SRC_DIR)/sudoku_solve.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
sudoku_solve_dbg: $(BUILD_DIR)/sudoku_solve_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: sudoku_solve sudoku_solve_dbg


# sum_root_to_leaf.cc

$(BUILD_DIR)/sum_root_to_leaf: $(SRC_DIR)/sum_root_to_leaf.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
sum_root_to_leaf: $(BUILD_DIR)/sum_root_to_leaf
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/sum_root_to_leaf_dbg: $(SRC_DIR)/sum_root_to_leaf.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
sum_root_to_leaf_dbg: $(BUILD_DIR)/sum_root_to_leaf_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: sum_root_to_leaf sum_root_to_leaf_dbg


# sunset_view.cc

$(BUILD_DIR)/sunset_view: $(SRC_DIR)/sunset_view.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
sunset_view: $(BUILD_DIR)/sunset_view
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/sunset_view_dbg: $(SRC_DIR)/sunset_view.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
sunset_view_dbg: $(BUILD_DIR)/sunset_view_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: sunset_view sunset_view_dbg


# swap_bits.cc

$(BUILD_DIR)/swap_bits: $(SRC_DIR)/swap_bits.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
swap_bits: $(BUILD_DIR)/swap_bits
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/swap_bits_dbg: $(SRC_DIR)/swap_bits.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
swap_bits_dbg: $(BUILD_DIR)/swap_bits_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: swap_bits swap_bits_dbg


# task_pairing.cc

$(BUILD_DIR)/task_pairing: $(SRC_DIR)/task_pairing.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
task_pairing: $(BUILD_DIR)/task_pairing
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/task_pairing_dbg: $(SRC_DIR)/task_pairing.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
task_pairing_dbg: $(BUILD_DIR)/task_pairing_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: task_pairing task_pairing_dbg


# three_sum.cc

$(BUILD_DIR)/three_sum: $(SRC_DIR)/three_sum.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
three_sum: $(BUILD_DIR)/three_sum
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/three_sum_dbg: $(SRC_DIR)/three_sum.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
three_sum_dbg: $(BUILD_DIR)/three_sum_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: three_sum three_sum_dbg


# tree_connect_leaves.cc

$(BUILD_DIR)/tree_connect_leaves: $(SRC_DIR)/tree_connect_leaves.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
tree_connect_leaves: $(BUILD_DIR)/tree_connect_leaves
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/tree_connect_leaves_dbg: $(SRC_DIR)/tree_connect_leaves.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
tree_connect_leaves_dbg: $(BUILD_DIR)/tree_connect_leaves_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: tree_connect_leaves tree_connect_leaves_dbg


# tree_exterior.cc

$(BUILD_DIR)/tree_exterior: $(SRC_DIR)/tree_exterior.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
tree_exterior: $(BUILD_DIR)/tree_exterior
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/tree_exterior_dbg: $(SRC_DIR)/tree_exterior.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
tree_exterior_dbg: $(BUILD_DIR)/tree_exterior_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: tree_exterior tree_exterior_dbg


# tree_from_preorder_inorder.cc

$(BUILD_DIR)/tree_from_preorder_inorder: $(SRC_DIR)/tree_from_preorder_inorder.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
tree_from_preorder_inorder: $(BUILD_DIR)/tree_from_preorder_inorder
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/tree_from_preorder_inorder_dbg: $(SRC_DIR)/tree_from_preorder_inorder.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
tree_from_preorder_inorder_dbg: $(BUILD_DIR)/tree_from_preorder_inorder_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: tree_from_preorder_inorder tree_from_preorder_inorder_dbg


# tree_from_preorder_with_null.cc

$(BUILD_DIR)/tree_from_preorder_with_null: $(SRC_DIR)/tree_from_preorder_with_null.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
tree_from_preorder_with_null: $(BUILD_DIR)/tree_from_preorder_with_null
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/tree_from_preorder_with_null_dbg: $(SRC_DIR)/tree_from_preorder_with_null.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
tree_from_preorder_with_null_dbg: $(BUILD_DIR)/tree_from_preorder_with_null_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: tree_from_preorder_with_null tree_from_preorder_with_null_dbg


# tree_inorder.cc

$(BUILD_DIR)/tree_inorder: $(SRC_DIR)/tree_inorder.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
tree_inorder: $(BUILD_DIR)/tree_inorder
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/tree_inorder_dbg: $(SRC_DIR)/tree_inorder.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
tree_inorder_dbg: $(BUILD_DIR)/tree_inorder_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: tree_inorder tree_inorder_dbg


# tree_level_order.cc

$(BUILD_DIR)/tree_level_order: $(SRC_DIR)/tree_level_order.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
tree_level_order: $(BUILD_DIR)/tree_level_order
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/tree_level_order_dbg: $(SRC_DIR)/tree_level_order.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
tree_level_order_dbg: $(BUILD_DIR)/tree_level_order_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: tree_level_order tree_level_order_dbg


# tree_postorder.cc

$(BUILD_DIR)/tree_postorder: $(SRC_DIR)/tree_postorder.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
tree_postorder: $(BUILD_DIR)/tree_postorder
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/tree_postorder_dbg: $(SRC_DIR)/tree_postorder.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
tree_postorder_dbg: $(BUILD_DIR)/tree_postorder_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: tree_postorder tree_postorder_dbg


# tree_preorder.cc

$(BUILD_DIR)/tree_preorder: $(SRC_DIR)/tree_preorder.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
tree_preorder: $(BUILD_DIR)/tree_preorder
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/tree_preorder_dbg: $(SRC_DIR)/tree_preorder.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
tree_preorder_dbg: $(BUILD_DIR)/tree_preorder_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: tree_preorder tree_preorder_dbg


# tree_right_sibling.cc

$(BUILD_DIR)/tree_right_sibling: $(SRC_DIR)/tree_right_sibling.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
tree_right_sibling: $(BUILD_DIR)/tree_right_sibling
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/tree_right_sibling_dbg: $(SRC_DIR)/tree_right_sibling.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
tree_right_sibling_dbg: $(BUILD_DIR)/tree_right_sibling_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: tree_right_sibling tree_right_sibling_dbg


# tree_with_parent_inorder.cc

$(BUILD_DIR)/tree_with_parent_inorder: $(SRC_DIR)/tree_with_parent_inorder.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
tree_with_parent_inorder: $(BUILD_DIR)/tree_with_parent_inorder
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/tree_with_parent_inorder_dbg: $(SRC_DIR)/tree_with_parent_inorder.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
tree_with_parent_inorder_dbg: $(BUILD_DIR)/tree_with_parent_inorder_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: tree_with_parent_inorder tree_with_parent_inorder_dbg


# two_sum.cc

$(BUILD_DIR)/two_sum: $(SRC_DIR)/two_sum.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
two_sum: $(BUILD_DIR)/two_sum
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/two_sum_dbg: $(SRC_DIR)/two_sum.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
two_sum_dbg: $(BUILD_DIR)/two_sum_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: two_sum two_sum_dbg


# uniform_random_number.cc

$(BUILD_DIR)/uniform_random_number: $(SRC_DIR)/uniform_random_number.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
uniform_random_number: $(BUILD_DIR)/uniform_random_number
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/uniform_random_number_dbg: $(SRC_DIR)/uniform_random_number.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
uniform_random_number_dbg: $(BUILD_DIR)/uniform_random_number_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: uniform_random_number uniform_random_number_dbg


# valid_ip_addresses.cc

$(BUILD_DIR)/valid_ip_addresses: $(SRC_DIR)/valid_ip_addresses.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
valid_ip_addresses: $(BUILD_DIR)/valid_ip_addresses
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/valid_ip_addresses_dbg: $(SRC_DIR)/valid_ip_addresses.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
valid_ip_addresses_dbg: $(BUILD_DIR)/valid_ip_addresses_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: valid_ip_addresses valid_ip_addresses_dbg


# zip_list.cc

$(BUILD_DIR)/zip_list: $(SRC_DIR)/zip_list.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_RELEASE) -o $@ $<
zip_list: $(BUILD_DIR)/zip_list
	$< --test_data_dir $(TEST_DATA_DIR)

$(BUILD_DIR)/zip_list_dbg: $(SRC_DIR)/zip_list.cc $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
zip_list_dbg: $(BUILD_DIR)/zip_list_dbg
	$< --test_data_dir $(TEST_DATA_DIR)

.PHONY: zip_list zip_list_dbg
