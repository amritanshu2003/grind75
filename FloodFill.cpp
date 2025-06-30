# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```cpp []
class Solution {
public:

/*
DFS
explores as far as possible along each branch before backtracking.
Recursively visits all 4-connected neighbours{up,down,right,left}
Steps:
1- Start at the given pixel (i,j) & check its color
2- if the pixels color matches the original color change it to the new color
3- recursively apply the same process to its neighbors {up,down,right,left}
4- also check if the neighbors are not going outside the 2D matrix
*/
vector<vector<int>> floodFill_dfs(vector<vector<int>>& image, int sr, int sc, int origColor, int color) {
    if(
        image.empty() || sr<0 || sr>= image.size() || 
        sc<0 || sc>=image[0].size() ||
        image[sr][sc] != origColor || 
        image[sr][sc] == color) {
        //pixel has the same color as original color or new color
        // so no need to do anything
        return image;
    }
    
    //change the color 
    image[sr][sc] = color;
    //recursively call for all 4 directions
    floodFill_dfs(image, sr+1, sc, origColor, color);
    floodFill_dfs(image, sr-1, sc, origColor, color);
    floodFill_dfs(image, sr, sc+1, origColor, color);
    floodFill_dfs(image, sr, sc-1, origColor, color);
    return image;
}

/*
BFS- uses queue to explore all the neighbours level by level 
Iteratively visits all 4-connected neighbours of a pixel.
Each pixel is added to the queue once and processed once.
performs queue operations once for each pixel
Time complexity   O(m*n) 
Space complexity  O(m*n) due to queue- stores a pixel to be processed in the queue.
In the worst case queue can hold all m*n pixels.

1- start at the given index (i,j)
2- push the starting pixel into the queue
3- while the q is not empty:
    - pop the pixel from the q
    - change its color to the new color
    - push its valid neighbours {up,down,right,left} into the queue
    vector<pair<int,int>> dirs={
        {1, 0}, // down
        {-1, 0}, // up
        {0, 1}, // right
        {0, -1} // left
    };

*/
vector<vector<int>> floodFill_bfs(vector<vector<int>>& image, int sr, int sc, int origColor, int color) {
    if(
        image.empty() || sr<0 || sr>= image.size() || 
        sc<0 || sc>=image[0].size()
       ) {
        return image;
    }
    vector<pair<int,int>> dirs={
        {1, 0}, // down
        {-1, 0}, // up
        {0, 1}, // right
        {0, -1} // left
    };
    //change the color 
    image[sr][sc] = color;
    std::queue<pair<int, int>> q;
    q.push({sr, sc});

    while (!q.empty()) {
        pair<int, int>p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        
        // Process the current pixel and check its neighbors
        // pixel has the same color as new color
        // so no need to do anything
        if( image[x][y] != color ){
            image[x][y] = color;
        }
        
        // Check bounds before pushing to queue
        for (const auto& dir : dirs) {
            int newX = x + dir.first;
            int newY = y + dir.second;
            if (newX >= 0 && newX < image.size() && newY >= 0 && newY < image[0].size()) {
                // Only push to queue if the pixel is of original color
                if (image[newX][newY] == origColor) {
                    q.push({newX, newY});
                }
            }
        }      
    }    
    return image;
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image.empty()){
            return image;
        }
        int origColor = image[sr][sc]; //start index color
        vector<vector<int>> result = floodFill_dfs(image, sr, sc, origColor, color);
        //vector<vector<int>> result = floodFill_bfs(image, sr, sc, origColor, color);
        return result;     
        
    }
};
```
