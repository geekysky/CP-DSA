#include <bits/stdc++.h>
using namespace std;
#define int long long int

// Precompute Fibonacci numbers as per problem definition.
vector<int> computeFibonacci(int n) {
    vector<int> fib(n);
    fib[0] = 1;  // f1 = 1
    if(n >= 2)
        fib[1] = 2;  // f2 = 2
    for (int i = 2; i < n; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    return fib;
}

/*
 packLayer(layer, w, l)
  Input: layer is a vector of square side lengths (all cubes in one layer).
  Returns: true if these squares can be arranged (without overlapping)
    inside a rectangle of dimensions w×l.
  (This is a classical recursive square-packing problem:
   Use backtracking by always placing the square in the top-leftmost free cell.)
*/
bool packLayerRec(vector<vector<bool>> &grid, int w, int l, const vector<int>& squares, int idx) {
    if(idx >= squares.size()) return true;
    // Find first free cell (row, col)
    int r = -1, c = -1;
    for (int i = 0; i < l; i++){
        for (int j = 0; j < w; j++){
            if(!grid[i][j]){
                r = i; c = j;
                break;
            }
        }
        if(r != -1) break;
    }
    if(r == -1) return true; // grid full

    int side = squares[idx];
    // Try to place the square with top-left at (r,c)
    if(c + side <= w && r + side <= l) {
        bool canPlace = true;
        for (int i = r; i < r+side && canPlace; i++){
            for (int j = c; j < c+side; j++){
                if(grid[i][j]){
                    canPlace = false;
                    break;
                }
            }
        }
        if(canPlace) {
            // Mark cells
            for (int i = r; i < r+side; i++){
                for (int j = c; j < c+side; j++){
                    grid[i][j] = true;
                }
            }
            if(packLayerRec(grid, w, l, squares, idx+1))
                return true;
            // Unmark
            for (int i = r; i < r+side; i++){
                for (int j = c; j < c+side; j++){
                    grid[i][j] = false;
                }
            }
        }
    }
    // Alternatively, skip placement at (r,c) (but in most square packing problems we must fill from top-left)
    return false;
}

bool packLayer(const vector<int>& layerSquares, int box_w, int box_l){
    int r = box_l, c = box_w;
    vector<vector<bool>> grid(r, vector<bool>(c, false));
    // sort descending so larger squares are placed first (optional)
    vector<int> squares = layerSquares;
    sort(squares.rbegin(), squares.rend());
    return packLayerRec(grid, c, r, squares, 0);
}

/*
 DP over layers:
  Let f(mask, prev_min, rem_h) = true if we can partition the cubes represented by mask into layers,
  where:
     - In each layer, let H = max(square side) (layer height) and M = min(square side).
     - We require H <= prev_min (to satisfy stacking: layer above cannot have cubes larger than
       support from below). For the bottom layer, prev_min can be a very large number.
     - Sum of H over layers <= rem_h.
  We iterate over all nonempty subsets S of mask, check if S can form one valid layer (i.e. packLayer(S, box_w, box_l)
  returns true) and if the largest cube in S is <= prev_min.
*/
int dp[1<<10];
int nCubes;
 
// Use memoization with state (mask, prev_min, rem_h). Here we compress prev_min and rem_h into parameters
// For brevity, assume n is small and use recursion over bitmask.
map<tuple<int,int,int>, bool> memo;
 
bool solveLayers(int mask, int prev_min, int rem_h, const vector<int>& cubes, int w, int l) {
    if(mask == 0) return true;
    if(rem_h < 0) return false;
    auto state = make_tuple(mask, prev_min, rem_h);
    if(memo.find(state)!=memo.end()) return memo[state];
    
    // Enumerate all nonempty subsets S of mask.
    // (Since n<=10, we can iterate over submasks.)
    for (int sub = mask; sub; sub = (sub-1)&mask) {
        vector<int> layer;
        int layer_max = 0;
        int layer_min = INT_MAX;
        // Build layer from submask
        for (int i = 0; i < nCubes; i++){
            if(sub & (1<<i)) {
                layer.push_back(cubes[i]);
                layer_max = max(layer_max, cubes[i]);
                layer_min = min(layer_min, cubes[i]);
            }
        }
        if(layer_max > prev_min) continue; // violates stacking rule
        // Try to pack this layer in the box base.
        if(!packLayer(layer, w, l)) continue;
        // Layer height is layer_max.
        if(rem_h < layer_max) continue;
        // New support for above layers is min(prev_min, layer_min)
        int new_prev = min(prev_min, layer_min);
        // Recurse on remaining cubes.
        if(solveLayers(mask ^ sub, new_prev, rem_h - layer_max, cubes, w, l))
            return memo[state] = true;
    }
    return memo[state] = false;
}
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;  // n: number of cubes, m: number of boxes
        vector<vector<int>> boxes(m, vector<int>(3)); // each box: w, l, h
        for (int i = 0; i < m; i++){
            cin >> boxes[i][0] >> boxes[i][1] >> boxes[i][2];
        }
        // Compute Fibonacci cubes (sides)
        vector<int> fib = computeFibonacci(n);
        // According to stacking rule, sort cubes in descending order.
        vector<int> cubes = fib;
        sort(cubes.rbegin(), cubes.rend());
        nCubes = n; // global for DP
        
        string output = "";
        // Process each box using recursion/DP
        for (int i = 0; i < m; i++){
            int box_w = boxes[i][0], box_l = boxes[i][1], box_h = boxes[i][2];
            // For each box, try whether we can partition cubes into layers,
            // with no layer exceeding box base (w x l) and total height <= box_h.
            memo.clear();
            bool fits = solveLayers((1<<nCubes)-1, INT_MAX, box_h, cubes, box_w, box_l);
            output.push_back(fits ? '1' : '0');
        }
        cout << output << "\n";
    }
    return 0;
}