#!/usr/bin/perl
#
use Astro::Api qw(:all);
use strict;

my @lines = &Astro::Api::short();

# Print HTTP headers

print "Content-Type: text/xml;\n";
print "\n";

foreach my $line (@lines) {
    print "$line\n";
}
