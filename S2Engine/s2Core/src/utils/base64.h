//
//  base64 encoding and decoding with C++.
//  Version: 1.01.00
//
#ifndef BASE64_H_C0CE2A47_D10E_42C9_A27C_C883944E704A
#define BASE64_H_C0CE2A47_D10E_42C9_A27C_C883944E704A

#include "s2Core_API.h"

#include <string>

namespace s2 {

std::string S2CORE_API base64_encode( const std::string & );
std::string S2CORE_API base64_encode( unsigned char const*, unsigned int len );
std::string S2CORE_API base64_decode( std::string const& s );

}

#endif /* BASE64_H_C0CE2A47_D10E_42C9_A27C_C883944E704A */
