check_PROGRAMS 	= 	radixSortSlow radixSortFast

radixSortSlow_SOURCES 	= test_sort_slow.cpp
radixSortSlow_LDADD     = $(top_builddir)/src/libsort.la
radixSortSlow_LDFLAGS	= 
radixSortSlow_CPPFLAGS	=  $(AM_CPPFLAGS)

radixSortFast_SOURCES 	= test_sort_fast.cpp
radixSortFast_LDADD     = $(top_builddir)/src/libsort.la
radixSortFast_LDFLAGS	= 
radixSortFast_CPPFLAGS	=  $(AM_CPPFLAGS)

#
# Nothing below this line should need customization on a per-project basis.
#

AM_CPPFLAGS		= -v -O3 -march=native -mtune=native -funroll-loops


all: check
