#include "tensor1.h"
#include "sym_tensor2.h"
#include "tensor2.h"
#include "sym_tensor4.h"

namespace tens{
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// trace
double tensor2::trace() const{
	return elem[0]+elem[4]+elem[8];
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// norm
double tensor2::norm() const{
	double ret = dbdot_prdct( *this );
	return std::sqrt(ret);
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// det
double tensor2::det() const{
	return elem[0]*elem[4]*elem[8]
		 + elem[1]*elem[5]*elem[6]
		 + elem[2]*elem[3]*elem[7]
		 - elem[2]*elem[4]*elem[6]
		 - elem[0]*elem[5]*elem[7]
		 - elem[1]*elem[3]*elem[8];
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// inverse
tensor2 tensor2::inverse() const{
	tensor2 ret;
	double dett = this->det();
	ret(0) = ( elem[4]*elem[8] - elem[5]*elem[7] )/dett;
	ret(1) = ( elem[2]*elem[7] - elem[1]*elem[8] )/dett;
	ret(2) = ( elem[1]*elem[5] - elem[2]*elem[4] )/dett;
	ret(3) = ( elem[5]*elem[6] - elem[3]*elem[8] )/dett;
	ret(4) = ( elem[0]*elem[8] - elem[2]*elem[6] )/dett;
	ret(5) = ( elem[2]*elem[3] - elem[0]*elem[5] )/dett;
	ret(6) = ( elem[3]*elem[7] - elem[4]*elem[6] )/dett;
	ret(7) = ( elem[1]*elem[6] - elem[0]*elem[7] )/dett;
	ret(8) = ( elem[0]*elem[4] - elem[1]*elem[3] )/dett;
	return ret;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// deviatoric
tensor2 tensor2::deviatoric() const{
	tensor2 del = tensor2::delta();
	return *this - (this->trace()/3.0)*del;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// transpose
tensor2 tensor2::transpose() const{
	tensor2 ret;
	ret(0) = elem[0];
	ret(1) = elem[3];
	ret(2) = elem[6];
	ret(3) = elem[1];
	ret(4) = elem[4];
	ret(5) = elem[7];
	ret(6) = elem[2];
	ret(7) = elem[5];
	ret(8) = elem[8];
	return ret;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// I1
double tensor2::I1() const{
	return elem[0] + elem[4] + elem[8];
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// I2
double tensor2::I2() const{
	double tr = this->trace();
	tensor2 t2 = this->dot_prdct( *this );
	double tr2 = t2.trace();
	return 0.5*(tr*tr-tr2);
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// I3
double tensor2::I3() const{
	return this->det();
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// tens2 dot vec
tensor1 tensor2::dot_prdct( const tensor1& v ) const{
	tensor1 ret;
	ret(0) = elem[0]*v(0) + elem[1]*v(1) + elem[2]*v(2);
	ret(1) = elem[3]*v(0) + elem[4]*v(1) + elem[5]*v(2);
	ret(2) = elem[6]*v(0) + elem[7]*v(1) + elem[8]*v(2);
	return ret;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// tens2 dot tens2
tensor2 tensor2::dot_prdct( const tensor2& t ) const{
	tensor2 ret;
	ret(0) = elem[0]*t(0) + elem[1]*t(3) + elem[2]*t(6);
	ret(1) = elem[0]*t(1) + elem[1]*t(4) + elem[2]*t(7);
	ret(2) = elem[0]*t(2) + elem[1]*t(5) + elem[2]*t(8);
	ret(3) = elem[3]*t(0) + elem[4]*t(3) + elem[5]*t(6);
	ret(4) = elem[3]*t(1) + elem[4]*t(4) + elem[5]*t(7);
	ret(5) = elem[3]*t(2) + elem[4]*t(5) + elem[5]*t(8);
	ret(6) = elem[6]*t(0) + elem[7]*t(3) + elem[8]*t(6);
	ret(7) = elem[6]*t(1) + elem[7]*t(4) + elem[8]*t(7);
	ret(8) = elem[6]*t(2) + elem[7]*t(5) + elem[8]*t(8);
	return ret;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// tens2 double_dot tens2
double tensor2::dbdot_prdct( const tensor2& t ) const{
	double ret;
	ret = elem[0]*t(0)
	    + elem[1]*t(1)
	    + elem[2]*t(2)
	    + elem[3]*t(3)
	    + elem[4]*t(4)
	    + elem[5]*t(5)
	    + elem[6]*t(6)
	    + elem[7]*t(7)
	    + elem[8]*t(8);
	return ret;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// symmetrize
sym_tensor2 tensor2::symmetrize() const{
	sym_tensor2 ret;
	ret(0) = elem[0];
	ret(1) = elem[4];
	ret(2) = elem[8];
	ret(3) = 0.5*( elem[1] + elem[3] );
	ret(4) = 0.5*( elem[5] + elem[7] );
	ret(5) = 0.5*( elem[2] + elem[6] );
	return ret;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// binary operators
tensor2 operator +( const tensor2& t1, const tensor2& t2 ){
	tensor2 ret;
	ret(0) = t1(0) + t2(0);
	ret(1) = t1(1) + t2(1);
	ret(2) = t1(2) + t2(2);
	ret(3) = t1(3) + t2(3);
	ret(4) = t1(4) + t2(4);
	ret(5) = t1(5) + t2(5);
	ret(6) = t1(6) + t2(6);
	ret(7) = t1(7) + t2(7);
	ret(8) = t1(8) + t2(8);
	return ret;
}

tensor2 operator -( const tensor2& t1, const tensor2& t2 ){
	tensor2 ret;
	ret(0) = t1(0) - t2(0);
	ret(1) = t1(1) - t2(1);
	ret(2) = t1(2) - t2(2);
	ret(3) = t1(3) - t2(3);
	ret(4) = t1(4) - t2(4);
	ret(5) = t1(5) - t2(5);
	ret(6) = t1(6) - t2(6);
	ret(7) = t1(7) - t2(7);
	ret(8) = t1(8) - t2(8);
	return ret;
}

tensor2 operator *( const double s, const tensor2& t ){
	tensor2 ret;
	ret(0) = s*t(0);
	ret(1) = s*t(1);
	ret(2) = s*t(2);
	ret(3) = s*t(3);
	ret(4) = s*t(4);
	ret(5) = s*t(5);
	ret(6) = s*t(6);
	ret(7) = s*t(7);
	ret(8) = s*t(8);
	return ret;
}

tensor2 operator *( const tensor2& t, const double s ){
	tensor2 ret;
	ret(0) = s*t(0);
	ret(1) = s*t(1);
	ret(2) = s*t(2);
	ret(3) = s*t(3);
	ret(4) = s*t(4);
	ret(5) = s*t(5);
	ret(6) = s*t(6);
	ret(7) = s*t(7);
	ret(8) = s*t(8);
	return ret;
}

tensor2 operator /( const tensor2& t, const double s ){
	tensor2 ret;
	ret(0) = t(0)/s;
	ret(1) = t(1)/s;
	ret(2) = t(2)/s;
	ret(3) = t(3)/s;
	ret(4) = t(4)/s;
	ret(5) = t(5)/s;
	ret(6) = t(6)/s;
	ret(7) = t(7)/s;
	ret(8) = t(8)/s;
	return ret;
}

}