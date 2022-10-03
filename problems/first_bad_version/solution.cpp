// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int pivot = n/2;
        int i,j;
        i = 0; j = n;
        
        while (j-i > 1)
        {
            cout << i << " " << j << " " << pivot << endl;
            bool bad_pivot = isBadVersion(pivot);
            
            if(bad_pivot) j = pivot;
            else i = pivot; 
            
            pivot = (j-i)/2 + i;
        }
        return j;
    }
};