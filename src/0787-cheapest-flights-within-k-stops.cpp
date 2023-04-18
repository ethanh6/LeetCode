/*
There are `n` cities connected by some number of flights. You are given an
array `flights` where `flights[i] = [fromi, toi, pricei]` indicates that there
is a flight from city `fromi` to city `toi` with cost `pricei`.

You are also given three integers `src`, `dst`, and `k`, return _**the
cheapest price** from _`src` _to_`dst` _with at most_`k` _stops._ If there is
no such route, return __`-1`.

 **Example 1:**

![](https://assets.leetcode.com/uploads/2022/03/18/cheapest-flights-within-k-
stops-3drawio.png)



     **Input:** n = 4, flights =
[[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
**Output:** 700 **Explanation:** The graph is shown above.The optimal path with
at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 =
700.Note that the path through cities [0,1,2,3] is cheaper but is invalid
because it uses 2 stops.

 **Example 2:**

![](https://assets.leetcode.com/uploads/2022/03/18/cheapest-flights-within-k-
stops-1drawio.png)



     **Input:** n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst =
2, k = 1 **Output:** 200 **Explanation:** The graph is shown above.The optimal
path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 +
100 = 200.

 **Example 3:**

![](https://assets.leetcode.com/uploads/2022/03/18/cheapest-flights-within-k-
stops-2drawio.png)



     **Input:** n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst =
2, k = 0 **Output:** 500 **Explanation:** The graph is shown above.The optimal
path with no stops from city 0 to 2 is marked in red and has cost 500.

 **Constraints:**

  * `1 <= n <= 100`
  * `0 <= flights.length <= (n * (n - 1) / 2)`
  * `flights[i].length == 3`
  * `0 <= fromi, toi < n`
  * `fromi != toi`
  * `1 <= pricei <= 104`
  * There will not be any multiple flights between two cities.
  * `0 <= src, dst, k < n`
  * `src != dst`


*/

#include "leetcode.hpp"

class Solution_with_node_class {
public:
  class Node {
  public:
    Node() {}
    Node(int _id, int _cost) : id(_id), cost(_cost) {}
    int id, cost;
    friend std::ostream &operator<<(std::ostream &o, const Node &node) {
      o << "(" << node.id << ", " << node.cost << ")";
      return o;
    }
  };
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                        int k) {

    // adjacent representation of graph
    vector<vector<Node>> adj(n);
    for (const auto &edge : flights) {
      int from = edge[0], to = edge[1], cost = edge[2];
      adj[from].push_back(Node(to, cost));
    }

    // min priority queue, compared by price
    struct {
      bool operator()(const Node &a, const Node &b) const {
        return a.cost > b.cost;
      }
    } NodeLess;
    priority_queue<Node, vector<Node>, decltype(NodeLess)> pq(NodeLess);

    unordered_map<int, Node> visited;
    pq.push(Node(src, 0));

    for (int step = 0; !pq.empty(); pq.pop(), ++step) {
      Node cur_node = pq.top();

      cout << cur_node << " " << step << endl;
      visited[cur_node.id] = cur_node;

      // min path found
      if (cur_node.id == dst && step <= k + 1) {
        return cur_node.cost;
      }

      // explore neighbor nodes
      for (const auto &next_node : adj[cur_node.id]) {
        int new_cost = cur_node.cost + next_node.cost;
        if (visited.count(next_node.id) == 0 ||
            (visited.count(next_node.id) != 0 &&
             new_cost < visited[next_node.id].cost)) {
          auto new_node = Node(next_node.id, new_cost);
          visited[next_node.id] = new_node;
          pq.push(new_node);
        }
      }
    }

    return -1;
  }
};

class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                        int k) {
    // Create adjList
    // map: from -> vector<{to, price}>
    unordered_map<int, vector<pair<int, int>>> adjList;
    for (auto flight : flights)
      adjList[flight[0]].push_back({flight[1], flight[2]});

    // minHeap based on cost of distance from source
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
        minHeap;

    // avoid TLE
    vector<int> dist(n, INT_MAX);

    // cost, vertex, hops
    minHeap.push({0, src, 0});

    // perform Dijkstra
    for (; !minHeap.empty(); minHeap.pop()) {
      auto t = minHeap.top();
      int cost = t[0], curr = t[1], stop = t[2];

      // optimization to avoid TLE
      if (dist[curr] < stop)
        continue;
      dist[curr] = stop;

      // solution found
      if (curr == dst) 
        return cost;

      // stop exploring when there's no more stops to go
      if (stop > k) 
        continue;

      for (auto next : adjList[curr]) 
        minHeap.push(vector<int>{cost + next.second, next.first, stop + 1});

    }
    return -1;
  }
};

TEST_CASE("cheapest-flights-within-k-stops", "[0787]") {
  Solution sol;
  vector<vector<int>> flights{
      {0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
  int n = 4, src = 0, dst = 3, k = 1, output = 700;
  CHECK(sol.findCheapestPrice(n, flights, src, dst, k) == output);
}

TEST_CASE("cheapest-flights-within-k-stops - 1", "[0787]") {
  Solution sol;
  vector<vector<int>> flights{{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
  int n = 3, src = 0, dst = 2, k = 1, output = 200;
  CHECK(sol.findCheapestPrice(n, flights, src, dst, k) == output);
}

TEST_CASE("cheapest-flights-within-k-stops - 2", "[0787]") {
  Solution sol;
  vector<vector<int>> flights{{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
  int n = 3, src = 0, dst = 2, k = 0, output = 500;
  CHECK(sol.findCheapestPrice(n, flights, src, dst, k) == output);
}

TEST_CASE("cheapest-flights-within-k-stops - 3", "[0787]") {
  Solution sol;
  vector<vector<int>> flights{
      {0, 1, 100}, {1, 2, 400}, {0, 2, 300}, {2, 3, 50}};
  int n = 4, src = 0, dst = 3, k = 2, output = 350;
  CHECK(sol.findCheapestPrice(n, flights, src, dst, k) == output);
}
