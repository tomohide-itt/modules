#ifndef SYM_TENSOR4
#define SYM_TENSOR4

#include <iostream>
#include <iomanip>
#include <cmath>
#include <initializer_list>
using std::cout;
using std::endl;
using std::scientific;
using std::setprecision;
using std::setw;

namespace tens{

class tensor1;
class sym_tensor2;

class sym_tensor4{
private:
	double elem[36];
public:
	//constructor1
	sym_tensor4(){}

	//copy constructor
	sym_tensor4( const sym_tensor4& t ){
		for( int i=0; i<36; i++ ){
			elem[i] = t(i);
		}
	}

	//initializer
	sym_tensor4( std::initializer_list<double> init ){
		int min_sz = init.size();
		if( init.size() > 36  ){
			cout << "WARNING(sym_tensor4::sym_tensor4): size of initializer_list( " << init.size() << " ) should be 36" << endl;
			min_sz = 36;
		}
		for( int i=0; i<min_sz; i++ ){
			elem[i] = *( init.begin() + i );
		}
	}

	//assignment operator
	sym_tensor4& operator =( const sym_tensor4& t ){
		for( int i=0; i<36; i++ ){
			elem[i] = t(i);
		}
		return *this;
	}

	//destructor
	~sym_tensor4(){}

	//ref operator
	double& operator()( int i ){
		if( i >= 36 ){
			cout << "ERROR(sym_tensor4::operator()): Access violation. arg: " << i << " should be less than or equal to 36" << endl;
		}
		return elem[i];
	}

	double operator()( int i  ) const{
		if( i >= 36 ){
			cout << "ERROR(sym_tensor4::operator()): Access violation. arg: " << i << " should be less than or equal to 36" << endl;
		}
		return elem[i];
	}

	//assignment func
	void fill( double val ){
		for( int i=0; i<36; i++ ){
			elem[i] = val;
		}
	}

	//display elements
	void show( std::ostream& stream=std::cout, int width=15, int dec=5 ) const{
		stream << scientific << setprecision( dec );
		for( int i=0; i<36; i++ ){
			stream << setw(2) << i << ": " << setw(width) << this->operator()(i) << std::endl;
		}
		stream.unsetf( std::ios::scientific );
	}

	void show_in_mat( std::ostream& stream=std::cout, int width=15, int dec=5 ) const{
		stream << scientific << setprecision( dec );
		for( int i=0; i<6; i++ ){
			stream << setw(width) << elem[i*6+0];
			stream << setw(width) << elem[i*6+1];
			stream << setw(width) << elem[i*6+2];
			stream << setw(width) << elem[i*6+3];
			stream << setw(width) << elem[i*6+4];
			stream << setw(width) << elem[i*6+5] << std::endl;
		}
		stream.unsetf( std::ios::scientific );
	}

	//static func
	static sym_tensor4 zero(){
		sym_tensor4 t;
		for( int i=0; i<36; i++ ){
			t(i) = 0.0;
		}
		return t;
	}

	static sym_tensor4 constant( const double val ){
		sym_tensor4 t;
		for( int i=0; i<36; i++ ){
			t(i) = val;
		}
		return t;
	}

	static sym_tensor4 idn(){
		sym_tensor4 idn;
		idn( 0) = 1.0; idn( 1) = 0.0; idn( 2) = 0.0; idn( 3) = 0.0; idn( 4) = 0.0; idn( 5) = 0.0;
		idn( 6) = 0.0; idn( 7) = 1.0; idn( 8) = 0.0; idn( 9) = 0.0; idn(10) = 0.0; idn(11) = 0.0;
		idn(12) = 0.0; idn(13) = 0.0; idn(14) = 1.0; idn(15) = 0.0; idn(16) = 0.0; idn(17) = 0.0;
		idn(18) = 0.0; idn(19) = 0.0; idn(20) = 0.0; idn(21) = 0.5; idn(22) = 0.0; idn(23) = 0.0;
		idn(24) = 0.0; idn(25) = 0.0; idn(26) = 0.0; idn(27) = 0.0; idn(28) = 0.5; idn(29) = 0.0;
		idn(30) = 0.0; idn(31) = 0.0; idn(32) = 0.0; idn(33) = 0.0; idn(34) = 0.0; idn(35) = 0.5;
		return idn;
	}

	//unary operators
	sym_tensor4& operator += ( const sym_tensor4& t ){
		for( int i=0; i<36; i++ ) elem[i] += t(i);
		return *this;
	}
	sym_tensor4& operator += ( const double s ){
		for( int i=0; i<36; i++ ) elem[i] += s;
		return *this;
	}
	sym_tensor4& operator -= ( const sym_tensor4& t ){
		for( int i=0; i<36; i++ ) elem[i] -= t(i);
		return *this;
	}
	sym_tensor4& operator -= ( const double s ){
		for( int i=0; i<36; i++ ) elem[i] -= s;
		return *this;
	}
	sym_tensor4& operator *= ( const double s ){
		for( int i=0; i<36; i++ ) elem[i] *= s;
		return *this;
	}
	sym_tensor4& operator /= ( const double s ){
		for( int i=0; i<36; i++ ) elem[i] /= s;
		return *this;
	}
	sym_tensor4 operator - () const{
		sym_tensor4 ret;
		for( int i=0; i<36; i++ ) ret(i) = -elem[i];
		return ret;
	}

	bool operator == ( const sym_tensor4& t ) const{
		bool ret = true;
		for( int i=0; i<36; i++ ){
			if( elem[i] != t(i) ) ret = false;
		}
		return ret;
	}
	bool operator != ( const sym_tensor4& t ) const{
		return !(*this == t );
	}

	//tensor operators
	sym_tensor4 dot_prdct( const sym_tensor2& t ) const;
	sym_tensor4 dbdot_prdct( const sym_tensor4& t ) const;
	sym_tensor2 dbdot_prdct( const sym_tensor2& t ) const;

};

//Binary operators
sym_tensor4 operator +( const sym_tensor4& t1, const sym_tensor4& t2 );
sym_tensor4 operator -( const sym_tensor4& t1, const sym_tensor4& t2 );
sym_tensor4 operator *( const double s, const sym_tensor4& t );
sym_tensor4 operator *( const sym_tensor4& t, const double s );
sym_tensor4 operator /( const sym_tensor4& t, const double s );

}

#endif