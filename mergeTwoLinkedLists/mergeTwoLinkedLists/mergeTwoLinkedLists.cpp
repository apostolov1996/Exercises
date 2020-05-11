#include <iostream>

struct node
{
	int data;
	node* next;
};

class LinkedList {
private:

	node* head;
	node* tail;

public:
	LinkedList(): head { nullptr }, tail{ nullptr } {};

	void addNode(int value)
	{
		node* temp = new node;
		temp->data = value;
		temp->next = nullptr;
		if (head == nullptr)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
	}

	void printList()
	{
		node* temp = new node;
		temp = head;
		while (temp != nullptr)
		{
			std::cout << temp->data << "\t";
			temp = temp->next;
		}
	}

	void swapPosition(node* first, node* second)
	{
		node* temp = new node;
		temp->data = first->data;
		first->data = second->data;
		second->data = temp->data;
	}

	void bubbleSortList()
	{
		int swapped;
		node* ptr1;

		if (head == nullptr)
		{
			return;
		}
		do
		{
			swapped = 0;
			ptr1 = head;

			while (ptr1->next != nullptr)
			{
				if (ptr1->data > ptr1->next->data)
				{
					swapPosition(ptr1, ptr1->next);
					swapped = 1;
				}
				ptr1 = ptr1->next;
			}
		} while (swapped);
	}

	node* getHead()
	{
		return head;
	}
};

LinkedList mergeList(LinkedList& firstList, LinkedList& secondList)
{
	LinkedList final = LinkedList();
	if (firstList.getHead() == nullptr && secondList.getHead() == nullptr)
	{
		return final;
	}
	else if (firstList.getHead() == nullptr)
	{
		return secondList;
	}
	else if (secondList.getHead() == nullptr)
	{
		return firstList;
	}
	else
	{
		node* temp = firstList.getHead();
		while (temp != nullptr)
		{
			final.addNode(temp->data);
			temp = temp->next;
		}
		temp = secondList.getHead();
		while (temp != nullptr)
		{
			final.addNode(temp->data);
			temp = temp->next;
		}
		final.bubbleSortList();
		return final;
	}
}

int main()
{
	LinkedList list = LinkedList();
	list.addNode(545);
	LinkedList secondList = LinkedList();
	secondList.addNode(5);
	LinkedList final = mergeList(list, secondList);
	final.printList();
	return 0;
}
