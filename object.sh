#!/bin/bash

PREFIX=`echo -n $1 | perl -ne 'print uc($_);'`
Prefix=`echo -n $1 | perl -ne 'print ucfirst($_);'`
prefix=`echo -n $1 | perl -ne 'print lc($_);'`
NAME=`echo -n $2 | perl -ne 'print uc($_);'`
Name=`echo -n $2 | perl -ne 'print ucfirst($_);'`
name=`echo -n $2 | perl -ne 'print lc($_);'`

echo "PREFIX=$PREFIX"
echo "Prefix=$Prefix"
echo "prefix=$prefix"
echo "NAME=$NAME"
echo "Name=$Name"
echo "name=$name"

REPLACEMENTS="s/PREFIX/$PREFIX/g
s/Prefix/$Prefix/g
s/prefix/$prefix/g
s/Name/$Name/g
s/NAME/$NAME/g
s/name/$name/g"

REPLACEMENTS="$(tr -s '\n' ';' <<< "$REPLACEMENTS")"

C_FILE="./$prefix$name.c"
H_FILE="./$prefix$name.h"


sed -e $REPLACEMENTS prefixname.c > $C_FILE
sed -e $REPLACEMENTS prefixname.h > $H_FILE


echo "Done."

