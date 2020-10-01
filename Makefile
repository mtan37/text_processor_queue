#make file for assignment1 @CS537
CC = gcc
CFLAGS = -c -Wall -pedantic -g
ODIR = ./obj
SDIR = ./src
OBJECTS = $(ODIR)/main.o $(ODIR)/reader.o $(ODIR)/munch1.o $(ODIR)/munch2.o $(ODIR)/writer.o  
run:$(OBJECTS)
	$(CC) -Wall $(OBJECTS) -o run
$(ODIR)/main.o: $(SDIR)/main.c | $(ODIR)
	$(CC) $(CFLAGS) $< -o $@
$(ODIR)/reader.o: $(SDIR)/reader.c | $(ODIR)
	$(CC) $(CFLAGS) $< -o $@
$(ODIR)/munch1.o: $(SDIR)/munch1.c | $(ODIR)
	$(CC) $(CFLAGS) $< -o $@
$(ODIR)/munch2.o: $(SDIR)/munch2.c | $(ODIR)
	$(CC) $(CFLAGS) $< -o $@
$(ODIR)/writer.o: $(SDIR)/writer.c | $(ODIR)
	$(CC) $(CFLAGS) $< -o $@
$(ODIR):
	mkdir -p $(ODIR)
clean:
	rm $(ODIR)/*.o
	rm -r $(ODIR)
	rm run
