AC_CONFIG_SRCDIR([src])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR([build-aux])

AC_INIT([z80prog], [0.1], [naopross@tharcway.org])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

AC_PROG_CC

####
# Check for required packages / libraries
#
LIBGTK_REQUIRED=2.91

PKG_CHECK_MODULES(gtk3, [gtk+-3.0 >= $LIBGTK_REQUIRED])

AC_CONFIG_FILES([
    makefile
    src/makefile
])

AC_OUTPUT
