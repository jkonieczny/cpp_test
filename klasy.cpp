#include <iostream>
#include <conio.h>

using namespace std;

class Ulamek
 {
	int l;
	int m;
public:
    Ulamek(int=0, int=0);	
       void wypisz()
 {
        	cout << l <<"/"<< m << endl;
 }
    void mnoz(Ulamek&);
    Ulamek mnoz2(Ulamek&);
    void dodaj(Ulamek&);
    void normalizuj(); //alg.Euklidesa
    float toFloat();
    bool porownaj(Ulamek&);
    Ulamek(float);		
 };

Ulamek::Ulamek(int licz,int mian)
 {
	l = licz; m = mian;
 }
void Ulamek::mnoz(Ulamek& u)
 {
   l*=u.l;
   m*=u.m;
 }	

Ulamek Ulamek::mnoz2(Ulamek& u)
 {
	Ulamek t(0,0);
	t.l=l*u.l;
	t.m=m*u.m;
return t;
 }
 void  Ulamek::dodaj(Ulamek& u)
 {
	l = l*u.m +u.l*m;
	m *= u.m; 
	
 }
void Ulamek::normalizuj()
{
		
}
int main()
{
	Ulamek ul(2,3), ul1(1,3), ul2(1);


	ul.wypisz(); 	
	ul.mnoz(ul1);
	ul.wypisz();
	ul2=ul.mnoz2(ul2);
	ul2.wypisz();
	ul.dodaj(ul);	
	ul.wypisz();
	ul.normalizuj();
getch();
return 0;

}



