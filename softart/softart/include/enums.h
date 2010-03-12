#ifndef SOFTART_ENUMS_H
#define SOFTART_ENUMS_H

#include "eflib/include/stl_utilities.h"
#include <boost/smart_ptr.hpp>
#include <string>
#include "softart_fwd.h"
BEGIN_NS_SOFTART()


#define BEGIN_ENUM(enum_type) enum enum_type{
#define END_ENUM(enum_type) enum_type##_invalid_value = 0x7FFFFFFF, enum_type##_invalid
/**********************************
 * Device
 *********************************/
struct result
{
	typedef int result_code_type;
	typedef boost::shared_ptr<std::_tstring> desc_type;

	static const result ok;
	static const result failed;
	static const result outofmemory;
	static const result invalid_parameter;

	result(result_code_type code, const std::_tstring& desc_str) : code_(code), desc_( new std::_tstring(desc_str) ){}
	result(result_code_type code, const std::_tchar* desc_str) : code_(code), desc_( new std::_tstring(desc_str) ){}
	result(result_code_type code, boost::shared_ptr<std::_tstring> pdesc = boost::shared_ptr<std::_tstring>())
		: code_(code), desc_(pdesc){}

	result(const result& rhs):code_(rhs.code_), desc_(rhs.desc_){}
	result& operator = (const result& rhs){
		code_ = rhs.code_;
		desc_ = rhs.desc_;
	}

	const std::_tstring& desc(){
		return *desc_;
	}

	result_code_type code(){
		return code_;
	}

	operator bool(){
		return code_ == ok.code_;
	}

	bool operator !(){
		return code_ != ok.code_;
	}

private:
	result(){}

	result_code_type code_;
	desc_type desc_;
};

/**********************************
 *  Resources
 *********************************/
enum lock_mode
{
	lock_read_only = 1,
	lock_write_only = 2,
	lock_read_write = 3,
};

/***************************
 * Input Assembler
 **************************/
#define RESERVED(i) 0xFFFF0000 + i
enum primitive_topology
{
	primitive_point_list = RESERVED(0),
	primitive_point_sprite = RESERVED(1),
	
	primitive_line_list = 0,
	primitive_line_strip = 1,
	
	primitive_triangle_list = 2,
	primitive_triangle_fan = 3,
	primitive_triangle_strip = 4,

	primivite_topology_count = 5
};

enum index_type
{
	index_int16 = 0,
	index_int32 = 1,

	index_type_count = 2
};

enum cull_mode
{
	cull_none = 0,
	cull_front = 1,
	cull_back = 2,

	cull_mode_count = 3,


};

enum fill_mode
{
	fill_wireframe = 0,
	fill_solid = 1,

	fill_mode_count = 2
};

/****************************
 * Texture
 ***************************/
enum address_mode
{
	address_wrap = 0,
	address_mirror = 1,
	address_clamp = 2,
	address_border = 3,
	address_mode_count = 4
};

enum filter_type
{
	filter_none = 0,
	filter_point = 1,
	filter_linear = 2,
	filter_type_count = 3
};

enum sampler_state
{
	sampler_state_min = 0,
	sampler_state_mag = 1,
	sampler_state_mip = 2,
	sampler_state_count = 3
};

enum sampler_axis
{
	sampler_axis_u = 0,
	sampler_axis_v = 1,
	sampler_axis_w = 2,
	sampler_axis_count = 3
};

enum cubemap_faces
{
	cubemap_face_positive_x = 0,
	cubemap_face_negative_x = 1,
	cubemap_face_positive_y = 2,
	cubemap_face_negative_y = 3,
	cubemap_face_positive_z = 4,
	cubemap_face_negative_z = 5,
	cubemap_faces_count = 6
};

/****************************
 * Shader
 ***************************/
// 该项指示在所给数据不足float4的时候补全方式：
// Position补齐为(0, 0, 0, 1)的形式；
// Attrib 补齐为(0,0,0,0)的形式
enum input_register_usage_decl
{
	input_register_usage_position = 0,
	input_register_usage_attribute = 1,
	input_register_usage_decl_count = 2
};

/****************************
 * Framebuffer
 ***************************/
enum render_target
{
	render_target_color = 0,
	render_target_depth = 1,
	render_target_stencil = 2,
	render_target_count = 3
};

END_NS_SOFTART()

#endif