#include "tensor1.h"
#include "sym_tensor2.h"
#include "sym_tensor4.h"

namespace tens{
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// tens4 dot tens2
sym_tensor4 sym_tensor4::dot_prdct( const sym_tensor2& t ) const{
	sym_tensor4 ret;
	ret(0*6+0) = elem[0*6+0]*t(0) + elem[0*6+3]*t(3) + elem[0*6+5]*t(5);
	ret(0*6+1) = elem[0*6+3]*t(3) + elem[0*6+1]*t(1) + elem[0*6+4]*t(4);
	ret(0*6+2) = elem[0*6+5]*t(5) + elem[0*6+4]*t(4) + elem[0*6+2]*t(2);
	ret(0*6+3) = elem[0*6+0]*t(3) + elem[0*6+3]*t(1) + elem[0*6+5]*t(4);
	ret(0*6+4) = elem[0*6+3]*t(5) + elem[0*6+1]*t(4) + elem[0*6+4]*t(2);
	ret(0*6+5) = elem[0*6+5]*t(0) + elem[0*6+4]*t(3) + elem[0*6+2]*t(5);
	ret(1*6+0) = elem[1*6+0]*t(0) + elem[1*6+3]*t(3) + elem[1*6+5]*t(5);
	ret(1*6+1) = elem[1*6+3]*t(3) + elem[1*6+1]*t(1) + elem[1*6+4]*t(4);
	ret(1*6+2) = elem[1*6+5]*t(5) + elem[1*6+4]*t(4) + elem[1*6+2]*t(2);
	ret(1*6+3) = elem[1*6+0]*t(3) + elem[1*6+3]*t(1) + elem[1*6+5]*t(4);
	ret(1*6+4) = elem[1*6+3]*t(5) + elem[1*6+1]*t(4) + elem[1*6+4]*t(2);
	ret(1*6+5) = elem[1*6+5]*t(0) + elem[1*6+4]*t(3) + elem[1*6+2]*t(5);
	ret(2*6+0) = elem[2*6+0]*t(0) + elem[2*6+3]*t(3) + elem[2*6+5]*t(5);
	ret(2*6+1) = elem[2*6+3]*t(3) + elem[2*6+1]*t(1) + elem[2*6+4]*t(4);
	ret(2*6+2) = elem[2*6+5]*t(5) + elem[2*6+4]*t(4) + elem[2*6+2]*t(2);
	ret(2*6+3) = elem[2*6+0]*t(3) + elem[2*6+3]*t(1) + elem[2*6+5]*t(4);
	ret(2*6+4) = elem[2*6+3]*t(5) + elem[2*6+1]*t(4) + elem[2*6+4]*t(2);
	ret(2*6+5) = elem[2*6+5]*t(0) + elem[2*6+4]*t(3) + elem[2*6+2]*t(5);
	ret(3*6+0) = elem[3*6+0]*t(0) + elem[3*6+3]*t(3) + elem[3*6+5]*t(5);
	ret(3*6+1) = elem[3*6+3]*t(3) + elem[3*6+1]*t(1) + elem[3*6+4]*t(4);
	ret(3*6+2) = elem[3*6+5]*t(5) + elem[3*6+4]*t(4) + elem[3*6+2]*t(2);
	ret(3*6+3) = elem[3*6+0]*t(3) + elem[3*6+3]*t(1) + elem[3*6+5]*t(4);
	ret(3*6+4) = elem[3*6+3]*t(5) + elem[3*6+1]*t(4) + elem[3*6+4]*t(2);
	ret(3*6+5) = elem[3*6+5]*t(0) + elem[3*6+4]*t(3) + elem[3*6+2]*t(5);
	ret(4*6+0) = elem[4*6+0]*t(0) + elem[4*6+3]*t(3) + elem[4*6+5]*t(5);
	ret(4*6+1) = elem[4*6+3]*t(3) + elem[4*6+1]*t(1) + elem[4*6+4]*t(4);
	ret(4*6+2) = elem[4*6+5]*t(5) + elem[4*6+4]*t(4) + elem[4*6+2]*t(2);
	ret(4*6+3) = elem[4*6+0]*t(3) + elem[4*6+3]*t(1) + elem[4*6+5]*t(4);
	ret(4*6+4) = elem[4*6+3]*t(5) + elem[4*6+1]*t(4) + elem[4*6+4]*t(2);
	ret(4*6+5) = elem[4*6+5]*t(0) + elem[4*6+4]*t(3) + elem[4*6+2]*t(5);
	ret(5*6+0) = elem[5*6+0]*t(0) + elem[5*6+3]*t(3) + elem[5*6+5]*t(5);
	ret(5*6+1) = elem[5*6+3]*t(3) + elem[5*6+1]*t(1) + elem[5*6+4]*t(4);
	ret(5*6+2) = elem[5*6+5]*t(5) + elem[5*6+4]*t(4) + elem[5*6+2]*t(2);
	ret(5*6+3) = elem[5*6+0]*t(3) + elem[5*6+3]*t(1) + elem[5*6+5]*t(4);
	ret(5*6+4) = elem[5*6+3]*t(5) + elem[5*6+1]*t(4) + elem[5*6+4]*t(2);
	ret(5*6+5) = elem[5*6+5]*t(0) + elem[5*6+4]*t(3) + elem[5*6+2]*t(5);
	return ret;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// vec dot tens2
sym_tensor2 sym_tensor4::dbdot_prdct( const sym_tensor2& t ) const{
	sym_tensor2 ret;
	ret(0) = t(0)*elem[0*6+0] + t(1)*elem[1*6+0] + t(2)*elem[2*6+0]
	  + 2.0*(t(3)*elem[3*6+0] + t(4)*elem[4*6+0] + t(5)*elem[5*6+0]);
	ret(1) = t(0)*elem[0*6+1] + t(1)*elem[1*6+1] + t(2)*elem[2*6+1]
	  + 2.0*(t(3)*elem[3*6+1] + t(4)*elem[4*6+1] + t(5)*elem[5*6+1]);
	ret(2) = t(0)*elem[0*6+2] + t(1)*elem[1*6+2] + t(2)*elem[2*6+2]
	  + 2.0*(t(3)*elem[3*6+2] + t(4)*elem[4*6+2] + t(5)*elem[5*6+2]);
	ret(3) = t(0)*elem[0*6+3] + t(1)*elem[1*6+3] + t(2)*elem[2*6+3]
	  + 2.0*(t(3)*elem[3*6+3] + t(4)*elem[4*6+3] + t(5)*elem[5*6+3]);
	ret(4) = t(0)*elem[0*6+4] + t(1)*elem[1*6+4] + t(2)*elem[2*6+4]
	  + 2.0*(t(3)*elem[3*6+4] + t(4)*elem[4*6+4] + t(5)*elem[5*6+4]);
	ret(5) = t(0)*elem[0*6+5] + t(1)*elem[1*6+5] + t(2)*elem[2*6+5]
	  + 2.0*(t(3)*elem[3*6+5] + t(4)*elem[4*6+5] + t(5)*elem[5*6+5]);
	return ret;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// tens4 dbdot tens4
sym_tensor4 sym_tensor4::dbdot_prdct( const sym_tensor4& t ) const{
	sym_tensor4 ret;
	for( int i=0; i<6; i++ ){
		for( int j=0; j<6; j++ ){
			ret(i*6+j) = 0.0;
			for( int k=0; k<6; k++ ){
				if( k <   3 ) ret(i*6+j) += elem[i*6+k]*t(k*6+j);
				if( k >=  3 ) ret(i*6+j) += 2.0*elem[i*6+k]*t(k*6+j);
			}
		}
	}
	return ret;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// binary operators
sym_tensor4 operator +( const sym_tensor4& t1, const sym_tensor4& t2 ){
	sym_tensor4 ret;
	ret( 0) = t1( 0) + t2( 0);
	ret( 1) = t1( 1) + t2( 1);
	ret( 2) = t1( 2) + t2( 2);
	ret( 3) = t1( 3) + t2( 3);
	ret( 4) = t1( 4) + t2( 4);
	ret( 5) = t1( 5) + t2( 5);
	ret( 6) = t1( 6) + t2( 6);
    ret( 7) = t1( 7) + t2( 7);
    ret( 8) = t1( 8) + t2( 8);
    ret( 9) = t1( 9) + t2( 9);
    ret(10) = t1(10) + t2(10);
	ret(11) = t1(11) + t2(11);
	ret(12) = t1(12) + t2(12);
	ret(13) = t1(13) + t2(13);
	ret(14) = t1(14) + t2(14);
	ret(15) = t1(15) + t2(15);
	ret(16) = t1(16) + t2(16);
    ret(17) = t1(17) + t2(17);
    ret(18) = t1(18) + t2(18);
    ret(19) = t1(19) + t2(19);
    ret(20) = t1(20) + t2(20);
	ret(21) = t1(21) + t2(21);
	ret(22) = t1(22) + t2(22);
	ret(23) = t1(23) + t2(23);
	ret(24) = t1(24) + t2(24);
	ret(25) = t1(25) + t2(25);
	ret(26) = t1(26) + t2(26);
    ret(27) = t1(27) + t2(27);
    ret(28) = t1(28) + t2(28);
    ret(29) = t1(29) + t2(29);
    ret(30) = t1(30) + t2(30);
	ret(31) = t1(31) + t2(31);
	ret(32) = t1(32) + t2(32);
	ret(33) = t1(33) + t2(33);
	ret(34) = t1(34) + t2(34);
	ret(35) = t1(35) + t2(35);
	return ret;
}

sym_tensor4 operator -( const sym_tensor4& t1, const sym_tensor4& t2 ){
	sym_tensor4 ret;
	ret( 0) = t1( 0) - t2( 0);
	ret( 1) = t1( 1) - t2( 1);
	ret( 2) = t1( 2) - t2( 2);
	ret( 3) = t1( 3) - t2( 3);
	ret( 4) = t1( 4) - t2( 4);
	ret( 5) = t1( 5) - t2( 5);
	ret( 6) = t1( 6) - t2( 6);
    ret( 7) = t1( 7) - t2( 7);
    ret( 8) = t1( 8) - t2( 8);
    ret( 9) = t1( 9) - t2( 9);
    ret(10) = t1(10) - t2(10);
	ret(11) = t1(11) - t2(11);
	ret(12) = t1(12) - t2(12);
	ret(13) = t1(13) - t2(13);
	ret(14) = t1(14) - t2(14);
	ret(15) = t1(15) - t2(15);
	ret(16) = t1(16) - t2(16);
    ret(17) = t1(17) - t2(17);
    ret(18) = t1(18) - t2(18);
    ret(19) = t1(19) - t2(19);
    ret(20) = t1(20) - t2(20);
	ret(21) = t1(21) - t2(21);
	ret(22) = t1(22) - t2(22);
	ret(23) = t1(23) - t2(23);
	ret(24) = t1(24) - t2(24);
	ret(25) = t1(25) - t2(25);
	ret(26) = t1(26) - t2(26);
    ret(27) = t1(27) - t2(27);
    ret(28) = t1(28) - t2(28);
    ret(29) = t1(29) - t2(29);
    ret(30) = t1(30) - t2(30);
	ret(31) = t1(31) - t2(31);
	ret(32) = t1(32) - t2(32);
	ret(33) = t1(33) - t2(33);
	ret(34) = t1(34) - t2(34);
	ret(35) = t1(35) - t2(35);
	return ret;
}

sym_tensor4 operator *( const double s, const sym_tensor4& t ){
	sym_tensor4 ret;
	ret( 0) = s*t( 0);
	ret( 1) = s*t( 1);
	ret( 2) = s*t( 2);
	ret( 3) = s*t( 3);
	ret( 4) = s*t( 4);
	ret( 5) = s*t( 5);
	ret( 6) = s*t( 6);
    ret( 7) = s*t( 7);
    ret( 8) = s*t( 8);
    ret( 9) = s*t( 9);
    ret(10) = s*t(10);
	ret(11) = s*t(11);
	ret(12) = s*t(12);
	ret(13) = s*t(13);
	ret(14) = s*t(14);
	ret(15) = s*t(15);
	ret(16) = s*t(16);
    ret(17) = s*t(17);
    ret(18) = s*t(18);
    ret(19) = s*t(19);
    ret(20) = s*t(20);
	ret(21) = s*t(21);
	ret(22) = s*t(22);
	ret(23) = s*t(23);
	ret(24) = s*t(24);
	ret(25) = s*t(25);
	ret(26) = s*t(26);
    ret(27) = s*t(27);
    ret(28) = s*t(28);
    ret(29) = s*t(29);
    ret(30) = s*t(30);
	ret(31) = s*t(31);
	ret(32) = s*t(32);
	ret(33) = s*t(33);
	ret(34) = s*t(34);
	ret(35) = s*t(35);
	return ret;
}

sym_tensor4 operator *( const sym_tensor4& t, const double s ){
	sym_tensor4 ret;
	ret( 0) = s*t( 0);
	ret( 1) = s*t( 1);
	ret( 2) = s*t( 2);
	ret( 3) = s*t( 3);
	ret( 4) = s*t( 4);
	ret( 5) = s*t( 5);
	ret( 6) = s*t( 6);
    ret( 7) = s*t( 7);
    ret( 8) = s*t( 8);
    ret( 9) = s*t( 9);
    ret(10) = s*t(10);
	ret(11) = s*t(11);
	ret(12) = s*t(12);
	ret(13) = s*t(13);
	ret(14) = s*t(14);
	ret(15) = s*t(15);
	ret(16) = s*t(16);
    ret(17) = s*t(17);
    ret(18) = s*t(18);
    ret(19) = s*t(19);
    ret(20) = s*t(20);
	ret(21) = s*t(21);
	ret(22) = s*t(22);
	ret(23) = s*t(23);
	ret(24) = s*t(24);
	ret(25) = s*t(25);
	ret(26) = s*t(26);
    ret(27) = s*t(27);
    ret(28) = s*t(28);
    ret(29) = s*t(29);
    ret(30) = s*t(30);
	ret(31) = s*t(31);
	ret(32) = s*t(32);
	ret(33) = s*t(33);
	ret(34) = s*t(34);
	ret(35) = s*t(35);
	return ret;
}

sym_tensor4 operator /( const sym_tensor4& t, const double s ){
	sym_tensor4 ret;
	ret( 0) = t( 0)/s;
	ret( 1) = t( 1)/s;
	ret( 2) = t( 2)/s;
	ret( 3) = t( 3)/s;
	ret( 4) = t( 4)/s;
	ret( 5) = t( 5)/s;
	ret( 6) = t( 6)/s;
    ret( 7) = t( 7)/s;
    ret( 8) = t( 8)/s;
    ret( 9) = t( 9)/s;
    ret(10) = t(10)/s;
	ret(11) = t(11)/s;
	ret(12) = t(12)/s;
	ret(13) = t(13)/s;
	ret(14) = t(14)/s;
	ret(15) = t(15)/s;
	ret(16) = t(16)/s;
    ret(17) = t(17)/s;
    ret(18) = t(18)/s;
    ret(19) = t(19)/s;
    ret(20) = t(20)/s;
	ret(21) = t(21)/s;
	ret(22) = t(22)/s;
	ret(23) = t(23)/s;
	ret(24) = t(24)/s;
	ret(25) = t(25)/s;
	ret(26) = t(26)/s;
    ret(27) = t(27)/s;
    ret(28) = t(28)/s;
    ret(29) = t(29)/s;
    ret(30) = t(30)/s;
	ret(31) = t(31)/s;
	ret(32) = t(32)/s;
	ret(33) = t(33)/s;
	ret(34) = t(34)/s;
	ret(35) = t(35)/s;
	return ret;
}

}