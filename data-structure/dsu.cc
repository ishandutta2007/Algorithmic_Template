/**
 * @brief 并查集 (Disjoint Set Union / Union-Find)
 */
class DSU {
private:
    std::vector<int> parent;
    std::vector<int> sz;     // 每个集合的大小
    int components;          // 当前连通分量的数量

public:
    // init from 0 ~ n-1
    explicit DSU(int n) : parent(n), sz(n, 1), components(n) {
        std::iota(parent.begin(), parent.end(), 0);
    }

    // find root
    int find(int u) {
        return parent[u] == u ? u: parent[u] = find(parent[u]);
    }

    // 合并两个元素所在的集合
    // return：如果发生了实际合并返回 true，若已在同一集合返回 false
    bool unite(int u, int v) {
        int root_u = find(u), root_v = find(v);
        if (root_u == root_v) return false;
        // 将较小的树合并到较大的树上，保持树的平衡
        if (sz[root_u] < sz[root_v]) {
            std::swap(root_u, root_v);
        }
        parent[root_v] = root_u;
        sz[root_u] += sz[root_v];
        components--; // 每成功合并一次，连通分量减少一个
        return true;
    }

    // 判断两个元素是否属于同一个集合
    bool same(int u, int v) {
        return find(u) == find(v);
    }

    // 获取元素 u 所属集合的大小
    int size(int u) {
        return sz[find(u)];
    }

    // 获取当前连通分量的总数
    int count() const {
        return components;
    }

    // reset
    void reset(int n) {
        parent.resize(n);
        std::iota(parent.begin(), parent.end(), 0);
        sz.assign(n, 1);
        components = n;
    }
};