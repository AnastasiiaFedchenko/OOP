#include "Errors.h"

System::String^ error_controller(error_t rc)
{
	System::String^ str;
	if (rc == ERR_INVALID_ARG)
		str = "В одну из функций был передан невалидный параметр.";
	else if (rc == ERR_FILE_OPEN)
		str = "Произошла ошибка при попытке открыть файл.";
	else if (rc == ERR_FILE_READ)
		str = "Произошла ошибка при чтении файла, возможно проблема в неправильной структуре.";
	else if (rc == ERR_MEM)
		str = "Произошла ошибка выделени памяти.";
	else if (rc == ERR_NO_OBJECT)
		str = "Не выбран объект для произведения преобразований.";
	else if (rc == ERR_ANGLE)
		str = "Ошибка ввода данных, угол поворота должен быть целым числом.";
	else if (rc == ERR_D)
		str = "Ошибка ввода данных, смещение должно быть целым числом.";
	else if (rc == ERR_K)
		str = "Ошибка ввода данных, коэфициент масштабирования должно быть вещественным числом (через запятую).";
	else if (rc == ERR_UNKNOWN)
		str = "Неизвестная ошибка.";
	else
		str = "Ошибка)";
	return str;
}