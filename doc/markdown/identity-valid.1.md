NAME
====

**identity-validate** -- check *validated-identity* received by
*identity-confirm*

SYNOPSIS
========

**virgil identity-valid** -f *file* \[--\] \[--version\] \[-h\]

DESCRIPTION
===========

Check *validated-identity* received by *identity-confirm*

OPTIONS
=======

    -f *file*,  --validated-identity *file*
     (required)  Validated identity

    --,  --ignore_rest
     Ignores the rest of the labeled arguments following this flag

    --version
     Displays version information and exits

    -h,  --help
     Displays usage information and exits

RETURN VALUE
============

On success, true is returned else false.

EXAMPLES
========

        virgil identity-valid -f validated-identity.txt

SEE ALSO
========

[`virgil(1)`](../markdown/virgil.1.md),  
[`identity-confirm(1)`](../markdown/identity-confirm.1.md)