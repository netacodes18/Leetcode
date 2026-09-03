class Solution {
public:
    string pushDominoes(string dominoes) {

        int n = dominoes.size();

        vector<int> left(n, -1);
        vector<int> right(n, -1);

        // Left -> Right
        // left[i] = i tak R ki force kitne distance/time mein aati hai
        int force = -1;

        for (int i = 0; i < n; i++) {

            if (dominoes[i] == 'R') {
                force = 0;
            }
            else if (dominoes[i] == 'L') {
                force = -1;
            }
            else if (force != -1) {
                force++;
            }

            left[i] = force;
        }

        // Right -> Left
        // right[i] = i tak L ki force kitne distance/time mein aati hai
        force = -1;

        for (int i = n - 1; i >= 0; i--) {

            if (dominoes[i] == 'L') {
                force = 0;
            }
            else if (dominoes[i] == 'R') {
                force = -1;
            }
            else if (force != -1) {
                force++;
            }

            right[i] = force;
        }

        // Combine both forces
        for (int i = 0; i < n; i++) {

            if (dominoes[i] != '.')
                continue;

            if (left[i] == -1 && right[i] == -1) {
                dominoes[i] = '.';
            }
            else if (left[i] == -1) {
                dominoes[i] = 'L';
            }
            else if (right[i] == -1) {
                dominoes[i] = 'R';
            }
            else if (left[i] < right[i]) {
                dominoes[i] = 'R';
            }
            else if (right[i] < left[i]) {
                dominoes[i] = 'L';
            }
            else {
                // Equal force
                dominoes[i] = '.';
            }
        }

        return dominoes;
    }
};