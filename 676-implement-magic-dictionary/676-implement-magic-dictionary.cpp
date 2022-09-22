class MagicDictionary {
public:
    
    vector<string>Dict;
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        Dict = dictionary;
    }
    
    bool check(string a , string b){
        if(a.size() != b.size()) return false;
        int ct = 0;
        for(int i=0; i<a.size(); i++){
            if(a[i] != b[i]) ct++;
        }
        
        if(ct == 1) return true;
        return false;
    }
    bool search(string searchWord) {
        for(auto i : Dict){
            if(check(i , searchWord) == true) return true;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */