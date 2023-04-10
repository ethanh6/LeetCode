/*
Given a list of `accounts` where each element `accounts[i]` is a list of
strings, where the first element `accounts[i][0]` is a name, and the rest of
the elements are **emails** representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to
the same person if there is some common email to both accounts. Note that even
if two accounts have the same name, they may belong to different people as
people could have the same name. A person can have any number of accounts
initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the
first element of each account is the name, and the rest of the elements are
emails **in sorted order**. The accounts themselves can be returned in **any
order**.

 **Example 1:**



     **Input:** accounts =
[["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
**Output:**
[["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
**Explanation:** The first and second John's are the same person as they have
the common email "johnsmith@mail.com".The third John and Mary are different
people as none of their email addresses are used by other accounts.We could
return these lists in any order, for example the answer [['Mary',
'mary@mail.com'], ['John', 'johnnybravo@mail.com'], ['John', 'john00@mail.com',
'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.

 **Example 2:**



     **Input:** accounts =
[["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]
**Output:**
[["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]]

 **Constraints:**

  * `1 <= accounts.length <= 1000`
  * `2 <= accounts[i].length <= 10`
  * `1 <= accounts[i][j].length <= 30`
  * `accounts[i][0]` consists of English letters.
  * `accounts[i][j] (for j > 0)` is a valid email.


*/

#include "leetcode.hpp"

class Solution {
public:
  unordered_map<string, vector<string>> adjacent;
  unordered_set<string> visited;
  vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {

    // build the graph as adjacent list
    for (const auto &account : accounts) {
      const string firstEmail = account[1];
      for (int i = 2; i < account.size(); ++i) {
        string email = account[i];
        adjacent[email].push_back(firstEmail);
        adjacent[firstEmail].push_back(email);
      }
    }

    // answer to be returned
    vector<vector<string>> mergedAccounts;

    // traverse all the accounts
    for (const auto &account : accounts) {
      const string name = account[0];
      const string firstEmail = account[1];

      // if the new email is newly seen
      if (visited.count(firstEmail) == 0) {
        vector<string> newAccount{name};
        dfs(newAccount, firstEmail);

        // sort the emails
        sort(newAccount.begin() + 1, newAccount.end());
        mergedAccounts.push_back(newAccount);
      }
    }

    return mergedAccounts;
  }

  void dfs(vector<string> &mergedAccount, string email) {
    visited.insert(email);
    mergedAccount.push_back(email);

    for (const auto &adj_email : adjacent[email]) {

      // skip visited email
      if (visited.count(adj_email) != 0)
        continue;

      dfs(mergedAccount, adj_email);
    }
  }
};

class Solution_UF {
public:
  vector<vector<string>> accountsMerge(vector<vector<string>> &acts) {
    map<string, string> owner;
    map<string, string> parents;

    // declare function within function with std::function
    std::function<string(string)> findRoot = [&](string s) {
      return parents[s] == s ? s : findRoot(parents[s]);
    };

    // initialization of union find data structure
    for (const auto &act : acts) {
      string name = act[0];
      for (int i = 1; i < act[i].size(); ++i) {
        parents[act[i]] = act[i];
        owner[act[i]] = name;
      }
    }

    // set all the emails in the account points to the same root (aka the first
    // email)
    for (const auto &act : acts) {
      string firstEmail = act[1];
      string p = findRoot(firstEmail);
      for (int j = 2; j < act.size(); ++j) {
        string root = findRoot(act[j]);
        parents[root] = p;
      }
    }

    // union
    // map: email_root -> set<email>
    map<string, set<string>> unions;
    for (const auto &act : acts) {
      for (int j = 1; j < act.size(); ++j) {
        string email = act[j];
        string email_root = findRoot(email);
        unions[email_root].insert(
            email); // set<string> will maintain sorted internally
      }
    }

    vector<vector<string>> res;
    for (const auto &p : unions) {
      string name = p.first;
      set<string> email_set = p.second;

      // convert set<string> to vector<string>
      vector<string> emails(email_set.begin(), email_set.end());

      // insert one element to the front
      emails.insert(emails.begin(), owner[p.first]);
      res.push_back(emails);
    }
    return res;
  }

};

TEST_CASE("accounts-merge", "[0721]") {
  Solution sol;
  vector<vector<string>> accounts{
      {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
      {"John", "johnsmith@mail.com", "john00@mail.com"},
      {"Mary", "mary@mail.com"},
      {"John", "johnnybravo@mail.com"}};
  vector<vector<string>> output{{"John", "john00@mail.com",
                                 "john_newyork@mail.com", "johnsmith@mail.com"},
                                {"Mary", "mary@mail.com"},
                                {"John", "johnnybravo@mail.com"}};
  CHECK(sol.accountsMerge(accounts) == output);
}

TEST_CASE("accounts-merge - 1", "[0721]") {
  Solution sol;
  vector<vector<string>> accounts{
      {"Gabe", "Gabe0@m.co", "Gabe3@m.co", "Gabe1@m.co"},
      {"Kevin", "Kevin3@m.co", "Kevin5@m.co", "Kevin0@m.co"},
      {"Ethan", "Ethan5@m.co", "Ethan4@m.co", "Ethan0@m.co"},
      {"Hanzo", "Hanzo3@m.co", "Hanzo1@m.co", "Hanzo0@m.co"},
      {"Fern", "Fern5@m.co", "Fern1@m.co", "Fern0@m.co"}};

  vector<vector<string>> output{
      {"Gabe", "Gabe0@m.co", "Gabe1@m.co", "Gabe3@m.co"},
      {"Kevin", "Kevin0@m.co", "Kevin3@m.co", "Kevin5@m.co"},
      {"Ethan", "Ethan0@m.co", "Ethan4@m.co", "Ethan5@m.co"},
      {"Hanzo", "Hanzo0@m.co", "Hanzo1@m.co", "Hanzo3@m.co"},
      {"Fern", "Fern0@m.co", "Fern1@m.co", "Fern5@m.co"}};
  CHECK(sol.accountsMerge(accounts) == output);
}

TEST_CASE("accounts-merge - DSU", "[0721]") {
  Solution_UF sol;
  vector<vector<string>> accounts{
      {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
      {"John", "johnsmith@mail.com", "john00@mail.com"},
      {"Mary", "mary@mail.com"},
      {"John", "johnnybravo@mail.com"}};
  vector<vector<string>> output{{"John", "johnnybravo@mail.com"},
                                {"John", "john00@mail.com",
                                 "john_newyork@mail.com", "johnsmith@mail.com"},
                                {"Mary", "mary@mail.com"}};
  CHECK(sol.accountsMerge(accounts) == output);
}

// TEST_CASE("accounts-merge - DSU - 1", "[0721]") {
//   Solution_UF sol;
//   vector<vector<string>> accounts{
//       {"Gabe", "Gabe0@m.co", "Gabe3@m.co", "Gabe1@m.co"},
//       {"Kevin", "Kevin3@m.co", "Kevin5@m.co", "Kevin0@m.co"},
//       {"Ethan", "Ethan5@m.co", "Ethan4@m.co", "Ethan0@m.co"},
//       {"Hanzo", "Hanzo3@m.co", "Hanzo1@m.co", "Hanzo0@m.co"},
//       {"Fern", "Fern5@m.co", "Fern1@m.co", "Fern0@m.co"}};
//
//   vector<vector<string>> output{
//       {"Gabe", "Gabe0@m.co", "Gabe1@m.co", "Gabe3@m.co"},
//       {"Kevin", "Kevin0@m.co", "Kevin3@m.co", "Kevin5@m.co"},
//       {"Ethan", "Ethan0@m.co", "Ethan4@m.co", "Ethan5@m.co"},
//       {"Hanzo", "Hanzo0@m.co", "Hanzo1@m.co", "Hanzo3@m.co"},
//       {"Fern", "Fern0@m.co", "Fern1@m.co", "Fern5@m.co"}};
//   CHECK(sol.accountsMerge(accounts) == output);
// }
