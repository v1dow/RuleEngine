/* This demo reasons with list data. And we pre-scanned the rule set and completed the deployment of the container for the operators that appear in the rule set, which improves the efficiency of our reasoning. Not only that, but we also designed a set of data storage solutions for the inference process. */
#include "func.h"

extern reason* re;

extern calc::calc_parser *parser;

int main(int argc, char *argv[])
{
	parser = new calc::calc_parser();

	if (parser->create(0) != 1)
	{
		printf("Create calc_parser failed!\n");
	}
	/* We have only defined 6 statistical operations for the time being. */
	array<int, 6> opTable{0, 0, 0, 0, 0, 0};

	reason *re = new reason();
	re->InitReasonNetwork();
	initReasonwork(re, parser);
	/* allocate for original data from sensor */
	oriAllocator *oa = new oriAllocator();
	/* optimize efficiency of reasoning */
	optimize *opt = new optimize();
	/* scan the rule and set operations appear in rule set */
	opt->setOpTable(re);
	/* re-write rule and para to optimize */
	reshapeRulePara(re, parser, opt);
	opt->testOp();
	srand((unsigned)time(NULL));

	PARALIST *pl = re->GetParaList();

	double value = 0;
	bool mflag = false;

	/* simulate sensor sent data and original data memory space receives the first batch of sensor data */
	while(1)
	{
		value = genRandData(0.8,1.5);
		mflag = oa->genMemData(value);
		if(mflag)
			break;
	}

	/* simulate sensor data */
	while(1){
		value = genRandData(0.7,1.5);

		if(ready)
			/* reason with one batch of data */
			reasonOnce(opt,re,parser,oa,pl);
		else
		{
			/* update data in original data memory space */
			thread tupdateData(updateData,value,oa);
			tupdateData.join();
		}
	}
	delete re;
	delete oa;
	delete opt;
	delete parser;
	return 0;
}
