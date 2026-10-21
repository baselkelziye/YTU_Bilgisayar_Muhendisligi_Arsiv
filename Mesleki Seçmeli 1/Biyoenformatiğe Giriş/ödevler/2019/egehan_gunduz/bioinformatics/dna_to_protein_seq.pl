#!/usr/bin/perl


#RNA look up table for triplets
%genetic_code = (
  'UCA' => 'S', # Serine
  'UCC' => 'S', # Serine
  'UCG' => 'S', # Serine
  'UCU' => 'S', # Serine
  'UUC' => 'F', # Phenylalanine
  'UUU' => 'F', # Phenylalanine
  'UUA' => 'L', # Leucine
  'UUG' => 'L', # Leucine
  'UAC' => 'Y', # Tyrosine
  'UAU' => 'Y', # Tyrosine
  'UAA' => '_', # Stop
  'UAG' => '_', # Stop
  'UGC' => 'C', # Cysteine
  'UGU' => 'C', # Cysteine
  'UGA' => '_', # Stop
  'UGG' => 'W', # Tryptophan
  'CUA' => 'L', # Leucine
  'CUC' => 'L', # Leucine
  'CUG' => 'L', # Leucine
  'CUU' => 'L', # Leucine
  'CCA' => 'P', # Proline
  'CAU' => 'H', # Histidine
  'CAA' => 'Q', # Glutamine
  'CAG' => 'Q', # Glutamine
  'CGA' => 'R', # Arginine
  'CGC' => 'R', # Arginine
  'CGG' => 'R', # Arginine
  'CGU' => 'R', # Arginine
  'AUA' => 'I', # Isoleucine
  'AUC' => 'I', # Isoleucine
  'AUU' => 'I', # Isoleucine
  'AUG' => 'M', # Methionine
  'ACA' => 'T', # Threonine
  'ACC' => 'T', # Threonine
  'ACG' => 'T', # Threonine
  'ACU' => 'T', # Threonine
  'AAC' => 'N', # Asparagine
  'AAU' => 'N', # Asparagine
  'AAA' => 'K', # Lysine
  'AAG' => 'K', # Lysine
  'AGC' => 'S', # Serine
  'AGU' => 'S', # Serine
  'AGA' => 'R', # Arginine
  'AGG' => 'R', # Arginine
  'CCC' => 'P', # Proline
  'CCG' => 'P', # Proline
  'CCU' => 'P', # Proline
  'CAC' => 'H', # Histidine
  'GUA' => 'V', # Valine
  'GUC' => 'V', # Valine
  'GUG' => 'V', # Valine
  'GUU' => 'V', # Valine
  'GCA' => 'A', # Alanine
  'GCC' => 'A', # Alanine
  'GCG' => 'A', # Alanine
  'GCU' => 'A', # Alanine
  'GAC' => 'D', # Aspartic Acid
  'GAU' => 'D', # Aspartic Acid
  'GAA' => 'E', # Glutamic Acid
  'GAG' => 'E', # Glutamic Acid
  'GGA' => 'G', # Glycine
  'GGC' => 'G', # Glycine
  'GGG' => 'G', # Glycine
  'GGU' => 'G'  # Glycine
);

#DNA counterpart look up table
%counterpart=(
  'A' => 'T', 
  'T' => 'A', 
  'G' => 'C', 
  'C' => 'G'
);

#input and output files
$filename = 'data.txt';  #input file
$output_file = "result.txt";   #output file

my $protein='';
my $RNA='';
my $dna_counterpart='';

open(my $file, '<:encoding(UTF-8)', $filename)
  or die "Could not open file '$filename' $!";

my $DNA = <$file>;

#if it consist of any lower case, make it upper
$DNA =~ tr/a-z/A-Z/; 
print "DNA sequence: $DNA\n";


for(my $i=0;$i<length($DNA);$i+=1){
	$pyrimidine= substr($DNA,$i,1);
	$dna_counterpart .= $counterpart{$pyrimidine};
}

print "DNA counterpart sequence: $dna_counterpart\n";

$dna_counterpart =~ tr/T/U/; #make the dna_counterpart RNA by substituting T with U
$RNA=$dna_counterpart;


 print "RNA sequence: $RNA\n";

#look for each triplet from RNA look up table and append to protein list
for(my $i=0;$i<length($RNA)-2;$i+=3){
  $codon = substr($RNA,$i,3);
  $protein .= $genetic_code{$codon};
}

print "Protein sequences: $protein\n";


unless(open FILE, '>'.$output_file) {
    # Die with error message 
    # if we can't open it.
    die "\nUnable to create $file\n";
}

print FILE "$protein";
close FILE;








