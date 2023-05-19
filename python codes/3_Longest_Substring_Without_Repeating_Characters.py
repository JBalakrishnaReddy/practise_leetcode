class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        # max subsubstring length will not be more than 26
        maxString = ""
        subString = ""
        for data in s:
            # if data not in subString:
            dataElementFoundAt = subString.find(data)
            if dataElementFoundAt < 0:    # This implies letter not found in the subString
                subString += data
                if len(subString) > len(maxString):
                    maxString = subString
            else:
                subString = data if(dataElementFoundAt == len(subString)-1) else subString[dataElementFoundAt+1:] + data
        return len(maxString)

sol = Solution()
# print(sol.lengthOfLongestSubstring("abcabcbb"))
print(sol.lengthOfLongestSubstring("anviaj"))