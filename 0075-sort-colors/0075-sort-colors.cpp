class Solution {
public:
    //  void sortColors(vector<int>& v) {
    //     int l =0, h = v.size()-1, pivot = 0;
    //     while(pivot<=high){
    //         if(v[pivot]==0){
    //             swap(v[low],v[pivot]);
    //             low++;
    //             pivot++;
    //         }
    //         else if (v[pivot]==1){
    //             pivot++;
    //         }
    //         else{
    //             swap(v[pivot],v[high]);
    //             high--;
    //         }
    //     }
    // }
    
    
    void sortColors(vector<int>& v) {
        int l =0 , h = v.size()-1, p= 0;
        while(p<=h){
            if(v[p]==0){
                swap(v[p],v[l]);
                l++;
                p++;
            }
             else if(v[p]==2){
                swap(v[h],v[p]);
                h--;
                // p++;
            }
            else if(v[p]==1)p++;
        }
    }
    
    // void sortColors(vector<int>& v) {
    //     int l =0 , h = v.size()-1, p= 0;
    //     while(p<=h){
    //         if(v[p]==0){
    //             swap(v[p],v[l]);
    //             l++;
    //             p++;
    //         }
    //          else if(v[p]==2){
    //             swap(v[h],v[p]);
    //             h--;
    //             // p++;
    //         }
    //         else if(v[p]==1)p++;
    //     }
    // }
};