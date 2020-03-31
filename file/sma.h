#pragma once

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::ostream;
using std::istream;
using std::string;
using std::vector;
using std::cerr;
using std::endl;
using std::cout;
using std::cin;

class sma4_color{
private:
	int r, g, b;
public:
	sma4_color() : r(0), g(0), b(0){};
	sma4_color( int r_, int g_, int b_ ) : r(r_), g(g_), b(b_) {};
	int id(){ return r+256*g+256*256*b; }
	void set( int r_, int g_, int b_ ){ r = r_; g = g_; b = b_; }
	int red(){ return r; }
	int green(){ return g; }
	int blue(){ return b; }
};

class sma4_data{
public:
	string file_name;
	int x_error_bar, y_error_bar;
	int x_col_no, y_col_no;
	int num_data;
	int skip;
	int num_line;
	int line_width;
	sma4_color line_col;
	int line_pitch;
	int flag_tab, flag_abs, flag_comment;
	int line_type;
	int dot_type;
	int dot_size;
	sma4_color dot_col;
	int x_ref, y_ref;
	int intvl;
	int h_nei_ave, v_nei_ave;
	sma4_color fill_col;
	int flag_x_val, flag_y_val;
	string x_eq, y_eq;
	sma4_data( string fname, int xn, int yn );
	void show( std::ostream& stream = std::cout );
};

class sma4_graph_header{
public:
	int left, top, width, height, zoom, type, line_width;
	sma4_color line_col, back_col;
	sma4_graph_header();
	void show( std::ostream& stream = std::cout );
};

class sma4_axis{
public:
	double from, to, increment;
	int no;
	int range_begin, range_end, cross_point, gauge_num, gauge_begin, gauge_intvl,
		flag_plus, flag_zero, flag_zero2, num_int, num_dec, flag_overline,
		division, type, flag_fig, right_shift, bottom_shift, fig_size,
		mg_in, mg_out, mg_length, mg_line_width, mg_pitch, mg_line_type,
		sg_in, sg_out, sg_length, sg_line_width, sg_pitch, sg_line_type;
	sma4_color fig_col, mg_col, sg_col;
	string font_name;
	sma4_axis();
	sma4_axis( int no_ );
	void show( std::ostream& stream = std::cout );
};

class sma4_legend{
public:
	int no;
	int pos_x, pos_y, size, degree;
	string str, font1, font2, font3;
	sma4_color col;
	sma4_legend();
	void show( std::ostream& stream = std::cout );
	void setpos( const int x, const int y );
};

class sma4_graph{
public:
	vector<sma4_data> data;
	sma4_graph_header graph_header;
	sma4_axis x_axis, y_axis, u_axis, r_axis;
	vector<sma4_legend> legend;
	sma4_graph(){
		y_axis.no = 1; y_axis.right_shift=-100; y_axis.bottom_shift=   0;
		u_axis.no = 2; u_axis.right_shift=   0; u_axis.bottom_shift=-100; u_axis.flag_fig=0;
		r_axis.no = 3; r_axis.right_shift= 100; r_axis.bottom_shift=   0; r_axis.flag_fig=0;
	}
	void add_data( const string filename, const int xn, const int yn );
	void add_x_title( const string caption );
	void add_y_title( const string caption );
	void add_u_title( const string caption );
	void add_r_title( const string caption );
	void setpos( const int l, const int t, const int w, const int h );
	void set_axis_range( const double b, const double e, int ax_no=0 );
	void show( std::ostream& stream = std::cout );
};

class sma4_file{
public:
	vector<sma4_graph> graph;
	void add_graph(){
		sma4_graph g;
		graph.push_back(g);
	}
	void create( std::ofstream& stream );
};
