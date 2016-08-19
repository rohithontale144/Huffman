#include "Huffman.h"

using namespace std;


typedef pair <char,unsigned int> PAIRFREQ;
typedef map <char,unsigned int> MAPFREQUENCY;


CFileOperations::CFileOperations(char szFileName[])
{
	ifstream file;
	file.exceptions(ifstream::failbit | ifstream::badbit);

	try
	{
		file.open(szFileName,ios::binary | ios::ate);
		iFileSize = file.tellg();
		file.seekg(0,ios::beg);
		pszFileData = new char[iFileSize];
		file.read(pszFileData,iFileSize);
		file.close();
	
	}catch(fstream::failure e)
	{
		cout << "File operation fails\n";
	}
}


MAPFREQUENCY CFileOperations::getFrequency()
{
	MAPFREQUENCY mapFreq;
	MAPFREQUENCY::iterator mapIt;

	for (int iCnt = 0 ; pszFileData[iCnt] != '\0' ; iCnt++)
	{
		mapIt = mapFreq.find(pszFileData[iCnt]);

		if (mapFreq.end() == mapIt) //Not found in MAP.
		{
			mapFreq[pszFileData[iCnt]] = 1;
		}

		else
		{
			mapIt->second++;
		}
	}

	mapFreq.erase(char(10));

	return mapFreq;
}


CFileOperations::~CFileOperations()
{
	delete pszFileData;
}



bool compare(
			PAIRFREQ &a,
			PAIRFREQ &b
			)
{
	return a.second < b.second;
}


int main(
		int iArgc,
		char *szArgv[]
		)
{
	PAIRFREQ pairFreq;
	MAPFREQUENCY mapFreq;
	vector<PAIRFREQ> vecPair;
	MAPFREQUENCY::iterator mapIt;

	if (2 != iArgc)
	{
		cout << "Please enter file name as Parameter\n";
		return 1;
	}

	FileOperations obj(szArgv[1]);
	mapFreq = obj.getFrequency();
	
	for (mapIt = mapFreq.begin() ; mapFreq.end() != mapIt ; mapIt++)
	{
		pairFreq.first = mapIt->first;
		pairFreq.second = mapIt->second;

		vecPair.push_back(pairFreq);
	//	cout << "( "  << int(mapIt->first) << " ) - (" << mapIt->second << ")" << endl;
	}

	sort(vecPair.begin(),vecPair.end(),compare);

	for (int iCnt = 0; vecPair.size() > iCnt ; iCnt++)
	{	
		cout << "("  << int(vecPair[iCnt].first) << ") - (" << vecPair[iCnt].second << ")" << endl;
	}

	return 0;
}


