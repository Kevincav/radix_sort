# configure.ac file

AC_PREREQ([2.59])
AC_INIT([libsort], [1.0.0], [kmm4mc@mizzou.edu])

AM_INIT_AUTOMAKE(libsort,1.0.0)

# Checks for programs.
AC_PROG_CC
AM_PROG_CC_C_O
AC_PROG_CPP
AC_PROG_CXX
AC_PROG_INSTALL
AC_PROG_LIBTOOL
AC_PROG_LN_S
AC_PROG_MAKE_SET

AC_CONFIG_FILES([Makefile src/Makefile tests/Makefile])

#find out what version we are running
ARCH=`uname -m`
if [[ $ARCH == "x86_64" ]];
then
  SUFFIX="64"
else
  SUFFIX=""
fi

AC_LANG([C++])

# Global CPP Flags
AM_CPPFLAGS=-v -O3 -march=native -mtune=native -funroll-loops
AC_SUBST([AM_CPPFLAGS])

AC_OUTPUT


