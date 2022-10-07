// Simple first implementation
// Represent as a set


// class MyCalendar {
// set<pair<unsigned int, unsigned int>> data;    
// public:
//     MyCalendar() { }
    
//     bool book(int start, int end) {
//         pair<unsigned int,unsigned int> input = {start, end};        
//         auto res = data.upper_bound(input);
//         if(res != data.end() and end > res->first) return false;
//         if(res != data.begin() and (--res)->second > start) return false;
//         data.insert(input); 
//         return true;
//     }
// };

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

// struct date_comp {
//   bool operator() (const pair<unsigned int, unsigned int>& lhs, const pair<unsigned int, unsigned int>& rhs) const
//   {return lhs.second<=rhs.first;}
// };


// Reverse with a map 
class MyCalendar {
map<unsigned int, unsigned int> data;    
public:
    MyCalendar() { }
    
    bool book(int start, int end) {
        auto res = data.upper_bound(start);
        if(res != data.end() and end > res->second) return false;
        data.insert({end, start}); 
        return true;
    }
};