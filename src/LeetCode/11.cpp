class Solution {
public:
    int maxArea(vector<int>& height) {
       int left = 0;
	int right = height.size()-1;
	int weight = height.size() - 1;
	int maxAr = 0;
	int currentAr = 0;
	while (right-left>0)
	{
		currentAr = (right - left) * min(height[left], height[right]);
		maxAr = currentAr > maxAr?currentAr : maxAr;
		if (height[left]< height[right])
		{
			left++;
		}
		else {
			right--;
		}
	}
	return maxAr;
 
    }
};