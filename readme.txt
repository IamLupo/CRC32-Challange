CRC32 Challenge:
	The file "challenge.zip" is the only file people need to do the challenge.

Generate:
	In the generate directory you will find two files:
		index.php:
			This will generate the flag at the end of the challenge.
		
		result/main.py:
			This will read the index.php and make it small text file.
			Then it will zip and encrypt them with a random 256 charter password.
			Then it will pack all the zip file in the challenge.zip
	
Solution:
	I also made a C++ script to confirm that this challange can be cracked.
	