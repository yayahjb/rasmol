#!/usr/bin/perl -w

#
#  mk8859alias.pl
#      Generates font aliases with rgstry-encdng set to "iso8859-1".
#      The fndry has original encoding appended (e.g. "adobe"->"adobe_koi8_1")
#
#  Usage:
#      mk8859alias.pl <fonts.dir >>fonts.alias
#

use strict;

my $l;
my $f;
my $a;

<STDIN>; # Skip the number of fonts

print "!ENC: 8859-1\n";

while (<STDIN>)
{
    $l = $_;
    $l =~ /^.+?\s+(.*)$/;

    $f = $1;
    $f =~ /^(-.*?)(-.*?-.*?-.*?-.*?-.*?-.*?-.*?-.*?-.*?-.*?-.*?-)(.*?)-(.*?)$/;

    $a = "$1_$3_$4$2iso8859-1";

    print "\"$a\" \"$f\"\n";

}
