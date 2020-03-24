#include "file.h"

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// open_file_f
void open_file_f( ifstream& fp, string fname, ios_base::openmode mode ){
	fp.open( fname, mode );
	if( !fp ){
		cout << fname << " could not be opened." << endl;
	}
}

void open_file_f( ofstream& fp, string fname, ios_base::openmode mode ){
	fp.open( fname, mode );
	if( !fp ){
		cout << fname << " could not be opened." << endl;
	}
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// open_file_m
string open_file_m( ifstream& fp, string message, ios_base::openmode mode, string pfilename ){
	string fname;
	cout << message;
	cin >> fname;
	if( fname == pfilename ){
		cout << "prohibeted file name is specified." << endl;
		exit(1);
	}
	fp.open( fname, mode );
	if( !fp ){
		cout << fname << " could not be opened." << endl;
		exit(1);
	}
	return fname;
}

string open_file_m( ofstream& fp, string message, ios_base::openmode mode, string pfilename ){
	string fname;
	cout << message;
	cin >> fname;
	if( fname == pfilename ){
		cout << "prohibeted file name is specified." << endl;
		exit(1);
	}
	fp.open( fname, mode );
	if( !fp ){
		cout << fname << " could not be opened." << endl;
		exit(1);
	}
	return fname;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// readline
void readline( ifstream& fp, string& str ){
	getline( fp, str );
	size_t slash_pos = str.find("//");
	if( slash_pos != std::string::npos ){
		str.erase( slash_pos );
	}
	if( str[0] == '#' || str.empty() ){
		readline( fp, str );
	}
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// write_bin
template<>
void write_bin( ofstream& fp, double val ){
	float valf = (float)val;
	fp.write( (const char*)&valf, sizeof(float) );
}

template<>
void write_bin( ofstream& fp, bool val ){
	int vali = 0;
	if( val ) vali = 1;
	fp.write( (const char*)&vali, sizeof(int) );
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// read_bin
template<>
double read_bin( ifstream& fp ){
	float valf;
	fp.read( (char*)&valf, sizeof(float) );
	return (double)valf;
}

template<>
bool read_bin( ifstream& fp ){
	int vali;
	fp.read( (char*)&vali, sizeof(int) );
	return bool( vali );
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// str_to_num
template<>
bool str_to_num( const string& str, bool fail ){
	if( str.empty() ){
		return fail;
	}else{
		int i = stoi( str );
		if( i != 0 ){
			return true;
		}else{
			return false;
		}
	}
}