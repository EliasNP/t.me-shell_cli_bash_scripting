#!/bin/bash
clear

#Aquí llamamos al comando "source" para dirigirnos al archivo .config.
source .config	
#Este "printf" solo hace un salto de línea.
printf "\n"

#Aquí llamamos a la FUNCION FIJA.
_Data

#Aquí llamamos a las VARIABLES FIJAS.
#Usamos "printf" en vez de "echo" porque usamos colores.
#Con el simbolo "$" + el nombre de la variable, nos dá su valor.
#Bash tiene variables standard (estan en mayusculas).
printf "\n"
printf "\033[32m$fecha\e[0m\n"
printf "\033[35m$hora\e[0m\n"
printf "\033[36m$userid\e[0m\n"
printf "\033[1;31m$ip\e[0m\n"
printf "\033[1;37m$version_sistema\e[0m\n"
printf "\033[33m$nom_distro\e[0m\n"
printf "\033[1;33m$BASH_VERSION\e[0m\n"
printf "\033[1;32m$nombre_usuario\e[0m\n"
printf "\n"
#FIN
