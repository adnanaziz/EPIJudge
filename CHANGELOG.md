## [Unreleased]
  - Highlight mismatched items in arrays (when printing test failure explanation)
  - Run each test case with a timeout
 
 
## [Beta 5] - 2020-01-11

### Added
  - Namespace for C++ test framework
  - Python type hints
  - Added a page to track progress on exercises (list of exercises with number of passed tests in each language)
  - Added continuous testing  

### Changed
  - Changed test data format
    - Now every field is encoded in pure JSON format  

### Fixed
  - Numerous fixes sent by our users
  
 
## [Beta 4] - 2018-05-08

### Added
  - This changelog
  - New programs
    - Fibonacci
    - KthLargestElementInLongArray
    - MaxSumSubarray
    - QueueWithMaxUsingDeque
    - RangeLookupInBst
    - ReverseLinkedListIterative
    - TwoSortedArraysMerge
  - Separate compiler requirements for the solution projects  
  
### Changed
  - [IMPORTANT] Java project now requires at least Java 9 JDK
  - [IMPORTANT] [Windows only] C++ project now requires at least Visual Studio 17 Preview 6 
    - You are still free to use MinGW or LXSS compilers
  - [IMPORTANT] Python project now requires at least Python 3.6
  - Java JSON library is divided into separate files
  - Some solution code improvements
  
### Fixed
  - Issue with C++ anonymous namespaces
  - Several warnings issued by VS2017  
 
### Removed
  - All test cases with binary trees with height greater than 500 
    - They may cause stack overflow on some systems
 
 
## [Beta 3] - 2018-04-05

### Added
  - Exercise solutions


## [Beta 2] - 2018-03-27

### Added
  - Print argument names on test failure
  - Shared configuration file as an alternative for command-line parameters
  
  
### Changed
  - Make C++ framework C++14 conformant (previously C++17)
  - Better support for detailed test failure explanation
  - Change command-line interface
  - Move include and import statements to top
 
 
### Fixed
  - Missing res_printer in search_for_min_max_in_array.py  
  - Replace all long type usages with long long 
  
  
## [Beta 1] - 2018-02-01
### Added
  - Judge exercises in C++, Java, and Python
  - Test framework for implementation evaluation
  - Thousands of test cases
  - Makefile and CMake (C++ only) projects
  - Test run timing
  - Video tutorials
