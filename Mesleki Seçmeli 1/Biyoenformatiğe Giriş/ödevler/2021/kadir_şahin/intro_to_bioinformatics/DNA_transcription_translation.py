gene_table = {
  "UUU" : "F",   
  "UUC" : "F",
  "UUA" : "L",
  "UUG" : "L",
  "CUU" : "L",
  "CUC" : "L",
  "CUA" : "L",
  "CUG" : "L",
  "AUU" : "I",
  "AUC" : "I",
  "AUA" : "I",
  "AUG" : "M",
  "GUU" : "V",
  "GUC" : "V",
  "GUA" : "V",
  "GUG" : "V",
  "UCU" : "S",
  "UCC" : "S",
  "UCA" : "S",
  "UCG" : "S",
  "CCU" : "P",
  "CCC" : "P",
  "CCA" : "P",
  "CCG" : "P",
  "ACU" : "T",
  "ACC" : "T",
  "ACA" : "T",
  "ACG" : "T",
  "GCU" : "A",
  "GCC" : "A",
  "GCA" : "A",
  "GCG" : "A",
  "UAU" : "Y",
  "UAC" : "Y",
  "UAA" : ".",
  "UAG" : ".",
  "CAU" : "H",
  "CAC" : "H",
  "CAA" : "Q",
  "CAG" : "Q",
  "AAU" : "N",
  "AAC" : "N",
  "AAA" : "K",
  "AAG" : "K",
  "GAU" : "D",
  "GAC" : "D",
  "GAA" : "E",
  "GAG" : "E",
  "UGU" : "C",
  "UGC" : "C",
  "UGA" : ".",
  "UGG" : "W",
  "CGU" : "R",
  "CGC" : "R",
  "CGA" : "R",
  "CGG" : "R",
  "AGU" : "S",
  "AGC" : "S",
  "AGA" : "R",
  "AGG" : "R",
  "GGU" : "G",
  "GGC" : "G",
  "GGA" : "G",
  "GGG" : "G"
}


with open("dataset.txt") as dataset: 
    dna=dataset.read()


#dna=input('Enter the raw DNA sequence to translate:')

print(dna)
print("\n")
rna=""

for i in dna:
    if(i=='A'):
        rna+='U'
    elif(i=='T'):
        rna+='A'
    elif(i=='C'):
        rna+='G'
    elif(i=='G'):
        rna+='C'

print(rna)
print("\n")

lis=[]
for i in range(0, len(rna),3):
    lis.append(rna[i:i+3])

print(lis)

codon=""

for i in lis:
    codon+=gene_table[i]

print("\n")
print(codon)

f = open("codon.txt", "w")
f.write(codon)
f.close()
