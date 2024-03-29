cmake_minimum_required(VERSION 3.20)
project(LeetCode CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENTIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

message(STATUS "CMAKE_CXX_COMPILER: ${CMAKE_CXX_COMPILER}")
message(STATUS "CMAKE_EXPORT_COMPILE_COMMANDS: ${CMAKE_EXPORT_COMPILE_COMMANDS}")
message(STATUS "CMAKE_TOOLCHAIN_FILE: ${CMAKE_TOOLCHAIN_FILE}")
message(STATUS "PROJECT_SOURCE_DIR: " ${PROJECT_SOURCE_DIR})

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
endif()

find_package(Catch2 3 REQUIRED)

function(add_problem id slug)
    add_executable(${id} ${PROJECT_SOURCE_DIR}/src/${id}-${slug}.cpp)
    target_link_libraries(${id} PRIVATE Catch2::Catch2WithMain)
endfunction(add_problem)

# leetcode contests
add_problem(9999 weekly-contest)

# list of questions here

add_problem(0000 common-patterns)
add_problem(0001 two-sum)
add_problem(0121 best-time-to-buy-and-sell-stock)
add_problem(0015 3sum)
add_problem(0238 product-of-array-except-self)
add_problem(0039 combination-sum)
add_problem(0056 merge-intervals)
add_problem(0169 majority-element)
add_problem(0075 sort-colors)
add_problem(0217 contains-duplicate)
add_problem(0011 container-with-most-water)
add_problem(0252 meeting-rooms)
add_problem(0134 gas-station)
add_problem(0128 longest-consecutive-sequence)
add_problem(0189 rotate-array)
add_problem(0525 contiguous-array)
add_problem(0560 subarray-sum-equals-k)
add_problem(0759 employee-free-time)
add_problem(0283 move-zeroes)
add_problem(0253 meeting-rooms-ii)
add_problem(0977 squares-of-a-sorted-array)
add_problem(0239 sliding-window-maximum)
add_problem(0016 3sum-closest)
add_problem(0435 non-overlapping-intervals)
add_problem(0125 valid-palindrome)
add_problem(0242 valid-anagram)
add_problem(0003 longest-substring-without-repeating-characters)
add_problem(0409 longest-palindrome)
add_problem(0076 minimum-window-substring)
add_problem(0008 string-to-integer-atoi)
add_problem(0005 longest-palindromic-substring)
add_problem(0438 find-all-anagrams-in-a-string)
add_problem(0049 group-anagrams)
add_problem(0424 longest-repeating-character-replacement)
add_problem(0014 longest-common-prefix)
add_problem(0179 largest-number)
add_problem(0271 encode-and-decode-strings)
add_problem(0336 palindrome-pairs)
add_problem(0054 spiral-matrix)
add_problem(0036 valid-sudoku)
add_problem(0048 rotate-image)
add_problem(0073 set-matrix-zeroes)
add_problem(0704 binary-search)
add_problem(0037 sudoku-solver)
add_problem(0278 first-bad-version)
add_problem(0033 search-in-rotated-sorted-array)
add_problem(0981 time-based-key-value-store)
add_problem(1235 maximum-profit-in-job-scheduling)
add_problem(0074 search-a-2d-matrix)
# add_problem(0004 median-of-two-sorted-arrays)
add_problem(0153 find-minimum-in-rotated-sorted-array)
add_problem(0733 flood-fill)
add_problem(0542 01-matrix)
add_problem(0133 clone-graph)
add_problem(0207 course-schedule)
add_problem(0200 number-of-islands)
add_problem(0994 rotting-oranges)
add_problem(0721 accounts-merge)
add_problem(0079 word-search)
add_problem(0127 word-ladder)
add_problem(0310 minimum-height-trees)
add_problem(0417 pacific-atlantic-water-flow)
add_problem(1730 shortest-path-to-get-food)
add_problem(0261 graph-valid-tree)
add_problem(0210 course-schedule-ii)
add_problem(0323 number-of-connected-components-in-an-undirected-graph)
add_problem(1197 minimum-knight-moves)
# add_problem(0329 longest-increasing-path-in-a-matrix)
# add_problem(0212 word-search-ii)
# add_problem(0269 alien-dictionary)
# add_problem(0815 bus-routes)
add_problem(0787 cheapest-flights-within-k-stops)
add_problem(1768 merge-strings-alternately)
add_problem(0235 lowest-common-ancestor-of-a-binary-search-tree)
add_problem(0098 validate-binary-search-tree)
add_problem(0230 kth-smallest-element-in-a-bst)
add_problem(0285 inorder-successor-in-bst)
add_problem(0108 convert-sorted-array-to-binary-search-tree)
add_problem(0226 invert-binary-tree)
add_problem(0110 balanced-binary-tree)
add_problem(0102 binary-tree-level-order-traversal)
add_problem(0236 lowest-common-ancestor-of-a-binary-tree)
add_problem(0543 diameter-of-binary-tree)
add_problem(0199 binary-tree-right-side-view)
add_problem(0104 maximum-depth-of-binary-tree)
add_problem(0105 construct-binary-tree-from-preorder-and-inorder-traversal)
add_problem(0113 path-sum-ii)
add_problem(0662 maximum-width-of-binary-tree)
add_problem(0100 same-tree)
add_problem(0103 binary-tree-zigzag-level-order-traversal)
add_problem(0437 path-sum-iii)
add_problem(0101 symmetric-tree)
add_problem(0863 all-nodes-distance-k-in-binary-tree)
add_problem(0572 subtree-of-another-tree)
add_problem(0383 ransom-note)
add_problem(0380 insert-delete-getrandom-o1)
add_problem(0046 permutations)
add_problem(0078 subsets)
add_problem(0017 letter-combinations-of-a-phone-number)
add_problem(0031 next-permutation)
add_problem(0022 generate-parentheses)
add_problem(0021 merge-two-sorted-lists)
add_problem(0141 linked-list-cycle)
add_problem(0206 reverse-linked-list)
add_problem(0876 middle-of-the-linked-list)
add_problem(0146 lru-cache)
add_problem(0019 remove-nth-node-from-end-of-list)
add_problem(0024 swap-nodes-in-pairs)
add_problem(0328 odd-even-linked-list)
add_problem(0002 add-two-numbers)
add_problem(0148 sort-list)
add_problem(0234 palindrome-linked-list)
add_problem(0143 reorder-list)
add_problem(0061 rotate-list)
add_problem(0020 valid-parentheses)
add_problem(0155 min-stack)
add_problem(0739 daily-temperatures)
add_problem(0844 backspace-string-compare)
add_problem(0394 decode-string)
add_problem(0735 asteroid-collision)
add_problem(0227 basic-calculator-ii)
add_problem(0362 design-hit-counter)
add_problem(0973 k-closest-points-to-origin)
add_problem(1027 longest-arithmetic-subsequence)
add_problem(0621 task-scheduler)
add_problem(0692 top-k-frequent-words)
add_problem(0373 find-k-pairs-with-smallest-sums)
add_problem(0215 kth-largest-element-in-an-array)
add_problem(0208 implement-trie-prefix-tree)
add_problem(0139 word-break)
add_problem(0211 design-add-and-search-words-data-structure)
add_problem(0053 maximum-subarray)
add_problem(0322 coin-change)
add_problem(0070 climbing-stairs)
add_problem(0416 partition-equal-subset-sum)
add_problem(0062 unique-paths)
add_problem(0198 house-robber)
add_problem(0152 maximum-product-subarray)
add_problem(0300 longest-increasing-subsequence)
add_problem(0055 jump-game)
add_problem(0091 decode-ways)
add_problem(0377 combination-sum-iv)
add_problem(0067 add-binary)
add_problem(0287 find-the-duplicate-number)
add_problem(0338 counting-bits)
add_problem(0191 number-of-1-bits)
add_problem(0136 single-number)
add_problem(0268 missing-number)
add_problem(0190 reverse-bits)
add_problem(0013 roman-to-integer)
add_problem(0528 random-pick-with-weight)
add_problem(0050 powx-n)
add_problem(0007 reverse-integer)
add_problem(0009 palindrome-number)
add_problem(0673 number-of-longest-increasing-subsequence)
add_problem(0088 merge-sorted-array)
add_problem(0027 remove-element)
add_problem(0026 remove-duplicates-from-sorted-array)
add_problem(0080 remove-duplicates-from-sorted-array-ii)
add_problem(0122 best-time-to-buy-and-sell-stock-ii)
add_problem(0045 jump-game-ii)
add_problem(0274 h-index)
