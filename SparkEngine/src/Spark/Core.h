#pragma once
#include <memory>

#ifdef SPARK_PLATFORM_WINDOWS
#if SPARK_DYNAMIC_LINK
	#ifdef SPARK_BUILD_DLL
		#define SPARK_API __declspec(dllexport)
	#else
		#define SPARK_API __declspec(dllimport)
	#endif
#else
#define SPARK_API
#endif
#else
	#error SPARK CURRENTLY ONLY SUPPORTS WINDOWS
#endif

#ifdef SPARK_ENABLE_ASSERTS
	#define SPARK_ASSERT(x, ...) { if(!(x)) { SPARK_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
	#define SPARK_CORE_ASSERT(x, ...) { if(!(x)) { SPARK_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#else
	#define SPARK_ASSERT(x, ...)
	#define SPARK_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

namespace Spark
{
	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T>
	using Ref = std::shared_ptr<T>;
}