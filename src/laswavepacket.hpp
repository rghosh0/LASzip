/*
===============================================================================

  FILE:  laswavepacket.hpp
  
  CONTENTS:
  
    LASwavepacketXX classes for easy reuse among compressor/decompressor.

  PROGRAMMERS:

    martin.isenburg@rapidlasso.com  -  http://rapidlasso.com
    uday.karan@gmail.com - http://github.com/verma

  COPYRIGHT:

    (c) 2007-2012, martin isenburg, rapidlasso - fast tools to catch reality

    This is free software; you can redistribute and/or modify it under the
    terms of the GNU Lesser General Licence as published by the Free Software
    Foundation. See the COPYING file for more information.

    This software is distributed WITHOUT ANY WARRANTY and without even the
    implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  
  CHANGE HISTORY:
  
      10 April 2014 - Refactor LASwavepacket and add other functions to it.
  
===============================================================================
*/

#ifndef LAS_WAVEPACKET_HPP
#define LAS_WAVEPACKET_HPP

#include "mydefs.hpp"

struct LASwavepacket13
{
  U64 offset;
  U32 packet_size;
  U32I32F32 return_point;
  U32I32F32 x;
  U32I32F32 y;
  U32I32F32 z;

  static inline LASwavepacket13 make(const U8* item) {
    // Make a lAS wavepacket out of raw memory
    LASwavepacket13 r;

    r.offset = makeU64(item);
    r.packet_size = makeU32(item + 8);
    r.return_point.u32 = makeU32(item + 12);

    r.x.u32 = makeU32(item + 16);
    r.y.u32 = makeU32(item + 20);
    r.z.u32 = makeU32(item + 24);

    return r;
  }
  
  void inline lay(U8 *item) {
    // layout this packet into given memory
    //
    layU32((U32)(offset & 0xFFFFFFFF), item);
    layU32((U32)(offset >> 32), item+4);

    layU32(packet_size, item + 8);
    layU32(return_point.u32, item + 12);
    layU32(x.u32, item + 16);
    layU32(y.u32, item + 20);
    layU32(z.u32, item + 24);
  }

private:
  static inline U64 makeU64(const U8* item) {
    U64 dw0 = (U64)makeU32(item);
    U64 dw1 = (U64)makeU32(item+4);

    return dw0 | (dw1 << 32);
  }

  static inline U32 makeU32(const U8 *item) {
    U64 b0 = (U64)item[0];
    U64 b1 = (U64)item[1];
    U64 b2 = (U64)item[2];
    U64 b3 = (U64)item[3];

    return b0 | (b1 << 8) | (b2 << 16) | (b3 << 24);
  }
  static inline void layU32(U32 v, U8 *item) {
	  item[0] = v & 0xFF;
	  item[1] = (v >> 8) & 0xFF;
	  item[2] = (v >> 16) & 0xFF;
	  item[3] = (v >> 24) & 0xFF;
  }
};

#endif // LAS_WAVEPACKET_HPP

// vim: ts=2:sw=2:expandtabs
