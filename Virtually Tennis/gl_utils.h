#ifndef _GL_UTILS_H_
#define _GL_UTILS_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

// Include GLM (OpenGL Mathematics)
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
using namespace glm; // Save having to type glm:: everywhere

struct plane {
	mat4 model_matrix;
	int point_count;
	GLuint textureID;
	vec3 pos, rot;
};

bool start_gl (int width, int height);
GLuint link_programme_from_files (const char* vs_file_name,
	const char* fs_file_name);
GLuint create_texture_from_file (const char* file_name);

bool parse_file_into_str (const char* file_name, char* shader_str);
long get_file_size (const char* file_name);

void reserve_video_memory ();
void grab_video_frame ();
bool dump_video_frame ();
bool dump_video_frames ();
bool screenshot ();

bool createPlane(
	plane * planePointer,
	float*& points,
	float*& uvs,
	vec2 dim,
	vec3 pos,
	vec3 rot,
	const char * imagePath
	);

// check a secondary framebuffer was created okay
bool verify_bound_framebuffer ();

extern int gl_width;
extern int gl_height;
extern bool full_screen;
extern GLFWwindow* gl_window;
extern int myargc;
extern char** myargv;
extern int g_video_fps;
extern int g_video_seconds_total;

extern int draws;
extern int uniforms;
extern int verts;
extern int frames;

#endif