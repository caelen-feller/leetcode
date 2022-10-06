class TimeMap {
    unordered_map<string, vector<pair<int,string>>> data;
    
public:
    TimeMap() {        
    }
    
    void set(string key, string value, int timestamp) {
        data[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(data.find(key) == data.end()) return "";
        vector<pair<int, string>> * vals = &(data.find(key)->second);
        
        if(vals->size() < 32) {
            for(auto i = vals->rbegin(); i!=vals->rend(); i++){
                if(i->first<=timestamp){
                    return i->second;
                }
            }
        } else {
        
            int left = 0;
            int right =  vals->size() - 1;
            int mid; 
            while (left <= right) {
                if((*vals)[right].first <= timestamp) return (*vals)[right].second;
                mid = (right + left) / 2;
                if ((*vals)[mid].first > timestamp) right = mid - 1;
                if ((*vals)[mid].first == timestamp) return (*vals)[mid].second;
                if ((*vals)[mid].first < timestamp) left =  mid + 1;
            }
            if (right >= 0) return (*vals)[right].second;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

// class TimeMap {
//     list<pair<pair<int,string>,string>> data;
    
// public:
//     TimeMap() {        
//     }
    
//     void set(string key, string value, int timestamp) {
//         data.push_back({{timestamp,value}, key});
//     }
    
//     string get(string key, int timestamp) {
//         for(auto i = data.rbegin(); i!=data.rend(); i++){
//             if(i->second==key && i->first.first<=timestamp){
//                 return i->first.second;
//             }
//         }
//         return "";
//     }
// };

// /**
//  * Your TimeMap object will be instantiated and called as such:
//  * TimeMap* obj = new TimeMap();
//  * obj->set(key,value,timestamp);
//  * string param_2 = obj->get(key,timestamp);
//  */