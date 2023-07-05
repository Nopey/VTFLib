/*
 * VTFLib
 * Copyright (C) 2005-2011 Neil Jedrzejewski & Ryan Gregg

 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later
 * version.
 */

// ============================================================
// NOTE: This file is commented for compatibility with Doxygen.
// ============================================================
/*!
	\file StdAfx.h
	\brief Application framework header plus VTFLib custom data types.
*/

#ifndef STDAFX_H
#define STDAFX_H

#ifdef VTFLIB_EXPORTS
#	if defined(_MSC_VER) && !defined(VTFLIB_STATIC)
#		define VTFLIB_API __declspec(dllexport)
#	elif defined(__clang__) || defined(__GNUC__)
#		define VTFLIB_API	__attribute__((visibility("default")))
#	else
#		define VTFLIB_API
#	endif
#else
#	if defined(_WIN32) && !defined(VTFLIB_STATIC)
#		define VTFLIB_API __declspec(dllimport)
#	else
#		define VTFLIB_API
#	endif
#endif

#include <cstdint>

// Custom data types
typedef unsigned char	vlBool;				//!< Boolean value 0/1.
typedef char			vlChar;				//!< Single signed character.
typedef unsigned char	vlByte;				//!< Single unsigned byte.
typedef signed short	vlShort;			//!< Signed short floating point value.
typedef unsigned short	vlUShort;			//!< Unsigned short floating point value.
typedef signed int		vlInt;				//!< Signed integer value.
typedef unsigned int	vlUInt;				//!< Unsigned integer value.
typedef signed long		vlLong;				//!< Signed long number.
typedef unsigned long	vlULong;			//!< Unsigned long number.
typedef float			vlSingle;			//!< Floating point number
typedef double			vlDouble;			//!< Double number
typedef void			vlVoid;				//!< Void value.

typedef std::uint8_t	vlUInt8;
typedef std::uint16_t	vlUInt16;
typedef std::uint32_t	vlUInt32;
typedef std::uint64_t	vlUInt64;

typedef std::int8_t		vlInt8;
typedef std::int16_t	vlInt16;
typedef std::int32_t	vlInt32;
typedef std::int64_t	vlInt64;

typedef vlSingle		vlFloat;			//!< Floating point number (same as vlSingled).

static inline constexpr vlBool vlFalse = 0;
static inline constexpr vlBool vlTrue = 1;

struct vlUInt128
{
	vlUInt64 low = 0;
	vlUInt64 high = 0;
	vlUInt128() = default;
	template<typename vlUIntx>
	vlUInt128( vlUIntx low ) : low( low ) {}
	vlUInt128( vlUInt64 low, vlUInt64 high ) : low( low ), high( high )
	{}
	template <typename vlUIntx>
	operator vlUIntx()
	{
		if ( high > 0 )
		{
			// set a breakpoint here
			return (vlUIntx)-1;
		}

		// drop high bits
		return (vlUIntx)low;
	}
	vlUInt128 operator<<( vlUInt128 shift ) const
	{
		if ( shift.low == 0 )
			return *this;

		// huge shift
		if (shift.low >= 64)
			return vlUInt128(0, low << (shift.low - 64));

		// small shift
		return vlUInt128( low << shift.low, high << shift.low | low >> ( 64 - shift.low ) );
	}
	vlUInt128 operator>>( vlUInt128 shift ) const
	{
		if ( shift.low == 0 )
			return *this;

		// huge shift
		if ( shift.low >= 64 )
			return vlUInt128( high >> ( shift.low - 64 ), 0 );
		// small shift
		return vlUInt128( low >> shift.low | high << ( 64 - shift.low ), high >> shift.low );
	}
	vlUInt128 operator*( vlUInt128 rhs ) const
	{
		// ignore rhs's high bits
		vlUInt128 x( low * rhs.low, high * rhs.low + low / UINT32_MAX * rhs.low / UINT32_MAX );
		return x;
	}
	vlUInt128 operator|( vlUInt128 const &rhs ) const
	{
		return vlUInt128( low | rhs.low, high | rhs.high );
	}
	vlUInt128 operator&( vlUInt128 const &rhs ) const
	{
		return vlUInt128( low & rhs.low, high & rhs.high );
	}
};

#if _MSC_VER >= 1400
#	define _CRT_SECURE_NO_WARNINGS
#	define _CRT_NONSTDC_NO_DEPRECATE
#endif

#ifdef _WIN32
#	define WIN32_LEAN_AND_MEAN
#	include <windows.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdarg.h>
#include <string.h>
#include <memory.h>
#include <ctype.h>
#include <cstring>

#ifdef __unix__
#	define stricmp strcasecmp
#	define _stricmp strcasecmp
#endif

#if _MSC_VER >= 1600 // Visual Studio 2010
#	define STATIC_ASSERT(condition, message) static_assert(condition, message)
#else
#	define STATIC_ASSERT(condition, message) typedef char __C_ASSERT__[(condition) ? 1 : -1]
#endif

#endif
