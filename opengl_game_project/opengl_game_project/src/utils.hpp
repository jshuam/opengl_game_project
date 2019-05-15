#pragma once

#include <initguid.h>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <guiddef.h>
#include <vcruntime_string.h>

static void APIENTRY glCheckErrors(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam)
{
	const char* m_source, *m_type, *m_severity;

	switch(source)
	{
		case GL_DEBUG_SOURCE_API:
			m_source = "API";
			break;

		case GL_DEBUG_SOURCE_WINDOW_SYSTEM:
			m_source = "WINDOW SYSTEM";
			break;

		case GL_DEBUG_SOURCE_SHADER_COMPILER:
			m_source = "SHADER COMPILER";
			break;

		case GL_DEBUG_SOURCE_THIRD_PARTY:
			m_source = "THIRD PARTY";
			break;

		case GL_DEBUG_SOURCE_APPLICATION:
			m_source = "APPLICATION";
			break;

		case GL_DEBUG_SOURCE_OTHER:
			m_source = "UNKNOWN";
			break;

		default:
			m_source = "UNKNOWN";
			break;
	}

	switch(type)
	{
		case GL_DEBUG_TYPE_ERROR:
			m_type = "ERROR";
			break;

		case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
			m_type = "DEPRECATED BEHAVIOR";
			break;

		case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
			m_type = "UDEFINED BEHAVIOR";
			break;

		case GL_DEBUG_TYPE_PORTABILITY:
			m_type = "PORTABILITY";
			break;

		case GL_DEBUG_TYPE_PERFORMANCE:
			m_type = "PERFORMANCE";
			break;

		case GL_DEBUG_TYPE_OTHER:
			m_type = "OTHER";
			break;

		case GL_DEBUG_TYPE_MARKER:
			m_type = "MARKER";
			break;

		default:
			m_type = "UNKNOWN";
			break;
	}

	switch(severity)
	{
		case GL_DEBUG_SEVERITY_HIGH:
			m_severity = "HIGH";
			break;

		case GL_DEBUG_SEVERITY_MEDIUM:
			m_severity = "MEDIUM";
			break;

		case GL_DEBUG_SEVERITY_LOW:
			m_severity = "LOW";
			break;

		case GL_DEBUG_SEVERITY_NOTIFICATION:
			m_severity = "NOTIFICATION";
			break;

		default:
			m_severity = "UNKNOWN";
			break;
	}

	/* If the severity is higher than notification, then print the message and break execution */
	if(severity > GL_DEBUG_SEVERITY_NOTIFICATION)
	{
		printf("[ERROR %d] %s of %s severity, raised from %s: \n%s\n", id, m_type, m_severity, m_source, message);
	}
}

struct GUIDComparator
{
	bool operator()(const GUID& left, const GUID& right) const
	{
		return memcmp(&left, &right, sizeof(right)) < 0;
	}
};
