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


template_py = """

from typing import Optional

sol = Solution
myans = sol.Func()
ans = 0
assert(ans == myans)
print("(1) passed")

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
	clang++ {} -o solu --std=c++17 && ./solu && rm solu
clean:
	rm solu
""".format(file_name, file_name)


with open(os.path.join(dir_name, file_name), "w") as f:
    if question_language == "cpp":
        f.write(template_cpp)
    elif question_language == "py":
        f.write(template_py)

with open(os.path.join(dir_name, "makefile"), "w") as f:
    f.write(makefile)


print("Problem directory -> " + os.path.join(dir_name) + " created.")






