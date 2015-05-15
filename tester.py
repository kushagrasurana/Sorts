#!/usr/bin/python
import sys
import subprocess
import random

def generate_data(size, limit):
	ret = []
	ret.append(size)
	ret.extend( [random.randint(-limit,limit) for x in range(0,size)] )
	inp = open("input",'w')
	inp.write("%s"% ' '.join(str(x) for x in ret))
	return ret

def compile_and_open(file_name):
	if file_name.endswith(".py"):
			process = subprocess.Popen(["python ", file_name], stdout=subprocess.PIPE,stdin=subprocess.PIPE)

	elif file_name.endswith(".jar"):
		process = subprocess.Popen(["java -jar ", file_name], stdout=subprocess.PIPE,stdin=subprocess.PIPE)

	elif file_name.endswith(".class"):
		class_name = file_name.split('/')[-1].split('.')[0]
		pos = file_name.rfind('/')
		class_path =file_name[0:pos]
		process = subprocess.Popen(["java","-classpath",class_path,class_name], stdout=subprocess.PIPE,stdin=subprocess.PIPE)

	elif file_name.endswith(".java"):
		process = subprocess.Popen(["javac",file_name], stdout=subprocess.PIPE,stdin=subprocess.PIPE)
		class_name = file_name.split('/')[-1].split('.')[0]
		pos = file_name.rfind('/')
		class_path =file_name[0:pos]
		process.wait()
		process = subprocess.Popen(["java","-classpath",class_path,class_name], stdout=subprocess.PIPE,stdin=subprocess.PIPE)

	elif file_name.endswith(".cpp"):
		command =  "g++ ",file_name," -o "+file_name[0:-4]+".out"
		process = subprocess.Popen([command], stdout=subprocess.PIPE,stdin=subprocess.PIPE)
		file_name = file_name[0:-4]+".out"
		process.wait()
		process = subprocess.Popen([file_name], stdout=subprocess.PIPE,stdin=subprocess.PIPE)

	elif file_name.endswith(".c"):
		command =  "gcc ",file_name," -o "+file_name[0:-4]+".out"
		process = subprocess.Popen([command], stdout=subprocess.PIPE,stdin=subprocess.PIPE)
		file_name = file_name[0:-4]+".out"
		process.wait()
		process = subprocess.Popen([file_name], stdout=subprocess.PIPE,stdin=subprocess.PIPE)
	else:
		process = subprocess.Popen([file_name], stdout=subprocess.PIPE,stdin=subprocess.PIPE)
	return process

def test_file(file_name, size = 10000, limit = 10000):
	flag=0
	data = generate_data(size, limit)
	data_str = ' '.join(str(x) for x in data)
	
	file_name.strip()
	process = compile_and_open(file_name)
	sort_out = process.communicate(data_str)[0].strip().split(' ')
	process.wait()
	
	data.pop(0) # remove size of input
	data.sort()
	
	if len(sort_out)!=size:
		flag=1
	else:
		for i in range(0,size):
			if data[i]!=int(sort_out[i]):
				flag=1
	if flag:
		print("error, see error.txt for details")
		error_file = open("error.txt", 'w')
		error_file.write("input data\n%s"% data_str)
		error_file.write("\noutput data\n%s"% ' '.join(sort_out))
		error_file.write("\ncorrect data\n%s"% ' '.join(str(x) for x in data))
		error_file.close()
	else:
		print("correct")

def main():
	if len(sys.argv) > 1: # check if filename is given in command line arguments
		name = sys.argv[1]
		if len(sys.argv) == 3:
			size = int(sys.argv[2])
			test_file(name, size)
		else:
			if len(sys.argv) > 3:
				size = int(sys.argv[2])
				limit = int(sys.argv[3])
				test_file(name, size, limit)
			else:
				test_file(name)
	else:
		name = str(raw_input("Enter file name:"))
		size = int(input("Enter n:"))
		limit = int(input("Enter limit of random numbers:"))
		test_file(name, size, limit)

if __name__ == '__main__':
	main()