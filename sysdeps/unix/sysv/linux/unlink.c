/* Delete a name and possibly the file it refers to.  Linux version.
   Copyright (C) 2011-2025 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library.  If not, see
   <https://www.gnu.org/licenses/>.  */

#include <unistd.h>
#include <fcntl.h>
#include <sysdep.h>

/* Remove the link named NAME.  */
int
__unlink (const char *name)
{
#ifdef __NR_unlink
  return INLINE_SYSCALL_CALL (unlink, name);
#else
  return INLINE_SYSCALL_CALL (unlinkat, AT_FDCWD, name, 0);
#endif
}
weak_alias (__unlink, unlink)
