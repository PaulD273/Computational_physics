//============================================================
// F i l e C i r c l e . cpp
// Cons t an t angular v e l o c i t y c i r c u l a r motion
// S e t ( x0 , y0) c e n t e r o f c i r c l e , i t s r adiu s R and omega .
// At t=t0 , the p a r t i c l e i s a t t h e t a=0
//−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
#include <iostream >
#include <fstream>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;
#define PI 3.1415926535897932
int main() {
	//−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
	// D e cl a r a ti o n o f v a r i a b l e s
	double x0 , y0 , R , x , y , vx , vy , t , t0 , tf , dt ;
	double theta , omega ;
	string buf ;
	//−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
	// Ask use r f o r inpu t :
	cout << "# Enter omega:\n";
	cin >> omega ; getline (cin , buf);
	if ( omega <=0.0)
	{
  		cerr <<" Illegal value of omega\n";
 	        exit ( 1 ) ;
	}
	cout << "# Enter center of circle (x0 , y0) and radius R:\n" ;
	cin >> x0 >> y0 >> R;  getline ( cin , buf );
	if ( R <=0.0)
	{
    		cerr <<" Illegal value of R \n" ;
                exit ( 1 ) ;
	}
	cout << "# Enter t0 , tf , dt :\n" ;
	cin >> t0 >> tf >> dt ; getline (cin ,buf) ;
	cout <<"# omega= " << omega << endl ;
	cout <<"# x0= " << x0 << " y0= " << y0 << " R= " << R << endl ;
	cout <<"# t0= " << t0 << " tf = " << tf << " dt= " << dt << endl ;
	//−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
	// Initialize

	cout << "# T= " << 2.0 * PI / omega << endl ;
	ofstream myfile ("Circle.dat");
	// Set precision for numeric output to my file to 17 digits
	myfile.precision(17);
	//−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
	// Compute :
	t = t0;
	while (t <= tf) 
	{
		theta = omega * (t−t0) ;
		x = x0+R*cos(theta);
		y = y0+R * sin(theta) ;
		vx = −omega * R * sin ( theta ) ;
		vy = omega * R * cos ( theta ) ;
		myfile << t << " " << x << " " << y << " " << vx << " " << vy << endl ;
		t = t + dt ;
	}



}
