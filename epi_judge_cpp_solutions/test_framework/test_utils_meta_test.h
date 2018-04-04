// @library
#pragma once

#include <ostream>
#include <set>
#include <vector>

#include "test_utils_meta.h"

static_assert(std::is_same<remove_ref_cv_t<int>, int>::value, "");
static_assert(std::is_same<remove_ref_cv_t<const int&>, int>::value, "");

static_assert(is_pure_type<int>::value == true, "");
static_assert(is_pure_type<int&>::value == false, "");
static_assert(is_pure_type<const int>::value == false, "");

static_assert(FirstFalseArg() == 0, "");
static_assert(FirstFalseArg(false) == 1, "");
static_assert(FirstFalseArg(true) == 0, "");
static_assert(FirstFalseArg(true, false) == 2, "");
static_assert(FirstFalseArg(true, true, true, false) == 4, "");
static_assert(FirstFalseArg(false, true, true, false) == 1, "");

namespace {
void WithExecutorHook(TimedExecutor&, int);
void WithoutExecutorHook(int, int);

static_assert(
    FunctionalTraits<decltype(&WithExecutorHook)>::HasExecutorHook() == true,
    "");
static_assert(
    FunctionalTraits<decltype(&WithoutExecutorHook)>::HasExecutorHook() ==
        false,
    "");
}  // namespace

static_assert(
    std::is_same<SubTuple<std::tuple<char, short, int, long>, 0, 4>::type,
                 std::tuple<char, short, int, long>>::value,
    "");

static_assert(
    std::is_same<SubTuple<std::tuple<char, short, int, long>, 0, 0>::type,
                 std::tuple<>>::value,
    "");

static_assert(
    std::is_same<SubTuple<std::tuple<char, short, int, long>, 4, 4>::type,
                 std::tuple<>>::value,
    "");

static_assert(
    std::is_same<SubTuple<std::tuple<char, short, int, long>, 0, 2>::type,
                 std::tuple<char, short>>::value,
    "");
static_assert(
    std::is_same<SubTuple<std::tuple<char, short, int, long>, 2, 4>::type,
                 std::tuple<int, long>>::value,
    "");

static_assert(std::is_same<escape_void_t<int>, int>::value, "");
static_assert(std::is_same<escape_void_t<void>, VoidPlaceholder>::value, "");

namespace {
class NoOperator {};
class NormalOperator {};
class WeirdOperator {};
class InvalidOperator {};

bool operator==(const NormalOperator&, const NormalOperator&);
WeirdOperator operator==(WeirdOperator, WeirdOperator);
bool operator==(const InvalidOperator&, const WeirdOperator&);

static_assert(HasEqualOp<NoOperator>::value == false, "");
static_assert(HasEqualOp<NormalOperator>::value == true, "");
static_assert(HasEqualOp<WeirdOperator>::value == true, "");
static_assert(HasEqualOp<InvalidOperator>::value == false, "");

std::ostream& operator<<(std::ostream&, const NormalOperator&);
void operator<<(std::ostream&, WeirdOperator);
std::ostream& operator<<(InvalidOperator&, InvalidOperator);

static_assert(HasOStreamOp<NoOperator>::value == false, "");
static_assert(HasOStreamOp<NormalOperator>::value == true, "");
static_assert(HasOStreamOp<WeirdOperator>::value == true, "");
static_assert(HasOStreamOp<InvalidOperator>::value == false, "");

struct UserCollection1 {
  int begin() const;
  int end() const;
};

struct UserCollection2 {};
int begin(UserCollection2);
int end(UserCollection2);

class InvalidUserCollection {
  int begin();
};

static_assert(HasBeginEnd<int>::value == false, "");
static_assert(HasBeginEnd<NoOperator>::value == false, "");
static_assert(HasBeginEnd<std::vector<int>>::value == true, "");
static_assert(HasBeginEnd<std::set<int>>::value == true, "");
static_assert(HasBeginEnd<InvalidUserCollection>::value == false, "");
static_assert(HasBeginEnd<UserCollection1>::value == true, "");
static_assert(HasBeginEnd<UserCollection2>::value == true, "");
}  // namespace
