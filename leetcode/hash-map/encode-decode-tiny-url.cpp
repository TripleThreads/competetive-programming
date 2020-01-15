//
// Created by segni on 15/01/2020.
//

class Solution {
public:
    map<long long, string> enc, dec;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        long long hash = compute_hash(longUrl);
        string baseUrl = "http://tinyurl.com/" + to_string(hash);
        enc[hash] = baseUrl;
        dec[compute_hash(baseUrl)] = longUrl;
        return baseUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return dec[compute_hash(shortUrl)];
    }

    long long compute_hash(string const& s) {
        const int p = 31;
        const int m = 1e9 + 9;
        long long hash_value = 0;
        long long p_pow = 1;
        for (char c : s) {
            hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
            p_pow = (p_pow * p) % m;
        }
        return hash_value;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));