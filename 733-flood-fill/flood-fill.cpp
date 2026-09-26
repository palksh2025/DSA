class Solution {
public:
    void dfs (vector<vector<int>>& image, int sr, int sc, long long color, long long orgCol){
        int m = image.size();
        int n = image[0].size();

        image[sr][sc] = color;

        if(sc > 0){
            if(image[sr][sc-1] == orgCol){
                dfs(image, sr, sc-1, color, orgCol);
            }
        }

        if(sc < n-1){
            if(image[sr][sc+1] == orgCol){
                dfs(image, sr, sc+1, color, orgCol);
            }
        }

        if(sr < m-1){
            if(image[sr+1][sc] == orgCol){
                dfs(image, sr+1, sc, color, orgCol);
            }
        }

        if(sr > 0){
            if(image[sr-1][sc] == orgCol){
                dfs(image, sr-1, sc, color, orgCol);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color)
        return image;

        dfs(image, sr, sc, color, image[sr][sc]);

        return image;
    }
};