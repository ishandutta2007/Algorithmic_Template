/**
 * @brief binary index tree (fenwick tree)
 */
template <typename T>
struct BIT {
  int n;
  vector<T> tree;
  BIT(int s) : n(s), tree(s + 1, 0) {}
  void add(int i, T v) {
    for (; i <= n; i += i & -i) tree[i] += v;
  }
  T query(int i) {
    T s = 0;
    for (; i > 0; i -= i & -i) s += tree[i];
    return s;
  }
  int find_kth(T k) {
    int id = 0, p2 = 1;
    while (p2 * 2 <= n) p2 *= 2;
    for (int i = p2; i > 0; i >>= 1) {
      if (id + i <= n && tree[id + i] < k) {
        id += i;
        k -= tree[id];
      }
    }
    return id + 1;
  }
};
