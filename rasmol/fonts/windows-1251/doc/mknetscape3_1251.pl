#!/usr/bin/perl

#
#  mknetscape3_1251.pl
#      Modifies Unix versions of Netscape3 (incl. Gold)
#      to understand windows-1251.
#
#      To do this, turns off iso8859-9 (Turkish) support and replaces
#      it with windows-1251 one.
#
#  Usage:
#      mknetscape3_1251.pl <netscape >netscape_h
#

$d = $/;
$/ = undef;
$aa = <>;
$/ = $d;


foreach $cs ('windows-1251','csWindows31Latin5', 'iso-8859-5-windows-latin-5','x-cp1251' )
{
  if( $aa =~ s/($cs)(\0{36,64})\0\x29/$1$2\0\x14/m)
  {
  #  printf STDERR "%04x : %04x; %x\n",unpack("s",$1),unpack("s",$2),int($&); 
    print STDERR "Turn on $1 length=",length($1),"\n"; 
  }
  else
  {
    print STDERR "Not found $1 ",length($1),"\n"; 

  }
}
foreach $cs ( 'iso-8859-9', 'windows-1254')
{
  if( $aa =~ s/($cs)(\0{38,64})\0\x14/$1$2\0\x29/m)
  {
  #  printf STDERR "%04x : %04x; %x\n",unpack("s",$1),unpack("s",$2),int($&); 
    print STDERR "Turn off $1 length=",length($1),"\n"; 
  }
  else
  {
    print STDERR "Not found $1 ",length($1),"\n"; 

  }
}

$win_14_o="\x00\\\x29\x00\x27";
$win_14_n="\x00\x14\x00\x27";

if( $aa =~s/$win_14_o(\000?koi8-r)/$win_14_n$1/m )
 {
    print STDERR "Change for 1251  from 0x29 to 0x14\n"; 
 }
  else
 {
    print STDERR "Not Change for 1251\n"; 
 }

$win_29_o="\x00\x14\x00\x14";
$win_29_n="\x00\x29\x00\x29";


if( $aa =~s/$win_29_o(\000?iso-8859-9)/$win_29_n$1/m)
 {
    print STDERR "Change for 8859-9 from 0x14 to 0x29\n"; 
 }
  else
 {
    print STDERR "Not make new item w51\n"; 
 }

$win_2e_o="\x00\x2e\x00\x14";
$win_2e_n="\x00\x2e\x00\x29";


if( $aa =~s/$win_2e_o(\000?iso-8859-9)/$win_2e_n$1/m)
 {
    print STDERR "Change for 8859-9 from 0x14 to 0x29\n"; 
 }
  else
 {
    print STDERR "Not make new item w51\n"; 
 }

# Full revers 0x14 <-> 0x29 done.
# Make conv 88599 -> 1251:

if( $aa =~s/\0(88599)\0/\0001251\0\0/m)
 {
    print STDERR "Make new item 1251 from 88599\n"; 
 }
  else
 {
    print STDERR "Not!! make new item 88599\n"; 
 }


if( $aa =~s/88599.labelString:\t\tTurkish \(ISO 8859-9\)\0\0\0/1251.labelString:\t\tCyrillic \(Windows-1251\)\0/m)
 {
    print STDERR "Make new item 1251 from 88599 in xres\n"; 
 }
elsif( $aa =~s/88599.labelString:\t\tTurkish \(ISO 8859-9\)\0/1251.labelString:\t\tCyrillic \(Wins-1251\)\0\0/m)
 {
    print STDERR "Make new item 1251 from 88599 in xres SHORT\n"; 
 }
  else
 {
    print STDERR "Not make new item 1251 from 88599 in xres\n"; 
 }


print $aa;
exit 0;

