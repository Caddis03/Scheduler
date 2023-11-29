job.o: job.c
	gcc -c job.c -o job.o

project10_scheduler.o: project10_scheduler.c
	gcc -c project10_scheduler.c -o project10_scheduler.o

project10_scheduler: job.o project10_scheduler.o
	gcc job.o project10_scheduler.o -o project10_scheduler

clean:
	rm *.o