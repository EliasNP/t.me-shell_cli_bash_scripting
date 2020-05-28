#!/bin/bash  
function _Data(){
echo "Titulo         :testenrique.sh"
echo "Descripción   :compare files and extrat the info not igual"
echo "Autor          :Elías Nieva"
echo "Fecha          :2020-05-01"
echo "Versión       :A.0.1  "
echo "uso            :./testenrique.sh"
echo "Notas          :       "
echo "bash_version   :4.4.20(1)-release"
echo "E-mail         :eliasnievap(at)protonmail(dot)com"
echo "Telegram       :@EliasNieva"
echo "Mastodon       :@EliasNieva@mastodon.social"
echo "============================================================================@"
}
##============================================================================@
function _Logo(){
printf "\033[1;34m 			═══════════════════════════════════\e[0m\n"
printf "\033[1;34m 			║█████████████████████████████████║\e[0m\n"
printf "\033[1;34m 			║██╔═══╦╗███████╔═╗█╔╗████████████║\e[0m\n"
printf "\033[1;34m 			║██║╔══╣║███████║║╚╗║║████████████║\e[0m\n"
printf "\033[1;34m 			║██║╚══╣║╔╦══╦══╣╔╗╚╝╠╦══╦╗╔╦══╗██║\e[0m\n"
printf "\033[1;34m 			║██║╔══╣║╠╣╔╗║══╣║╚╗║╠╣║═╣╚╝║╔╗║██║\e[0m\n"
printf "\033[1;34m 			║██║╚══╣╚╣║╔╗╠══║║█║║║║║═╬╗╔╣╔╗║██║\e[0m\n"
printf "\033[1;34m 			║██╚═══╩═╩╩╝╚╩══╩╝█╚═╩╩══╝╚╝╚╝╚╝██║\e[0m\n"
printf "\033[1;34m 			║█████████████████████████████████║\e[0m\n"
printf "\033[1;34m 			═══════════════════════════════════\e[0m\n"
printf "\033[1;34m                         -----------------------\e[0m\n"
printf "\033[1;34m                        https://EliasNp.github.io\e[0m\n"
printf "\033[1;34m ============================================================================@\e[0m\n"
}
# ============================
#    PREVIOUS CHECK WORK 
# ============================

reset #Clean all the screen 
_Logo #This Function show Logo
_Data #This Funtion Show file Data
printf "\033[1;34m ============================================================================@\e[0m\n"
echo " "
printf "\033[1;34m First Check if the Temporal files \"Exist OnlyFile1,OnlyFile2,both,exit1,exit2\"\e[0m\n"
printf "\033[1;34m ============================================================================@\e[0m\n"
echo "Press \"ENTER\" 4 next \"Crtl + Z\" for Exit"
read P

if [ -r OnlyFile1.txt ] ; then rm OnlyFile1.txt ; fi
if [ -r OnlyFile2.txt ] ; then rm OnlyFile2.txt ; fi
if [ -r both.txt ] ; then rm both.txt ; fi
if [ -r exit1.tmp ] ; then rm exit1.tmp ; fi	
if [ -r exit2.tmp ] ; then rm exit2.tmp ; fi	

	printf "\033[1;34m  All Clean, wait until finish compare"


# ============================
# DEFINITION OF OWN VARIABLES 
# ============================

# here you can declare the variables for the files you want to compare when you run the script like :~$ sh testenrique.sh file1.txt file2.txt
File_one=$1
File_two=$2

# ============================
#    WE START THE SCRIPT 
# ============================

# Here we start the Code.
# Example of Show Variable results as Example.

<<-COMENT1 

THIS CODE IS COMMENTED TO SHOW THE SYNTAX OF HOW THE VARIABLES SHOULD BE SHOWN.
echo $ VARIABLE_EXAMPLE

COMENT1
                    

<<-COMENT2
THIS CODE IS COMMENTED TO SHOW INHERITED FILE VARIABLES /home/enieva/scripts/variables.sh

----- (↑) ---- (↑) ------ (↑) -------- UNTIL THE INHERITED VARIABLES ---- (↑) ----- - (↑) ----- (↑) -------
COMENT2

# First clean de Blank Spaces on the files in a new one named exitX.tmp

cat $File_one | tr " \t" "\n" | tr -s "\n" > exit1.tmp
cat $File_two | tr " \t" "\n" | tr -s "\n" > exit2.tmp


for LINEA in `cat exit1.tmp` # Loop in the first file compare whith second file.
do
            
            #	This is Coment because it's only 4 test propouses
			#	echo -e "LINEA = $LINEA"
			

	CHECK=`grep $LINEA exit2.tmp` # Here extract de line in the first file and search in the second
            
            
            #	This is Coment because it's only 4 test propouses
			#	echo -e "CHECK = $CHECK"
			

	if [ -z $CHECK ]  # Here check if the var is empty.
	then 
		    
            #	This is Coment because it's only 4 test propouses
			#	echo $LINEA "EXIST ONLY IN [ $File_one ]"
			

		echo "$LINEA" >> OnlyFile1.txt
	else
		if [ $LINEA -eq $CHECK ]
		then
			    
            	#This is Coment because it's only 4 test propouses
		    	#echo $LINEA 'EXIST IN BOTH'
		    	

		    echo "$LINEA" >> both.txt
		fi
	fi

done

for LINEA in `cat exit2.tmp` # Loop in the second file compare whith first file.
do

	CHECK=`grep $LINEA exit1.tmp`  # Here extract de line in the second file and search in the first

	if [ -z $CHECK ]
	then 
            #	This is Coment because it's only 4 test propouses
			#	echo $LINEA "EXIST ONLY IN [ $File_two ]"
			
		echo "$LINEA" >> OnlyFile2.txt
	fi

done

clear

#This Print the Exit you want with conditional for the files don`t exist.

echo "This data are in both files"
if [ -r OnlyFile1.txt ] ; then cat both.txt ; else echo "No data exclusive in both files " ; fi
echo "==================================="
echo " This data it only exist in $File_one"
if [ -r OnlyFile1.txt ] ; then cat OnlyFile1.txt ; else echo "No data exclusive in $File_one" ; fi
echo "==================================="
echo " This data it only exist in $File_two"
if [ -r OnlyFile2.txt ] ; then cat OnlyFile2.txt ; else echo "No data exclusive in $File_two" ; fi
echo "==================================="
