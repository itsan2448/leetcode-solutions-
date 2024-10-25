class Node{
    public:
    Node* children[26];
    bool isend=false;
    Node(){  // Constructor to initialize array
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isend = false;
    }
};
class WordDictionary {
public:
Node* root;
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
        Node *i=root;
        for(auto w:word){
            if(i->children[w-'a']==nullptr)
                i->children[w-'a']=new Node();            
            i=i->children[w-'a'];
        }
        i->isend=true;
    }
    
    bool searchhelp(string &word, Node* root, int ind){
        if(ind==word.size()) return root->isend;
        char c=word[ind];
        if(c=='.'){
            for(int i=0;i<26;i++){
                if(root->children[i] && searchhelp(word,root->children[i],ind+1)){
                    return true;
                }                
            }
            return false;
        }else{
            if(root->children[c-'a']){
                return searchhelp(word,root->children[c-'a'],ind+1);
            }else{
                return false;
            }
        }
        return root->isend;
    }
    bool search(string word) {
        return searchhelp(word,root,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */