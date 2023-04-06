/*
We have `n` jobs, where every job is scheduled to be done from `startTime[i]`
to `endTime[i]`, obtaining a profit of `profit[i]`.

You're given the `startTime`, `endTime` and `profit` arrays, return the
maximum profit you can take such that there are no two jobs in the subset with
overlapping time range.

If you choose a job that ends at time `X` you will be able to start another
job that starts at time `X`.

 **Example 1:**

 **![](https://assets.leetcode.com/uploads/2019/10/10/sample1_1584.png)**



     **Input:** startTime = [1,2,3,3], endTime = [3,4,5,6], profit =
[50,10,40,70] **Output:** 120 **Explanation:** The subset chosen is the first
and fourth job. Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.

 **Example 2:**

 **![](https://assets.leetcode.com/uploads/2019/10/10/sample22_1584.png)**



    **Input:** startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit =
[20,20,100,70,60] **Output:** 150 **Explanation:** The subset chosen is the
first, fourth and fifth job. Profit obtained 150 = 20 + 70 + 60.

 **Example 3:**

 **![](https://assets.leetcode.com/uploads/2019/10/10/sample3_1584.png)**



     **Input:** startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
**Output:** 6

 **Constraints:**

  * `1 <= startTime.length == endTime.length == profit.length <= 5 * 104`
  * `1 <= startTime[i] < endTime[i] <= 109`
  * `1 <= profit[i] <= 104`


*/

#include "leetcode.hpp"

class Solution {
public:
  // maximum number of jobs are 50000
  int memo[50001];

  int findMaxProfit(vector<vector<int>> &jobs, vector<int> &start, int n, int position) {

    // 0 profit if we have already iterated over all the jobs
    if (position == n) {
      return 0;
    }

    // we have already calculated the answer so no need to go into recursion
    if (memo[position] != -1) {
      return memo[position];
    }

    // nextIndex is the index of next non-conflicting job
    // this step is similar to the binary search as in the java solution
    // lower_bound will return the iterator to the first element which is
    // equal to or greater than the element at `jobs[position][1]`
    int nextIndex = lower_bound(start.begin(), start.end(), jobs[position][1]) - start.begin();

    // find the maximum profit of our two options: skipping or scheduling the current job

    int profit_skip_current = findMaxProfit(jobs, start, n, position + 1);
    int profit_select_current = jobs[position][2] + findMaxProfit(jobs, start, n, nextIndex);

    int maxProfit = max(profit_select_current, profit_skip_current);

    // memoization
    memo[position] = maxProfit;

    // returning maximum profit
    return maxProfit;

  }


  int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit) {
    vector<vector<int>> jobs;
    // marking all values to -1 so that we can differentiate
    // if we have already calculated the answer or not
    memset(memo, -1, sizeof(memo));

    // storing job's details into one list
    // this will help in sorting the jobs while maintaining the other parameters
    for (int i = 0; i < profit.size(); i++) {
      jobs.push_back({startTime[i], endTime[i], profit[i]});
    }

    sort(jobs.begin(), jobs.end());

    // binary search will be used in startTime so store it as separate list
    for (int i = 0; i < profit.size(); i++) {
      startTime[i] = jobs[i][0];
    }

    return findMaxProfit(jobs, startTime, profit.size(), 0);
  }
};

TEST_CASE("maximum-profit-in-job-scheduling", "[1235]") {
  Solution sol;
  vector<int> startTime = {1, 1, 1};
  vector<int> endTime = {2, 3, 4};
  vector<int> profit = {5, 6, 4};
  CHECK(sol.jobScheduling(startTime, endTime, profit) == 6);
}
