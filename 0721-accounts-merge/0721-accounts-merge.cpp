class Solution {
public:

    int find(int x, vector<int>& parent) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x], parent);
    }

    void unite(int a, int b, vector<int>& parent, vector<int>& rank) {
        a = find(a, parent);
        b = find(b, parent);

        if (a == b) return;

        if (rank[a] < rank[b]) {
            parent[a] = b;
        }
        else if (rank[a] > rank[b]) {
            parent[b] = a;
        }
        else {
            parent[b] = a;
            rank[a]++;
        }
    }

    vector<vector<string>> accountsMerge(
        vector<vector<string>>& accounts
    ) {

        int n = accounts.size();

        vector<int> parent(n);
        vector<int> rank(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        // email -> account index
        unordered_map<string, int> emailToAccount;

        // Step 1: Union accounts having common emails
        for (int i = 0; i < n; i++) {

            for (int j = 1; j < accounts[i].size(); j++) {

                string email = accounts[i][j];

                if (emailToAccount.find(email) == emailToAccount.end()) {
                    // First time seeing this email
                    emailToAccount[email] = i;
                }
                else {
                    // Email already belongs to another account
                    unite(i, emailToAccount[email], parent, rank);
                }
            }
        }

        // Step 2: Group emails according to DSU root
        unordered_map<int, vector<string>> groups;

        for (auto& [email, account] : emailToAccount) {

            int root = find(account, parent);

            groups[root].push_back(email);
        }

        // Step 3: Build answer
        vector<vector<string>> ans;

        for (auto& [root, emails] : groups) {

            sort(emails.begin(), emails.end());

            vector<string> current;

            // Name of the person
            current.push_back(accounts[root][0]);

            // Sorted emails
            for (string& email : emails) {
                current.push_back(email);
            }

            ans.push_back(current);
        }

        return ans;
    }
};