#include <stdio.h>
#include <stdlib.h>
/*
 * Builds a linked list using data entered by the user, one by one.
 * Prints the list data and then frees/deletes the list.
 */

// Defines a node struct
typedef struct Node
{
	int data;
	struct Node *next;
}Node;


// Function Prototypes
Node* create_node();

int main()
{
	Node *list;
	Node *head;

	int num_nodes = 0;
	int num;	// Used to store input from user
	
	while(num != 2)
	{
		printf("Would you like to add a Node? Enter 1 if yes, otherwise enter 2: ");
		scanf("%d", &num);
		if (num == 1)
		{
			num_nodes++;
			if (num_nodes == 1)
			{
				list = create_node(); // Allocates dynamic memory for a new node
				printf("Enter data for Node %d: ", num_nodes); // Gets data from user
				scanf("%d", &list->data); // Inserts data for the node
				list->next = NULL; // Sets Node's next ptr to NULL
				head = list; // Saves head of the node(Points to address of 1st node)
			}
			else
			{
				list->next = create_node();
				printf("Enter data for Node %d: ", num_nodes);
				scanf("%d", &list->next->data);
				list->next->next = NULL;
				list = list->next;
			}
		}
	}

	// Print list data
	list = head;
	while (list != NULL)
	{
		printf("-----\n");
		printf("| %d |\n", list->data);
		printf("-----\n");
		printf("  |  \n");
		printf("  |  \n");
		printf("  V  \n");
		list = list->next;
	}
	printf("------\n");
	printf(" NULL\n");
	printf("------\n");

	// Free dynamic memory
	Node *temp;
	list = head;
	while (list != NULL)
	{
		temp = list;
		list = list->next;
		free(temp);
	}

	return 0;
}

// Creates and returns a new node
Node* create_node()
{
	Node *node = (Node *) malloc(sizeof(Node));
	if (node == NULL)
	{
		printf("Error allocating Node memory!\n");
		exit(1);
	}
	return node;
}
