#ifndef MFILE
#define MFILE

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <iomanip>
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::ios_base;
using std::scientific;
using std::setprecision;
using std::setw;

void open_file_f( ifstream& fp, string fname, ios_base::openmode mode = ios_base::in );
void open_file_f( ofstream& fp, string fname, ios_base::openmode mode = ios_base::out );
string open_file_m( ifstream& fp, string message, ios_base::openmode mode = ios_base::in, string pfilename="" );
string open_file_m( ofstream& fp, string message, ios_base::openmode mode = ios_base::out, string pfilename="" );
void readline( ifstream& fp, string& str );

template< typename T >
void write_bin( ofstream& fp, T val ){
	fp.write( (const char*)&val, sizeof(T) );
}

template<>
void write_bin( ofstream& fp, double val );

template<>
void write_bin( ofstream& fp, bool val );

template< typename T >
T read_bin( ifstream& fp ){
	T val;
	fp.read( (char*)&val, sizeof(T) );
	return val;
}

template<>
double read_bin( ifstream& fp );

template<>
bool read_bin( ifstream& fp );

template< typename T >
T str_to_num( const string& str, T fail = 0 ){
	if( str.empty() ){
		return fail;
	}else{
		return T( stod(str) );
	}
}

template<>
bool str_to_num( const string& str, bool fail );

template<typename T>
vector<string> split( const string& str, const T& sep ){
	vector<string> vecstr;
	string sub_str = "";
	int cnt = 0;
	while( cnt <= str.size() ){
		char c = str[cnt];
		if( c == sep || cnt == str.size() ){
			if( !sub_str.empty() ){
				vecstr.push_back( sub_str );
				sub_str.clear();
			}
		}else{
			sub_str += c;
		}
		cnt++;
	}
	return vecstr;
}

template< typename First, typename... DIM >
void writeline( std::ostream& stream, bool lf, First first, DIM... dim ){
	stream << first << " ";
	writeline( stream, lf, dim... );
}

template< typename First >
void writeline( std::ostream& stream, bool lf, First first ){
	stream << first;
	if( lf ) stream << endl;
}

#endif