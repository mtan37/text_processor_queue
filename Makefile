#make file for assignment1 @CS537
CC = gcc
CFLAGS = -c -Wall -Wextra -pedantic -g -pthread
ODIR = ./obj
SDIR = ./src
OBJECTS = $(ODIR)/main.o $(ODIR)/reader.o $(ODIR)/munch1.o $(ODIR)/munch2.o $(ODIR)/writer.o $(ODIR)/queue.o 
HEADERS = $(SDIR)/reader.h $(SDIR)/munch1.h $(SDIR)/munch2.h $(SDIR)/writer.h $(SDIR)/queue.h
run:$(OBJECTS)
	$(CC) -Wall -pthread -Wextra $(OBJECTS) -o run
$(ODIR)/test.o: $(SDIR)/test.c | $(ODIR)
	$(CC) $(CFLAGS) $< -o $@
$(ODIR)/main.o: $(SDIR)/main.c $(HEADERS) | $(ODIR)
	$(CC) $(CFLAGS) $< -o $@
$(ODIR)/reader.o: $(SDIR)/reader.c $(SDIR)/reader.h $(SDIR)/queue.h | $(ODIR)
	$(CC) $(CFLAGS) $< -o $@
$(ODIR)/munch1.o: $(SDIR)/munch1.c $(SDIR)/munch1.h $(SDIR)/queue.h | $(ODIR)
	$(CC) $(CFLAGS) $< -o $@
$(ODIR)/munch2.o: $(SDIR)/munch2.c $(SDIR)/munch2.h $(SDIR)/queue.h | $(ODIR)
	$(CC) $(CFLAGS) $< -o $@
$(ODIR)/writer.o: $(SDIR)/writer.c $(SDIR)/writer.h $(SDIR)/queue.h | $(ODIR)
	$(CC) $(CFLAGS) $< -o $@
$(ODIR)/queue.o: $(SDIR)/queue.c | $(ODIR)
	$(CC) $(CFLAGS) $< -o $@
$(ODIR):
	mkdir -p $(ODIR)
clean:
	rm $(ODIR)/*.o
	rm -r $(ODIR)
	rm run
