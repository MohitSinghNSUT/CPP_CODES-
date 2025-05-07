#include <bits/stdc++.h>
using namespace std;
#define int long long

class SegmentTree
{
public:
    vector<int> tree;
    int n;

    SegmentTree(int size)
    {
        n = size;
        tree.resize(4 * n);
    }

    void build(int i, int l, int r, vector<int> &arr)
    {
        if (l == r)
        {
            tree[i] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(i * 2, l, mid, arr);
        build(i * 2 + 1, mid + 1, r, arr);
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }

    void update(int i, int l, int r, int pos, int val)
    {
        if (l == r)
        {
            tree[i] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid)
            update(i * 2, l, mid, pos, val);
        else
            update(i * 2 + 1, mid + 1, r, pos, val);
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }

    int query(int i, int l, int r, int ql, int qr)
    {
        if (qr < l || ql > r)
            return 0;
        if (ql <= l && r <= qr)
            return tree[i];
        int mid = (l + r) / 2;
        return query(i * 2, l, mid, ql, qr) + query(i * 2 + 1, mid + 1, r, ql, qr);
    }
};

class EulerTour
{
public:
    vector<int> in, out, flat;
    int timer = 0;

    EulerTour(vector<vector<int>> &graph, vector<int> &weights)
    {
        int n = graph.size();
        in.resize(n);
        out.resize(n);
        flat.resize(2 * n);
        vector<bool> visited(n, false);
        dfs(0, -1, graph, weights, visited);
    }

    void dfs(int u, int p, vector<vector<int>> &graph, vector<int> &weights, vector<bool> &visited)
    {
        in[u] = timer;
        flat[timer] = weights[u];
        visited[u] = true;
        timer++;
        for (int v : graph[u])
        {
            if (v != p)
            {
                dfs(v, u, graph, weights, visited);
            }
        }
        out[u] = timer;
    }
};

signed main()
{
    int n, q;
    cin >> n >> q;
    vector<int> weight(n);
    for (auto &w : weight)
        cin >> w;

    vector<vector<int>> graph(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--; // Adjusting for 0-based indexing
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    EulerTour e(graph, weight);
    SegmentTree sgt(2 * n);
    sgt.build(1, 0, 2 * n - 1, e.flat);

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int u, val;
            cin >> u >> val;
            u--; // Adjusting for 0-based indexing
            sgt.update(1, 0, 2 * n - 1, e.in[u], val);
            // sgt.update(1, 0, 2 * n - 1, e.out[u], val);
        }
        else
        {
            int u;
            cin >> u;
            u--; // Adjusting for 0-based indexing
            int sum = sgt.query(1, 0, 2 * n - 1, e.in[u], e.out[u]);
            cout << sum << '\n'; // Dividing by 2 to correct double-counting
        }
    }

    return 0;
}
