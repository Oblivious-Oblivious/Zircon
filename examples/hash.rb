#!/usr/bin/env ruby

join_char = "";
puts join_char + ARGV[0]
    .chomp.split(//)
    .map(&:ord)
    .map { |v| v.to_s(16) }
    .join(join_char);
