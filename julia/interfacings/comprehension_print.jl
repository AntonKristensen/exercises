

file = open("printed_array.data","w+")


argumentstring = ARGS[1]				#store the argument as a string just to be safe :)
fullstring = string( "(" ,argumentstring, ")" )		#then add extra syntax on it
expression = Meta.parse(fullstring)			#then we turn it into an expression datatype
generator = eval(expression)				#now evaluate the expression
array = collect(generator)				#makes the array from the generator


print(file,array)


close(file)

