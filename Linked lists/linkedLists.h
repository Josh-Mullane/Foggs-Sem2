#pragma once
#include "structs.h"
#include <iostream>
#include <iomanip>
using namespace std;
class linkedLists
{
	private:

	listNode* head = nullptr;

	public:

	linkedLists();
	~linkedLists();

	listNode* makeNode(listNode** head, int d);
	listNode* insertFirst(listNode** head, int d);
	void insertAfter(listNode* lastNode, int d);
	void deleteList(listNode** node);


};

