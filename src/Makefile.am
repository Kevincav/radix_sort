#SUBDIRS =

LINK = $(LIBTOOL) --mode=link $(CC) -o  $@

EXAMPLE_LIBRARY_VERSION=1:0:0

lib_LTLIBRARIES = libsort.la

AM_CPPFLAGS = -v -O3 -march=native -mtune=native -funroll-loops

libsort_la_LDFLAGS = -version-info $(EXAMPLE_LIBRARY_VERSION) @LTLIBOBJS@
libsort_la_SOURCES = radixSort_slow.cpp radixSort_fast.cpp

libsortdir = $(includedir)/libsort
libsort_HEADERS = radixSort_slow.hpp radixSort_fast.hpp