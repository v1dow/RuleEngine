#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int numrules = 5000;
	string rule1[] = {"IF MAX(#p1)<1.46 THEN p1=1",
	                  "IF MIN(#p2)<1.44 THEN p1=2",
					  "IF MAX(#p3)<1.42 THEN p1=3",
					  "IF MIN(#p4)<1.46 THEN p1=4",
					  "IF MAX(#p5)<1.44 THEN p1=5",
					  "IF MIN(#p6)<1.42 THEN p1=6",
					  "IF MAX(#p7)<1.40 THEN p1=7",
					  "IF MIN(#p8)<1.38 THEN p1=8",
					  "IF MAX(#p9)<1.36 THEN p1=9",
					  "IF MIN(#p10)<1.4 THEN p1=10",
					  "IF MAX(#p11)<1.4 THEN p1=11",
					  "IF MIN(#p12)<1.4 THEN p1=12",
	                  "IF MAX(#p13)<1.4 THEN p1=13",
                      "IF MIN(#p14)<1.4 THEN p1=14",
                      "IF MAX(#p15)<1.4 THEN p1=15",
                      "IF MIN(#p16)<1.4 THEN p1=16",
                      "IF MAX(#p17)<1.4 THEN p1=17",
                      "IF MIN(#p18)<1.4 THEN p1=18",
                      "IF MAX(#p19)<1.4 THEN p1=19",
                      "IF MIN(#p20)<1.4 THEN p1=20",
                      "IF MAX(#p21)<1.4 THEN p1=21",
	                  "IF MIN(#p22)<1.4 THEN p1=22",
	                  "IF MAX(#p23)<1.4 THEN p1=23",
	                  "IF MIN(#p24)<1.4 THEN p1=24",
	                  "IF MAX(#p25)<1.4 THEN p1=25",
	                  "IF MIN(#p26)<1.4 THEN p1=26",
					  };
	string rule2[] = {"IF p1<1.46 THEN p0=1",
					  "IF p2<1.44 THEN p0=2",
					  "IF p3<1.42 THEN p0=3",
					  "IF p4<1.46 THEN p0=4",
					  "IF p5<1.44 THEN p0=5",
					  "IF p6<1.42 THEN p0=6",
					  "IF p7<1.40 THEN p0=7",
					  "IF p8<1.40 THEN p0=8",
					  "IF p9<1.40 THEN p0=9",
					  "IF p10<1.40 THEN p0=10",
					  "IF p11<1.40 THEN p0=11",
"IF p12<1.40 THEN p0=12",
"IF p13<1.40 THEN p0=13",
"IF p14<1.40 THEN p0=14",
"IF p15<1.40 THEN p0=15",
"IF p16<1.40 THEN p0=16",
"IF p17<1.40 THEN p0=17",
"IF p18<1.40 THEN p0=18",
"IF p19<1.40 THEN p0=19",
"IF p20<1.40 THEN p0=20",
"IF p21<1.40 THEN p0=21",
"IF p22<1.40 THEN p0=22",
"IF p23<1.40 THEN p0=23",
"IF p24<1.40 THEN p0=24",
"IF p25<1.40 THEN p0=25",
"IF p26<1.40 THEN p0=26",
};
	size_t rulesize1 = sizeof(rule1)/sizeof(rule1[0]);
	size_t rulesize2 = sizeof(rule2)/sizeof(rule2[0]);
	ofstream fout1("rule11.txt");
	if(fout1.is_open())
	{
		int index = 0;
		for(int i=0;i<numrules;i++)
		{
			if(index == rulesize1)
			{
				index = 0;
			}
			fout1<<"R"<<i+1<<":"<<rule1[index]<<"\n";
			index++;
		}
	}else{
		cout<<"create file rule11.txt failed."<<endl;
	}

	fout1.close();

	ofstream fout2("rule22.txt");
	if(fout2.is_open())
	{
		int index = 0;
		for(int i=0;i<numrules;i++)
		{
			if(index == rulesize2)
			{
				index = 0;
			}
			fout2<<"R"<<i+1<<":"<<rule2[index]<<"\n";
			index++;
		}
	}else{
		cout<<"create file rule22.txt failed."<<endl;
	}

	fout2.close();

	return 0;
}
