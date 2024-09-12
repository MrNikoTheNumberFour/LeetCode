class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//       vector<int>dist(n, numeric_limits<int>::max());
//             dist[src]=0;

//             for(int i=0; i <= k; i++){

//                 vector<int>temp(dist);

//                 for(auto flight: flights){

//                      if(dist[flight[0]] != numeric_limits<int>::max()){
//                           temp[flight[1]] = min(temp[flight[1]], dist[flight[0]] + flight[2]);
//                      }
//                 }

//                 dist = temp;
//             }

//             return dist[dst] == numeric_limits<int>::max() ? -1 : dist[dst];  
//     }
        vector<int> prices(n, numeric_limits<int>::max());
        prices[src] = 0;

        for (int i = 0; i <= k; ++i) {
            vector<int> tmpPrices = prices;
            for (auto& flight : flights) {
                int s = flight[0], d = flight[1], p = flight[2];
                if (prices[s] == numeric_limits<int>::max()) {
                    continue;
                }
                if (prices[s] + p < tmpPrices[d]) {
                    tmpPrices[d] = prices[s] + p;
                }
            }
            prices = tmpPrices;
        }
        return prices[dst] == numeric_limits<int>::max() ? -1 : prices[dst];
    }
};