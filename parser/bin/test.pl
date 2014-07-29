#!/usr/bin/perl

use strict;
use warnings;

#add the lib directory to @INC
use File::Basename qw(dirname);
use Cwd qw(abs_path);
use lib dirname(dirname abs_path $0) . '/lib';

use RemoteValue;
use Expression;
use SimpleValue;


my $remoteValue = RemoteValue->new(param=>"rank", value=>1);
my $simpleValue = SimpleValue->new(value=>1);

foreach my $key (keys %{$remoteValue}) {
  print "key: $key, value: " . $remoteValue->{$key} ."\n";
}

print "The value is remote? " . $remoteValue->isRemote . "\n";
print "The value is remote? " . $simpleValue->isRemote . "\n";

my $expression = Expression->new(lhs => $simpleValue, operator => "==", rhs => $remoteValue);

print "The expression is remote? " .$expression->isRemote . "\n";
