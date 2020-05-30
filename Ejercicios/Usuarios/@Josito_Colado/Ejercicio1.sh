#!/bin/bash
#Fecha:28/05/2020
#Autor:Josito Colado	
#Proposito:Primer Script con Elias

#Con "mkdir" creamos el directorio indicando la ruta:		
	mkdir /home/josito/Cursos/To_se_borro

#Usamos "cd" + la ruta, para colocarnos el la carpeta creada:
	cd /home/josito/Cursos/To_se_borro

#Limpiamos pantalla:
	clear
	
#Mostramos texto con el comando "echo" y,
#Le añadimos "-e" para que tenga en cuenta el "\n" (salto de linea):
	echo -e "\nAqui salen los 40 archivos:"

#Con el comando touch creamos los 40 archivos .txt.
#Aquí no hay que indicar la ruta porque "cd" ya nos trasladó donde hay que crear los archivos.
#Con "ls" los mostramos añadiendo "-1v " para que sea en columna.
	touch {1..40}.txt
	ls -1v

#Volvemos a mostrar texto:	
	echo -e "\nSe comprimen el 23 y el 29 con gzip:"

#Comprimimos los dos archivos a la vez:
	gzip 23.txt 29.txt

#Visualizamos por pantalla solo los archivos comprimidos:	
	ls -1v *.txt.gz

#Muestra texto:
	echo -e "\nRenombramos los que contienen el nº3 en su nombre de *.txt a *.md:"

#Aquí creamos un bucle de la estructura "for".
#El valor inicial es una cadena en el nombre de archivo.
#Y con lo que encuentra le apica el "do".
#Así pasamos al "mv" que cambia la extensión de los archivos.
#y finalizamos el bucle con el "done"
	for file in *3*.txt; 
	do
    	mv "$file" "${file%.txt}.md"
	done
	
#Visualizamos solo los archivos con extensión .md:	
	ls -1v *.md

#FIN
