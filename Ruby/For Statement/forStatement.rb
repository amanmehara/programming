#! /usr/bin/env ruby

# Measure some strings:
words = ['cat', 'window', 'defenestrate']

for w in words do   
    puts "('" + w  + "', " + w.length.to_s + ")"
end   