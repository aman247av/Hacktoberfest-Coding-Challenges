#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>&prices){

int buy=prices[0];
int profit=0;

for(int i=1;i<prices.size();i++){
    if(prices[i]<buy){//stock prices get decreases so need to buy it
        buy=prices[i];
    }
    else{
        //optherwise we sell it  and calculates the new profit
        // and add it in your final result profit
        // and we buy current stock again  
        profit+=prices[i]-buy;//profit
        buy=prices[i];//buy it
    }
}
return profit;
}
};