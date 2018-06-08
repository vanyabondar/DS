#include "tree.h"

void print_tree(Node * p, int level)
{
	if (p)
	{
		print_tree(p->left, level + 1);
		for (int i = 0; i< level; i++) cout << "    ";
		cout << setprecision(3) << p->data << endl;
		print_tree(p->right, level + 1);
	}
}

Node* Creat_Node(int data) {
	Node* a = new Node;
	a->data = data;
	a->left = nullptr;
	a->right = nullptr;
	return a;
}

Node *Creat_tree() {
	srand(time(NULL));
	Node* q[ELEMENTS];
	for (int i = 0; i < ELEMENTS; i++) {
		float data = rand() % (MAX_NUM - MIN_NUM + 1) + MIN_NUM;
		q[i] = Creat_Node(data);
	}
	for (int i = 0; i < ELEMENTS; i++) {
		if (i * 2 + 1 < ELEMENTS)
			q[i]->left = q[i * 2 + 1];
		if (i * 2 + 2 < ELEMENTS)
			q[i]->right = q[i * 2 + 2];
	}
	return q[0];
}

float max_in_tree(Node* root) {
	if (!root)
		return INT_MIN;
	return max(root->data, max(max_in_tree(root->left), max_in_tree(root->right)));
}

float min_in_tree(Node* root) {
	if (!root)
		return INT_MAX;
	return min(root->data, min(min_in_tree(root->left), min_in_tree(root->right)));
}

void print_leafs(Node* root) {
	if (!(root->left || root->right)) {
		cout << setprecision(3) << root->data << ' ';
		return;
	}
	print_leafs(root->left);
	print_leafs(root->right);
}

void Add(Node** root, Node* temp) {
	if (*root == nullptr) {
		*root = temp;
		return;
	}
	queue<Node*> q;
	q.push(*root);
	while (true) {
		if (q.front()->left)
			q.push(q.front()->left);
		else {
			q.front()->left = temp;
			return;
		}
		if (q.front()->right)
			q.push(q.front()->right);
		else {
			q.front()->right = temp;
			return;
		}
		q.pop();
	}
}

void Delete_element(Node** root, int data) {
	vector<Node*> q;
	q.push_back((*root));
	int i = 0;
	while (true) {
		if (q[i]->left)
			q.push_back(q[i]->left);
		else
			break;
		if (q[i]->right)
			q.push_back(q[i]->right);
		else
			break;
		i++;
	}
	int pos;
	for (i = 0; i < q.size(); i++)
		if (q[i]->data == data) {
			pos = i;
			break;
		}

	if (q.size() == 1) {
		delete (*root);
		(*root) = nullptr;
	}
	else {
		q[pos]->data = q.back()->data;
		if ((q.size() - 2) % 2)
			q[(q.size() - 2) / 2]->right = nullptr;
		else
			q[(q.size() - 2) / 2]->left = nullptr;
		delete q.back();
	}
}

void Clear_tree(Node **root) {
	if (*root == nullptr)
		return;
	Clear_tree(&(*root)->left);
	delete (*root)->left;
	Clear_tree(&(*root)->right);
	delete (*root)->right;
	(*root) = nullptr;
}
void problem() {
	Node* tree = Creat_tree();

	cout << "Initial Tree:" << endl;
	print_tree(tree, 0);
	cout << endl << endl;

	cout << "Max: " << max_in_tree(tree);
	cout << endl << endl;

	cout << "Min: " << min_in_tree(tree);
	cout << endl << endl;

	cout << "Print leafs:" << endl;
	print_leafs(tree);

	Clear_tree(&tree);
}