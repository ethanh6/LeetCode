import os

template_cpp = """
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <assert.h>
using namespace std;

int main() {

  Solution sol;
  string ans;

  ans = sol.SampleFunc();
  assert(ans == xxx);

  return 0;
}
"""


# example question URL
# https://leetcode.com/problems/longest-common-subsequence/

# get slug and number and language
question_slug = input("Question URL? ").split("/")[-2]
question_number = input("Question number? ")
question_language = input("Question language [cpp/py] ? ")

dir_name = question_number + "." + question_slug
file_name = question_number + "." + question_language
os.mkdir(dir_name)

makefile = """
all: {}
	clang++ {} -o solu --std=c++17 && ./solu
""".format(file_name, file_name)


with open(os.path.join(dir_name, file_name), "w") as f:
    f.write(template_cpp)

with open(os.path.join(dir_name, "makefile"), "w") as f:
    f.write(makefile)








