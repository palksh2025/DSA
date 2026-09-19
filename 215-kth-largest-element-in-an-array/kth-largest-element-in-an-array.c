int findKthLargest(int* nums, int numsSize, int k) {
    int freq[20005] = {0};

    for(int i = 0; i < numsSize; i++){
        freq[nums[i] + (10002)]++;
    }

    int count = 0;
    for(int i = 20004; i >= 0; i--){
        if(freq[i] == 0){
            continue;
        }

        count = count + freq[i];
        if(count >= k){
            return i - 10002;
        }
    }

    return -1;
}