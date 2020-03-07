## Make grade

### lab1

### lab2

### lab3

``` bash
divzero: OK (1.0s) 
softint: OK (1.0s) 
badsegment: OK (1.0s) 
Part A score: 30/30

faultread: OK (1.0s) 
faultreadkernel: OK (1.9s) 
faultwrite: OK (1.2s) 
faultwritekernel: OK (2.0s) 
breakpoint: OK (1.9s) 
testbss: OK (2.1s) 
hello: OK (1.9s) 
buggyhello: OK (2.2s) 
    (Old jos.out.buggyhello failure log removed)
buggyhello2: OK (1.9s) 
    (Old jos.out.buggyhello2 failure log removed)
evilhello: OK (2.1s) 
    (Old jos.out.evilhello failure log removed)
Part B score: 50/50
```

### lab4

``` bash
dumbfork: OK (2.1s)
Part A score: 5/5

faultread: OK (1.4s)
faultwrite: OK (1.9s)
faultdie: OK (1.9s)
faultregs: OK (2.0s)
faultalloc: OK (2.1s)
faultallocbad: OK (2.0s)
faultnostack: OK (2.0s)
faultbadhandler: OK (1.9s)
faultevilhandler: OK (1.2s)
forktree: OK (2.0s)
Part B score: 50/50

spin: OK (2.0s) 
stresssched: OK (2.4s)
sendpage: OK (2.0s)
pingpong: OK (2.0s)
primes: OK (4.4s)
Part C score: 25/25

Score: 80/80
```

### lab5

``` bash
internal FS tests [fs/test.c]: OK (2.6s)
  fs i/o: OK
  check_bc: OK
  check_super: OK
  check_bitmap: OK
  alloc_block: OK
  file_open: OK
  file_get_block: OK
  file_flush/file_truncate/file rewrite: OK
testfile: OK (2.3s)
  serve_open/file_stat/file_close: OK
  file_read: OK
  file_write: OK
  file_read after file_write: OK
  open: OK
  large file: OK
spawn via spawnhello: OK (2.4s)
Protection I/O space: OK (2.4s)
    (Old jos.out.faultio failure log removed)
PTE_SHARE [testpteshare]: OK (2.3s)
PTE_SHARE [testfdsharing]: OK (1.4s)
start the shell [icode]: Timeout! OK (31.1s)
testshell: OK (4.0s)
primespipe: OK (6.7s)
Score: 150/150

```
