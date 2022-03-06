#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "test_framework/generic_test.h"
#include "test_framework/serialization_traits.h"
using std::vector;

long long Gcd(long long x, long long y) {

    if (x == 0) return y;
    if (y == 0) return x;

    if (x == y) {
        return x;
    }
    else if (!(x & 1) && !(y & 1)) {
        return Gcd(x >> 1, y >> 1) << 1;
    }
    else if (!(x & 1) && (y & 1)) {
        return Gcd(x >> 1, y);
    }
    else if ((x & 1) && !(y & 1)) {
        return Gcd(x, y >> 1);
    }
    else if (x > y) {
        return Gcd(x - y, y);
    }
    return Gcd(x, y - x);

}
struct Point {
    /*bool operator == (const Point& pt) const {
        return (x == pt.x) && (y == pt.y);
    }*/
    int x, y;
};

struct HashPoint {
    size_t operator()(const Point& pt) const {
        return std::hash<int>()(pt.x) ^ std::hash<int>()(pt.y);
    }
};

struct Rational {

    bool operator== (const Rational& rt) const {
        return numerator == rt.numerator && denomenator == rt.denomenator;
    }

    int numerator, denomenator;
};

Rational GetCanonicalForm(int a, int b) {
    int gcd = Gcd(std::abs(a), std::abs(b));

    a /= gcd;
    b /= gcd;

    return b < 0 ? Rational{ -a, -b } : Rational{a, b};
}

struct Line {
    Line(const Point& a, const Point& b) {
        slope = a.x != b.x ? GetCanonicalForm(b.y - a.y, b.x - a.x) : Rational{1, 0};
        intercept = a.x != b.x ? GetCanonicalForm(b.x * a.y - a.x * b.y, b.x - a.x) : Rational{ a.x, 1 };
    }

    bool operator== (const Line& that) const {
        return slope == that.slope && intercept == that.intercept;
    }
    Rational slope, intercept;
};

struct HashLine {
    size_t operator()(const Line& ln) const {
        return std::hash<int>()(ln.slope.numerator) ^ std::hash<int>()(ln.slope.denomenator) ^
            std::hash<int>()(ln.intercept.numerator) ^ std::hash<int>()(ln.intercept.denomenator);
    }

};


int FindLineWithMostPoints(const vector<Point>& points) {
    std::unordered_map < Line, std::unordered_set<Point, HashPoint>, HashLine> table;

    for (int i = 0; i < points.size(); i++) {
        for (int j = i + 1; j < points.size(); j++) {
            Line ln(points[i], points[j]);
            
            table[ln].emplace(points[i]);
            table[ln].emplace(points[i]);
        }
    }

    /*Line lt = std::max_element(table.cbegin(), table.cend(), [](const auto& a, const auto& b) {
        return a.second.size() < b.second.size();
        })->first;
    */

    return std::max_element(table.cbegin(), table.cend(), [](const auto& a, const auto& b) {
            return a.second.size() < b.second.size();
        })->second.size();

}

namespace test_framework {
template <>
struct SerializationTrait<Point> : UserSerTrait<Point, int, int> {};
}  // namespace test_framework
bool operator==(const Point& lhs, const Point& rhs) {
  return std::tie(lhs.x, lhs.y) == std::tie(rhs.x, rhs.y);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"points"};
  return GenericTestMain(
      args, "line_through_most_points.cc", "line_through_most_points.tsv",
      &FindLineWithMostPoints, DefaultComparator{}, param_names);
}
