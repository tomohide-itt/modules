#include "tensor1.h"
#include "sym_tensor2.h"
#include "tensor2.h"

namespace tens{
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// norm
double tensor1::norm() const{
	return std::sqrt( elem[0]*elem[0] + elem[1]*elem[1] + elem[2]*elem[2] );
}
double tensor1::norm(){
	return ( static_cast<const tensor1*>(this)->norm());
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// vec cross vec
tensor1 tensor1::vec_prdct( const tensor1& v ) const{
	tensor1 ret;
	ret.elem[0] = elem[1]*v.elem[2] - elem[2]*v.elem[1];
	ret.elem[1] = elem[2]*v.elem[0] - elem[0]*v.elem[2];
	ret.elem[2] = elem[0]*v.elem[1] - elem[1]*v.elem[0];
	return ret;
}
tensor1 tensor1::vec_prdct( const tensor1& v ){
	return ( static_cast<const tensor1*>(this)->vec_prdct(v));
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// vec dot vec
double tensor1::dot_prdct( const tensor1& t ) const{
	return t.elem[0]*elem[0] + t.elem[1]*elem[1] + t.elem[2]*elem[2];
}
double tensor1::dot_prdct( const tensor1& t ){
	return ( static_cast<const tensor1*>(this)->dot_prdct(t));
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// vec dot tens2
tensor1 tensor1::dot_prdct( const sym_tensor2& t ) const{
	tensor1 ret;
	ret.elem[0] = t.elem[0]*elem[0] + t.elem[3]*elem[1] + t.elem[5]*elem[2];
	ret.elem[1] = t.elem[3]*elem[0] + t.elem[1]*elem[1] + t.elem[4]*elem[2];
	ret.elem[2] = t.elem[5]*elem[0] + t.elem[4]*elem[1] + t.elem[2]*elem[2];
	return ret;
}
tensor1 tensor1::dot_prdct( const sym_tensor2& t ){
	return ( static_cast<const tensor1*>(this)->dot_prdct(t));
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// vec tens_prdct vec
tensor2 tensor1::tens_prdct( const tensor1& v ) const{
	tensor2 ret;
	ret.elem[0] = elem[0]*v.elem[0];
	ret.elem[1] = elem[0]*v.elem[1];
	ret.elem[2] = elem[0]*v.elem[2];
	ret.elem[3] = elem[1]*v.elem[0];
	ret.elem[4] = elem[1]*v.elem[1];
	ret.elem[5] = elem[1]*v.elem[2];
	ret.elem[6] = elem[2]*v.elem[0];
	ret.elem[7] = elem[2]*v.elem[1];
	ret.elem[8] = elem[2]*v.elem[2];
	return ret;
}
tensor2 tensor1::tens_prdct( const tensor1& v ){
	return ( static_cast<const tensor1*>(this)->tens_prdct(v) );
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// binary operators
tensor1 operator +( const tensor1& v1, const tensor1& v2 ){
	tensor1 ret;
	ret.elem[0] = v1.elem[0] + v2.elem[0];
	ret.elem[1] = v1.elem[1] + v2.elem[1];
	ret.elem[2] = v1.elem[2] + v2.elem[2];
	return ret;
}

tensor1 operator -( const tensor1& v1, const tensor1& v2 ){
	tensor1 ret;
	ret.elem[0] = v1.elem[0] - v2.elem[0];
	ret.elem[1] = v1.elem[1] - v2.elem[1];
	ret.elem[2] = v1.elem[2] - v2.elem[2];
	return ret;
}

tensor1 operator *( const double s, const tensor1& t ){
	tensor1 ret = t;
	ret.elem[0] *= s;
	ret.elem[1] *= s;
	ret.elem[2] *= s;
	return ret;
}

tensor1 operator *( const tensor1& t, const double s ){
	tensor1 ret;
	ret.elem[0] = s*t.elem[0];
	ret.elem[1] = s*t.elem[1];
	ret.elem[2] = s*t.elem[2];
	return ret;
}

tensor1 operator /( const tensor1& t, const double s ){
	tensor1 ret;
	ret.elem[0] = t.elem[0]/s;
	ret.elem[1] = t.elem[1]/s;
	ret.elem[2] = t.elem[2]/s;
	return ret;
}
}