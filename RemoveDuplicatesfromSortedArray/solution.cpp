class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n==0) return 0;
        int i = 0, j = 1;
        while(j<n){
            if(A[i]==A[j]){
                j++;
            }else{
                A[i+1] = A[j];
                i++;
                j++;
            }
        }
        return i+1;
    }
};