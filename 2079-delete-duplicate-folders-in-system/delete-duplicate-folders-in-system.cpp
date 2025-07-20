class TrieNode {
public:
    string name;
    unordered_map<string, TrieNode*> children;
    string serial;
    bool marked = false;

    TrieNode(string _name = "") : name(_name) {}
};

class Solution {
public:
    TrieNode* root = new TrieNode();
    unordered_map<string, vector<TrieNode*>> serialMap;

    void insert(const vector<string>& path) {
        TrieNode* node = root;
        for (const string& folder : path) {
            if (!node->children.count(folder)) {
                node->children[folder] = new TrieNode(folder);
            }
            node = node->children[folder];
        }
    }

    string serialize(TrieNode* node) {
        if (node->children.empty()) {
            node->serial = "";
            return "";
        }

        vector<pair<string, string>> child_serials;
        for (auto& [childName, childNode] : node->children) {
            child_serials.emplace_back(childName, serialize(childNode));
        }

        sort(child_serials.begin(), child_serials.end());

        string result;
        for (auto& [name, ser] : child_serials) {
            result += name + "(" + ser + ")";
        }

        node->serial = result;
        serialMap[result].push_back(node);
        return result;
    }

    void markDuplicates() {
        for (auto& [ser, nodes] : serialMap) {
            if (nodes.size() > 1) {
                for (TrieNode* node : nodes) {
                    node->marked = true;
                }
            }
        }
    }

    void collectPaths(TrieNode* node, vector<string>& path, vector<vector<string>>& result) {
        for (auto& [name, child] : node->children) {
            if (!child->marked) {
                path.push_back(name);
                result.push_back(path);
                collectPaths(child, path, result);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        // Step 1: Build Trie
        for (auto& path : paths) {
            insert(path);
        }

        // Step 2: Serialize
        serialize(root);

        // Step 3: Mark Duplicates
        markDuplicates();

        // Step 4: Collect non-duplicate paths
        vector<vector<string>> result;
        vector<string> currentPath;
        collectPaths(root, currentPath, result);
        return result;
    }
};
