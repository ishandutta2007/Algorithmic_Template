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
};
