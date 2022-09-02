class LockingTree {
public:
    vector<int>parent;
    vector<int>adj[2001];
    int len;
    map<int , int> lockedby;
    LockingTree(vector<int>& parent) {
        this->parent = parent;
        
        for(int i=1; i<parent.size(); i++){
            adj[parent[i]].push_back(i);
        }
        len = parent.size();
    }
    
    bool lock(int num, int user) {
        if(lockedby.find(num) == lockedby.end()){
            //lock this node
            lockedby[num] = user;
            return true;
        }
        return false;
    }
    
    bool unlock(int num, int user) {
        if(lockedby.find(num) == lockedby.end()){
            return false;
        }
        if(lockedby[num] == user){
            //unlock
            lockedby.erase(num);
            return true;
        }
        return false;
    }
    
    bool upgrade(int num, int user) {
        // if lock then false
        if(lockedby.find(num) != lockedby.end())
            return false;
        
        //ancestors locked then false
        int k = num;
        while(k != -1){
            k = parent[k];
            if(lockedby.find(k) != lockedby.end())
                return false;
        }
        
        //check atleast any one descent 
        if(check_atleast_one_descendant_lock(num)){
            //unlock all descendant node
            unlock_all_node(num);
            lockedby[num] = user;
            return true;
        }
        
        return false;
        
        
    }
    
    bool check_atleast_one_descendant_lock(int num){
        for(auto node : adj[num]){
            if(lockedby.find(node) != lockedby.end()){
                return true;
            }
            if(check_atleast_one_descendant_lock(node))
                return true;
        }
        return false;
    }
    
    void unlock_all_node(int num){
        for(auto node : adj[num]){
            if(lockedby.find(node) != lockedby.end()){
                lockedby.erase(node);
            }
            unlock_all_node(node);
        }
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */