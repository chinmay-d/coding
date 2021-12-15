/*
 * @lc app=leetcode id=706 lang=cpp
 *
 * [706] Design HashMap
 */

// @lc code=start
// ["MyHashMap","put","put","get","get","put","get","remove","get"]\n[[],[1,1],[2,2],[1],[3],[2,1],[2],[2],[2]]

class MyHashMap {
public:
    /** Initialize your data structure here. */
    int mp[1000001];

    MyHashMap() {
        memset(mp, -1, 1000001);   //creates an array  with size=10000001 filled with -1
        mp[250005]=-1;     //manually set  mp[250005]=-1 as idk why it sets tht value to 0
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        mp[key] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return mp[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        mp[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end

