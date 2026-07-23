class Solution {
public:
    void mergeSort(vector<int> &arr, int st, int end){
        if(st>=end) return;
        int mid=(st+end)/2;
        mergeSort(arr, st, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, st, end);
    }
    void merge(vector<int> &arr, int st, int end){
        int mid=(st+end)/2;
        vector<int> left(arr.begin()+st, arr.begin()+mid+1);
        vector<int> right(arr.begin()+mid+1, arr.begin()+end+1);
        int i=0;
        int j=0;
        int ind=st;
        while(i<left.size() && j<right.size()){
            if(left[i]<right[j]){
                arr[ind++]=left[i++];
            }
            else{
                arr[ind++]=right[j++];
            }
        }
        while(i<left.size()){
            arr[ind++]=left[i++];
        }
        while(j<right.size()) arr[ind++]=right[j++];
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};