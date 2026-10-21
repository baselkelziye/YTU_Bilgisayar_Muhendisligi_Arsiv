#!/usr/bin/perl

 

#ask user to choose reading the dna sequences from file or command line
print "If you want to read the DNA sequences from file, file extensions must be .txt! \n\n";
do{
	print "Press 1 to read the sequences from file\n";
    print "Press 2 to read the sequences from command line\n";
    $choice=<STDIN>;
    chomp($choice);
    if ($choice == 1 ) {
    	opendir(DIR, ".") or die "cannot open directory"; #open current directory
    	@files = grep(/\.txt$/,readdir(DIR)); #get name of all txt files
    	open(my $file, '<:encoding(UTF-8)', $files[0]) #read the first txt file
          or die "Could not open file '$filename' $!";
          $dna1 = <$file>; #read the file content as a dna1 variable
        open(my $file, '<:encoding(UTF-8)', $files[1]) #read the second txt file
          or die "Could not open file '$filename' $!";
          $dna2 = <$file>; #read the file content as a dna2 variable
    }elsif($choice == 2){
    	print "Enter the first DNA sequence:\n";
      $dna1 = <STDIN>;     
      $dna1 = uc $dna1;  #make it uppercase
      print "Enter the second DNA sequence:\n";
      $dna2 = <STDIN>;
      $dna2 = uc $dna2;  #make it uppercase
    }else{
    	print "Wrong number has been pressed. Please enter it again:\n";
    }
}while($choice != 1  && $choice != 2); # check until the user enters the proper number.

print "\nFirst dna sequence: $dna1\n";
print "\nSecond dna sequence: $dna2\n";

$dna1_length = length($dna1); #first dna length
$dna2_length = length($dna2); #second dna length

print "Enter the window size:\n";
$ws = <STDIN>; 

print "Enter the threshold value: \n";
$threshold = <STDIN>; 


my @dotPlot;  #will be used for plotting the matrix
for (my $i = 0; $i <= $dna1_length-$ws; $i++) {
  for (my $j = 0; $j <= $dna2_length-$ws; $j++) {
    $size = 0;  #used for checking the windowsize
    $equal = 0;  #used for checking the threshold
    while ($size < $ws && $equal < $threshold) {
      $size+=1;
      #if two nucloids are equal then increase the equal variable
      if (substr($dna1,$i+$size,1) eq substr($dna2,$j+$size,1)) { 
        $equal++;
      }
    }
    #if threshold value is reached then assign the \ value to dotPlot
    if ($equal == $threshold) {
      $dotPlot[$i][$j] ="\\";
    } 
  } 
}

print "Window size: $ws\n";
print "Threshold value: $threshold\n";
print "According to given window size and threshold value if two sequences are equal then show '\\' for matches, otherwise show .\n";
print "If two sequences match show the '\\' sign\n";


print "  "; # two space before printing dna2 sequences in order to show the dot plot neatly
for (my $i = 0; $i < $dna2_length; $i++) { 
  print substr($dna2, $i, 1);
  print " ";
}
print "\n";

for (my $i = 0; $i < $dna1_length; $i++) {
  print substr($dna1, $i, 1);
  for (my $j = 0; $j < $dna2_length; $j++) {
    if ($dotPlot[$i][$j] eq "\\") {
      print " \\";    
    }else{
      print " .";
    }
  }
  print "\n";
}








