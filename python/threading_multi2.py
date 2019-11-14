import threading

def print_cube(num):
    for i in range(100):
        print("Cube")

def print_square(num):
    for i in range(100):
        print("Square")

if __name__ == "__main__":
	# creating thread
	t1 = threading.Thread(target=print_square, args=(100,))
	t2 = threading.Thread(target=print_cube, args=(100,))

	# starting thread 1
	t1.start()
	# starting thread 2
	t2.start()

	# wait until thread 1 is completely executed
	t1.join()
	# wait until thread 2 is completely executed
	t2.join()

	# both threads completely executed
	print("Done!")
