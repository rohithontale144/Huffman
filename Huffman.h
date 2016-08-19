#ifndef _HUFFMAN_H_
#define _HUFFMAN_H_


#include <map>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>


class CFileOperations
{
	streampos iFileSize;
	char *pszFileData;

	public:

		CFileOperations(char szFileName[]);

		MAPFREQUENCY getFrequency();

		~CFileOperations();
};


#endif


