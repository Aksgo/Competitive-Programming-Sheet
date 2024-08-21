class Solution {
public:
   void dfs(int initial, int newColor, int i, int j, vector<vector<int>> &image){
	if(i<0 || j<0 || i>=image.size() || j>=image[0].size())return;
	if(image[i][j]!=initial)return;
	image[i][j]=newColor;
	dfs(initial, newColor,i-1,j,image);
	dfs(initial, newColor,i+1,j,image);
	dfs(initial, newColor,i,j-1, image);
	dfs(initial, newColor,i,j+1, image);
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
	int initialColor = image[sr][sc];
    if(initialColor!=color)
        dfs(initialColor, color, sr, sc, image);
	return image;
}
};
