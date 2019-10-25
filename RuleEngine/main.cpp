#include "fun.h"

#include <sstream>
#include <fstream>
#include <stdlib.h>

extern reason* re;

int main(int argc, char* argv[])
{
    initReason();
    PARALIST *pl = re->GetParaList();
    ifstream fin("data.txt");
    double t = 3;
    UpdatePara(t, fin, pl);
    fin.close();
    return 0;
}