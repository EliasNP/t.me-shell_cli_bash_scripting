#!/bin/bash
#Crear 40 archivos txt
function creaficheros()
{
for i in `seq 1 40`; 
do 
	touch $i.txt; 
done
}
#Comprimir sólo los archivos 29 y 23
function kompressor()
{ 
gzip $(ls {23.txt,29.txt})
}
#modificar la extensión de los archivos que contengan un 3 de txt a md
function renombra()
{
for f in *3*.txt; 
do 
	mv -- "$f" "${f%.txt}.md"; 
done  
}
function copio_alpastebinit()
{
ls *.{txt,md,gz} | pastebinit
}
#Llamada a las funciones
creaficheros
kompressor
renombra
copio_alpastebinit
