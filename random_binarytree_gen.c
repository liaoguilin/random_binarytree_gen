#include <stdio.h>
#include <stdlib.h>
#include<time.h>
//#define num_nodes = 100
#define MAX  3
typedef struct bwtree Bwtree;
struct bwtree {
	int weight;
	Bwtree* left;
	Bwtree* right;
}bwtree;
//~ strcut

Bwtree* impbwtree(const int num_nodes)
{
	Bwtree* root = calloc(sizeof(struct bwtree), 1);
	Bwtree* temp = root;
	//printf("time to show");
	//int  ss;
	//
	//scanf("%d, &ss");
	//int b = 2;
	//int static MAX;
	const int tt = 9;
	Bwtree* nodelist[MAX] = { -1 };
	nodelist[0] = root;
	srand(time(NULL));
	root->weight = (rand() % 10);
	int i = 0;
	while (i < num_nodes - 1)
	{
	loop:
		//int szarr = sizeof(nodelist) / sizeof(nodelist[0]);
		srand(time(NULL));
	access:
		temp = nodelist[rand() % (i + 1)];
		if (temp != NULL)
		{
			int randw = rand() % 10;
			if (temp->left == NULL && temp->right == NULL)
			{
				if (rand() % 2 == 0)
				{
					temp->left = calloc(sizeof(Bwtree), 1);
					temp->left->weight = randw;
					temp = temp->left;
					nodelist[i + 1] = temp;
				}
				else
				{
					temp->right = calloc(sizeof(Bwtree), 1);
					temp->right->weight = randw;
					temp = temp->right;
					nodelist[i + 1] = temp;
				}
			}
			if (temp->left == NULL && temp->right != NULL)
			{
				temp->left = calloc(sizeof(Bwtree), 1);
				temp->left->weight = randw;
				temp = temp->left;
				nodelist[i + 1] = temp;
			}
			if (temp->right == NULL && temp->left != NULL)
			{
				temp->right = calloc(sizeof(Bwtree), 1);
				temp->right->weight = randw;
				temp = temp->right;
				nodelist[i + 1] = temp;
			}
			if (temp->right != NULL && temp->right != NULL)
				goto loop;
			i++;
		}
		else
		{
			goto access;
		}

	}
	return root;

}
void main()
{
	//int num_nodes;
	//scanf("%d", &num_nodes);
	const int para = 3;
	Bwtree* tett = impbwtree(para);
	printf("");
}
