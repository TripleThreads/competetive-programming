class Solution {
public:
    vector<int> rank, parent;
    int find(int node) {
        if (parent[node] == node) return node;
        return(parent[node] = find(parent[node]));
    }
    void uni(int a, int b) {
        a = find(a);
        b = find(b);
        if (rank[a] >= rank[b]) {
            parent[b] = a;
            rank[a]++;
        }
        else {
            parent[a] = b; 
            rank[b]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        vector<string> eq;
        for (string st : equations) {
            if (st[1] == '=')
                eq.push_back(st);
        }
        for (string st: equations) {
            if (st[1] == '!')
                eq.push_back(st);
        }
        parent = vector<int>(27);
        rank = vector<int>(27 + 1, 1);
        for (int i = 0; i < 26; i++) 
            parent[i] = i;
        
        for (string &e : eq) {
            if (find(e[0] - 'a') == find(e[3] - 'a') && e[1] == '!') return false;
            if (e[1] == '=')
                uni(e[0] - 'a', e[3] - 'a');
        }
        return true;
    }
};
