#include "tensor1.h"
#include "sym_tensor2.h"
#include "sym_tensor4.h"

namespace tens{
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// tens4 dot tens2
sym_tensor4 sym_tensor4::dot_prdct( const sym_tensor2& t ) const{
	sym_tensor4 ret;
	ret.elem[0*6+0] = elem[0*6+0]*t.elem[0] + elem[0*6+3]*t.elem[3] + elem[0*6+5]*t.elem[5];
	ret.elem[0*6+1] = elem[0*6+3]*t.elem[3] + elem[0*6+1]*t.elem[1] + elem[0*6+4]*t.elem[4];
	ret.elem[0*6+2] = elem[0*6+5]*t.elem[5] + elem[0*6+4]*t.elem[4] + elem[0*6+2]*t.elem[2];
	ret.elem[0*6+3] = elem[0*6+0]*t.elem[3] + elem[0*6+3]*t.elem[1] + elem[0*6+5]*t.elem[4];
	ret.elem[0*6+4] = elem[0*6+3]*t.elem[5] + elem[0*6+1]*t.elem[4] + elem[0*6+4]*t.elem[2];
	ret.elem[0*6+5] = elem[0*6+5]*t.elem[0] + elem[0*6+4]*t.elem[3] + elem[0*6+2]*t.elem[5];
	ret.elem[1*6+0] = elem[1*6+0]*t.elem[0] + elem[1*6+3]*t.elem[3] + elem[1*6+5]*t.elem[5];
	ret.elem[1*6+1] = elem[1*6+3]*t.elem[3] + elem[1*6+1]*t.elem[1] + elem[1*6+4]*t.elem[4];
	ret.elem[1*6+2] = elem[1*6+5]*t.elem[5] + elem[1*6+4]*t.elem[4] + elem[1*6+2]*t.elem[2];
	ret.elem[1*6+3] = elem[1*6+0]*t.elem[3] + elem[1*6+3]*t.elem[1] + elem[1*6+5]*t.elem[4];
	ret.elem[1*6+4] = elem[1*6+3]*t.elem[5] + elem[1*6+1]*t.elem[4] + elem[1*6+4]*t.elem[2];
	ret.elem[1*6+5] = elem[1*6+5]*t.elem[0] + elem[1*6+4]*t.elem[3] + elem[1*6+2]*t.elem[5];
	ret.elem[2*6+0] = elem[2*6+0]*t.elem[0] + elem[2*6+3]*t.elem[3] + elem[2*6+5]*t.elem[5];
	ret.elem[2*6+1] = elem[2*6+3]*t.elem[3] + elem[2*6+1]*t.elem[1] + elem[2*6+4]*t.elem[4];
	ret.elem[2*6+2] = elem[2*6+5]*t.elem[5] + elem[2*6+4]*t.elem[4] + elem[2*6+2]*t.elem[2];
	ret.elem[2*6+3] = elem[2*6+0]*t.elem[3] + elem[2*6+3]*t.elem[1] + elem[2*6+5]*t.elem[4];
	ret.elem[2*6+4] = elem[2*6+3]*t.elem[5] + elem[2*6+1]*t.elem[4] + elem[2*6+4]*t.elem[2];
	ret.elem[2*6+5] = elem[2*6+5]*t.elem[0] + elem[2*6+4]*t.elem[3] + elem[2*6+2]*t.elem[5];
	ret.elem[3*6+0] = elem[3*6+0]*t.elem[0] + elem[3*6+3]*t.elem[3] + elem[3*6+5]*t.elem[5];
	ret.elem[3*6+1] = elem[3*6+3]*t.elem[3] + elem[3*6+1]*t.elem[1] + elem[3*6+4]*t.elem[4];
	ret.elem[3*6+2] = elem[3*6+5]*t.elem[5] + elem[3*6+4]*t.elem[4] + elem[3*6+2]*t.elem[2];
	ret.elem[3*6+3] = elem[3*6+0]*t.elem[3] + elem[3*6+3]*t.elem[1] + elem[3*6+5]*t.elem[4];
	ret.elem[3*6+4] = elem[3*6+3]*t.elem[5] + elem[3*6+1]*t.elem[4] + elem[3*6+4]*t.elem[2];
	ret.elem[3*6+5] = elem[3*6+5]*t.elem[0] + elem[3*6+4]*t.elem[3] + elem[3*6+2]*t.elem[5];
	ret.elem[4*6+0] = elem[4*6+0]*t.elem[0] + elem[4*6+3]*t.elem[3] + elem[4*6+5]*t.elem[5];
	ret.elem[4*6+1] = elem[4*6+3]*t.elem[3] + elem[4*6+1]*t.elem[1] + elem[4*6+4]*t.elem[4];
	ret.elem[4*6+2] = elem[4*6+5]*t.elem[5] + elem[4*6+4]*t.elem[4] + elem[4*6+2]*t.elem[2];
	ret.elem[4*6+3] = elem[4*6+0]*t.elem[3] + elem[4*6+3]*t.elem[1] + elem[4*6+5]*t.elem[4];
	ret.elem[4*6+4] = elem[4*6+3]*t.elem[5] + elem[4*6+1]*t.elem[4] + elem[4*6+4]*t.elem[2];
	ret.elem[4*6+5] = elem[4*6+5]*t.elem[0] + elem[4*6+4]*t.elem[3] + elem[4*6+2]*t.elem[5];
	ret.elem[5*6+0] = elem[5*6+0]*t.elem[0] + elem[5*6+3]*t.elem[3] + elem[5*6+5]*t.elem[5];
	ret.elem[5*6+1] = elem[5*6+3]*t.elem[3] + elem[5*6+1]*t.elem[1] + elem[5*6+4]*t.elem[4];
	ret.elem[5*6+2] = elem[5*6+5]*t.elem[5] + elem[5*6+4]*t.elem[4] + elem[5*6+2]*t.elem[2];
	ret.elem[5*6+3] = elem[5*6+0]*t.elem[3] + elem[5*6+3]*t.elem[1] + elem[5*6+5]*t.elem[4];
	ret.elem[5*6+4] = elem[5*6+3]*t.elem[5] + elem[5*6+1]*t.elem[4] + elem[5*6+4]*t.elem[2];
	ret.elem[5*6+5] = elem[5*6+5]*t.elem[0] + elem[5*6+4]*t.elem[3] + elem[5*6+2]*t.elem[5];
	return ret;
}
sym_tensor4 sym_tensor4::dot_prdct( const sym_tensor2& t ){
	return ( static_cast<const sym_tensor4*>(this)->dot_prdct(t));
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// vec dot tens2
sym_tensor2 sym_tensor4::dbdot_prdct( const sym_tensor2& t ) const{
	sym_tensor2 ret;
	ret.elem[0] = t.elem[0]*elem[0*6+0] + t.elem[1]*elem[1*6+0] + t.elem[2]*elem[2*6+0]
	  + 2.0*(t.elem[3]*elem[3*6+0] + t.elem[4]*elem[4*6+0] + t.elem[5]*elem[5*6+0]);
	ret.elem[1] = t.elem[0]*elem[0*6+1] + t.elem[1]*elem[1*6+1] + t.elem[2]*elem[2*6+1]
	  + 2.0*(t.elem[3]*elem[3*6+1] + t.elem[4]*elem[4*6+1] + t.elem[5]*elem[5*6+1]);
	ret.elem[2] = t.elem[0]*elem[0*6+2] + t.elem[1]*elem[1*6+2] + t.elem[2]*elem[2*6+2]
	  + 2.0*(t.elem[3]*elem[3*6+2] + t.elem[4]*elem[4*6+2] + t.elem[5]*elem[5*6+2]);
	ret.elem[3] = t.elem[0]*elem[0*6+3] + t.elem[1]*elem[1*6+3] + t.elem[2]*elem[2*6+3]
	  + 2.0*(t.elem[3]*elem[3*6+3] + t.elem[4]*elem[4*6+3] + t.elem[5]*elem[5*6+3]);
	ret.elem[4] = t.elem[0]*elem[0*6+4] + t.elem[1]*elem[1*6+4] + t.elem[2]*elem[2*6+4]
	  + 2.0*(t.elem[3]*elem[3*6+4] + t.elem[4]*elem[4*6+4] + t.elem[5]*elem[5*6+4]);
	ret.elem[5] = t.elem[0]*elem[0*6+5] + t.elem[1]*elem[1*6+5] + t.elem[2]*elem[2*6+5]
	  + 2.0*(t.elem[3]*elem[3*6+5] + t.elem[4]*elem[4*6+5] + t.elem[5]*elem[5*6+5]);
	return ret;
}
sym_tensor2 sym_tensor4::dbdot_prdct( const sym_tensor2& t ){
	return ( static_cast<const sym_tensor4*>(this)->dbdot_prdct(t));
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// tens4 dbdot tens4
sym_tensor4 sym_tensor4::dbdot_prdct( const sym_tensor4& t ) const{
	sym_tensor4 ret;
	for( int i=0; i<6; i++ ){
		for( int j=0; j<6; j++ ){
			ret(i*6+j) = 0.0;
			for( int k=0; k<6; k++ ){
				if( k <   3 ) ret.elem[i*6+j] += elem[i*6+k]*t.elem[k*6+j];
				if( k >=  3 ) ret.elem[i*6+j] += 2.0*elem[i*6+k]*t.elem[k*6+j];
			}
		}
	}
	return ret;
}
sym_tensor4 sym_tensor4::dbdot_prdct( const sym_tensor4& t ){
	return ( static_cast<const sym_tensor4*>(this)->dbdot_prdct(t));	
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// binary operators
sym_tensor4 operator +( const sym_tensor4& t1, const sym_tensor4& t2 ){
	sym_tensor4 ret;
	ret.elem[ 0] = t1.elem[ 0] + t2.elem[ 0];
	ret.elem[ 1] = t1.elem[ 1] + t2.elem[ 1];
	ret.elem[ 2] = t1.elem[ 2] + t2.elem[ 2];
	ret.elem[ 3] = t1.elem[ 3] + t2.elem[ 3];
	ret.elem[ 4] = t1.elem[ 4] + t2.elem[ 4];
	ret.elem[ 5] = t1.elem[ 5] + t2.elem[ 5];
	ret.elem[ 6] = t1.elem[ 6] + t2.elem[ 6];
    ret.elem[ 7] = t1.elem[ 7] + t2.elem[ 7];
    ret.elem[ 8] = t1.elem[ 8] + t2.elem[ 8];
    ret.elem[ 9] = t1.elem[ 9] + t2.elem[ 9];
    ret.elem[10] = t1.elem[10] + t2.elem[10];
	ret.elem[11] = t1.elem[11] + t2.elem[11];
	ret.elem[12] = t1.elem[12] + t2.elem[12];
	ret.elem[13] = t1.elem[13] + t2.elem[13];
	ret.elem[14] = t1.elem[14] + t2.elem[14];
	ret.elem[15] = t1.elem[15] + t2.elem[15];
	ret.elem[16] = t1.elem[16] + t2.elem[16];
    ret.elem[17] = t1.elem[17] + t2.elem[17];
    ret.elem[18] = t1.elem[18] + t2.elem[18];
    ret.elem[19] = t1.elem[19] + t2.elem[19];
    ret.elem[20] = t1.elem[20] + t2.elem[20];
	ret.elem[21] = t1.elem[21] + t2.elem[21];
	ret.elem[22] = t1.elem[22] + t2.elem[22];
	ret.elem[23] = t1.elem[23] + t2.elem[23];
	ret.elem[24] = t1.elem[24] + t2.elem[24];
	ret.elem[25] = t1.elem[25] + t2.elem[25];
	ret.elem[26] = t1.elem[26] + t2.elem[26];
    ret.elem[27] = t1.elem[27] + t2.elem[27];
    ret.elem[28] = t1.elem[28] + t2.elem[28];
    ret.elem[29] = t1.elem[29] + t2.elem[29];
    ret.elem[30] = t1.elem[30] + t2.elem[30];
	ret.elem[31] = t1.elem[31] + t2.elem[31];
	ret.elem[32] = t1.elem[32] + t2.elem[32];
	ret.elem[33] = t1.elem[33] + t2.elem[33];
	ret.elem[34] = t1.elem[34] + t2.elem[34];
	ret.elem[35] = t1.elem[35] + t2.elem[35];
	return ret;
}

sym_tensor4 operator -( const sym_tensor4& t1, const sym_tensor4& t2 ){
	sym_tensor4 ret;
	ret.elem[ 0] = t1.elem[ 0] - t2.elem[ 0];
	ret.elem[ 1] = t1.elem[ 1] - t2.elem[ 1];
	ret.elem[ 2] = t1.elem[ 2] - t2.elem[ 2];
	ret.elem[ 3] = t1.elem[ 3] - t2.elem[ 3];
	ret.elem[ 4] = t1.elem[ 4] - t2.elem[ 4];
	ret.elem[ 5] = t1.elem[ 5] - t2.elem[ 5];
	ret.elem[ 6] = t1.elem[ 6] - t2.elem[ 6];
    ret.elem[ 7] = t1.elem[ 7] - t2.elem[ 7];
    ret.elem[ 8] = t1.elem[ 8] - t2.elem[ 8];
    ret.elem[ 9] = t1.elem[ 9] - t2.elem[ 9];
    ret.elem[10] = t1.elem[10] - t2.elem[10];
	ret.elem[11] = t1.elem[11] - t2.elem[11];
	ret.elem[12] = t1.elem[12] - t2.elem[12];
	ret.elem[13] = t1.elem[13] - t2.elem[13];
	ret.elem[14] = t1.elem[14] - t2.elem[14];
	ret.elem[15] = t1.elem[15] - t2.elem[15];
	ret.elem[16] = t1.elem[16] - t2.elem[16];
    ret.elem[17] = t1.elem[17] - t2.elem[17];
    ret.elem[18] = t1.elem[18] - t2.elem[18];
    ret.elem[19] = t1.elem[19] - t2.elem[19];
    ret.elem[20] = t1.elem[20] - t2.elem[20];
	ret.elem[21] = t1.elem[21] - t2.elem[21];
	ret.elem[22] = t1.elem[22] - t2.elem[22];
	ret.elem[23] = t1.elem[23] - t2.elem[23];
	ret.elem[24] = t1.elem[24] - t2.elem[24];
	ret.elem[25] = t1.elem[25] - t2.elem[25];
	ret.elem[26] = t1.elem[26] - t2.elem[26];
    ret.elem[27] = t1.elem[27] - t2.elem[27];
    ret.elem[28] = t1.elem[28] - t2.elem[28];
    ret.elem[29] = t1.elem[29] - t2.elem[29];
    ret.elem[30] = t1.elem[30] - t2.elem[30];
	ret.elem[31] = t1.elem[31] - t2.elem[31];
	ret.elem[32] = t1.elem[32] - t2.elem[32];
	ret.elem[33] = t1.elem[33] - t2.elem[33];
	ret.elem[34] = t1.elem[34] - t2.elem[34];
	ret.elem[35] = t1.elem[35] - t2.elem[35];
	return ret;
}

sym_tensor4 operator *( const double s, const sym_tensor4& t ){
	sym_tensor4 ret;
	ret.elem[ 0] = s*t.elem[ 0];
	ret.elem[ 1] = s*t.elem[ 1];
	ret.elem[ 2] = s*t.elem[ 2];
	ret.elem[ 3] = s*t.elem[ 3];
	ret.elem[ 4] = s*t.elem[ 4];
	ret.elem[ 5] = s*t.elem[ 5];
	ret.elem[ 6] = s*t.elem[ 6];
    ret.elem[ 7] = s*t.elem[ 7];
    ret.elem[ 8] = s*t.elem[ 8];
    ret.elem[ 9] = s*t.elem[ 9];
    ret.elem[10] = s*t.elem[10];
	ret.elem[11] = s*t.elem[11];
	ret.elem[12] = s*t.elem[12];
	ret.elem[13] = s*t.elem[13];
	ret.elem[14] = s*t.elem[14];
	ret.elem[15] = s*t.elem[15];
	ret.elem[16] = s*t.elem[16];
    ret.elem[17] = s*t.elem[17];
    ret.elem[18] = s*t.elem[18];
    ret.elem[19] = s*t.elem[19];
    ret.elem[20] = s*t.elem[20];
	ret.elem[21] = s*t.elem[21];
	ret.elem[22] = s*t.elem[22];
	ret.elem[23] = s*t.elem[23];
	ret.elem[24] = s*t.elem[24];
	ret.elem[25] = s*t.elem[25];
	ret.elem[26] = s*t.elem[26];
    ret.elem[27] = s*t.elem[27];
    ret.elem[28] = s*t.elem[28];
    ret.elem[29] = s*t.elem[29];
    ret.elem[30] = s*t.elem[30];
	ret.elem[31] = s*t.elem[31];
	ret.elem[32] = s*t.elem[32];
	ret.elem[33] = s*t.elem[33];
	ret.elem[34] = s*t.elem[34];
	ret.elem[35] = s*t.elem[35];
	return ret;
}

sym_tensor4 operator *( const sym_tensor4& t, const double s ){
	sym_tensor4 ret;
	ret.elem[ 0] = s*t.elem[ 0];
	ret.elem[ 1] = s*t.elem[ 1];
	ret.elem[ 2] = s*t.elem[ 2];
	ret.elem[ 3] = s*t.elem[ 3];
	ret.elem[ 4] = s*t.elem[ 4];
	ret.elem[ 5] = s*t.elem[ 5];
	ret.elem[ 6] = s*t.elem[ 6];
    ret.elem[ 7] = s*t.elem[ 7];
    ret.elem[ 8] = s*t.elem[ 8];
    ret.elem[ 9] = s*t.elem[ 9];
    ret.elem[10] = s*t.elem[10];
	ret.elem[11] = s*t.elem[11];
	ret.elem[12] = s*t.elem[12];
	ret.elem[13] = s*t.elem[13];
	ret.elem[14] = s*t.elem[14];
	ret.elem[15] = s*t.elem[15];
	ret.elem[16] = s*t.elem[16];
    ret.elem[17] = s*t.elem[17];
    ret.elem[18] = s*t.elem[18];
    ret.elem[19] = s*t.elem[19];
    ret.elem[20] = s*t.elem[20];
	ret.elem[21] = s*t.elem[21];
	ret.elem[22] = s*t.elem[22];
	ret.elem[23] = s*t.elem[23];
	ret.elem[24] = s*t.elem[24];
	ret.elem[25] = s*t.elem[25];
	ret.elem[26] = s*t.elem[26];
    ret.elem[27] = s*t.elem[27];
    ret.elem[28] = s*t.elem[28];
    ret.elem[29] = s*t.elem[29];
    ret.elem[30] = s*t.elem[30];
	ret.elem[31] = s*t.elem[31];
	ret.elem[32] = s*t.elem[32];
	ret.elem[33] = s*t.elem[33];
	ret.elem[34] = s*t.elem[34];
	ret.elem[35] = s*t.elem[35];
	return ret;
}

sym_tensor4 operator /( const sym_tensor4& t, const double s ){
	sym_tensor4 ret;
	ret.elem[ 0] = t.elem[ 0]/s;
	ret.elem[ 1] = t.elem[ 1]/s;
	ret.elem[ 2] = t.elem[ 2]/s;
	ret.elem[ 3] = t.elem[ 3]/s;
	ret.elem[ 4] = t.elem[ 4]/s;
	ret.elem[ 5] = t.elem[ 5]/s;
	ret.elem[ 6] = t.elem[ 6]/s;
    ret.elem[ 7] = t.elem[ 7]/s;
    ret.elem[ 8] = t.elem[ 8]/s;
    ret.elem[ 9] = t.elem[ 9]/s;
    ret.elem[10] = t.elem[10]/s;
	ret.elem[11] = t.elem[11]/s;
	ret.elem[12] = t.elem[12]/s;
	ret.elem[13] = t.elem[13]/s;
	ret.elem[14] = t.elem[14]/s;
	ret.elem[15] = t.elem[15]/s;
	ret.elem[16] = t.elem[16]/s;
    ret.elem[17] = t.elem[17]/s;
    ret.elem[18] = t.elem[18]/s;
    ret.elem[19] = t.elem[19]/s;
    ret.elem[20] = t.elem[20]/s;
	ret.elem[21] = t.elem[21]/s;
	ret.elem[22] = t.elem[22]/s;
	ret.elem[23] = t.elem[23]/s;
	ret.elem[24] = t.elem[24]/s;
	ret.elem[25] = t.elem[25]/s;
	ret.elem[26] = t.elem[26]/s;
    ret.elem[27] = t.elem[27]/s;
    ret.elem[28] = t.elem[28]/s;
    ret.elem[29] = t.elem[29]/s;
    ret.elem[30] = t.elem[30]/s;
	ret.elem[31] = t.elem[31]/s;
	ret.elem[32] = t.elem[32]/s;
	ret.elem[33] = t.elem[33]/s;
	ret.elem[34] = t.elem[34]/s;
	ret.elem[35] = t.elem[35]/s;
	return ret;
}

}