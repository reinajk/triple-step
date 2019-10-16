#! /usr/bin/env ruby

class Array

def sum
   reduce(:+)
end

def ave
   self.inject(:+) / self.length
end

def std 
   av = ave
   reduce(0) { |a,b| a+(b-av)**2} / (size-1)
end

def sdd 
   Math.sqrt(std)
end
end 
 
sci = [65,80,67,35,58,60,72,75,68,92,36,50,2,58.5,46,42,78,62,84,70]
eng = [44,87,100,63,52,60,58,73,55,86,29,56,89,23,65,84,64,27,86,84]

puts"\n"
print "理科の平均点:"
puts sci.ave
print "英語の平均点:"
puts eng.ave
puts "\n" 
puts "\n"

print "理科の標準偏差:"
puts sci.sdd
print "英語の標準偏差:"
puts eng.sdd
puts"\n"
puts"\n"

print "理科の合計点:"
puts sci.sum
print "英語の合計点:"
puts eng.sum
puts "\n"
puts "\n"

puts "理科の偏差値:"
sci.each do |x|
    dev = ( x - sci.ave ) / sci.sdd * 10 + 50 
    print "#{x}\t#{dev}\n"
end
print "\n"

puts "英語の偏差値:"
eng.each do |x|
    dev = ( x - eng.ave ) / eng.sdd * 10 + 50
    print "#{x}\t#{dev}\n"
end
puts"\n"
puts"\n" 
