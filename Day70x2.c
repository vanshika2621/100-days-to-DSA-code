#include <stdio.h>
#include <stdlib.h>

#define INF 10000000

int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize, int src, int dst, int k) {
    // According to constraints, n is at most 100. 
    // We can use fixed-size arrays to avoid the overhead of malloc/free.
    int prices[100];
    int tmp_prices[100];
    
    // Initialize all distances to "infinity"
    for (int i = 0; i < n; i++) {
        prices[i] = INF;
    }
    
    // The cost to reach the source city is 0
    prices[src] = 0;
    
    // Iterate k + 1 times to allow for k stops
    for (int i = 0; i <= k; i++) {
        
        // Copy current prices into our temporary array
        for (int j = 0; j < n; j++) {
            tmp_prices[j] = prices[j];
        }
        
        // Relax all edges
        for (int j = 0; j < flightsSize; j++) {
            int u = flights[j][0]; // From city
            int v = flights[j][1]; // To city
            int w = flights[j][2]; // Price
            
            // If the starting city 'u' is reachable, check if this flight is cheaper
            if (prices[u] != INF && prices[u] + w < tmp_prices[v]) {
                tmp_prices[v] = prices[u] + w;
            }
        }
        
        // Apply the updated prices for the next iteration
        for (int j = 0; j < n; j++) {
            prices[j] = tmp_prices[j];
        }
    }
    
    // If the destination is still at INF, it's unreachable within k stops
    if (prices[dst] == INF) {
        return -1;
    }
    
    return prices[dst];
}