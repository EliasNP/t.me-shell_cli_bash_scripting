#!/bin/bash  
# ============================
#    FUNCTIONS GENERICS
# ============================
function _Data(){
printf "\033[1;34m ============================================================================@\e[0m\n"
echo "Titulo         :tgfile.sh"
echo "Descripción   :Envia Texto y ficheros al Grupo desde la consola"
echo "Autor          :Elías Nieva"
echo "Fecha          :2020-05-15"
echo "Versión       :A.0.1  "
echo "uso            :./tgfile.sh"
echo "Notas          :       "
echo "bash_version   :4.4.20(1)-release"
echo "E-mail         :eliasnievap(at)protonmail(dot)com"
echo "Telegram       :@EliasNieva"
echo "Mastodon       :@EliasNieva@mastodon.social"
printf "\033[1;34m ============================================================================@\e[0m\n"
}

##============================================================================@

function _Logo(){
printf "\033[1;34m ============================================================================@\e[0m\n"
printf "\033[1;34m                      ═══════════════════════════════════\e[0m\n"
printf "\033[1;34m                      ║█████████████████████████████████║\e[0m\n"
printf "\033[1;34m                      ║██╔═══╦╗███████╔═╗█╔╗████████████║\e[0m\n"
printf "\033[1;34m                      ║██║╔══╣║███████║║╚╗║║████████████║\e[0m\n"
printf "\033[1;34m                      ║██║╚══╣║╔╦══╦══╣╔╗╚╝╠╦══╦╗╔╦══╗██║\e[0m\n"
printf "\033[1;34m                      ║██║╔══╣║╠╣╔╗║══╣║╚╗║╠╣║═╣╚╝║╔╗║██║\e[0m\n"
printf "\033[1;34m                      ║██║╚══╣╚╣║╔╗╠══║║█║║║║║═╬╗╔╣╔╗║██║\e[0m\n"
printf "\033[1;34m                      ║██╚═══╩═╩╩╝╚╩══╩╝█╚═╩╩══╝╚╝╚╝╚╝██║\e[0m\n"
printf "\033[1;34m                      ║█████████████████████████████████║\e[0m\n"
printf "\033[1;34m                      ═══════════════════════════════════\e[0m\n"
printf "\033[1;34m                         -----------------------\e[0m\n"
printf "\033[1;34m                        https://EliasNp.github.io\e[0m\n"
printf "\033[1;34m ============================================================================@\e[0m\n"
}
# ============================
#    PREVIOUS CHECK WORK 
# ============================
# Call a source whith common variables.

#source .config # here Don't needed
# DESCRIPCION DEL EJERCICO
#   Con 3 funciones
# 	- Una que cree 40 archivos .txt en una carpeta de tu escritorio (usa touch para crearlos)
# 	- Otra que comprima con gzip sólo los archivos 23 y 29.
# 	- La última que cambie la extensión de los ficheros que contengan un 3 en su nombre de .txt a .md.

# ============================
#   VARIABLES ONLY 4 THIS
# ============================


# ============================
#   FUNTIONS ONLY 4 THIS
# ============================

# Creamos x archivos .txt en una carpeta con "touch"
function _createfiles(){
	# touch crea archivos con {x..y} le decimos una secuencia ".txt" le damos contexto.
	touch {1..40}.txt
	#con "ls" listamos solo los nombres creados en 1 columna usando la opción -1v
	ls -1v
}

# Comprimimos los ficheros marcados en el ejercicio 23 y 29 en uno de salida.
function _compress(){
	# gzip comprimimos, la opcion -c mantiene los ficheros originales, "> nombre.gz" nos permite darle un nombre a la salida.
	gzip -c 23.txt 29.txt > 23y29.gz
}

# Cambiamos las extensiónes de los ficheros que contengan un "3" en su nombre de .txt a .md.

function _rename(){
	# Lo primero es localizar los archivos que contengan el 3 para eso usamos "find"
	# despues usamos la opcion de find para ejecutar otros comandos "-exec"
	# Usamos el comando "rename" con la variable -V para que nos muestre el proceso  y le pasamos los valores a cambiar
	# 	sustituyendo el nombre del archivo por "{}" para que introduzca los valores del find.
	# NOTA: tambien se puede usar "mv" pero se complicaria más teniendo que meter datos en variables como se haci antes.
	find *3*.txt -exec rename -v 's/\.txt/\.md/' {} \;
}


# ============================
#     SCRIPT START HERE
# ============================
 
_Data #This Funtion Show file Data
_Logo #This Function show Logo

clear

#Printf \033[1;32m solo le da una nota de color

printf "\033[1;32m Creamos los archivos y los listamos \e[0m\n"
printf "\033[1;33m \n" #nota de color sin importancia

	_createfiles

printf "\033[1;34m 2do punto \"\033[1;32mComprimimos\033[1;34m\" los Archivos \033[1;32m23.txt\033[1;34m y\033[1;32m 29.txt\033[1;34m en un solo fichero\033[1;32m\"23y29.gz\" \e[0m\n"

	_compress

printf "\033[1;34m 3er punto \"\033[1;32mRenombramos\033[1;34m\" los Archivos\033[1;32m .txt\033[1;34m en\033[1;32m .md\e[0m\n"

	_rename

#Imprimimos la salida en un pastebin para compartir.

printf "\033[1;33m Imprimimos la salida en un pastebin para compartir\e[0m\n"

	ls -lv > Ejercicio_1.out
	pastebinit Ejercicio_1.out

printf "\033[1;35m Imprimimos el \"Script\" en un pastebin para compartir\e[0m\n"

	pastebinit $0

printf "\033[1;33m Hemos Terminado el Ejercicio_1 \e[0m\n"


