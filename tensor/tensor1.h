#ifndef TENSOR1
#define TENSOR1

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

class sym_tensor2;
class tensor2;

class tensor1{
private:
	double elem[3];
public:
	//constructor1
	tensor1(){}

	//copy constructor
	tensor1( const tensor1& t ){
		elem[0] = t.elem[0];
		elem[1] = t.elem[1];
		elem[2] = t.elem[2];
	}

	//initializer
	tensor1( std::initializer_list<double> init ){
		int min_sz = init.size();
		if( init.size() > 3  ){
			cout << "WARNING(tensor1::tensor1): size of initializer_list( " << init.size() << " ) should be 3" << endl;
			min_sz = 3;
		}
		for( int i=0; i<min_sz; i++ ){
			elem[i] = *( init.begin() + i );
		}
	}

	//assignment operator
	tensor1& operator =( const tensor1& t ){
		elem[0] = t(0);
		elem[1] = t(1);
		elem[2] = t(2);
		return *this;
	}

	//destructor
	~tensor1(){}

	//ref operator
	double& operator()( int i ){
		if( i >= 3 || i < 0 ){
			cout << "ERROR(tensor1::operator()): Access violation. arg: " << i << " should be less than or equal to 3" << endl;
		}
		return elem[i];
	}

	double operator()( int i  ) const{
		if( i >= 3 || i < 0 ){
			cout << "ERROR(tensor1::operator()): Access violation. arg: " << i << " should be less than or equal to 3" << endl;
		}
		return elem[i];
	}

	//assignment func
	void fill( double val ){
		elem[0] = val;
		elem[1] = val;
		elem[2] = val;
	}

	//display elements
	void show( std::ostream& stream=std::cout, int width=15, int dec=5 ) const{
		stream << scientific << setprecision( dec );
		for( int i=0; i<3; i++ ){
			stream << setw(2) << i << ": " << setw(width) << elem[i] << std::endl;
		}
		stream.unsetf( std::ios::scientific );
	}

	void show_in_mat( std::ostream& stream=std::cout, int width=15, int dec=5 ) const{
		stream << scientific << setprecision( dec );
		stream << setw(width) << elem[0];
		stream << setw(width) << elem[1];
		stream << setw(width) << elem[2] << std::endl;
		stream.unsetf( std::ios::scientific );
	}

	//static func
	static tensor1 zero(){
		tensor1 t;
		t(0) = t(1) = t(2) = 0.0;
		return t;
	}

	static tensor1 constant( const double val ){
		tensor1 t;
		t(0) = t(1) = t(2) = val;
		return t;
	}

	//unary operators
	tensor1& operator += ( const tensor1& t ){
		elem[0] += t(0);
		elem[1] += t(1);
		elem[2] += t(2);
		return *this;
	}
	tensor1& operator += ( const double s ){
		for( int i=0; i<3; i++ ) elem[i] += s;
		return *this;
	}
	tensor1& operator -= ( const tensor1& t ){
		elem[0] -= t(0);
		elem[1] -= t(1);
		elem[2] -= t(2);
		return *this;
	}
	tensor1& operator -= ( const double s ){
		for( int i=0; i<3; i++ ) elem[i] -= s;
		return *this;
	}
	tensor1& operator *= ( const double s ){
		for( int i=0; i<3; i++ ) elem[i] *= s;
		return *this;
	}
	tensor1& operator /= ( const double s ){
		for( int i=0; i<3; i++ ) elem[i] /= s;
		return *this;
	}
	tensor1 operator - () const{
		tensor1 ret;
		ret(0) = -elem[0];
		ret(1) = -elem[1];
		ret(2) = -elem[2];
		return ret;
	}

	bool operator == ( const tensor1& v ) const{
		bool ret = true;
		for( int i=0; i<3; i++ ){
			if( elem[i] != v(i) ) ret = false;
		}
		return ret;
	}
	bool operator != ( const tensor1& v ) const{
		return !(*this == v );
	}

	//tensor operators
	double norm() const;
	tensor1 vec_prdct( const tensor1& v ) const;
	double  dot_prdct( const tensor1& v ) const;
	tensor1 dot_prdct( const sym_tensor2& t2 ) const;
	tensor2 tens_prdct( const tensor1& v ) const;

};

//Binary operators
tensor1 operator +( const tensor1& v1, const tensor1& v2 );
tensor1 operator -( const tensor1& v1, const tensor1& v2 );
tensor1 operator *( const double s, const tensor1& t );
tensor1 operator *( const tensor1& t, const double s );
tensor1 operator /( const tensor1& t, const double s );

}

#endif