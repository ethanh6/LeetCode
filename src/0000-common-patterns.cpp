#include "leetcode.hpp"


TEST_CASE("accumulate") {
  vector<int> v {1, 2, 3, 4, 5};
  auto sum = accumulate(v.cbegin(), v.cend(), 0);
  REQUIRE(sum == 15);
}

TEST_CASE("min and max element") {
  vector<int> v {1, 2, 3, 4, 5};

  const auto _max = max_element(v.cbegin(), v.cend());
  REQUIRE(*_max == 5);

  const auto _min = min_element(v.cbegin(), v.cend());
  REQUIRE(*_min == 1);

  const auto _min_max = minmax_element(v.cbegin(), v.cend());
  REQUIRE(*_min_max.first == 1);
  REQUIRE(*_min_max.second == 5);
}


TEST_CASE("casting: str & int & float") {
  const string s = to_string(35);  // defined in <string>
  REQUIRE(s == "35");

  const string s1 = to_string(0.287);
  REQUIRE(s1 == "0.287000");

  int i = atoi("29");
  REQUIRE(i == 29);  // defined in <stdlib>

  float f = atof("0.123");
  REQUIRE(f == 0.123f);
}

TEST_CASE("converting: vector & set") {
  vector<string> v0 {"apple", "banana", "lemon"};
  set<string> s0 {v0.cbegin(), v0.cend()};  // vector -> set
  vector<string> v1 {s0.cbegin(), s0.cend()};  // set -> vector
  REQUIRE(v0 == v1);
}

TEST_CASE("custom compare object") {
  auto comp = [](const string& x, const string& y) {
    return x.size() > y.size();
  };

  priority_queue<string, vector<string>, decltype(comp)> pq(comp);

  REQUIRE(true);
}
