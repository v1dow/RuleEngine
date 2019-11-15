#include "func.h"

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
		initReasonwork(re, parser);

		while (1)
		{
			cout << "************" << endl;
			dataProduce(re);
			reasonIndeRules(re, parser);
			reasonNestedRules(re, parser);

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

		int curIndex = 0;
		double value = 0;
		bool mflag = false;
		bool dflag = false;
		bool rflag = false;


		reason *re = new reason();
		re->InitReasonNetwork();
		initReasonwork(re, parser);
		oriAllocator *oa = new oriAllocator();
		optimize *opt = new optimize();
		opt->setOpTable(re);
		reshapeRulePara(re, parser, opt);
		opt->testOp();
		srand((unsigned)time(NULL));

		PARALIST *pl = re->GetParaList();
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

		while(1)
		{
			value = genRandData(0.8,1.5);
			mflag = oa->genMemData(value);
			if(mflag)
				break;
		}
		//reasonOnce(re,parser,oa,pl);
		while(1){
			//thread treason(reasonOnce,opt,re,parser,oa,pl);
			//updateData(oa);
			/*
			{
				unique_lock <mutex> lck(mtx);
				cv.wait(lck, [] { return processed; });
			}
			*/
			//treason.join();
			value = genRandData(0.7,1.5);

			if(ready)
				reasonOnce(opt,re,parser,oa,pl);
			else
			{
				thread tupdateData(updateData,value,oa);
				tupdateData.join();				
			}
		}


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