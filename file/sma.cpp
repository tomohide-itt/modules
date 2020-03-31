#include "sma.h"

//_________________________________________________________________________________________________
//--- sma4_data -----------------------------------------------------------------------------------
sma4_data::sma4_data( string fname, int xn, int yn ) : file_name(fname), x_error_bar(0), y_error_bar(0),
		x_col_no(xn-1), y_col_no(yn-1), num_data(0), skip(0), num_line(-1), line_width(40),
		line_col(0,0,0), line_pitch(300), flag_tab(0), flag_abs(0), flag_comment(0),
		line_type(0), dot_type(1), dot_size(300), dot_col(0,0,0), x_ref(0), y_ref(0), intvl(1),
		h_nei_ave(0), v_nei_ave(0), fill_col(255,255,255), flag_x_val(0), flag_y_val(0),
		x_eq("x"), y_eq("y") {};

void sma4_data::show( std::ostream& stream ){
	stream << "[" << file_name << "]" << endl;
	stream << file_name << endl;
	writeline( stream, true, 0, 0, x_error_bar, y_error_bar, x_col_no, y_col_no, num_data,
		skip, num_line );
	writeline( stream, true, line_width, line_col.id(), line_pitch, flag_tab, flag_abs,
		flag_comment, 0 );
	writeline( stream, true, line_type, dot_type, dot_size, dot_col.id() );
	writeline( stream, true, x_ref, y_ref, intvl, h_nei_ave, v_nei_ave, 0, fill_col.id(), 5 );
	writeline( stream, true, flag_x_val, flag_y_val, 0 );
	writeline( stream, true, x_eq );
	writeline( stream, true, y_eq );
	writeline( stream, true, 0, 0, 0, 0, 0, 0, 0, 0, 0 );
	writeline( stream, true, 1, 40, 0, 300, 1 );
}

//_________________________________________________________________________________________________
//--- sma4_graph ----------------------------------------------------------------------------------
sma4_graph_header::sma4_graph_header() : left(4000), top(1500), width(14000), height(10000),
		zoom(100), type(1), line_width(40), line_col(0,0,0), back_col(255,255,255){}

void sma4_graph_header::show( std::ostream& stream ){
	stream << "[GRAPH]" << endl;
	writeline( stream, true, left, top, width, height );
	writeline( stream, true, zoom, type, 0, 0, 1, 0 );
	writeline( stream, true, line_width, line_col.id(), 300, back_col.id() );
	stream << endl;
}

//_________________________________________________________________________________________________
//--- sma4_axis -----------------------------------------------------------------------------------
sma4_axis::sma4_axis() : no(0), from(0.0), to(100.0), increment(20.0), range_begin(0),
		range_end(10000), cross_point(-1), gauge_num(-1), gauge_begin(0),
		gauge_intvl(1), flag_plus(0), flag_zero(0), flag_zero2(1),
		num_int(5), num_dec(5), flag_overline(1), division(5), type(0),
		flag_fig(1), right_shift(0), bottom_shift(100), fig_col(0,0,0),
		fig_size(-2400), font_name("Times New Roman"),
		mg_in(1), mg_out(0), mg_length(300), mg_line_width(40), mg_col(0,0,0), mg_pitch(300), mg_line_type(1),
		sg_in(1), sg_out(0), sg_length(150), sg_line_width(40), sg_col(0,0,0), sg_pitch(300), sg_line_type(1){
}

sma4_axis::sma4_axis( int no_ ) : no(no_), from(0.0), to(100.0), increment(20.0), range_begin(0),
	range_end(10000), cross_point(-1), gauge_num(-1), gauge_begin(0),
	gauge_intvl(1), flag_plus(0), flag_zero(0), flag_zero2(1),
	num_int(5), num_dec(5), flag_overline(1), division(5), type(0),
	flag_fig(1), right_shift(0), bottom_shift(100), fig_col(0,0,0),
	fig_size(-2400), font_name("Times New Roman"),
	mg_in(1), mg_out(0), mg_length(300), mg_line_width(40), mg_col(0,0,0), mg_pitch(300), mg_line_type(1),
	sg_in(1), sg_out(0), sg_length(150), sg_line_width(40), sg_col(0,0,0), sg_pitch(300), sg_line_type(1){
	if( no == 1 ){
		right_shift = -100; bottom_shift = 0;
	}else if( no == 2 ){
		right_shift = 0; bottom_shift = -100; flag_fig = 0;
	}else if( no == 3 ){
		right_shift = 100; bottom_shift = 0; flag_fig = 0;
	}
}

void sma4_axis::show( std::ostream& stream ){
	stream << "[AXIS-" << no << "]" << endl;
	writeline( stream, true, from, to, increment, 0, range_begin, range_end,
		cross_point, gauge_num, gauge_begin, gauge_intvl, flag_plus, flag_zero,
		flag_zero2, num_int, num_dec, 1, flag_overline );
	writeline( stream, true, division, type, 1, 1, 1, flag_fig, right_shift,
		bottom_shift, fig_col.id(), 300, 100 );
	writeline( stream, true, fig_size, 0, 0, 0, 400, 0, 0, 0, 0, 0, 0, 2, 18 );
	writeline( stream, true, font_name );
	writeline( stream, true, mg_in, mg_out, mg_length, mg_line_width, mg_col.id(), mg_pitch, mg_line_type );
	writeline( stream, true, sg_in, sg_out, sg_length, sg_line_width, sg_col.id(), sg_pitch, sg_line_type );
	stream << endl;
}

//_________________________________________________________________________________________________
//--- sma4_legend ---------------------------------------------------------------------------------
sma4_legend::sma4_legend() : no(1), pos_x(0), pos_y(0), size(-2400), degree(0),
		str(""), col(0,0,0), font1("Times New Roman"), font2("MS 明朝"), font3("Symbol"){}

void sma4_legend::show( std::ostream& stream ){
	stream << no << endl;
	writeline( stream, true, pos_x, pos_y, size, 1,1,0 );
	stream << str << endl;
	writeline( stream, true, size, 0, -degree, degree, 400, 0, 0 ,0, 162, 3, 2, 1, 18 );
	stream << font1 << endl;
	writeline( stream, true, size, 0, -degree, degree, 400, 0, 0 ,0, 121, 3, 2, 1, 17 );
	stream << font2 << endl;
	writeline( stream, true, size, 0, -degree, degree, 400, 0, 0 ,0, 2, 3, 2, 1, 18 );
	stream << font3 << endl;
	stream << endl;
}

void sma4_legend::setpos( const int x, const int y ){
	pos_x = x;
	pos_y = y;
}


//_________________________________________________________________________________________________
//--- sma4_graph ----------------------------------------------------------------------------------
void sma4_graph::add_data( const string filename, const int xn, const int yn ){
	sma4_data d(filename,xn,yn);
	data.push_back(d);
}

void sma4_graph::add_x_title( const string caption ){
	sma4_legend x_title;
	x_title.no = 4;
	x_title.str = caption;
	x_title.pos_x = graph_header.width/2;
	x_title.pos_y = graph_header.height+1800;
	legend.push_back(x_title);
}

void sma4_graph::add_y_title( const string caption ){
	sma4_legend y_title;
	y_title.no = 5;
	y_title.str = caption;
	y_title.pos_x = -1500;
	y_title.pos_y = graph_header.height/2;
	y_title.degree = 900;
	legend.push_back(y_title);
}

void sma4_graph::add_u_title( const string caption ){
	sma4_legend u_title;
	u_title.no = 6;
	u_title.str = caption;
	u_title.pos_x = graph_header.width/2;
	u_title.pos_y = -1500;
	legend.push_back(u_title);
}

void sma4_graph::add_r_title( const string caption ){
	sma4_legend r_title;
	r_title.no = 7;
	r_title.str = caption;
	r_title.pos_x = graph_header.width+1000;
	r_title.pos_y = graph_header.height/2;
	r_title.degree = 900;
	legend.push_back(r_title);
}

void sma4_graph::set_axis_range( const double f, const double t, int ax_no ){
	if( ax_no == 0 ){
		x_axis.from = f;
		x_axis.to = t;
	}else if( ax_no == 1 ){
		y_axis.from = f;
		y_axis.to = t;
	}else if( ax_no == 2 ){
		u_axis.from = f;
		u_axis.to = t;
	}else if( ax_no == 3 ){
		r_axis.from = f;
		r_axis.to = t;
	}
}

void sma4_graph::setpos( const int l, const int t, const int w, const int h ){
	graph_header.left = l;
	graph_header.top = t;
	graph_header.width = w;
	graph_header.height = h;
}

void sma4_graph::show( std::ostream& stream ){
	stream << " Sma4Win ver. 1.8  SMP file" << endl;
	stream << endl;
	writeline( stream, true, 0, 1, 210, 297, 0, 0, 2 );
	stream << data.size() << endl;
	for( int i=0; i<data.size(); i++ ){
		data[i].show(stream); stream << endl; stream << endl;
	}
	graph_header.show(stream);
	x_axis.show(stream);
	y_axis.show(stream);
	u_axis.show(stream);
	r_axis.show(stream);
	stream << "[LEGEND]" << endl;
	stream << legend.size() << endl;
	for( int i=0; i<legend.size(); i++ ){
		legend[i].show(stream);
	}
}

//_________________________________________________________________________________________________
//--- sma4_file -----------------------------------------------------------------------------------
void sma4_file::create( std::ofstream& stream ){
	if( graph.size() <= 0 ) return;
	stream << " Sma4Win ver. 1.1  SMA file" << endl;
	writeline( stream, true, graph.size(), 0, 0, 0, 0, 100 );
	for( int i=0; i<graph.size(); i++ ){
		stream << "[file-" << i << "]" << endl;
		graph[i].show(stream);
		stream << "[OTHERS]\n 0\n" << endl;
		stream << "[MASKS]\n 0\n0\n0\n" << endl;
	}
}