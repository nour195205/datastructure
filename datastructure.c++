#define Size 5

//----------->Stack<-----------
#pragma region Stack_implementaion
int Stack[Size], top = -1;
#pragma region Empty_func
bool Empty() {
	if (top == -1)
	{
		cout << "Stack is empty" << endl;
		return true;
	}
	else
	{
		cout << "Stack is not empty" << endl;
		return false;
	}
}
#pragma endregion
#pragma region Full_func
bool Full() {
	if (top == Size - 1)
	{
		cout << "Stack is full" << endl;
		return true;
	}
	else
	{
		cout << "Stack is not full" << endl;
		return false;
	}
}
#pragma endregion
#pragma region Push_func
void push(int item) {
	if (top != Size - 1)
	{
		top++;
		Stack[top] = item;
		//OR Stack[++top]=item;
	}
	else
	{
		cout << "Stack Overflow" << endl;
	}
}
#pragma endregion
#pragma region POP_func
int POP() {
	if (top != -1)
	{
		return Stack[top--];
	}
	else
	{
		cout << "Stack is Empty" << endl;
	}
}
#pragma endregion
#pragma region Peek_func
int Peek() {
	if (top != -1)
	{
		return Stack[top];
	}
	else
	{
		cout << "Stack is Empty" << endl;
	}
}
#pragma endregion  
#pragma endregion
//----------->Queue<-----------
#pragma region Queue_implementation
int Queue[Size], head = -1, tail = -1;
#pragma region Simple_queue
#pragma region Empty_func
bool empty() {
	if (head == -1 && tail == -1 || head > tail)
	{
		cout << "Queue is empty" << endl;
		return true;
	}
	else
	{
		return false;
	}
}
#pragma endregion
#pragma region Full_func
bool full() {
	if (tail == Size - 1)
	{
		cout << "Queue is full" << endl;
		return true;
	}
	else
	{
		return false;
	}
}
#pragma endregion
#pragma region Enqueue_func
void enqueue(int item) {
	if (tail != Size - 1)
	{
		if (head == -1 && tail == -1)
		{
			tail++;
			head++;
			Queue[tail] = item;
		}
		else
		{
			tail++;
			Queue[tail] = item;
		}

	}
	else
	{
		cout << "Queue is Full" << endl;
	}
}
#pragma endregion
#pragma region Dequeue_func
void dequeue() {
	if (head != -1 && tail != -1 && head <= tail)
	{
		head++;
	}
	else
	{
		cout << "Queue is empty" << endl;
	}
}
#pragma endregion
#pragma region Peek_func
int peek() {
	if (head != -1 && tail != -1 && head <= tail)
	{
		return Queue[head];
	}
	else
	{
		cout << "Queue is empty" << endl;
	}
}
#pragma endregion   
#pragma endregion
#pragma region Circular_queue
#pragma region Empty_func
bool Emptty() {
	if (head == -1 && tail == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
#pragma endregion
#pragma region Full_func
bool Fulll() {
	if (head == 0 && tail == Size - 1)
	{
		return true;
	}
	else if (head == tail + 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
#pragma endregion
#pragma region Enqueue_func
void Enqueue(int item) {
	if (!Fulll())
	{
		if (head == -1 && tail == -1)
		{
			head++;
			tail++;
			Queue[tail] = item;
		}
		else if (tail == Size - 1)
		{
			tail = 0;
			Queue[tail] = item;
		}
		else
		{
			tail++;
			Queue[tail] = item;
		}
	}
	else
	{
		cout << "Queue is full" << endl;
	}
}
#pragma endregion
#pragma region Dequeue_func
void Dequeue() {
	if (!Emptty)
	{
		if (head == tail)
		{
			head = tail == -1;
		}
		else if (head == Size - 1)
		{
			head = 0;
		}
		else
		{
			head++;
		}
	}
	else
	{
		cout << "Queue is empty" << endl;
	}
}
#pragma endregion
#pragma region Peek_func
int Peekk() {
	if (!Emptty)
	{
		return Queue[head];
	}
	else
	{
		cout << "Queue is empty" << endl;
	}
}
#pragma endregion

#pragma endregion
#pragma endregion
//----------->Linked list<-----------
#pragma region LinkedList_implementation
struct Node
{
	int Data;
	Node* Next;
};
Node* Head = NULL;
#pragma region InsertAtEnd_func
void insertAtEnd(int value) {
	Node* new_node, * last_node;
	new_node = new Node;
	new_node->Data = value;
	if (Head == NULL)
	{
		Head = new_node;
		new_node->Next = NULL;
	}
	else
	{
		last_node = Head;
		while (last_node->Next != NULL)
		{
			last_node = last_node->Next;
		}
		last_node->Next = new_node;
		new_node->Next = NULL;
	}
}
#pragma endregion
#pragma region InsertAtBeginig_func
void InsertAtBeginig(int value) {
	Node* new_node = new Node;
	new_node->Data = value;
	new_node->Next = Head;
	Head = new_node;
}
#pragma endregion
#pragma region InsertAtPosition_func
void InsertAtPosition(int value, int position) {
	Node* new_node = new Node;
	new_node->Data = value;
	if (position == 0)
	{
		new_node->Next = Head;
		Head = new_node;
	}
	else
	{
		Node* current_node = Head;
		for (int i = 0; i < position - 1; i++)
		{
			current_node = current_node->Next;
		}
		new_node->Next = current_node->Next;
		current_node->Next = new_node;
	}
}
#pragma endregion
#pragma region DeleteNode_func
void delete_node(int value) {
	Node* current, * previous;
	current = Head;
	previous = Head;
	if (current->Data == value)
	{
		Head = current->Next;
		free(current);
		return;
	}

	while (current->Data != value)
	{
		previous = current;
		current = current->Next;
	}
	previous->Next = current->Next;
	free(current);

}
#pragma endregion
#pragma region DeleteAtEnd_func
void delete_end() {
	if (Head == NULL)
	{
		cout << "Linkedlist is empty" << endl;
	}
	else
	{
		Node* last_node = Head;
		while (last_node->Next->Next != NULL)
		{
			last_node = last_node->Next;
		}
		delete(last_node->Next);
		last_node->Next = NULL;
	}
}
#pragma endregion
#pragma region DeleteAtBeginig_func
void delete_start() {
	if (Head == NULL)
	{
		cout << "Linkedlist is empty" << endl;
	}
	else
	{
		Head = Head->Next;
	}
}
#pragma endregion
#pragma region Display_fun
void display() {
	Node* current_node;
	if (Head == NULL)
	{
		cout << "Linkedlist is empty" << endl;
	}
	else
	{
		current_node = Head;
		while (current_node != NULL)
		{
			cout << current_node->Data << "\t";
			current_node = current_node->Next;
		}
		cout << endl;
	}
}
#pragma endregion

#pragma endregion
//----------->Tree<-----------
#pragma region Tree_implementation
struct node {
	int data;
	node* left;
	node* right;
};
//——— create_node ———
#pragma region CreatNode_func
node* createNode(int value) {
	node* n = new node;
	n->data = value;
	n->left = nullptr;
	n->right = nullptr;
	return n;
}
#pragma endregion


//——— insert_on_left ———
#pragma region InsertOnLeft_func
node* insertLeft(node* root, int value) {
	// ???? ?????? ??????? ???? ????
	root->left = createNode(value);
	return root->left;          // ????? ???? ?????? ????????
}
#pragma endregion


//——— insert_on_right ———
#pragma region InsertOnRight_func
node* insertRight(node* root, int value) {
	// ???? ?????? ??????? ???? ????
	root->right = createNode(value);
	return root->right;         // ????? ???? ?????? ????????
}
#pragma endregion

#pragma endregion




#include <iostream>
using namespace std;

// Traverse array
void traverse(int arr[], int size) {
    cout << "Array elements: ";
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Reverse array
void reverse(int arr[], int size) {
    for(int i = 0; i < size / 2; i++)
        swap(arr[i], arr[size - 1 - i]);
}

// Merge two arrays
int merge(int arr1[], int size1, int arr2[], int size2, int result[]) {
    for(int i = 0; i < size1; i++)
        result[i] = arr1[i];
    for(int i = 0; i < size2; i++)
        result[size1 + i] = arr2[i];
    return size1 + size2;
}

// Insert element at position
int insert(int arr[], int size, int pos, int value) {
    for(int i = size; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = value;
    return size + 1;
}

// Delete element at position
int remove(int arr[], int size, int pos) {
    for(int i = pos; i < size - 1; i++)
        arr[i] = arr[i + 1];
    return size - 1;
}

int main() {
    int arr[20] = {1, 2, 3, 4, 5};
    int size = 5;

    traverse(arr, size);

    reverse(arr, size);
    cout << "After reverse: ";
    traverse(arr, size);

    size = insert(arr, size, 2, 99);
    cout << "After insertion: ";
    traverse(arr, size);

    size = remove(arr, size, 3);
    cout << "After deletion: ";
    traverse(arr, size);

    int arr2[3] = {10, 20, 30};
    int merged[30];
    int mergedSize = merge(arr, size, arr2, 3, merged);
    cout << "After merge: ";
    traverse(merged, mergedSize);

    return 0;
}