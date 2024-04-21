#include"sklepik.h"


int main()
{
    Chemia c1(100,30);
    Chemia c2(37,10);

    Sportowe s1(450,"i");
    Sportowe s2(150,"t");

    Koszyk k(123);

    k+=&c1;
    k+=&c2;
    k+=&s1;
    k+=&s2;

    cout<<k<<endl;

    k.suma();

    cout<<"\npo zmianach"<<endl;

    k-=0;

    cout<<k<<endl;

    k.suma();


    return 0;
}
