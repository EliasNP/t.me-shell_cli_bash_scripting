#!/bin/bash
#Fecha:28/05/2020
#Autor:Josito Colado	
#Proposito:Primer Script con Elias

#Con "mkdir" creamos el directorio indicando la ruta:		
	mkdir /home/josito/Cursos/Script_Pruebas/Shell_Cli_Bash_Scripting/Ejercicio1/EJECUTANDO

#Usamos "cd" + la ruta, para colocarnos el la carpeta creada:
	cd /home/josito/Cursos/Script_Pruebas/Shell_Cli_Bash_Scripting/Ejercicio1/EJECUTANDO

#Limpiamos pantalla:
	clear
	
#Cuando mostramos texto con el comando "echo",
#Le añadimos "-e" para que tenga en cuenta el "\n" (salto de linea):

#Con el comando touch creamos los 40 archivos .txt.
#Aquí no indicar la ruta porque "cd" ya nos trasladó donde hay que crear los archivos.
#Con "ls" los mostramos añadiendo "-1v " para que sea en columna.

function _createfiles(){

	touch {1..40}.txt
	ls -1v
}

#Comprimimos los dos archivos a la vez:
	
function _compress(){

	gzip -c 23.txt 29.txt > 23y29.gz
}

#Aqui usamos el comando "find" para localizar los archivos que en el nombre contienen un numero "3".
#Luego con el comando "-exec" podemos concatenar el comando "rename" para cambiar el nombre a los archivos encontrados con el comando "find".
	
function _rename(){

    find *3*.txt -exec rename -v 's/\.txt/\.md/' {} \;
}	
	
#Llamamos las funciones que se han creado:
	
	clear

	echo -e "\nAquí salen los 40 archivos:"
		_createfiles

	echo -e "\nSe comprimen el23 y el 29 con gzip:"
		_compress
	
	echo -e "\nRenombramos los que contienen 3 en el nombre de .txt a .md:"
		_rename

#Mandamos el resultado a un archivo:

	echo -e "\nEnviamos la salida a un pastebin"
		ls -1v > Ejercicio_1.out
		pastebinit Ejercicio_1.out
	
#FIN
