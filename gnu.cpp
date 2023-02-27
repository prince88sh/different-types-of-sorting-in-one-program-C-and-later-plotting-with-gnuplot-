#include <stdio.h>
#include<iostream>

using namespace std;

int main()
{
	FILE* gnupipe = NULL;
    const char* commands[] ={"set title \"Bubble Sort\"", "plot 'bubble_sort.txt' with lines"};
	gnupipe = popen("gnuplot -persistent", "w");
	for(int i=0; i<2;i++){
    fprintf(gnupipe, "%s\n", commands[i]);
	return 0;
        }
}


