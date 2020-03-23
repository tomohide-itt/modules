#include "tensor1.h"
#include "sym_tensor2.h"
#include "tensor2.h"

namespace tens{
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// norm
double tensor1::norm() const{
	return std::sqrt( elem[0]*elem[0] + elem[1]*elem[1] + elem[2]*elem[2] );
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// vec cross vec
tensor1 tensor1::vec_prdct( const tensor1& v ) const{
	tensor1 ret;
	ret(0) = elem[1]*v(2) - elem[2]*v(1);
	ret(1) = elem[2]*v(0) - elem[0]*v(2);
	ret(2) = elem[0]*v(1) - elem[1]*v(0);
	return ret;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// vec dot vec
double tensor1::dot_prdct( const tensor1& t ) const{
	return t(0)*elem[0] + t(1)*elem[1] + t(2)*elem[2];
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// vec dot tens2
tensor1 tensor1::dot_prdct( const sym_tensor2& t ) const{
	tensor1 ret;
	ret(0) = t(0)*elem[0] + t(3)*elem[1] + t(5)*elem[2];
	ret(1) = t(3)*elem[0] + t(1)*elem[1] + t(4)*elem[2];
	ret(2) = t(5)*elem[0] + t(4)*elem[1] + t(2)*elem[2];
	return ret;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// vec tens_prdct vec
tensor2 tensor1::tens_prdct( const tensor1& v ) const{
	tensor2 ret;
	ret(0) = elem[0]*v(0);
	ret(1) = elem[0]*v(1);
	ret(2) = elem[0]*v(2);
	ret(3) = elem[1]*v(0);
	ret(4) = elem[1]*v(1);
	ret(5) = elem[1]*v(2);
	ret(6) = elem[2]*v(0);
	ret(7) = elem[2]*v(1);
	ret(8) = elem[2]*v(2);
	return ret;
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// binary operators
tensor1 operator +( const tensor1& v1, const tensor1& v2 ){
	tensor1 ret;
	ret(0) = v1(0) + v2(0);
	ret(1) = v1(1) + v2(1);
	ret(2) = v1(2) + v2(2);
	return ret;
}

tensor1 operator -( const tensor1& v1, const tensor1& v2 ){
	tensor1 ret;
	ret(0) = v1(0) - v2(0);
	ret(1) = v1(1) - v2(1);
	ret(2) = v1(2) - v2(2);
	return ret;
}

tensor1 operator *( const double s, const tensor1& t ){
	tensor1 ret = t;
	ret(0) *= s;
	ret(1) *= s;
	ret(2) *= s;
	return ret;
}

tensor1 operator *( const tensor1& t, const double s ){
	tensor1 ret;
	ret(0) = s*t(0);
	ret(1) = s*t(1);
	ret(2) = s*t(2);
	return ret;
}

tensor1 operator /( const tensor1& t, const double s ){
	tensor1 ret;
	ret(0) = t(0)/s;
	ret(1) = t(1)/s;
	ret(2) = t(2)/s;
	return ret;
}
}