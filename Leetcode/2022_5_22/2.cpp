class Solution {
public:
    int maximumBags(vector<int>& cap, vector<int>& rocks, int more) {
        int n=cap.size();
        vector<int> cnt ;

        for(int i=0;i<n;i++){
            cnt.push_back( cap[i] - rocks[i] );
        } 

        sort( cnt.begin() , cnt.end() );

        int idx=0 ;

        for( ; idx< n ;idx++){
            if( cnt[idx]<=more ){
                more-=cnt[idx];
            }
            else break;
        }

        return idx;
    }
};

/*

[54,18,91,49,51,45,58,54,47,91,90,20,85,20,90,49,10,84,59,29,40,9,100,1,64,71,30,46,91]
[14,13,16,44,8,20,51,15,46,76,51,20,77,13,14,35,6,34,34,13,3,8,1,1,61,5,2,15,18]
77

out : 9
exp : 13 


*/