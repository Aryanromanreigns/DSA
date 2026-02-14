class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;

        int n = piles.size();

        for (int i = 0; i < n; i++) {
            pq.push(piles[i]);
        }
        int sum = 0;

        while (k--) {
            int temp = pq.top();
            pq.pop();

            temp = temp - (temp) / 2;
            pq.push(temp);
        }

        while (!pq.empty()) {
            int top = pq.top();
            sum += top;
            pq.pop();
        }

        return sum;
    }
};