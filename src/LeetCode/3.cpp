class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      map <char, int> mp;
	int current_start = 0;
	int max_size = 0;
	int i;
	for (i = 0; i < s.length(); i++) {
		if (mp.find(s[i]) == mp.end()) {
			mp.insert(make_pair(s[i], i));

		}
		else {
			if (mp[s[i]] + 1 > current_start)
			{
				current_start = mp[s[i]] + 1;
			}
			mp[s[i]] = i;
		}
		max_size = max_size > (i + 1 - current_start) ? max_size : (i + 1 - current_start);
	}
	return max_size;
  
    }
};