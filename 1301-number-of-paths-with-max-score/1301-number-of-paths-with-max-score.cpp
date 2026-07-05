class Solution {
    int mod = 1e9 + 7;
    int dp_score[105][105];
    int dp_paths[105][105];
    bool visited[105][105];
    int n;

    pair<int, int> solve(int i, int j, vector<string>& board) {
        if (i < 0 || j < 0 || board[i][j] == 'X') {
            return {-1, 0}; 
        }
        
        if (i == 0 && j == 0) {
            return {0, 1}; 
        }

        if (visited[i][j]) {
            return {dp_score[i][j], dp_paths[i][j]};
        }
        visited[i][j] = true;

        pair<int, int> up = solve(i - 1, j, board);
        pair<int, int> left = solve(i, j - 1, board);
        pair<int, int> diag = solve(i - 1, j - 1, board);

        int max_sub_score = max({up.first, left.first, diag.first});

        if (max_sub_score == -1) {
            dp_score[i][j] = -1;
            dp_paths[i][j] = 0;
            return {-1, 0};
        }

        long long total_paths = 0;
        if (up.first == max_sub_score) total_paths = (total_paths + up.second) % mod;
        if (left.first == max_sub_score) total_paths = (total_paths + left.second) % mod;
        if (diag.first == max_sub_score) total_paths = (total_paths + diag.second) % mod;

        int current_val = 0;
        if (isdigit(board[i][j])) {
            current_val = board[i][j] - '0';
        }

        dp_score[i][j] = max_sub_score + current_val;
        dp_paths[i][j] = total_paths;

        return {dp_score[i][j], dp_paths[i][j]};
    }

public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();
        
        memset(visited, false, sizeof(visited));

        pair<int, int> res = solve(n - 1, n - 1, board);

        if (res.first == -1) {
            return {0, 0};
        }
        
        return {res.first, res.second};
    }
};