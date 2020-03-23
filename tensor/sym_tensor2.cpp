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
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// norm
double sym_tensor2::norm() const{
	double ret = dbdot_prdct( *this );
	return std::sqrt(ret);
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
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// inverse
sym_tensor2 sym_tensor2::inverse() const{
	sym_tensor2 ret;
	double dett = this->det();
	ret(0) = ( elem[1]*elem[2] - elem[4]*elem[4] )/dett;
	ret(1) = ( elem[0]*elem[2] - elem[5]*elem[5] )/dett;
	ret(2) = ( elem[0]*elem[1] - elem[3]*elem[3] )/dett;
	ret(3) = ( elem[5]*elem[4] - elem[3]*elem[2] )/dett;
	ret(4) = ( elem[5]*elem[3] - elem[0]*elem[4] )/dett;
	ret(5) = ( elem[3]*elem[4] - elem[5]*elem[1] )/dett;
	return ret;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// deviatoric
sym_tensor2 sym_tensor2::deviatoric() const{
	sym_tensor2 del = sym_tensor2::delta();
	return *this - (this->trace()/3.0)*del;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// p
double sym_tensor2::p() const{
	return this->trace()/3.0;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// s
sym_tensor2 sym_tensor2::s() const{
	return this->deviatoric();
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// q
double sym_tensor2::q() const{
	return std::sqrt(1.5)*this->s().norm();
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ehta
sym_tensor2 sym_tensor2::ehta() const{
	return this->s()/this->p();
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// I1
double sym_tensor2::I1() const{
	return elem[0] + elem[1] + elem[2];
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// I2
double sym_tensor2::I2() const{
	double tr = this->trace();
	sym_tensor2 t2 = this->dot_prdct( *this );
	double tr2 = t2.trace();
	return 0.5*(tr*tr-tr2);
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// I3
double sym_tensor2::I3() const{
	return this->det();
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// J2
double sym_tensor2::J2() const{
	return 0.5* this->s().dbdot_prdct( this->s() );
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ehta_star
double sym_tensor2::ehta_star( const sym_tensor2& sig0 ) const{
	sym_tensor2 dehta;
	dehta = this->ehta() - sig0.ehta();
	return std::sqrt( 1.5 )*dehta.norm();
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ehta_rot
double sym_tensor2::ehta_rot( const sym_tensor2& ehtae ) const{
	double p = this->p();
	if( p == 0.0 ) return 0.0;
	sym_tensor2 dehta;
	dehta = this->ehta() - ehtae;
	return std::sqrt( 1.5 )*dehta.norm();
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// s_bar
sym_tensor2 sym_tensor2::s_bar( const sym_tensor2& sig0 ) const{
	sym_tensor2 del = sym_tensor2::delta();
	return *this - this->p()*( del + sig0.ehta() );
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// n_bar
sym_tensor2 sym_tensor2::n_bar( const sym_tensor2& sig0 ) const{
	sym_tensor2 ret = this->s_bar(sig0);
	return ret/ret.norm();
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// q_bar
double sym_tensor2::q_bar( const sym_tensor2& sig0 ) const{
	double norms_bar =  this->s_bar(sig0).norm();
	return std::sqrt(1.5)*norms_bar;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// epsv
double sym_tensor2::epsv() const{
	return elem[0]+elem[1]+elem[2];
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// epsd
sym_tensor2 sym_tensor2::epsd() const{
	return this->deviatoric();
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// epss
double sym_tensor2::epss() const{
	double normepsd = this->epsd().norm();
	return std::sqrt(2.0/3.0)*normepsd;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// tens2 dot vec
tensor1 sym_tensor2::dot_prdct( const tensor1& v ) const{
	tensor1 ret;
	ret(0) = elem[0]*v(0) + elem[3]*v(1) + elem[5]*v(2);
	ret(1) = elem[3]*v(0) + elem[1]*v(1) + elem[4]*v(2);
	ret(2) = elem[5]*v(0) + elem[4]*v(1) + elem[2]*v(2);
	return ret;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// tens2 dot tens2
sym_tensor2 sym_tensor2::dot_prdct( const sym_tensor2& t ) const{
	sym_tensor2 ret;
	ret(0) = elem[0]*t(0) + elem[3]*t(3) + elem[5]*t(5);
	ret(1) = elem[3]*t(3) + elem[1]*t(1) + elem[4]*t(4);
	ret(2) = elem[5]*t(5) + elem[4]*t(4) + elem[2]*t(2);
	ret(3) = elem[0]*t(3) + elem[3]*t(1) + elem[5]*t(4);
	ret(4) = elem[3]*t(5) + elem[1]*t(4) + elem[4]*t(2);
	ret(5) = elem[0]*t(5) + elem[3]*t(4) + elem[5]*t(2);
	return ret;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// tens2 dot tens4
sym_tensor4 sym_tensor2::dot_prdct( const sym_tensor4& t ) const{
	sym_tensor4 ret;
	for( int i=0; i<6; i++ ){
		ret(0*6+i) = elem[0]*t(0*6+i) + elem[3]*t(3*6+i) + elem[5]*t(5*6+i);
		ret(1*6+i) = elem[3]*t(3*6+i) + elem[1]*t(1*6+i) + elem[4]*t(4*6+i);
		ret(2*6+i) = elem[5]*t(5*6+i) + elem[4]*t(4*6+i) + elem[2]*t(2*6+i);
		ret(3*6+i) = elem[0]*t(3*6+i) + elem[3]*t(1*6+i) + elem[5]*t(4*6+i);
		ret(4*6+i) = elem[3]*t(5*6+i) + elem[1]*t(4*6+i) + elem[4]*t(2*6+i);
		ret(5*6+i) = elem[5]*t(0*6+i) + elem[4]*t(3*6+i) + elem[2]*t(5*6+i);
	}
	return ret;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// tens2 tens tens2
sym_tensor4 sym_tensor2::tens_prdct( const sym_tensor2& t ) const{
	sym_tensor4 ret;
	ret(0*6+0) = elem[0] * t(0);
	ret(0*6+1) = elem[0] * t(1);
	ret(0*6+2) = elem[0] * t(2);
	ret(0*6+3) = elem[0] * t(3);
	ret(0*6+4) = elem[0] * t(4);
	ret(0*6+5) = elem[0] * t(5);
	ret(1*6+0) = elem[1] * t(0);
	ret(1*6+1) = elem[1] * t(1);
	ret(1*6+2) = elem[1] * t(2);
	ret(1*6+3) = elem[1] * t(3);
	ret(1*6+4) = elem[1] * t(4);
	ret(1*6+5) = elem[1] * t(5);
	ret(2*6+0) = elem[2] * t(0);
	ret(2*6+1) = elem[2] * t(1);
	ret(2*6+2) = elem[2] * t(2);
	ret(2*6+3) = elem[2] * t(3);
	ret(2*6+4) = elem[2] * t(4);
	ret(2*6+5) = elem[2] * t(5);
	ret(3*6+0) = elem[3] * t(0);
	ret(3*6+1) = elem[3] * t(1);
	ret(3*6+2) = elem[3] * t(2);
	ret(3*6+3) = elem[3] * t(3);
	ret(3*6+4) = elem[3] * t(4);
	ret(3*6+5) = elem[3] * t(5);
	ret(4*6+0) = elem[4] * t(0);
	ret(4*6+1) = elem[4] * t(1);
	ret(4*6+2) = elem[4] * t(2);
	ret(4*6+3) = elem[4] * t(3);
	ret(4*6+4) = elem[4] * t(4);
	ret(4*6+5) = elem[4] * t(5);
	ret(5*6+0) = elem[5] * t(0);
	ret(5*6+1) = elem[5] * t(1);
	ret(5*6+2) = elem[5] * t(2);
	ret(5*6+3) = elem[5] * t(3);
	ret(5*6+4) = elem[5] * t(4);
	ret(5*6+5) = elem[5] * t(5);
	return ret;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// tens2 double_dot tens2
double sym_tensor2::dbdot_prdct( const sym_tensor2& t ) const{
	double ret;
	ret = elem[0]*t(0)
	    + elem[1]*t(1)
	    + elem[2]*t(2)
	    + elem[3]*t(3)*2.0
	    + elem[4]*t(4)*2.0
	    + elem[5]*t(5)*2.0;
	return ret;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// tens2 double_dot tens4
sym_tensor2 sym_tensor2::dbdot_prdct( const sym_tensor4& t ) const{
	sym_tensor2 ret;
	ret(0) = elem[0]*t(0*6+0) + elem[1]*t(1*6+0) + elem[2]*t(2*6+0)
	  + 2.0*(elem[3]*t(3*6+0) + elem[4]*t(4*6+0) + elem[5]*t(5*6+0));
	ret(1) = elem[0]*t(0*6+1) + elem[1]*t(1*6+1) + elem[2]*t(2*6+1)
	  + 2.0*(elem[3]*t(3*6+1) + elem[4]*t(4*6+1) + elem[5]*t(5*6+1));
	ret(2) = elem[0]*t(0*6+2) + elem[1]*t(1*6+2) + elem[2]*t(2*6+2)
	  + 2.0*(elem[3]*t(3*6+2) + elem[4]*t(4*6+2) + elem[5]*t(5*6+2));
	ret(3) = elem[0]*t(0*6+3) + elem[1]*t(1*6+3) + elem[2]*t(2*6+3)
	  + 2.0*(elem[3]*t(3*6+3) + elem[4]*t(4*6+3) + elem[5]*t(5*6+3));
	ret(4) = elem[0]*t(0*6+4) + elem[1]*t(1*6+4) + elem[2]*t(2*6+4)
	  + 2.0*(elem[3]*t(3*6+4) + elem[4]*t(4*6+4) + elem[5]*t(5*6+4));
	ret(5) = elem[0]*t(0*6+5) + elem[1]*t(1*6+5) + elem[2]*t(2*6+5)
	  + 2.0*(elem[3]*t(3*6+5) + elem[4]*t(4*6+5) + elem[5]*t(5*6+5));
	return ret;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// calculate summation product of 2nd order tensors Rijkl = Aik Blj
sym_tensor4 sym_tensor2::sum_prdct( const sym_tensor2& t ) const{
	sym_tensor4 ret;
	ret(0*6+0) = elem[0]*t(0);
	ret(0*6+1) = elem[3]*t(3);
	ret(0*6+2) = elem[5]*t(5);
	ret(0*6+3) = elem[0]*t(3);
	ret(0*6+4) = elem[3]*t(5);
	ret(0*6+5) = elem[5]*t(0);
	ret(1*6+0) = elem[3]*t(3);
	ret(1*6+1) = elem[1]*t(1);
	ret(1*6+2) = elem[4]*t(4);
	ret(1*6+3) = elem[3]*t(1);
	ret(1*6+4) = elem[1]*t(4);
	ret(1*6+5) = elem[4]*t(3);
	ret(2*6+0) = elem[5]*t(5);
	ret(2*6+1) = elem[4]*t(4);
	ret(2*6+2) = elem[2]*t(2);
	ret(2*6+3) = elem[5]*t(4);
	ret(2*6+4) = elem[4]*t(2);
	ret(2*6+5) = elem[2]*t(5);
	ret(3*6+0) = elem[0]*t(3);
	ret(3*6+1) = elem[3]*t(1);
	ret(3*6+2) = elem[5]*t(4);
	ret(3*6+3) = elem[0]*t(1);
	ret(3*6+4) = elem[3]*t(4);
	ret(3*6+5) = elem[5]*t(3);
	ret(4*6+0) = elem[3]*t(5);
	ret(4*6+1) = elem[1]*t(4);
	ret(4*6+2) = elem[4]*t(2);
	ret(4*6+3) = elem[3]*t(4);
	ret(4*6+4) = elem[1]*t(2);
	ret(4*6+5) = elem[4]*t(5);
	ret(5*6+0) = elem[5]*t(0);
	ret(5*6+1) = elem[4]*t(3);
	ret(5*6+2) = elem[2]*t(5);
	ret(5*6+3) = elem[5]*t(3);
	ret(5*6+4) = elem[4]*t(5);
	ret(5*6+5) = elem[2]*t(0);
	return ret;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// calculate summation product of 2nd order tensors Rijkl = Ail Bkj
sym_tensor4 sym_tensor2::det_prdct( const sym_tensor2& t ) const{
	sym_tensor4 ret;
	ret(0*6+0) = elem[0]*t(0);
	ret(0*6+1) = elem[3]*t(3);
	ret(0*6+2) = elem[5]*t(5);
	ret(0*6+3) = elem[3]*t(0);
	ret(0*6+4) = elem[5]*t(3);
	ret(0*6+5) = elem[0]*t(5);
	ret(1*6+0) = elem[3]*t(3);
	ret(1*6+1) = elem[1]*t(1);
	ret(1*6+2) = elem[4]*t(4);
	ret(1*6+3) = elem[1]*t(3);
	ret(1*6+4) = elem[4]*t(1);
	ret(1*6+5) = elem[3]*t(4);
	ret(2*6+0) = elem[5]*t(5);
	ret(2*6+1) = elem[4]*t(4);
	ret(2*6+2) = elem[2]*t(2);
	ret(2*6+3) = elem[4]*t(5);
	ret(2*6+4) = elem[2]*t(4);
	ret(2*6+5) = elem[5]*t(2);
	ret(3*6+0) = elem[0]*t(3);
	ret(3*6+1) = elem[3]*t(1);
	ret(3*6+2) = elem[5]*t(4);
	ret(3*6+3) = elem[3]*t(3);
	ret(3*6+4) = elem[5]*t(1);
	ret(3*6+5) = elem[0]*t(4);
	ret(4*6+0) = elem[3]*t(5);
	ret(4*6+1) = elem[1]*t(4);
	ret(4*6+2) = elem[4]*t(2);
	ret(4*6+3) = elem[1]*t(5);
	ret(4*6+4) = elem[4]*t(4);
	ret(4*6+5) = elem[3]*t(2);
	ret(5*6+0) = elem[5]*t(0);
	ret(5*6+1) = elem[4]*t(3);
	ret(5*6+2) = elem[2]*t(5);
	ret(5*6+3) = elem[4]*t(0);
	ret(5*6+4) = elem[2]*t(3);
	ret(5*6+5) = elem[5]*t(5);
	return ret;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
tensor2 sym_tensor2::asymmetrize() const{
	tensor2 ret;
	ret(0) = elem[0];
	ret(1) = elem[3];
	ret(2) = elem[5];
	ret(3) = elem[3];
	ret(4) = elem[1];
	ret(5) = elem[4];
	ret(6) = elem[5];
	ret(7) = elem[4];
	ret(8) = elem[2];
	return ret;
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// binary operators
sym_tensor2 operator +( const sym_tensor2& t1, const sym_tensor2& t2 ){
	sym_tensor2 ret;
	ret(0) = t1(0) + t2(0);
	ret(1) = t1(1) + t2(1);
	ret(2) = t1(2) + t2(2);
	ret(3) = t1(3) + t2(3);
	ret(4) = t1(4) + t2(4);
	ret(5) = t1(5) + t2(5);
	return ret;
}

sym_tensor2 operator -( const sym_tensor2& t1, const sym_tensor2& t2 ){
	sym_tensor2 ret;
	ret(0) = t1(0) - t2(0);
	ret(1) = t1(1) - t2(1);
	ret(2) = t1(2) - t2(2);
	ret(3) = t1(3) - t2(3);
	ret(4) = t1(4) - t2(4);
	ret(5) = t1(5) - t2(5);
	return ret;
}

sym_tensor2 operator *( const double s, const sym_tensor2& t ){
	sym_tensor2 ret;
	ret(0) = s*t(0);
	ret(1) = s*t(1);
	ret(2) = s*t(2);
	ret(3) = s*t(3);
	ret(4) = s*t(4);
	ret(5) = s*t(5);
	return ret;
}

sym_tensor2 operator *( const sym_tensor2& t, const double s ){
	sym_tensor2 ret;
	ret(0) = s*t(0);
	ret(1) = s*t(1);
	ret(2) = s*t(2);
	ret(3) = s*t(3);
	ret(4) = s*t(4);
	ret(5) = s*t(5);
	return ret;
}

sym_tensor2 operator /( const sym_tensor2& t, const double s ){
	sym_tensor2 ret;
	ret(0) = t(0)/s;
	ret(1) = t(1)/s;
	ret(2) = t(2)/s;
	ret(3) = t(3)/s;
	ret(4) = t(4)/s;
	ret(5) = t(5)/s;
	return ret;
}

}