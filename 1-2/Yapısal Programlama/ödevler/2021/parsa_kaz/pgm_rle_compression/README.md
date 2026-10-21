# PGM Compressor

<hr>

Tags: #YTU #Assignment #SemesterProject

## Description

A command line tool to compress, decompress, modify the PGM image files using Run Lenght Encoding approach.


## Usage

```bash
PGMRLE [-edcph] [file]
```

> -e : to Encode the file  
-d : to Decode the file  
-c : to change a Color  
-p : to change a Pixel. // Incomplete  
-h : to print the histogram of all colors


Example
```
$ PGMRLE -e input.pgm
$ PGMRLE -d test_encoded.txt
$ PGMRLE -c test_encoded.txt
$ PGMRLE -h test_encoded.txt
```

<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE` for more information.
