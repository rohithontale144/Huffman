#include <iostream>

#ifndef _TREE_H_
#define _TREE_H_

class CNode
{
	private:
		unsigned int iValue;
		CNode *pLeft;
		CNode *pRight;

	public:
		/*
		 * API's
		 *
		 *  1)insertLeft
		 *	2)insertRight
		 *	4)operator+
		 *	5)operator=
		*/


		/*
		 * This function will insert the node to the left side.
		*/
		void insertLeft(CNode *node);
		/*
		 * This function will insert the node to the right side.
		*/
		void insertRight(CNode *node);

		CNode* operator+ (int iValue);
};

#endif


