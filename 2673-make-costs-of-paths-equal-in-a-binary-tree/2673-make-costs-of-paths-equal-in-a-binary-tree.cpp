class Solution {
public:
    int dfs(int node, int n, vector<int>& cost, int &ans)
    {
        if(node > n) return 0;
        
        int left = dfs(2*node, n, cost, ans);
        int right = dfs(2*node+1, n, cost, ans);
        
        ans += abs(left - right);
        
        return cost[node-1] + max(left, right);
        //1 based indexing given so node-1
    }
    
    int minIncrements(int n, vector<int>& cost) {
        int ans = 0;
        dfs(1, n, cost, ans);
        return ans;
    }
};

/*
Always think of Tree Questions in Subtree Manner once.
Here we have to make all paths from root to leaves equal. So, We can generalize it for every subtree node i.e. The path from each node to leaves should be equal.

Lets say we are at Node X,
the cost of left path is A
and of the right path is B, where A>B.
Now, path length from X to leaves = A (as we can only add 1, so we will make B equal to A and in this way all paths from node to leaf will be equal)

The parent of X needs the max cost of path containing X. So, X will return

cost[X] + (the path length from X to leaves which are all equal)

= cost[X] + A
= cost[X]+ max(A,B)
*/