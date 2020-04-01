#include "structTest.h"
#include <stdio.h>
#include <string.h>

int main(void)
{

    mycar.year = 2011;
    mycar.model = "hot";
    mycar.plate = "damn";
    //strcpy (mycar.plate, "damn");
    //e.g. int x;
    //e.g. int x = 32
    
    printf("%i<-mycar.year, %s<-mycar.model, %s<-mycar.plate\n", mycar.year, mycar.model, mycar.plate);
    //printf("%i", node.number);
}