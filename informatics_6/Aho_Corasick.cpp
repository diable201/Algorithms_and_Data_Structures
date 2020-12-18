#include <bits/stdc++.h>

using namespace std;

const int alpha = 26;
int qq = 0;

struct node {
	vector<node*> child;	
	bool term;
	node *suff;
	vector<node*> go;
	int cnt;
	int id;

	node() {
		child.resize(alpha, nullptr);
		term = false;
		suff = nullptr;
		go.resize(alpha, nullptr);
		cnt = 0;
		id = qq++;
	}
};

bool find(node *v, string &s, int i) {
	if (v == nullptr)
		return false;
	if (i == s.size())
		return v->term;
	return find(v->child[s[i] - 'a'], s, i + 1);
}

node *insert(node *v, string &s, int i) {
	if (v == nullptr)
		v = new node();
	if (i == s.size()) {
		v->term = true;
		return v;
	}
	int ch = s[i] - 'a';
	v->child[ch] = insert(v->child[ch], s, i + 1);
	return v;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	node *root = nullptr;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		root = insert(root, s, 0);
	}

	node *f = new node();

	f->child.assign(alpha, root);
	f->go.assign(alpha, root);

	root->suff = f;
	queue <node*> q;
	q.push(root);

	while (!q.empty()) {
		node *v = q.front();
		q.pop();
		v->cnt = v->suff->cnt + v->term;
		for (int i = 0; i < alpha; i++) {
			if (v->child[i] == nullptr)
				v->go[i] = v->suff->go[i];
			else {
				v->go[i] = v->child[i];
				v->child[i]->suff = v->suff->go[i];
				q.push(v->child[i]);
			}
		}
	}

	node *v = root;

	string t;
	cin >> t;

	for (auto &ch: t) {
		v = v->go[ch - 'a'];
		cout << v->cnt << " ";
	}
	cout << '\n';
	return 0;
}
