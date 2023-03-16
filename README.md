# Leetcode

This program is a Leetcode solutions tracker developed using Python that automatically
retrieves code snippets from the Leetcode API. It comes with a preconfigured code template
that includes essential C++ headers and a Catch2 unit testing boilerplate to help verify
code correctness. CMake is utilized to streamline the building and testing process for ease of use.

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

# How to use:

> all commands are run in project root directory

### 0 - Create and activate virtual env and install dependencies

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

### 4. Build project

Run it everytime a question is added, since changes are made to
`CMakeLists.txt`.

```bash
cmake --build build
```

<br>

### 5. Build the code with make

```bash
make -C build
```

<br>

### 6. Run tests

```bash
./build/<question_id>
```

<br>

### 7. Clean up (optional)

```bash
make -C build clean
```

<br>

## todo:

1. build integration with neovim
