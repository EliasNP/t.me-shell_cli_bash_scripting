#!/usr/bin/env bash

source ../.config

# Muestra los datos personales de la función genérica en azul
printf "%b" "${AZUL}"
_data
printf "%b" "${NC}"

# Muestra la información de las variables genéricas importadas del archivo .config
printf "%s\n%b\n" "Fecha de hoy:" " ${VERDE}${FECHA}${NC}"
printf "%s\n%b\n" "Hora actual:" " ${PURPURA}${HORA}${NC}"
printf "%s\n%b\n" "ID de usuario:" " ${CYAN}${USERID}${NC}"
printf "%s\n%b\n" "IP privada:" " ${ROJOCLARO}${IP}${NC}"
printf "%s\n%b\n" "Versión del Sistema Operativo:" " ${BLANCO}${VERSION_SISTEMA}${NC}"
printf "%s\n%b\n" "Nombre corto de la distribución:" " ${MARRON}${NOM_DISTRO_C}${NC}"
printf "%s\n%b\n" "Versión de Bash:" " ${AMARILLO}${VERSION_BASH}${NC}"
printf "%s\n%b\n" "Nombre del usuario creado por UID/GID:" \
    "${VERDECLARO}$(cowsay "$NOMBRE_USUARIO")${NC}"
