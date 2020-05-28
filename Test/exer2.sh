#!/bin/bash

echo "What are you looking for?"
read wtf

declare -a arr=('deploy/role.yaml' 'pkg/deploy/pod_exec.go' 'deploy/cluster_role.yaml' 'olm/testUpdate.sh' )

for it in "${arr[@]}"
 do 
        if [[ $it == "$wtf"* ]];then
	echo "$it OK"
	fi
done
