class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse(n), pse(n);
        stack<int> st;

        nse[n-1] = n;
        st.push(n-1);
        for(int i = n - 2; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        pse[0] = -1;
        st.push(0);
        for(int i = 1; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        int maxi = 0;
        for(int i = 0; i < n; i++){
            int area = heights[i] * (nse[i] - pse[i] - 1);
            maxi = max(maxi, area);
        }
        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> heights(m, 0);
        int maxArea = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '1')
                    heights[j] += 1; 
                else
                    heights[j] = 0;  
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }
};