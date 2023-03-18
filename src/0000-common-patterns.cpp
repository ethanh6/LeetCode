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
