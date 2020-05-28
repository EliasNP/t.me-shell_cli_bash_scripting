#!/bin/sh

# VARIABLES Y FORMATOS
var_correcto=''
var_error='Error. Inténtalo más tarde.'
col_yellow='\033[1;33m'
col_red='\033[31m'
nc='\033[0m'

# FUNCIONES
fun_checkLastCommand (){
	if [ $? -eq 0 ]; then 
		printf "${col_yellow}$var_correcto${nc}\n\n";
		else printf "${col_red}\n$var_error\n\n" && exit 1;
	fi
}

#REPOSITORIOS
printf "${col_yellow}Actualizando repositorios...${nc}\n"
var_correcto="Repositorios actualizados."
sudo apt update
fun_checkLastCommand

#PAQUETES
printf "${col_yellow}Actualizando paquetes...${nc}\n"
var_correcto="Paquetes actualizados."
sudo apt upgrade -y
fun_checkLastCommand

#KERNEL
printf "${col_yellow}Comprobando actualización del kernel...${nc}\n"
var_correcto="Actualización del kernel comprobada."
sudo apt full-upgrade -y
fun_checkLastCommand

#REPARACIONES
printf "${col_yellow}Comprobando paquetes rotos${nc}\n"
var_correcto="Paquetes rotos comprobados."
sudo apt install -f -y &&
sudo dpkg --configure -a
fun_checkLastCommand

#LIMPIEZA
printf "${col_yellow}Limpiando el sistema...${nc}\n"
var_correcto="Limpieza terminada\n\nSistema actualizado y limpio"
sudo apt autoclean &&
sudo apt autoremove -y &&
sudo apt clean
fun_checkLastCommand

exit 0


