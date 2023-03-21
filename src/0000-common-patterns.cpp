#include "leetcode.hpp"

TEST_CASE("accumulate") {
  vector<int> v{1, 2, 3, 4, 5};
  auto sum = accumulate(v.cbegin(), v.cend(), 0);
  REQUIRE(sum == 15);
}

TEST_CASE("min and max element") {
  vector<int> v{1, 2, 3, 4, 5};

  const auto _max = max_element(v.cbegin(), v.cend());
  REQUIRE(*_max == 5);

  const auto _min = min_element(v.cbegin(), v.cend());
  REQUIRE(*_min == 1);

  const auto _min_max = minmax_element(v.cbegin(), v.cend());
  REQUIRE(*_min_max.first == 1);
  REQUIRE(*_min_max.second == 5);
}

TEST_CASE("casting: str & int & float") {
  const string s = to_string(35); // defined in <string>
  REQUIRE(s == "35");

  const string s1 = to_string(0.287);
  REQUIRE(s1 == "0.287000");

  int i = atoi("29");
  REQUIRE(i == 29); // defined in <stdlib>

  float f = atof("0.123");
  REQUIRE(f == 0.123f);
}

TEST_CASE("converting: vector & set") {
  vector<string> v0{"apple", "banana", "lemon"};
  set<string> s0{v0.cbegin(), v0.cend()};    // vector -> set
  vector<string> v1{s0.cbegin(), s0.cend()}; // set -> vector
  REQUIRE(v0 == v1);
}

TEST_CASE("custom compare, priority_queue") {
  const auto data = {"a", "aaa", "aaaaa"};

  auto comp = [](const string &x, const string &y) {
    return x.size() < y.size();
  };

  priority_queue<string, vector<string>, decltype(comp)> pq(comp);
  for (const auto x : data) {
    pq.emplace(x);
  }

  REQUIRE(pq.top() == "aaaaa");
  pq.pop();

  REQUIRE(pq.top() == "aaa");
  pq.pop();

  REQUIRE(pq.top() == "a");
  pq.pop();
}

TEST_CASE("4 direction grid problems") {
  int x = 0, y = 0;
  int m = 100, n = 100; // 100 x 100 grid

  vector<pair<int, int>> record{};

  vector<pair<int, int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  for (const auto &d : dir) {
    x += d.first;
    y += d.second;
    if (x >= 0 && y >= 0 && x < m && y < n) {
      record.push_back(pair<int, int>{x, y});
    }
  }
  REQUIRE(record[0].first == 0);
  REQUIRE(record[0].second == 1);

  REQUIRE(record[1].first == 0);
  REQUIRE(record[1].second == 0);

  REQUIRE(record[2].first == 1);
  REQUIRE(record[2].second == 0);

  REQUIRE(record[3].first == 0);
  REQUIRE(record[3].second == 0);
}

TEST_CASE("split string with delimeter") {

  SECTION("method 1") {
    string s0 = "please split me by spaces";
    string buf;
    stringstream ss(s0);
    vector<string> tokens{};
    while (ss >> buf) {
      tokens.emplace_back(buf);
    }

    REQUIRE(tokens[0] == "please");
    REQUIRE(tokens[1] == "split");
    REQUIRE(tokens[2] == "me");
    REQUIRE(tokens[3] == "by");
    REQUIRE(tokens[4] == "spaces");
  }

  SECTION("method 2 - does not take delimeter") {
    string sentence = "And I feel fine...";
    istringstream iss(sentence);
    vector<string> tokens{istream_iterator<string>{iss},
                          istream_iterator<string>{}};
    REQUIRE(tokens[0] == "And");
    REQUIRE(tokens[1] == "I");
    REQUIRE(tokens[2] == "feel");
    REQUIRE(tokens[3] == "fine...");
  }

  SECTION("method 3 - with custom delimeter") {
    string sentence = "a;b;c;d;e";
    string buf;
    stringstream ss(sentence);
    vector<string> tokens;

    while (getline(ss, buf, ';')) {
      tokens.emplace_back(buf);
    }

    REQUIRE(tokens[0] == "a");
    REQUIRE(tokens[1] == "b");
    REQUIRE(tokens[2] == "c");
    REQUIRE(tokens[3] == "d");
  }
}

TEST_CASE("right most set bit") {
  auto x = 5; // 0b101
  REQUIRE((x & -x) == 1);

  auto y = 12; // 0b01100
  REQUIRE((y & -y) == 4);
}

TEST_CASE("cyclic array") {
  vector<int> nums{1, 3, 5, 7, 9};
  int _size = nums.size();
  vector<int> res(_size * 2);

  for (int i = 0; i < _size * 2; ++i) {
    res[i] = nums[i % _size];
  }

  REQUIRE(res.size() == 10);
  REQUIRE(res == vector<int>{1, 3, 5, 7, 9, 1, 3, 5, 7, 9});
}

TEST_CASE("vector comparison") {
  vector<int> v1{1, 2, 3};
  vector<int> v2{1, 2, 3};
  REQUIRE(v1 == v2);
}

int mygcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b); // tail recursion
}

TEST_CASE("gcd - greatest common divisor") {
  REQUIRE(mygcd(100, 12) == 4);

  // or use the stdlib version
  constexpr auto p{3 * 7 * 11};
  constexpr auto q{3 * 11 * 17};
  REQUIRE(std::gcd(p, q) == 3 * 11);
}

TEST_CASE("concat char to string") {
  char c0 = 'a', c1 = 'b';

  // this isn't concatenation since chars are treated as integer
  REQUIRE(c0 + c1 == 195);

  // append char to a empty string makes the intended result
  REQUIRE(string("") + c0 + c1 == string("ab"));
}

TEST_CASE("combination") {
  string s = "abcd";
  int _size = s.size();
  vector<string> res;
  for (int i = 0; i < _size; ++i) {
    for (int j = i + 1; j < _size; ++j) {
      res.emplace_back(string("") + s[i] + s[j]);
    }
  }
  REQUIRE(res == vector<string>{"ab", "ac", "ad", "bc", "bd", "cd"});
}

TEST_CASE("remove element from vector") {
  vector<int> nums {1, 2, 3, 4, 5};
  nums.erase(nums.begin() + 1);
  REQUIRE(nums == vector<int> {1, 3, 4, 5});

  nums.pop_back();
  REQUIRE(nums == vector<int> {1, 3, 4});

}
