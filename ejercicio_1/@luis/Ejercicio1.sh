#!/bin/bash



#Función que crear el númeor de ficheros que se le pasan por parámetro

function CreaFicheros

{

	for ((i=1;i<=$1;i++))

	do

		touch "$i.txt"

		if [ $? -eq 0 ]; then

			echo "Fichero $i.txt creado"

		fi

	done

}



#Función a la que se le pasan el nombre del archivo (sin extensión) y se comprimen mediante gzip

function ComprimeFicheros

{

	for fich in $*

	do

		gzip "$fich.txt"

		if [ $? -eq 0 ]; then 

			echo "El fichero $fich ha sido comprimido"

		fi

	done

}



#Cambia la extensión de los ficheros que contengan un 3

function CambiaExtension

{

	#Obtengo los ficheros del directorio actual que contienen un 3 en su nombre y tienen extensión .txt

	fichCambiar=$(ls | grep ".*3.*.txt$")



	for fich in $fichCambiar

	do

		#Otra posibilidad rename 's/\.txt/\.md/' $fich	

		mv "$fich" "${fich%.txt}.md"

		if [ $? -eq 0 ]; then

			echo "El fichero $fich ha sido renombrado"

		fi	

	done

}



numFicheros=40

fichComprimir="23 29"

CreaFicheros $numFicheros

ComprimeFicheros $fichComprimir

CambiaExtension
