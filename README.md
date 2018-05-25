# EPI Judge

## Introduction

EPI Judge consists of the following:

- **Stub programs** for each problem in our book in Python, Java, and C++
- **Test-cases** that cover common corner-case and performance bugs
- A **framework** for running these tests on your implementation on your machine

## Installation

Here's how to download the judge:

    $ git clone https://github.com/adnanaziz/EPIJudge.git
If you do not have `git`, here's a good [tutorial](https://www.atlassian.com/git/tutorials/install-git) on installing git itself.

## Running the judge using IDEs

Check out these one minute videos to see how easy it is to get started with the judge.

### Python

[PyCharm](https://youtu.be/ImD_iI-uGYo), [Eclipse](https://youtu.be/rZ1qqwEXwQY), [NetBeans](https://youtu.be/Z41jW1TyZwY)

### Java

[IntelliJ IDEA](https://youtu.be/1BzHUpluQHM), [Eclipse](https://youtu.be/i9uz9Zazo0A)

### C++

[CLion](https://youtu.be/aHPDApyyYEg), [Visual Studio 2017](https://youtu.be/hgd8IIQpBEE)


## Running the judge from the command line

### Python

    $ python3 <program_name>.py

#### Java

Use the [`Makefile`](https://github.com/adnanaziz/EPIJudge/blob/master/epi_judge_java/Makefile). 

Compile and run a specific program:

    $ make <program_name> 
Example:

    $ make Anagrams
Compile and run the last program that you edited:

	$ make

### C++

You can manually compile and run all programs by directly invoking GCC and Clang. 

    $ g++ -pthread -std=c++14 -O3 -o anagrams anagrams.cc
You can also use the provided Makefile: `make <program_name>`. You can also use CMake with the provided CMakeLists.txt file. 

	$ make 
The default Makefile target is the last edited file.

    $ make anagrams


## FAQ

- How can I contact the authors? 

Please feel free to send us questions and feedback -  `adnan.aziz@gmail.com` and `tsung.hsien.lee@gmail.com`

- Help, my EPIJudge is not working, what should I do?

If you do have issues, e.g., with install or with buggy tests, feel free to reach out to us via email. Please be as detailed as you can: the ideal is if you can upload a screencast video of the issue to youtube; failing that, please upload screenshots.  The more detailed the description of the problem and your environment (OS, language version, IDE and version), the easier it’ll be for us to help you.

- I'm new to programming, and don't have any kind of development environment, what should I do?

The IntelliJ Integrated Development environments described above are best-in-class, and have free versions that will work fine for the EPI Judge. They do not include the compilers. You can get the Java development environment from [Oracle](http://www.oracle.com/technetwork/java/javase/downloads/jdk8-downloads-2133151.html), and the Python development environment from [Python.org](https://www.python.org/downloads/). For C++, you have multiple options. The simplest is to install [VisualStudio](https://code.visualstudio.com/download), which includes both the IDE and the compiler. Google is a good resource for installation help.

- What compilers are supported for judge?
  - C++
    - Linux
      - **GCC** 5.4.1
      - **Clang** 4.0
    - OS X  
      - **Apple LLVM Clang** 9.0.0
    - Windows
      - **Visual Studio** 2017 15.7.0 Preview 6
        - Release version of VS2017 contains a bug that makes it impossible to compile judge programs
      - **MinGW** GCC 5.4.0
      - **LXSS** (Windows Subsystem for Linux) GCC 5.4.0
  - Java     
    - **Java** 9
  - Python
    - **Python** 3.6
   

- What compilers are supported for solutions?
  - C++
      - Linux
        - **GCC** 7.0.0
        - **Clang** 5.0
      - OS X  
        - **Apple LLVM Clang** 9.0.0
      - Windows
        - **Visual Studio** 2017 15.7.0 Preview 6
            - Release version of VS2017 contains a bug that makes it impossible to compile judge programs
        - **MinGW** GCC 7.2.0
        - **LXSS** (Windows Subsystem for Linux) GCC 7.2.0
    - Java     
      - **Java** 9
    - Python
      - **Python** 3.6 

Let us know if you managed to compile with an older version.

- What does the UI look like?

Take a look at this screenshot.

<img src="http://elementsofprogramminginterviews.com/img/judge-ide-example.png" width="600px"></img>

- How can I understand the test framework better?

The judge harness is fairly complex (but does not use nonstandard language features or libraries). You are welcome to study it, but we’d advise you against making changes to it (since it will lead to nasty merge conflicts when you update).

- How do I import the C++ project?

If you want to import the project into your favourite IDE, you probably need to create IDE project with [CMake](https://cmake.org/) (no need to do it for CLion, it supports CMake out-of-the-box).

Here is an example recipe for generationg Visual Studio project ([list](https://cmake.org/cmake/help/v3.10/manual/cmake-generators.7.html) of all CMake supported IDEs).
After installing CMake, open your terminal, go to `epi_judge_cpp` folder and run following commands:

    mkdir vs
    cd vs
    cmake -G "Visual Studio 15 2017" ..

Then just open `epi_judge_cpp/vs/epi_judge_cpp.sln` solution with Visual Studio and it will load all EPI programs.

## Problem to Program Mapping

(You may have to scroll to the right to view the Python column.)

| Problem | C++ | Java | Python  |
| ------ | ------ | ------ | ------ |
| Bootcamp: Primitive Types | count\_bits.cc | CountBits.java | count\_bits.py | 
| Computing the parity of a word | parity.cc | Parity.java | parity.py | 
| Swap bits | swap\_bits.cc | SwapBits.java | swap\_bits.py | 
| Reverse bits | reverse\_bits.cc | ReverseBits.java | reverse\_bits.py | 
| Find a closest integer with the same weight | closest\_int\_same\_weight.cc | ClosestIntSameWeight.java | closest\_int\_same\_weight.py | 
| Compute x * y without arithmetical operators | primitive\_multiply.cc | PrimitiveMultiply.java | primitive\_multiply.py | 
| Compute x/y | primitive\_divide.cc | PrimitiveDivide.java | primitive\_divide.py | 
| Compute x^y | power\_x\_y.cc | PowerXY.java | power\_x\_y.py | 
| Reverse digits | reverse\_digits.cc | ReverseDigits.java | reverse\_digits.py | 
| Check if a decimal integer is a palindrome | is\_number\_palindromic.cc | IsNumberPalindromic.java | is\_number\_palindromic.py | 
| Generate uniform random numbers | uniform\_random\_number.cc | UniformRandomNumber.java | uniform\_random\_number.py | 
| Rectangle intersection | rectangle\_intersection.cc | RectangleIntersection.java | rectangle\_intersection.py | 
| Bootcamp: Arrays | even\_odd\_array.cc | EvenOddArray.java | even\_odd\_array.py | 
| The Dutch national flag problem | dutch\_national\_flag.cc | DutchNationalFlag.java | dutch\_national\_flag.py | 
| Increment an arbitrary-precision integer | int\_as\_array\_increment.cc | IntAsArrayIncrement.java | int\_as\_array\_increment.py | 
| Multiply two arbitrary-precision integers | int\_as\_array\_multiply.cc | IntAsArrayMultiply.java | int\_as\_array\_multiply.py | 
| Advancing through an array | advance\_by\_offsets.cc | AdvanceByOffsets.java | advance\_by\_offsets.py | 
| Delete duplicates from a sorted array | sorted\_array\_remove\_dups.cc | SortedArrayRemoveDups.java | sorted\_array\_remove\_dups.py | 
| Buy and sell a stock once | buy\_and\_sell\_stock.cc | BuyAndSellStock.java | buy\_and\_sell\_stock.py | 
| Buy and sell a stock twice | buy\_and\_sell\_stock\_twice.cc | BuyAndSellStockTwice.java | buy\_and\_sell\_stock\_twice.py | 
| Computing an alternation | alternating\_array.cc | AlternatingArray.java | alternating\_array.py | 
| Enumerate all primes to n | prime\_sieve.cc | PrimeSieve.java | prime\_sieve.py | 
| Permute the elements of an array | apply\_permutation.cc | ApplyPermutation.java | apply\_permutation.py | 
| Compute the next permutation | next\_permutation.cc | NextPermutation.java | next\_permutation.py | 
| Sample offline data | offline\_sampling.cc | OfflineSampling.java | offline\_sampling.py | 
| Sample online data | online\_sampling.cc | OnlineSampling.java | online\_sampling.py | 
| Compute a random permutation | random\_permutation.cc | RandomPermutation.java | random\_permutation.py | 
| Compute a random subset | random\_subset.cc | RandomSubset.java | random\_subset.py | 
| Generate nonuniform random numbers | nonuniform\_random\_number.cc | NonuniformRandomNumber.java | nonuniform\_random\_number.py | 
| The Sudoku checker problem | is\_valid\_sudoku.cc | IsValidSudoku.java | is\_valid\_sudoku.py | 
| Compute the spiral ordering of a 2D array | spiral\_ordering\_segments.cc | SpiralOrderingSegments.java | spiral\_ordering\_segments.py | 
| Rotate a 2D array | matrix\_rotation.cc | MatrixRotation.java | matrix\_rotation.py | 
| Compute rows in Pascal's Triangle | pascal\_triangle.cc | PascalTriangle.java | pascal\_triangle.py | 
| Interconvert strings and integers | string\_integer\_interconversion.cc | StringIntegerInterconversion.java | string\_integer\_interconversion.py | 
| Base conversion | convert\_base.cc | ConvertBase.java | convert\_base.py | 
| Compute the spreadsheet column encoding | spreadsheet\_encoding.cc | SpreadsheetEncoding.java | spreadsheet\_encoding.py | 
| Replace and remove | replace\_and\_remove.cc | ReplaceAndRemove.java | replace\_and\_remove.py | 
| Test palindromicity | is\_string\_palindromic\_punctuation.cc | IsStringPalindromicPunctuation.java | is\_string\_palindromic\_punctuation.py | 
| Reverse all the words in a sentence | reverse\_words.cc | ReverseWords.java | reverse\_words.py | 
| Compute all mnemonics for a phone number | phone\_number\_mnemonic.cc | PhoneNumberMnemonic.java | phone\_number\_mnemonic.py | 
| The look-and-say problem | look\_and\_say.cc | LookAndSay.java | look\_and\_say.py | 
| Convert from Roman to decimal | roman\_to\_integer.cc | RomanToInteger.java | roman\_to\_integer.py | 
| Compute all valid IP addresses | valid\_ip\_addresses.cc | ValidIpAddresses.java | valid\_ip\_addresses.py | 
| Write a string sinusoidally | snake\_string.cc | SnakeString.java | snake\_string.py | 
| Implement run-length encoding | run\_length\_compression.cc | RunLengthCompression.java | run\_length\_compression.py | 
| Find the first occurrence of a substring | substring\_match.cc | SubstringMatch.java | substring\_match.py | 
| Bootcamp: Linked Lists | search\_in\_list.cc | SearchInList.java | search\_in\_list.py | 
| Bootcamp: Linked Lists | insert\_in\_list.cc | InsertInList.java | insert\_in\_list.py | 
| Bootcamp: Linked Lists | delete\_from\_list.cc | DeleteFromList.java | delete\_from\_list.py | 
| Merge two sorted lists | sorted\_lists\_merge.cc | SortedListsMerge.java | sorted\_lists\_merge.py | 
| Reverse a single sublist | reverse\_sublist.cc | ReverseSublist.java | reverse\_sublist.py | 
| Test for cyclicity | is\_list\_cyclic.cc | IsListCyclic.java | is\_list\_cyclic.py | 
| Test for overlapping lists - lists are cycle-free | do\_terminated\_lists\_overlap.cc | DoTerminatedListsOverlap.java | do\_terminated\_lists\_overlap.py | 
| Test for overlapping lists - lists may have cycles | do\_lists\_overlap.cc | DoListsOverlap.java | do\_lists\_overlap.py | 
| Delete a node from a singly linked list | delete\_node\_from\_list.cc | DeleteNodeFromList.java | delete\_node\_from\_list.py | 
| Remove the kth last element from a list | delete\_kth\_last\_from\_list.cc | DeleteKthLastFromList.java | delete\_kth\_last\_from\_list.py | 
| Remove duplicates from a sorted list | remove\_duplicates\_from\_sorted\_list.cc | RemoveDuplicatesFromSortedList.java | remove\_duplicates\_from\_sorted\_list.py | 
| Implement cyclic right shift for singly linked lists | list\_cyclic\_right\_shift.cc | ListCyclicRightShift.java | list\_cyclic\_right\_shift.py | 
| Implement even-odd merge | even\_odd\_list\_merge.cc | EvenOddListMerge.java | even\_odd\_list\_merge.py | 
| Test whether a singly linked list is palindromic | is\_list\_palindromic.cc | IsListPalindromic.java | is\_list\_palindromic.py | 
| Implement list pivoting | pivot\_list.cc | PivotList.java | pivot\_list.py | 
| Add list-based integers | int\_as\_list\_add.cc | IntAsListAdd.java | int\_as\_list\_add.py | 
| Implement a stack with max API | stack\_with\_max.cc | StackWithMax.java | stack\_with\_max.py | 
| Evaluate RPN expressions | evaluate\_rpn.cc | EvaluateRpn.java | evaluate\_rpn.py | 
| Test a string over ''{,},(,),[,]'' for well-formedness | is\_valid\_parenthesization.cc | IsValidParenthesization.java | is\_valid\_parenthesization.py | 
| Normalize pathnames | directory\_path\_normalization.cc | DirectoryPathNormalization.java | directory\_path\_normalization.py | 
| Compute buildings with a sunset view | sunset\_view.cc | SunsetView.java | sunset\_view.py | 
| Compute binary tree nodes in order of increasing depth | tree\_level\_order.cc | TreeLevelOrder.java | tree\_level\_order.py | 
| Implement a circular queue | circular\_queue.cc | CircularQueue.java | circular\_queue.py | 
| Implement a queue using stacks | queue\_from\_stacks.cc | QueueFromStacks.java | queue\_from\_stacks.py | 
| Implement a queue with max API | queue\_with\_max.cc | QueueWithMax.java | queue\_with\_max.py | 
| Test if a binary tree is height-balanced | is\_tree\_balanced.cc | IsTreeBalanced.java | is\_tree\_balanced.py | 
| Test if a binary tree is symmetric | is\_tree\_symmetric.cc | IsTreeSymmetric.java | is\_tree\_symmetric.py | 
| Compute the lowest common ancestor in a binary tree | lowest\_common\_ancestor.cc | LowestCommonAncestor.java | lowest\_common\_ancestor.py | 
| Compute the LCA when nodes have parent pointers | lowest\_common\_ancestor\_with\_parent.cc | LowestCommonAncestorWithParent.java | lowest\_common\_ancestor\_with\_parent.py | 
| Sum the root-to-leaf paths in a binary tree | sum\_root\_to\_leaf.cc | SumRootToLeaf.java | sum\_root\_to\_leaf.py | 
| Find a root to leaf path with specified sum | path\_sum.cc | PathSum.java | path\_sum.py | 
| Implement an inorder traversal without recursion | tree\_inorder.cc | TreeInorder.java | tree\_inorder.py | 
| Implement a preorder traversal without recursion | tree\_preorder.cc | TreePreorder.java | tree\_preorder.py | 
| Compute the kth node in an inorder traversal | kth\_node\_in\_tree.cc | KthNodeInTree.java | kth\_node\_in\_tree.py | 
| Compute the successor | successor\_in\_tree.cc | SuccessorInTree.java | successor\_in\_tree.py | 
| Implement an inorder traversal with O(1) space | tree\_with\_parent\_inorder.cc | TreeWithParentInorder.java | tree\_with\_parent\_inorder.py | 
| Reconstruct a binary tree from traversal data | tree\_from\_preorder\_inorder.cc | TreeFromPreorderInorder.java | tree\_from\_preorder\_inorder.py | 
| Reconstruct a binary tree from a preorder traversal with markers | tree\_from\_preorder\_with\_null.cc | TreeFromPreorderWithNull.java | tree\_from\_preorder\_with\_null.py | 
| Form a linked list from the leaves of a binary tree | tree\_connect\_leaves.cc | TreeConnectLeaves.java | tree\_connect\_leaves.py | 
| Compute the exterior of a binary tree | tree\_exterior.cc | TreeExterior.java | tree\_exterior.py | 
| Compute the right sibling tree | tree\_right\_sibling.cc | TreeRightSibling.java | tree\_right\_sibling.py | 
| Merge sorted files | sorted\_arrays\_merge.cc | SortedArraysMerge.java | sorted\_arrays\_merge.py | 
| Sort an increasing-decreasing array | sort\_increasing\_decreasing\_array.cc | SortIncreasingDecreasingArray.java | sort\_increasing\_decreasing\_array.py | 
| Sort an almost-sorted array | sort\_almost\_sorted\_array.cc | SortAlmostSortedArray.java | sort\_almost\_sorted\_array.py | 
| Compute the k closest stars | k\_closest\_stars.cc | KClosestStars.java | k\_closest\_stars.py | 
| Compute the median of online data | online\_median.cc | OnlineMedian.java | online\_median.py | 
| Compute the k largest elements in a max-heap | k\_largest\_in\_heap.cc | KLargestInHeap.java | k\_largest\_in\_heap.py | 
| Search a sorted array for first occurrence of k | search\_first\_key.cc | SearchFirstKey.java | search\_first\_key.py | 
| Search a sorted array for entry equal to its index | search\_entry\_equal\_to\_index.cc | SearchEntryEqualToIndex.java | search\_entry\_equal\_to\_index.py | 
| Search a cyclically sorted array | search\_shifted\_sorted\_array.cc | SearchShiftedSortedArray.java | search\_shifted\_sorted\_array.py | 
| Compute the integer square root | int\_square\_root.cc | IntSquareRoot.java | int\_square\_root.py | 
| Compute the real square root | real\_square\_root.cc | RealSquareRoot.java | real\_square\_root.py | 
| Search in a 2D sorted array | search\_row\_col\_sorted\_matrix.cc | SearchRowColSortedMatrix.java | search\_row\_col\_sorted\_matrix.py | 
| Find the min and max simultaneously | search\_for\_min\_max\_in\_array.cc | SearchForMinMaxInArray.java | search\_for\_min\_max\_in\_array.py | 
| Find the kth largest element | kth\_largest\_in\_array.cc | KthLargestInArray.java | kth\_largest\_in\_array.py | 
| Find the missing IP address | absent\_value\_array.cc | AbsentValueArray.java | absent\_value\_array.py | 
| Find the duplicate and missing elements | search\_for\_missing\_element.cc | SearchForMissingElement.java | search\_for\_missing\_element.py | 
| Bootcamp: Hash Tables | anagrams.cc | Anagrams.java | anagrams.py | 
| Test for palindromic permutations | is\_string\_permutable\_to\_palindrome.cc | IsStringPermutableToPalindrome.java | is\_string\_permutable\_to\_palindrome.py | 
| Is an anonymous letter constructible? | is\_anonymous\_letter\_constructible.cc | IsAnonymousLetterConstructible.java | is\_anonymous\_letter\_constructible.py | 
| Implement an ISBN cache | lru\_cache.cc | LruCache.java | lru\_cache.py | 
| Compute the LCA, optimizing for close ancestors | lowest\_common\_ancestor\_close\_ancestor.cc | LowestCommonAncestorCloseAncestor.java | lowest\_common\_ancestor\_close\_ancestor.py | 
| Find the nearest repeated entries in an array | nearest\_repeated\_entries.cc | NearestRepeatedEntries.java | nearest\_repeated\_entries.py | 
| Find the smallest subarray covering all values | smallest\_subarray\_covering\_set.cc | SmallestSubarrayCoveringSet.java | smallest\_subarray\_covering\_set.py | 
| Find smallest subarray sequentially covering all values | smallest\_subarray\_covering\_all\_values.cc | SmallestSubarrayCoveringAllValues.java | smallest\_subarray\_covering\_all\_values.py | 
| Find the longest subarray with distinct entries | longest\_subarray\_with\_distinct\_values.cc | LongestSubarrayWithDistinctValues.java | longest\_subarray\_with\_distinct\_values.py | 
| Find the length of a longest contained interval | longest\_contained\_interval.cc | LongestContainedInterval.java | longest\_contained\_interval.py | 
| Compute all string decompositions | string\_decompositions\_into\_dictionary\_words.cc | StringDecompositionsIntoDictionaryWords.java | string\_decompositions\_into\_dictionary\_words.py | 
| Test the Collatz conjecture | collatz\_checker.cc | CollatzChecker.java | collatz\_checker.py | 
| Compute the intersection of two sorted arrays | intersect\_sorted\_arrays.cc | IntersectSortedArrays.java | intersect\_sorted\_arrays.py | 
| Merge two sorted arrays | two\_sorted\_arrays\_merge.cc | TwoSortedArraysMerge.java | two\_sorted\_arrays\_merge.py | 
| Computing the h-index | h\_index.cc | HIndex.java | h\_index.py | 
| Remove first-name duplicates | remove\_duplicates.cc | RemoveDuplicates.java | remove\_duplicates.py | 
| Smallest nonconstructible value | smallest\_nonconstructible\_value.cc | SmallestNonconstructibleValue.java | smallest\_nonconstructible\_value.py | 
| Render a calendar | calendar\_rendering.cc | CalendarRendering.java | calendar\_rendering.py | 
| Merging intervals | interval\_add.cc | IntervalAdd.java | interval\_add.py | 
| Compute the union of intervals | intervals\_union.cc | IntervalsUnion.java | intervals\_union.py | 
| Partitioning and sorting an array with many repeated entries | group\_equal\_entries.cc | GroupEqualEntries.java | group\_equal\_entries.py | 
| Team photo day - 1 | is\_array\_dominated.cc | IsArrayDominated.java | is\_array\_dominated.py | 
| Implement a fast sorting algorithm for lists | sort\_list.cc | SortList.java | sort\_list.py | 
| Compute a salary threshold | find\_salary\_threshold.cc | FindSalaryThreshold.java | find\_salary\_threshold.py | 
| Test if a binary tree satisfies the BST property | is\_tree\_a\_bst.cc | IsTreeABst.java | is\_tree\_a\_bst.py | 
| Find the first key greater than a given value in a BST | search\_first\_greater\_value\_in\_bst.cc | SearchFirstGreaterValueInBst.java | search\_first\_greater\_value\_in\_bst.py | 
| Find the k largest elements in a BST | k\_largest\_values\_in\_bst.cc | KLargestValuesInBst.java | k\_largest\_values\_in\_bst.py | 
| Compute the LCA in a BST | lowest\_common\_ancestor\_in\_bst.cc | LowestCommonAncestorInBst.java | lowest\_common\_ancestor\_in\_bst.py | 
| Reconstruct a BST from traversal data | bst\_from\_preorder.cc | BstFromPreorder.java | bst\_from\_preorder.py | 
| Find the closest entries in three sorted arrays | minimum\_distance\_3\_sorted\_arrays.cc | MinimumDistance3SortedArrays.java | minimum\_distance\_3\_sorted\_arrays.py | 
| Enumerate numbers of the form a + b sqrt(2) | a\_b\_sqrt2.cc | ABSqrt2.java | a\_b\_sqrt2.py | 
| Build a minimum height BST from a sorted array | bst\_from\_sorted\_array.cc | BstFromSortedArray.java | bst\_from\_sorted\_array.py | 
| Test if three BST nodes are totally ordered | descendant\_and\_ancestor\_in\_bst.cc | DescendantAndAncestorInBst.java | descendant\_and\_ancestor\_in\_bst.py | 
| The range lookup problem | range\_lookup\_in\_bst.cc | RangeLookupInBst.java | range\_lookup\_in\_bst.py | 
| Add credits | adding\_credits.cc | AddingCredits.java | adding\_credits.py | 
| The Towers of Hanoi problem | hanoi.cc | Hanoi.java | hanoi.py | 
| Generate all nonattacking placements of n-Queens | n\_queens.cc | NQueens.java | n\_queens.py | 
| Generate permutations | permutations.cc | Permutations.java | permutations.py | 
| Generate the power set | power\_set.cc | PowerSet.java | power\_set.py | 
| Generate all subsets of size k | combinations.cc | Combinations.java | combinations.py | 
| Generate strings of matched parens | enumerate\_balanced\_parentheses.cc | EnumerateBalancedParentheses.java | enumerate\_balanced\_parentheses.py | 
| Generate palindromic decompositions | enumerate\_palindromic\_decompositions.cc | EnumeratePalindromicDecompositions.java | enumerate\_palindromic\_decompositions.py | 
| Generate binary trees | enumerate\_trees.cc | EnumerateTrees.java | enumerate\_trees.py | 
| Implement a Sudoku solver | sudoku\_solve.cc | SudokuSolve.java | sudoku\_solve.py | 
| Compute a Gray code | gray\_code.cc | GrayCode.java | gray\_code.py | 
| Bootcamp: Dynamic Programming | fibonacci.cc | Fibonacci.java | fibonacci.py | 
| Bootcamp: Dynamic Programming | max\_sum\_subarray.cc | MaxSumSubarray.java | max\_sum\_subarray.py | 
| Count the number of score combinations | number\_of\_score\_combinations.cc | NumberOfScoreCombinations.java | number\_of\_score\_combinations.py | 
| Compute the Levenshtein distance | levenshtein\_distance.cc | LevenshteinDistance.java | levenshtein\_distance.py | 
| Count the number of ways to traverse a 2D array | number\_of\_traversals\_matrix.cc | NumberOfTraversalsMatrix.java | number\_of\_traversals\_matrix.py | 
| Compute the binomial coefficients | binomial\_coefficients.cc | BinomialCoefficients.java | binomial\_coefficients.py | 
| Search for a sequence in a 2D array | is\_string\_in\_matrix.cc | IsStringInMatrix.java | is\_string\_in\_matrix.py | 
| The knapsack problem | knapsack.cc | Knapsack.java | knapsack.py | 
| The bedbathandbeyond.com problem | is\_string\_decomposable\_into\_words.cc | IsStringDecomposableIntoWords.java | is\_string\_decomposable\_into\_words.py | 
| Find the minimum weight path in a triangle | minimum\_weight\_path\_in\_a\_triangle.cc | MinimumWeightPathInATriangle.java | minimum\_weight\_path\_in\_a\_triangle.py | 
| Pick up coins for maximum gain | picking\_up\_coins.cc | PickingUpCoins.java | picking\_up\_coins.py | 
| Count the number of moves to climb stairs | number\_of\_traversals\_staircase.cc | NumberOfTraversalsStaircase.java | number\_of\_traversals\_staircase.py | 
| The pretty printing problem | pretty\_printing.cc | PrettyPrinting.java | pretty\_printing.py | 
| Find the longest nondecreasing subsequence | longest\_nondecreasing\_subsequence.cc | LongestNondecreasingSubsequence.java | longest\_nondecreasing\_subsequence.py | 
| Compute an optimum assignment of tasks | task\_pairing.cc | TaskPairing.java | task\_pairing.py | 
| Schedule to minimize waiting time | minimum\_waiting\_time.cc | MinimumWaitingTime.java | minimum\_waiting\_time.py | 
| The interval covering problem | minimum\_points\_covering\_intervals.cc | MinimumPointsCoveringIntervals.java | minimum\_points\_covering\_intervals.py | 
| The interval covering problem | two\_sum.cc | TwoSum.java | two\_sum.py | 
| The 3-sum problem | three\_sum.cc | ThreeSum.java | three\_sum.py | 
| Find the majority element | majority\_element.cc | MajorityElement.java | majority\_element.py | 
| The gasup problem | refueling\_schedule.cc | RefuelingSchedule.java | refueling\_schedule.py | 
| Compute the maximum water trapped by a pair of vertical lines | max\_trapped\_water.cc | MaxTrappedWater.java | max\_trapped\_water.py | 
| Compute the largest rectangle under the skyline | largest\_rectangle\_under\_skyline.cc | LargestRectangleUnderSkyline.java | largest\_rectangle\_under\_skyline.py | 
| Search a maze | search\_maze.cc | SearchMaze.java | search\_maze.py | 
| Paint a Boolean matrix | matrix\_connected\_regions.cc | MatrixConnectedRegions.java | matrix\_connected\_regions.py | 
| Compute enclosed regions | matrix\_enclosed\_regions.cc | MatrixEnclosedRegions.java | matrix\_enclosed\_regions.py | 
| Deadlock detection | deadlock\_detection.cc | DeadlockDetection.java | deadlock\_detection.py | 
| Clone a graph | graph\_clone.cc | GraphClone.java | graph\_clone.py | 
| Making wired connections | is\_circuit\_wirable.cc | IsCircuitWirable.java | is\_circuit\_wirable.py | 
| Transform one string to another | string\_transformability.cc | StringTransformability.java | string\_transformability.py | 
| Team photo day - 2 | max\_teams\_in\_photograph.cc | MaxTeamsInPhotograph.java | max\_teams\_in\_photograph.py | 
| Compute the greatest common divisor | gcd.cc | Gcd.java | gcd.py | 
| Find the first missing positive entry | first\_missing\_positive\_entry.cc | FirstMissingPositiveEntry.java | first\_missing\_positive\_entry.py | 
| Buy and sell a stock k times | buy\_and\_sell\_stock\_k\_times.cc | BuyAndSellStockKTimes.java | buy\_and\_sell\_stock\_k\_times.py | 
| Compute the maximum product of all entries but one | max\_product\_all\_but\_one.cc | MaxProductAllButOne.java | max\_product\_all\_but\_one.py | 
| Compute the longest contiguous increasing subarray | longest\_increasing\_subarray.cc | LongestIncreasingSubarray.java | longest\_increasing\_subarray.py | 
| Rotate an array | rotate\_array.cc | RotateArray.java | rotate\_array.py | 
| Identify positions attacked by rooks | rook\_attack.cc | RookAttack.java | rook\_attack.py | 
| Justify text | left\_right\_justify\_text.cc | LeftRightJustifyText.java | left\_right\_justify\_text.py | 
| Implement list zipping | zip\_list.cc | ZipList.java | zip\_list.py | 
| Copy a postings list | copy\_posting\_list.cc | CopyPostingList.java | copy\_posting\_list.py | 
| Compute the longest substring with matching parens | longest\_substring\_with\_matching\_parentheses.cc | LongestSubstringWithMatchingParentheses.java | longest\_substring\_with\_matching\_parentheses.py | 
| Compute the maximum of a sliding window | max\_of\_sliding\_window.cc | MaxOfSlidingWindow.java | max\_of\_sliding\_window.py | 
| Implement a postorder traversal without recursion | tree\_postorder.cc | TreePostorder.java | tree\_postorder.py | 
| Compute fair bonuses | bonus.cc | Bonus.java | bonus.py | 
| Search a sorted array of unknown length | search\_unknown\_length\_array.cc | SearchUnknownLengthArray.java | search\_unknown\_length\_array.py | 
| Search in two sorted arrays | kth\_largest\_element\_in\_two\_sorted\_arrays.cc | KthLargestElementInTwoSortedArrays.java | kth\_largest\_element\_in\_two\_sorted\_arrays.py | 
| Find the kth largest element - large n, small k | kth\_largest\_element\_in\_long\_array.cc | KthLargestElementInLongArray.java | kth\_largest\_element\_in\_long\_array.py | 
| Find an element that appears only once | element\_appearing\_once.cc | ElementAppearingOnce.java | element\_appearing\_once.py | 
| Find the line through the most points | line\_through\_most\_points.cc | LineThroughMostPoints.java | line\_through\_most\_points.py | 
| Convert a sorted doubly linked list into a BST | sorted\_list\_to\_bst.cc | SortedListToBst.java | sorted\_list\_to\_bst.py | 
| Convert a BST to a sorted doubly linked list | bst\_to\_sorted\_list.cc | BstToSortedList.java | bst\_to\_sorted\_list.py | 
| Merge two BSTs | bst\_merge.cc | BstMerge.java | bst\_merge.py | 
| Implement regular expression matching | regular\_expression.cc | RegularExpression.java | regular\_expression.py | 
| Synthesize an expression | insert\_operators\_in\_string.cc | InsertOperatorsInString.java | insert\_operators\_in\_string.py | 
| Count inversions | count\_inversions.cc | CountInversions.java | count\_inversions.py | 
| Draw the skyline | drawing\_skyline.cc | DrawingSkyline.java | drawing\_skyline.py | 
| Measure with defective jugs | defective\_jugs.cc | DefectiveJugs.java | defective\_jugs.py | 
| Compute the maximum subarray sum in a circular array | maximum\_subarray\_in\_circular\_array.cc | MaximumSubarrayInCircularArray.java | maximum\_subarray\_in\_circular\_array.py | 
| Determine the critical height | max\_safe\_height.cc | MaxSafeHeight.java | max\_safe\_height.py | 
| Find the maximum 2D subarray | max\_submatrix.cc | MaxSubmatrix.java | max\_submatrix.py | 
| Find the maximum 2D subarray | max\_square\_submatrix.cc | MaxSquareSubmatrix.java | max\_square\_submatrix.py | 
| Implement Huffman coding | huffman\_coding.cc | HuffmanCoding.java | huffman\_coding.py | 
| Trapping water | max\_water\_trappable.cc | MaxWaterTrappable.java | max\_water\_trappable.py | 
| The heavy hitter problem | search\_frequent\_items.cc | SearchFrequentItems.java | search\_frequent\_items.py | 
| Find the longest subarray whose sum <=  k | longest\_subarray\_with\_sum\_constraint.cc | LongestSubarrayWithSumConstraint.java | longest\_subarray\_with\_sum\_constraint.py | 
| Road network | road\_network.cc | RoadNetwork.java | road\_network.py | 
| Test if arbitrage is possible | arbitrage.cc | Arbitrage.java | arbitrage.py | 

## Acknowledgments

A big shout-out to the hundreds of users who tried out the release over the past couple of months. As always, we never fail to be impressed by the enthusiasm and commitment our readers have; it has served to bring out the best in us.
We all thank [Viacheslav Kroilov](https://github.com/metopa), for applying his exceptional software engineering skills to make EPI Judge a reality.
