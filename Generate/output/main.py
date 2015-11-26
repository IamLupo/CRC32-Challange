#!/usr/bin/env python

import os
import random
import string
from subprocess import call

def randomword(length):
   return ''.join(random.choice(string.lowercase) for i in range(length))

"""
	Index.php is what people need to find and run to get the flag.
"""
input_file = open("../index.php", "r")
filesize = os.path.getsize("../index.php")

make_challange_command = [
		"zip",
		"../../challange.zip"
	]

for i in range((filesize / 5) + 1):
	output_filename = "{id}.txt".format(id = i)
	output_filename_zip = "{id}.zip".format(id = i)
	
	output_file = open(output_filename, "w+")
	data = input_file.read(5)
	output_file.write(data)
	output_file.close()
	
	call([
		"zip",
		"--password=\"{password}\"".format(password = randomword(256)),
		output_filename_zip,
		output_filename
	])
	
	make_challange_command.append(output_filename_zip)

input_file.close()

"""
	When all the small zips are made they will be put in one zip file.
	This will be the final product to give to the users
"""
call(make_challange_command)