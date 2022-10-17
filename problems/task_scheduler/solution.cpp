class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(!n) return tasks.size();
        unordered_map<char,int>mp;
        int count = 0;
        
        for(auto e : tasks)
            if(++mp[e] > count) count = mp[e];
        
        int ans = (count-1)*(n+1);
        for(auto e : mp) if(e.second == count) ans++;
        
        return max((int)tasks.size(), ans);
    }
};


// Count_sort method
// class Solution {
// public:
//     int leastInterval(vector<char>& tasks, int n) {
//         int n_tasks = tasks.size();
//         if(n == 0) return n_tasks;
        
//         int count[26] = {0};
//         int count_sort[26];
//         int i,j;
//         for(i = 0; i < 26; i++) {count_sort[i] = i;}
        
//         int time = 0, temp;
        
//         // Find freq of task_i, i = 0, n_tasks 
//         for(i = 0; i<n_tasks; i++) {
//             temp = tasks[i] - 'A';
//             count[temp]++;
            
//             // Sort from largest to smallest freq        
//             for(j = 0; j < count_sort[temp]; j++) {
//                 if(count[count_sort[j]] < count[temp]) {
//                     swap(count_sort[j], count_sort[temp]);
//                     break;
//                 }
//             }
//         }
        
// // decrement f_0 through f_n (if f_j = 0, j < n then use idles)
// // Time will be sum of frequencies and any idles used.
//         while(count[count_sort[0]] > 0) {            
//             for(i = 0; i < n + 1 and i < 26; i++) {
//                 if(count[count_sort[i]] > 0) { 
//                     count[count_sort[i]]--; 
//                     time++;
//                     // cout << (char)(count_sort[i] + 'A')  << ":" << count[count_sort[i]]<< endl;
//                 }
//                 else if(count[count_sort[0]] > 0) {
//                     // cout << "idle" << endl;
//                     time++;
//                 }
//             }
//             // Resort
//             sort(count_sort, count_sort+26, [count](int a, int b) {
//                 return count[a] > count[b];
//             });
            
//             if(count[count_sort[0]] > 0) {
//                 // cout << n+1 - i << " extra idles" << endl;
//                 time += n+1 - i;
//             }
//         }
        
//         return time;
//     }
// };

// GIven A A B B C C
// A B C A B C
// AAABBB, n = 1 -> ABABAB_B
// n= 2 -> AB_AB_AB
// For each group of Task_i..Task_j (uniquely), if j-i >= n then can repeat block
// otherwise need to add idles. 
// A *6 BCDEF, n =2 
// ABC ADE AFG A__ A__ A__

/* ALGO
 - Find freq of task_i, i = 0, n_tasks 
 - Sort from largest to smallest freq
 - decrement f_0 through f_n (if f_j = 0, j < n then use idles)
 - Time will be sum of frequencies and any idles used.
 
*/