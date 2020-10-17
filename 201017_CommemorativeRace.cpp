/// task : cho đồ thị DAG, tìm 1 cạnh (u -> v) sao cho tất cả đường đi dài nhất đều đi qua cạnh này và đường đi dài nhất đi qua u nhưng không đi qua (u -> v) là  nhỏ nhất
/// trước hết xác định tất cả các đường đi dài nhất là duy nhất ( bằng BFS ) thì tát cả đường đi dài nhất đều đi qua những cạnh này

/// gọi dp[u] sẽ là dường đi dài nhất bắt đầu từ u, và  dp2[u] sẽ là đường đi dài thứ nhì bắt đầu từ u
/// ta tạo 1 đỉnh ảo p = 0, nối p với mọi đỉnh i (i = 1.. n)
/// gọi dfs(0) để tạo dp[u] và dp2[u]

/// để xác định xét cạnh (u->v) có phải là cạnh duy nhất hay không : 
/// ta sẽ loang từ đỉnh u (u chắc chắn nằm trên đường đi dài nhất) ra đỉnh (v sao cho (u->v) thuộc đường đi dài nhất xuất phát từ u)
/// cạnh (u -> v) là duy nhất khi : 

/// xác định chi phí nhỏ nhất từ các cạnh duy nhất tìm được ở trên = đường đi dài nhất đến u + dp2[u]


#include <bits/stdc++.h>

int main(){

}
