class Node{
public:
    int key,val;
    Node *prev,*next;
    
    Node(int k, int v){
        key=k;
        val=v;  
        prev=NULL;      
        next=NULL;      
    }
};
class LRUCache {
public:
    int cap;
    map<int,Node*> cache;
    Node *left,*right;

    LRUCache(int c) {
        cap=c;        
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next=right;
        right->prev=left;
    }
    void remove(Node *n){
        Node *prv = n->prev;
        Node *nxt = n->next;
        prv->next=nxt;
        nxt->prev=prv;
    }
    void insert(Node *n){
        Node *prv=right->prev;
        Node *nxt=right;
        prv->next=n;
        nxt->prev=n;
        n->next=nxt;
        n->prev=prv;
    }

    int get(int key) {
        if(cache.find(key)!=cache.end()){
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end())
            remove(cache[key]);
        cache[key]=new Node(key,value);
        insert(cache[key]);
        
        if(cache.size()>cap){
            Node *lru=left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */