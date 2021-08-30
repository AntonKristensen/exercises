io = open("testfile.txt","w+")

a = rand(1:10,(2,7))

print(io,a)

close(io)
