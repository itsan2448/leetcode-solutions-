class Solution {

public:

    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> words;
        stringstream ss(sentence);
        string word;
        while(ss>>word){
            words.push_back(word);
        }
        for (int i = 0; i < words.size(); ++i) {
            if (words[i].size() >= searchWord.size() && words[i].substr(0, searchWord.size())== searchWord) {
                return i + 1; 
            }
        }
        return -1;
    }
};