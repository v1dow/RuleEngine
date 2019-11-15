/* This demo demonstrates how to randomly generate data for reasoning and reading data from file for reasoning. */
/* This demo applies to the inference of using a single piece of data,and cannot reason simultaneously for multiple data. */
#include "func.h"

extern reason* re;

extern calc::calc_parser *parser;

int main(int argc, char *argv[])
{
	int n = -1;

	/* calc_parser is a class contains all kinds of calculation operations. The result of reasoning work also can be find in parser*/
	parser = new calc::calc_parser();


	if (parser->create(0) != 1)
	{
		printf("Create calc_parser failed!\n");
	}

	if (argc == 1)
	{
		cout << "reasoning with random data:"
			 << "(3 seconds apart)" << endl
			 << endl
			 << endl;
		sleep(3);

		/* all reason work prepared in class reason, 
		including read and store paras, rules and 
		some reason related works */
		reason *re = new reason();
		/* read and store paras and rules from files */
		re->InitReasonNetwork();

		srand((unsigned)time(NULL));
		/* scan and assign paras */
		initReasonwork(re, parser);

		while (1)
		{
			cout << "************" << endl;
			/* generate random data */
			dataProduce(re);
			//reasonIndeRules(re, parser);
			//reasonNestedRules(re, parser);
			/* scan rules and reason with data */
			reasonRules(re,parser);

			cout << "************" << endl
				 << endl
				 << endl;


			sleep(3);
		}
		delete re;
	}
	/* reason with data from file */
	if (argc == 2)
	{
		ifstream fin(argv[1]);
        if(!fin)
        {
            printf("no file data!\n");
            exit(1);
        }


        else
        {
            cout<<"read data from file"<<endl;
            sleep(1);

            reason *re = new reason();
            re->InitReasonNetwork();
            initReasonwork(re,parser);

			/* get list of paras */
            PARALIST *pl = re->GetParaList();
            PARALIST::iterator pit;
            string value;
            double dvalue=0;
            string pstring;

            ifstream fin("data.txt");
            for(pit= pl->begin();pit!=pl->end();pit++)
            {
                    fin>> dvalue;

					/*  set value for para */
                    (*pit)->SetValue(dvalue);

                    value = ConvertToString(dvalue);
                    pstring = (*pit)->GetName() + "=" + value+"\n";
					/* scan and assign para */
                    scan_string(pstring.c_str());
                    //cout<<"The info of para is : "<< pstring<<endl;
                    yyparse();
            }

            //reasonIndeRules(re,parser);
            //reasonNestedRules(re,parser);
			reasonRules(re,parser);

//            for(pit= pl->begin();pit!=pl->end();pit++)
//            {

//                cout<<(*pit)->GetName()<<":"<<(*pit)->GetValue()<<endl;
//            }

            cout<<"************"<<endl<<endl;
            //delete pl;
            delete re;

            fin.close();
        }
	}

	delete parser;
	return n;
}
