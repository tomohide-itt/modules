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
public:
	double elem[36];

	//constructor1
	sym_tensor4(){}

	//copy constructor
	sym_tensor4( const sym_tensor4& t ){
		for( int i=0; i<36; i++ ){
			elem[i] = t.elem[i];
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
			elem[i] = t.elem[i];
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
	void show( std::ostream& stream=std::cout, int width=15, int dec=5 ){
		static_cast<const sym_tensor4*>(this)->show(stream,width,dec);
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
	void show_in_mat( std::ostream& stream=std::cout, int width=15, int dec=5 ){
		static_cast<const sym_tensor4*>(this)->show_in_mat(stream,width,dec);
	}

	//static func
	static sym_tensor4 zero(){
		sym_tensor4 t;
		t.elem[ 0] = 0.0; t.elem[ 1] = 0.0; t.elem[ 2] = 0.0; t.elem[ 3] = 0.0; t.elem[ 4] = 0.0; t.elem[ 5] = 0.0;
		t.elem[ 6] = 0.0; t.elem[ 7] = 0.0; t.elem[ 8] = 0.0; t.elem[ 9] = 0.0; t.elem[10] = 0.0; t.elem[11] = 0.0;
		t.elem[12] = 0.0; t.elem[13] = 0.0; t.elem[14] = 0.0; t.elem[15] = 0.0; t.elem[16] = 0.0; t.elem[17] = 0.0;
		t.elem[18] = 0.0; t.elem[19] = 0.0; t.elem[20] = 0.0; t.elem[21] = 0.0; t.elem[22] = 0.0; t.elem[23] = 0.0;
		t.elem[24] = 0.0; t.elem[25] = 0.0; t.elem[26] = 0.0; t.elem[27] = 0.0; t.elem[28] = 0.0; t.elem[29] = 0.0;
		t.elem[30] = 0.0; t.elem[31] = 0.0; t.elem[32] = 0.0; t.elem[33] = 0.0; t.elem[34] = 0.0; t.elem[35] = 0.0;
		return t;
	}

	static sym_tensor4 constant( const double val ){
		sym_tensor4 t;
		t.elem[ 0] = val; t.elem[ 1] = val; t.elem[ 2] = val; t.elem[ 3] = val; t.elem[ 4] = val; t.elem[ 5] = val;
		t.elem[ 6] = val; t.elem[ 7] = val; t.elem[ 8] = val; t.elem[ 9] = val; t.elem[10] = val; t.elem[11] = val;
		t.elem[12] = val; t.elem[13] = val; t.elem[14] = val; t.elem[15] = val; t.elem[16] = val; t.elem[17] = val;
		t.elem[18] = val; t.elem[19] = val; t.elem[20] = val; t.elem[21] = val; t.elem[22] = val; t.elem[23] = val;
		t.elem[24] = val; t.elem[25] = val; t.elem[26] = val; t.elem[27] = val; t.elem[28] = val; t.elem[29] = val;
		t.elem[30] = val; t.elem[31] = val; t.elem[32] = val; t.elem[33] = val; t.elem[34] = val; t.elem[35] = val;
		return t;
	}

	static sym_tensor4 idn(){
		sym_tensor4 idn;
		idn.elem[ 0] = 1.0; idn.elem[ 1] = 0.0; idn.elem[ 2] = 0.0; idn.elem[ 3] = 0.0; idn.elem[ 4] = 0.0; idn.elem[ 5] = 0.0;
		idn.elem[ 6] = 0.0; idn.elem[ 7] = 1.0; idn.elem[ 8] = 0.0; idn.elem[ 9] = 0.0; idn.elem[10] = 0.0; idn.elem[11] = 0.0;
		idn.elem[12] = 0.0; idn.elem[13] = 0.0; idn.elem[14] = 1.0; idn.elem[15] = 0.0; idn.elem[16] = 0.0; idn.elem[17] = 0.0;
		idn.elem[18] = 0.0; idn.elem[19] = 0.0; idn.elem[20] = 0.0; idn.elem[21] = 0.5; idn.elem[22] = 0.0; idn.elem[23] = 0.0;
		idn.elem[24] = 0.0; idn.elem[25] = 0.0; idn.elem[26] = 0.0; idn.elem[27] = 0.0; idn.elem[28] = 0.5; idn.elem[29] = 0.0;
		idn.elem[30] = 0.0; idn.elem[31] = 0.0; idn.elem[32] = 0.0; idn.elem[33] = 0.0; idn.elem[34] = 0.0; idn.elem[35] = 0.5;
		return idn;
	}

	//unary operators
	sym_tensor4& operator += ( const sym_tensor4& t ){
		for( int i=0; i<36; i++ ) elem[i] += t.elem[i];
		return *this;
	}
	sym_tensor4& operator += ( const double s ){
		for( int i=0; i<36; i++ ) elem[i] += s;
		return *this;
	}
	sym_tensor4& operator -= ( const sym_tensor4& t ){
		for( int i=0; i<36; i++ ) elem[i] -= t.elem[i];
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
			if( elem[i] != t.elem[i] ) ret = false;
		}
		return ret;
	}
	bool operator != ( const sym_tensor4& t ) const{
		return !(*this == t );
	}

	//tensor operators
	sym_tensor4 dot_prdct( const sym_tensor2& t ) const;
	sym_tensor4 dot_prdct( const sym_tensor2& t );
	sym_tensor4 dbdot_prdct( const sym_tensor4& t ) const;
	sym_tensor4 dbdot_prdct( const sym_tensor4& t );
	sym_tensor2 dbdot_prdct( const sym_tensor2& t ) const;
	sym_tensor2 dbdot_prdct( const sym_tensor2& t );

};

//Binary operators
sym_tensor4 operator +( const sym_tensor4& t1, const sym_tensor4& t2 );
sym_tensor4 operator -( const sym_tensor4& t1, const sym_tensor4& t2 );
sym_tensor4 operator *( const double s, const sym_tensor4& t );
sym_tensor4 operator *( const sym_tensor4& t, const double s );
sym_tensor4 operator /( const sym_tensor4& t, const double s );

}

#endif