#!/usr/bin/python
import hashlib
import random


randseed=random.random();
randstr="(0DeD |3`/ _-"+str(randseed)+"-_ T08as7";
key=hashlib.sha512(randstr.encode('utf-8')).hexdigest();

print(key);
