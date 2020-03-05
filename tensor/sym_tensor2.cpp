#include "tensor1.h"
#include "sym_tensor2.h"
#include "tensor2.h"
#include "sym_tensor4.h"

namespace tens{
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// trace
double sym_tensor2::trace() const{
	return elem[0]+elem[1]+elem[2];
}
double sym_tensor2::trace(){
	return ( static_cast<const sym_tensor2*>(this)->trace());
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// norm
double sym_tensor2::norm() const{
	double ret = elem[0]*elem[0]
	           + elem[1]*elem[1]
	           + elem[2]*elem[2]
	           + elem[3]*elem[3]*2.0
	           + elem[4]*elem[4]*2.0
	           + elem[5]*elem[5]*2.0;
	return std::sqrt(ret);
}
double sym_tensor2::norm(){
	return ( static_cast<const sym_tensor2*>(this)->norm());
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// det
double sym_tensor2::det() const{
	return elem[0]*elem[1]*elem[2]
		 + elem[3]*elem[4]*elem[5]
		 + elem[3]*elem[4]*elem[5]
		 - elem[5]*elem[1]*elem[5]
		 - elem[0]*elem[4]*elem[4]
		 - elem[3]*elem[3]*elem[2];
}
double sym_tensor2::det(){
	return ( static_cast<const sym_tensor2*>(this)->det());
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// inverse
sym_tensor2 sym_tensor2::inverse() const{
	sym_tensor2 ret;
	double dett = this->det();
	ret.elem[0] = ( elem[1]*elem[2] - elem[4]*elem[4] )/dett;
	ret.elem[1] = ( elem[0]*elem[2] - elem[5]*elem[5] )/dett;
	ret.elem[2] = ( elem[0]*elem[1] - elem[3]*elem[3] )/dett;
	ret.elem[3] = ( elem[5]*elem[4] - elem[3]*elem[2] )/dett;
	ret.elem[4] = ( elem[5]*elem[3] - elem[0]*elem[4] )/dett;
	ret.elem[5] = ( elem[3]*elem[4] - elem[5]*elem[1] )/dett;
	return ret;
}

sym_tensor2 sym_tensor2::inverse(){
	return ( static_cast<const sym_tensor2*>(this)->inverse());
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// deviatoric
sym_tensor2 sym_tensor2::deviatoric() const{
	double iso = (elem[0] + elem[1] + elem[2])/3.0;
	sym_tensor2 ret;
	ret.elem[0] = elem[0] - iso;
	ret.elem[1] = elem[1] - iso;
	ret.elem[2] = elem[2] - iso;
	ret.elem[3] = elem[3];
	ret.elem[4] = elem[4];
	ret.elem[5] = elem[5];
	return ret;
}
sym_tensor2 sym_tensor2::deviatoric(){
	return ( static_cast<const sym_tensor2*>(this)->deviatoric());
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// p
double sym_tensor2::p() const{
	return ( elem[0] + elem[1] + elem[2] )/3.0;
}
double sym_tensor2::p(){
	return ( static_cast<const sym_tensor2*>(this)->p());
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// s
sym_tensor2 sym_tensor2::s() const{
	double iso = ( elem[0] + elem[1] + elem[2] )/3.0;
	sym_tensor2 ret;
	ret.elem[0] = elem[0] - iso;
	ret.elem[1] = elem[1] - iso;
	ret.elem[2] = elem[2] - iso;
	ret.elem[3] = elem[3];
	ret.elem[4] = elem[4];
	ret.elem[5] = elem[5];
	return ret;
}
sym_tensor2 sym_tensor2::s(){
	return ( static_cast<const sym_tensor2*>(this)->s());
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// q
double sym_tensor2::q() const{
	double norms = this->s().norm();
	return std::sqrt(1.5)*norms;
}
double sym_tensor2::q(){
	return ( static_cast<const sym_tensor2*>(this)->q());
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ehta
sym_tensor2 sym_tensor2::ehta() const{
	double p = ( elem[0] + elem[1] + elem[2] )/3.0;
	if( p == 0.0 ) return sym_tensor2::zero();
	sym_tensor2 ret;
	ret.elem[0] = ( elem[0] - p )/p;
	ret.elem[1] = ( elem[1] - p )/p;
	ret.elem[2] = ( elem[2] - p )/p;
	ret.elem[3] = elem[3]/p;
	ret.elem[4] = elem[4]/p;
	ret.elem[5] = elem[5]/p;
	return ret;
}
sym_tensor2 sym_tensor2::ehta(){
	return ( static_cast<const sym_tensor2*>(this)->ehta());
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// I1
double sym_tensor2::I1() const{
	return elem[0] + elem[1] + elem[2];
}
double sym_tensor2::I1(){
	return ( static_cast<const sym_tensor2*>(this)->I1());
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// I2
double sym_tensor2::I2() const{
	double tr = this->trace();
	sym_tensor2 t2 = this->dot_prdct( *this );
	double tr2 = t2.trace();
	return 0.5*(tr*tr-tr2);
}
double sym_tensor2::I2(){
	return ( static_cast<const sym_tensor2*>(this)->I2());
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// I3
double sym_tensor2::I3() const{
	return this->det();
}
double sym_tensor2::I3(){
	return ( static_cast<const sym_tensor2*>(this)->I3());
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// J2
double sym_tensor2::J2() const{
	return 0.5* this->s().dbdot_prdct( this->s() );
}
double sym_tensor2::J2(){
	return ( static_cast<const sym_tensor2*>(this)->J2());
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ehta_star
double sym_tensor2::ehta_star( const sym_tensor2& sig0 ) const{
	double p = this->p();
	double p0 = ( sig0.elem[0] + sig0.elem[1] + sig0.elem[2] )/3.0;
	sym_tensor2 dehta;
	dehta.elem[0] = elem[0]/p - sig0.elem[0]/p0;
	dehta.elem[1] = elem[1]/p - sig0.elem[1]/p0;
	dehta.elem[2] = elem[2]/p - sig0.elem[2]/p0;
	dehta.elem[3] = elem[3]/p - sig0.elem[3]/p0;
	dehta.elem[4] = elem[4]/p - sig0.elem[4]/p0;
	dehta.elem[5] = elem[5]/p - sig0.elem[5]/p0;
	return std::sqrt( 1.5 )*dehta.norm();
}
double sym_tensor2::ehta_star( const sym_tensor2& sig0 ){
	return ( static_cast<const sym_tensor2*>(this)->ehta_star(sig0));
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ehta_rot
double sym_tensor2::ehta_rot( const sym_tensor2& ehtae ) const{
	double p = this->p();
	if( p == 0.0 ) return 0.0;
	sym_tensor2 dehta;
	dehta.elem[0] = ( elem[0] - p)/p - ehtae.elem[0];
	dehta.elem[1] = ( elem[1] - p)/p - ehtae.elem[1];
	dehta.elem[2] = ( elem[2] - p)/p - ehtae.elem[2];
	dehta.elem[3] = elem[3]/p - ehtae.elem[3];
	dehta.elem[4] = elem[4]/p - ehtae.elem[4];
	dehta.elem[5] = elem[5]/p - ehtae.elem[5];
	return std::sqrt( 1.5 )*dehta.norm();
}
double sym_tensor2::ehta_rot( const sym_tensor2& ehtae ){
	return ( static_cast<const sym_tensor2*>(this)->ehta_rot(ehtae));
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// s_bar
sym_tensor2 sym_tensor2::s_bar( const sym_tensor2& sig0 ) const{
	double p = this->p();
	double p0 = ( sig0.elem[0] + sig0.elem[1] + sig0.elem[2] )/3.0;
	sym_tensor2 ret;
	ret.elem[0] = elem[0] - p*( 1.0 - ( sig0.elem[0]- p0)/p0 );
	ret.elem[1] = elem[1] - p*( 1.0 - ( sig0.elem[1]- p0)/p0 );
	ret.elem[2] = elem[2] - p*( 1.0 - ( sig0.elem[2]- p0)/p0 );
	ret.elem[3] = elem[3] - p*sig0.elem[3]/p0;
	ret.elem[4] = elem[4] - p*sig0.elem[4]/p0;
	ret.elem[5] = elem[5] - p*sig0.elem[5]/p0;
	return ret;
}
sym_tensor2 sym_tensor2::s_bar( const sym_tensor2& sig0 ){
	return ( static_cast<const sym_tensor2*>(this)->s_bar(sig0));
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// n_bar
sym_tensor2 sym_tensor2::n_bar( const sym_tensor2& sig0 ) const{
	sym_tensor2 ret = this->s_bar(sig0);
	return ret/ret.norm();
}
sym_tensor2 sym_tensor2::n_bar( const sym_tensor2& sig0 ){
	return ( static_cast<const sym_tensor2*>(this)->n_bar(sig0));
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// q_bar
double sym_tensor2::q_bar( const sym_tensor2& sig0 ) const{
	double norms_bar =  this->s_bar(sig0).norm();
	return std::sqrt(1.5)*norms_bar;
}
double sym_tensor2::q_bar( const sym_tensor2& sig0 ){
	return ( static_cast<const sym_tensor2*>(this)->q_bar(sig0));
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// epsv
double sym_tensor2::epsv() const{
	return elem[0]+elem[1]+elem[2];
}
double sym_tensor2::epsv(){
	return ( static_cast<const sym_tensor2*>(this)->epsv());
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// epsd
sym_tensor2 sym_tensor2::epsd() const{
	double iso = ( elem[0] + elem[1] + elem[2] )/3.0;
	sym_tensor2 ret;
	ret.elem[0] = elem[0] - iso;
	ret.elem[1] = elem[1] - iso;
	ret.elem[2] = elem[2] - iso;
	ret.elem[3] = elem[3];
	ret.elem[4] = elem[4];
	ret.elem[5] = elem[5];
	return ret;
}
sym_tensor2 sym_tensor2::epsd(){
	return ( static_cast<const sym_tensor2*>(this)->epsd());
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// epss
double sym_tensor2::epss() const{
	double normepsd = this->epsd().norm();
	return std::sqrt(2.0/3.0)*normepsd;
}
double sym_tensor2::epss(){
	return ( static_cast<const sym_tensor2*>(this)->epss());
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// tens2 dot vec
tensor1 sym_tensor2::dot_prdct( const tensor1& v ) const{
	tensor1 ret;
	ret.elem[0] = elem[0]*v.elem[0] + elem[3]*v.elem[1] + elem[5]*v.elem[2];
	ret.elem[1] = elem[3]*v.elem[0] + elem[1]*v.elem[1] + elem[4]*v.elem[2];
	ret.elem[2] = elem[5]*v.elem[0] + elem[4]*v.elem[1] + elem[2]*v.elem[2];
	return ret;
}
tensor1 sym_tensor2::dot_prdct( const tensor1& v ){
	return ( static_cast<const sym_tensor2*>(this)->dot_prdct(v));
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// tens2 dot tens2
sym_tensor2 sym_tensor2::dot_prdct( const sym_tensor2& t ) const{
	sym_tensor2 ret;
	ret.elem[0] = elem[0]*t.elem[0] + elem[3]*t.elem[3] + elem[5]*t.elem[5];
	ret.elem[1] = elem[3]*t.elem[3] + elem[1]*t.elem[1] + elem[4]*t.elem[4];
	ret.elem[2] = elem[5]*t.elem[5] + elem[4]*t.elem[4] + elem[2]*t.elem[2];
	ret.elem[3] = elem[0]*t.elem[3] + elem[3]*t.elem[1] + elem[5]*t.elem[4];
	ret.elem[4] = elem[3]*t.elem[5] + elem[1]*t.elem[4] + elem[4]*t.elem[2];
	ret.elem[5] = elem[0]*t.elem[5] + elem[3]*t.elem[4] + elem[5]*t.elem[2];
	return ret;
}
sym_tensor2 sym_tensor2::dot_prdct( const sym_tensor2& t ){
	return ( static_cast<const sym_tensor2*>(this)->dot_prdct(t));
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// tens2 dot tens4
sym_tensor4 sym_tensor2::dot_prdct( const sym_tensor4& t ) const{
	sym_tensor4 ret;
	for( int i=0; i<6; i++ ){
		ret.elem[0*6+i] = elem[0]*t.elem[0*6+i] + elem[3]*t.elem[3*6+i] + elem[5]*t.elem[5*6+i];
		ret.elem[1*6+i] = elem[3]*t.elem[3*6+i] + elem[1]*t.elem[1*6+i] + elem[4]*t.elem[4*6+i];
		ret.elem[2*6+i] = elem[5]*t.elem[5*6+i] + elem[4]*t.elem[4*6+i] + elem[2]*t.elem[2*6+i];
		ret.elem[3*6+i] = elem[0]*t.elem[3*6+i] + elem[3]*t.elem[1*6+i] + elem[5]*t.elem[4*6+i];
		ret.elem[4*6+i] = elem[3]*t.elem[5*6+i] + elem[1]*t.elem[4*6+i] + elem[4]*t.elem[2*6+i];
		ret.elem[5*6+i] = elem[5]*t.elem[0*6+i] + elem[4]*t.elem[3*6+i] + elem[2]*t.elem[5*6+i];
	}
	return ret;
}
sym_tensor4 sym_tensor2::dot_prdct( const sym_tensor4& t ){
	return ( static_cast<const sym_tensor2*>(this)->dot_prdct(t));
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// tens2 tens tens2
sym_tensor4 sym_tensor2::tens_prdct( const sym_tensor2& t ) const{
	sym_tensor4 ret;
	ret.elem[0*6+0] = elem[0] * t.elem[0];
	ret.elem[0*6+1] = elem[0] * t.elem[1];
	ret.elem[0*6+2] = elem[0] * t.elem[2];
	ret.elem[0*6+3] = elem[0] * t.elem[3];
	ret.elem[0*6+4] = elem[0] * t.elem[4];
	ret.elem[0*6+5] = elem[0] * t.elem[5];
	ret.elem[1*6+0] = elem[1] * t.elem[0];
	ret.elem[1*6+1] = elem[1] * t.elem[1];
	ret.elem[1*6+2] = elem[1] * t.elem[2];
	ret.elem[1*6+3] = elem[1] * t.elem[3];
	ret.elem[1*6+4] = elem[1] * t.elem[4];
	ret.elem[1*6+5] = elem[1] * t.elem[5];
	ret.elem[2*6+0] = elem[2] * t.elem[0];
	ret.elem[2*6+1] = elem[2] * t.elem[1];
	ret.elem[2*6+2] = elem[2] * t.elem[2];
	ret.elem[2*6+3] = elem[2] * t.elem[3];
	ret.elem[2*6+4] = elem[2] * t.elem[4];
	ret.elem[2*6+5] = elem[2] * t.elem[5];
	ret.elem[3*6+0] = elem[3] * t.elem[0];
	ret.elem[3*6+1] = elem[3] * t.elem[1];
	ret.elem[3*6+2] = elem[3] * t.elem[2];
	ret.elem[3*6+3] = elem[3] * t.elem[3];
	ret.elem[3*6+4] = elem[3] * t.elem[4];
	ret.elem[3*6+5] = elem[3] * t.elem[5];
	ret.elem[4*6+0] = elem[4] * t.elem[0];
	ret.elem[4*6+1] = elem[4] * t.elem[1];
	ret.elem[4*6+2] = elem[4] * t.elem[2];
	ret.elem[4*6+3] = elem[4] * t.elem[3];
	ret.elem[4*6+4] = elem[4] * t.elem[4];
	ret.elem[4*6+5] = elem[4] * t.elem[5];
	ret.elem[5*6+0] = elem[5] * t.elem[0];
	ret.elem[5*6+1] = elem[5] * t.elem[1];
	ret.elem[5*6+2] = elem[5] * t.elem[2];
	ret.elem[5*6+3] = elem[5] * t.elem[3];
	ret.elem[5*6+4] = elem[5] * t.elem[4];
	ret.elem[5*6+5] = elem[5] * t.elem[5];
	return ret;
}

sym_tensor4 sym_tensor2::tens_prdct( const sym_tensor2& t ){
	return ( static_cast<const sym_tensor2*>(this)->tens_prdct(t));
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// tens2 double_dot tens2
double sym_tensor2::dbdot_prdct( const sym_tensor2& t ) const{
	double ret;
	ret = elem[0]*t.elem[0]
	    + elem[1]*t.elem[1]
	    + elem[2]*t.elem[2]
	    + elem[3]*t.elem[3]*2.0
	    + elem[4]*t.elem[4]*2.0
	    + elem[5]*t.elem[5]*2.0;
	return ret;
}
double sym_tensor2::dbdot_prdct( const sym_tensor2& t ){
	return ( static_cast<const sym_tensor2*>(this)->dbdot_prdct(t));
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// tens2 double_dot tens4
sym_tensor2 sym_tensor2::dbdot_prdct( const sym_tensor4& t ) const{
	sym_tensor2 ret;
	ret.elem[0] = elem[0]*t.elem[0*6+0] + elem[1]*t.elem[1*6+0] + elem[2]*t.elem[2*6+0]
	  + 2.0*(elem[3]*t.elem[3*6+0] + elem[4]*t.elem[4*6+0] + elem[5]*t.elem[5*6+0]);
	ret.elem[1] = elem[0]*t.elem[0*6+1] + elem[1]*t.elem[1*6+1] + elem[2]*t.elem[2*6+1]
	  + 2.0*(elem[3]*t.elem[3*6+1] + elem[4]*t.elem[4*6+1] + elem[5]*t.elem[5*6+1]);
	ret.elem[2] = elem[0]*t.elem[0*6+2] + elem[1]*t.elem[1*6+2] + elem[2]*t.elem[2*6+2]
	  + 2.0*(elem[3]*t.elem[3*6+2] + elem[4]*t.elem[4*6+2] + elem[5]*t.elem[5*6+2]);
	ret.elem[3] = elem[0]*t.elem[0*6+3] + elem[1]*t.elem[1*6+3] + elem[2]*t.elem[2*6+3]
	  + 2.0*(elem[3]*t.elem[3*6+3] + elem[4]*t.elem[4*6+3] + elem[5]*t.elem[5*6+3]);
	ret.elem[4] = elem[0]*t.elem[0*6+4] + elem[1]*t.elem[1*6+4] + elem[2]*t.elem[2*6+4]
	  + 2.0*(elem[3]*t.elem[3*6+4] + elem[4]*t.elem[4*6+4] + elem[5]*t.elem[5*6+4]);
	ret.elem[5] = elem[0]*t.elem[0*6+5] + elem[1]*t.elem[1*6+5] + elem[2]*t.elem[2*6+5]
	  + 2.0*(elem[3]*t.elem[3*6+5] + elem[4]*t.elem[4*6+5] + elem[5]*t.elem[5*6+5]);
	return ret;
}
sym_tensor2 sym_tensor2::dbdot_prdct( const sym_tensor4& t ){
	return ( static_cast<const sym_tensor2*>(this)->dbdot_prdct(t));
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// calculate summation product of 2nd order tensors Rijkl = Aik Blj
sym_tensor4 sym_tensor2::sum_prdct( const sym_tensor2& t ) const{
	sym_tensor4 ret;
	ret.elem[0*6+0] = elem[0]*t.elem[0];
	ret.elem[0*6+1] = elem[3]*t.elem[3];
	ret.elem[0*6+2] = elem[5]*t.elem[5];
	ret.elem[0*6+3] = elem[0]*t.elem[3];
	ret.elem[0*6+4] = elem[3]*t.elem[5];
	ret.elem[0*6+5] = elem[5]*t.elem[0];
	ret.elem[1*6+0] = elem[3]*t.elem[3];
	ret.elem[1*6+1] = elem[1]*t.elem[1];
	ret.elem[1*6+2] = elem[4]*t.elem[4];
	ret.elem[1*6+3] = elem[3]*t.elem[1];
	ret.elem[1*6+4] = elem[1]*t.elem[4];
	ret.elem[1*6+5] = elem[4]*t.elem[3];
	ret.elem[2*6+0] = elem[5]*t.elem[5];
	ret.elem[2*6+1] = elem[4]*t.elem[4];
	ret.elem[2*6+2] = elem[2]*t.elem[2];
	ret.elem[2*6+3] = elem[5]*t.elem[4];
	ret.elem[2*6+4] = elem[4]*t.elem[2];
	ret.elem[2*6+5] = elem[2]*t.elem[5];
	ret.elem[3*6+0] = elem[0]*t.elem[3];
	ret.elem[3*6+1] = elem[3]*t.elem[1];
	ret.elem[3*6+2] = elem[5]*t.elem[4];
	ret.elem[3*6+3] = elem[0]*t.elem[1];
	ret.elem[3*6+4] = elem[3]*t.elem[4];
	ret.elem[3*6+5] = elem[5]*t.elem[3];
	ret.elem[4*6+0] = elem[3]*t.elem[5];
	ret.elem[4*6+1] = elem[1]*t.elem[4];
	ret.elem[4*6+2] = elem[4]*t.elem[2];
	ret.elem[4*6+3] = elem[3]*t.elem[4];
	ret.elem[4*6+4] = elem[1]*t.elem[2];
	ret.elem[4*6+5] = elem[4]*t.elem[5];
	ret.elem[5*6+0] = elem[5]*t.elem[0];
	ret.elem[5*6+1] = elem[4]*t.elem[3];
	ret.elem[5*6+2] = elem[2]*t.elem[5];
	ret.elem[5*6+3] = elem[5]*t.elem[3];
	ret.elem[5*6+4] = elem[4]*t.elem[5];
	ret.elem[5*6+5] = elem[2]*t.elem[0];
	return ret;
}
sym_tensor4 sym_tensor2::sum_prdct( const sym_tensor2& t ){
	return ( static_cast<const sym_tensor2*>(this)->sum_prdct(t));
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// calculate summation product of 2nd order tensors Rijkl = Ail Bkj
sym_tensor4 sym_tensor2::det_prdct( const sym_tensor2& t ) const{
	sym_tensor4 ret;
	ret.elem[0*6+0] = elem[0]*t.elem[0];
	ret.elem[0*6+1] = elem[3]*t.elem[3];
	ret.elem[0*6+2] = elem[5]*t.elem[5];
	ret.elem[0*6+3] = elem[3]*t.elem[0];
	ret.elem[0*6+4] = elem[5]*t.elem[3];
	ret.elem[0*6+5] = elem[0]*t.elem[5];
	ret.elem[1*6+0] = elem[3]*t.elem[3];
	ret.elem[1*6+1] = elem[1]*t.elem[1];
	ret.elem[1*6+2] = elem[4]*t.elem[4];
	ret.elem[1*6+3] = elem[1]*t.elem[3];
	ret.elem[1*6+4] = elem[4]*t.elem[1];
	ret.elem[1*6+5] = elem[3]*t.elem[4];
	ret.elem[2*6+0] = elem[5]*t.elem[5];
	ret.elem[2*6+1] = elem[4]*t.elem[4];
	ret.elem[2*6+2] = elem[2]*t.elem[2];
	ret.elem[2*6+3] = elem[4]*t.elem[5];
	ret.elem[2*6+4] = elem[2]*t.elem[4];
	ret.elem[2*6+5] = elem[5]*t.elem[2];
	ret.elem[3*6+0] = elem[0]*t.elem[3];
	ret.elem[3*6+1] = elem[3]*t.elem[1];
	ret.elem[3*6+2] = elem[5]*t.elem[4];
	ret.elem[3*6+3] = elem[3]*t.elem[3];
	ret.elem[3*6+4] = elem[5]*t.elem[1];
	ret.elem[3*6+5] = elem[0]*t.elem[4];
	ret.elem[4*6+0] = elem[3]*t.elem[5];
	ret.elem[4*6+1] = elem[1]*t.elem[4];
	ret.elem[4*6+2] = elem[4]*t.elem[2];
	ret.elem[4*6+3] = elem[1]*t.elem[5];
	ret.elem[4*6+4] = elem[4]*t.elem[4];
	ret.elem[4*6+5] = elem[3]*t.elem[2];
	ret.elem[5*6+0] = elem[5]*t.elem[0];
	ret.elem[5*6+1] = elem[4]*t.elem[3];
	ret.elem[5*6+2] = elem[2]*t.elem[5];
	ret.elem[5*6+3] = elem[4]*t.elem[0];
	ret.elem[5*6+4] = elem[2]*t.elem[3];
	ret.elem[5*6+5] = elem[5]*t.elem[5];
	return ret;
}
sym_tensor4 sym_tensor2::det_prdct( const sym_tensor2& t ){
	return ( static_cast<const sym_tensor2*>(this)->det_prdct(t));
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
tensor2 sym_tensor2::asymmetrize() const{
	tensor2 ret;
	ret.elem[0] = elem[0];
	ret.elem[1] = elem[3];
	ret.elem[2] = elem[5];
	ret.elem[3] = elem[3];
	ret.elem[4] = elem[1];
	ret.elem[5] = elem[4];
	ret.elem[6] = elem[5];
	ret.elem[7] = elem[4];
	ret.elem[8] = elem[2];
	return ret;
}
tensor2 sym_tensor2::asymmetrize(){
	return ( static_cast<const sym_tensor2*>(this)->asymmetrize());
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// binary operators
sym_tensor2 operator +( const sym_tensor2& t1, const sym_tensor2& t2 ){
	sym_tensor2 ret;
	ret.elem[0] = t1.elem[0] + t2.elem[0];
	ret.elem[1] = t1.elem[1] + t2.elem[1];
	ret.elem[2] = t1.elem[2] + t2.elem[2];
	ret.elem[3] = t1.elem[3] + t2.elem[3];
	ret.elem[4] = t1.elem[4] + t2.elem[4];
	ret.elem[5] = t1.elem[5] + t2.elem[5];
	return ret;
}

sym_tensor2 operator -( const sym_tensor2& t1, const sym_tensor2& t2 ){
	sym_tensor2 ret;
	ret.elem[0] = t1.elem[0] - t2.elem[0];
	ret.elem[1] = t1.elem[1] - t2.elem[1];
	ret.elem[2] = t1.elem[2] - t2.elem[2];
	ret.elem[3] = t1.elem[3] - t2.elem[3];
	ret.elem[4] = t1.elem[4] - t2.elem[4];
	ret.elem[5] = t1.elem[5] - t2.elem[5];
	return ret;
}

sym_tensor2 operator *( const double s, const sym_tensor2& t ){
	sym_tensor2 ret;
	ret.elem[0] = s*t.elem[0];
	ret.elem[1] = s*t.elem[1];
	ret.elem[2] = s*t.elem[2];
	ret.elem[3] = s*t.elem[3];
	ret.elem[4] = s*t.elem[4];
	ret.elem[5] = s*t.elem[5];
	return ret;
}

sym_tensor2 operator *( const sym_tensor2& t, const double s ){
	sym_tensor2 ret;
	ret.elem[0] = s*t.elem[0];
	ret.elem[1] = s*t.elem[1];
	ret.elem[2] = s*t.elem[2];
	ret.elem[3] = s*t.elem[3];
	ret.elem[4] = s*t.elem[4];
	ret.elem[5] = s*t.elem[5];
	return ret;
}

sym_tensor2 operator /( const sym_tensor2& t, const double s ){
	sym_tensor2 ret;
	ret.elem[0] = t.elem[0]/s;
	ret.elem[1] = t.elem[1]/s;
	ret.elem[2] = t.elem[2]/s;
	ret.elem[3] = t.elem[3]/s;
	ret.elem[4] = t.elem[4]/s;
	ret.elem[5] = t.elem[5]/s;
	return ret;
}

}