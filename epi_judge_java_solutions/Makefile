# Compile and run by "make <program_name>"
# For example, typing "make Parity" in your terminal will compile and run Parity.java.
#
# You could try "make last" (or simply "make"), this command will compile and run the last modified file.
# This comes pretty handy while you are working a problem, and then you want to see the result soon without thinking program name.
BUILD_DIR := java_build
SRC_DIR := .
TEST_DATA_DIR := ../test_data

# Modify this line if you want to pass custom arguments
PROGRAM_ARGS := --test-data-dir $(TEST_DATA_DIR) 

ifdef ComSpec # Running on Windows
	JAVAC_CMD := javac -parameters -d "$(BUILD_DIR)" -cp "$(BUILD_DIR);."
	RUN_CMD := java -cp "$(BUILD_DIR)" -Djava.library.path="$(SRC_DIR)/epi/test_framework/"
else
	JAVAC_CMD := javac -parameters -d "$(BUILD_DIR)" -cp "$(BUILD_DIR):."
	RUN_CMD := java -cp "$(BUILD_DIR)"
endif

MAIN_PACKAGE := epi

LAST_MODIFIED_JAVA_FILE = $(shell ls -rt $(SRC_DIR)/$(MAIN_PACKAGE)/*\.java | tail -1)

# Compile and run the last modified file.
.PHONY: last
last: $(notdir $(basename $(LAST_MODIFIED_JAVA_FILE)))


$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/$(MAIN_PACKAGE)/BinaryTree.class : $(SRC_DIR)/$(MAIN_PACKAGE)/BinaryTree.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/BinaryTree.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/BinaryTreeNode.class : $(SRC_DIR)/$(MAIN_PACKAGE)/BinaryTreeNode.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/BinaryTreeNode.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/BstNode.class : $(SRC_DIR)/$(MAIN_PACKAGE)/BstNode.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/BstNode.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/DoublyListNode.class : $(SRC_DIR)/$(MAIN_PACKAGE)/DoublyListNode.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/DoublyListNode.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/ListNode.class : $(SRC_DIR)/$(MAIN_PACKAGE)/ListNode.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/ListNode.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/PostingListNode.class : $(SRC_DIR)/$(MAIN_PACKAGE)/PostingListNode.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/PostingListNode.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/TreeLike.class : $(SRC_DIR)/$(MAIN_PACKAGE)/TreeLike.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/TreeLike.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/BinaryTreeUtils.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/BinaryTreeUtils.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/BinaryTreeUtils.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/ConsoleColor.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/ConsoleColor.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/ConsoleColor.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/EpiProgramConfig.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/EpiProgramConfig.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/EpiProgramConfig.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/EpiTest.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/EpiTest.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/EpiTest.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/EpiTestComparator.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/EpiTestComparator.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/EpiTestComparator.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/EpiTestExpectedType.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/EpiTestExpectedType.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/EpiTestExpectedType.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/EpiUserType.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/EpiUserType.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/EpiUserType.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/GenericTest.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/GenericTest.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/GenericTest.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/GenericTestHandler.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/GenericTestHandler.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/GenericTestHandler.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/LexicographicalListComparator.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/LexicographicalListComparator.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/LexicographicalListComparator.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/Platform.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/Platform.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/Platform.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/RandomSequenceChecker.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/RandomSequenceChecker.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/RandomSequenceChecker.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/TestConfig.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/TestConfig.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/TestConfig.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/TestFailure.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/TestFailure.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/TestFailure.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/TestOutput.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/TestOutput.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/TestOutput.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/TestResult.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/TestResult.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/TestResult.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/TestTimer.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/TestTimer.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/TestTimer.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/TestUtils.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/TestUtils.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/TestUtils.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/TestUtilsConsole.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/TestUtilsConsole.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/TestUtilsConsole.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/TimedExecutor.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/TimedExecutor.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/TimedExecutor.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/TimeoutException.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/TimeoutException.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/TimeoutException.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/TriBool.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/TriBool.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/TriBool.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/Json.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/Json.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/Json.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/JsonArray.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/JsonArray.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/JsonArray.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/JsonHandler.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/JsonHandler.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/JsonHandler.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/JsonLiteral.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/JsonLiteral.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/JsonLiteral.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/JsonNumber.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/JsonNumber.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/JsonNumber.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/JsonObject.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/JsonObject.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/JsonObject.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/JsonParser.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/JsonParser.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/JsonParser.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/JsonString.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/JsonString.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/JsonString.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/JsonValue.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/JsonValue.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/JsonValue.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/JsonWriter.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/JsonWriter.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/JsonWriter.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/Location.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/Location.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/Location.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/Member.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/Member.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/Member.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/ParseException.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/ParseException.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/ParseException.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/PrettyPrint.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/PrettyPrint.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/PrettyPrint.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/WriterConfig.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/WriterConfig.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/WriterConfig.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/WritingBuffer.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/WritingBuffer.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/WritingBuffer.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/BinaryTreeTrait.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/BinaryTreeTrait.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/BinaryTreeTrait.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/BooleanTrait.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/BooleanTrait.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/BooleanTrait.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/CharacterTrait.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/CharacterTrait.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/CharacterTrait.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/DoubleTrait.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/DoubleTrait.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/DoubleTrait.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/FloatTrait.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/FloatTrait.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/FloatTrait.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/IntegerTrait.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/IntegerTrait.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/IntegerTrait.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/LinkedListTrait.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/LinkedListTrait.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/LinkedListTrait.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/ListTrait.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/ListTrait.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/ListTrait.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/LongTrait.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/LongTrait.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/LongTrait.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/SerializationTrait.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/SerializationTrait.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/SerializationTrait.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/SetTrait.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/SetTrait.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/SetTrait.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/ShortTrait.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/ShortTrait.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/ShortTrait.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/StringTrait.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/StringTrait.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/StringTrait.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/TraitsFactory.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/TraitsFactory.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/TraitsFactory.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/UserTypeTrait.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/UserTypeTrait.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/UserTypeTrait.java"

$(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/VoidTrait.class : $(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/VoidTrait.java | $(BUILD_DIR)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/VoidTrait.java"

TEST_FRAMEWORK := \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/BinaryTree.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/BinaryTreeNode.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/BstNode.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/DoublyListNode.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/ListNode.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/PostingListNode.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/TreeLike.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/BinaryTreeUtils.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/ConsoleColor.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/EpiProgramConfig.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/EpiTest.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/EpiTestComparator.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/EpiTestExpectedType.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/EpiUserType.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/GenericTest.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/GenericTestHandler.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/LexicographicalListComparator.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/Platform.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/RandomSequenceChecker.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/TestConfig.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/TestFailure.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/TestOutput.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/TestResult.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/TestTimer.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/TestUtils.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/TestUtilsConsole.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/TimedExecutor.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/TimeoutException.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/TriBool.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/Json.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/JsonArray.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/JsonHandler.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/JsonLiteral.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/JsonNumber.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/JsonObject.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/JsonParser.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/JsonString.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/JsonValue.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/JsonWriter.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/Location.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/Member.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/ParseException.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/PrettyPrint.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/WriterConfig.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/minimal_json/WritingBuffer.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/BinaryTreeTrait.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/BooleanTrait.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/CharacterTrait.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/DoubleTrait.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/FloatTrait.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/IntegerTrait.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/LinkedListTrait.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/ListTrait.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/LongTrait.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/SerializationTrait.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/SetTrait.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/ShortTrait.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/StringTrait.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/TraitsFactory.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/UserTypeTrait.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/test_framework/serialization_traits/VoidTrait.class



# ABSqrt2.java

.PHONY: ABSqrt2
$(BUILD_DIR)/$(MAIN_PACKAGE)/ABSqrt2.class: $(SRC_DIR)/$(MAIN_PACKAGE)/ABSqrt2.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/ABSqrt2.java"
ABSqrt2: $(BUILD_DIR)/$(MAIN_PACKAGE)/ABSqrt2.class
	$(RUN_CMD) $(MAIN_PACKAGE).ABSqrt2 $(PROGRAM_ARGS)



# AbsentValueArray.java

.PHONY: AbsentValueArray
$(BUILD_DIR)/$(MAIN_PACKAGE)/AbsentValueArray.class: $(SRC_DIR)/$(MAIN_PACKAGE)/AbsentValueArray.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/AbsentValueArray.java"
AbsentValueArray: $(BUILD_DIR)/$(MAIN_PACKAGE)/AbsentValueArray.class
	$(RUN_CMD) $(MAIN_PACKAGE).AbsentValueArray $(PROGRAM_ARGS)



# AddingCredits.java

.PHONY: AddingCredits
$(BUILD_DIR)/$(MAIN_PACKAGE)/AddingCredits.class: $(SRC_DIR)/$(MAIN_PACKAGE)/AddingCredits.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/AddingCredits.java"
AddingCredits: $(BUILD_DIR)/$(MAIN_PACKAGE)/AddingCredits.class
	$(RUN_CMD) $(MAIN_PACKAGE).AddingCredits $(PROGRAM_ARGS)



# AdvanceByOffsets.java

.PHONY: AdvanceByOffsets
$(BUILD_DIR)/$(MAIN_PACKAGE)/AdvanceByOffsets.class: $(SRC_DIR)/$(MAIN_PACKAGE)/AdvanceByOffsets.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/AdvanceByOffsets.java"
AdvanceByOffsets: $(BUILD_DIR)/$(MAIN_PACKAGE)/AdvanceByOffsets.class
	$(RUN_CMD) $(MAIN_PACKAGE).AdvanceByOffsets $(PROGRAM_ARGS)



# AlternatingArray.java

.PHONY: AlternatingArray
$(BUILD_DIR)/$(MAIN_PACKAGE)/AlternatingArray.class: $(SRC_DIR)/$(MAIN_PACKAGE)/AlternatingArray.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/AlternatingArray.java"
AlternatingArray: $(BUILD_DIR)/$(MAIN_PACKAGE)/AlternatingArray.class
	$(RUN_CMD) $(MAIN_PACKAGE).AlternatingArray $(PROGRAM_ARGS)



# Anagrams.java

.PHONY: Anagrams
$(BUILD_DIR)/$(MAIN_PACKAGE)/Anagrams.class: $(SRC_DIR)/$(MAIN_PACKAGE)/Anagrams.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/Anagrams.java"
Anagrams: $(BUILD_DIR)/$(MAIN_PACKAGE)/Anagrams.class
	$(RUN_CMD) $(MAIN_PACKAGE).Anagrams $(PROGRAM_ARGS)



# ApplyPermutation.java

.PHONY: ApplyPermutation
$(BUILD_DIR)/$(MAIN_PACKAGE)/ApplyPermutation.class: $(SRC_DIR)/$(MAIN_PACKAGE)/ApplyPermutation.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/ApplyPermutation.java"
ApplyPermutation: $(BUILD_DIR)/$(MAIN_PACKAGE)/ApplyPermutation.class
	$(RUN_CMD) $(MAIN_PACKAGE).ApplyPermutation $(PROGRAM_ARGS)



# Arbitrage.java

.PHONY: Arbitrage
$(BUILD_DIR)/$(MAIN_PACKAGE)/Arbitrage.class: $(SRC_DIR)/$(MAIN_PACKAGE)/Arbitrage.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/Arbitrage.java"
Arbitrage: $(BUILD_DIR)/$(MAIN_PACKAGE)/Arbitrage.class
	$(RUN_CMD) $(MAIN_PACKAGE).Arbitrage $(PROGRAM_ARGS)



# BinomialCoefficients.java

.PHONY: BinomialCoefficients
$(BUILD_DIR)/$(MAIN_PACKAGE)/BinomialCoefficients.class: $(SRC_DIR)/$(MAIN_PACKAGE)/BinomialCoefficients.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/BinomialCoefficients.java"
BinomialCoefficients: $(BUILD_DIR)/$(MAIN_PACKAGE)/BinomialCoefficients.class
	$(RUN_CMD) $(MAIN_PACKAGE).BinomialCoefficients $(PROGRAM_ARGS)



# Bonus.java

.PHONY: Bonus
$(BUILD_DIR)/$(MAIN_PACKAGE)/Bonus.class: $(SRC_DIR)/$(MAIN_PACKAGE)/Bonus.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/Bonus.java"
Bonus: $(BUILD_DIR)/$(MAIN_PACKAGE)/Bonus.class
	$(RUN_CMD) $(MAIN_PACKAGE).Bonus $(PROGRAM_ARGS)



# BstFromPreorder.java

.PHONY: BstFromPreorder
$(BUILD_DIR)/$(MAIN_PACKAGE)/BstFromPreorder.class: $(SRC_DIR)/$(MAIN_PACKAGE)/BstFromPreorder.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/BstFromPreorder.java"
BstFromPreorder: $(BUILD_DIR)/$(MAIN_PACKAGE)/BstFromPreorder.class
	$(RUN_CMD) $(MAIN_PACKAGE).BstFromPreorder $(PROGRAM_ARGS)



# BstFromSortedArray.java

.PHONY: BstFromSortedArray
$(BUILD_DIR)/$(MAIN_PACKAGE)/BstFromSortedArray.class: $(SRC_DIR)/$(MAIN_PACKAGE)/BstFromSortedArray.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/BstFromSortedArray.java"
BstFromSortedArray: $(BUILD_DIR)/$(MAIN_PACKAGE)/BstFromSortedArray.class
	$(RUN_CMD) $(MAIN_PACKAGE).BstFromSortedArray $(PROGRAM_ARGS)



# BstMerge.java

.PHONY: BstMerge
$(BUILD_DIR)/$(MAIN_PACKAGE)/BstMerge.class: $(SRC_DIR)/$(MAIN_PACKAGE)/BstMerge.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/BstMerge.java"
BstMerge: $(BUILD_DIR)/$(MAIN_PACKAGE)/BstMerge.class
	$(RUN_CMD) $(MAIN_PACKAGE).BstMerge $(PROGRAM_ARGS)



# BstToSortedList.java

.PHONY: BstToSortedList
$(BUILD_DIR)/$(MAIN_PACKAGE)/BstToSortedList.class: $(SRC_DIR)/$(MAIN_PACKAGE)/BstToSortedList.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/BstToSortedList.java"
BstToSortedList: $(BUILD_DIR)/$(MAIN_PACKAGE)/BstToSortedList.class
	$(RUN_CMD) $(MAIN_PACKAGE).BstToSortedList $(PROGRAM_ARGS)



# BuyAndSellStock.java

.PHONY: BuyAndSellStock
$(BUILD_DIR)/$(MAIN_PACKAGE)/BuyAndSellStock.class: $(SRC_DIR)/$(MAIN_PACKAGE)/BuyAndSellStock.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/BuyAndSellStock.java"
BuyAndSellStock: $(BUILD_DIR)/$(MAIN_PACKAGE)/BuyAndSellStock.class
	$(RUN_CMD) $(MAIN_PACKAGE).BuyAndSellStock $(PROGRAM_ARGS)



# BuyAndSellStockKTimes.java

.PHONY: BuyAndSellStockKTimes
$(BUILD_DIR)/$(MAIN_PACKAGE)/BuyAndSellStockKTimes.class: $(SRC_DIR)/$(MAIN_PACKAGE)/BuyAndSellStockKTimes.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/BuyAndSellStockKTimes.java"
BuyAndSellStockKTimes: $(BUILD_DIR)/$(MAIN_PACKAGE)/BuyAndSellStockKTimes.class
	$(RUN_CMD) $(MAIN_PACKAGE).BuyAndSellStockKTimes $(PROGRAM_ARGS)



# BuyAndSellStockTwice.java

.PHONY: BuyAndSellStockTwice
$(BUILD_DIR)/$(MAIN_PACKAGE)/BuyAndSellStockTwice.class: $(SRC_DIR)/$(MAIN_PACKAGE)/BuyAndSellStockTwice.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/BuyAndSellStockTwice.java"
BuyAndSellStockTwice: $(BUILD_DIR)/$(MAIN_PACKAGE)/BuyAndSellStockTwice.class
	$(RUN_CMD) $(MAIN_PACKAGE).BuyAndSellStockTwice $(PROGRAM_ARGS)



# CalendarRendering.java

.PHONY: CalendarRendering
$(BUILD_DIR)/$(MAIN_PACKAGE)/CalendarRendering.class: $(SRC_DIR)/$(MAIN_PACKAGE)/CalendarRendering.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/CalendarRendering.java"
CalendarRendering: $(BUILD_DIR)/$(MAIN_PACKAGE)/CalendarRendering.class
	$(RUN_CMD) $(MAIN_PACKAGE).CalendarRendering $(PROGRAM_ARGS)



# CircularQueue.java

.PHONY: CircularQueue
$(BUILD_DIR)/$(MAIN_PACKAGE)/CircularQueue.class: $(SRC_DIR)/$(MAIN_PACKAGE)/CircularQueue.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/CircularQueue.java"
CircularQueue: $(BUILD_DIR)/$(MAIN_PACKAGE)/CircularQueue.class
	$(RUN_CMD) $(MAIN_PACKAGE).CircularQueue $(PROGRAM_ARGS)



# ClosestIntSameWeight.java

.PHONY: ClosestIntSameWeight
$(BUILD_DIR)/$(MAIN_PACKAGE)/ClosestIntSameWeight.class: $(SRC_DIR)/$(MAIN_PACKAGE)/ClosestIntSameWeight.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/ClosestIntSameWeight.java"
ClosestIntSameWeight: $(BUILD_DIR)/$(MAIN_PACKAGE)/ClosestIntSameWeight.class
	$(RUN_CMD) $(MAIN_PACKAGE).ClosestIntSameWeight $(PROGRAM_ARGS)



# CollatzChecker.java

.PHONY: CollatzChecker
$(BUILD_DIR)/$(MAIN_PACKAGE)/CollatzChecker.class: $(SRC_DIR)/$(MAIN_PACKAGE)/CollatzChecker.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/CollatzChecker.java"
CollatzChecker: $(BUILD_DIR)/$(MAIN_PACKAGE)/CollatzChecker.class
	$(RUN_CMD) $(MAIN_PACKAGE).CollatzChecker $(PROGRAM_ARGS)



# Combinations.java

.PHONY: Combinations
$(BUILD_DIR)/$(MAIN_PACKAGE)/Combinations.class: $(SRC_DIR)/$(MAIN_PACKAGE)/Combinations.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/Combinations.java"
Combinations: $(BUILD_DIR)/$(MAIN_PACKAGE)/Combinations.class
	$(RUN_CMD) $(MAIN_PACKAGE).Combinations $(PROGRAM_ARGS)



# ConvertBase.java

.PHONY: ConvertBase
$(BUILD_DIR)/$(MAIN_PACKAGE)/ConvertBase.class: $(SRC_DIR)/$(MAIN_PACKAGE)/ConvertBase.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/ConvertBase.java"
ConvertBase: $(BUILD_DIR)/$(MAIN_PACKAGE)/ConvertBase.class
	$(RUN_CMD) $(MAIN_PACKAGE).ConvertBase $(PROGRAM_ARGS)



# CopyPostingList.java

.PHONY: CopyPostingList
$(BUILD_DIR)/$(MAIN_PACKAGE)/CopyPostingList.class: $(SRC_DIR)/$(MAIN_PACKAGE)/CopyPostingList.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/CopyPostingList.java"
CopyPostingList: $(BUILD_DIR)/$(MAIN_PACKAGE)/CopyPostingList.class
	$(RUN_CMD) $(MAIN_PACKAGE).CopyPostingList $(PROGRAM_ARGS)



# CountBits.java

.PHONY: CountBits
$(BUILD_DIR)/$(MAIN_PACKAGE)/CountBits.class: $(SRC_DIR)/$(MAIN_PACKAGE)/CountBits.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/CountBits.java"
CountBits: $(BUILD_DIR)/$(MAIN_PACKAGE)/CountBits.class
	$(RUN_CMD) $(MAIN_PACKAGE).CountBits $(PROGRAM_ARGS)



# CountInversions.java

.PHONY: CountInversions
$(BUILD_DIR)/$(MAIN_PACKAGE)/CountInversions.class: $(SRC_DIR)/$(MAIN_PACKAGE)/CountInversions.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/CountInversions.java"
CountInversions: $(BUILD_DIR)/$(MAIN_PACKAGE)/CountInversions.class
	$(RUN_CMD) $(MAIN_PACKAGE).CountInversions $(PROGRAM_ARGS)



# DeadlockDetection.java

.PHONY: DeadlockDetection
$(BUILD_DIR)/$(MAIN_PACKAGE)/DeadlockDetection.class: $(SRC_DIR)/$(MAIN_PACKAGE)/DeadlockDetection.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/DeadlockDetection.java"
DeadlockDetection: $(BUILD_DIR)/$(MAIN_PACKAGE)/DeadlockDetection.class
	$(RUN_CMD) $(MAIN_PACKAGE).DeadlockDetection $(PROGRAM_ARGS)



# DefectiveJugs.java

.PHONY: DefectiveJugs
$(BUILD_DIR)/$(MAIN_PACKAGE)/DefectiveJugs.class: $(SRC_DIR)/$(MAIN_PACKAGE)/DefectiveJugs.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/DefectiveJugs.java"
DefectiveJugs: $(BUILD_DIR)/$(MAIN_PACKAGE)/DefectiveJugs.class
	$(RUN_CMD) $(MAIN_PACKAGE).DefectiveJugs $(PROGRAM_ARGS)



# DeleteFromList.java

.PHONY: DeleteFromList
$(BUILD_DIR)/$(MAIN_PACKAGE)/DeleteFromList.class: $(SRC_DIR)/$(MAIN_PACKAGE)/DeleteFromList.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/DeleteFromList.java"
DeleteFromList: $(BUILD_DIR)/$(MAIN_PACKAGE)/DeleteFromList.class
	$(RUN_CMD) $(MAIN_PACKAGE).DeleteFromList $(PROGRAM_ARGS)



# DeleteKthLastFromList.java

.PHONY: DeleteKthLastFromList
$(BUILD_DIR)/$(MAIN_PACKAGE)/DeleteKthLastFromList.class: $(SRC_DIR)/$(MAIN_PACKAGE)/DeleteKthLastFromList.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/DeleteKthLastFromList.java"
DeleteKthLastFromList: $(BUILD_DIR)/$(MAIN_PACKAGE)/DeleteKthLastFromList.class
	$(RUN_CMD) $(MAIN_PACKAGE).DeleteKthLastFromList $(PROGRAM_ARGS)



# DeleteNodeFromList.java

.PHONY: DeleteNodeFromList
$(BUILD_DIR)/$(MAIN_PACKAGE)/DeleteNodeFromList.class: $(SRC_DIR)/$(MAIN_PACKAGE)/DeleteNodeFromList.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/DeleteNodeFromList.java"
DeleteNodeFromList: $(BUILD_DIR)/$(MAIN_PACKAGE)/DeleteNodeFromList.class
	$(RUN_CMD) $(MAIN_PACKAGE).DeleteNodeFromList $(PROGRAM_ARGS)



# DescendantAndAncestorInBst.java

.PHONY: DescendantAndAncestorInBst
$(BUILD_DIR)/$(MAIN_PACKAGE)/DescendantAndAncestorInBst.class: $(SRC_DIR)/$(MAIN_PACKAGE)/DescendantAndAncestorInBst.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/DescendantAndAncestorInBst.java"
DescendantAndAncestorInBst: $(BUILD_DIR)/$(MAIN_PACKAGE)/DescendantAndAncestorInBst.class
	$(RUN_CMD) $(MAIN_PACKAGE).DescendantAndAncestorInBst $(PROGRAM_ARGS)



# DirectoryPathNormalization.java

.PHONY: DirectoryPathNormalization
$(BUILD_DIR)/$(MAIN_PACKAGE)/DirectoryPathNormalization.class: $(SRC_DIR)/$(MAIN_PACKAGE)/DirectoryPathNormalization.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/DirectoryPathNormalization.java"
DirectoryPathNormalization: $(BUILD_DIR)/$(MAIN_PACKAGE)/DirectoryPathNormalization.class
	$(RUN_CMD) $(MAIN_PACKAGE).DirectoryPathNormalization $(PROGRAM_ARGS)



# DoListsOverlap.java

.PHONY: DoListsOverlap
$(BUILD_DIR)/$(MAIN_PACKAGE)/DoListsOverlap.class: $(SRC_DIR)/$(MAIN_PACKAGE)/DoListsOverlap.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/DoListsOverlap.java"
DoListsOverlap: $(BUILD_DIR)/$(MAIN_PACKAGE)/DoListsOverlap.class
	$(RUN_CMD) $(MAIN_PACKAGE).DoListsOverlap $(PROGRAM_ARGS)



# DoTerminatedListsOverlap.java

.PHONY: DoTerminatedListsOverlap
$(BUILD_DIR)/$(MAIN_PACKAGE)/DoTerminatedListsOverlap.class: $(SRC_DIR)/$(MAIN_PACKAGE)/DoTerminatedListsOverlap.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/DoTerminatedListsOverlap.java"
DoTerminatedListsOverlap: $(BUILD_DIR)/$(MAIN_PACKAGE)/DoTerminatedListsOverlap.class
	$(RUN_CMD) $(MAIN_PACKAGE).DoTerminatedListsOverlap $(PROGRAM_ARGS)



# DrawingSkyline.java

.PHONY: DrawingSkyline
$(BUILD_DIR)/$(MAIN_PACKAGE)/DrawingSkyline.class: $(SRC_DIR)/$(MAIN_PACKAGE)/DrawingSkyline.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/DrawingSkyline.java"
DrawingSkyline: $(BUILD_DIR)/$(MAIN_PACKAGE)/DrawingSkyline.class
	$(RUN_CMD) $(MAIN_PACKAGE).DrawingSkyline $(PROGRAM_ARGS)



# DutchNationalFlag.java

.PHONY: DutchNationalFlag
$(BUILD_DIR)/$(MAIN_PACKAGE)/DutchNationalFlag.class: $(SRC_DIR)/$(MAIN_PACKAGE)/DutchNationalFlag.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/DutchNationalFlag.java"
DutchNationalFlag: $(BUILD_DIR)/$(MAIN_PACKAGE)/DutchNationalFlag.class
	$(RUN_CMD) $(MAIN_PACKAGE).DutchNationalFlag $(PROGRAM_ARGS)



# ElementAppearingOnce.java

.PHONY: ElementAppearingOnce
$(BUILD_DIR)/$(MAIN_PACKAGE)/ElementAppearingOnce.class: $(SRC_DIR)/$(MAIN_PACKAGE)/ElementAppearingOnce.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/ElementAppearingOnce.java"
ElementAppearingOnce: $(BUILD_DIR)/$(MAIN_PACKAGE)/ElementAppearingOnce.class
	$(RUN_CMD) $(MAIN_PACKAGE).ElementAppearingOnce $(PROGRAM_ARGS)



# EnumerateBalancedParentheses.java

.PHONY: EnumerateBalancedParentheses
$(BUILD_DIR)/$(MAIN_PACKAGE)/EnumerateBalancedParentheses.class: $(SRC_DIR)/$(MAIN_PACKAGE)/EnumerateBalancedParentheses.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/EnumerateBalancedParentheses.java"
EnumerateBalancedParentheses: $(BUILD_DIR)/$(MAIN_PACKAGE)/EnumerateBalancedParentheses.class
	$(RUN_CMD) $(MAIN_PACKAGE).EnumerateBalancedParentheses $(PROGRAM_ARGS)



# EnumeratePalindromicDecompositions.java

.PHONY: EnumeratePalindromicDecompositions
$(BUILD_DIR)/$(MAIN_PACKAGE)/EnumeratePalindromicDecompositions.class: $(SRC_DIR)/$(MAIN_PACKAGE)/EnumeratePalindromicDecompositions.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/EnumeratePalindromicDecompositions.java"
EnumeratePalindromicDecompositions: $(BUILD_DIR)/$(MAIN_PACKAGE)/EnumeratePalindromicDecompositions.class
	$(RUN_CMD) $(MAIN_PACKAGE).EnumeratePalindromicDecompositions $(PROGRAM_ARGS)



# EnumerateTrees.java

.PHONY: EnumerateTrees
$(BUILD_DIR)/$(MAIN_PACKAGE)/EnumerateTrees.class: $(SRC_DIR)/$(MAIN_PACKAGE)/EnumerateTrees.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/EnumerateTrees.java"
EnumerateTrees: $(BUILD_DIR)/$(MAIN_PACKAGE)/EnumerateTrees.class
	$(RUN_CMD) $(MAIN_PACKAGE).EnumerateTrees $(PROGRAM_ARGS)



# EuclideanGcd.java

.PHONY: EuclideanGcd
$(BUILD_DIR)/$(MAIN_PACKAGE)/EuclideanGcd.class: $(SRC_DIR)/$(MAIN_PACKAGE)/EuclideanGcd.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/EuclideanGcd.java"
EuclideanGcd: $(BUILD_DIR)/$(MAIN_PACKAGE)/EuclideanGcd.class
	$(RUN_CMD) $(MAIN_PACKAGE).EuclideanGcd $(PROGRAM_ARGS)



# EvaluateRpn.java

.PHONY: EvaluateRpn
$(BUILD_DIR)/$(MAIN_PACKAGE)/EvaluateRpn.class: $(SRC_DIR)/$(MAIN_PACKAGE)/EvaluateRpn.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/EvaluateRpn.java"
EvaluateRpn: $(BUILD_DIR)/$(MAIN_PACKAGE)/EvaluateRpn.class
	$(RUN_CMD) $(MAIN_PACKAGE).EvaluateRpn $(PROGRAM_ARGS)



# EvenOddArray.java

.PHONY: EvenOddArray
$(BUILD_DIR)/$(MAIN_PACKAGE)/EvenOddArray.class: $(SRC_DIR)/$(MAIN_PACKAGE)/EvenOddArray.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/EvenOddArray.java"
EvenOddArray: $(BUILD_DIR)/$(MAIN_PACKAGE)/EvenOddArray.class
	$(RUN_CMD) $(MAIN_PACKAGE).EvenOddArray $(PROGRAM_ARGS)



# EvenOddListMerge.java

.PHONY: EvenOddListMerge
$(BUILD_DIR)/$(MAIN_PACKAGE)/EvenOddListMerge.class: $(SRC_DIR)/$(MAIN_PACKAGE)/EvenOddListMerge.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/EvenOddListMerge.java"
EvenOddListMerge: $(BUILD_DIR)/$(MAIN_PACKAGE)/EvenOddListMerge.class
	$(RUN_CMD) $(MAIN_PACKAGE).EvenOddListMerge $(PROGRAM_ARGS)



# Fibonacci.java

.PHONY: Fibonacci
$(BUILD_DIR)/$(MAIN_PACKAGE)/Fibonacci.class: $(SRC_DIR)/$(MAIN_PACKAGE)/Fibonacci.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/Fibonacci.java"
Fibonacci: $(BUILD_DIR)/$(MAIN_PACKAGE)/Fibonacci.class
	$(RUN_CMD) $(MAIN_PACKAGE).Fibonacci $(PROGRAM_ARGS)



# FindSalaryThreshold.java

.PHONY: FindSalaryThreshold
$(BUILD_DIR)/$(MAIN_PACKAGE)/FindSalaryThreshold.class: $(SRC_DIR)/$(MAIN_PACKAGE)/FindSalaryThreshold.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/FindSalaryThreshold.java"
FindSalaryThreshold: $(BUILD_DIR)/$(MAIN_PACKAGE)/FindSalaryThreshold.class
	$(RUN_CMD) $(MAIN_PACKAGE).FindSalaryThreshold $(PROGRAM_ARGS)



# FirstMissingPositiveEntry.java

.PHONY: FirstMissingPositiveEntry
$(BUILD_DIR)/$(MAIN_PACKAGE)/FirstMissingPositiveEntry.class: $(SRC_DIR)/$(MAIN_PACKAGE)/FirstMissingPositiveEntry.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/FirstMissingPositiveEntry.java"
FirstMissingPositiveEntry: $(BUILD_DIR)/$(MAIN_PACKAGE)/FirstMissingPositiveEntry.class
	$(RUN_CMD) $(MAIN_PACKAGE).FirstMissingPositiveEntry $(PROGRAM_ARGS)



# Gcd.java

.PHONY: Gcd
$(BUILD_DIR)/$(MAIN_PACKAGE)/Gcd.class: $(SRC_DIR)/$(MAIN_PACKAGE)/Gcd.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/Gcd.java"
Gcd: $(BUILD_DIR)/$(MAIN_PACKAGE)/Gcd.class
	$(RUN_CMD) $(MAIN_PACKAGE).Gcd $(PROGRAM_ARGS)



# GraphClone.java

.PHONY: GraphClone
$(BUILD_DIR)/$(MAIN_PACKAGE)/GraphClone.class: $(SRC_DIR)/$(MAIN_PACKAGE)/GraphClone.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/GraphClone.java"
GraphClone: $(BUILD_DIR)/$(MAIN_PACKAGE)/GraphClone.class
	$(RUN_CMD) $(MAIN_PACKAGE).GraphClone $(PROGRAM_ARGS)



# GrayCode.java

.PHONY: GrayCode
$(BUILD_DIR)/$(MAIN_PACKAGE)/GrayCode.class: $(SRC_DIR)/$(MAIN_PACKAGE)/GrayCode.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/GrayCode.java"
GrayCode: $(BUILD_DIR)/$(MAIN_PACKAGE)/GrayCode.class
	$(RUN_CMD) $(MAIN_PACKAGE).GrayCode $(PROGRAM_ARGS)



# GroupEqualEntries.java

.PHONY: GroupEqualEntries
$(BUILD_DIR)/$(MAIN_PACKAGE)/GroupEqualEntries.class: $(SRC_DIR)/$(MAIN_PACKAGE)/GroupEqualEntries.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/GroupEqualEntries.java"
GroupEqualEntries: $(BUILD_DIR)/$(MAIN_PACKAGE)/GroupEqualEntries.class
	$(RUN_CMD) $(MAIN_PACKAGE).GroupEqualEntries $(PROGRAM_ARGS)



# HIndex.java

.PHONY: HIndex
$(BUILD_DIR)/$(MAIN_PACKAGE)/HIndex.class: $(SRC_DIR)/$(MAIN_PACKAGE)/HIndex.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/HIndex.java"
HIndex: $(BUILD_DIR)/$(MAIN_PACKAGE)/HIndex.class
	$(RUN_CMD) $(MAIN_PACKAGE).HIndex $(PROGRAM_ARGS)



# Hanoi.java

.PHONY: Hanoi
$(BUILD_DIR)/$(MAIN_PACKAGE)/Hanoi.class: $(SRC_DIR)/$(MAIN_PACKAGE)/Hanoi.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/Hanoi.java"
Hanoi: $(BUILD_DIR)/$(MAIN_PACKAGE)/Hanoi.class
	$(RUN_CMD) $(MAIN_PACKAGE).Hanoi $(PROGRAM_ARGS)



# HuffmanCoding.java

.PHONY: HuffmanCoding
$(BUILD_DIR)/$(MAIN_PACKAGE)/HuffmanCoding.class: $(SRC_DIR)/$(MAIN_PACKAGE)/HuffmanCoding.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/HuffmanCoding.java"
HuffmanCoding: $(BUILD_DIR)/$(MAIN_PACKAGE)/HuffmanCoding.class
	$(RUN_CMD) $(MAIN_PACKAGE).HuffmanCoding $(PROGRAM_ARGS)



# InsertInList.java

.PHONY: InsertInList
$(BUILD_DIR)/$(MAIN_PACKAGE)/InsertInList.class: $(SRC_DIR)/$(MAIN_PACKAGE)/InsertInList.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/InsertInList.java"
InsertInList: $(BUILD_DIR)/$(MAIN_PACKAGE)/InsertInList.class
	$(RUN_CMD) $(MAIN_PACKAGE).InsertInList $(PROGRAM_ARGS)



# InsertOperatorsInString.java

.PHONY: InsertOperatorsInString
$(BUILD_DIR)/$(MAIN_PACKAGE)/InsertOperatorsInString.class: $(SRC_DIR)/$(MAIN_PACKAGE)/InsertOperatorsInString.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/InsertOperatorsInString.java"
InsertOperatorsInString: $(BUILD_DIR)/$(MAIN_PACKAGE)/InsertOperatorsInString.class
	$(RUN_CMD) $(MAIN_PACKAGE).InsertOperatorsInString $(PROGRAM_ARGS)



# IntAsArrayIncrement.java

.PHONY: IntAsArrayIncrement
$(BUILD_DIR)/$(MAIN_PACKAGE)/IntAsArrayIncrement.class: $(SRC_DIR)/$(MAIN_PACKAGE)/IntAsArrayIncrement.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/IntAsArrayIncrement.java"
IntAsArrayIncrement: $(BUILD_DIR)/$(MAIN_PACKAGE)/IntAsArrayIncrement.class
	$(RUN_CMD) $(MAIN_PACKAGE).IntAsArrayIncrement $(PROGRAM_ARGS)



# IntAsArrayMultiply.java

.PHONY: IntAsArrayMultiply
$(BUILD_DIR)/$(MAIN_PACKAGE)/IntAsArrayMultiply.class: $(SRC_DIR)/$(MAIN_PACKAGE)/IntAsArrayMultiply.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/IntAsArrayMultiply.java"
IntAsArrayMultiply: $(BUILD_DIR)/$(MAIN_PACKAGE)/IntAsArrayMultiply.class
	$(RUN_CMD) $(MAIN_PACKAGE).IntAsArrayMultiply $(PROGRAM_ARGS)



# IntAsListAdd.java

.PHONY: IntAsListAdd
$(BUILD_DIR)/$(MAIN_PACKAGE)/IntAsListAdd.class: $(SRC_DIR)/$(MAIN_PACKAGE)/IntAsListAdd.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/IntAsListAdd.java"
IntAsListAdd: $(BUILD_DIR)/$(MAIN_PACKAGE)/IntAsListAdd.class
	$(RUN_CMD) $(MAIN_PACKAGE).IntAsListAdd $(PROGRAM_ARGS)



# IntSquareRoot.java

.PHONY: IntSquareRoot
$(BUILD_DIR)/$(MAIN_PACKAGE)/IntSquareRoot.class: $(SRC_DIR)/$(MAIN_PACKAGE)/IntSquareRoot.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/IntSquareRoot.java"
IntSquareRoot: $(BUILD_DIR)/$(MAIN_PACKAGE)/IntSquareRoot.class
	$(RUN_CMD) $(MAIN_PACKAGE).IntSquareRoot $(PROGRAM_ARGS)



# IntersectSortedArrays.java

.PHONY: IntersectSortedArrays
$(BUILD_DIR)/$(MAIN_PACKAGE)/IntersectSortedArrays.class: $(SRC_DIR)/$(MAIN_PACKAGE)/IntersectSortedArrays.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/IntersectSortedArrays.java"
IntersectSortedArrays: $(BUILD_DIR)/$(MAIN_PACKAGE)/IntersectSortedArrays.class
	$(RUN_CMD) $(MAIN_PACKAGE).IntersectSortedArrays $(PROGRAM_ARGS)



# IntervalAdd.java

.PHONY: IntervalAdd
$(BUILD_DIR)/$(MAIN_PACKAGE)/IntervalAdd.class: $(SRC_DIR)/$(MAIN_PACKAGE)/IntervalAdd.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/IntervalAdd.java"
IntervalAdd: $(BUILD_DIR)/$(MAIN_PACKAGE)/IntervalAdd.class
	$(RUN_CMD) $(MAIN_PACKAGE).IntervalAdd $(PROGRAM_ARGS)



# IntervalsUnion.java

.PHONY: IntervalsUnion
$(BUILD_DIR)/$(MAIN_PACKAGE)/IntervalsUnion.class: $(SRC_DIR)/$(MAIN_PACKAGE)/IntervalsUnion.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/IntervalsUnion.java"
IntervalsUnion: $(BUILD_DIR)/$(MAIN_PACKAGE)/IntervalsUnion.class
	$(RUN_CMD) $(MAIN_PACKAGE).IntervalsUnion $(PROGRAM_ARGS)



# IsAnonymousLetterConstructible.java

.PHONY: IsAnonymousLetterConstructible
$(BUILD_DIR)/$(MAIN_PACKAGE)/IsAnonymousLetterConstructible.class: $(SRC_DIR)/$(MAIN_PACKAGE)/IsAnonymousLetterConstructible.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/IsAnonymousLetterConstructible.java"
IsAnonymousLetterConstructible: $(BUILD_DIR)/$(MAIN_PACKAGE)/IsAnonymousLetterConstructible.class
	$(RUN_CMD) $(MAIN_PACKAGE).IsAnonymousLetterConstructible $(PROGRAM_ARGS)



# IsArrayDominated.java

.PHONY: IsArrayDominated
$(BUILD_DIR)/$(MAIN_PACKAGE)/IsArrayDominated.class: $(SRC_DIR)/$(MAIN_PACKAGE)/IsArrayDominated.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/IsArrayDominated.java"
IsArrayDominated: $(BUILD_DIR)/$(MAIN_PACKAGE)/IsArrayDominated.class
	$(RUN_CMD) $(MAIN_PACKAGE).IsArrayDominated $(PROGRAM_ARGS)



# IsCircuitWirable.java

.PHONY: IsCircuitWirable
$(BUILD_DIR)/$(MAIN_PACKAGE)/IsCircuitWirable.class: $(SRC_DIR)/$(MAIN_PACKAGE)/IsCircuitWirable.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/IsCircuitWirable.java"
IsCircuitWirable: $(BUILD_DIR)/$(MAIN_PACKAGE)/IsCircuitWirable.class
	$(RUN_CMD) $(MAIN_PACKAGE).IsCircuitWirable $(PROGRAM_ARGS)



# IsListCyclic.java

.PHONY: IsListCyclic
$(BUILD_DIR)/$(MAIN_PACKAGE)/IsListCyclic.class: $(SRC_DIR)/$(MAIN_PACKAGE)/IsListCyclic.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/IsListCyclic.java"
IsListCyclic: $(BUILD_DIR)/$(MAIN_PACKAGE)/IsListCyclic.class
	$(RUN_CMD) $(MAIN_PACKAGE).IsListCyclic $(PROGRAM_ARGS)



# IsListPalindromic.java

.PHONY: IsListPalindromic
$(BUILD_DIR)/$(MAIN_PACKAGE)/IsListPalindromic.class: $(SRC_DIR)/$(MAIN_PACKAGE)/IsListPalindromic.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/IsListPalindromic.java"
IsListPalindromic: $(BUILD_DIR)/$(MAIN_PACKAGE)/IsListPalindromic.class
	$(RUN_CMD) $(MAIN_PACKAGE).IsListPalindromic $(PROGRAM_ARGS)



# IsNumberPalindromic.java

.PHONY: IsNumberPalindromic
$(BUILD_DIR)/$(MAIN_PACKAGE)/IsNumberPalindromic.class: $(SRC_DIR)/$(MAIN_PACKAGE)/IsNumberPalindromic.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/IsNumberPalindromic.java"
IsNumberPalindromic: $(BUILD_DIR)/$(MAIN_PACKAGE)/IsNumberPalindromic.class
	$(RUN_CMD) $(MAIN_PACKAGE).IsNumberPalindromic $(PROGRAM_ARGS)



# IsStringDecomposableIntoWords.java

.PHONY: IsStringDecomposableIntoWords
$(BUILD_DIR)/$(MAIN_PACKAGE)/IsStringDecomposableIntoWords.class: $(SRC_DIR)/$(MAIN_PACKAGE)/IsStringDecomposableIntoWords.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/IsStringDecomposableIntoWords.java"
IsStringDecomposableIntoWords: $(BUILD_DIR)/$(MAIN_PACKAGE)/IsStringDecomposableIntoWords.class
	$(RUN_CMD) $(MAIN_PACKAGE).IsStringDecomposableIntoWords $(PROGRAM_ARGS)



# IsStringInMatrix.java

.PHONY: IsStringInMatrix
$(BUILD_DIR)/$(MAIN_PACKAGE)/IsStringInMatrix.class: $(SRC_DIR)/$(MAIN_PACKAGE)/IsStringInMatrix.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/IsStringInMatrix.java"
IsStringInMatrix: $(BUILD_DIR)/$(MAIN_PACKAGE)/IsStringInMatrix.class
	$(RUN_CMD) $(MAIN_PACKAGE).IsStringInMatrix $(PROGRAM_ARGS)



# IsStringPalindromic.java

.PHONY: IsStringPalindromic
$(BUILD_DIR)/$(MAIN_PACKAGE)/IsStringPalindromic.class: $(SRC_DIR)/$(MAIN_PACKAGE)/IsStringPalindromic.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/IsStringPalindromic.java"
IsStringPalindromic: $(BUILD_DIR)/$(MAIN_PACKAGE)/IsStringPalindromic.class
	$(RUN_CMD) $(MAIN_PACKAGE).IsStringPalindromic $(PROGRAM_ARGS)



# IsStringPalindromicPunctuation.java

.PHONY: IsStringPalindromicPunctuation
$(BUILD_DIR)/$(MAIN_PACKAGE)/IsStringPalindromicPunctuation.class: $(SRC_DIR)/$(MAIN_PACKAGE)/IsStringPalindromicPunctuation.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/IsStringPalindromicPunctuation.java"
IsStringPalindromicPunctuation: $(BUILD_DIR)/$(MAIN_PACKAGE)/IsStringPalindromicPunctuation.class
	$(RUN_CMD) $(MAIN_PACKAGE).IsStringPalindromicPunctuation $(PROGRAM_ARGS)



# IsStringPermutableToPalindrome.java

.PHONY: IsStringPermutableToPalindrome
$(BUILD_DIR)/$(MAIN_PACKAGE)/IsStringPermutableToPalindrome.class: $(SRC_DIR)/$(MAIN_PACKAGE)/IsStringPermutableToPalindrome.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/IsStringPermutableToPalindrome.java"
IsStringPermutableToPalindrome: $(BUILD_DIR)/$(MAIN_PACKAGE)/IsStringPermutableToPalindrome.class
	$(RUN_CMD) $(MAIN_PACKAGE).IsStringPermutableToPalindrome $(PROGRAM_ARGS)



# IsTreeABst.java

.PHONY: IsTreeABst
$(BUILD_DIR)/$(MAIN_PACKAGE)/IsTreeABst.class: $(SRC_DIR)/$(MAIN_PACKAGE)/IsTreeABst.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/IsTreeABst.java"
IsTreeABst: $(BUILD_DIR)/$(MAIN_PACKAGE)/IsTreeABst.class
	$(RUN_CMD) $(MAIN_PACKAGE).IsTreeABst $(PROGRAM_ARGS)



# IsTreeBalanced.java

.PHONY: IsTreeBalanced
$(BUILD_DIR)/$(MAIN_PACKAGE)/IsTreeBalanced.class: $(SRC_DIR)/$(MAIN_PACKAGE)/IsTreeBalanced.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/IsTreeBalanced.java"
IsTreeBalanced: $(BUILD_DIR)/$(MAIN_PACKAGE)/IsTreeBalanced.class
	$(RUN_CMD) $(MAIN_PACKAGE).IsTreeBalanced $(PROGRAM_ARGS)



# IsTreeSymmetric.java

.PHONY: IsTreeSymmetric
$(BUILD_DIR)/$(MAIN_PACKAGE)/IsTreeSymmetric.class: $(SRC_DIR)/$(MAIN_PACKAGE)/IsTreeSymmetric.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/IsTreeSymmetric.java"
IsTreeSymmetric: $(BUILD_DIR)/$(MAIN_PACKAGE)/IsTreeSymmetric.class
	$(RUN_CMD) $(MAIN_PACKAGE).IsTreeSymmetric $(PROGRAM_ARGS)



# IsValidParenthesization.java

.PHONY: IsValidParenthesization
$(BUILD_DIR)/$(MAIN_PACKAGE)/IsValidParenthesization.class: $(SRC_DIR)/$(MAIN_PACKAGE)/IsValidParenthesization.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/IsValidParenthesization.java"
IsValidParenthesization: $(BUILD_DIR)/$(MAIN_PACKAGE)/IsValidParenthesization.class
	$(RUN_CMD) $(MAIN_PACKAGE).IsValidParenthesization $(PROGRAM_ARGS)



# IsValidSudoku.java

.PHONY: IsValidSudoku
$(BUILD_DIR)/$(MAIN_PACKAGE)/IsValidSudoku.class: $(SRC_DIR)/$(MAIN_PACKAGE)/IsValidSudoku.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/IsValidSudoku.java"
IsValidSudoku: $(BUILD_DIR)/$(MAIN_PACKAGE)/IsValidSudoku.class
	$(RUN_CMD) $(MAIN_PACKAGE).IsValidSudoku $(PROGRAM_ARGS)



# KClosestStars.java

.PHONY: KClosestStars
$(BUILD_DIR)/$(MAIN_PACKAGE)/KClosestStars.class: $(SRC_DIR)/$(MAIN_PACKAGE)/KClosestStars.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/KClosestStars.java"
KClosestStars: $(BUILD_DIR)/$(MAIN_PACKAGE)/KClosestStars.class
	$(RUN_CMD) $(MAIN_PACKAGE).KClosestStars $(PROGRAM_ARGS)



# KLargestInHeap.java

.PHONY: KLargestInHeap
$(BUILD_DIR)/$(MAIN_PACKAGE)/KLargestInHeap.class: $(SRC_DIR)/$(MAIN_PACKAGE)/KLargestInHeap.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/KLargestInHeap.java"
KLargestInHeap: $(BUILD_DIR)/$(MAIN_PACKAGE)/KLargestInHeap.class
	$(RUN_CMD) $(MAIN_PACKAGE).KLargestInHeap $(PROGRAM_ARGS)



# KLargestValuesInBst.java

.PHONY: KLargestValuesInBst
$(BUILD_DIR)/$(MAIN_PACKAGE)/KLargestValuesInBst.class: $(SRC_DIR)/$(MAIN_PACKAGE)/KLargestValuesInBst.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/KLargestValuesInBst.java"
KLargestValuesInBst: $(BUILD_DIR)/$(MAIN_PACKAGE)/KLargestValuesInBst.class
	$(RUN_CMD) $(MAIN_PACKAGE).KLargestValuesInBst $(PROGRAM_ARGS)



# Knapsack.java

.PHONY: Knapsack
$(BUILD_DIR)/$(MAIN_PACKAGE)/Knapsack.class: $(SRC_DIR)/$(MAIN_PACKAGE)/Knapsack.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/Knapsack.java"
Knapsack: $(BUILD_DIR)/$(MAIN_PACKAGE)/Knapsack.class
	$(RUN_CMD) $(MAIN_PACKAGE).Knapsack $(PROGRAM_ARGS)



# KthLargestElementInLongArray.java

.PHONY: KthLargestElementInLongArray
$(BUILD_DIR)/$(MAIN_PACKAGE)/KthLargestElementInLongArray.class: $(SRC_DIR)/$(MAIN_PACKAGE)/KthLargestElementInLongArray.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/KthLargestElementInLongArray.java"
KthLargestElementInLongArray: $(BUILD_DIR)/$(MAIN_PACKAGE)/KthLargestElementInLongArray.class
	$(RUN_CMD) $(MAIN_PACKAGE).KthLargestElementInLongArray $(PROGRAM_ARGS)



# KthLargestElementInTwoSortedArrays.java

.PHONY: KthLargestElementInTwoSortedArrays
$(BUILD_DIR)/$(MAIN_PACKAGE)/KthLargestElementInTwoSortedArrays.class: $(SRC_DIR)/$(MAIN_PACKAGE)/KthLargestElementInTwoSortedArrays.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/KthLargestElementInTwoSortedArrays.java"
KthLargestElementInTwoSortedArrays: $(BUILD_DIR)/$(MAIN_PACKAGE)/KthLargestElementInTwoSortedArrays.class
	$(RUN_CMD) $(MAIN_PACKAGE).KthLargestElementInTwoSortedArrays $(PROGRAM_ARGS)



# KthLargestInArray.java

.PHONY: KthLargestInArray
$(BUILD_DIR)/$(MAIN_PACKAGE)/KthLargestInArray.class: $(SRC_DIR)/$(MAIN_PACKAGE)/KthLargestInArray.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/KthLargestInArray.java"
KthLargestInArray: $(BUILD_DIR)/$(MAIN_PACKAGE)/KthLargestInArray.class
	$(RUN_CMD) $(MAIN_PACKAGE).KthLargestInArray $(PROGRAM_ARGS)



# KthNodeInTree.java

.PHONY: KthNodeInTree
$(BUILD_DIR)/$(MAIN_PACKAGE)/KthNodeInTree.class: $(SRC_DIR)/$(MAIN_PACKAGE)/KthNodeInTree.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/KthNodeInTree.java"
KthNodeInTree: $(BUILD_DIR)/$(MAIN_PACKAGE)/KthNodeInTree.class
	$(RUN_CMD) $(MAIN_PACKAGE).KthNodeInTree $(PROGRAM_ARGS)



# LargestRectangleUnderSkyline.java

.PHONY: LargestRectangleUnderSkyline
$(BUILD_DIR)/$(MAIN_PACKAGE)/LargestRectangleUnderSkyline.class: $(SRC_DIR)/$(MAIN_PACKAGE)/LargestRectangleUnderSkyline.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/LargestRectangleUnderSkyline.java"
LargestRectangleUnderSkyline: $(BUILD_DIR)/$(MAIN_PACKAGE)/LargestRectangleUnderSkyline.class
	$(RUN_CMD) $(MAIN_PACKAGE).LargestRectangleUnderSkyline $(PROGRAM_ARGS)



# LeftRightJustifyText.java

.PHONY: LeftRightJustifyText
$(BUILD_DIR)/$(MAIN_PACKAGE)/LeftRightJustifyText.class: $(SRC_DIR)/$(MAIN_PACKAGE)/LeftRightJustifyText.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/LeftRightJustifyText.java"
LeftRightJustifyText: $(BUILD_DIR)/$(MAIN_PACKAGE)/LeftRightJustifyText.class
	$(RUN_CMD) $(MAIN_PACKAGE).LeftRightJustifyText $(PROGRAM_ARGS)



# LevenshteinDistance.java

.PHONY: LevenshteinDistance
$(BUILD_DIR)/$(MAIN_PACKAGE)/LevenshteinDistance.class: $(SRC_DIR)/$(MAIN_PACKAGE)/LevenshteinDistance.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/LevenshteinDistance.java"
LevenshteinDistance: $(BUILD_DIR)/$(MAIN_PACKAGE)/LevenshteinDistance.class
	$(RUN_CMD) $(MAIN_PACKAGE).LevenshteinDistance $(PROGRAM_ARGS)



# LineThroughMostPoints.java

.PHONY: LineThroughMostPoints
$(BUILD_DIR)/$(MAIN_PACKAGE)/LineThroughMostPoints.class: $(SRC_DIR)/$(MAIN_PACKAGE)/LineThroughMostPoints.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/LineThroughMostPoints.java"
LineThroughMostPoints: $(BUILD_DIR)/$(MAIN_PACKAGE)/LineThroughMostPoints.class
	$(RUN_CMD) $(MAIN_PACKAGE).LineThroughMostPoints $(PROGRAM_ARGS)



# ListCyclicRightShift.java

.PHONY: ListCyclicRightShift
$(BUILD_DIR)/$(MAIN_PACKAGE)/ListCyclicRightShift.class: $(SRC_DIR)/$(MAIN_PACKAGE)/ListCyclicRightShift.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/ListCyclicRightShift.java"
ListCyclicRightShift: $(BUILD_DIR)/$(MAIN_PACKAGE)/ListCyclicRightShift.class
	$(RUN_CMD) $(MAIN_PACKAGE).ListCyclicRightShift $(PROGRAM_ARGS)



# LongestContainedInterval.java

.PHONY: LongestContainedInterval
$(BUILD_DIR)/$(MAIN_PACKAGE)/LongestContainedInterval.class: $(SRC_DIR)/$(MAIN_PACKAGE)/LongestContainedInterval.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/LongestContainedInterval.java"
LongestContainedInterval: $(BUILD_DIR)/$(MAIN_PACKAGE)/LongestContainedInterval.class
	$(RUN_CMD) $(MAIN_PACKAGE).LongestContainedInterval $(PROGRAM_ARGS)



# LongestIncreasingSubarray.java

.PHONY: LongestIncreasingSubarray
$(BUILD_DIR)/$(MAIN_PACKAGE)/LongestIncreasingSubarray.class: $(SRC_DIR)/$(MAIN_PACKAGE)/LongestIncreasingSubarray.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/LongestIncreasingSubarray.java"
LongestIncreasingSubarray: $(BUILD_DIR)/$(MAIN_PACKAGE)/LongestIncreasingSubarray.class
	$(RUN_CMD) $(MAIN_PACKAGE).LongestIncreasingSubarray $(PROGRAM_ARGS)



# LongestNondecreasingSubsequence.java

.PHONY: LongestNondecreasingSubsequence
$(BUILD_DIR)/$(MAIN_PACKAGE)/LongestNondecreasingSubsequence.class: $(SRC_DIR)/$(MAIN_PACKAGE)/LongestNondecreasingSubsequence.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/LongestNondecreasingSubsequence.java"
LongestNondecreasingSubsequence: $(BUILD_DIR)/$(MAIN_PACKAGE)/LongestNondecreasingSubsequence.class
	$(RUN_CMD) $(MAIN_PACKAGE).LongestNondecreasingSubsequence $(PROGRAM_ARGS)



# LongestSubarrayWithDistinctValues.java

.PHONY: LongestSubarrayWithDistinctValues
$(BUILD_DIR)/$(MAIN_PACKAGE)/LongestSubarrayWithDistinctValues.class: $(SRC_DIR)/$(MAIN_PACKAGE)/LongestSubarrayWithDistinctValues.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/LongestSubarrayWithDistinctValues.java"
LongestSubarrayWithDistinctValues: $(BUILD_DIR)/$(MAIN_PACKAGE)/LongestSubarrayWithDistinctValues.class
	$(RUN_CMD) $(MAIN_PACKAGE).LongestSubarrayWithDistinctValues $(PROGRAM_ARGS)



# LongestSubarrayWithSumConstraint.java

.PHONY: LongestSubarrayWithSumConstraint
$(BUILD_DIR)/$(MAIN_PACKAGE)/LongestSubarrayWithSumConstraint.class: $(SRC_DIR)/$(MAIN_PACKAGE)/LongestSubarrayWithSumConstraint.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/LongestSubarrayWithSumConstraint.java"
LongestSubarrayWithSumConstraint: $(BUILD_DIR)/$(MAIN_PACKAGE)/LongestSubarrayWithSumConstraint.class
	$(RUN_CMD) $(MAIN_PACKAGE).LongestSubarrayWithSumConstraint $(PROGRAM_ARGS)



# LongestSubstringWithMatchingParentheses.java

.PHONY: LongestSubstringWithMatchingParentheses
$(BUILD_DIR)/$(MAIN_PACKAGE)/LongestSubstringWithMatchingParentheses.class: $(SRC_DIR)/$(MAIN_PACKAGE)/LongestSubstringWithMatchingParentheses.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/LongestSubstringWithMatchingParentheses.java"
LongestSubstringWithMatchingParentheses: $(BUILD_DIR)/$(MAIN_PACKAGE)/LongestSubstringWithMatchingParentheses.class
	$(RUN_CMD) $(MAIN_PACKAGE).LongestSubstringWithMatchingParentheses $(PROGRAM_ARGS)



# LookAndSay.java

.PHONY: LookAndSay
$(BUILD_DIR)/$(MAIN_PACKAGE)/LookAndSay.class: $(SRC_DIR)/$(MAIN_PACKAGE)/LookAndSay.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/LookAndSay.java"
LookAndSay: $(BUILD_DIR)/$(MAIN_PACKAGE)/LookAndSay.class
	$(RUN_CMD) $(MAIN_PACKAGE).LookAndSay $(PROGRAM_ARGS)



# LowestCommonAncestor.java

.PHONY: LowestCommonAncestor
$(BUILD_DIR)/$(MAIN_PACKAGE)/LowestCommonAncestor.class: $(SRC_DIR)/$(MAIN_PACKAGE)/LowestCommonAncestor.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/LowestCommonAncestor.java"
LowestCommonAncestor: $(BUILD_DIR)/$(MAIN_PACKAGE)/LowestCommonAncestor.class
	$(RUN_CMD) $(MAIN_PACKAGE).LowestCommonAncestor $(PROGRAM_ARGS)



# LowestCommonAncestorCloseAncestor.java

.PHONY: LowestCommonAncestorCloseAncestor
$(BUILD_DIR)/$(MAIN_PACKAGE)/LowestCommonAncestorCloseAncestor.class: $(SRC_DIR)/$(MAIN_PACKAGE)/LowestCommonAncestorCloseAncestor.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/LowestCommonAncestorCloseAncestor.java"
LowestCommonAncestorCloseAncestor: $(BUILD_DIR)/$(MAIN_PACKAGE)/LowestCommonAncestorCloseAncestor.class
	$(RUN_CMD) $(MAIN_PACKAGE).LowestCommonAncestorCloseAncestor $(PROGRAM_ARGS)



# LowestCommonAncestorInBst.java

.PHONY: LowestCommonAncestorInBst
$(BUILD_DIR)/$(MAIN_PACKAGE)/LowestCommonAncestorInBst.class: $(SRC_DIR)/$(MAIN_PACKAGE)/LowestCommonAncestorInBst.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/LowestCommonAncestorInBst.java"
LowestCommonAncestorInBst: $(BUILD_DIR)/$(MAIN_PACKAGE)/LowestCommonAncestorInBst.class
	$(RUN_CMD) $(MAIN_PACKAGE).LowestCommonAncestorInBst $(PROGRAM_ARGS)



# LowestCommonAncestorWithParent.java

.PHONY: LowestCommonAncestorWithParent
$(BUILD_DIR)/$(MAIN_PACKAGE)/LowestCommonAncestorWithParent.class: $(SRC_DIR)/$(MAIN_PACKAGE)/LowestCommonAncestorWithParent.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/LowestCommonAncestorWithParent.java"
LowestCommonAncestorWithParent: $(BUILD_DIR)/$(MAIN_PACKAGE)/LowestCommonAncestorWithParent.class
	$(RUN_CMD) $(MAIN_PACKAGE).LowestCommonAncestorWithParent $(PROGRAM_ARGS)



# LruCache.java

.PHONY: LruCache
$(BUILD_DIR)/$(MAIN_PACKAGE)/LruCache.class: $(SRC_DIR)/$(MAIN_PACKAGE)/LruCache.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/LruCache.java"
LruCache: $(BUILD_DIR)/$(MAIN_PACKAGE)/LruCache.class
	$(RUN_CMD) $(MAIN_PACKAGE).LruCache $(PROGRAM_ARGS)



# MajorityElement.java

.PHONY: MajorityElement
$(BUILD_DIR)/$(MAIN_PACKAGE)/MajorityElement.class: $(SRC_DIR)/$(MAIN_PACKAGE)/MajorityElement.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/MajorityElement.java"
MajorityElement: $(BUILD_DIR)/$(MAIN_PACKAGE)/MajorityElement.class
	$(RUN_CMD) $(MAIN_PACKAGE).MajorityElement $(PROGRAM_ARGS)



# MakingChange.java

.PHONY: MakingChange
$(BUILD_DIR)/$(MAIN_PACKAGE)/MakingChange.class: $(SRC_DIR)/$(MAIN_PACKAGE)/MakingChange.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/MakingChange.java"
MakingChange: $(BUILD_DIR)/$(MAIN_PACKAGE)/MakingChange.class
	$(RUN_CMD) $(MAIN_PACKAGE).MakingChange $(PROGRAM_ARGS)



# MatrixConnectedRegions.java

.PHONY: MatrixConnectedRegions
$(BUILD_DIR)/$(MAIN_PACKAGE)/MatrixConnectedRegions.class: $(SRC_DIR)/$(MAIN_PACKAGE)/MatrixConnectedRegions.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/MatrixConnectedRegions.java"
MatrixConnectedRegions: $(BUILD_DIR)/$(MAIN_PACKAGE)/MatrixConnectedRegions.class
	$(RUN_CMD) $(MAIN_PACKAGE).MatrixConnectedRegions $(PROGRAM_ARGS)



# MatrixEnclosedRegions.java

.PHONY: MatrixEnclosedRegions
$(BUILD_DIR)/$(MAIN_PACKAGE)/MatrixEnclosedRegions.class: $(SRC_DIR)/$(MAIN_PACKAGE)/MatrixEnclosedRegions.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/MatrixEnclosedRegions.java"
MatrixEnclosedRegions: $(BUILD_DIR)/$(MAIN_PACKAGE)/MatrixEnclosedRegions.class
	$(RUN_CMD) $(MAIN_PACKAGE).MatrixEnclosedRegions $(PROGRAM_ARGS)



# MatrixRotation.java

.PHONY: MatrixRotation
$(BUILD_DIR)/$(MAIN_PACKAGE)/MatrixRotation.class: $(SRC_DIR)/$(MAIN_PACKAGE)/MatrixRotation.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/MatrixRotation.java"
MatrixRotation: $(BUILD_DIR)/$(MAIN_PACKAGE)/MatrixRotation.class
	$(RUN_CMD) $(MAIN_PACKAGE).MatrixRotation $(PROGRAM_ARGS)



# MaxOfSlidingWindow.java

.PHONY: MaxOfSlidingWindow
$(BUILD_DIR)/$(MAIN_PACKAGE)/MaxOfSlidingWindow.class: $(SRC_DIR)/$(MAIN_PACKAGE)/MaxOfSlidingWindow.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/MaxOfSlidingWindow.java"
MaxOfSlidingWindow: $(BUILD_DIR)/$(MAIN_PACKAGE)/MaxOfSlidingWindow.class
	$(RUN_CMD) $(MAIN_PACKAGE).MaxOfSlidingWindow $(PROGRAM_ARGS)



# MaxProductAllButOne.java

.PHONY: MaxProductAllButOne
$(BUILD_DIR)/$(MAIN_PACKAGE)/MaxProductAllButOne.class: $(SRC_DIR)/$(MAIN_PACKAGE)/MaxProductAllButOne.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/MaxProductAllButOne.java"
MaxProductAllButOne: $(BUILD_DIR)/$(MAIN_PACKAGE)/MaxProductAllButOne.class
	$(RUN_CMD) $(MAIN_PACKAGE).MaxProductAllButOne $(PROGRAM_ARGS)



# MaxSafeHeight.java

.PHONY: MaxSafeHeight
$(BUILD_DIR)/$(MAIN_PACKAGE)/MaxSafeHeight.class: $(SRC_DIR)/$(MAIN_PACKAGE)/MaxSafeHeight.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/MaxSafeHeight.java"
MaxSafeHeight: $(BUILD_DIR)/$(MAIN_PACKAGE)/MaxSafeHeight.class
	$(RUN_CMD) $(MAIN_PACKAGE).MaxSafeHeight $(PROGRAM_ARGS)



# MaxSquareSubmatrix.java

.PHONY: MaxSquareSubmatrix
$(BUILD_DIR)/$(MAIN_PACKAGE)/MaxSquareSubmatrix.class: $(SRC_DIR)/$(MAIN_PACKAGE)/MaxSquareSubmatrix.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/MaxSquareSubmatrix.java"
MaxSquareSubmatrix: $(BUILD_DIR)/$(MAIN_PACKAGE)/MaxSquareSubmatrix.class
	$(RUN_CMD) $(MAIN_PACKAGE).MaxSquareSubmatrix $(PROGRAM_ARGS)



# MaxSubmatrix.java

.PHONY: MaxSubmatrix
$(BUILD_DIR)/$(MAIN_PACKAGE)/MaxSubmatrix.class: $(SRC_DIR)/$(MAIN_PACKAGE)/MaxSubmatrix.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/MaxSubmatrix.java"
MaxSubmatrix: $(BUILD_DIR)/$(MAIN_PACKAGE)/MaxSubmatrix.class
	$(RUN_CMD) $(MAIN_PACKAGE).MaxSubmatrix $(PROGRAM_ARGS)



# MaxSumSubarray.java

.PHONY: MaxSumSubarray
$(BUILD_DIR)/$(MAIN_PACKAGE)/MaxSumSubarray.class: $(SRC_DIR)/$(MAIN_PACKAGE)/MaxSumSubarray.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/MaxSumSubarray.java"
MaxSumSubarray: $(BUILD_DIR)/$(MAIN_PACKAGE)/MaxSumSubarray.class
	$(RUN_CMD) $(MAIN_PACKAGE).MaxSumSubarray $(PROGRAM_ARGS)



# MaxTeamsInPhotograph.java

.PHONY: MaxTeamsInPhotograph
$(BUILD_DIR)/$(MAIN_PACKAGE)/MaxTeamsInPhotograph.class: $(SRC_DIR)/$(MAIN_PACKAGE)/MaxTeamsInPhotograph.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/MaxTeamsInPhotograph.java"
MaxTeamsInPhotograph: $(BUILD_DIR)/$(MAIN_PACKAGE)/MaxTeamsInPhotograph.class
	$(RUN_CMD) $(MAIN_PACKAGE).MaxTeamsInPhotograph $(PROGRAM_ARGS)



# MaxTrappedWater.java

.PHONY: MaxTrappedWater
$(BUILD_DIR)/$(MAIN_PACKAGE)/MaxTrappedWater.class: $(SRC_DIR)/$(MAIN_PACKAGE)/MaxTrappedWater.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/MaxTrappedWater.java"
MaxTrappedWater: $(BUILD_DIR)/$(MAIN_PACKAGE)/MaxTrappedWater.class
	$(RUN_CMD) $(MAIN_PACKAGE).MaxTrappedWater $(PROGRAM_ARGS)



# MaxWaterTrappable.java

.PHONY: MaxWaterTrappable
$(BUILD_DIR)/$(MAIN_PACKAGE)/MaxWaterTrappable.class: $(SRC_DIR)/$(MAIN_PACKAGE)/MaxWaterTrappable.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/MaxWaterTrappable.java"
MaxWaterTrappable: $(BUILD_DIR)/$(MAIN_PACKAGE)/MaxWaterTrappable.class
	$(RUN_CMD) $(MAIN_PACKAGE).MaxWaterTrappable $(PROGRAM_ARGS)



# MaximumSubarrayInCircularArray.java

.PHONY: MaximumSubarrayInCircularArray
$(BUILD_DIR)/$(MAIN_PACKAGE)/MaximumSubarrayInCircularArray.class: $(SRC_DIR)/$(MAIN_PACKAGE)/MaximumSubarrayInCircularArray.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/MaximumSubarrayInCircularArray.java"
MaximumSubarrayInCircularArray: $(BUILD_DIR)/$(MAIN_PACKAGE)/MaximumSubarrayInCircularArray.class
	$(RUN_CMD) $(MAIN_PACKAGE).MaximumSubarrayInCircularArray $(PROGRAM_ARGS)



# MinimumDistance3SortedArrays.java

.PHONY: MinimumDistance3SortedArrays
$(BUILD_DIR)/$(MAIN_PACKAGE)/MinimumDistance3SortedArrays.class: $(SRC_DIR)/$(MAIN_PACKAGE)/MinimumDistance3SortedArrays.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/MinimumDistance3SortedArrays.java"
MinimumDistance3SortedArrays: $(BUILD_DIR)/$(MAIN_PACKAGE)/MinimumDistance3SortedArrays.class
	$(RUN_CMD) $(MAIN_PACKAGE).MinimumDistance3SortedArrays $(PROGRAM_ARGS)



# MinimumPointsCoveringIntervals.java

.PHONY: MinimumPointsCoveringIntervals
$(BUILD_DIR)/$(MAIN_PACKAGE)/MinimumPointsCoveringIntervals.class: $(SRC_DIR)/$(MAIN_PACKAGE)/MinimumPointsCoveringIntervals.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/MinimumPointsCoveringIntervals.java"
MinimumPointsCoveringIntervals: $(BUILD_DIR)/$(MAIN_PACKAGE)/MinimumPointsCoveringIntervals.class
	$(RUN_CMD) $(MAIN_PACKAGE).MinimumPointsCoveringIntervals $(PROGRAM_ARGS)



# MinimumWaitingTime.java

.PHONY: MinimumWaitingTime
$(BUILD_DIR)/$(MAIN_PACKAGE)/MinimumWaitingTime.class: $(SRC_DIR)/$(MAIN_PACKAGE)/MinimumWaitingTime.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/MinimumWaitingTime.java"
MinimumWaitingTime: $(BUILD_DIR)/$(MAIN_PACKAGE)/MinimumWaitingTime.class
	$(RUN_CMD) $(MAIN_PACKAGE).MinimumWaitingTime $(PROGRAM_ARGS)



# MinimumWeightPathInATriangle.java

.PHONY: MinimumWeightPathInATriangle
$(BUILD_DIR)/$(MAIN_PACKAGE)/MinimumWeightPathInATriangle.class: $(SRC_DIR)/$(MAIN_PACKAGE)/MinimumWeightPathInATriangle.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/MinimumWeightPathInATriangle.java"
MinimumWeightPathInATriangle: $(BUILD_DIR)/$(MAIN_PACKAGE)/MinimumWeightPathInATriangle.class
	$(RUN_CMD) $(MAIN_PACKAGE).MinimumWeightPathInATriangle $(PROGRAM_ARGS)



# NQueens.java

.PHONY: NQueens
$(BUILD_DIR)/$(MAIN_PACKAGE)/NQueens.class: $(SRC_DIR)/$(MAIN_PACKAGE)/NQueens.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/NQueens.java"
NQueens: $(BUILD_DIR)/$(MAIN_PACKAGE)/NQueens.class
	$(RUN_CMD) $(MAIN_PACKAGE).NQueens $(PROGRAM_ARGS)



# NearestRepeatedEntries.java

.PHONY: NearestRepeatedEntries
$(BUILD_DIR)/$(MAIN_PACKAGE)/NearestRepeatedEntries.class: $(SRC_DIR)/$(MAIN_PACKAGE)/NearestRepeatedEntries.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/NearestRepeatedEntries.java"
NearestRepeatedEntries: $(BUILD_DIR)/$(MAIN_PACKAGE)/NearestRepeatedEntries.class
	$(RUN_CMD) $(MAIN_PACKAGE).NearestRepeatedEntries $(PROGRAM_ARGS)



# NextPermutation.java

.PHONY: NextPermutation
$(BUILD_DIR)/$(MAIN_PACKAGE)/NextPermutation.class: $(SRC_DIR)/$(MAIN_PACKAGE)/NextPermutation.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/NextPermutation.java"
NextPermutation: $(BUILD_DIR)/$(MAIN_PACKAGE)/NextPermutation.class
	$(RUN_CMD) $(MAIN_PACKAGE).NextPermutation $(PROGRAM_ARGS)



# NonuniformRandomNumber.java

.PHONY: NonuniformRandomNumber
$(BUILD_DIR)/$(MAIN_PACKAGE)/NonuniformRandomNumber.class: $(SRC_DIR)/$(MAIN_PACKAGE)/NonuniformRandomNumber.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/NonuniformRandomNumber.java"
NonuniformRandomNumber: $(BUILD_DIR)/$(MAIN_PACKAGE)/NonuniformRandomNumber.class
	$(RUN_CMD) $(MAIN_PACKAGE).NonuniformRandomNumber $(PROGRAM_ARGS)



# NumberOfScoreCombinations.java

.PHONY: NumberOfScoreCombinations
$(BUILD_DIR)/$(MAIN_PACKAGE)/NumberOfScoreCombinations.class: $(SRC_DIR)/$(MAIN_PACKAGE)/NumberOfScoreCombinations.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/NumberOfScoreCombinations.java"
NumberOfScoreCombinations: $(BUILD_DIR)/$(MAIN_PACKAGE)/NumberOfScoreCombinations.class
	$(RUN_CMD) $(MAIN_PACKAGE).NumberOfScoreCombinations $(PROGRAM_ARGS)



# NumberOfTraversalsMatrix.java

.PHONY: NumberOfTraversalsMatrix
$(BUILD_DIR)/$(MAIN_PACKAGE)/NumberOfTraversalsMatrix.class: $(SRC_DIR)/$(MAIN_PACKAGE)/NumberOfTraversalsMatrix.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/NumberOfTraversalsMatrix.java"
NumberOfTraversalsMatrix: $(BUILD_DIR)/$(MAIN_PACKAGE)/NumberOfTraversalsMatrix.class
	$(RUN_CMD) $(MAIN_PACKAGE).NumberOfTraversalsMatrix $(PROGRAM_ARGS)



# NumberOfTraversalsStaircase.java

.PHONY: NumberOfTraversalsStaircase
$(BUILD_DIR)/$(MAIN_PACKAGE)/NumberOfTraversalsStaircase.class: $(SRC_DIR)/$(MAIN_PACKAGE)/NumberOfTraversalsStaircase.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/NumberOfTraversalsStaircase.java"
NumberOfTraversalsStaircase: $(BUILD_DIR)/$(MAIN_PACKAGE)/NumberOfTraversalsStaircase.class
	$(RUN_CMD) $(MAIN_PACKAGE).NumberOfTraversalsStaircase $(PROGRAM_ARGS)



# OfflineSampling.java

.PHONY: OfflineSampling
$(BUILD_DIR)/$(MAIN_PACKAGE)/OfflineSampling.class: $(SRC_DIR)/$(MAIN_PACKAGE)/OfflineSampling.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/OfflineSampling.java"
OfflineSampling: $(BUILD_DIR)/$(MAIN_PACKAGE)/OfflineSampling.class
	$(RUN_CMD) $(MAIN_PACKAGE).OfflineSampling $(PROGRAM_ARGS)



# OnlineMedian.java

.PHONY: OnlineMedian
$(BUILD_DIR)/$(MAIN_PACKAGE)/OnlineMedian.class: $(SRC_DIR)/$(MAIN_PACKAGE)/OnlineMedian.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/OnlineMedian.java"
OnlineMedian: $(BUILD_DIR)/$(MAIN_PACKAGE)/OnlineMedian.class
	$(RUN_CMD) $(MAIN_PACKAGE).OnlineMedian $(PROGRAM_ARGS)



# OnlineSampling.java

.PHONY: OnlineSampling
$(BUILD_DIR)/$(MAIN_PACKAGE)/OnlineSampling.class: $(SRC_DIR)/$(MAIN_PACKAGE)/OnlineSampling.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/OnlineSampling.java"
OnlineSampling: $(BUILD_DIR)/$(MAIN_PACKAGE)/OnlineSampling.class
	$(RUN_CMD) $(MAIN_PACKAGE).OnlineSampling $(PROGRAM_ARGS)



# Parity.java

.PHONY: Parity
$(BUILD_DIR)/$(MAIN_PACKAGE)/Parity.class: $(SRC_DIR)/$(MAIN_PACKAGE)/Parity.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/Parity.java"
Parity: $(BUILD_DIR)/$(MAIN_PACKAGE)/Parity.class
	$(RUN_CMD) $(MAIN_PACKAGE).Parity $(PROGRAM_ARGS)



# PascalTriangle.java

.PHONY: PascalTriangle
$(BUILD_DIR)/$(MAIN_PACKAGE)/PascalTriangle.class: $(SRC_DIR)/$(MAIN_PACKAGE)/PascalTriangle.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/PascalTriangle.java"
PascalTriangle: $(BUILD_DIR)/$(MAIN_PACKAGE)/PascalTriangle.class
	$(RUN_CMD) $(MAIN_PACKAGE).PascalTriangle $(PROGRAM_ARGS)



# PathSum.java

.PHONY: PathSum
$(BUILD_DIR)/$(MAIN_PACKAGE)/PathSum.class: $(SRC_DIR)/$(MAIN_PACKAGE)/PathSum.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/PathSum.java"
PathSum: $(BUILD_DIR)/$(MAIN_PACKAGE)/PathSum.class
	$(RUN_CMD) $(MAIN_PACKAGE).PathSum $(PROGRAM_ARGS)



# Permutations.java

.PHONY: Permutations
$(BUILD_DIR)/$(MAIN_PACKAGE)/Permutations.class: $(SRC_DIR)/$(MAIN_PACKAGE)/Permutations.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/Permutations.java"
Permutations: $(BUILD_DIR)/$(MAIN_PACKAGE)/Permutations.class
	$(RUN_CMD) $(MAIN_PACKAGE).Permutations $(PROGRAM_ARGS)



# PhoneNumberMnemonic.java

.PHONY: PhoneNumberMnemonic
$(BUILD_DIR)/$(MAIN_PACKAGE)/PhoneNumberMnemonic.class: $(SRC_DIR)/$(MAIN_PACKAGE)/PhoneNumberMnemonic.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/PhoneNumberMnemonic.java"
PhoneNumberMnemonic: $(BUILD_DIR)/$(MAIN_PACKAGE)/PhoneNumberMnemonic.class
	$(RUN_CMD) $(MAIN_PACKAGE).PhoneNumberMnemonic $(PROGRAM_ARGS)



# PickingUpCoins.java

.PHONY: PickingUpCoins
$(BUILD_DIR)/$(MAIN_PACKAGE)/PickingUpCoins.class: $(SRC_DIR)/$(MAIN_PACKAGE)/PickingUpCoins.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/PickingUpCoins.java"
PickingUpCoins: $(BUILD_DIR)/$(MAIN_PACKAGE)/PickingUpCoins.class
	$(RUN_CMD) $(MAIN_PACKAGE).PickingUpCoins $(PROGRAM_ARGS)



# PivotList.java

.PHONY: PivotList
$(BUILD_DIR)/$(MAIN_PACKAGE)/PivotList.class: $(SRC_DIR)/$(MAIN_PACKAGE)/PivotList.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/PivotList.java"
PivotList: $(BUILD_DIR)/$(MAIN_PACKAGE)/PivotList.class
	$(RUN_CMD) $(MAIN_PACKAGE).PivotList $(PROGRAM_ARGS)



# PowerSet.java

.PHONY: PowerSet
$(BUILD_DIR)/$(MAIN_PACKAGE)/PowerSet.class: $(SRC_DIR)/$(MAIN_PACKAGE)/PowerSet.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/PowerSet.java"
PowerSet: $(BUILD_DIR)/$(MAIN_PACKAGE)/PowerSet.class
	$(RUN_CMD) $(MAIN_PACKAGE).PowerSet $(PROGRAM_ARGS)



# PowerXY.java

.PHONY: PowerXY
$(BUILD_DIR)/$(MAIN_PACKAGE)/PowerXY.class: $(SRC_DIR)/$(MAIN_PACKAGE)/PowerXY.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/PowerXY.java"
PowerXY: $(BUILD_DIR)/$(MAIN_PACKAGE)/PowerXY.class
	$(RUN_CMD) $(MAIN_PACKAGE).PowerXY $(PROGRAM_ARGS)



# PrettyPrinting.java

.PHONY: PrettyPrinting
$(BUILD_DIR)/$(MAIN_PACKAGE)/PrettyPrinting.class: $(SRC_DIR)/$(MAIN_PACKAGE)/PrettyPrinting.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/PrettyPrinting.java"
PrettyPrinting: $(BUILD_DIR)/$(MAIN_PACKAGE)/PrettyPrinting.class
	$(RUN_CMD) $(MAIN_PACKAGE).PrettyPrinting $(PROGRAM_ARGS)



# PrimeSieve.java

.PHONY: PrimeSieve
$(BUILD_DIR)/$(MAIN_PACKAGE)/PrimeSieve.class: $(SRC_DIR)/$(MAIN_PACKAGE)/PrimeSieve.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/PrimeSieve.java"
PrimeSieve: $(BUILD_DIR)/$(MAIN_PACKAGE)/PrimeSieve.class
	$(RUN_CMD) $(MAIN_PACKAGE).PrimeSieve $(PROGRAM_ARGS)



# PrimitiveDivide.java

.PHONY: PrimitiveDivide
$(BUILD_DIR)/$(MAIN_PACKAGE)/PrimitiveDivide.class: $(SRC_DIR)/$(MAIN_PACKAGE)/PrimitiveDivide.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/PrimitiveDivide.java"
PrimitiveDivide: $(BUILD_DIR)/$(MAIN_PACKAGE)/PrimitiveDivide.class
	$(RUN_CMD) $(MAIN_PACKAGE).PrimitiveDivide $(PROGRAM_ARGS)



# PrimitiveMultiply.java

.PHONY: PrimitiveMultiply
$(BUILD_DIR)/$(MAIN_PACKAGE)/PrimitiveMultiply.class: $(SRC_DIR)/$(MAIN_PACKAGE)/PrimitiveMultiply.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/PrimitiveMultiply.java"
PrimitiveMultiply: $(BUILD_DIR)/$(MAIN_PACKAGE)/PrimitiveMultiply.class
	$(RUN_CMD) $(MAIN_PACKAGE).PrimitiveMultiply $(PROGRAM_ARGS)



# QueueFromStacks.java

.PHONY: QueueFromStacks
$(BUILD_DIR)/$(MAIN_PACKAGE)/QueueFromStacks.class: $(SRC_DIR)/$(MAIN_PACKAGE)/QueueFromStacks.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/QueueFromStacks.java"
QueueFromStacks: $(BUILD_DIR)/$(MAIN_PACKAGE)/QueueFromStacks.class
	$(RUN_CMD) $(MAIN_PACKAGE).QueueFromStacks $(PROGRAM_ARGS)



# QueueWithMax.java

.PHONY: QueueWithMax
$(BUILD_DIR)/$(MAIN_PACKAGE)/QueueWithMax.class: $(SRC_DIR)/$(MAIN_PACKAGE)/QueueWithMax.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/QueueWithMax.java"
QueueWithMax: $(BUILD_DIR)/$(MAIN_PACKAGE)/QueueWithMax.class
	$(RUN_CMD) $(MAIN_PACKAGE).QueueWithMax $(PROGRAM_ARGS)



# RandomPermutation.java

.PHONY: RandomPermutation
$(BUILD_DIR)/$(MAIN_PACKAGE)/RandomPermutation.class: $(SRC_DIR)/$(MAIN_PACKAGE)/RandomPermutation.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/RandomPermutation.java"
RandomPermutation: $(BUILD_DIR)/$(MAIN_PACKAGE)/RandomPermutation.class
	$(RUN_CMD) $(MAIN_PACKAGE).RandomPermutation $(PROGRAM_ARGS)



# RandomSubset.java

.PHONY: RandomSubset
$(BUILD_DIR)/$(MAIN_PACKAGE)/RandomSubset.class: $(SRC_DIR)/$(MAIN_PACKAGE)/RandomSubset.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/RandomSubset.java"
RandomSubset: $(BUILD_DIR)/$(MAIN_PACKAGE)/RandomSubset.class
	$(RUN_CMD) $(MAIN_PACKAGE).RandomSubset $(PROGRAM_ARGS)



# RangeLookupInBst.java

.PHONY: RangeLookupInBst
$(BUILD_DIR)/$(MAIN_PACKAGE)/RangeLookupInBst.class: $(SRC_DIR)/$(MAIN_PACKAGE)/RangeLookupInBst.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/RangeLookupInBst.java"
RangeLookupInBst: $(BUILD_DIR)/$(MAIN_PACKAGE)/RangeLookupInBst.class
	$(RUN_CMD) $(MAIN_PACKAGE).RangeLookupInBst $(PROGRAM_ARGS)



# RealSquareRoot.java

.PHONY: RealSquareRoot
$(BUILD_DIR)/$(MAIN_PACKAGE)/RealSquareRoot.class: $(SRC_DIR)/$(MAIN_PACKAGE)/RealSquareRoot.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/RealSquareRoot.java"
RealSquareRoot: $(BUILD_DIR)/$(MAIN_PACKAGE)/RealSquareRoot.class
	$(RUN_CMD) $(MAIN_PACKAGE).RealSquareRoot $(PROGRAM_ARGS)



# RectangleIntersection.java

.PHONY: RectangleIntersection
$(BUILD_DIR)/$(MAIN_PACKAGE)/RectangleIntersection.class: $(SRC_DIR)/$(MAIN_PACKAGE)/RectangleIntersection.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/RectangleIntersection.java"
RectangleIntersection: $(BUILD_DIR)/$(MAIN_PACKAGE)/RectangleIntersection.class
	$(RUN_CMD) $(MAIN_PACKAGE).RectangleIntersection $(PROGRAM_ARGS)



# RefuelingSchedule.java

.PHONY: RefuelingSchedule
$(BUILD_DIR)/$(MAIN_PACKAGE)/RefuelingSchedule.class: $(SRC_DIR)/$(MAIN_PACKAGE)/RefuelingSchedule.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/RefuelingSchedule.java"
RefuelingSchedule: $(BUILD_DIR)/$(MAIN_PACKAGE)/RefuelingSchedule.class
	$(RUN_CMD) $(MAIN_PACKAGE).RefuelingSchedule $(PROGRAM_ARGS)



# RegularExpression.java

.PHONY: RegularExpression
$(BUILD_DIR)/$(MAIN_PACKAGE)/RegularExpression.class: $(SRC_DIR)/$(MAIN_PACKAGE)/RegularExpression.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/RegularExpression.java"
RegularExpression: $(BUILD_DIR)/$(MAIN_PACKAGE)/RegularExpression.class
	$(RUN_CMD) $(MAIN_PACKAGE).RegularExpression $(PROGRAM_ARGS)



# RemoveDuplicates.java

.PHONY: RemoveDuplicates
$(BUILD_DIR)/$(MAIN_PACKAGE)/RemoveDuplicates.class: $(SRC_DIR)/$(MAIN_PACKAGE)/RemoveDuplicates.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/RemoveDuplicates.java"
RemoveDuplicates: $(BUILD_DIR)/$(MAIN_PACKAGE)/RemoveDuplicates.class
	$(RUN_CMD) $(MAIN_PACKAGE).RemoveDuplicates $(PROGRAM_ARGS)



# RemoveDuplicatesFromSortedList.java

.PHONY: RemoveDuplicatesFromSortedList
$(BUILD_DIR)/$(MAIN_PACKAGE)/RemoveDuplicatesFromSortedList.class: $(SRC_DIR)/$(MAIN_PACKAGE)/RemoveDuplicatesFromSortedList.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/RemoveDuplicatesFromSortedList.java"
RemoveDuplicatesFromSortedList: $(BUILD_DIR)/$(MAIN_PACKAGE)/RemoveDuplicatesFromSortedList.class
	$(RUN_CMD) $(MAIN_PACKAGE).RemoveDuplicatesFromSortedList $(PROGRAM_ARGS)



# ReplaceAndRemove.java

.PHONY: ReplaceAndRemove
$(BUILD_DIR)/$(MAIN_PACKAGE)/ReplaceAndRemove.class: $(SRC_DIR)/$(MAIN_PACKAGE)/ReplaceAndRemove.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/ReplaceAndRemove.java"
ReplaceAndRemove: $(BUILD_DIR)/$(MAIN_PACKAGE)/ReplaceAndRemove.class
	$(RUN_CMD) $(MAIN_PACKAGE).ReplaceAndRemove $(PROGRAM_ARGS)



# ReverseBits.java

.PHONY: ReverseBits
$(BUILD_DIR)/$(MAIN_PACKAGE)/ReverseBits.class: $(SRC_DIR)/$(MAIN_PACKAGE)/ReverseBits.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/ReverseBits.java"
ReverseBits: $(BUILD_DIR)/$(MAIN_PACKAGE)/ReverseBits.class
	$(RUN_CMD) $(MAIN_PACKAGE).ReverseBits $(PROGRAM_ARGS)



# ReverseDigits.java

.PHONY: ReverseDigits
$(BUILD_DIR)/$(MAIN_PACKAGE)/ReverseDigits.class: $(SRC_DIR)/$(MAIN_PACKAGE)/ReverseDigits.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/ReverseDigits.java"
ReverseDigits: $(BUILD_DIR)/$(MAIN_PACKAGE)/ReverseDigits.class
	$(RUN_CMD) $(MAIN_PACKAGE).ReverseDigits $(PROGRAM_ARGS)



# ReverseSublist.java

.PHONY: ReverseSublist
$(BUILD_DIR)/$(MAIN_PACKAGE)/ReverseSublist.class: $(SRC_DIR)/$(MAIN_PACKAGE)/ReverseSublist.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/ReverseSublist.java"
ReverseSublist: $(BUILD_DIR)/$(MAIN_PACKAGE)/ReverseSublist.class
	$(RUN_CMD) $(MAIN_PACKAGE).ReverseSublist $(PROGRAM_ARGS)



# ReverseWords.java

.PHONY: ReverseWords
$(BUILD_DIR)/$(MAIN_PACKAGE)/ReverseWords.class: $(SRC_DIR)/$(MAIN_PACKAGE)/ReverseWords.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/ReverseWords.java"
ReverseWords: $(BUILD_DIR)/$(MAIN_PACKAGE)/ReverseWords.class
	$(RUN_CMD) $(MAIN_PACKAGE).ReverseWords $(PROGRAM_ARGS)



# RoadNetwork.java

.PHONY: RoadNetwork
$(BUILD_DIR)/$(MAIN_PACKAGE)/RoadNetwork.class: $(SRC_DIR)/$(MAIN_PACKAGE)/RoadNetwork.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/RoadNetwork.java"
RoadNetwork: $(BUILD_DIR)/$(MAIN_PACKAGE)/RoadNetwork.class
	$(RUN_CMD) $(MAIN_PACKAGE).RoadNetwork $(PROGRAM_ARGS)



# RomanToInteger.java

.PHONY: RomanToInteger
$(BUILD_DIR)/$(MAIN_PACKAGE)/RomanToInteger.class: $(SRC_DIR)/$(MAIN_PACKAGE)/RomanToInteger.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/RomanToInteger.java"
RomanToInteger: $(BUILD_DIR)/$(MAIN_PACKAGE)/RomanToInteger.class
	$(RUN_CMD) $(MAIN_PACKAGE).RomanToInteger $(PROGRAM_ARGS)



# RookAttack.java

.PHONY: RookAttack
$(BUILD_DIR)/$(MAIN_PACKAGE)/RookAttack.class: $(SRC_DIR)/$(MAIN_PACKAGE)/RookAttack.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/RookAttack.java"
RookAttack: $(BUILD_DIR)/$(MAIN_PACKAGE)/RookAttack.class
	$(RUN_CMD) $(MAIN_PACKAGE).RookAttack $(PROGRAM_ARGS)



# RotateArray.java

.PHONY: RotateArray
$(BUILD_DIR)/$(MAIN_PACKAGE)/RotateArray.class: $(SRC_DIR)/$(MAIN_PACKAGE)/RotateArray.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/RotateArray.java"
RotateArray: $(BUILD_DIR)/$(MAIN_PACKAGE)/RotateArray.class
	$(RUN_CMD) $(MAIN_PACKAGE).RotateArray $(PROGRAM_ARGS)



# RunLengthCompression.java

.PHONY: RunLengthCompression
$(BUILD_DIR)/$(MAIN_PACKAGE)/RunLengthCompression.class: $(SRC_DIR)/$(MAIN_PACKAGE)/RunLengthCompression.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/RunLengthCompression.java"
RunLengthCompression: $(BUILD_DIR)/$(MAIN_PACKAGE)/RunLengthCompression.class
	$(RUN_CMD) $(MAIN_PACKAGE).RunLengthCompression $(PROGRAM_ARGS)



# SearchEntryEqualToIndex.java

.PHONY: SearchEntryEqualToIndex
$(BUILD_DIR)/$(MAIN_PACKAGE)/SearchEntryEqualToIndex.class: $(SRC_DIR)/$(MAIN_PACKAGE)/SearchEntryEqualToIndex.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/SearchEntryEqualToIndex.java"
SearchEntryEqualToIndex: $(BUILD_DIR)/$(MAIN_PACKAGE)/SearchEntryEqualToIndex.class
	$(RUN_CMD) $(MAIN_PACKAGE).SearchEntryEqualToIndex $(PROGRAM_ARGS)



# SearchFirstGreaterValueInBst.java

.PHONY: SearchFirstGreaterValueInBst
$(BUILD_DIR)/$(MAIN_PACKAGE)/SearchFirstGreaterValueInBst.class: $(SRC_DIR)/$(MAIN_PACKAGE)/SearchFirstGreaterValueInBst.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/SearchFirstGreaterValueInBst.java"
SearchFirstGreaterValueInBst: $(BUILD_DIR)/$(MAIN_PACKAGE)/SearchFirstGreaterValueInBst.class
	$(RUN_CMD) $(MAIN_PACKAGE).SearchFirstGreaterValueInBst $(PROGRAM_ARGS)



# SearchFirstKey.java

.PHONY: SearchFirstKey
$(BUILD_DIR)/$(MAIN_PACKAGE)/SearchFirstKey.class: $(SRC_DIR)/$(MAIN_PACKAGE)/SearchFirstKey.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/SearchFirstKey.java"
SearchFirstKey: $(BUILD_DIR)/$(MAIN_PACKAGE)/SearchFirstKey.class
	$(RUN_CMD) $(MAIN_PACKAGE).SearchFirstKey $(PROGRAM_ARGS)



# SearchForMinMaxInArray.java

.PHONY: SearchForMinMaxInArray
$(BUILD_DIR)/$(MAIN_PACKAGE)/SearchForMinMaxInArray.class: $(SRC_DIR)/$(MAIN_PACKAGE)/SearchForMinMaxInArray.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/SearchForMinMaxInArray.java"
SearchForMinMaxInArray: $(BUILD_DIR)/$(MAIN_PACKAGE)/SearchForMinMaxInArray.class
	$(RUN_CMD) $(MAIN_PACKAGE).SearchForMinMaxInArray $(PROGRAM_ARGS)



# SearchForMissingElement.java

.PHONY: SearchForMissingElement
$(BUILD_DIR)/$(MAIN_PACKAGE)/SearchForMissingElement.class: $(SRC_DIR)/$(MAIN_PACKAGE)/SearchForMissingElement.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/SearchForMissingElement.java"
SearchForMissingElement: $(BUILD_DIR)/$(MAIN_PACKAGE)/SearchForMissingElement.class
	$(RUN_CMD) $(MAIN_PACKAGE).SearchForMissingElement $(PROGRAM_ARGS)



# SearchFrequentItems.java

.PHONY: SearchFrequentItems
$(BUILD_DIR)/$(MAIN_PACKAGE)/SearchFrequentItems.class: $(SRC_DIR)/$(MAIN_PACKAGE)/SearchFrequentItems.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/SearchFrequentItems.java"
SearchFrequentItems: $(BUILD_DIR)/$(MAIN_PACKAGE)/SearchFrequentItems.class
	$(RUN_CMD) $(MAIN_PACKAGE).SearchFrequentItems $(PROGRAM_ARGS)



# SearchInBst.java

.PHONY: SearchInBst
$(BUILD_DIR)/$(MAIN_PACKAGE)/SearchInBst.class: $(SRC_DIR)/$(MAIN_PACKAGE)/SearchInBst.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/SearchInBst.java"
SearchInBst: $(BUILD_DIR)/$(MAIN_PACKAGE)/SearchInBst.class
	$(RUN_CMD) $(MAIN_PACKAGE).SearchInBst $(PROGRAM_ARGS)



# SearchInList.java

.PHONY: SearchInList
$(BUILD_DIR)/$(MAIN_PACKAGE)/SearchInList.class: $(SRC_DIR)/$(MAIN_PACKAGE)/SearchInList.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/SearchInList.java"
SearchInList: $(BUILD_DIR)/$(MAIN_PACKAGE)/SearchInList.class
	$(RUN_CMD) $(MAIN_PACKAGE).SearchInList $(PROGRAM_ARGS)



# SearchMaze.java

.PHONY: SearchMaze
$(BUILD_DIR)/$(MAIN_PACKAGE)/SearchMaze.class: $(SRC_DIR)/$(MAIN_PACKAGE)/SearchMaze.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/SearchMaze.java"
SearchMaze: $(BUILD_DIR)/$(MAIN_PACKAGE)/SearchMaze.class
	$(RUN_CMD) $(MAIN_PACKAGE).SearchMaze $(PROGRAM_ARGS)



# SearchRowColSortedMatrix.java

.PHONY: SearchRowColSortedMatrix
$(BUILD_DIR)/$(MAIN_PACKAGE)/SearchRowColSortedMatrix.class: $(SRC_DIR)/$(MAIN_PACKAGE)/SearchRowColSortedMatrix.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/SearchRowColSortedMatrix.java"
SearchRowColSortedMatrix: $(BUILD_DIR)/$(MAIN_PACKAGE)/SearchRowColSortedMatrix.class
	$(RUN_CMD) $(MAIN_PACKAGE).SearchRowColSortedMatrix $(PROGRAM_ARGS)



# SearchShiftedSortedArray.java

.PHONY: SearchShiftedSortedArray
$(BUILD_DIR)/$(MAIN_PACKAGE)/SearchShiftedSortedArray.class: $(SRC_DIR)/$(MAIN_PACKAGE)/SearchShiftedSortedArray.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/SearchShiftedSortedArray.java"
SearchShiftedSortedArray: $(BUILD_DIR)/$(MAIN_PACKAGE)/SearchShiftedSortedArray.class
	$(RUN_CMD) $(MAIN_PACKAGE).SearchShiftedSortedArray $(PROGRAM_ARGS)



# SearchUnknownLengthArray.java

.PHONY: SearchUnknownLengthArray
$(BUILD_DIR)/$(MAIN_PACKAGE)/SearchUnknownLengthArray.class: $(SRC_DIR)/$(MAIN_PACKAGE)/SearchUnknownLengthArray.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/SearchUnknownLengthArray.java"
SearchUnknownLengthArray: $(BUILD_DIR)/$(MAIN_PACKAGE)/SearchUnknownLengthArray.class
	$(RUN_CMD) $(MAIN_PACKAGE).SearchUnknownLengthArray $(PROGRAM_ARGS)



# SmallestNonconstructibleValue.java

.PHONY: SmallestNonconstructibleValue
$(BUILD_DIR)/$(MAIN_PACKAGE)/SmallestNonconstructibleValue.class: $(SRC_DIR)/$(MAIN_PACKAGE)/SmallestNonconstructibleValue.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/SmallestNonconstructibleValue.java"
SmallestNonconstructibleValue: $(BUILD_DIR)/$(MAIN_PACKAGE)/SmallestNonconstructibleValue.class
	$(RUN_CMD) $(MAIN_PACKAGE).SmallestNonconstructibleValue $(PROGRAM_ARGS)



# SmallestSubarrayCoveringAllValues.java

.PHONY: SmallestSubarrayCoveringAllValues
$(BUILD_DIR)/$(MAIN_PACKAGE)/SmallestSubarrayCoveringAllValues.class: $(SRC_DIR)/$(MAIN_PACKAGE)/SmallestSubarrayCoveringAllValues.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/SmallestSubarrayCoveringAllValues.java"
SmallestSubarrayCoveringAllValues: $(BUILD_DIR)/$(MAIN_PACKAGE)/SmallestSubarrayCoveringAllValues.class
	$(RUN_CMD) $(MAIN_PACKAGE).SmallestSubarrayCoveringAllValues $(PROGRAM_ARGS)



# SmallestSubarrayCoveringSet.java

.PHONY: SmallestSubarrayCoveringSet
$(BUILD_DIR)/$(MAIN_PACKAGE)/SmallestSubarrayCoveringSet.class: $(SRC_DIR)/$(MAIN_PACKAGE)/SmallestSubarrayCoveringSet.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/SmallestSubarrayCoveringSet.java"
SmallestSubarrayCoveringSet: $(BUILD_DIR)/$(MAIN_PACKAGE)/SmallestSubarrayCoveringSet.class
	$(RUN_CMD) $(MAIN_PACKAGE).SmallestSubarrayCoveringSet $(PROGRAM_ARGS)



# SnakeString.java

.PHONY: SnakeString
$(BUILD_DIR)/$(MAIN_PACKAGE)/SnakeString.class: $(SRC_DIR)/$(MAIN_PACKAGE)/SnakeString.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/SnakeString.java"
SnakeString: $(BUILD_DIR)/$(MAIN_PACKAGE)/SnakeString.class
	$(RUN_CMD) $(MAIN_PACKAGE).SnakeString $(PROGRAM_ARGS)



# SortAlmostSortedArray.java

.PHONY: SortAlmostSortedArray
$(BUILD_DIR)/$(MAIN_PACKAGE)/SortAlmostSortedArray.class: $(SRC_DIR)/$(MAIN_PACKAGE)/SortAlmostSortedArray.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/SortAlmostSortedArray.java"
SortAlmostSortedArray: $(BUILD_DIR)/$(MAIN_PACKAGE)/SortAlmostSortedArray.class
	$(RUN_CMD) $(MAIN_PACKAGE).SortAlmostSortedArray $(PROGRAM_ARGS)



# SortIncreasingDecreasingArray.java

.PHONY: SortIncreasingDecreasingArray
$(BUILD_DIR)/$(MAIN_PACKAGE)/SortIncreasingDecreasingArray.class: $(SRC_DIR)/$(MAIN_PACKAGE)/SortIncreasingDecreasingArray.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/SortIncreasingDecreasingArray.java"
SortIncreasingDecreasingArray: $(BUILD_DIR)/$(MAIN_PACKAGE)/SortIncreasingDecreasingArray.class
	$(RUN_CMD) $(MAIN_PACKAGE).SortIncreasingDecreasingArray $(PROGRAM_ARGS)



# SortList.java

.PHONY: SortList
$(BUILD_DIR)/$(MAIN_PACKAGE)/SortList.class: $(SRC_DIR)/$(MAIN_PACKAGE)/SortList.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/SortList.java"
SortList: $(BUILD_DIR)/$(MAIN_PACKAGE)/SortList.class
	$(RUN_CMD) $(MAIN_PACKAGE).SortList $(PROGRAM_ARGS)



# SortedArrayRemoveDups.java

.PHONY: SortedArrayRemoveDups
$(BUILD_DIR)/$(MAIN_PACKAGE)/SortedArrayRemoveDups.class: $(SRC_DIR)/$(MAIN_PACKAGE)/SortedArrayRemoveDups.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/SortedArrayRemoveDups.java"
SortedArrayRemoveDups: $(BUILD_DIR)/$(MAIN_PACKAGE)/SortedArrayRemoveDups.class
	$(RUN_CMD) $(MAIN_PACKAGE).SortedArrayRemoveDups $(PROGRAM_ARGS)



# SortedArraysMerge.java

.PHONY: SortedArraysMerge
$(BUILD_DIR)/$(MAIN_PACKAGE)/SortedArraysMerge.class: $(SRC_DIR)/$(MAIN_PACKAGE)/SortedArraysMerge.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/SortedArraysMerge.java"
SortedArraysMerge: $(BUILD_DIR)/$(MAIN_PACKAGE)/SortedArraysMerge.class
	$(RUN_CMD) $(MAIN_PACKAGE).SortedArraysMerge $(PROGRAM_ARGS)



# SortedListToBst.java

.PHONY: SortedListToBst
$(BUILD_DIR)/$(MAIN_PACKAGE)/SortedListToBst.class: $(SRC_DIR)/$(MAIN_PACKAGE)/SortedListToBst.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/SortedListToBst.java"
SortedListToBst: $(BUILD_DIR)/$(MAIN_PACKAGE)/SortedListToBst.class
	$(RUN_CMD) $(MAIN_PACKAGE).SortedListToBst $(PROGRAM_ARGS)



# SortedListsMerge.java

.PHONY: SortedListsMerge
$(BUILD_DIR)/$(MAIN_PACKAGE)/SortedListsMerge.class: $(SRC_DIR)/$(MAIN_PACKAGE)/SortedListsMerge.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/SortedListsMerge.java"
SortedListsMerge: $(BUILD_DIR)/$(MAIN_PACKAGE)/SortedListsMerge.class
	$(RUN_CMD) $(MAIN_PACKAGE).SortedListsMerge $(PROGRAM_ARGS)



# SpiralOrdering.java

.PHONY: SpiralOrdering
$(BUILD_DIR)/$(MAIN_PACKAGE)/SpiralOrdering.class: $(SRC_DIR)/$(MAIN_PACKAGE)/SpiralOrdering.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/SpiralOrdering.java"
SpiralOrdering: $(BUILD_DIR)/$(MAIN_PACKAGE)/SpiralOrdering.class
	$(RUN_CMD) $(MAIN_PACKAGE).SpiralOrdering $(PROGRAM_ARGS)



# SpreadsheetEncoding.java

.PHONY: SpreadsheetEncoding
$(BUILD_DIR)/$(MAIN_PACKAGE)/SpreadsheetEncoding.class: $(SRC_DIR)/$(MAIN_PACKAGE)/SpreadsheetEncoding.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/SpreadsheetEncoding.java"
SpreadsheetEncoding: $(BUILD_DIR)/$(MAIN_PACKAGE)/SpreadsheetEncoding.class
	$(RUN_CMD) $(MAIN_PACKAGE).SpreadsheetEncoding $(PROGRAM_ARGS)



# StackWithMax.java

.PHONY: StackWithMax
$(BUILD_DIR)/$(MAIN_PACKAGE)/StackWithMax.class: $(SRC_DIR)/$(MAIN_PACKAGE)/StackWithMax.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/StackWithMax.java"
StackWithMax: $(BUILD_DIR)/$(MAIN_PACKAGE)/StackWithMax.class
	$(RUN_CMD) $(MAIN_PACKAGE).StackWithMax $(PROGRAM_ARGS)



# StringDecompositionsIntoDictionaryWords.java

.PHONY: StringDecompositionsIntoDictionaryWords
$(BUILD_DIR)/$(MAIN_PACKAGE)/StringDecompositionsIntoDictionaryWords.class: $(SRC_DIR)/$(MAIN_PACKAGE)/StringDecompositionsIntoDictionaryWords.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/StringDecompositionsIntoDictionaryWords.java"
StringDecompositionsIntoDictionaryWords: $(BUILD_DIR)/$(MAIN_PACKAGE)/StringDecompositionsIntoDictionaryWords.class
	$(RUN_CMD) $(MAIN_PACKAGE).StringDecompositionsIntoDictionaryWords $(PROGRAM_ARGS)



# StringIntegerInterconversion.java

.PHONY: StringIntegerInterconversion
$(BUILD_DIR)/$(MAIN_PACKAGE)/StringIntegerInterconversion.class: $(SRC_DIR)/$(MAIN_PACKAGE)/StringIntegerInterconversion.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/StringIntegerInterconversion.java"
StringIntegerInterconversion: $(BUILD_DIR)/$(MAIN_PACKAGE)/StringIntegerInterconversion.class
	$(RUN_CMD) $(MAIN_PACKAGE).StringIntegerInterconversion $(PROGRAM_ARGS)



# StringTransformability.java

.PHONY: StringTransformability
$(BUILD_DIR)/$(MAIN_PACKAGE)/StringTransformability.class: $(SRC_DIR)/$(MAIN_PACKAGE)/StringTransformability.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/StringTransformability.java"
StringTransformability: $(BUILD_DIR)/$(MAIN_PACKAGE)/StringTransformability.class
	$(RUN_CMD) $(MAIN_PACKAGE).StringTransformability $(PROGRAM_ARGS)



# SubstringMatch.java

.PHONY: SubstringMatch
$(BUILD_DIR)/$(MAIN_PACKAGE)/SubstringMatch.class: $(SRC_DIR)/$(MAIN_PACKAGE)/SubstringMatch.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/SubstringMatch.java"
SubstringMatch: $(BUILD_DIR)/$(MAIN_PACKAGE)/SubstringMatch.class
	$(RUN_CMD) $(MAIN_PACKAGE).SubstringMatch $(PROGRAM_ARGS)



# SuccessorInTree.java

.PHONY: SuccessorInTree
$(BUILD_DIR)/$(MAIN_PACKAGE)/SuccessorInTree.class: $(SRC_DIR)/$(MAIN_PACKAGE)/SuccessorInTree.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/SuccessorInTree.java"
SuccessorInTree: $(BUILD_DIR)/$(MAIN_PACKAGE)/SuccessorInTree.class
	$(RUN_CMD) $(MAIN_PACKAGE).SuccessorInTree $(PROGRAM_ARGS)



# SudokuSolve.java

.PHONY: SudokuSolve
$(BUILD_DIR)/$(MAIN_PACKAGE)/SudokuSolve.class: $(SRC_DIR)/$(MAIN_PACKAGE)/SudokuSolve.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/SudokuSolve.java"
SudokuSolve: $(BUILD_DIR)/$(MAIN_PACKAGE)/SudokuSolve.class
	$(RUN_CMD) $(MAIN_PACKAGE).SudokuSolve $(PROGRAM_ARGS)



# SumRootToLeaf.java

.PHONY: SumRootToLeaf
$(BUILD_DIR)/$(MAIN_PACKAGE)/SumRootToLeaf.class: $(SRC_DIR)/$(MAIN_PACKAGE)/SumRootToLeaf.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/SumRootToLeaf.java"
SumRootToLeaf: $(BUILD_DIR)/$(MAIN_PACKAGE)/SumRootToLeaf.class
	$(RUN_CMD) $(MAIN_PACKAGE).SumRootToLeaf $(PROGRAM_ARGS)



# SunsetView.java

.PHONY: SunsetView
$(BUILD_DIR)/$(MAIN_PACKAGE)/SunsetView.class: $(SRC_DIR)/$(MAIN_PACKAGE)/SunsetView.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/SunsetView.java"
SunsetView: $(BUILD_DIR)/$(MAIN_PACKAGE)/SunsetView.class
	$(RUN_CMD) $(MAIN_PACKAGE).SunsetView $(PROGRAM_ARGS)



# SwapBits.java

.PHONY: SwapBits
$(BUILD_DIR)/$(MAIN_PACKAGE)/SwapBits.class: $(SRC_DIR)/$(MAIN_PACKAGE)/SwapBits.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/SwapBits.java"
SwapBits: $(BUILD_DIR)/$(MAIN_PACKAGE)/SwapBits.class
	$(RUN_CMD) $(MAIN_PACKAGE).SwapBits $(PROGRAM_ARGS)



# TaskPairing.java

.PHONY: TaskPairing
$(BUILD_DIR)/$(MAIN_PACKAGE)/TaskPairing.class: $(SRC_DIR)/$(MAIN_PACKAGE)/TaskPairing.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/TaskPairing.java"
TaskPairing: $(BUILD_DIR)/$(MAIN_PACKAGE)/TaskPairing.class
	$(RUN_CMD) $(MAIN_PACKAGE).TaskPairing $(PROGRAM_ARGS)



# ThreeSum.java

.PHONY: ThreeSum
$(BUILD_DIR)/$(MAIN_PACKAGE)/ThreeSum.class: $(SRC_DIR)/$(MAIN_PACKAGE)/ThreeSum.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/ThreeSum.java"
ThreeSum: $(BUILD_DIR)/$(MAIN_PACKAGE)/ThreeSum.class
	$(RUN_CMD) $(MAIN_PACKAGE).ThreeSum $(PROGRAM_ARGS)



# TreeConnectLeaves.java

.PHONY: TreeConnectLeaves
$(BUILD_DIR)/$(MAIN_PACKAGE)/TreeConnectLeaves.class: $(SRC_DIR)/$(MAIN_PACKAGE)/TreeConnectLeaves.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/TreeConnectLeaves.java"
TreeConnectLeaves: $(BUILD_DIR)/$(MAIN_PACKAGE)/TreeConnectLeaves.class
	$(RUN_CMD) $(MAIN_PACKAGE).TreeConnectLeaves $(PROGRAM_ARGS)



# TreeExterior.java

.PHONY: TreeExterior
$(BUILD_DIR)/$(MAIN_PACKAGE)/TreeExterior.class: $(SRC_DIR)/$(MAIN_PACKAGE)/TreeExterior.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/TreeExterior.java"
TreeExterior: $(BUILD_DIR)/$(MAIN_PACKAGE)/TreeExterior.class
	$(RUN_CMD) $(MAIN_PACKAGE).TreeExterior $(PROGRAM_ARGS)



# TreeFromPreorderInorder.java

.PHONY: TreeFromPreorderInorder
$(BUILD_DIR)/$(MAIN_PACKAGE)/TreeFromPreorderInorder.class: $(SRC_DIR)/$(MAIN_PACKAGE)/TreeFromPreorderInorder.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/TreeFromPreorderInorder.java"
TreeFromPreorderInorder: $(BUILD_DIR)/$(MAIN_PACKAGE)/TreeFromPreorderInorder.class
	$(RUN_CMD) $(MAIN_PACKAGE).TreeFromPreorderInorder $(PROGRAM_ARGS)



# TreeFromPreorderWithNull.java

.PHONY: TreeFromPreorderWithNull
$(BUILD_DIR)/$(MAIN_PACKAGE)/TreeFromPreorderWithNull.class: $(SRC_DIR)/$(MAIN_PACKAGE)/TreeFromPreorderWithNull.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/TreeFromPreorderWithNull.java"
TreeFromPreorderWithNull: $(BUILD_DIR)/$(MAIN_PACKAGE)/TreeFromPreorderWithNull.class
	$(RUN_CMD) $(MAIN_PACKAGE).TreeFromPreorderWithNull $(PROGRAM_ARGS)



# TreeInorder.java

.PHONY: TreeInorder
$(BUILD_DIR)/$(MAIN_PACKAGE)/TreeInorder.class: $(SRC_DIR)/$(MAIN_PACKAGE)/TreeInorder.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/TreeInorder.java"
TreeInorder: $(BUILD_DIR)/$(MAIN_PACKAGE)/TreeInorder.class
	$(RUN_CMD) $(MAIN_PACKAGE).TreeInorder $(PROGRAM_ARGS)



# TreeLevelOrder.java

.PHONY: TreeLevelOrder
$(BUILD_DIR)/$(MAIN_PACKAGE)/TreeLevelOrder.class: $(SRC_DIR)/$(MAIN_PACKAGE)/TreeLevelOrder.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/TreeLevelOrder.java"
TreeLevelOrder: $(BUILD_DIR)/$(MAIN_PACKAGE)/TreeLevelOrder.class
	$(RUN_CMD) $(MAIN_PACKAGE).TreeLevelOrder $(PROGRAM_ARGS)



# TreePostorder.java

.PHONY: TreePostorder
$(BUILD_DIR)/$(MAIN_PACKAGE)/TreePostorder.class: $(SRC_DIR)/$(MAIN_PACKAGE)/TreePostorder.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/TreePostorder.java"
TreePostorder: $(BUILD_DIR)/$(MAIN_PACKAGE)/TreePostorder.class
	$(RUN_CMD) $(MAIN_PACKAGE).TreePostorder $(PROGRAM_ARGS)



# TreePreorder.java

.PHONY: TreePreorder
$(BUILD_DIR)/$(MAIN_PACKAGE)/TreePreorder.class: $(SRC_DIR)/$(MAIN_PACKAGE)/TreePreorder.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/TreePreorder.java"
TreePreorder: $(BUILD_DIR)/$(MAIN_PACKAGE)/TreePreorder.class
	$(RUN_CMD) $(MAIN_PACKAGE).TreePreorder $(PROGRAM_ARGS)



# TreeRightSibling.java

.PHONY: TreeRightSibling
$(BUILD_DIR)/$(MAIN_PACKAGE)/TreeRightSibling.class: $(SRC_DIR)/$(MAIN_PACKAGE)/TreeRightSibling.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/TreeRightSibling.java"
TreeRightSibling: $(BUILD_DIR)/$(MAIN_PACKAGE)/TreeRightSibling.class
	$(RUN_CMD) $(MAIN_PACKAGE).TreeRightSibling $(PROGRAM_ARGS)



# TreeWithParentInorder.java

.PHONY: TreeWithParentInorder
$(BUILD_DIR)/$(MAIN_PACKAGE)/TreeWithParentInorder.class: $(SRC_DIR)/$(MAIN_PACKAGE)/TreeWithParentInorder.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/TreeWithParentInorder.java"
TreeWithParentInorder: $(BUILD_DIR)/$(MAIN_PACKAGE)/TreeWithParentInorder.class
	$(RUN_CMD) $(MAIN_PACKAGE).TreeWithParentInorder $(PROGRAM_ARGS)



# TwoSortedArraysMerge.java

.PHONY: TwoSortedArraysMerge
$(BUILD_DIR)/$(MAIN_PACKAGE)/TwoSortedArraysMerge.class: $(SRC_DIR)/$(MAIN_PACKAGE)/TwoSortedArraysMerge.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/TwoSortedArraysMerge.java"
TwoSortedArraysMerge: $(BUILD_DIR)/$(MAIN_PACKAGE)/TwoSortedArraysMerge.class
	$(RUN_CMD) $(MAIN_PACKAGE).TwoSortedArraysMerge $(PROGRAM_ARGS)



# TwoSum.java

.PHONY: TwoSum
$(BUILD_DIR)/$(MAIN_PACKAGE)/TwoSum.class: $(SRC_DIR)/$(MAIN_PACKAGE)/TwoSum.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/TwoSum.java"
TwoSum: $(BUILD_DIR)/$(MAIN_PACKAGE)/TwoSum.class
	$(RUN_CMD) $(MAIN_PACKAGE).TwoSum $(PROGRAM_ARGS)



# UniformRandomNumber.java

.PHONY: UniformRandomNumber
$(BUILD_DIR)/$(MAIN_PACKAGE)/UniformRandomNumber.class: $(SRC_DIR)/$(MAIN_PACKAGE)/UniformRandomNumber.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/UniformRandomNumber.java"
UniformRandomNumber: $(BUILD_DIR)/$(MAIN_PACKAGE)/UniformRandomNumber.class
	$(RUN_CMD) $(MAIN_PACKAGE).UniformRandomNumber $(PROGRAM_ARGS)



# ValidIpAddresses.java

.PHONY: ValidIpAddresses
$(BUILD_DIR)/$(MAIN_PACKAGE)/ValidIpAddresses.class: $(SRC_DIR)/$(MAIN_PACKAGE)/ValidIpAddresses.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/ValidIpAddresses.java"
ValidIpAddresses: $(BUILD_DIR)/$(MAIN_PACKAGE)/ValidIpAddresses.class
	$(RUN_CMD) $(MAIN_PACKAGE).ValidIpAddresses $(PROGRAM_ARGS)



# ZipList.java

.PHONY: ZipList
$(BUILD_DIR)/$(MAIN_PACKAGE)/ZipList.class: $(SRC_DIR)/$(MAIN_PACKAGE)/ZipList.java $(TEST_FRAMEWORK)
	$(JAVAC_CMD) "$(SRC_DIR)/$(MAIN_PACKAGE)/ZipList.java"
ZipList: $(BUILD_DIR)/$(MAIN_PACKAGE)/ZipList.class
	$(RUN_CMD) $(MAIN_PACKAGE).ZipList $(PROGRAM_ARGS)

.PHONY: all
all: \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/ABSqrt2.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/AbsentValueArray.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/AddingCredits.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/AdvanceByOffsets.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/AlternatingArray.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/Anagrams.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/ApplyPermutation.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/Arbitrage.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/BinomialCoefficients.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/Bonus.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/BstFromPreorder.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/BstFromSortedArray.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/BstMerge.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/BstToSortedList.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/BuyAndSellStock.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/BuyAndSellStockKTimes.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/BuyAndSellStockTwice.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/CalendarRendering.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/CircularQueue.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/ClosestIntSameWeight.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/CollatzChecker.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/Combinations.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/ConvertBase.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/CopyPostingList.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/CountBits.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/CountInversions.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/DeadlockDetection.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/DefectiveJugs.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/DeleteFromList.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/DeleteKthLastFromList.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/DeleteNodeFromList.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/DescendantAndAncestorInBst.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/DirectoryPathNormalization.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/DoListsOverlap.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/DoTerminatedListsOverlap.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/DrawingSkyline.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/DutchNationalFlag.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/ElementAppearingOnce.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/EnumerateBalancedParentheses.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/EnumeratePalindromicDecompositions.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/EnumerateTrees.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/EuclideanGcd.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/EvaluateRpn.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/EvenOddArray.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/EvenOddListMerge.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/Fibonacci.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/FindSalaryThreshold.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/FirstMissingPositiveEntry.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/Gcd.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/GraphClone.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/GrayCode.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/GroupEqualEntries.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/HIndex.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/Hanoi.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/HuffmanCoding.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/InsertInList.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/InsertOperatorsInString.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/IntAsArrayIncrement.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/IntAsArrayMultiply.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/IntAsListAdd.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/IntSquareRoot.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/IntersectSortedArrays.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/IntervalAdd.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/IntervalsUnion.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/IsAnonymousLetterConstructible.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/IsArrayDominated.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/IsCircuitWirable.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/IsListCyclic.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/IsListPalindromic.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/IsNumberPalindromic.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/IsStringDecomposableIntoWords.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/IsStringInMatrix.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/IsStringPalindromic.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/IsStringPalindromicPunctuation.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/IsStringPermutableToPalindrome.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/IsTreeABst.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/IsTreeBalanced.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/IsTreeSymmetric.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/IsValidParenthesization.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/IsValidSudoku.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/KClosestStars.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/KLargestInHeap.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/KLargestValuesInBst.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/Knapsack.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/KthLargestElementInLongArray.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/KthLargestElementInTwoSortedArrays.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/KthLargestInArray.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/KthNodeInTree.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/LargestRectangleUnderSkyline.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/LeftRightJustifyText.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/LevenshteinDistance.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/LineThroughMostPoints.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/ListCyclicRightShift.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/LongestContainedInterval.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/LongestIncreasingSubarray.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/LongestNondecreasingSubsequence.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/LongestSubarrayWithDistinctValues.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/LongestSubarrayWithSumConstraint.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/LongestSubstringWithMatchingParentheses.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/LookAndSay.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/LowestCommonAncestor.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/LowestCommonAncestorCloseAncestor.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/LowestCommonAncestorInBst.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/LowestCommonAncestorWithParent.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/LruCache.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/MajorityElement.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/MakingChange.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/MatrixConnectedRegions.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/MatrixEnclosedRegions.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/MatrixRotation.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/MaxOfSlidingWindow.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/MaxProductAllButOne.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/MaxSafeHeight.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/MaxSquareSubmatrix.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/MaxSubmatrix.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/MaxSumSubarray.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/MaxTeamsInPhotograph.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/MaxTrappedWater.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/MaxWaterTrappable.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/MaximumSubarrayInCircularArray.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/MinimumDistance3SortedArrays.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/MinimumPointsCoveringIntervals.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/MinimumWaitingTime.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/MinimumWeightPathInATriangle.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/NQueens.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/NearestRepeatedEntries.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/NextPermutation.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/NonuniformRandomNumber.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/NumberOfScoreCombinations.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/NumberOfTraversalsMatrix.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/NumberOfTraversalsStaircase.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/OfflineSampling.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/OnlineMedian.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/OnlineSampling.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/Parity.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/PascalTriangle.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/PathSum.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/Permutations.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/PhoneNumberMnemonic.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/PickingUpCoins.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/PivotList.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/PowerSet.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/PowerXY.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/PrettyPrinting.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/PrimeSieve.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/PrimitiveDivide.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/PrimitiveMultiply.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/QueueFromStacks.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/QueueWithMax.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/RandomPermutation.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/RandomSubset.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/RangeLookupInBst.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/RealSquareRoot.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/RectangleIntersection.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/RefuelingSchedule.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/RegularExpression.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/RemoveDuplicates.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/RemoveDuplicatesFromSortedList.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/ReplaceAndRemove.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/ReverseBits.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/ReverseDigits.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/ReverseSublist.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/ReverseWords.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/RoadNetwork.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/RomanToInteger.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/RookAttack.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/RotateArray.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/RunLengthCompression.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/SearchEntryEqualToIndex.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/SearchFirstGreaterValueInBst.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/SearchFirstKey.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/SearchForMinMaxInArray.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/SearchForMissingElement.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/SearchFrequentItems.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/SearchInBst.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/SearchInList.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/SearchMaze.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/SearchRowColSortedMatrix.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/SearchShiftedSortedArray.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/SearchUnknownLengthArray.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/SmallestNonconstructibleValue.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/SmallestSubarrayCoveringAllValues.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/SmallestSubarrayCoveringSet.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/SnakeString.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/SortAlmostSortedArray.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/SortIncreasingDecreasingArray.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/SortList.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/SortedArrayRemoveDups.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/SortedArraysMerge.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/SortedListToBst.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/SortedListsMerge.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/SpiralOrdering.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/SpreadsheetEncoding.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/StackWithMax.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/StringDecompositionsIntoDictionaryWords.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/StringIntegerInterconversion.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/StringTransformability.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/SubstringMatch.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/SuccessorInTree.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/SudokuSolve.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/SumRootToLeaf.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/SunsetView.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/SwapBits.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/TaskPairing.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/ThreeSum.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/TreeConnectLeaves.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/TreeExterior.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/TreeFromPreorderInorder.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/TreeFromPreorderWithNull.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/TreeInorder.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/TreeLevelOrder.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/TreePostorder.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/TreePreorder.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/TreeRightSibling.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/TreeWithParentInorder.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/TwoSortedArraysMerge.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/TwoSum.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/UniformRandomNumber.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/ValidIpAddresses.class \
    $(BUILD_DIR)/$(MAIN_PACKAGE)/ZipList.class

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)
