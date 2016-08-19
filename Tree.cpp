#include "Tree.h"

using namespace std;


/*
 * This function will insert the node to the left side.
*/
void CNode::insertLeft(
				CNode *node
				)
{
	this->pLeft = node;
}


/*
 * This function will insert the node to the right side.
*/
void CNode::insertRight(
				CNode *node
				)
{
	this->pRight = node;
}


CNode* CNode::operator+ (int iValue)
{
	this->iValue += iValue;
	return this;
}
