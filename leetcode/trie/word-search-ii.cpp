//
// Created by segni on 27/02/2020.
//

struct TrieNode {
    struct TrieNode *children[26];
    bool isEndOfWord;
};

struct TrieNode *getNode(void) {
    struct TrieNode *node = new TrieNode;
    node->isEndOfWord = false;
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    return node;
};
class Solution {
public:
    unordered_set<string> result;

    void insert(TrieNode *root, string key) {
        TrieNode *crawl = root;
        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if (!crawl->children[index]) {
                crawl->children[index] = getNode();
            }
            crawl = crawl->children[index];
        }
        crawl->isEndOfWord = true;
    }
    bool startsWith(TrieNode * root, string key) {
        TrieNode *crawl = root;
        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if (!crawl->children[index]) {
                return false;
            }
            crawl = crawl->children[index];
        }
        return true;
    }

    bool search(TrieNode * root, string key) {
        TrieNode *crawl = root;
        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if (!crawl->children[index]) {
                return false;
            }
            crawl = crawl->children[index];
        }
        return (crawl != NULL && crawl->isEndOfWord);
    }

    void dfs(vector<vector<char>> &board, string word, int x, int y, TrieNode *root) {
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || board[x][y] == '1') {
            return;
        }
        word.push_back(board[x][y]);
        if (!startsWith(root, word)) {
            return;
        }
        if (search(root, word)) {
            result.insert(word);
        }
        char backUp = board[x][y];
        board[x][y] = '1';
        dfs(board, word, x - 1, y, root);
        dfs(board, word, x + 1, y, root);
        dfs(board, word, x, y - 1, root);
        dfs(board, word, x, y + 1, root);
        board[x][y] = backUp;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode *root = new TrieNode();
        for (auto word : words) {
            insert(root, word);
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, "", i, j, root);
            }
        }
        vector<string> res(result.begin(), result.end());
        return res;
    }
};