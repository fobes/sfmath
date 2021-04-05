#pragma once

#ifdef EXPORT_API
#define MATHS_API __declspec(dllexport)
#else
#define MATHS_API __declspec(dllimport)
#endif