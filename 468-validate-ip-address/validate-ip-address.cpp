#include <bits/stdc++.h>
using namespace std;

class Solution {
private: 
    // IPv4 check
    bool isIPv4(string queryIP) {
        int dot = 0;
        for (int i = 0; i < queryIP.size(); i++) {
            if (queryIP[i] == '.') dot++;
        }
        if (dot != 3) return false;

        vector<string> nums;
        stringstream ss(queryIP);
        string part;

        while (getline(ss, part, '.')) {
            nums.push_back(part);
        }

        if (nums.size() != 4) return false;

        for (string p : nums) {
            if (p.empty()) return false;
            if (p.size() > 1 && p[0] == '0') return false; // no leading zero
            if (p.size() > 3) return false;
            for (char c : p) {
                if (!isdigit(c)) return false;
            }
            int num = stoi(p);
            if (num < 0 || num > 255) return false;
        }
        return true;
    }

    // IPv6 check
    bool isIPv6(string queryIP) {
        int colon = 0;
        for (int i = 0; i < queryIP.size(); i++) {
            if (queryIP[i] == ':') colon++;
        }
        if (colon != 7) return false;

        vector<string> nums;
        stringstream ss(queryIP);
        string part;

        while (getline(ss, part, ':')) {
            nums.push_back(part);
        }

        if (nums.size() != 8) return false;

        for (string p : nums) {
            if (p.empty() || p.size() > 4) return false;
            for (char c : p) {
                if (!isxdigit(c)) return false; // must be hex digit
            }
        }
        return true;
    }

public:
    string validIPAddress(string queryIP) {
        if (queryIP.find('.') != string::npos) {
            return isIPv4(queryIP) ? "IPv4" : "Neither";
        }
        if (queryIP.find(':') != string::npos) {
            return isIPv6(queryIP) ? "IPv6" : "Neither";
        }
        return "Neither";
    }
};
