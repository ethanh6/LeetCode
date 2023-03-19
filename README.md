# Leetcode

This is a Leetcode solutions tracker developed using Python that automatically
retrieves code snippets from the Leetcode API. It comes with a preconfigured code template
that includes essential C++ headers and a Catch2 unit testing boilerplate to help verify
code correctness. CMake is utilized to streamline the building and testing process for ease of use.

```cpp
// template

#include "leetcode.hpp"

class Solution {
public:
    int func() {
      return 123;
    }
};

TEST_CASE("[question slug]", "[question id]"){
  Solution s;
  REQUIRE(s.func() == 123);
}
```

# Environment

- CMake & Make
  - build system
- [Catch2](https://github.com/catchorg/Catch2)
  - unit testing
- C++17
  - based on [leetcode official doc](https://support.leetcode.com/hc/en-us/articles/360011833974-What-are-the-environments-for-the-programming-languages-)
- [Leetcode API](https://pypi.org/project/python-leetcode/)
  - Python3 - scripting
  - GraphQL - fetch the code template
- [virtualenv](https://virtualenv.pypa.io/en/latest/)
- Neovim

# How to use

> all commands are run in project root directory

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

Enter the question url e.g. https://leetcode.com/problems/remove-element/

Corresponding C++ template file will be created at src/{id}-{slug}.cpp. `CMakeLists.txt` will also be updated.

If the question already exists, the script does nothing.

<br>

### 2. Code

```bash
./src/*.cpp
```

<br>

### 3. Generate project buildsystem

Run it once will suffice.

```bash
cmake -S . -B build
```

<br>

### 4. Build the project

```bash
cmake --build build
```

<br>

### 5. Compile & execute

This bash script would make the target, execute it, and remove it.

`question_id` is 4 digit number, front-padded with zeros.

```bash
make -C build <question_id> && ./build/<question_id> && make -C build clean
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

Reference: [My Neovim config](https://github.com/ethanh6/dotfiles/blob/main/.config/nvim/lua/user/keymaps.lua)

<br>

## todo:

1. build integration with neovim
2. auto-submit with leetcode api
