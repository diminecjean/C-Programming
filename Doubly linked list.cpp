#include <iostream>
using namespace std;

template <class T>
class ListNode
{ 
	public:
		T value;
		ListNode<T> *next;
		ListNode<T> *previous;
};

template <class T>
class DoubleList
{ 
	private:
		ListNode<T> *head;
		ListNode<T> *end;
	
	//methods
	public:
		// Default constructor
		DoubleList();
		bool isEmpty() const;
		void destroyList();
		void showList();
		void showListReverse();
		bool search(T);
		void insertNode (T);
		void deleteNode(T);
		~DoubleList(){destroyList();}
};

template <class T>
DoubleList<T>::DoubleList()
{ 
	head = NULL;
	end = NULL;
}

template <class T>
bool DoubleList<T>::isEmpty() const
{ 
	// if head is null, returns true
	return (head == NULL);
}

template <class T>
void DoubleList <T>::destroyList()
{
	ListNode<T> *nodePtr;//pointer to delete the node
	while (head != NULL)
	{
		nodePtr = head;
		head = head->next;
		delete nodePtr;
	}
	end = NULL;
}

template <class T>
void DoubleList<T>::showList()
{ 
	ListNode<T> *nodePtr;
	nodePtr = head;
	while (nodePtr != NULL) 
	{
		cout<< nodePtr->value<<" ";
		nodePtr = nodePtr->next;
	}
}

template <class T>
void DoubleList<T>::showListReverse()
{ 
	ListNode<T> *nodePtr;
	nodePtr = end; //set to point last node
	while (nodePtr != NULL) 
	{
		cout<< nodePtr->value<<" ";
		nodePtr = nodePtr->previous;
	}
}

template <class T>
bool DoubleList<T>::search(T number)
{ 
	bool found = false;
	ListNode<T> *nodePtr;
	nodePtr = head; 
	while (nodePtr != NULL && !found) 
	{	
		// if the value is equal to or larger than 
		// the number in the list, return found as true
		// Only works if linkedlist is arranged according to order
		if (nodePtr->value >= number)
			found = true;
		else
			nodePtr = nodePtr->next;
	}
	
	// determine whether the number is equal to the value
	if (found) 
		found = (nodePtr->value == number); 
	return found;
}

template <class T>
void DoubleList<T>::insertNode(T newItem)
{
	ListNode<T> *nodePtr; //pointer to traverse the list
	ListNode<T> *trailPtr; //pointer just before current
	ListNode<T> *newNode; //pointer to create a node
	bool found;
	
	newNode = new ListNode<T>; //create the node
	newNode->value = newItem; //store the new item in the node
	newNode->next = NULL;
	newNode->previous = NULL;
	
	if (head == NULL) // Case 1:if the list is empty, newNode is the only node
	{
		head = newNode;
		end = newNode;
	}
	else
	{
		found = false;
		nodePtr = head;
		while(nodePtr != NULL && !found)
		{
			if (nodePtr->value >= newItem)
			{
				found = true;
				break;
			}	
			else
			{
				trailPtr = nodePtr;
				nodePtr = nodePtr->next;
			}
		}
		if (nodePtr == head) // Case 2
		{
			head->previous = newNode;
			newNode->next =head;
			head = newNode;
		}
		else if(nodePtr==NULL) // case 3
		{
			trailPtr->next = newNode;
			newNode->previous = trailPtr;
			end = newNode;
		}
		else if (nodePtr!=NULL) // case 4
		{
			trailPtr->next = newNode;
			newNode->previous = trailPtr;
			newNode->next = nodePtr;
			nodePtr->previous= newNode;
		}
	}
}

template <class T>
void DoubleList<T>::deleteNode(T delItem)
{
	ListNode<T> *nodePtr; //pointer to traverse the list
	ListNode<T> *trailPtr; //pointer just before current
	bool found;
	
	if (head == NULL) // case 1
	{
		cout<<"Cannot delete from an empty list";
	}
	else if (head->value == delItem) // case 2
	{
		nodePtr = head;
		head = head->next;
		if (head != NULL)
			head->previous = NULL;
		else
			end = NULL;
		delete nodePtr;
	}
	else  // case 3
	{
		found = false;
		nodePtr = head;
		while(nodePtr != NULL && !found)
		{
			if (nodePtr->value >= delItem)
				found = true;
			else
				nodePtr = nodePtr->next;
		}
		if (nodePtr->value == delItem)
		{
			trailPtr = nodePtr->previous;
			trailPtr->next = nodePtr->next;
			if (nodePtr->next != NULL)
				nodePtr->next->previous = trailPtr;
			if (nodePtr == end)
				end = trailPtr;
			delete nodePtr;
		}
		else // case 4
		{
			cout << "Item not in list.\n";
		}	
	}
}

int main()
{
	DoubleList<int> list;
	
	if(list.isEmpty())
	{
		cout << "List is empty.\n";
	}
	
	list.insertNode(1); 
	list.insertNode(6); 
	list.insertNode(10); 
	
	list.showList();
	cout << endl;
	
	list.showListReverse();
	cout << endl;
	
	list.insertNode(7);
	list.showList();
	cout << endl;
	
	list.insertNode(0);
	list.showList();
	cout << endl;
	
	list.deleteNode(0);
	list.deleteNode(2);
	list.showList();
	cout << endl;
	
	cout << list.search(5);
	
	return 0;
}
