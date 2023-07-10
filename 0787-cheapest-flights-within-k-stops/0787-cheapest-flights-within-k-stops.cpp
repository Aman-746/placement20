class Solution {
public:
    
    // distance ke according priority queue me dalne pr ye problem hogi ki agar kisi
    // node pr lower price me pahuch ja raha hai with k stops aur abhi bhi hum
    // destination pr nhi pahuche to hume us path ko reject krna padega aur aisa path
    // select krna padega jo ki with in k stops destination tak pahuch jaye chahe us  
    // path se jyada price hi kyu na lage, lekin if we sort according to distance then
    // longer price wale path ko hum pq me add hi nhi kr payenge to answer sahi nhi
    // aayega
    // this example can teach you better 
    // from node, to node, price
    // 0->{1,5}, 0->{3,2}, 1->{2,5}, 1->{4,1}, 3->{1,2},4->{2,1}
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {       
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        
        vector<int>price(n,INT_MAX);
        price[src]=0;
        
        // making a priority queue with 3 parameters (stop,node,price)
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        // adding info about source node
        pq.push({0,{src,0}});
        
        while(!pq.empty()){
            auto itz=pq.top();
            pq.pop();
            // source to that node
            int stop=itz.first;
            int node=itz.second.first;
            int money=itz.second.second;
            for(auto it:adj[node]){
                int adjNode=it.first;
                // cost is node to adjNode
                int cost=it.second;
                if(stop<=k && price[adjNode]>money+cost){
                    price[adjNode]=money+cost;
                    pq.push({stop+1,{adjNode,price[adjNode]}});
                }
            }
        }
        if(price[dst]==INT_MAX) return -1;
        return price[dst];
    }
};