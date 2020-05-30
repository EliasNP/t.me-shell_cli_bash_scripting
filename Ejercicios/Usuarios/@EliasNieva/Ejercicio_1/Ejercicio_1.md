# ============================
#   RESULTADO EJERCICIO_1
# ============================

### Creamos 40 archivos .txt en una carpeta con "touch"

Con el comando **touch** crea archivos con **{x..y}** le decimos una secuencia "**.txt**" le damos contexto.
con "**ls**" listamos solo los nombres creados en 1 columna usando la opción **-1v**

```bash 
	function _createfiles(){
	touch {1..40}.txt
	ls -1v
}
```

### Comprimimos los ficheros

Con el comando **gzip** comprimimos, la opcion **-c** mantiene los ficheros originales, "**> nombre.gz**" nos permite darle un nombre a la salida.

```bash 
function _compress(){

	gzip -c 23.txt 29.txt > 23y29.gz
}
```

### Cambiamos las extensiónes de los ficheros que contengan un "3" en su nombre de .txt a .md.

Lo primero es localizar los archivos que contengan el **3** para eso usamos "**find**" despues usamos la opcion de find para ejecutar otros comandos "**-exec**" usamos el comando "**rename**" con la variable **-V** para que nos muestre el proceso  y le pasamos los valores a cambiar sustituyendo el nombre del archivo por "**{}**" para que introduzca los valores del find.
 
>NOTA: tambien se puede usar "**mv**" pero se complicaria más teniendo que meter datos en variables como se hacia antes.
En Versiones derivadas de RHEL/CENTOS "**Rename** cambia un poco en su forma de ejecutarse"
	
```bash 
function _rename(){
	find *3*.txt -exec rename -v 's/\.txt/\.md/' {} \;
}
```
### Llamamos a las Funciones que hemos creado

```bash 
_createfiles
_compress
_rename
```

### Mandamos el resultado a un archivo 
```bash 
ls -lv > Ejercicio_1.out
```
### Imprimimos la salida en un pastebin para compartir.

```bash 
pastebinit Ejercicio_1.out
pastebinit $0
```

Para más detalle consultar el Script en Github

[Script Ejercicio_1](https://github.com/EliasNP/t.me-shell_cli_bash_scripting/blob/master/ejercicio_1/%40EliasNieva/Ejercicio_1.sh)

SI quereis tenerlo solo con lo necesario os dejo el script à continuación limpio

```bash
#!/bin/bash  

function _createfiles(){
	touch {1..40}.txt
	ls -1v
}

function _compress(){
	gzip -c 23.txt 29.txt > 23y29.gz
}

function _rename(){
	find *3*.txt -exec rename -v 's/\.txt/\.md/' {} \;
}

clear
_createfiles
_compress
_rename

	ls -lv > Ejercicio_1.out
	pastebinit Ejercicio_1.out
	pastebinit $0
```