## os ayarlari ##
sudo sysctl -w kernel.randomize_va_space=0


## compile ##
gcc -o program -z execstack -fno-stack-protector program.c


## programi calistirma ##
./program

ikinci ornekte root olarak calistirmak gerekli.
sudo ./program


