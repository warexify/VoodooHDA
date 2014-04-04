/* APPLE LOCAL file mainline 2005-06-30 Radar 4131077 */
/* Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007
   Free Software Foundation, Inc.

   This file is part of GCC.

   GCC is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   GCC is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with GCC; see the file COPYING.  If not, write to
   the Free Software Foundation, 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, if you include this header file into source
   files compiled by GCC, this header file does not by itself cause
   the resulting executable to be covered by the GNU General Public
   License.  This exception does not however invalidate any other
   reasons why the executable file might be covered by the GNU General
   Public License.  */

/* Implemented from the specification included in the Intel C++ Compiler
   User Guide and Reference, version 9.0.  */

#ifndef _MMINTRIN_H_INCLUDED
#define _MMINTRIN_H_INCLUDED

#ifdef __clang__

/*===---- mmintrin.h - MMX intrinsics --------------------------------------===
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 *===-----------------------------------------------------------------------===
 */

#ifndef __MMINTRIN_H
#define __MMINTRIN_H

#ifndef __MMX__
#error "MMX instruction set not enabled"
#else

typedef long long __m64 __attribute__((__vector_size__(8)));

typedef int __v2si __attribute__((__vector_size__(8)));
typedef short __v4hi __attribute__((__vector_size__(8)));
typedef char __v8qi __attribute__((__vector_size__(8)));

static __inline__ void __attribute__((__always_inline__, __nodebug__))
_mm_empty(void)
{
    __builtin_ia32_emms();
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_cvtsi32_si64(int __i)
{
    return (__m64)__builtin_ia32_vec_init_v2si(__i, 0);
}

static __inline__ int __attribute__((__always_inline__, __nodebug__))
_mm_cvtsi64_si32(__m64 __m)
{
    return __builtin_ia32_vec_ext_v2si((__v2si)__m, 0);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_cvtsi64_m64(long long __i)
{
    return (__m64)__i;
}

static __inline__ long long __attribute__((__always_inline__, __nodebug__))
_mm_cvtm64_si64(__m64 __m)
{
    return (long long)__m;
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_packs_pi16(__m64 __m1, __m64 __m2)
{
    return (__m64)__builtin_ia32_packsswb((__v4hi)__m1, (__v4hi)__m2);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_packs_pi32(__m64 __m1, __m64 __m2)
{
    return (__m64)__builtin_ia32_packssdw((__v2si)__m1, (__v2si)__m2);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_packs_pu16(__m64 __m1, __m64 __m2)
{
    return (__m64)__builtin_ia32_packuswb((__v4hi)__m1, (__v4hi)__m2);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_unpackhi_pi8(__m64 __m1, __m64 __m2)
{
    return (__m64)__builtin_ia32_punpckhbw((__v8qi)__m1, (__v8qi)__m2);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_unpackhi_pi16(__m64 __m1, __m64 __m2)
{
    return (__m64)__builtin_ia32_punpckhwd((__v4hi)__m1, (__v4hi)__m2);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_unpackhi_pi32(__m64 __m1, __m64 __m2)
{
    return (__m64)__builtin_ia32_punpckhdq((__v2si)__m1, (__v2si)__m2);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_unpacklo_pi8(__m64 __m1, __m64 __m2)
{
    return (__m64)__builtin_ia32_punpcklbw((__v8qi)__m1, (__v8qi)__m2);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_unpacklo_pi16(__m64 __m1, __m64 __m2)
{
    return (__m64)__builtin_ia32_punpcklwd((__v4hi)__m1, (__v4hi)__m2);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_unpacklo_pi32(__m64 __m1, __m64 __m2)
{
    return (__m64)__builtin_ia32_punpckldq((__v2si)__m1, (__v2si)__m2);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_add_pi8(__m64 __m1, __m64 __m2)
{
    return (__m64)__builtin_ia32_paddb((__v8qi)__m1, (__v8qi)__m2);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_add_pi16(__m64 __m1, __m64 __m2)
{
    return (__m64)__builtin_ia32_paddw((__v4hi)__m1, (__v4hi)__m2);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_add_pi32(__m64 __m1, __m64 __m2)
{
    return (__m64)__builtin_ia32_paddd((__v2si)__m1, (__v2si)__m2);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_adds_pi8(__m64 __m1, __m64 __m2)
{
    return (__m64)__builtin_ia32_paddsb((__v8qi)__m1, (__v8qi)__m2);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_adds_pi16(__m64 __m1, __m64 __m2)
{
    return (__m64)__builtin_ia32_paddsw((__v4hi)__m1, (__v4hi)__m2);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_adds_pu8(__m64 __m1, __m64 __m2)
{
    return (__m64)__builtin_ia32_paddusb((__v8qi)__m1, (__v8qi)__m2);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_adds_pu16(__m64 __m1, __m64 __m2)
{
    return (__m64)__builtin_ia32_paddusw((__v4hi)__m1, (__v4hi)__m2);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_sub_pi8(__m64 __m1, __m64 __m2)
{
    return (__m64)__builtin_ia32_psubb((__v8qi)__m1, (__v8qi)__m2);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_sub_pi16(__m64 __m1, __m64 __m2)
{
    return (__m64)__builtin_ia32_psubw((__v4hi)__m1, (__v4hi)__m2);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_sub_pi32(__m64 __m1, __m64 __m2)
{
    return (__m64)__builtin_ia32_psubd((__v2si)__m1, (__v2si)__m2);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_subs_pi8(__m64 __m1, __m64 __m2)
{
    return (__m64)__builtin_ia32_psubsb((__v8qi)__m1, (__v8qi)__m2);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_subs_pi16(__m64 __m1, __m64 __m2)
{
    return (__m64)__builtin_ia32_psubsw((__v4hi)__m1, (__v4hi)__m2);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_subs_pu8(__m64 __m1, __m64 __m2)
{
    return (__m64)__builtin_ia32_psubusb((__v8qi)__m1, (__v8qi)__m2);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_subs_pu16(__m64 __m1, __m64 __m2)
{
    return (__m64)__builtin_ia32_psubusw((__v4hi)__m1, (__v4hi)__m2);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_madd_pi16(__m64 __m1, __m64 __m2)
{
    return (__m64)__builtin_ia32_pmaddwd((__v4hi)__m1, (__v4hi)__m2);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_mulhi_pi16(__m64 __m1, __m64 __m2)
{
    return (__m64)__builtin_ia32_pmulhw((__v4hi)__m1, (__v4hi)__m2);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_mullo_pi16(__m64 __m1, __m64 __m2)
{
    return (__m64)__builtin_ia32_pmullw((__v4hi)__m1, (__v4hi)__m2);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_sll_pi16(__m64 __m, __m64 __count)
{
    return (__m64)__builtin_ia32_psllw((__v4hi)__m, __count);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_slli_pi16(__m64 __m, int __count)
{
    return (__m64)__builtin_ia32_psllwi((__v4hi)__m, __count);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_sll_pi32(__m64 __m, __m64 __count)
{
    return (__m64)__builtin_ia32_pslld((__v2si)__m, __count);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_slli_pi32(__m64 __m, int __count)
{
    return (__m64)__builtin_ia32_pslldi((__v2si)__m, __count);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_sll_si64(__m64 __m, __m64 __count)
{
    return (__m64)__builtin_ia32_psllq(__m, __count);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_slli_si64(__m64 __m, int __count)
{
    return (__m64)__builtin_ia32_psllqi(__m, __count);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_sra_pi16(__m64 __m, __m64 __count)
{
    return (__m64)__builtin_ia32_psraw((__v4hi)__m, __count);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_srai_pi16(__m64 __m, int __count)
{
    return (__m64)__builtin_ia32_psrawi((__v4hi)__m, __count);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_sra_pi32(__m64 __m, __m64 __count)
{
    return (__m64)__builtin_ia32_psrad((__v2si)__m, __count);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_srai_pi32(__m64 __m, int __count)
{
    return (__m64)__builtin_ia32_psradi((__v2si)__m, __count);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_srl_pi16(__m64 __m, __m64 __count)
{
    return (__m64)__builtin_ia32_psrlw((__v4hi)__m, __count);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_srli_pi16(__m64 __m, int __count)
{
    return (__m64)__builtin_ia32_psrlwi((__v4hi)__m, __count);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_srl_pi32(__m64 __m, __m64 __count)
{
    return (__m64)__builtin_ia32_psrld((__v2si)__m, __count);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_srli_pi32(__m64 __m, int __count)
{
    return (__m64)__builtin_ia32_psrldi((__v2si)__m, __count);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_srl_si64(__m64 __m, __m64 __count)
{
    return (__m64)__builtin_ia32_psrlq(__m, __count);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_srli_si64(__m64 __m, int __count)
{
    return (__m64)__builtin_ia32_psrlqi(__m, __count);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_and_si64(__m64 __m1, __m64 __m2)
{
    return __builtin_ia32_pand(__m1, __m2);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_andnot_si64(__m64 __m1, __m64 __m2)
{
    return __builtin_ia32_pandn(__m1, __m2);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_or_si64(__m64 __m1, __m64 __m2)
{
    return __builtin_ia32_por(__m1, __m2);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_xor_si64(__m64 __m1, __m64 __m2)
{
    return __builtin_ia32_pxor(__m1, __m2);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_cmpeq_pi8(__m64 __m1, __m64 __m2)
{
    return (__m64)__builtin_ia32_pcmpeqb((__v8qi)__m1, (__v8qi)__m2);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_cmpeq_pi16(__m64 __m1, __m64 __m2)
{
    return (__m64)__builtin_ia32_pcmpeqw((__v4hi)__m1, (__v4hi)__m2);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_cmpeq_pi32(__m64 __m1, __m64 __m2)
{
    return (__m64)__builtin_ia32_pcmpeqd((__v2si)__m1, (__v2si)__m2);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_cmpgt_pi8(__m64 __m1, __m64 __m2)
{
    return (__m64)__builtin_ia32_pcmpgtb((__v8qi)__m1, (__v8qi)__m2);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_cmpgt_pi16(__m64 __m1, __m64 __m2)
{
    return (__m64)__builtin_ia32_pcmpgtw((__v4hi)__m1, (__v4hi)__m2);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_cmpgt_pi32(__m64 __m1, __m64 __m2)
{
    return (__m64)__builtin_ia32_pcmpgtd((__v2si)__m1, (__v2si)__m2);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_setzero_si64(void)
{
    return (__m64){ 0LL };
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_set_pi32(int __i1, int __i0)
{
    return (__m64)__builtin_ia32_vec_init_v2si(__i0, __i1);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_set_pi16(short __s3, short __s2, short __s1, short __s0)
{
    return (__m64)__builtin_ia32_vec_init_v4hi(__s0, __s1, __s2, __s3);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_set_pi8(char __b7, char __b6, char __b5, char __b4, char __b3, char __b2,
            char __b1, char __b0)
{
    return (__m64)__builtin_ia32_vec_init_v8qi(__b0, __b1, __b2, __b3,
                                               __b4, __b5, __b6, __b7);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_set1_pi32(int __i)
{
    return _mm_set_pi32(__i, __i);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_set1_pi16(short __w)
{
    return _mm_set_pi16(__w, __w, __w, __w);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_set1_pi8(char __b)
{
    return _mm_set_pi8(__b, __b, __b, __b, __b, __b, __b, __b);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_setr_pi32(int __i0, int __i1)
{
    return _mm_set_pi32(__i1, __i0);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_setr_pi16(short __w0, short __w1, short __w2, short __w3)
{
    return _mm_set_pi16(__w3, __w2, __w1, __w0);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_setr_pi8(char __b0, char __b1, char __b2, char __b3, char __b4, char __b5,
             char __b6, char __b7)
{
    return _mm_set_pi8(__b7, __b6, __b5, __b4, __b3, __b2, __b1, __b0);
}


/* Aliases for compatibility. */
#define _m_empty _mm_empty
#define _m_from_int _mm_cvtsi32_si64
#define _m_to_int _mm_cvtsi64_si32
#define _m_packsswb _mm_packs_pi16
#define _m_packssdw _mm_packs_pi32
#define _m_packuswb _mm_packs_pu16
#define _m_punpckhbw _mm_unpackhi_pi8
#define _m_punpckhwd _mm_unpackhi_pi16
#define _m_punpckhdq _mm_unpackhi_pi32
#define _m_punpcklbw _mm_unpacklo_pi8
#define _m_punpcklwd _mm_unpacklo_pi16
#define _m_punpckldq _mm_unpacklo_pi32
#define _m_paddb _mm_add_pi8
#define _m_paddw _mm_add_pi16
#define _m_paddd _mm_add_pi32
#define _m_paddsb _mm_adds_pi8
#define _m_paddsw _mm_adds_pi16
#define _m_paddusb _mm_adds_pu8
#define _m_paddusw _mm_adds_pu16
#define _m_psubb _mm_sub_pi8
#define _m_psubw _mm_sub_pi16
#define _m_psubd _mm_sub_pi32
#define _m_psubsb _mm_subs_pi8
#define _m_psubsw _mm_subs_pi16
#define _m_psubusb _mm_subs_pu8
#define _m_psubusw _mm_subs_pu16
#define _m_pmaddwd _mm_madd_pi16
#define _m_pmulhw _mm_mulhi_pi16
#define _m_pmullw _mm_mullo_pi16
#define _m_psllw _mm_sll_pi16
#define _m_psllwi _mm_slli_pi16
#define _m_pslld _mm_sll_pi32
#define _m_pslldi _mm_slli_pi32
#define _m_psllq _mm_sll_si64
#define _m_psllqi _mm_slli_si64
#define _m_psraw _mm_sra_pi16
#define _m_psrawi _mm_srai_pi16
#define _m_psrad _mm_sra_pi32
#define _m_psradi _mm_srai_pi32
#define _m_psrlw _mm_srl_pi16
#define _m_psrlwi _mm_srli_pi16
#define _m_psrld _mm_srl_pi32
#define _m_psrldi _mm_srli_pi32
#define _m_psrlq _mm_srl_si64
#define _m_psrlqi _mm_srli_si64
#define _m_pand _mm_and_si64
#define _m_pandn _mm_andnot_si64
#define _m_por _mm_or_si64
#define _m_pxor _mm_xor_si64
#define _m_pcmpeqb _mm_cmpeq_pi8
#define _m_pcmpeqw _mm_cmpeq_pi16
#define _m_pcmpeqd _mm_cmpeq_pi32
#define _m_pcmpgtb _mm_cmpgt_pi8
#define _m_pcmpgtw _mm_cmpgt_pi16
#define _m_pcmpgtd _mm_cmpgt_pi32

#endif /* __MMX__ */

#endif /* __MMINTRIN_H */

#else  /* !__clang__ */

#ifndef __MMX__
# error "MMX instruction set not enabled"
#else
/* The Intel API is flexible enough that we must allow aliasing with other
   vector types, and their scalar components.  */
/* APPLE LOCAL 4505813 */
typedef long long __m64 __attribute__ ((__vector_size__ (8), __may_alias__));

/* Internal data types for implementing the intrinsics.  */
typedef int __v2si __attribute__ ((__vector_size__ (8)));
typedef short __v4hi __attribute__ ((__vector_size__ (8)));
typedef char __v8qi __attribute__ ((__vector_size__ (8)));
/* LLVM LOCAL */
typedef long long __v1di __attribute__ ((__vector_size__ (8)));

/* APPLE LOCAL begin nodebug inline 4152603 */
#define __always_inline__ __always_inline__, __nodebug__
/* APPLE LOCAL end nodebug inline 4152603 */

/* APPLE LOCAL begin radar 5618945 */
#undef __STATIC_INLINE
#ifdef __GNUC_STDC_INLINE__
#define __STATIC_INLINE __inline
#else
#define __STATIC_INLINE static __inline
#endif
/* APPLE LOCAL end radar 5618945 */

/* Empty the multimedia state.  */
/* APPLE LOCAL begin radar 4152603 */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE void __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_empty (void)
{
  __builtin_ia32_emms ();
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE void __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_empty (void)
{
  _mm_empty ();
}

/* Convert I to a __m64 object.  The integer is zero-extended to 64-bits.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64  __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cvtsi32_si64 (int __i)
{
  return (__m64) __builtin_ia32_vec_init_v2si (__i, 0);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64  __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_from_int (int __i)
{
  return _mm_cvtsi32_si64 (__i);
}

#ifdef __x86_64__
/* Convert I to a __m64 object.  */

/* Intel intrinsic.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64  __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_from_int64 (long long __i)
{
  return (__m64) __i;
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64  __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cvtsi64_m64 (long long __i)
{
  return (__m64) __i;
}

/* Microsoft intrinsic.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64  __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cvtsi64x_si64 (long long __i)
{
  return (__m64) __i;
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64  __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_set_pi64x (long long __i)
{
  return (__m64) __i;
}
#endif

/* Convert the lower 32 bits of the __m64 object into an integer.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE int __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cvtsi64_si32 (__m64 __i)
{
  return __builtin_ia32_vec_ext_v2si ((__v2si)__i, 0);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE int __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_to_int (__m64 __i)
{
  return _mm_cvtsi64_si32 (__i);
}

#ifdef __x86_64__
/* Convert the __m64 object to a 64bit integer.  */

/* Intel intrinsic.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE long long __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_to_int64 (__m64 __i)
{
  return (long long)__i;
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE long long __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cvtm64_si64 (__m64 __i)
{
  return (long long)__i;
}

/* Microsoft intrinsic.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE long long __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cvtsi64_si64x (__m64 __i)
{
  return (long long)__i;
}
#endif

/* Pack the four 16-bit values from M1 into the lower four 8-bit values of
   the result, and the four 16-bit values from M2 into the upper four 8-bit
   values of the result, all with signed saturation.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_packs_pi16 (__m64 __m1, __m64 __m2)
{
  return (__m64) __builtin_ia32_packsswb ((__v4hi)__m1, (__v4hi)__m2);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_packsswb (__m64 __m1, __m64 __m2)
{
  return _mm_packs_pi16 (__m1, __m2);
}

/* Pack the two 32-bit values from M1 in to the lower two 16-bit values of
   the result, and the two 32-bit values from M2 into the upper two 16-bit
   values of the result, all with signed saturation.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_packs_pi32 (__m64 __m1, __m64 __m2)
{
  return (__m64) __builtin_ia32_packssdw ((__v2si)__m1, (__v2si)__m2);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_packssdw (__m64 __m1, __m64 __m2)
{
  return _mm_packs_pi32 (__m1, __m2);
}

/* Pack the four 16-bit values from M1 into the lower four 8-bit values of
   the result, and the four 16-bit values from M2 into the upper four 8-bit
   values of the result, all with unsigned saturation.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_packs_pu16 (__m64 __m1, __m64 __m2)
{
  return (__m64) __builtin_ia32_packuswb ((__v4hi)__m1, (__v4hi)__m2);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_packuswb (__m64 __m1, __m64 __m2)
{
  return _mm_packs_pu16 (__m1, __m2);
}

/* Interleave the four 8-bit values from the high half of M1 with the four
   8-bit values from the high half of M2.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_unpackhi_pi8 (__m64 __m1, __m64 __m2)
{
  return (__m64) __builtin_ia32_punpckhbw ((__v8qi)__m1, (__v8qi)__m2);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_punpckhbw (__m64 __m1, __m64 __m2)
{
  return _mm_unpackhi_pi8 (__m1, __m2);
}

/* Interleave the two 16-bit values from the high half of M1 with the two
   16-bit values from the high half of M2.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_unpackhi_pi16 (__m64 __m1, __m64 __m2)
{
  return (__m64) __builtin_ia32_punpckhwd ((__v4hi)__m1, (__v4hi)__m2);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_punpckhwd (__m64 __m1, __m64 __m2)
{
  return _mm_unpackhi_pi16 (__m1, __m2);
}

/* Interleave the 32-bit value from the high half of M1 with the 32-bit
   value from the high half of M2.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_unpackhi_pi32 (__m64 __m1, __m64 __m2)
{
  return (__m64) __builtin_ia32_punpckhdq ((__v2si)__m1, (__v2si)__m2);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_punpckhdq (__m64 __m1, __m64 __m2)
{
  return _mm_unpackhi_pi32 (__m1, __m2);
}

/* Interleave the four 8-bit values from the low half of M1 with the four
   8-bit values from the low half of M2.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_unpacklo_pi8 (__m64 __m1, __m64 __m2)
{
  return (__m64) __builtin_ia32_punpcklbw ((__v8qi)__m1, (__v8qi)__m2);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_punpcklbw (__m64 __m1, __m64 __m2)
{
  return _mm_unpacklo_pi8 (__m1, __m2);
}

/* Interleave the two 16-bit values from the low half of M1 with the two
   16-bit values from the low half of M2.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_unpacklo_pi16 (__m64 __m1, __m64 __m2)
{
  return (__m64) __builtin_ia32_punpcklwd ((__v4hi)__m1, (__v4hi)__m2);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_punpcklwd (__m64 __m1, __m64 __m2)
{
  return _mm_unpacklo_pi16 (__m1, __m2);
}

/* Interleave the 32-bit value from the low half of M1 with the 32-bit
   value from the low half of M2.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_unpacklo_pi32 (__m64 __m1, __m64 __m2)
{
  return (__m64) __builtin_ia32_punpckldq ((__v2si)__m1, (__v2si)__m2);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_punpckldq (__m64 __m1, __m64 __m2)
{
  return _mm_unpacklo_pi32 (__m1, __m2);
}

/* Add the 8-bit values in M1 to the 8-bit values in M2.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_add_pi8 (__m64 __m1, __m64 __m2)
{
  return (__m64) __builtin_ia32_paddb ((__v8qi)__m1, (__v8qi)__m2);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_paddb (__m64 __m1, __m64 __m2)
{
  return _mm_add_pi8 (__m1, __m2);
}

/* Add the 16-bit values in M1 to the 16-bit values in M2.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_add_pi16 (__m64 __m1, __m64 __m2)
{
  return (__m64) __builtin_ia32_paddw ((__v4hi)__m1, (__v4hi)__m2);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_paddw (__m64 __m1, __m64 __m2)
{
  return _mm_add_pi16 (__m1, __m2);
}

/* Add the 32-bit values in M1 to the 32-bit values in M2.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_add_pi32 (__m64 __m1, __m64 __m2)
{
  return (__m64) __builtin_ia32_paddd ((__v2si)__m1, (__v2si)__m2);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_paddd (__m64 __m1, __m64 __m2)
{
  return _mm_add_pi32 (__m1, __m2);
}

/* Add the 64-bit values in M1 to the 64-bit values in M2.  */
#ifdef __SSE2__
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_add_si64 (__m64 __m1, __m64 __m2)
{
  /* APPLE LOCAL 4656532 use V1DImode for _m64 */
  return (__m64) __builtin_ia32_paddq (__m1, __m2);
}
#endif

/* Add the 8-bit values in M1 to the 8-bit values in M2 using signed
   saturated arithmetic.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_adds_pi8 (__m64 __m1, __m64 __m2)
{
  return (__m64) __builtin_ia32_paddsb ((__v8qi)__m1, (__v8qi)__m2);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_paddsb (__m64 __m1, __m64 __m2)
{
  return _mm_adds_pi8 (__m1, __m2);
}

/* Add the 16-bit values in M1 to the 16-bit values in M2 using signed
   saturated arithmetic.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_adds_pi16 (__m64 __m1, __m64 __m2)
{
  return (__m64) __builtin_ia32_paddsw ((__v4hi)__m1, (__v4hi)__m2);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_paddsw (__m64 __m1, __m64 __m2)
{
  return _mm_adds_pi16 (__m1, __m2);
}

/* Add the 8-bit values in M1 to the 8-bit values in M2 using unsigned
   saturated arithmetic.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_adds_pu8 (__m64 __m1, __m64 __m2)
{
  return (__m64) __builtin_ia32_paddusb ((__v8qi)__m1, (__v8qi)__m2);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_paddusb (__m64 __m1, __m64 __m2)
{
  return _mm_adds_pu8 (__m1, __m2);
}

/* Add the 16-bit values in M1 to the 16-bit values in M2 using unsigned
   saturated arithmetic.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_adds_pu16 (__m64 __m1, __m64 __m2)
{
  return (__m64) __builtin_ia32_paddusw ((__v4hi)__m1, (__v4hi)__m2);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_paddusw (__m64 __m1, __m64 __m2)
{
  return _mm_adds_pu16 (__m1, __m2);
}

/* Subtract the 8-bit values in M2 from the 8-bit values in M1.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_sub_pi8 (__m64 __m1, __m64 __m2)
{
  return (__m64) __builtin_ia32_psubb ((__v8qi)__m1, (__v8qi)__m2);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_psubb (__m64 __m1, __m64 __m2)
{
  return _mm_sub_pi8 (__m1, __m2);
}

/* Subtract the 16-bit values in M2 from the 16-bit values in M1.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_sub_pi16 (__m64 __m1, __m64 __m2)
{
  return (__m64) __builtin_ia32_psubw ((__v4hi)__m1, (__v4hi)__m2);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_psubw (__m64 __m1, __m64 __m2)
{
  return _mm_sub_pi16 (__m1, __m2);
}

/* Subtract the 32-bit values in M2 from the 32-bit values in M1.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_sub_pi32 (__m64 __m1, __m64 __m2)
{
  return (__m64) __builtin_ia32_psubd ((__v2si)__m1, (__v2si)__m2);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_psubd (__m64 __m1, __m64 __m2)
{
  return _mm_sub_pi32 (__m1, __m2);
}

/* Add the 64-bit values in M1 to the 64-bit values in M2.  */
#ifdef __SSE2__
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_sub_si64 (__m64 __m1, __m64 __m2)
{
  /* APPLE LOCAL 4656532 use V1DImode for _m64 */
  return (__m64) __builtin_ia32_psubq (__m1, __m2);
}
#endif

/* Subtract the 8-bit values in M2 from the 8-bit values in M1 using signed
   saturating arithmetic.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_subs_pi8 (__m64 __m1, __m64 __m2)
{
  return (__m64) __builtin_ia32_psubsb ((__v8qi)__m1, (__v8qi)__m2);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_psubsb (__m64 __m1, __m64 __m2)
{
  return _mm_subs_pi8 (__m1, __m2);
}

/* Subtract the 16-bit values in M2 from the 16-bit values in M1 using
   signed saturating arithmetic.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_subs_pi16 (__m64 __m1, __m64 __m2)
{
  return (__m64) __builtin_ia32_psubsw ((__v4hi)__m1, (__v4hi)__m2);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_psubsw (__m64 __m1, __m64 __m2)
{
  return _mm_subs_pi16 (__m1, __m2);
}

/* Subtract the 8-bit values in M2 from the 8-bit values in M1 using
   unsigned saturating arithmetic.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_subs_pu8 (__m64 __m1, __m64 __m2)
{
  return (__m64) __builtin_ia32_psubusb ((__v8qi)__m1, (__v8qi)__m2);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_psubusb (__m64 __m1, __m64 __m2)
{
  return _mm_subs_pu8 (__m1, __m2);
}

/* Subtract the 16-bit values in M2 from the 16-bit values in M1 using
   unsigned saturating arithmetic.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_subs_pu16 (__m64 __m1, __m64 __m2)
{
  return (__m64) __builtin_ia32_psubusw ((__v4hi)__m1, (__v4hi)__m2);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_psubusw (__m64 __m1, __m64 __m2)
{
  return _mm_subs_pu16 (__m1, __m2);
}

/* Multiply four 16-bit values in M1 by four 16-bit values in M2 producing
   four 32-bit intermediate results, which are then summed by pairs to
   produce two 32-bit results.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_madd_pi16 (__m64 __m1, __m64 __m2)
{
  return (__m64) __builtin_ia32_pmaddwd ((__v4hi)__m1, (__v4hi)__m2);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_pmaddwd (__m64 __m1, __m64 __m2)
{
  return _mm_madd_pi16 (__m1, __m2);
}

/* Multiply four signed 16-bit values in M1 by four signed 16-bit values in
   M2 and produce the high 16 bits of the 32-bit results.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_mulhi_pi16 (__m64 __m1, __m64 __m2)
{
  return (__m64) __builtin_ia32_pmulhw ((__v4hi)__m1, (__v4hi)__m2);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_pmulhw (__m64 __m1, __m64 __m2)
{
  return _mm_mulhi_pi16 (__m1, __m2);
}

/* Multiply four 16-bit values in M1 by four 16-bit values in M2 and produce
   the low 16 bits of the results.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_mullo_pi16 (__m64 __m1, __m64 __m2)
{
  return (__m64) __builtin_ia32_pmullw ((__v4hi)__m1, (__v4hi)__m2);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_pmullw (__m64 __m1, __m64 __m2)
{
  return _mm_mullo_pi16 (__m1, __m2);
}

/* Shift four 16-bit values in M left by COUNT.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_sll_pi16 (__m64 __m, __m64 __count)
{
  /* APPLE LOCAL 4656532 use V1DImode for _m64 */
  return (__m64) __builtin_ia32_psllw ((__v4hi)__m, __count);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_psllw (__m64 __m, __m64 __count)
{
  return _mm_sll_pi16 (__m, __count);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_slli_pi16 (__m64 __m, int __count)
{
  /* APPLE LOCAL 4656532 use V1DImode for _m64 */
  return (__m64) __builtin_ia32_psllwi ((__v4hi)__m, __count);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_psllwi (__m64 __m, int __count)
{
  return _mm_slli_pi16 (__m, __count);
}

/* Shift two 32-bit values in M left by COUNT.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_sll_pi32 (__m64 __m, __m64 __count)
{
  /* APPLE LOCAL 4656532 use V1DImode for _m64 */
  return (__m64) __builtin_ia32_pslld ((__v2si)__m, __count);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_pslld (__m64 __m, __m64 __count)
{
  return _mm_sll_pi32 (__m, __count);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_slli_pi32 (__m64 __m, int __count)
{
  /* APPLE LOCAL 4656532 use V1DImode for _m64 */
  return (__m64) __builtin_ia32_pslldi ((__v2si)__m, __count);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_pslldi (__m64 __m, int __count)
{
  return _mm_slli_pi32 (__m, __count);
}

/* Shift the 64-bit value in M left by COUNT.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_sll_si64 (__m64 __m, __m64 __count)
{
  /* APPLE LOCAL 4656532 use V1DImode for _m64 */
  return (__m64) __builtin_ia32_psllq (__m, __count);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_psllq (__m64 __m, __m64 __count)
{
  return _mm_sll_si64 (__m, __count);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_slli_si64 (__m64 __m, int __count)
{
  /* APPLE LOCAL 4656532 use V1DImode for _m64 */
  return (__m64) __builtin_ia32_psllqi (__m, __count);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_psllqi (__m64 __m, int __count)
{
  return _mm_slli_si64 (__m, __count);
}

/* Shift four 16-bit values in M right by COUNT; shift in the sign bit.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_sra_pi16 (__m64 __m, __m64 __count)
{
  /* APPLE LOCAL 4656532 use V1DImode for _m64 */
  return (__m64) __builtin_ia32_psraw ((__v4hi)__m, __count);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_psraw (__m64 __m, __m64 __count)
{
  return _mm_sra_pi16 (__m, __count);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_srai_pi16 (__m64 __m, int __count)
{
  /* APPLE LOCAL 4656532 use V1DImode for _m64 */
  return (__m64) __builtin_ia32_psrawi ((__v4hi)__m, __count);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_psrawi (__m64 __m, int __count)
{
  return _mm_srai_pi16 (__m, __count);
}

/* Shift two 32-bit values in M right by COUNT; shift in the sign bit.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_sra_pi32 (__m64 __m, __m64 __count)
{
  /* APPLE LOCAL 4656532 use V1DImode for _m64 */
  return (__m64) __builtin_ia32_psrad ((__v2si)__m, __count);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_psrad (__m64 __m, __m64 __count)
{
  return _mm_sra_pi32 (__m, __count);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_srai_pi32 (__m64 __m, int __count)
{
  /* APPLE LOCAL 4656532 use V1DImode for _m64 */
  return (__m64) __builtin_ia32_psradi ((__v2si)__m, __count);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_psradi (__m64 __m, int __count)
{
  return _mm_srai_pi32 (__m, __count);
}

/* Shift four 16-bit values in M right by COUNT; shift in zeros.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_srl_pi16 (__m64 __m, __m64 __count)
{
  /* APPLE LOCAL 4656532 use V1DImode for _m64 */
  return (__m64) __builtin_ia32_psrlw ((__v4hi)__m, __count);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_psrlw (__m64 __m, __m64 __count)
{
  return _mm_srl_pi16 (__m, __count);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_srli_pi16 (__m64 __m, int __count)
{
  /* APPLE LOCAL 4656532 use V1DImode for _m64 */
  return (__m64) __builtin_ia32_psrlwi ((__v4hi)__m, __count);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_psrlwi (__m64 __m, int __count)
{
  return _mm_srli_pi16 (__m, __count);
}

/* Shift two 32-bit values in M right by COUNT; shift in zeros.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_srl_pi32 (__m64 __m, __m64 __count)
{
  /* APPLE LOCAL 4656532 use V1DImode for _m64 */
  return (__m64) __builtin_ia32_psrld ((__v2si)__m, __count);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_psrld (__m64 __m, __m64 __count)
{
  return _mm_srl_pi32 (__m, __count);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_srli_pi32 (__m64 __m, int __count)
{
  /* APPLE LOCAL 4656532 use V1DImode for _m64 */
  return (__m64) __builtin_ia32_psrldi ((__v2si)__m, __count);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_psrldi (__m64 __m, int __count)
{
  return _mm_srli_pi32 (__m, __count);
}

/* Shift the 64-bit value in M left by COUNT; shift in zeros.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_srl_si64 (__m64 __m, __m64 __count)
{
  /* APPLE LOCAL 4656532 use V1DImode for _m64 */
  return (__m64) __builtin_ia32_psrlq (__m, __count);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_psrlq (__m64 __m, __m64 __count)
{
  return _mm_srl_si64 (__m, __count);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_srli_si64 (__m64 __m, int __count)
{
  /* APPLE LOCAL 4656532 use V1DImode for _m64 */
  return (__m64) __builtin_ia32_psrlqi (__m, __count);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_psrlqi (__m64 __m, int __count)
{
  return _mm_srli_si64 (__m, __count);
}

/* Bit-wise AND the 64-bit values in M1 and M2.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_and_si64 (__m64 __m1, __m64 __m2)
{
  return __builtin_ia32_pand (__m1, __m2);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_pand (__m64 __m1, __m64 __m2)
{
  return _mm_and_si64 (__m1, __m2);
}

/* Bit-wise complement the 64-bit value in M1 and bit-wise AND it with the
   64-bit value in M2.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_andnot_si64 (__m64 __m1, __m64 __m2)
{
  return __builtin_ia32_pandn (__m1, __m2);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_pandn (__m64 __m1, __m64 __m2)
{
  return _mm_andnot_si64 (__m1, __m2);
}

/* Bit-wise inclusive OR the 64-bit values in M1 and M2.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_or_si64 (__m64 __m1, __m64 __m2)
{
  return __builtin_ia32_por (__m1, __m2);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_por (__m64 __m1, __m64 __m2)
{
  return _mm_or_si64 (__m1, __m2);
}

/* Bit-wise exclusive OR the 64-bit values in M1 and M2.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_xor_si64 (__m64 __m1, __m64 __m2)
{
  return __builtin_ia32_pxor (__m1, __m2);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_pxor (__m64 __m1, __m64 __m2)
{
  return _mm_xor_si64 (__m1, __m2);
}

/* Compare eight 8-bit values.  The result of the comparison is 0xFF if the
   test is true and zero if false.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cmpeq_pi8 (__m64 __m1, __m64 __m2)
{
  return (__m64) __builtin_ia32_pcmpeqb ((__v8qi)__m1, (__v8qi)__m2);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_pcmpeqb (__m64 __m1, __m64 __m2)
{
  return _mm_cmpeq_pi8 (__m1, __m2);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cmpgt_pi8 (__m64 __m1, __m64 __m2)
{
  return (__m64) __builtin_ia32_pcmpgtb ((__v8qi)__m1, (__v8qi)__m2);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_pcmpgtb (__m64 __m1, __m64 __m2)
{
  return _mm_cmpgt_pi8 (__m1, __m2);
}

/* Compare four 16-bit values.  The result of the comparison is 0xFFFF if
   the test is true and zero if false.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cmpeq_pi16 (__m64 __m1, __m64 __m2)
{
  return (__m64) __builtin_ia32_pcmpeqw ((__v4hi)__m1, (__v4hi)__m2);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_pcmpeqw (__m64 __m1, __m64 __m2)
{
  return _mm_cmpeq_pi16 (__m1, __m2);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cmpgt_pi16 (__m64 __m1, __m64 __m2)
{
  return (__m64) __builtin_ia32_pcmpgtw ((__v4hi)__m1, (__v4hi)__m2);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_pcmpgtw (__m64 __m1, __m64 __m2)
{
  return _mm_cmpgt_pi16 (__m1, __m2);
}

/* Compare two 32-bit values.  The result of the comparison is 0xFFFFFFFF if
   the test is true and zero if false.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cmpeq_pi32 (__m64 __m1, __m64 __m2)
{
  return (__m64) __builtin_ia32_pcmpeqd ((__v2si)__m1, (__v2si)__m2);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_pcmpeqd (__m64 __m1, __m64 __m2)
{
  return _mm_cmpeq_pi32 (__m1, __m2);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cmpgt_pi32 (__m64 __m1, __m64 __m2)
{
  return (__m64) __builtin_ia32_pcmpgtd ((__v2si)__m1, (__v2si)__m2);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_pcmpgtd (__m64 __m1, __m64 __m2)
{
  return _mm_cmpgt_pi32 (__m1, __m2);
}

/* Creates a 64-bit zero.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_setzero_si64 (void)
{
  return (__m64)0LL;
}

/* Creates a vector of two 32-bit values; I0 is least significant.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_set_pi32 (int __i1, int __i0)
{
  return (__m64) __builtin_ia32_vec_init_v2si (__i0, __i1);
}

/* Creates a vector of four 16-bit values; W0 is least significant.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_set_pi16 (short __w3, short __w2, short __w1, short __w0)
{
  return (__m64) __builtin_ia32_vec_init_v4hi (__w0, __w1, __w2, __w3);
}

/* Creates a vector of eight 8-bit values; B0 is least significant.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_set_pi8 (char __b7, char __b6, char __b5, char __b4,
	     char __b3, char __b2, char __b1, char __b0)
{
  return (__m64) __builtin_ia32_vec_init_v8qi (__b0, __b1, __b2, __b3,
					       __b4, __b5, __b6, __b7);
}

/* Similar, but with the arguments in reverse order.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_setr_pi32 (int __i0, int __i1)
{
  return _mm_set_pi32 (__i1, __i0);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_setr_pi16 (short __w0, short __w1, short __w2, short __w3)
{
  return _mm_set_pi16 (__w3, __w2, __w1, __w0);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_setr_pi8 (char __b0, char __b1, char __b2, char __b3,
	      char __b4, char __b5, char __b6, char __b7)
{
  return _mm_set_pi8 (__b7, __b6, __b5, __b4, __b3, __b2, __b1, __b0);
}

/* Creates a vector of two 32-bit values, both elements containing I.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_set1_pi32 (int __i)
{
  return _mm_set_pi32 (__i, __i);
}

/* Creates a vector of four 16-bit values, all elements containing W.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_set1_pi16 (short __w)
{
  return _mm_set_pi16 (__w, __w, __w, __w);
}

/* Creates a vector of eight 8-bit values, all elements containing B.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_set1_pi8 (char __b)
{
  return _mm_set_pi8 (__b, __b, __b, __b, __b, __b, __b, __b);
}
/* APPLE LOCAL end radar 4152603 */

/* APPLE LOCAL begin nodebug inline 4152603 */
#undef __always_inline__
/* APPLE LOCAL end nodebug inline 4152603 */

#endif /* __MMX__ */

#endif /* __clang__ */

#endif /* _MMINTRIN_H_INCLUDED */
