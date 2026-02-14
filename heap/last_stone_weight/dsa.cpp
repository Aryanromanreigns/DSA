class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();


        priority_queue<int>pq;

        for(int i = 0;i<n;i++){
            pq.push(stones[i]);
        }

        while(pq.size() > 1){
            int top = pq.top();
            pq.pop();
            int nexttop = pq.top();
            pq.pop();

            if(top != nexttop){
                int newone = abs(top - nexttop);
                pq.push(newone); 

            }
            
        }
        if(pq.empty()){
            return 0;
        }
        else{
            return pq.top();
        }

        
    }
};