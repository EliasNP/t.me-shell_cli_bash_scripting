#!/bin/bash  

function _createfiles(){
	touch {1..40}.txt
	ls -1v
}

function _compress(){
	gzip -c 23.txt 29.txt > 23y29.gz
}

function _rename(){
	find *3*.txt -exec rename -v 's/\.txt/\.md/' {} \;
}

clear
_createfiles
_compress
_rename

	ls -lv > Ejercicio_1.out
	pastebinit Ejercicio_1.out
	pastebinit $0