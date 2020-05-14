---
name: Report an issue
about: Bugs, better programs, problems with install/running program, enhancements
title: ''
labels: ''
assignees: ''

---

Please mention if this is a **general issue or specific problem**

 - Example of general issue: [Solution to variant problems](https://github.com/adnanaziz/EPIJudge/issues/114)
 - Example of specific problem: [Python solution to node depth problem has off-by-1](https://github.com/adnanaziz/EPIJudge/issues/110)

If you are referring to a specific problem, please **reference it by problem name, not problem number or page number** (since both page and problem numbering have changed across editions)

- Please **classify issues**
(1.) Better solution, e.g.,  [Java countTrailingBits()](https://github.com/adnanaziz/EPIJudge/pull/55)
(2.) Trouble with installation/execution, e.g.,  [IntelliJ import](https://github.com/adnanaziz/EPIJudge/issues/52), and [Visual Studio 2017 compile bug](https://github.com/adnanaziz/EPIJudge/issues/63)
(3.) Buggy test or buggy code, e.g.,  [tests for permutation problem have nonpermutation inputs](https://github.com/adnanaziz/EPIJudge/issues/57)
(4.) Feature request, e.g.,  [Go language support](https://github.com/adnanaziz/EPIJudge/issues/109)

By better solution we mean something that is (1.) more **idiomatic**; (2.) **faster** (from a complexity perspective, or in practical settings); or  (3.) easier to **understand**.
 - If you have a complete solution that is better solution, please consider using a [pull request](https://github.com/adnanaziz/EPIJudge/pulls). (If possible, please provide the solution for C++, Java, and Python.)
 - If the problem is with installation or execution, please give system information, i.e., OS, and language and build environment (including versions).
 - Please describe the behavior you see, including screenshots (you can use Google Drive, GitHub, or [Imgur](https://imgur.com/) to upload images and link to them); as well as the expected behavior.
 - For bugs, if possible please provide a reproducible test case that is the bare minimum necessary to generate the problem.

Because of our build process we cannot **directly accept PRs** by merging into the master branch. Instead please send PRs against the dev branch.
  - The reason for this is that we have a single source of truth, which is the complete solution that we annotate with markers that are used to generate the solution that goes inline in the book as well as the skeleton for the judge. (Here is a [snippet](https://imgur.com/nN6nbVL) of a source program, note the markers.)
