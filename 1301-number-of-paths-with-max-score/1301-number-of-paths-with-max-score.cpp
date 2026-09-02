class Solution { 
 
    int n; 
    int MOD = 1e9 + 7; 
    int INF = 1e9;
    vector<vector<pair<int, int>>> t; 
 
    int getIntFromChar(char ch) { 
        return ch != 'S' ? ch - '0' : 0; 
    } 
 
    bool isValid(int i, int j, vector<string>& board) { 
        return i >= 0 && i < n && j >= 0 && j < n && board[i][j] != 'X'; 
    } 
 
    pair<int, int> solve(int i, int j, vector<string>& board) { 
        
        if (board[i][j] == 'E')  
            return {0, 1};    
 
        if (board[i][j] == 'X')  
            return {-INF, 0};  
 
        if (t[i][j] != make_pair(-1, -1)) 
            return t[i][j]; 
 
        int upScore = -INF, upPaths = 0; 
        int leftScore = -INF, leftPaths = 0; 
        int diagScore = -INF, diagPaths = 0; 
 
        char ch = board[i][j]; 
 
        if (isValid(i - 1, j, board)) { 
            auto [score, paths] = solve(i - 1, j, board); 
            
            if (score != -INF) {
                upScore = score + getIntFromChar(ch); 
                upPaths = paths; 
            }
        } 
 
        if (isValid(i, j - 1, board)) { 
            auto [score, paths] = solve(i, j - 1, board); 
            
            if (score != -INF) {
                leftScore = score + getIntFromChar(ch); 
                leftPaths = paths; 
            }
        } 
 
        if (isValid(i - 1, j - 1, board)) { 
            auto [score, paths] = solve(i - 1, j - 1, board); 
            
            if (score != -INF) {
                diagScore = score + getIntFromChar(ch); 
                diagPaths = paths; 
            }
        } 
 
        int bestScore = max({upScore, leftScore, diagScore}); 

        // No path from this cell to E
        if (bestScore == -INF)
            return t[i][j] = {-INF, 0};

        long long bestPaths = 0;

        if (upScore == bestScore)
            bestPaths += upPaths;

        if (leftScore == bestScore)
            bestPaths += leftPaths;

        if (diagScore == bestScore)
            bestPaths += diagPaths;

        t[i][j] = {bestScore, (int)(bestPaths % MOD)}; 

        return t[i][j]; 
    } 
 
public: 
    vector<int> pathsWithMaxScore(vector<string>& board) { 
        n = board.size(); 
         
        t.assign(n, vector<pair<int, int>>(n, {-1, -1})); 
 
        auto result = solve(n - 1, n - 1, board); 

        if (result.second == 0 && result.first == -INF)
            return {0, 0};

        return {result.first, result.second}; 
    } 
};