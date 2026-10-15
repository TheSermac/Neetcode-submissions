class PrefixTree {
private:
    bool introduced_word;
    map<char,PrefixTree> next;
public:
    PrefixTree() {
        introduced_word= false;
    }
    
    void insert(const string& word, int index = 0) {
        if(index < word.length()){
            next[word[index]].insert(word, index+1);
        }
        else{
            introduced_word = true;
        } 
    }
    
    bool search(const string& word, int index = 0) {
        if(index >= word.length()){
            return introduced_word;
        }
        else if(next.find(word[index]) != next.end()){
            return next[word[index]].search(word, index+1);
        }

        return false;
    }
    
    bool startsWith(const string& word, int index = 0) {
        if(index >= word.length()){
            return true;
        }
        else if(next.find(word[index]) != next.end()){
            return next[word[index]].startsWith(word, index+1);
        }

        return false;
    }
};
