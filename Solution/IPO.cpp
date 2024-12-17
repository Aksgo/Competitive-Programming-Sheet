class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int,int>> pro;
        priority_queue<int> mx;
        for(int i =0; i<capital.size(); ++i){
            pro.push({-capital[i],profits[i]});
        }
        while(k--){
            while(!pro.empty() && -pro.top().first<=w){
                pair<int,int> p = pro.top();
                mx.push(p.second);
                pro.pop();
            }
            if(!mx.empty()){
                w+=mx.top();
                mx.pop();
            }
            else{break;}
        }
        return w;
    }
};
