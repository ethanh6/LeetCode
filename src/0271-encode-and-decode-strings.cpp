#include "leetcode.hpp"

class Codec {
public:
  // Encodes a list of strings to a single string.
  string encode(vector<string> &strs) {
    string result("");
    for (const auto &s : strs) {
      result.append(to_string(s.size()) + "@" + s);
    }
    return result;
  }

  // Decodes a single string to a list of strings.
  vector<string> decode(string s) {
    vector<string> result{};

    int i = 0;
    while (i < s.size()) {
      int at_idx = s.find_first_of('@', i);

      int length = stoi(s.substr(i, at_idx - i));

      i = at_idx + 1;
      result.push_back(s.substr(i, length));
      i += length;
    }
    return result;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

// TEST_CASE("encode-and-decode-strings", "[0271]") {
//   Codec sol;
//   vector<string> input{"Hello", "Worlddd"};
//   auto encoded = sol.encode(input);
//   CHECK(encoded == "5@Hello7@Worlddd");
//   auto decoded = sol.decode(encoded);
//   CHECK(decoded == input);
// }

TEST_CASE("encode-and-decode-strings - 1", "[0271]") {
  Codec sol;
  vector<string> input { "63/Rc","h","BmI3FS~J9#vmk","7uBZ?7*/","24h+X","O " };
  auto encoded = sol.encode(input);
  CHECK(encoded == "5@63/Rc1@h13@BmI3FS~J9#vmk8@7uBZ?7*/5@24h+X2@O ");
  auto decoded = sol.decode(encoded);
  // CHECK(decoded == input);
}
