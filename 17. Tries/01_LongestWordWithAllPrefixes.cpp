class Node {
	public:
	Node* links[26] = {NULL};
	bool flag = false;
	
	bool containsChar(char ch) {return links[ch - 'a'] != NULL; }
	void putChar(char ch, Node* node) {links[ch - 'a'] = node; }
	Node* getChar(char ch) { return links[ch - 'a']; }
	void setEnd() {flag = true; }
	bool isEnd() {return flag; }
};
class Trie {
	public:
	Node* root;
	Trie() {
		root = new Node();
	}
	
	void insert(string word) {
		Node* node = root;
		for (char ch: word) {
			if (!node->containsChar(ch))
				node->putChar(ch, new Node());
			node = node->getChar(ch);
		}
		node->setEnd();
	}
	
	bool checkIfPrefixExists(string word) {
		Node* node = root;
		
		for (char ch: word) {
			if (node->containsChar(ch)) {
				node = node->getChar(ch);
				if (!node->isEnd())
					return false;
			}
			else
				return false;
		}
		return true;
	}
	
};
class Solution {
	public:
	
	string longestValidWord(vector<string>& words) {
		// code here
		
		Trie t;
		for (auto &it: words) {
			t.insert(it);
		}
		
		string ans = "";
		
		for (auto &it: words) {
			if (t.checkIfPrefixExists(it)) {
				if (it.size() > ans.size())
					ans = it;
				else if (it.size() == ans.size() && it<ans)
					ans = it;
			}
		}
		return ans;
	}
};
