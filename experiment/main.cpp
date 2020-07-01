#include "func.h"
#include <chrono>
#include <fstream>

extern reason* re;

extern calc::calc_parser *parser;

int main(int argc, char *argv[])
{
	int n = -1;

	parser = new calc::calc_parser();

	if (parser->create(0) != 1)
	{
		printf("Create calc_parser failed!\n");
	}

	array<int, 6> opTable{0, 0, 0, 0, 0, 0};

	if (argc == 1)
	{
		cout << "现在用随机产生的数据进行规则推理:"
			 << "(每隔三秒推理一次)" << endl
			 << endl
			 << endl;
		sleep(3);

		reason *re = new reason();
		re->InitReasonNetwork();

		srand((unsigned)time(NULL));
		initReasonwork2(re, parser);

		while (1)
		{
			cout << "************" << endl;
			dataProduce(re);
			//reasonIndeRules(re, parser);
			//reasonNestedRules(re, parser);
			reasonRules(re,parser);

			cout << "************" << endl
				 << endl
				 << endl;


			sleep(3);
		}
		delete re;
	}
	if (argc == 2)
	{

		// ifstream fin(argv[1]);
		// if(!fin)
		// {
		//     printf("no file data!\n");
		//     exit(1);
		// }

		//else
		//{
		//cout<<"现在从该文档中读入数据"<<endl;
		//sleep(1);

		// int curIndex = 0;
		// double value = 0;
		// bool mflag = false;
		// bool dflag = false;
		// bool rflag = false;

		// sqlite3* db = NULL;
		// const string tName = "vibration";
		// int rc;
		// rc = sqlite3_open("test.db",&db);
		// if(rc)
		// {
		// 	fprintf(stderr,"Can't open database:%s\n",sqlite3_errmsg(db));
		// 	sqlite3_close(db);
		// 	exit(1);
		// }
		// else
		// 	printf("open database successfully.\n");

		int timeseries[] = {5,10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95,100,105,110,115,120,125,130};
		auto timesize = sizeof(timeseries)/sizeof(int);
		double timescale = 0;
		double samplingFreq = 0.01;
		bool flag = false;
		double value = 0;

		reason *re = new reason();
		re->InitReasonNetwork();
		initReasonwork2(re, parser);
		srand((unsigned)time(NULL));


		/* ************************
		* Scheme without optimize *
		************************ */
/*
		auto start = chrono::high_resolution_clock::now();

		window* windows[timesize];
		double tmpscale = 0;
		for(int i = 0;i < timesize;i++){
			timescale = timeseries[i] - tmpscale;
			tmpscale = timeseries[i];
			windows[i] = new window(samplingFreq,timescale);
		}

		for(int k=0;k<1;k++)
		{
			deque<double>* bigwindow[timesize];
			int index = 0;
			while(1)
			{
				if(index == timesize)
				{
					break;
				}
				value = genRandData(0.7,1.5);
				if(!flag){
					flag = windows[index]->fillWindow(value);
				}else{
					bigwindow[index] = combineWindows(windows,index);
					flag = false;
					index++;
				}
			}

			PARALIST *pl = re->GetParaList();

			updateParas1(pl,bigwindow);
			for(int y=0;y<timesize;y++)
			{
				delete bigwindow[y];
			}
			reasonRules(re,parser);
		}

		for(int i=0;i<timesize;i++){
			delete windows[i];
		}


		auto finish = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsed = finish - start;
		cout<<"elapsed time: "<<elapsed.count()<<" s"<<endl;
*/

		/* *********************
		* Scheme with optimize *
		********************* */

		auto start = chrono::high_resolution_clock::now();

		window* windowslice;
		deque<double>* tmpdq;

		double buffer[26] = {0};
		size_t buffersize = sizeof(buffer)/sizeof(double);
		double maxbuffer[26] = {0};
		double minbuffer[26] = {0};
		//double meanbuffer[26] = {0};
		//double varbuffer[26] = {0};
		double maxindex[13] = {0,2,4,6,8,10,12,14,16,18,20,22,24};
		double minindex[13] = {1,3,5,7,9,11,13,15,17,19,21,23,25};
		//double meanindex[8] = {2,5,8,11,14,17,20,23};
		//double varindex[10] = {3,7,11,15,19,23,27,31,35,39};

	 	for(int k=0;k<1;k++)
		{   
			int index = 0;
			double tmpscale = 0;
			timescale = timeseries[0] - tmpscale;
			tmpscale = timeseries[0];
			windowslice = new window(samplingFreq,timescale);
			while(1)
			{
				value = genRandData(0.7,1.5);
				if(!flag){
					flag = windowslice->fillWindow(value);
				}else{
					maxbuffer[index] = GetMax(windowslice->getData());
					minbuffer[index] = GetMin(windowslice->getData());
					//meanbuffer[index] = GetMean(windowslice->getData());
					//varbuffer[index] = GetVar(windowslice->getData());
					flag = false;
					index++;
					delete windowslice;
					if(index == timesize)
					{
						break;
					}
					timescale = timeseries[index]-tmpscale;
					tmpscale = timeseries[index];
					windowslice = new window(samplingFreq,timescale);
				}
			}
			
			//makebuffer4(buffer,maxindex,maxbuffer,minindex,minbuffer,meanindex,meanbuffer,varindex,varbuffer,11,11,10,10);
			//makebuffer3(buffer,maxindex,maxbuffer,minindex,minbuffer,meanindex,meanbuffer,9,9,8);
			makebuffer(buffer,maxindex,maxbuffer,minindex,minbuffer,13,13);
			//makebuffer1(buffer,minindex,minbuffer,10);

			PARALIST *pl = re->GetParaList();

			updateParas2(pl,buffer);

			reasonRules(re,parser);

		}
		auto finish = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsed = finish - start;
		cout<<"elapsed time: "<<elapsed.count()<<" s"<<endl;


        /* track memory usage. */
		int tSize = 0, resident = 0, share = 0;
    	ifstream fbuffer("/proc/self/statm");
    	fbuffer >> tSize >> resident >> share;
    	fbuffer.close();

    	long page_size_kb = sysconf(_SC_PAGE_SIZE) / 1024; // in case x86-64 is configured to use 2MB pages
    	double rss = resident * page_size_kb;
    	cout << "RSS - " << rss << " kB\n";

    	double shared_mem = share * page_size_kb;
    	cout << "Shared Memory - " << shared_mem << " kB\n";

    	cout << "Private Memory - " << rss - shared_mem << "kB\n";


		// oriAllocator *oa = new oriAllocator(0.01,1);
		// optimize *opt = new optimize();
		// opt->setOpTable(re);
		// reshapeRulePara(re, parser, opt);
		// opt->testOp();

		// cout<<"------------after reshape------------"<<endl;
		// re->testPara();
		// re->testRule();

		// PARALIST *pl = re->GetParaList();
		/*
            PARALIST::iterator pit;
            string value;
            double dvalue=0;
            string pstring;
		*/

		//ifstream fin("data.txt");
		/*
            for(pit= pl->begin();pit!=pl->end();pit++)
            {
                    fin>> dvalue;

                    //change
                    (*pit)->SetValue(dvalue);
                    //change

                    value = ConvertToString(dvalue);
                    pstring = (*pit)->GetName() + "=" + value+"\n";
                    scan_string(pstring.c_str());
                    //cout<<"The info of para is : "<< pstring<<endl;
                    yyparse();
            }
			*/

		// while (1)
		// {
		// 	value = genRandData(0.8,1.5);
		// 	cout << "value: " << value << endl;
		// 	if (mflag)
		// 	{
		// 		// for(int index = 0;index < oa->GetInferRound();index++){
		// 		// 	updatePara(oa,pl,curIndex);
		// 		// 	reasonRules(re,parser);
		// 		// 	if(index == oa->GetInferRound()-1)
		// 		// 		rflag = true;
		// 		// }
		// 		if (curIndex == oa->GetInferRound())
		// 		{
		// 			curIndex = 0;
		// 			rflag = true;
		// 		}
		// 		if (curIndex < oa->GetInferRound())
		// 		{
		// 			updatePara(oa, pl, curIndex);
		// 			cout << "reason Rule: " << curIndex << endl;
		// 			reasonRules(re, parser);
		// 			curIndex++;
		// 		}
		// 		if (dflag && rflag)
		// 		{
		// 			cout << "loadFromDisk1" << endl;
		// 			oa->loadFromDisk();
		// 			cout << "loadFromDisk2" << endl;
		// 			dflag = false;
		// 			rflag = false;
		// 		}
		// 		// else{
		// 		// 	cout<<"appendfile1"<<endl;
		// 		// 	dflag = oa->appendFile(value);
		// 		// 	cout<<"appendfile2"<<endl;
		// 		// }
		// 	}
		// 	else
		// 	{
		// 		mflag = oa->genMemData(value);
		// 	}
		// }
		// while(1)
		// {
		// 	value = genRandData(0.7,1.5);
		// 	mflag = oa->genMemData(value);
		// 	if(mflag)
		// 		break;
		// }
		// //reasonOnce(re,parser,oa,pl);
//		auto start1 = chrono::high_resolution_clock::now();
		// for(int i=0;i<oa->GetRoundLength()*oa->GetInferRound()*100;i++){
		// 	//thread treason(reasonOnce,opt,re,parser,oa,pl);
		// 	//updateData(oa);
		// 	/*
		// 	{
		// 		unique_lock <mutex> lck(mtx);
		// 		cv.wait(lck, [] { return processed; });
		// 	}
		// 	*/
		// 	//treason.join();
		// 	value = genRandData(0.7,1.5);

		// 	if(ready)
		// 		//reasonOnce(re,parser,oa,pl);
		// 		//reasonOnceOPT(opt,re,parser,oa,pl);
		// 		//reasonOnceOPTSQL(opt,re,parser,oa,pl,db,tName);
		// 		reasonOnceSQL(re,parser,oa,pl,db,tName);
		// 	else
		// 	{
		// 		//thread tupdateData(updateData,value,oa);
		// 		thread tupdateData(updateDataSQL,to_string(value),oa,db,tName);
		// 		//cout<<"start updateDataSQL()"<<endl;
		// 		//updateDataSQL(to_string(value),oa,db,tName);
		// 		tupdateData.join();				
		// 	}
		// }
//		oriAllocator *oa1 = new oriAllocator(100,1);
//		for(int i=0;i<oa1->GetRoundLength()*1000;i++)
//		{
//			value = genRandData(0.7,1.5);
//			mflag = oa1->genMemData(value);
//			//cout<<"value: "<<value<<endl;
//			//cout<<"test1, count i: "<<i<<endl;
//			if(mflag)
//			{
//				//oa1->testMemData();
//				reasonRulesList(opt,re,parser,oa1,pl);
//				mflag = false;
//			}
//		}
//		auto finish1 = chrono::high_resolution_clock::now();
//		chrono::duration<double> elapsed1 = finish1 - start1;

		// auto start2 = chrono::high_resolution_clock::now();
		// oriAllocator *oa2 = new oriAllocator(1000,10);
		// for(int i=0;i<oa2->GetRoundLength()*1000;i++)
		// {
		// 	value = genRandData(0.7,1.5);
		// 	mflag = oa2->genMemData(value);
		// 	//cout<<"value: "<<value<<endl;
		// 	//cout<<"test2, count i: "<<i<<endl;
		// 	if(mflag)
		// 	{
		// 		//oa2->testMemData();
		// 		reasonRulesList(re,parser,oa2,pl);
		// 		mflag = false;
		// 	}
		// }
		// auto finish2 = chrono::high_resolution_clock::now();
		// chrono::duration<double> elapsed2 = finish2 - start2;

		// auto start3 = chrono::high_resolution_clock::now();
		// oriAllocator *oa3 = new oriAllocator(1000,100);
		// for(int i=0;i<oa3->GetRoundLength()*1000;i++)
		// {
		// 	value = genRandData(0.7,1.5);
		// 	mflag = oa3->genMemData(value);
		// 	//cout<<"value: "<<value<<endl;
		// 	//cout<<"test2, count i: "<<i<<endl;
		// 	if(mflag)
		// 	{
		// 		//oa2->testMemData();
		// 		reasonRulesList(re,parser,oa3,pl);
		// 		mflag = false;
		// 	}
		// }
		// auto finish3 = chrono::high_resolution_clock::now();
		// chrono::duration<double> elapsed3 = finish3 - start3;
		// cout<<"when InferRound = 1, elapsed time: "<<elapsed1.count()<<" s"<<endl;
		// cout<<"when InferRound = 10, elapsed time: "<<elapsed2.count()<<" s"<<endl;
		// cout<<"when InferRound = 100, elapsed time: "<<elapsed3.count()<<" s"<<endl;

		// while(1)
		// {
		// 	value = lo + static_cast<double>(rand())/(static_cast<double>(RAND_MAX/(hi-lo)));
		// 	cout<<"value: "<<value<<endl;
		// 	if(mflag){
		// 		break;
		// 	}else{
		// 			mflag = oa->genMemData(value);
		// 		}
		// }
		// for(int i = 0;i<oa->GetMemData()->size();i++){
		// 	updatePara(oa,pl,curIndex);
		// 	//reasonRules(re,parser);
		// 	testReason(re,parser);
		// 	sleep(3);
		// }

		delete re;
		//delete oa1;
		// delete oa2;
		// delete oa3;
		//delete opt;
		//sqlite3_close(db);
		//}
	}

	delete parser;
	return n;

	/*
    int n = -1;
    parser= new calc::calc_parser();

	double* faddress;

	vector<double> v;
	double count = 0;

    if (parser->create(0)!=1) {
        printf("Create calc_parser failed!\n");
    }
    if(argc == 2 )
    {

        ifstream fin(argv[1]);
        if(!fin)
        {
            printf("no file data!\n");
            exit(1);
        }


        else
        {
			while(!fin.eof()){
				string strbuf;
				getline(fin,strbuf);
				v.push_back(atof(strbuf.c_str()));
				count++;
			}
			faddress = &v[0];
		}
		cout<<"address:"<<faddress<<endl;
		cout<<"data:"<<endl;
		for(auto iter=v.begin();iter!=v.end();iter++)
		{
			cout<<*iter<<endl;
		}
		fin.close();
	}

	yyparse();
	delete parser;
	return n;
*/
}
