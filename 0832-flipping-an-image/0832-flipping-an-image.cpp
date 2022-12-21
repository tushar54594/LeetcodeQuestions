class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        
        for(int i=0; i<image.size(); i++)
        {
            int s = 0;
            int e = image[0].size()-1;
            while(s < e)
            {
                swap(image[i][s], image[i][e]);
                s++;
                e--;
            }
        }
        
        for(int i=0; i<image.size(); i++)
        {
            for(int j=0; j<image[0].size(); j++)
            {
                if(image[i][j] == 1)
                    image[i][j] = 0;
                else
                    image[i][j] = 1;
            }
        }
        
        return image;
    }
};