#ifndef TENSOR2
#define TENSOR2

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
class sym_tensor4;

class tensor2{
private:
	double elem[9];
public:
	//constructor1
	tensor2(){}

	//copy constructor
	tensor2( const tensor2& t ){
		elem[0] = t(0);
		elem[1] = t(1);
		elem[2] = t(2);
		elem[3] = t(3);
		elem[4] = t(4);
		elem[5] = t(5);
		elem[6] = t(6);
		elem[7] = t(7);
		elem[8] = t(8);
	}

	//initializer
	tensor2( std::initializer_list<double> init ){
		int min_sz = init.size();
		if( init.size() > 9  ){
			cout << "WARNING(sym_tensor2::sym_tensor2): size of initializer_list( " << init.size() << " ) should be 9" << endl;
			min_sz = 9;
		}
		for( int i=0; i<min_sz; i++ ){
			elem[i] = *( init.begin() + i );
		}
	}

	//assignment operator
	tensor2& operator =( const tensor2& t ){
		elem[0] = t(0);
		elem[1] = t(1);
		elem[2] = t(2);
		elem[3] = t(3);
		elem[4] = t(4);
		elem[5] = t(5);
		elem[6] = t(6);
		elem[7] = t(7);
		elem[8] = t(8);
		return *this;
	}

	//destructor
	~tensor2(){}

	//ref operator
	double& operator()( int i ){
		if( i >= 9 ){
			cout << "ERROR(tensor2::operator()): Access violation. arg: " << i << " should be less than or equal to 9" << endl;
		}
		return elem[i];
	}

	double operator()( int i  ) const{
		if( i >= 9 ){
			cout << "ERROR(tensor2::operator()): Access violation. arg: " << i << " should be less than or equal to 9" << endl;
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
		elem[6] = val;
		elem[7] = val;
		elem[8] = val;
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
		stream << "6: " << setw(width) << elem[6] << std::endl;
		stream << "7: " << setw(width) << elem[7] << std::endl;
		stream << "8: " << setw(width) << elem[8] << std::endl;
		stream.unsetf( std::ios::scientific );
	}

	void show_in_mat( std::ostream& stream=std::cout, int width=15, int dec=5 ) const{
		stream << scientific << setprecision( dec );
		stream << setw(width) << elem[0];
		stream << setw(width) << elem[1];
		stream << setw(width) << elem[2] << std::endl;
		stream << setw(width) << elem[3];
		stream << setw(width) << elem[4];
		stream << setw(width) << elem[5] << std::endl;
		stream << setw(width) << elem[6];
		stream << setw(width) << elem[7];
		stream << setw(width) << elem[8] << std::endl;
		stream.unsetf( std::ios::scientific );
	}

	//static func
	static tensor2 zero(){
		tensor2 t;
		for( int i=0; i<9; i++ ) t(i) = 0.0;
		return t;
	}

	static tensor2 constant( const double val ){
		tensor2 t;
		for( int i=0; i<9; i++ ) t(i) = val;
		return t;
	}

	static tensor2 delta(){
		tensor2 del;
		del(0) = del(4) = del(8) = 1.0;
		del(1) = del(2) = del(3) = del(5) = del(6) = del(7) = 0.0;
		return del;
	}

	//unary operators
	tensor2& operator += ( const tensor2& t ){
		elem[0] += t(0);
		elem[1] += t(1);
		elem[2] += t(2);
		elem[3] += t(3);
		elem[4] += t(4);
		elem[5] += t(5);
		elem[6] += t(6);
		elem[7] += t(7);
		elem[8] += t(8);
		return *this;
	}
	tensor2& operator += ( const double s ){
		for( int i=0; i<9; i++ ) elem[i] += s;
		return *this;
	}
	tensor2& operator -= ( const tensor2& t ){
		for( int i=0; i<9; i++ ) elem[i] -= t(i);
		return *this;
	}
	tensor2& operator -= ( const double s ){
		for( int i=0; i<9; i++ ) elem[i] -= s;
		return *this;
	}
	tensor2& operator *= ( const double s ){
		for( int i=0; i<9; i++ ) elem[i] *= s;
		return *this;
	}
	tensor2& operator /= ( const double s ){
		for( int i=0; i<9; i++ ) elem[i] /= s;
		return *this;
	}
	tensor2 operator - () const{
		tensor2 ret;
		for( int i=0; i<9; i++ ) ret(i) = -elem[i];
		return ret;
	}

	bool operator == ( const tensor2& t ) const{
		bool ret = true;
		for( int i=0; i<9; i++ ){
			if( elem[i] != t(i) ) ret = false;
		}
		return ret;
	}
	bool operator != ( const tensor2& t ) const{
		return !(*this == t );
	}

	//tensor operators
	double trace() const;
	double norm() const;
	double det() const;
	tensor2 inverse() const;
	tensor2 deviatoric() const;
	tensor2 transpose() const;
	double I1() const;
	double I2() const;
	double I3() const;
	tensor1 dot_prdct( const tensor1& v ) const;
	tensor2 dot_prdct( const tensor2& t ) const;
	double dbdot_prdct( const tensor2& t ) const;
	sym_tensor2 symmetrize() const;

};

//Binary operators
tensor2 operator +( const tensor2& t1, const tensor2& t2 );
tensor2 operator -( const tensor2& t1, const tensor2& t2 );
tensor2 operator *( const double s, const tensor2& t );
tensor2 operator *( const tensor2& t, const double s );
tensor2 operator /( const tensor2& t, const double s );

}

#endif