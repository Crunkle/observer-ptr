// Copyright 2013-2018 by Martin Moene
//
// nonstd::observer_ptr<> is a C++98 onward implementation for std::observer_ptr as of C++17.
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#pragma once

#ifndef TEST_NONSTD_OBSERVER_PTR_H_INCLUDED
#define TEST_NONSTD_OBSERVER_PTR_H_INCLUDED

#include "observer_ptr.hpp"
#include "lest_cpp03.hpp"

using namespace nonstd;

#define CASE( name ) lest_CASE( specification(), name )

// Attribute externally visible for -fwhole-program:

#if defined(__GNUC__) && !defined(__clang__)
# define nsop_ATTRIBUTE_EXT_VIS  __attribute__((externally_visible))
#else
# define nsop_ATTRIBUTE_EXT_VIS
#endif

extern lest::tests & specification() nsop_ATTRIBUTE_EXT_VIS;

#if ! nsop_BETWEEN( nsop_COMPILER_MSVC_VERSION, 6, 7 )
namespace std {
#else
namespace lest {
#endif

template< typename W >
inline std::ostream & operator<<( std::ostream & os, observer_ptr<W> const & p )
{
    using ::lest::to_string;
    return os << "[observer_ptr:" << ( !!p.get() ? to_string(*p):"(empty)") << "]";
}

#if ! nsop_BETWEEN( nsop_COMPILER_MSVC_VERSION, 6, 7 )
} // namespace std
#else
} // namespace lest
#endif

#endif // TEST_NONSTD_OBSERVER_PTR_H_INCLUDED