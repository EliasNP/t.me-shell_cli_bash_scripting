#!/bin/bash

while true; do

	echo "Enter your Pastebin Developper API Key (see http://pastebin.com/api), or leave blank to use the default one (may not work):"
	read input

	if [ -z $input ] ; then
		echo "Trying to obtain default Developper API Key..."
		input=`wget -qO - http://tobast.fr/ressources/pastebin_devkey`

		if (( ! `echo $input | grep -ce "[0-9a-f]\{32\}"` > 0 )) ; then
			echo -e "\nERROR: Cannot obtain the default Developper API Key ! Please re-try with your API key.\n"
		else
			break
		fi
	else
		if (( ! `echo $input | grep -ce "[0-9a-f]\{32\}"` > 0 )) ; then
			echo -e "\nERROR: Wrong API key, please re-try.\n"
		else
			break
		fi
	fi
done

sed -ire "49s/\"\".*$/\"${input}\"/" data_devcode.h
echo "Success!"

