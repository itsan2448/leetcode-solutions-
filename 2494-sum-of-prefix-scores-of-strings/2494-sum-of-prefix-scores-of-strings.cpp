class Node{    
    int score;
    Node* children[26];
    bool end_of_word;
    public:
    bool hasKey(char c){
        return (children[c-'a']!=NULL);
    }
    void putKey(char c,Node *i){
        children[c-'a']=i;
    }
    Node *getNode(char c){
        return children[c-'a'];
    }
    void setend(){
        end_of_word=true;
    }
    bool isEnd(){
        return end_of_word;
    }
    void increment(){
        score++;
    }
    int getCount(){
        return score;
    }
};
class Trie{
    Node *root;
    public:
    Trie(){
        // int score=0;
        root=new Node();
    }
    void insert(string val){
        Node *i=root;
        for(auto j:val){
            if(!i->hasKey(j)){
                i->putKey(j,new Node());
            }
            i=i->getNode(j);
            i->increment();
        }
        i->setend();
    }    
    int PrefixScores(string val){
        Node *i=root;
        int p=0;
        for(auto j:val){
            if(!i->hasKey(j)){                
                return p;
            }

            i=i->getNode(j);  
            p+= i->getCount();          
        }
        return p;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& w) {
        Trie t;
        for(auto i:w){
            t.insert(i);
        }
        vector<int> sum;
        for(auto i:w){
            int tmp=t.PrefixScores(i);
            sum.push_back(tmp);
        }
        return sum;
    }
};