#include <iostream>
#include <string>
#include<vector>
using namespace std;

class QuadTree {		//QuadTree Class
public:
	char value;
	QuadTree * child[4];

	QuadTree();
	QuadTree(char);
	~QuadTree();
};

QuadTree::QuadTree(char input){
	value = input;
	for (int i = 0; i < 4; i++)
		child[i] = NULL;
}

QuadTree::QuadTree(){
	for (int i = 0; i < 4; i++)
		child[i] = NULL;
}

QuadTree::~QuadTree(){
	for (int i = 0; i < 4; i++)
		if (child[i] != NULL)
			delete child[i];
}

void print_flip_tree(QuadTree * root){
	cout << root->value;
	int sequence[4] = { 2, 3, 0, 1 };
	for (int i = 0; i < 4; i++)
	{
		if (root->child[sequence[i]] == NULL)
			continue;
		if (root->child[sequence[i]]->value == 'x')
			print_flip_tree(root->child[sequence[i]]);
		else
			cout << root->child[sequence[i]]->value;
	}
}

string maketree(QuadTree* root, string input)
{
	unsigned int count = 0;
	unsigned int index = 0;
	root->value = input[0];
	index++;

	while (count < 4)
	{
		if (input[index] == 'b' || input[index] == 'w'){
			root->child[count] = new QuadTree(input[index]);
			index++;
		}
		else if (input[index] == 'x'){
			root->child[count] = new QuadTree();
			input = maketree(root->child[count], input.substr(index));
			index = 0;
		}
		count++;
	}
	return input.substr(index);
}


int main(void)
{
	int test_num;
	string input;
	string temp;
	QuadTree * tree;
	vector<string> input_arr;

	getline(cin, temp);
	test_num = atoi(temp.c_str());
	for (int i = 0; i < test_num; i++){
		getline(cin, input);
		input_arr.push_back(input);
	}


	for (int i = 0; i < test_num; i++){
		input = input_arr.at(i);
		tree = new QuadTree();

		maketree(tree, input);

		print_flip_tree(tree);
		cout << endl;
		delete tree;
	}

	return 0;

}
