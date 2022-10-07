// class MyCalendarThree {
//     vector<pair<int, int>> events;
    
    
// public:
//     MyCalendarThree() { }
    
//     int book(int start,int end) {
//         //find start
        
//         //find end
//         events[start]++;
//         events[end]--;
        
//         int booked = 0, book_max = 0;
//         for(auto it = events.begin(); it != events.end(); it++) {
//             booked += it->second;
//             if(booked>book_max) book_max = booked; 
//         }
//         return book_max;
//     }
// };

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */

class MyCalendarThree {
    map<int, int> events;
    
    
public:
    MyCalendarThree() { }
    
    int book(int start,int end) {
        events[start]++;
        events[end]--;
        
        int booked = 0, book_max = 0;
        for(auto it = events.begin(); it != events.end(); it++) {
            booked += it->second;
            if(booked>book_max) book_max = booked; 
        }
        return book_max;
    }
};