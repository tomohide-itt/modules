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
double tensor2::trace(){
	return ( static_cast<const tensor2*>(this)->trace());
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// norm
double tensor2::norm() const{
	double ret = elem[0]*elem[0]
		       + elem[1]*elem[1]
		       + elem[2]*elem[2]
		       + elem[3]*elem[3]
		       + elem[4]*elem[4]
		       + elem[5]*elem[5]
		       + elem[6]*elem[6]
		       + elem[7]*elem[7]
		       + elem[8]*elem[8];
		return std::sqrt(ret);
}
double tensor2::norm(){
	return ( static_cast<const tensor2*>(this)->norm());
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
double tensor2::det(){
	return ( static_cast<const tensor2*>(this)->det());
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// inverse
tensor2 tensor2::inverse() const{
	tensor2 ret;
	double dett = this->det();
	ret.elem[0] = ( elem[4]*elem[8] - elem[5]*elem[7] )/dett;
	ret.elem[1] = ( elem[2]*elem[7] - elem[1]*elem[8] )/dett;
	ret.elem[2] = ( elem[1]*elem[5] - elem[2]*elem[4] )/dett;
	ret.elem[3] = ( elem[5]*elem[6] - elem[3]*elem[8] )/dett;
	ret.elem[4] = ( elem[0]*elem[8] - elem[2]*elem[6] )/dett;
	ret.elem[5] = ( elem[2]*elem[3] - elem[0]*elem[5] )/dett;
	ret.elem[6] = ( elem[3]*elem[7] - elem[4]*elem[6] )/dett;
	ret.elem[7] = ( elem[1]*elem[6] - elem[0]*elem[7] )/dett;
	ret.elem[8] = ( elem[0]*elem[4] - elem[1]*elem[3] )/dett;
	return ret;
}

tensor2 tensor2::inverse(){
	return ( static_cast<const tensor2*>(this)->inverse());
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// deviatoric
tensor2 tensor2::deviatoric() const{
	double iso = (elem[0] + elem[4] + elem[8])/3.0;
	tensor2 ret;
	ret.elem[0] = elem[0] - iso;
	ret.elem[1] = elem[1];
	ret.elem[2] = elem[2];
	ret.elem[3] = elem[3];
	ret.elem[4] = elem[4] - iso;
	ret.elem[5] = elem[5];
	ret.elem[6] = elem[6];
	ret.elem[7] = elem[7];
	ret.elem[8] = elem[8] - iso;
	return ret;
}
tensor2 tensor2::deviatoric(){
	return ( static_cast<const tensor2*>(this)->deviatoric());
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// transpose
tensor2 tensor2::transpose() const{
	tensor2 ret;
	ret.elem[0] = elem[0];
	ret.elem[1] = elem[3];
	ret.elem[2] = elem[6];
	ret.elem[3] = elem[1];
	ret.elem[4] = elem[4];
	ret.elem[5] = elem[7];
	ret.elem[6] = elem[2];
	ret.elem[7] = elem[5];
	ret.elem[8] = elem[8];
	return ret;
}
tensor2 tensor2::transpose(){
	return ( static_cast<const tensor2*>(this)->transpose());
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// I1
double tensor2::I1() const{
	return elem[0] + elem[4] + elem[8];
}
double tensor2::I1(){
	return ( static_cast<const tensor2*>(this)->I1());
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// I2
double tensor2::I2() const{
	double tr = this->trace();
	tensor2 t2 = this->dot_prdct( *this );
	double tr2 = t2.trace();
	return 0.5*(tr*tr-tr2);
}
double tensor2::I2(){
	return ( static_cast<const tensor2*>(this)->I2());
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// I3
double tensor2::I3() const{
	return this->det();
}
double tensor2::I3(){
	return ( static_cast<const tensor2*>(this)->I3());
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// tens2 dot vec
tensor1 tensor2::dot_prdct( const tensor1& v ) const{
	tensor1 ret;
	ret.elem[0] = elem[0]*v.elem[0] + elem[1]*v.elem[1] + elem[2]*v.elem[2];
	ret.elem[1] = elem[3]*v.elem[0] + elem[4]*v.elem[1] + elem[5]*v.elem[2];
	ret.elem[2] = elem[6]*v.elem[0] + elem[7]*v.elem[1] + elem[8]*v.elem[2];
	return ret;
}
tensor1 tensor2::dot_prdct( const tensor1& v ){
	return ( static_cast<const tensor2*>(this)->dot_prdct(v));
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// tens2 dot tens2
tensor2 tensor2::dot_prdct( const tensor2& t ) const{
	tensor2 ret;
	ret.elem[0] = elem[0]*t.elem[0] + elem[1]*t.elem[3] + elem[2]*t.elem[6];
	ret.elem[1] = elem[0]*t.elem[1] + elem[1]*t.elem[4] + elem[2]*t.elem[7];
	ret.elem[2] = elem[0]*t.elem[2] + elem[1]*t.elem[5] + elem[2]*t.elem[8];
	ret.elem[3] = elem[3]*t.elem[0] + elem[4]*t.elem[3] + elem[5]*t.elem[6];
	ret.elem[4] = elem[3]*t.elem[1] + elem[4]*t.elem[4] + elem[5]*t.elem[7];
	ret.elem[5] = elem[3]*t.elem[2] + elem[4]*t.elem[5] + elem[5]*t.elem[8];
	ret.elem[6] = elem[6]*t.elem[0] + elem[7]*t.elem[3] + elem[8]*t.elem[6];
	ret.elem[7] = elem[6]*t.elem[1] + elem[7]*t.elem[4] + elem[8]*t.elem[7];
	ret.elem[8] = elem[6]*t.elem[2] + elem[7]*t.elem[5] + elem[8]*t.elem[8];
	return ret;
}
tensor2 tensor2::dot_prdct( const tensor2& t ){
	return ( static_cast<const tensor2*>(this)->dot_prdct(t));
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// tens2 double_dot tens2
double tensor2::dbdot_prdct( const tensor2& t ) const{
	double ret;
	ret = elem[0]*t.elem[0]
	    + elem[1]*t.elem[1]
	    + elem[2]*t.elem[2]
	    + elem[3]*t.elem[3]
	    + elem[4]*t.elem[4]
	    + elem[5]*t.elem[5]
	    + elem[6]*t.elem[6]
	    + elem[7]*t.elem[7]
	    + elem[8]*t.elem[8];
	return ret;
}
double tensor2::dbdot_prdct( const tensor2& t ){
	return ( static_cast<const tensor2*>(this)->dbdot_prdct(t));
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// symmetrize
sym_tensor2 tensor2::symmetrize() const{
	sym_tensor2 ret;
	ret.elem[0] = elem[0];
	ret.elem[1] = elem[4];
	ret.elem[2] = elem[8];
	ret.elem[3] = 0.5*( elem[1] + elem[3] );
	ret.elem[4] = 0.5*( elem[5] + elem[7] );
	ret.elem[5] = 0.5*( elem[2] + elem[6] );
	return ret;
}
sym_tensor2 tensor2::symmetrize(){
	return ( static_cast<const tensor2*>(this)->symmetrize());
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// binary operators
tensor2 operator +( const tensor2& t1, const tensor2& t2 ){
	tensor2 ret;
	ret.elem[0] = t1.elem[0] + t2.elem[0];
	ret.elem[1] = t1.elem[1] + t2.elem[1];
	ret.elem[2] = t1.elem[2] + t2.elem[2];
	ret.elem[3] = t1.elem[3] + t2.elem[3];
	ret.elem[4] = t1.elem[4] + t2.elem[4];
	ret.elem[5] = t1.elem[5] + t2.elem[5];
	ret.elem[6] = t1.elem[6] + t2.elem[6];
	ret.elem[7] = t1.elem[7] + t2.elem[7];
	ret.elem[8] = t1.elem[8] + t2.elem[8];
	return ret;
}

tensor2 operator -( const tensor2& t1, const tensor2& t2 ){
	tensor2 ret;
	ret.elem[0] = t1.elem[0] - t2.elem[0];
	ret.elem[1] = t1.elem[1] - t2.elem[1];
	ret.elem[2] = t1.elem[2] - t2.elem[2];
	ret.elem[3] = t1.elem[3] - t2.elem[3];
	ret.elem[4] = t1.elem[4] - t2.elem[4];
	ret.elem[5] = t1.elem[5] - t2.elem[5];
	ret.elem[6] = t1.elem[6] - t2.elem[6];
	ret.elem[7] = t1.elem[7] - t2.elem[7];
	ret.elem[8] = t1.elem[8] - t2.elem[8];
	return ret;
}

tensor2 operator *( const double s, const tensor2& t ){
	tensor2 ret;
	ret.elem[0] = s*t.elem[0];
	ret.elem[1] = s*t.elem[1];
	ret.elem[2] = s*t.elem[2];
	ret.elem[3] = s*t.elem[3];
	ret.elem[4] = s*t.elem[4];
	ret.elem[5] = s*t.elem[5];
	ret.elem[6] = s*t.elem[6];
	ret.elem[7] = s*t.elem[7];
	ret.elem[8] = s*t.elem[8];
	return ret;
}

tensor2 operator *( const tensor2& t, const double s ){
	tensor2 ret;
	ret.elem[0] = s*t.elem[0];
	ret.elem[1] = s*t.elem[1];
	ret.elem[2] = s*t.elem[2];
	ret.elem[3] = s*t.elem[3];
	ret.elem[4] = s*t.elem[4];
	ret.elem[5] = s*t.elem[5];
	ret.elem[6] = s*t.elem[6];
	ret.elem[7] = s*t.elem[7];
	ret.elem[8] = s*t.elem[8];
	return ret;
}

tensor2 operator /( const tensor2& t, const double s ){
	tensor2 ret;
	ret.elem[0] = t.elem[0]/s;
	ret.elem[1] = t.elem[1]/s;
	ret.elem[2] = t.elem[2]/s;
	ret.elem[3] = t.elem[3]/s;
	ret.elem[4] = t.elem[4]/s;
	ret.elem[5] = t.elem[5]/s;
	ret.elem[6] = t.elem[6]/s;
	ret.elem[7] = t.elem[7]/s;
	ret.elem[8] = t.elem[8]/s;
	return ret;
}

}