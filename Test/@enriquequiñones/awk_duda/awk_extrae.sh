#!/bin/bash  
function _Data(){
printf "\033[1;34m ============================================================================@\n"
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
##============================================================================@
function _Logo(){
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

#source .config
#reset #Clean all the screen 
_Logo #This Function show Logo
_Data #This Funtion Show file Data

# ============================
#  SCRIPT START HERE VARIABLES
# ============================

echo "Iniciamos la consulata de awk"
# awk "-F" Nos permite insertar los delimitadores
awk -F\# '{ OFS = FS } { if ( $2 == "ASERV" && ( $9 ~ "27/05/2020" )) print FILENAME, " - ", $9 } ' *
