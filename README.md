# EPI Judge

## Beta 5

## Introduction

EPI Judge is meant to serve as a companion to our book Elements of Programming Interviews. Specifically, this project consists of the following:

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
      - **GCC** 5.4.1 and newer
      - **Clang** 4.0 and newer
    - OS X  
      - **Apple LLVM Clang** 9.0.0 and newer
    - Windows
      - **Visual Studio** 2017 and newer
      - **MinGW** GCC 5.4.0 and newer
      - **LXSS** (Windows Subsystem for Linux) GCC 5.4.0 and newer
  - Java     
    - **Java** 9 and newer
  - Python
    - **Python** 3.7 and newer
   

- What compilers are supported for solutions?
  - C++
      - Linux
        - **GCC** 7.0.0 and newer
        - **Clang** 5.0 and newer
      - OS X  
        - **Apple LLVM Clang** 9.0.0 and newer
      - Windows
      - **Visual Studio** 2017 and newer
        - **MinGW** GCC 7.2.0 and newer
        - **LXSS** (Windows Subsystem for Linux) GCC 7.2.0 and newer
    - Java     
      - **Java** 9 and newer
    - Python
      - **Python** 3.6 and newer 

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

## Tracking your progress

The file [index.html](https://github.com/adnanaziz/EPIJudge/blob/master/index.html) in the root of this project tracks your progress through the problems. Specifically, there's an expanding tab for each chapter. Click on it, and you will see your progress, e.g., as below. This file gets updated each time you execute a program. You can **use this file to map book problems to stub programs**.

<img src="https://i.imgur.com/xjf7Z32.png" width="600px"></img>

## Acknowledgments

A big shout-out to the hundreds of users who tried out the release over the past couple of months. As always, we never fail to be impressed by the enthusiasm and commitment our readers have; it has served to bring out the best in us.
We all thank [Viacheslav Kroilov](https://github.com/metopa), for applying his exceptional software engineering skills to make EPI Judge a reality.
