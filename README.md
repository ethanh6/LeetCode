# Leetcode problems
## c++ solutions


## How to use:
### all commands are run in project root directory
0. Activate virtual env: `source leetcode_env/bin/activate `
1. Run script: `python3 scripts/add_questions.py`
2. Enter the question url e.g. https://leetcode.com/problems/remove-element/
3. Corresponding c++ template code will be created under src/ with filename being <question_id>-<question-slug>.cpp and update `CMakeLists.txt` accordingly. If the question already exists, the script will do nothing.
4. Write code in `./src/*.cpp`, and unit-test it.
5. Generate a Project Buildsystem (run it once will suffice): `cmake -S . -B build`
6. Build project (run it everytime a question is added, meaning changes happen in CMakeLists.txt): `cmake --build build`
7. Build the code with make: `make -C build`
8. Run it with `./build/<question_id>` and see result



## Environment
- CMake - build system
- Catch2 - unit test
- C++ 17 - based on [leetcode official doc](https://support.leetcode.com/hc/en-us/articles/360011833974-What-are-the-environments-for-the-programming-languages-)
- [Leetcode API](https://pypi.org/project/python-leetcode/)
  - python3
  - GraphQL

