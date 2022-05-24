#ifndef my_func_h
#define my_func_h

double* inputFromConsole(int* sizeOfData, int* x);
double* inputFromFile(int* sizeOfData, int *x, std::ifstream &fin);
char getWay();
char getTask();
double getValue();
bool getNext();
void Task(double* arr, int size, int x, std::ostream& f);
#endif 