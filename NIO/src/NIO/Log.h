#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include <memory>

/*日志系统, 使用spdLog库*/
namespace NIO {

	class NIO_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger; 

	};
}

#define NIO_CORE_ERROR(...) ::NIO::Log::GetCoreLogger()->error(__VA_ARGS__)
#define NIO_CORE_WARN(...) ::NIO::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define NIO_CORE_INFO(...) ::NIO::Log::GetCoreLogger()->info(__VA_ARGS__)
#define NIO_CORE_TRACE(...) ::NIO::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define NIO_CORE_FATAL(...) ::NIO::Log::GetCoreLogger()->fatal(__VA_ARGS__)


#define NIO_ERROR(...) ::NIO::Log::GetClientLogger()->error(__VA_ARGS__)
#define NIO_WARN(...) ::NIO::Log::GetClientLogger()->warn(__VA_ARGS__)
#define NIO_INFO(...) ::NIO::Log::GetClientLogger()->info(__VA_ARGS__)
#define NIO_TRACE(...) ::NIO::Log::GetClientLogger()->trace(__VA_ARGS__)
#define NIO_FATAL(...) ::NIO::Log::GetClientLogger()->fatal(__VA_ARGS__)


