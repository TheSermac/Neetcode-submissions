class WordDictionary {
private:
    bool introduced_word;
    map<char,WordDictionary> next;

public:
    WordDictionary() {
        introduced_word = false;       
    }
    
    void addWord(const string& word, int index = 0) {
        if(index < word.length()){
            next[word[index]].addWord(word, index+1);
        }
        else{
            introduced_word = true;
        } 
    }
    
    bool search(const string& word, int index = 0) const {
        if(index >= word.length()){
            return introduced_word;
        }
        else if(word[index] == '.'){
            bool find = false;
            for(const auto& [key, value] : next){
                find = value.search(word,index+1);
                if(find){
                    return true;
                }
            }
        }
        else if(next.find(word[index]) != next.end()){
            return next.at(word[index]).search(word, index+1);
        }

        return false;
    }
};
