# Leetcode
> C++ solutions tracker with automation

## Environment
- CMake & make - build system
- Catch2 - unit testing
- C++ 17 - based on [leetcode official doc](https://support.leetcode.com/hc/en-us/articles/360011833974-What-are-the-environments-for-the-programming-languages-)
- [Leetcode API package](https://pypi.org/project/python-leetcode/)
  - python3
  - GraphQL
- Neovim

## How to use:
> all commands are run in project root directory

### 0. Activate virtual env:
```
source leetcode_env/bin/activate
```

### 1. Add question with script:
```bash
python3 scripts/add_question.py
```
And enter the question url e.g. https://leetcode.com/problems/remove-element/

Corresponding c++ template code will be created under src/ with filename being {id}-{slug}.cpp. `CMakeLists.txt` will also be updated.

If the question already exists, the script will do nothing.

### 2. Write code in file
```bash
./src/*.cpp
```

### 3. Generate a Project Buildsystem (run it once will suffice):
```bash
cmake -S . -B build
```

### 4. Build project (run it everytime a question is added, meaning changes happen in CMakeLists.txt):
```bash
cmake --build build
```

### 5. Build the code with make:
```bash
make -C build
```

### 6. See test result
```bash
./build/<question_id>
```

### 7. cleanup
```bash
make -C build clean
```

## todo:
1. build integration with neovim
