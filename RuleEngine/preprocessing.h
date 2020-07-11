/* rule set pre-processing
** extract SU from rule set 
** and create new SU for characteristic reference 
** calling method: new a instance => instance->SUExtraction() => instance->SUListProcessing() */
#ifndef PREPROCESSING_H
#define PREPROCESSING_H

#include "statisticalUnion.h"
#include "reason.h"


class statisticalUnion;

typedef list<statisticalUnion*> SULIST;

class preprocessing
{

public:
	SULIST* SUList;
	
public:
	preprocessing();
	~preprocessing();

	void trim(string& str);
	SULIST* GetSUList();
	bool isInSUList(statisticalUnion* SU);
	statisticalUnion* CreateSU(int CID, string statStr, int windowSize, int streamID, int period, double value,string AC);
	statisticalUnion* CreateSU(int CID, string statStr, int windowSize, int streamID, int period, double value);
	
	// need compatibility modification
	void SUExtraction(reason* re);
	void SUListProcessing();

	void testSUList();

};

#endif
