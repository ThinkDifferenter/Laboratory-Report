//#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <vector>


using namespace std;

void InitBinFun();
int CalBinFitness(int *pX);
int CalBinFitness(vector<int> vecx);
void ExitBinFun();


