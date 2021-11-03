#include <iostream>
#include <array>
#include <fstream>
#include <iomanip>
#include "array2d.h"
#include "fieldvariable.h"
#include "staggeredgrid.h"

//#include "centraldifferences.h"

int main(){
	

std::array<int,2> size{2,2};
Array2D array2D(size);        // object of class Array2D with size 2x2

array2D(0,1) = 1.0;
double value = array2D(0,1);
std::cout << value << std::endl;

std::cout<<"Diese Funktion printed die Fieldvariable" <<std::endl;
size={5,5};
FieldVariable Test(size);
Test.print();
Test(1,1)=5;
Test.print();
std::cout<< "Maximum " << Test.max() <<std::endl;

std::array<double,2> top={1,2};
std::array<double,2> left={3,4};
std::array<double,2> right={5,6};
std::array<double,2> bottom={7,8};

StaggeredGrid testgrid(size);
testgrid.setBorderVelocity(top,left,right,bottom);

testgrid.print("velocity_x");
std::cout<< " " <<std::endl;
testgrid.print("velocity_y");

return 0;
}