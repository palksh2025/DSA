class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        if (n == 1){
            return 1;
        }

        int mini = 0;
        int maxi = 0;

        for(int i = 1; i < n; i++){
            if(nums[i] > nums[maxi]){
                maxi = i;
            }
            if(nums[i] < nums[mini]){
                mini = i;
            }
        }

        cout<<"Mini: "<<mini<<endl;
        cout<<"Maxi: "<<maxi<<endl;

        int minidist = min(mini+1, n - mini);
        int maxidist = min(maxi+1, n - maxi);

          cout<<"Minidist: "<<minidist<<endl;
        cout<<"Maxidist: "<<maxidist<<endl;

       int total = 0;

       if(minidist < maxidist){
            total = total + minidist;
            cout<<total;
            total = total + min(maxidist, abs(mini - maxi));
       }
       else{
            total = total + maxidist;
            cout<<total;
            total = total + min(minidist, abs(mini - maxi));
       }

       return total;
    }
};