AUTOMAKE_OPTIONS = foreign

bin_PROGRAMS = expSeries
expSeries_SOURCES = main.cpp ExponentialSeries.cpp ExponentialSeries.h

check_PROGRAMS = test_funcA
test_funcA_SOURCES = tests/test_funcA.cpp ExponentialSeries.cpp ExponentialSeries.h
TESTS = test_funcA

nobase_dist_pkgdata_DATA = data/data.txt

dist_pkgdata_DATA = README.md
