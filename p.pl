#! /usr/bin/env perl

use v5.26;
use feature qw(say);
use strict;
use warnings;
use FFI::Platypus;
use FFI::CheckLib;

say "Running test script..";
say "LD_LIBRARY_PATH=", $ENV{LD_LIBRARY_PATH};
my $libname = 'ESNMP';
my @libs = find_lib(lib => $libname, libpath => './lib');
die "Could not find libary '$libname'\n" if !@libs;
my $libpath = $libs[0];
my $ffi = FFI::Platypus->new();
$ffi->lib( $libpath );
my $function = $ffi->function('load_library', ['int'] => 'int');
my $input_value = 2;
my $return_value = $function->($input_value);
say "Return value: ", $return_value;
my $snmp_initialize = $ffi->function('wsnmp_Initialize', ['string', 'int'] => 'int');
my $port = 22;
my $filename = 'sample.conf';
my $return_value2 = $snmp_initialize->($filename, $port);
say "Return value2: ", $return_value2;
