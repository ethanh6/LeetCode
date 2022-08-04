# LRU Cache


## Solution
Things you need:
1. A list (aka double-linked-list) as cache to achieve O(1) get and put time.
2. A key->value mapping
3. A key->[list iterator] mapping

Additionally, maintain the three data structure when calling `get` and `put`.

- The `get` method is simpler. If the key doesn't exist, return -1. If it does,
update `cache`, `key_2_it` and `kv`.

- The `put` method is where the complixity exists. I divided into 4 cases: 

  1. capacity full and key doesn't exist
  2. capacity full and key exists
  3. capacity not full and key doesn't exist
  4. capacity not full and key exist

The code is self-explanatory. </br>

The key is to think of the 4 cases and maintain the data structure accordingly. </br>

Although there exists some dulicate code among the 4 cases, it would be simpler if 
they are considered separately.
