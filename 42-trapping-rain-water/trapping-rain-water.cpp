class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
    
        int left = 0;
        int right = n-1;

        int maxLeft = 0;
        int maxRight = 0;

        int vol = 0;

        while(left < right){
            if(height[left] < height[right]){
                if(height[left] >= maxLeft){
                    maxLeft = height[left];
                }
                else{
                    vol += maxLeft - height[left];
                }

                left++;
            }
            else{
                if(height[right] >= maxRight){
                    maxRight = height[right];
                }
                else{
                    vol += maxRight - height[right];
                }

                right--;
            }
        }

        return vol;
    }
};