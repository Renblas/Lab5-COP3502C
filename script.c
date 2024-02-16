#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	int i = 0;
	node* temp = head;
	while (temp != NULL) {
		i++;
		temp = temp->next;
	}

	return i;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	int size = length(head);
	node* temp = head;

	char* string = (char*)malloc(sizeof(char) * (size + 1)); 
	for (int i = 0; i < size; i++) {
		string[i] = temp->letter;
			temp = temp->next;
	}
	string[size] = '\0';

	return string;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	if (*pHead == NULL) {

		*pHead = (node*)malloc(sizeof(node));
		(*pHead)->letter = c;

	} else {
		node* temp = *pHead;
		while (temp->next != NULL) {
			temp = temp->next;
		}

		temp->next = (node*)malloc(sizeof(node));
		temp->next->letter = c;
	}
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	node* past = *pHead;
	node* temp = *pHead;
	while (temp->next != NULL) {
		past = (temp);
		(temp) = (temp)->next;
		free(past);
	}
	free(temp);
	*pHead = NULL;	
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);

	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!\n");
			break;
		}
	}

	fclose(inFile);
}
