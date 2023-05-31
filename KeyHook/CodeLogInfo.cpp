#include "typedef.h"
#include "CodeLogInfo.h"
#include <format>

namespace LogUtils {
	CodeLogInfo::CodeLogInfo(std::string message, DWORD errorCode, const char* __fname, const int __fline) {
		m_message = message;
		m_errorCode = errorCode;
		m_fname = __fname;
		m_fline = __fline;
	}

	std::string CodeLogInfo::message() {
		return std::format("Function = {:s}({:d}), Code = 0x{:x}({:d}), Msg = {:s}",
			m_fname,
			m_fline,
			m_errorCode,
			m_errorCode,
			m_message
		);
	}
}