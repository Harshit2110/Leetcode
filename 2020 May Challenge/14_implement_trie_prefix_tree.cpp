class Trie {
public:
    struct TrieNode{
        char val;
        int endNode;
        TrieNode* child[26];
    } *root;

    /** Initialize your data structure here. */
    Trie() {
        //for fast I/O
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        //initialise root
        root = createNode('/');
    }

    /*
    Add new node into the trie structure
    */
    TrieNode *createNode(char c){
        TrieNode* newNode = new TrieNode();
        newNode->val = c;
        newNode->endNode = 0;

        for(int i = 0; i < 26; i++)
            newNode->child[i] = NULL;

        return newNode;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *node = root;

        for(int i = 0; word[i]!= '\0'; i++){
            int index = word[i] - 'a';

            if(node->child[index] == NULL)
                node->child[index] = createNode(word[i]);

            node = node->child[index];
        }

        node->endNode += 1;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *node = root;

        for(int i = 0;word[i] != '\0'; i++){
            int index = word[i] - 'a';

            if(node->child[index] == NULL)
                return false;

            node = node->child[index];
        }

        return (node->endNode > 0);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *node = root;

        for(int i = 0;prefix[i] != '\0'; i++){
            int index = prefix[i] - 'a';

            if(node->child[index] == NULL)
                return false;

            node = node->child[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
