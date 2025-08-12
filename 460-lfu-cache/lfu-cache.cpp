#include <unordered_map>
#include <list>
using namespace std;

class LFUCache {
    int capacity, minFreq;
    unordered_map<int, pair<int,int>> keyToValFreq;  // key -> {value, freq}
    unordered_map<int, list<int>> freqToKeys;        // freq -> list of keys (LRU order)
    unordered_map<int, list<int>::iterator> keyToIter; // key -> iterator in freqToKeys[freq]
    
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        if (!keyToValFreq.count(key)) return -1;
        int val = keyToValFreq[key].first;
        int freq = keyToValFreq[key].second;
        
        // Remove from old freq list
        freqToKeys[freq].erase(keyToIter[key]);
        
        // If list is empty and freq was minFreq, update minFreq
        if (freqToKeys[freq].empty()) {
            freqToKeys.erase(freq);
            if (minFreq == freq) minFreq++;
        }
        
        // Increase frequency
        freq++;
        keyToValFreq[key].second = freq;
        freqToKeys[freq].push_front(key);
        keyToIter[key] = freqToKeys[freq].begin();
        
        return val;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        
        if (keyToValFreq.count(key)) {
            // Update value & bump frequency
            keyToValFreq[key].first = value;
            get(key); // reuse get to update freq
            return;
        }
        
        // Evict if at capacity
        if (keyToValFreq.size() == capacity) {
            int keyToRemove = freqToKeys[minFreq].back();
            freqToKeys[minFreq].pop_back();
            if (freqToKeys[minFreq].empty()) {
                freqToKeys.erase(minFreq);
            }
            keyToValFreq.erase(keyToRemove);
            keyToIter.erase(keyToRemove);
        }
        
        // Insert new key with freq=1
        keyToValFreq[key] = {value, 1};
        freqToKeys[1].push_front(key);
        keyToIter[key] = freqToKeys[1].begin();
        minFreq = 1;
    }
};
