AC_INIT(libpes, version-0.1)
AC_CONFIG_AUX_DIR(autotools)

AM_INIT_AUTOMAKE($PACKAGE_TARNAME, $PACKAGE_VERSION, no-define)

AC_PROG_CC
AC_PROG_CXX
AC_PROG_LIBTOOL
AC_PROG_INSTALL
AC_PROG_MAKE_SET

if [[ "$GCC" = "yes" ]]; then
	is_gcc=true
else
	is_gcc=false
fi

TEST_CFLAGS=""

# Turn on all warnings for gcc.  Turn off optimisation for the test build.

if $is_gcc; then
	WARNINGS="-Wall -Wsign-compare -Wconversion"
	CFLAGS="$CFLAGS $WARNINGS"
	TEST_CFLAGS="$TEST_CFLAGS $WARNINGS -O0"
fi

AM_CONFIG_HEADER(config.h:config.h.in)

AC_SUBST(MAIN_CFLAGS)
AC_SUBST(TEST_CFLAGS)
AC_SUBST(ac_aux_dir)

AC_OUTPUT([
    Makefile
    libcalg-1.0.pc
    doc/Makefile
    src/Makefile
    test/Makefile
])

