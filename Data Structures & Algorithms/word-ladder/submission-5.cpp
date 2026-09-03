class Solution {
private:
    bool compare(string s1,string s2)
    {
        int count=0;
        for(int i=0;i<s1.length();i++)
        {
            if(s1[i]!=s2[i])
            count++;
        }

        if(count==1)
        return true;
        else return false;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        if(beginWord==endWord)
        return 0;

        int count=1;
        queue <string> q1;
        unordered_map<string,bool> visited;

        q1.push(beginWord);
        int n=q1.size();

        while(!q1.empty())
        {
            if(!n)
            {
                count++;
                n=q1.size();
            }
            n--;

            string temp=q1.front();
            visited[temp]=true;
            q1.pop();

            for(int i=0;i<wordList.size();i++)
            {
                if(visited[wordList[i]])
                continue;

                else if(compare(temp,wordList[i]))
                {
                    if(wordList[i]==endWord)
                    return count+1;
                    visited[wordList[i]]=true;
                    q1.push(wordList[i]);
                }
            }
        }
        return 0;
    }
};
