#pragma once
typedef enum {
	ERR_OK,
	ERR_INVALID_ARG,
	ERR_FILE_OPEN,
	ERR_FILE_READ,
	ERR_MEM,
	ERR_NO_OBJECT,
	ERR_ANGLE,
	ERR_D, 
	ERR_K,
	ERR_UNKNOWN
} error_t;

System::String^ error_controller(error_t rc);