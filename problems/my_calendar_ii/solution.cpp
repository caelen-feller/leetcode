class MyCalendarTwo {
    map<int, int> events;
    
public:
    MyCalendarTwo() { }
    
    bool book(int start,int end) {
        events[start]++;
        events[end]--;
        
        int booked = 0;
        for(auto it = events.begin(); it != events.end(); it++) {
            booked += it->second;
            if(booked==3) {
                events[start]--;
                events[end]++; 
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */