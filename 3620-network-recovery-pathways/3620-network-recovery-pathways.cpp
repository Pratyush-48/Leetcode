auto init = []() { ios_base::sync_with_stdio(false); cin.tie(NULL); return 0; }();
class Solution {
public:
    typedef pair<long long, int> p;
    bool check(const vector<vector<pair<int, int>>>& adj, int mid, long long k, int n) {
        priority_queue<p, vector<p>, greater<p>> mh;
        vector<long long> wt(n, LONG_LONG_MAX);
        wt[0] = 0;
        mh.push({0, 0});
        while (!mh.empty()) {
            long long costt = mh.top().first;
            int u = mh.top().second;
            mh.pop();
            if (u == n - 1) return true;
            if (costt > wt[u]) continue;
            for (auto& it : adj[u]) {
                int v = it.first;
                int wtt = it.second;
                if (wtt >= mid && ((costt + wtt) < wt[v]) && ((costt + wtt) <= k)) {
                    wt[v] = costt + wtt;
                    mh.push({wt[v], v});
                }
            }
        }
        return false;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> adj(n);
        int maxi = 0;
        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (online[u] && online[v]) {
                adj[u].push_back({v, wt});
                maxi = max(maxi, wt);
            }
        }
        int l = 0;
        int r = maxi;
        int result = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(adj, mid, k, n)) {
                result = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return result;
    }
};