// binary search - good question
// https://www.interviewbit.com/problems/painters-partition-problem/#

int Solution::paint(int A, int B, vector<int> &C) {
    long long int lo = *max_element(C.begin(),C.end());
    if(A >=C.size())
        return (lo*B)%10000003;
    long long int hi = 0;
    for(int i=0;i<C.size();i++){
        hi += C[i];
    }
    long long int ans = -1;
    while(lo<=hi){
        long long int mid = lo + (hi-lo)/2;
        int rp = 1;
        long long int sum = 0;
        for(int i=0;i<C.size();i++){
            sum += C[i];
            if(sum>mid){
                sum = C[i];
                rp+=1;
            }
        }
        if(rp<=A){
            ans = mid;
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
        // cout<<mid<<" ";
    }
    return (ans*B)%10000003;
}