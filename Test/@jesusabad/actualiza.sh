#!/bin/sh

# VARIABLES Y FORMATOS
var_correcto=''
var_error='Error. Inténtalo más tarde.'
col_yellow='\033[1;33m'
col_red='\033[31m'
nc='\033[0m'

# COMPROBACIÓN DE PERMISOS ADMINISTRATIVOS
if ! [ $(id -u) = 0 ]; then
	printf "${col_red}\nNecesitar permisos administrativos. Usa 'sudo actualiza'\n\n" && exit 1;
fi

# FUNCIONES
fun_checkLastCommand (){
	if [ $? -eq 0 ]; then 
		printf "${col_yellow}$var_correcto${nc}\n\n";
		else printf "${col_red}\n$var_error\n\n" && exit 1;
	fi
}

# COMPRUEBA LA INSTALACIÓN DEL SCRIPT
if [ ! -e "/usr/bin/actualiza" ]; then
        printf "${col_yellow}No existe el enlace simbólico, así que lo creo.${nc}\n"
        var_error='Error creando el enlace simbólico. "¿Has usado sudo?"'
        ln -s $PWD/actualiza.sh /usr/bin/actualiza
        fun_checkLastCommand
fi

#REPOSITORIOS
printf "${col_yellow}Actualizando repositorios...${nc}\n"
var_correcto="Repositorios actualizados."
apt update
fun_checkLastCommand

#PAQUETES
printf "${col_yellow}Actualizando paquetes...${nc}\n"
var_correcto="Paquetes actualizados."
apt upgrade -y
fun_checkLastCommand

#KERNEL
printf "${col_yellow}Comprobando actualización del kernel...${nc}\n"
var_correcto="Actualización del kernel comprobada."
apt full-upgrade -y
fun_checkLastCommand

#REPARACIONES
printf "${col_yellow}Comprobando paquetes rotos${nc}\n"
var_correcto="Paquetes rotos comprobados."
apt install -f -y &&
dpkg --configure -a
fun_checkLastCommand

#LIMPIEZA
printf "${col_yellow}Limpiando el sistema...${nc}\n"
var_correcto="Limpieza terminada\n\nSistema actualizado y limpio"
apt autoclean &&
apt autoremove -y &&
apt clean
fun_checkLastCommand

exit 0
