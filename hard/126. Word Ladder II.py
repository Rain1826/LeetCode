"""
Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:

Return an empty list if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: []

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
"""

"""
思路：
1. 建立一个index，作用就是把去掉某一个位置的字母后，剩余部分相同的放入一个桶中。
2. BFS一遍，确定为一个单词在图中的第几层
3. DFS一遍，找到每一个可行的路线。此时BFS的作用就是从第n层只能往n+1层走，以保证最短路径
"""

import queue

class Solution:
    def buildIndex(self, length, wordList):
        indexes = []
        for i in range(length):
            index = {}
            for word in wordList:
                entry = word[:i] + word[i + 1:]
                words = index.get(entry, [])
                words.append(word)
                index[entry] = words
            indexes.append(index)
        return indexes
     
    def getNextWord(self, word):
        res = []
        for i in range(len(word)):
            entry = word[:i] + word[i + 1:]
            if entry in self.indexes[i]:
                for nextWord in self.indexes[i][entry]:
                    if nextWord != word:
                        res.append(nextWord)
        return res
        
    def BFS(self, start, end):
        self.distance = {}
        self.distance[start] = 0
        q = queue.Queue()
        q.put(start)
        while not q.empty():
            head = q.get()
            for nextWord in self.getNextWord(head):
                if nextWord not in self.distance:
                    self.distance[nextWord] = self.distance[head] + 1
                    q.put(nextWord)
    
    def DFS(self, current, target, path):
        if current == target:
            self.result.append(path[:])
            return
        
        for word in self.getNextWord(current):
            if self.distance[word] - 1 == self.distance[current]:
                self.DFS(word, target, path + [word])

    def findLadders(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: List[List[str]]
        """
        if endWord not in wordList:
            return []
        
        self.indexes = self.buildIndex(len(beginWord), wordList)
        self.BFS(beginWord, endWord)
        
        self.result = []
        if beginWord in self.distance:
            self.DFS(beginWord, endWord, [beginWord])
            
        return self.result
        
