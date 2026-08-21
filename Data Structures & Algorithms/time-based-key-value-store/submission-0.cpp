class TimeMap {
public:
        unordered_map<string, map<int, string>> store;

    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        store[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(!store.contains(key)){
            return "";
        }
        else{
            auto& subStore = store[key];
            auto it = subStore.upper_bound(timestamp);
            if (it == subStore.begin()) {
                return "";
            }
            return prev(it)->second;
        }
    }
};