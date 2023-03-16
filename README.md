

# Leetcode automation


## How to use:
0. Activate virtual env: `source leetcode_env/bin/activate `
1. In project root, run script: `python3 scripts/add_questions.py`
2. Enter the question url e.g. https://leetcode.com/problems/remove-element/
3. Corresponding cpp template code will be created under src/ with filename being <question_id>-<question-slug>-<attempts>.cpp
4. Write code, and unit-test it.

## Environment
- CMake - build system
- Catch2 - unit test
- C++ 17 - based on [leetcode official doc](https://support.leetcode.com/hc/en-us/articles/360011833974-What-are-the-environments-for-the-programming-languages-)
- [Leetcode API](https://pypi.org/project/python-leetcode/)
  - python3
  - GraphQL

