# Leetcode solution tracker

This is a Leetcode solutions tracker built with Python that automatically
retrieves code snippets from the Leetcode API. It comes with a preconfigured code template
that includes essential C++ headers and a Catch2 unit testing boilerplate to help verify
code correctness. CMake is utilized to streamline the building and testing process for ease of use.

This problem set is based on [Grind 169](https://www.techinterviewhandbook.org/grind75?hours=30&difficulty=Medium&difficulty=Hard&difficulty=Easy&weeks=5&mode=preferences&order=topics&grouping=weeks#).


# Environment

- [CMake](https://cmake.org/)
  - the build system
- [Catch2](https://github.com/catchorg/Catch2)
  - unit testing
- C++20
  - based on [leetcode official doc](https://support.leetcode.com/hc/en-us/articles/360011833974-What-are-the-environments-for-the-programming-languages-)
- [Leetcode API](https://pypi.org/project/python-leetcode/)
  - Python3 - scripting
  - GraphQL - fetch the code template
- [Python virtualenv](https://virtualenv.pypa.io/en/latest/)
- Neovim

# How to use

### 0. Create and activate virtual env and install dependencies

```
virtualenv leetcode_env
source leetcode_env/bin/activate
pip3 install -r requirements.txt
```

<br>

### 1. Add question

```bash
python3 scripts/add_question.py
```

Enter the question url after prompt e.g. https://leetcode.com/problems/remove-element/

Corresponding C++ template file will be created as `src/<question_id>-<question_slug>.cpp`.

`CMakeLists.txt` will also be updated.

If the question already exists, the script will prompt that it exists and does nothing to the file structures.

The template:
```cpp

#include "leetcode.hpp"

class Solution {
public:
    int func() {
        return 123;
    }
};

TEST_CASE("[question slug]", "[question id]"){
    Solution sol;
    CHECK(sol.func() == 123);
}
```

<br>

### 2. Think and code

`question_id` is 4 digit number, front-padded with zeros.

```bash
./src/<question_id>.cpp
```

<br>

### 3. Build project

```bash
cmake -S . -B build
```

<br>

### 4. Build all targets

```bash
cmake --build build
```

or build only single target (this will only build `./build/<question_id>`)

```bash
cmake --build build --target <questioni_id>
```

<br>

### 5. Execute your solution

```bash
./build/<question_id>
```
<br>
Or run with keymap

```vim
<leader>make

-- this will be mapped to the following commands.
-- strpart(expand('%:t') retrieves the 4 digit question id, which is the target name.

:execute '!make -C build ' . strpart(expand('%:t'), 0, 4)<cr>:execute '!./build/' . strpart(expand('%:t'), 0, 4)<cr>:make -C build clean<cr>
```
<br>
For instance, say the current buffer is "src/0001-two-sum.cpp", the script would
be interpreted as

`make -C build 0001 && ./build/0001 && make -C build clean`

A single script to build -> run -> clean:

```bash
cmake --build build --target <question_id>; ./build/<question_id>; cmake --build build --target clean
```

Reference: [My Neovim config](https://github.com/ethanh6/dotfiles/blob/main/.config/nvim/lua/user/keymaps.lua)
