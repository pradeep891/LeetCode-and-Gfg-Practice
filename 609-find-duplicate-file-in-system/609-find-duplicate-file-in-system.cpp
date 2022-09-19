class Solution {
public:
    pair<string , string>find_content(string s){
        string file = "";
        int i = 0;
        for(i=0 ; i<s.size(); i++){
            if(s[i] == '('){
                break;
            }
            file.push_back(s[i]);
        }
        
        string cont = s.substr(i+1);
        cont.pop_back();
        
        // cout << cont << ", " << file << " | ";
        return {cont , file};
    }
    
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        map<string , vector<string> >mp;
        
        for(auto str : paths){
            // string pat
            vector<string>v;
            string k = "";
            for(auto ch : str){
                if(ch == ' '){
                    v.push_back(k);
                    k = "";
                }
                else
                    k.push_back(ch);
            }
            v.push_back(k);
            
            // for(auto j : v)
            //     cout << j << "      ";
            // cout << endl;
            
            for(int i=1; i<v.size(); i++){
                pair<string , string> content_file = find_content(v[i]);
                string path = v[0];
                path.push_back('/');
                path += content_file.second;
                mp[content_file.first].push_back(path);
                // cout << "{ " << content_file.first << ", " << path << "} , ";
            }
            // cout << endl;
        }
        
        vector< vector<string> > ans;
        for(auto i : mp){
            if(i.second.size() > 1)
            ans.push_back(i.second);
        }
        return ans;
        
    }
};