# How to leetcode 

The goal is to build a project that will help me to solve leetcode problems.

# Use docker compose to start multiple containers

The first container is the coding environment, consisting of the neovim environment.

The second container is the execution environment, where all C++ code is compiled and executed.

The third container is the database container, where all the problems and solutions are stored. We choose database postgresql because it is easy to use and has a good performance.

The fourth container is the web server container, where the problems and solutions are displayed along with progress tracking.

There will be a scripts that will do the following: 

1. interact with the database container to get the problems and solutions.
2. interact with the coding environment to create a new file with the problem statement and the solution.
3. retrive from the database and output the solution to a single README.md file.


# Workflow

1. Start docker compose
2. Use script to get problem, and generate corresponding coding template.
3. Solve the problem in `neovim` container.
4. Build and test the problem in `execution` container.
5. Save the solution to the database.
6. Use script to convert the entire database to a single README.md file as well as a EPUBs file.
7. The simple web server can display the progress of the problems and solutions.

