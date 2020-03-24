#ifndef SYM_TENSOR2
#define SYM_TENSOR2

#include <iostream>
#include <iomanip>
#include <cmath>
#include <initializer_list>
using std::cout;
using std::endl;
using std::scientific;
using std::setprecision;
using std::setw;
using std::ios_base;

namespace tens{

class tensor1;
class tensor2;
class sym_tensor4;

class sym_tensor2{
private:
	double elem[6];
public:

	//constructor1
	sym_tensor2(){}

	//copy constructor
	sym_tensor2( const sym_tensor2& t ){
		elem[0] = t(0);
		elem[1] = t(1);
		elem[2] = t(2);
		elem[3] = t(3);
		elem[4] = t(4);
		elem[5] = t(5);
	}

	//initializer
	sym_tensor2( std::initializer_list<double> init ){
		int min_sz = init.size();
		if( init.size() > 6  ){
			cout << "WARNING(sym_tensor2::sym_tensor2): size of initializer_list( " << init.size() << " ) should be 6" << endl;
			min_sz = 3;
		}
		for( int i=0; i<min_sz; i++ ){
			elem[i] = *( init.begin() + i );
		}
	}

	//assignment operator
	sym_tensor2& operator =( const sym_tensor2& t ){
		elem[0] = t(0);
		elem[1] = t(1);
		elem[2] = t(2);
		elem[3] = t(3);
		elem[4] = t(4);
		elem[5] = t(5);
		return *this;
	}

	//destructor
	~sym_tensor2(){}

	//ref operator
	double& operator()( int i ){
		if( i >= 6 ){
			cout << "ERROR(sym_tensor2::operator()): Access violation. arg: " << i << " should be less than or equal to 6" << endl;
		}
		return elem[i];
	}

	double operator()( int i  ) const{
		if( i >= 6 ){
			cout << "ERROR(sym_tensor2::operator()): Access violation. arg: " << i << " should be less than or equal to 6" << endl;
		}
		return elem[i];
	}

	//assignment func
	void fill( double val ){
		elem[0] = val;
		elem[1] = val;
		elem[2] = val;
		elem[3] = val;
		elem[4] = val;
		elem[5] = val;
	}

	//display elements
	void show( std::ostream& stream=std::cout, int width=15, int dec=5 ) const{
		stream << scientific << setprecision( dec );
		stream << "0: " << setw(width) << elem[0] << std::endl;
		stream << "1: " << setw(width) << elem[1] << std::endl;
		stream << "2: " << setw(width) << elem[2] << std::endl;
		stream << "3: " << setw(width) << elem[3] << std::endl;
		stream << "4: " << setw(width) << elem[4] << std::endl;
		stream << "5: " << setw(width) << elem[5] << std::endl;
		stream.unsetf( std::ios::scientific );
	}

	void show_in_mat( std::ostream& stream=std::cout, int width=15, int dec=5 ) const{
		stream << scientific << setprecision( dec );
		stream << setw(width) << elem[0];
		stream << setw(width) << elem[3];
		stream << setw(width) << elem[5] << std::endl;
		stream << setw(width) << elem[3];
		stream << setw(width) << elem[1];
		stream << setw(width) << elem[4] << std::endl;
		stream << setw(width) << elem[5];
		stream << setw(width) << elem[4];
		stream << setw(width) << elem[2] << std::endl;
		stream.unsetf( std::ios::scientific );
	}

	//static func
	static sym_tensor2 zero(){
		sym_tensor2 t;
		t(0) = t(1) = t(2) = t(3) = t(4) = t(5) = 0.0;
		return t;
	}

	static sym_tensor2 constant( const double val ){
		sym_tensor2 t;
		t(0) = t(1) = t(2) = t(3) = t(4) = t(5) = val;
		return t;
	}

	static sym_tensor2 delta(){
		sym_tensor2 del;
		del(0) = del(1) = del(2) = 1.0;
		del(3) = del(4) = del(5) = 0.0;
		return del;
	}

	//unary operators
	sym_tensor2& operator += ( const sym_tensor2& t ){
		elem[0] += t(0);
		elem[1] += t(1);
		elem[2] += t(2);
		elem[3] += t(3);
		elem[4] += t(4);
		elem[5] += t(5);
		return *this;
	}
	sym_tensor2& operator += ( const double s ){
		for( int i=0; i<6; i++ ) elem[i] += s;
		return *this;
	}
	sym_tensor2& operator -= ( const sym_tensor2& t ){
		elem[0] -= t(0);
		elem[1] -= t(1);
		elem[2] -= t(2);
		elem[3] -= t(3);
		elem[4] -= t(4);
		elem[5] -= t(5);
		return *this;
	}
	sym_tensor2& operator -= ( const double s ){
		elem[0] -= s;
		elem[1] -= s;
		elem[2] -= s;
		elem[3] -= s;
		elem[4] -= s;
		elem[5] -= s;
		return *this;
	}
	sym_tensor2& operator *= ( const double s ){
		for( int i=0; i<6; i++ ) elem[i] *= s;
		return *this;
	}
	sym_tensor2& operator /= ( const double s ){
		for( int i=0; i<6; i++ ) elem[i] /= s;
		return *this;
	}
	sym_tensor2 operator - () const{
		sym_tensor2 ret;
		ret(0) = -elem[0];
		ret(1) = -elem[1];
		ret(2) = -elem[2];
		ret(3) = -elem[3];
		ret(4) = -elem[4];
		ret(5) = -elem[5];
		return ret;
	}

	bool operator == ( const sym_tensor2& t ) const{
		bool ret = true;
		for( int i=0; i<6; i++ ){
			if( elem[i] != t(i) ) ret = false;
		}
		return ret;
	}
	bool operator != ( const sym_tensor2& t ) const{
		return !(*this == t );
	}

	//tensor operators
	double trace() const;
	double norm() const;
	double det() const;
	sym_tensor2 inverse() const;
	sym_tensor2 deviatoric() const;
	double p() const;
	sym_tensor2 s() const;
	double q() const;
	sym_tensor2 ehta() const;
	double I1() const;
	double I2() const;
	double I3() const;
	double J2() const;
	double ehta_star( const sym_tensor2& sig0 ) const;
	double ehta_rot( const sym_tensor2& ehta0 ) const;
	sym_tensor2 s_bar( const sym_tensor2& sig0 ) const;
	sym_tensor2 n_bar( const sym_tensor2& sig0 ) const;
	double q_bar( const sym_tensor2& sig0 ) const;
	double epsv() const;
	sym_tensor2 epsd() const;
	double epss() const;
	tensor1 dot_prdct( const tensor1& v ) const;
	sym_tensor2 dot_prdct( const sym_tensor2& t ) const;
	sym_tensor4 dot_prdct( const sym_tensor4& t ) const;
	sym_tensor4 tens_prdct( const sym_tensor2& t ) const;
	double dbdot_prdct( const sym_tensor2& t ) const;
	sym_tensor2 dbdot_prdct( const sym_tensor4& t ) const;
	sym_tensor4 sum_prdct( const sym_tensor2& t ) const;
	sym_tensor4 det_prdct( const sym_tensor2& t ) const;
	tensor2 asymmetrize() const;

};

//Binary operators
sym_tensor2 operator +( const sym_tensor2& t1, const sym_tensor2& t2 );
sym_tensor2 operator -( const sym_tensor2& t1, const sym_tensor2& t2 );
sym_tensor2 operator *( const double s, const sym_tensor2& t );
sym_tensor2 operator *( const sym_tensor2& t, const double s );
sym_tensor2 operator /( const sym_tensor2& t, const double s );

}

#endif