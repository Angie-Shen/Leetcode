class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n==0) return 0;

        int i = 0;
        int times = 0;
        for(int j = 0; j < n; j++){
            if(A[i] == A[j]){
                times++;
                if(times == 2){
                    A[++i] = A[j];
                }
            }else{
                A[++i] = A[j];
                times = 1;
            }
        }
        return i+1;
    }
};