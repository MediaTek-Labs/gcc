/* Copyright (C) 2021 Free Software Foundation, Inc.
   Contributed by Doug Kwan (dougkwan@google.com)
   Rewritten by CodeSourcery, Inc.

   This file is part of GCC.

   GCC is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published
   by the Free Software Foundation; either version 3, or (at your
   option) any later version.

   GCC is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License
   along with GCC; see the file COPYING3.  If not see
   <http://www.gnu.org/licenses/>.  */


#ifndef LIBSTDCXX
#define LIBSTDCXX_REAL "-lstdc++"
#else
#define LIBSTDCXX_REAL "-l" LIBSTDCXX
#endif

#ifndef LIBSTDCXX_NORTTI
#define LIBSTDCXX_NORTTI "nortti/libstdc++.a%s"
#endif

#define NORTTI_LIBSTDXX_LINK_SPEC \
  "%{nortti-libstdc++:%:replace-outfile(" LIBSTDCXX_REAL " " LIBSTDCXX_NORTTI ")}"


